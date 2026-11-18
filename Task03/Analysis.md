# Task 3 – Constructors in Derived Classes and Member Classes

## Task 3.1 – Pass Values to Base Constructors

A derived class can pass values to its base class constructor using a member initializer list.

### Constructor Design

- Student passes personal details to Person.
- Staff passes personal details to Person.
- TeachingAssistant passes values to both Student and Staff and directly initializes the virtual Person base.

### Example

```cpp
class Person
{
protected:
    string name;
    int id;

public:
    Person(string n, int i) : name(n), id(i) {}
};

class Student : virtual public Person
{
public:
    Student(string n, int i) : Person(n, i) {}
};

class Staff : virtual public Person
{
public:
    Staff(string n, int i) : Person(n, i) {}
};

class TeachingAssistant : public Student, public Staff
{
public:
    TeachingAssistant(string n, int i)
        : Person(n, i),
          Student(n, i),
          Staff(n, i) {}
};
```

### Why must the most-derived class initialize the virtual base?

When virtual inheritance is used, the most-derived class is responsible for constructing the virtual base class. Therefore, TeachingAssistant directly initializes Person.

If TeachingAssistant does not initialize Person, the default constructor of Person is used if available. If no suitable default constructor exists, compilation fails.

## Task 3.2 – Member Classes

A member class is an object of another class stored inside a class. It represents a has-a relationship.

### Address Class

Person contains an Address object to store the person's residential address.

### Course Class

Student contains a Course object to store course information.

### Example

```cpp
class Address
{
private:
    string city;
    int pin;

public:
    Address(string c, int p) : city(c), pin(p) {}
};

class Course
{
private:
    string courseName;

public:
    Course(string c) : courseName(c) {}
};

class Person
{
protected:
    string name;
    Address home;

public:
    Person(string n, string city, int pin)
        : name(n), home(city, pin) {}
};

class Student : public Person
{
private:
    Course course;

public:
    Student(string n, string city, int pin, string c)
        : Person(n, city, pin), course(c) {}
};
```

### Explanation

1. Address is created as a member object of Person.
2. Course is created as a member object of Student.
3. The initializer list passes the required values to each member constructor.
4. Member objects are automatically destroyed when their containing object is destroyed.

### Result

Base-class constructors and member-class constructors are initialized through member initializer lists. This improves object initialization and supports reusable class design.
## Task 3.3 – Trace the Order of Construction and Destruction

C++ follows a fixed order when constructing and destroying objects.

### Construction Rules

1. Virtual base classes are constructed first.
2. Direct base classes are constructed next, in the order in which they are declared.
3. Member objects are constructed in the order in which they are declared inside the class.
4. The derived-class constructor body executes last.

### Destruction Rules

Destruction takes place in the reverse order of construction.

1. The derived-class destructor executes first.
2. Member objects are destroyed in reverse declaration order.
3. Base classes are destroyed last, in reverse construction order.

### Expected Order for the University Classes

For a Student object:
- Person
- Address
- Course
- Student

Destruction:
- Student
- Course
- Address
- Person

For a Staff object:
- Person
- Address
- Staff

Destruction:
- Staff
- Address
- Person

For a TeachingAssistant object:
- Person (virtual base)
- Address (Person member)
- Student
- Course (Student member)
- Staff
- TeachingAssistant

Destruction:
- TeachingAssistant
- Staff
- Course
- Student
- Address
- Person

The exact order depends on the order of base classes and member declarations in the actual class definitions.
