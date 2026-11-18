#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    string name;

    Person(string n) : name(n) {}
};

class Student
{
public:
    Person person;

    Student(string n) : person(n) {}
};

class Staff
{
public:
    Person person;

    Staff(string n) : person(n) {}
};

class TeachingAssistant
{
public:
    Student student;
    Staff staff;

    TeachingAssistant(string n)
        : student(n), staff(n) {}
};

int main()
{
    TeachingAssistant ta("Kavya");

    cout << "Student name: " << ta.student.person.name << endl;
    cout << "Staff name: " << ta.staff.person.name << endl;

    cout << "TeachingAssistant size: "
         << sizeof(ta) << " bytes" << endl;

    return 0;
}
