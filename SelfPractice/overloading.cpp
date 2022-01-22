#include <iostream>
using namespace std;

class Complex {
public:
    friend ostream& operator<<(ostream&, const Complex&);
    friend istream& operator>>(istream&, Complex&);
    Complex(){};
    Complex(double _Real, double _imaginary){Real = _Real; Imaginary = _imaginary;};

    Complex &operator+=(Complex c);
    Complex operator+(Complex c);
    Complex operator-(Complex c);
    Complex operator*(Complex c);

    Complex &operator++();
    Complex operator++(int);
    Complex &operator--();
    Complex operator--(int);

    bool operator>(Complex c);
    bool operator<(Complex c);
    bool operator==(Complex c);
private:
    double Real;
    double Imaginary;
};

istream& operator>>( istream& in, Complex& c)
{
// Put your code hear...
    in>>c.Real>>c.Imaginary;
    return in;
//
}
ostream& operator<<(ostream& out, const Complex& c)
{
// Put your code hear...
    if(c.Imaginary>=0)
        out<<c.Real<<'+'<<c.Imaginary<<'i';
    else
        out<<c.Real<<'-'<<-(c.Imaginary)<<'i';
    return out;
//
}

Complex &Complex::operator+=(Complex c) {
// Put your code hear...
    Real+=c.Real;
    Imaginary+=c.Imaginary;
    return *this;
//
}
Complex Complex::operator+(Complex c) {
// Put your code hear...
    Complex temp(Real+c.Real, Imaginary+c.Imaginary);
    return temp;
//
}
Complex Complex::operator-(Complex c) {
// Put your code hear...
    Complex temp(Real-c.Real, Imaginary-c.Imaginary);
    return temp;
//
}
Complex Complex::operator*(Complex c) {
// Put your code hear...
    Complex temp(Real*c.Real-Imaginary*c.Imaginary, Imaginary*c.Real+Real*c.Imaginary);
    return temp;
//
}

Complex &Complex::operator++() {
// Put your code hear...
    Real++;
    Imaginary++;
    return *this;
//
}
Complex Complex::operator++(int) {
// Put your code hear...
    Complex temp=*this;
    Real++;
    Imaginary++;
    return temp;
//
}
Complex &Complex::operator--() {
// Put your code hear...
    Real--;
    Imaginary--;
    return *this;
//
}
Complex Complex::operator--(int) {
// Put your code hear...
    Complex temp=*this;
    Real--;
    Imaginary--;
    return temp;
//
}
bool Complex::operator>(Complex c){
// Put your code hear...
    if(Real==c.Real)
        return Imaginary>c.Imaginary?true:false;
    else
        return Real>c.Real?true:false;
//
}

bool Complex::operator<(Complex c){
// Put your code hear...
    if(Real==c.Real)
        return Imaginary<c.Imaginary?true:false;
    else
        return Real<c.Real?true:false;
//
}
bool Complex::operator==(Complex c){
// Put your code hear...
    return Real==c.Real&&Imaginary==c.Imaginary?true:false;
//
}
int main() {
    Complex C1, C2;
    while( cin >> C1 >> C2 ) {
        cout << "C1 = " << C1 << endl;
        cout << "C2 = " << C2 << endl;

        cout << "C1==C2? " << ((C1==C2)?"true":"false") << endl;
        cout << "C1<C2?  " << ((C1<C2)?"true":"false") << endl;
        cout << "C1>C2?  " << ((C1>C2)?"true":"false") << endl;

        cout << "C1+C2 = " << C1+C2 << endl;
        cout << "C1-C2 = " << C1-C2 << endl;
        cout << "C1*C2 = " << C1*C2 << endl;
        cout << "C1++  = " << C1++ << endl;
        cout << "C1++  = " << C1++ << endl;
        cout << "++C1  = " << ++C1 << endl;
        cout << "++C1  = " << ++C1 << endl;
        cout << "C2--  = " << C2-- << endl;
        cout << "C2--  = " << C2-- << endl;
        cout << "--C2  = " << --C2 << endl;
        cout << "--C2  = " << --C2 << endl;

        C1+=C2;
        cout << "C1+=C2  " << C1 << endl;
        cout << "==============" << endl;
    }
    return 0;
}