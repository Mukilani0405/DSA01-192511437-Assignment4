
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Vehicle
{
protected:
    string regNo;
    double dailyRate;
    bool rented;

public:
    Vehicle(string reg, double rate)
        : regNo(reg), dailyRate(rate), rented(false) {}

    virtual double rentalCharge(int days) const = 0;

    virtual void display() const
    {
        cout << "Registration: " << regNo
             << " | Daily Rate: Rs." << dailyRate
             << " | Status: "
             << (rented ? "Rented" : "Available") << endl;
    }

    void rent()
    {
        if (!rented)
        {
            rented = true;
            cout << regNo << " rented successfully.\n";
        }
        else
            cout << regNo << " is already rented.\n";
    }

    void returnVehicle(int days, int lateDays)
    {
        if (rented)
        {
            double amount = rentalCharge(days) + lateDays * 200;
            rented = false;

            cout << regNo << " returned successfully.\n";
            cout << "Rental Amount: Rs." << amount << endl;
        }
        else
            cout << regNo << " was not rented.\n";
    }

    virtual ~Vehicle() {}
};

class Bicycle : public Vehicle
{
public:
    Bicycle(string reg, double rate) : Vehicle(reg, rate) {}

    double rentalCharge(int days) const override
    {
        return dailyRate * days;
    }

    void display() const override
    {
        cout << "BICYCLE | ";
        Vehicle::display();
    }
};

class MotorVehicle : public Vehicle
{
protected:
    string serviceDue;

public:
    MotorVehicle(string reg, double rate, string service)
        : Vehicle(reg, rate), serviceDue(service) {}
};

class TwoWheeler : public MotorVehicle
{
public:
    TwoWheeler(string reg, double rate, string service)
        : MotorVehicle(reg, rate, service) {}

    double rentalCharge(int days) const override
    {
        return dailyRate * days;
    }

    void display() const override
    {
        cout << "TWO WHEELER | ";
        Vehicle::display();
        cout << "Service Due: " << serviceDue << endl;
    }
};

class Car : public MotorVehicle
{
protected:
    int seatingCapacity;

public:
    Car(string reg, double rate, string service, int seats)
        : MotorVehicle(reg, rate, service),
          seatingCapacity(seats) {}

    double rentalCharge(int days) const override
    {
        return dailyRate * days;
    }

    void display() const override
    {
        cout << "CAR | ";
        Vehicle::display();
        cout << "Seats: " << seatingCapacity
             << " | Service Due: " << serviceDue << endl;
    }
};

class ElectricCar : public Car
{
private:
    double batteryCapacity;
    double costPerKWh;

public:
    ElectricCar(string reg, double rate, string service,
                int seats, double battery, double cost)
        : Car(reg, rate, service, seats),
          batteryCapacity(battery), costPerKWh(cost) {}

    double rentalCharge(int days) const override
    {
        return dailyRate * days +
               batteryCapacity * 0.5 * costPerKWh * days;
    }

    void display() const override
    {
        cout << "ELECTRIC CAR | ";
        Vehicle::display();
        cout << "Seats: " << seatingCapacity
             << " | Battery: " << batteryCapacity << " kWh"
             << " | Service Due: " << serviceDue << endl;
    }
};

// New vehicle type added without modifying existing classes
class ElectricBus : public MotorVehicle
{
private:
    double batteryCapacity;

public:
    ElectricBus(string reg, double rate, string service,
                double battery)
        : MotorVehicle(reg, rate, service),
          batteryCapacity(battery) {}

    double rentalCharge(int days) const override
    {
        return dailyRate * days +
               batteryCapacity * 0.3 * 8 * days;
    }

    void display() const override
    {
        cout << "ELECTRIC BUS | ";
        Vehicle::display();
        cout << "Battery: " << batteryCapacity << " kWh"
             << " | Service Due: " << serviceDue << endl;
    }
};

int main()
{
    cout << fixed << setprecision(2);

    Bicycle bicycle("BIKE101", 100);
    TwoWheeler bike("BIKE202", 250, "2026-12-15");
    Car car("CAR303", 1000, "2026-12-20", 5);
    ElectricCar ev("EV404", 1500, "2026-12-25",
                   5, 60, 8);
    ElectricBus bus("BUS505", 3000, "2026-12-30", 200);

    Vehicle* fleet[] = {&bicycle, &bike, &car, &ev, &bus};

    cout << "===== VEHICLE RENTAL FLEET =====\n";

    for (Vehicle* v : fleet)
        v->display();

    cout << "\n===== RENTAL PROCESS =====\n";

    for (Vehicle* v : fleet)
        v->rent();

    cout << "\n===== RETURN PROCESS =====\n";

    bicycle.returnVehicle(2, 0);
    bike.returnVehicle(3, 1);
    car.returnVehicle(2, 0);
    ev.returnVehicle(2, 1);
    bus.returnVehicle(1, 0);

    cout << "\n===== UPDATED FLEET STATUS =====\n";

    for (Vehicle* v : fleet)
        v->display();

    return 0;
}
