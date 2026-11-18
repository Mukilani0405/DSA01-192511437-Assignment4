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
## 4.3 Predict the Output

**Expected output:**

3.5 4 3.5

**Explanation:**

The rate() function is non-virtual, so the base-class version is executed through the Account pointer. The vrate() function is virtual, so runtime polymorphism executes the SeniorAccount version. When the derived object is copied into an Account object, object slicing occurs and only the base-class portion is retained.
## 4.5 Alternative Design – Single Class with Type Checking

An alternative is to use a single Account class with a type variable and conditional statements to calculate interest rates.

However, this approach has disadvantages:
- Adding a new account type requires modifying the existing class.
- Conditional statements increase as account types increase.
- It does not provide the same flexibility as runtime polymorphism.

The corrected inheritance-based design is better because each account type implements its own rate() function. Smart pointers also provide automatic memory management.

**Conclusion:** Virtual functions, virtual destructors, and smart pointers make the account system safer, reusable, and easier to extend.
