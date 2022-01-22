#include <iostream>
#include <time.h>
using namespace std;
class grade{
    public:
    grade();
    grade(int score);
    ~grade(){};
    int getScore();
    private:
    int score;
};
grade::grade(){}
grade::grade(int score){
    this->score=score;
}
int grade::getScore(){
    return score;
}
int main(){
    grade student1(95), student2;
    grade student3=student1;
    student2 = student1;
    cout<<student1.getScore()<<' '<<student2.getScore()<<' '<<student3.getScore()<<' '<<endl;
}