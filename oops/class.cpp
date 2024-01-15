#include<iostream>
using namespace std;
class student{
    public:
    string name;
    int age;
    bool gender;
    student (){}
    student(student &a){
        name=a.name;
        age=a.age;
        gender=a.gender;

    }
    void printinfo(){
        cout<<name<<endl;
        cout<<age<<endl;
        cout<<gender<<endl;
    }
};
int main(){
student a;
a.name="harsh";
a.age=19;
a.gender=0;
a.printinfo();
student c(a);
c.printinfo();

    return 0;
}