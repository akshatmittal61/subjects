# Notes

OOPS: Object Oriented Programming

Object-oriented programming aims to implement real-world entities like inheritance, hiding, polymorphism etc in programming. The main aim of OOP is to bind together the data and the functions that operate on them so that no other part of the code can access this data except that function.

# Class

**class**: It is a user defined data type. It represents the set of properties or methods that are common to all objects of one type.

```cpp
class student{
    int roll;   // data members
    string name;
    bool gender;
};
```

_Object_ is an instance of a class.

**Access Specifiers**: They describe the access of data memebers of a class.

-   **public**: accessible in all class in your application.
-   **protected**: accessible within the package in which it is defined and in its subclass(es)(including subclasses declared outside the package)
-   **private**: accessible only within the class in which it is defined.
-   **default** (declared/defined without using any modifier): accessible within same class and package within which its class is defined.

```cpp
class student{
    private:
    int reg_id;

    protected:
    int marks;

    public:
    string name;
};
```
## Shallow Copy
Default constructor does shallow copy, only pointers are copied not the memory
## Deep Copy
Default constructor does shallow copy, only pointers are copied not the memory