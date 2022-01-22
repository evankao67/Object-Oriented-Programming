#include <iostream>
#include <time.h>
using namespace std;
class DataT;
    class GeneralT
    {
    public:
        void printX(DataT inputObject); // needs friendship
        void printIntro();
    };

    class DataT
    {
        friend GeneralT; // give GeneralT access to private data
    public:
        DataT(int );
        ~DataT(){};
    private:
        int x;

    private: // need to be public if friendship is not granted
        int &getData() { return x; }
    };
    DataT::DataT(int x_){
        x=x_;
    }
    void GeneralT::printX(DataT inputObject)
    {
        cout << inputObject.getData() << "\n";
        cout << inputObject.x << "\n";
    }
int main()
{
    DataT kkk(75);
    GeneralT jjj;
    jjj.printX(kkk);
}
