#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ln '\n'
class Point 
{
    friend istream &operator>>(istream &s, Point &t);
    friend ostream &operator<<(ostream &s, Point &t);
    private:
    int x, y;
};
istream &operator>>(istream &s, Point &t)
{
    cout<<"input 2 int with space"<<ln;
    cin>> t.x >>t.y;
    return s;
}
ostream &operator<<(ostream &s, Point &t)
{
    cout<<"("<<t.x<<", "<<t.y<<")"<<ln;
    return s;
}
int main()
{
    Point T;
    cin>>T;
    cout<<T;
}