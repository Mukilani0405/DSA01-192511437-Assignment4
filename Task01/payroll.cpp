
#include <iostream>
#include <string>
using namespace std;

// Common base class
class Staff
{
protected:
    string name;
    int id;

public:
    Staff(string n, int i) : name(n), id(i) {}

    virtual double pay() const = 0;

    virtual void display() const
    {
        cout << "Name: " << name
             << " | ID: " << id
             << " | Pay: " << pay() << endl;
    }

    virtual ~Staff() = default;

protected:
    static double salaryPay(double basic, double da)
    {
        return basic + da;
    }
};

// Professor class
class Professor : public Staff
{
private:
    double basic, da, research;

public:
    Professor(string n, int i, double b, double d, double r)
        : Staff(n, i), basic(b), da(d), research(r) {}

    double pay() const override
    {
        return salaryPay(basic, da) + research;
    }
};

// Lab Assistant class
class LabAssistant : public Staff
{
private:
    double basic, da;

public:
    LabAssistant(string n, int i, double b, double d)
        : Staff(n, i), basic(b), da(d) {}

    double pay() const override
    {
        return salaryPay(basic, da);
    }
};

// Guest Faculty class
class GuestFaculty : public Staff
{
private:
    double hours, rate;

public:
    GuestFaculty(string n, int i, double h, double r)
        : Staff(n, i), hours(h), rate(r) {}

    double pay() const override
    {
        return hours * rate;
    }
};

int main()
{
    Professor p("Arun", 101, 50000, 21000, 5000);
    LabAssistant l("Kumar", 102, 25000, 10500);
    GuestFaculty g("Priya", 103, 20, 1000);

    Staff* staffList[] = {&p, &l, &g};

    cout << "COLLEGE PAYROLL SYSTEM\n";

    for (Staff* s : staffList)
    {
        s->display();
    }

    return 0;
}
