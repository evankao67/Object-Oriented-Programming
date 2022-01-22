#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ln '\n'
void temperature(int t) throw(char const *, int)
{
    if (t == 100)
        throw "Boiling";
    else if (t == 0)
        throw "Freezing";
    else
        throw t;
}
int main()
{
    try
    {
        try
        {
            temperature(13);
        }
        catch (int x)
        {
            cout << "Temperature = " << x <<" deg C" << endl;
        }
        temperature(0);
    }
    catch (char const *str)
    {
        cout << str << endl;
    }
}