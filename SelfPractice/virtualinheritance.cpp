#include <bits/stdc++.h>
using namespace std;
class Animal
{
    public:
        Animal(char* inhabitat):habitat(inhabitat){}
        char* getHabitat() {return habitat;}
        ~Animal(){cout<<"kill animal"<<endl;}
    private:
    char* habitat;
};
class Pradator : public virtual Animal
{
    public:
        Pradator(char* inhabitat, char* inprey):Animal(inhabitat), prey(inprey){}
        char* getPrey() {return prey;}
        ~Pradator(){cout<<"kill pradator"<<endl;}
    private:
        char* prey;
};
class Pet : public virtual Animal
{
    public:
        Pet(char* inhabitat, char* inowner):Animal(inhabitat), owner(inowner){}
        char* getOwner() {return owner;}
        ~Pet(){cout<<"kill pet"<<endl;}
    private:
        char* owner;
};
class Cat : public Pradator, public Pet
{
    public:
        Cat(char* inhabitat, char* inprey, char* inowner, char* inname):Animal(inhabitat), Pradator(inhabitat, inprey), Pet(inhabitat, inowner), name(inname){}
        char* getName() {return name;}
        ~Cat(){cout<<"kill cat"<<endl;}
        private:
            char* name;
};
int main()
{
    Cat cat("home", "mice", "Evan", "candy");
    cout<<cat.getHabitat()<<' '<<cat.getPrey()<<' '<<cat.getOwner()<<' '<<cat.getName()<<endl;
}