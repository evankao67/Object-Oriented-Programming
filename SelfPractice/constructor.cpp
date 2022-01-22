#include <iostream>
using namespace std;
class App
{
public:
    App(int d) { download = d; }
    ~App(){};
    int getDownload() { return download; }
    void increaseDownload() { ++download; }

private:
    int download;
};
class JJBox : public App
{
public:
    JJBox(int _d) : App(_d) { song = _d * 5; };
    void update() { song = getDownload() * 5; };
    void print() { cout << "JJBox now has " << song << " songs." << endl; };

private:
    int song;
};
class NoseBook : public App
{
public:
    NoseBook(int _d) : App(_d) { Friend = _d * 3 + 5; };
    void update() { Friend = getDownload() * 3 + 5; };
    void print() { cout << "NoseBook now has " << Friend << " friends." << endl; };

private:
    int Friend;
};
int main()
{
    int x, y;
    cin >> x >> y;
    JJBox KKBox(x);
    NoseBook Facebook(y);
    int Case;
    while (cin >> Case)
    {
        if (Case == 1)
        {
            KKBox.increaseDownload();
        }
        else if (Case == 2)
        {
            Facebook.increaseDownload();
        }
        else if (Case == 3)
        {
            KKBox.increaseDownload();
            Facebook.increaseDownload();
        }
        else if (Case == 4)
        {
            KKBox.update();
        }
        else if (Case == 5)
        {
            Facebook.update();
        }
        else if (Case == -1)
        {
            break;
        }
        KKBox.print();
        Facebook.print();
        cout << "==========" << endl;
    }
}