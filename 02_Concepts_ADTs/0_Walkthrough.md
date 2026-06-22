# Walkthrough: Concepts & Abstract Data Types (ADT)

## Information vs Meaning
* **Data** is a collection of raw facts (e.g., `1001`).
* **Information** is data with meaning (e.g., `1001` is an employee ID).
Data structures give a logical form to this data so algorithms can process it efficiently.

## What is an Abstract Data Type (ADT)?
An **ADT** is a logical description of how data is viewed and the operations that can be performed on it. It hides the implementation details from the user.

Think of an ADT like a vending machine:
* You know the **operations**: Insert coin, press button, get item.
* You **don't need to know** the internal mechanics of how the coin is validated or how the item is pushed out.

### Components of an ADT:
1. **Declaration of data:** What are the components? (e.g., an array and a counter for its size).
2. **Declaration of operations:** What can you do with it? (e.g., `insert()`, `delete()`, `search()`).

By separating the "interface" from the "implementation", we can write cleaner, more modular C code. We implement ADTs in C using `struct` and functions that take a pointer to that `struct`.
