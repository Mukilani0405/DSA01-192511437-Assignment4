
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Cart
{
private:
    string items[10];
    double prices[10];
    int n = 0;
    double discount = 0;

public:
    Cart& add(const string& item, double price)
    {
        if (n < 10)
        {
            items[n] = item;
            prices[n] = price;
            ++n;
        }
        return *this;
    }

    Cart& setDiscount(double discount)
    {
        this->discount = discount;
        return *this;
    }

    double total() const
    {
        double sum = 0;
        for (int i = 0; i < n; i++)
            sum += prices[i];

        return sum - (sum * discount / 100);
    }

    void display() const
    {
        cout << "Shopping Cart\n";
        for (int i = 0; i < n; i++)
            cout << items[i] << " - Rs." << prices[i] << endl;

        cout << fixed << setprecision(2);
        cout << "Final Total: Rs." << total() << endl;
    }
};

int main()
{
    Cart c;

    c.add("Keyboard", 1000)
     .add("Mouse", 500)
     .add("Monitor", 2000)
     .setDiscount(10);

    Cart* ptr = &c;

    cout << "--- Using Object Pointer ---\n";
    ptr->display();

    Cart& ref = c;
    cout << "\n--- Using Object Reference ---\n";
    ref.display();

    Cart* dynamicCart = new Cart();
    dynamicCart->add("USB Cable", 200);
    cout << "\n--- Dynamic Object ---\n";
    dynamicCart->display();
    delete dynamicCart;

    Cart* carts[2] = {&c, new Cart()};
    carts[1]->add("Headphones", 1500);

    int highest = 0;
    for (int i = 1; i < 2; i++)
    {
        if (carts[i]->total() > carts[highest]->total())
            highest = i;
    }

    cout << "\nCart with highest total: Cart "
         << highest + 1 << endl;

    delete carts[1];

    return 0;
}
