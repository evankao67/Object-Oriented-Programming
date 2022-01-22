#include <bits/stdc++.h>
using namespace std;
template <class T>
class Array
{
public:
    Array(int insize);
    ~Array() {}
    void insert(T data, int slot);
    T getData(int slot) { return arr[slot]; }

private:
    int size;
    T *arr;
};
template<class T>
Array<T>::Array(int insize)
{
    size=insize;
    arr = new T[size];
}
template<class T>
void Array<T>::insert(T data, int slot)
{
    if(slot<size && slot>=0)
        arr[slot]=data;
    else
        cout<<"waring"<<endl;
} 
int main()
{
    Array<int> evan(25);
    for(int i=0;i<25;i++)
    {
        evan.insert((i*3+82)%61, i);
        cout<<evan.getData(i)<<endl;
    }
}