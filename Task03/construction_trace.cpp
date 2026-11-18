
#include <iostream>
#include <string>
using namespace std;

class Address
{
public:
    Address()
    {
        cout << "Address constructed\n";
    }

    ~Address()
    {
        cout << "Address destroyed\n";
    }
};

class Course
{
public:
    Course()
    {
        cout << "Course constructed\n";
    }

    ~Course()
    {
        cout << "Course destroyed\n";
    }
};

class Person
{
protected:
    string name;
    Address home;

public:
    Person(string n) : name(n)
    {
        cout << "Person constructed\n";
    }

    ~Person()
    {
        cout << "Person destroyed\n";
    }
};

class Student : virtual public Person
{
protected:
    Course course;

public:
    Student(string n) : Person(n)
    {
        cout << "Student constructed\n";
    }

    ~Student()
    {
        cout << "Student destroyed\n";
    }
};

class Staff : virtual public Person
{
public:
    Staff(string n) : Person(n)
    {
        cout << "Staff constructed\n";
    }

    ~Staff()
    {
        cout << "Staff destroyed\n";
    }
};

class TeachingAssistant : public Student, public Staff
{
public:
    TeachingAssistant(string n)
        : Person(n), Student(n), Staff(n)
    {
        cout << "TeachingAssistant constructed\n";
    }

    ~TeachingAssistant()
    {
        cout << "TeachingAssistant destroyed\n";
    }
};

int main()
{
    cout << "--- Student object ---\n";
    {
        Student s("Kavya");
    }

    cout << "\n--- Staff object ---\n";
    {
        Staff st("Arun");
    }

    cout << "\n--- TeachingAssistant object ---\n";
    {
        TeachingAssistant ta("Priya");
    }

    return 0;
}
