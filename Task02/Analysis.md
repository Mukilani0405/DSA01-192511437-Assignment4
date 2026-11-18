# Task 2 – University People Management

## Task 2.1 – Identify the Relationships

### 1. Person and Student
Student inherits from Person because every student is a person. This is an **is-a relationship** and uses single inheritance.

### 2. Person and Staff
Staff inherits from Person because every staff member is a person. This is an **is-a relationship** and uses single inheritance.

### 3. Student and Staff
TeachingAssistant inherits from both Student and Staff because a teaching assistant is both a student and a staff member. This is an **is-a relationship** and uses multiple inheritance.

### 4. Student and ResearchScholar
ResearchScholar inherits from Student because every research scholar is a student with additional fellowship information. This is an **is-a relationship** and uses single inheritance. Together with the Person-to-Student relationship, it forms multilevel inheritance.

### Overall Inheritance Type

The complete design uses **hybrid inheritance** because it combines hierarchical, multiple and multilevel inheritance.

### Relationship Summary

| Classes | Relationship | Inheritance type |
|---|---|---|
| Person → Student | Is-a | Single |
| Person → Staff | Is-a | Single |
| Student and Staff → TeachingAssistant | Is-a | Multiple |
| Student → ResearchScholar | Is-a | Single / Multilevel chain |

## Conclusion

The university people management system uses inheritance to represent common and specialised information. The hierarchy reduces repeated data and supports different categories of university members.
## Task 2.2 – Resolve the Diamond Problem

### Diamond Problem

The diamond problem occurs when a class inherits from two classes that share the same base class.

In this system:
- Student inherits from Person.
- Staff inherits from Person.
- TeachingAssistant inherits from both Student and Staff.

Without virtual inheritance, TeachingAssistant receives two separate copies of Person. This creates ambiguity when accessing common members such as name, ID and phone number.

### Solution – Virtual Base Class

We can solve this problem by using the `virtual` keyword while inheriting Person.

```cpp
class Person
{
public:
    string name;
    int id;
    string phone;
};

class Student : virtual public Person
{
public:
    string programme;
    double cgpa;
};

class Staff : virtual public Person
{
public:
    string department;
    double salary;
};

class TeachingAssistant : public Student, public Staff
{
};
```

### Advantages of Virtual Inheritance

1. Only one shared Person subobject is created in TeachingAssistant.
2. Duplicate copies of common data are avoided.
3. Ambiguity when accessing Person members is resolved.
4. Memory duplication is reduced.

### Conclusion

Virtual inheritance solves the diamond problem by ensuring that Student and Staff share a single Person base-class subobject inside TeachingAssistant.
## Task 2.3 – Design the Classes

The classes are designed using public inheritance because the derived classes represent specialised forms of Person, Student and Staff.

### C++ Class Declarations

```cpp
#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    int id;
    string phone;

public:
    Person(string n, int i, string p)
        : name(n), id(i), phone(p) {}
};

class Student : virtual public Person
{
protected:
    string programme;
    double cgpa;

public:
    Student(string n, int i, string p, string prog, double c)
        : Person(n, i, p), programme(prog), cgpa(c) {}
};

class Staff : virtual public Person
{
protected:
    string department;
    double salary;

public:
    Staff(string n, int i, string p, string d, double s)
        : Person(n, i, p), department(d), salary(s) {}
};

class TeachingAssistant : public Student, public Staff
{
public:
    TeachingAssistant(string n, int i, string p,
                      string prog, double c,
                      string d, double s)
        : Person(n, i, p),
          Student(n, i, p, prog, c),
          Staff(n, i, p, d, s) {}
};

class ResearchScholar : public Student
{
private:
    double fellowship;

public:
    ResearchScholar(string n, int i, string p,
                    string prog, double c, double f)
        : Person(n, i, p),
          Student(n, i, p, prog, c),
          fellowship(f) {}
};
```

### Design Decisions

1. Person contains common personal information.
2. Student and Staff inherit publicly and virtually from Person.
3. TeachingAssistant inherits publicly from both Student and Staff.
4. ResearchScholar inherits publicly from Student.
5. Fellowship is private because it is specific to ResearchScholar.
6. Protected members allow derived classes to access inherited information while preventing direct access from unrelated code.

### Inheritance Types

- Hierarchical inheritance: Person → Student and Staff.
- Multiple inheritance: Student + Staff → TeachingAssistant.
- Multilevel inheritance: Person → Student → ResearchScholar.
- Hybrid inheritance: Combination of the above structures.

## Task 2.4 – Access Table

The following table shows how Person members are accessed inside Student under different inheritance modes.

| Person member | Public inheritance | Protected inheritance | Private inheritance |
|---|---|---|---|
| Public | Public | Protected | Private |
| Protected | Protected | Protected | Private |
| Private | Not directly accessible | Not directly accessible | Not directly accessible |

### Explanation

- **Public inheritance:** Public members remain public and protected members remain protected.
- **Protected inheritance:** Public and protected members become protected.
- **Private inheritance:** Public and protected members become private.
- Private members of Person cannot be accessed directly by Student in any inheritance mode.

### Result

The university people management hierarchy was designed using virtual inheritance to avoid duplicate Person objects. Appropriate access specifiers protect the data while allowing derived classes to reuse common information.
## Predict the Output – Virtual Inheritance

### My Predicted Output

```text
Person Student Staff TA
```

### Explanation

1. Person is constructed first because it is a virtual base class.
2. Student is constructed next.
3. Staff is constructed after Student.
4. TeachingAssistant is constructed last.

Person is printed only once because virtual inheritance ensures that TeachingAssistant contains one shared Person base-class subobject.

### Verification

The predicted output must be compared with the actual output after compiling and running the given program.
