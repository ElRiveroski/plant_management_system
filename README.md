# plant_management_system
C++ project demonstrating OOP, inheritance, polymorphism, STL algorithms, and dynamic memory management via a plant management system


# Plant & Flower Management System (C++)

A console-based C++ application that manages a dynamic collection of plants and flowers. The project demonstrates object-oriented design, inheritance, polymorphism, and use of the C++ Standard Library for data management and algorithms.


## Overview

This system models a simple “garden” where users can add, remove, view, and organize items. It is designed to highlight core software engineering concepts, including dynamic memory management, runtime polymorphism, and algorithmic sorting.


## Features

* Add Plant and Flower objects at runtime
* Remove items by name
* Display all entries using polymorphic behavior
* Compute total cost across all items
* Sort collection by:

  * Name
  * Cost
* Menu-driven interface for user interaction


## Technical Highlights

### Object-Oriented Design

* Base class: `Plant` 
* Derived class: `Flower` extending `Plant` 
* Virtual `display()` method enables runtime polymorphism

### Data Structures and Memory

* Uses `std::vector<Plant*>` for dynamic storage 
* Dynamic allocation via `new`
* Explicit deallocation when removing elements

### Standard Library Usage

* `std::sort` with custom comparator functions for ordering
* `std::find_if` with lambda expressions for search operations

### Operator Overloading

* Overloaded `operator<<` for formatted output
* Overloaded `operator==` for name-based comparison


## Program Flow

The application runs a menu-driven loop:

```
1. Add a new plant
2. Remove a plant
3. Display your plants
4. Total Cost
5. Sort by plant name
6. Sort by plant cost
7. Quit
```

User input determines the operation executed on the collection.

---

## Tech Stack

* C++
* Standard Template Library (vector, algorithm)
* Object-Oriented Programming


## Key Outcomes

* Applied inheritance and polymorphism in C++
* Implemented dynamic data structures using pointers and STL containers
* Utilized standard algorithms for sorting and searching
* Structured code with separation of interface and implementation


## Future Improvements

* Replace raw pointers with `std::unique_ptr` to align with modern C++ practices
* Add file persistence (save/load functionality)
* Improve input validation and error handling
* Extend functionality with search and filtering capabilities




