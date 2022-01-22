#include <bits/stdc++.h>
using namespace std;
class Student
{
public:
    Student(char *inname, int inage){name=inname, age=inage;}
    //void setData(char *inname, int inage);
    int getAge() { return age; }
    char *getName() { return name; }
    ~Student(){cout<<"kill student"<<endl;}
private:
    char *name;
    int age;
};
//void Student::setData(char *inname, int inage)
//{
    //name = inname;
    //age = inage;
//}
class Graduated : public Student
{
public:
    Graduated(char *inname, int inage, int insalary);
    int getSalary() { return salary; }
    ~Graduated(){cout<<"kill graduated"<<endl;}
private:
    int salary;
};
Graduated::Graduated(char *inname, int inage, int insalary) : Student(inname, inage), salary(insalary)
{}
class ForiegnG : public Graduated
{
    public:
        ForiegnG(char*, int, int, char*);
        char* getNation() {return nation;}
        ~ForiegnG(){cout<<"kill foriegn"<<endl;}
    private:
        char* nation;
};
ForiegnG::ForiegnG(char* a, int b, int c, char* d):Graduated(a, b, c), nation(d)
{}
int main()
{
    Student Evan("Evan", 19);
    cout << Evan.getName() << ' ' << Evan.getAge() << endl;
    Graduated Paul("Paul", 20, 10000);
    cout << Paul.getName() << ' ' << Paul.getAge() << ' ' << Paul.getSalary() << endl;
    ForiegnG Ichiro("Ichiro", 55, 46710000, "Japan");
    cout<< Ichiro.getName()<<' '<<Ichiro.getAge()<<' '<<Ichiro.getSalary()<<' '<<Ichiro.getNation()<<endl;
}