# Task 4 – Pointers to Derived Classes: Forensics

## 4.1 Analysis of the Existing Account System

The existing Account system contains the following problems:

1. **Non-virtual rate function:** The rate() function in the base class is not virtual. Therefore, calling it through a base-class pointer uses static binding and executes the base-class version.
2. **Non-virtual destructor:** The base-class destructor is not virtual. Deleting a derived object through a base-class pointer can cause undefined behavior.
3. **Memory leak:** The SeniorAccount class dynamically allocates history memory. If it is not released properly, memory leakage occurs.
4. **Object slicing:** Assigning a derived object to a base-class object copies only the base-class portion. The derived-class data is lost.

## 4.2 Proposed Corrections

- Declare the rate() function as virtual in the base class.
- Use override in the derived class.
- Declare the base-class destructor as virtual.
- Release dynamically allocated memory properly or use smart pointers.
- Use base-class pointers or references to preserve runtime polymorphism and avoid object slicing.
