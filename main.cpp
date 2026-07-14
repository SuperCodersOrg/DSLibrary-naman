#include <iostream>
#include "hashMap.h"
using namespace std;
class Student
{
public:
    int roll;
    std::string name;

    Student() = default;

    Student(int r, std::string n)
    {
        roll = r;
        name = n;
    }

    bool operator==(const Student& other) const
    {
        return roll == other.roll;
    }
};

int main()
{
HashMap<Student, float> mp;

mp.set(Student(1,"Naman"),8.7f);
mp.set(Student(2,"Rahul"),9.1f);

std::cout<<mp.get(Student(1,""))<<'\n';
std::cout<<mp.get(Student(2,""))<<'\n';
}


