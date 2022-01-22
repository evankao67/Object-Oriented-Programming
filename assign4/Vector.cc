#include <iostream>
#include "Vector.h"
using namespace std;
ostream& operator<<(ostream& out, const Vector& c)
{
    out<<'(';
    for(int i=0;i<c.Size-1;i++)
        out<<c.arr[i]<<", ";
    out<<c.arr[c.Size-1]<<')';
    return out;
}
Vector::Vector(int size)
{
    arr = new double[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }
    Size = size;
    Length = 0;
}
Vector::Vector(int size, double elem[])
{
    arr = new double[size];
    double add = 0;
    for (int i = 0; i < size; i++)
    {
        arr[i] = elem[i];
        add += arr[i] * arr[i];
    }
    Size = size;
    Length = sqrt(add);
}
Vector::Vector(const Vector &v)
{
    Size = v.Size;
    Length = v.Length;
    arr = new double[Size];
    copy(v);
}
void Vector::copy(const Vector &v)
{
    double *p = arr + Size;
    double *q = v.arr + Size;
    while (p > arr)
        *--p = *--q;
}
Vector::~Vector()
{
    delete [] arr;
}
double Vector::length()
{
    double add=0;
    for(int i=0;i<Size;i++)
    {
        add+=arr[i]*arr[i];
    }
    return sqrt(add);
}
void Vector::setDimension(int i)
{
    int K;
    if(i>Size)
        K=i;
    else    
        K=Size; 
    double *tmp=new double[K];
    for(int j=0;j<Size;j++)
    {
        tmp[j]=arr[j];
    }
    delete [] arr;
    arr = new double[i];
    Size=i;
    for(int j=0;j<Size;j++)
    {
        arr[j]=tmp[j];
    }
    delete [] tmp;
}
Vector &Vector::operator=(const Vector &v)
{
    if(this==&v)
        return *this;
    delete [] arr;
    Size=v.Size;
    arr = new double[Size];
    for(int j=0;j<Size;j++)
    {
        arr[j]=v.arr[j];
    }
    return *this;
}
Vector Vector::operator-()
{
    Vector tmp(Size);
    for(int j=0;j<Size;j++)
    {
        tmp.arr[j]=0-arr[j];
    }   
    return tmp;
}
Vector Vector::operator+(Vector c)
{
    // Put your code hear...
    Vector temp(Size);
    for(int i=0;i<Size;i++)
    {
        temp.arr[i]=arr[i]+c.arr[i];
    }
    return temp;
    //
}
Vector Vector::operator-(Vector c)
{
    // Put your code hear...
    Vector temp(Size);
    for(int i=0;i<Size;i++)
    {
        temp.arr[i]=arr[i]-c.arr[i];
    }
    return temp;
    //
}

Vector Vector::operator*(double index)
{
    // Put your code hear...
    Vector temp(Size);
    double add=0;
    for(int i=0;i<Size;i++)
    {
        temp.arr[i]=arr[i]*index;
        add += temp.arr[i] * temp.arr[i];
    }
    temp.Length = sqrt(add);
    return temp;
    //
}
Vector &Vector::operator+=(Vector c)
{
    // Put your code hear...
    for(int i=0;i<Size;i++)
    {
        arr[i]+=c.arr[i];
    }
    return *this;
    //
}
Vector &Vector::operator-=(Vector c)
{
    // Put your code hear...
    for(int i=0;i<Size;i++)
    {
        arr[i]-=c.arr[i];
    }
    return *this;
    //
}
Vector &Vector::operator*=(double index)
{
    // Put your code hear...
    for(int i=0;i<Size;i++)
    {
        arr[i]*=index;
    }
    return *this;
    //
}
bool Vector::operator==(Vector c)
{
    // Put your code hear...
    if(Size!=c.Size)
        return false;
    for(int i=0;i<Size;i++)
    {
        if(arr[i]!=c.arr[i])
            return false;
    }
    return true;
    //
}
bool Vector::operator!=(Vector c)
{
    // Put your code hear...
    if(Size!=c.Size)
        return true;
    for(int i=0;i<Size;i++)
    {
        if(arr[i]!=c.arr[i])
            return true;
    }
    return false;
    //
}
double &Vector::operator[](int slot)
{
    if(slot>=0&&slot<Size)
        return arr[slot];
}
Vector operator*(double index, Vector v)
{
    return v*index;
}
