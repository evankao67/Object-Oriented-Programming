#include <iostream>
#include<cmath>
using namespace std;
class Vector
{
public:
    friend ostream &operator<<(ostream &, const Vector &);
    Vector(){arr=new double[2], Size=2, Length=0, arr[0]=0, arr[1]=0;};
    Vector(int size);
    Vector(int size, double elem[]);
    Vector(const Vector &v);
    ~Vector();
    double length();
    void setDimension(int i);
    int getDimension(){return Size;};
    Vector &operator=(const Vector &v);
    Vector operator-();
    Vector operator+(Vector c);
    Vector operator-(Vector c);
    Vector operator*(double index);

    Vector &operator+=(Vector c);
    Vector &operator-=(Vector c);
    Vector &operator*=(double index);

    bool operator==(Vector c);
    bool operator!=(Vector c);

    double &operator[](int slot);
private:
    double *arr;
    int Size;
    double Length;
    void copy(const Vector &v);
};
Vector operator*(double index, Vector v);