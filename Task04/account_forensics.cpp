
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Account
{
protected:
    string holder;

public:
    Account(string name) : holder(name) {}

    virtual double rate() const
    {
        return 3.5;
    }

    virtual void display() const
    {
        cout << "Account Holder: " << holder << endl;
        cout << "Interest Rate: " << rate() << "%" << endl;
    }

    virtual ~Account()
    {
        cout << "Account destroyed: " << holder << endl;
    }
};

class SeniorAccount : public Account
{
private:
    vector<double> history;

public:
    SeniorAccount(string name) : Account(name)
    {
        history = {1000, 2000, 3000};
    }

    double rate() const override
    {
        return 4.0;
    }

    void display() const override
    {
        cout << "Senior Account Holder: " << holder << endl;
        cout << "Interest Rate: " << rate() << "%" << endl;
        cout << "History Records: " << history.size() << endl;
    }

    ~SeniorAccount() override
    {
        cout << "SeniorAccount destroyed: " << holder << endl;
    }
};

int main()
{
    vector<unique_ptr<Account>> accounts;

    accounts.push_back(make_unique<Account>("Arun"));
    accounts.push_back(make_unique<SeniorAccount>("Priya"));

    cout << "--- Account Details ---\n";

    for (const auto& account : accounts)
    {
        account->display();
        cout << endl;
    }

    cout << "--- Runtime Polymorphism ---\n";

    for (const auto& account : accounts)
    {
        cout << account->rate() << "%\n";
    }

    cout << "\n--- Program Ending ---\n";

    return 0;
}
