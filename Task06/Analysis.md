# Task 6 – Vehicle Rental Fleet Management System

## 6.1 Problem Statement

A vehicle rental company needs a system to manage different vehicle types, including bicycles, two-wheelers, cars, and electric vehicles. The system should calculate rental charges, track rental status, display vehicle details, and support future vehicle extensions.

## 6.2 Proposed Class Hierarchy

- **Vehicle:** Abstract base class containing registration number, daily rate, and rental status.
- **Bicycle:** Represents a bicycle and calculates its rental charge.
- **MotorVehicle:** Intermediate base class containing service information.
- **TwoWheeler:** Represents motorbikes and scooters.
- **Car:** Represents cars and stores seating capacity.
- **ElectricCar:** Extends Car with battery capacity and electricity cost.
- **ElectricBus:** Extends MotorVehicle and represents an electric bus.

## 6.3 OOP Concepts Used

1. **Inheritance:** Derived vehicle classes reuse the common Vehicle properties.
2. **Abstraction:** Vehicle contains the pure virtual rentalCharge() function.
3. **Polymorphism:** A Vehicle pointer array manages different vehicle types and calls their overridden functions.
4. **Encapsulation:** Vehicle data members are protected or private.
5. **Virtual destructor:** Ensures safe destruction through base-class pointers.

## 6.4 Rental and Return Operations

The rent() function changes the vehicle status to rented if it is available.

The returnVehicle() function calculates the rental amount and adds a late fee of Rs.200 per late day. It then changes the status back to available.

Electric vehicle charges include an additional simplified energy cost.

## 6.5 Extension – Electric Bus

An ElectricBus class is added by inheriting from MotorVehicle. It provides its own rental charge calculation and display function.

The existing Vehicle, Car, and other classes do not need modification. The new class can be added to the fleet pointer array.

This demonstrates extensibility through inheritance and runtime polymorphism.

## 6.6 Alternative Design – Single Class with Conditions

An alternative is to create one Vehicle class containing a vehicle type variable and conditional statements for calculating charges.

However, this design requires additional conditions whenever a new vehicle type is introduced. It also stores data that may not be relevant to every vehicle.

The inheritance-based design separates responsibilities and allows new vehicle types to be added more easily.

## 6.7 Conclusion

The Vehicle Rental Fleet Management System demonstrates inheritance, abstraction, encapsulation, and runtime polymorphism. It manages different vehicle types using a common base-class pointer array and supports future extensions such as electric buses.
