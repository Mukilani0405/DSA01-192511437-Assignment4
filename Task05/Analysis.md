# Task 5 – Pointers to Objects and this Pointer

## 5.1 Object Access Methods

C++ provides different ways to access objects:

- Direct object access uses the dot operator (.).
- Pointer access uses the arrow operator (->).
- Reference access uses the object name directly.
- Dynamic objects are created using new and released using delete.

## 5.2 this Pointer and Method Chaining

The this pointer refers to the current object. It is useful when a parameter and data member have the same name.

The expression this->discount refers to the object's data member.

Returning *this by reference allows method chaining. Multiple functions can be called in one statement without creating unnecessary copies.

## 5.3 Array of Object Pointers

An array of Cart pointers stores addresses of Cart objects. A loop can access each object and compare its total.

The highest-total search takes O(n) time for n carts.

## 5.4 Alternative – vector of Objects

A vector<Cart> can store objects directly and automatically manage memory. Objects are stored contiguously, whereas an array of pointers can refer to separately allocated objects.

Vector storage is generally simpler, but resizing a vector may invalidate existing pointers and references to its elements.

**Conclusion:** Object pointers, references, and the this pointer provide flexible object access and support efficient method chaining.
