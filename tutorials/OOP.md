## OOP Fundamentals

- [Classes and Objects](https://algomaster.io/learn/lld/classes-and-objects)
- [Enums](https://algomaster.io/learn/lld/enums)
- [Interfaces](https://algomaster.io/learn/lld/interfaces)
- [Encapsulation](https://algomaster.io/learn/lld/encapsulation)
- [Abstraction](https://algomaster.io/learn/lld/abstraction)
- [Inheritance](https://algomaster.io/learn/lld/inheritance)
- [Polymorphism](https://algomaster.io/learn/lld/polymorphism)


##  Class Relationships
- [Association](https://algomaster.io/learn/lld/association)
- [Aggregation](https://algomaster.io/learn/lld/aggregation)
- [Composition](https://algomaster.io/learn/lld/composition)
- [Dependency](https://algomaster.io/learn/lld/dependency)

##  Design Principles
- [DRY Principle](https://algomaster.io/learn/lld/dry)
- [YAGNI Principle](https://algomaster.io/learn/lld/yagni)
- [KISS Principle](https://algomaster.io/learn/lld/kiss)
- [SOLID Principles with Pictures](https://medium.com/backticks-tildes/the-s-o-l-i-d-principles-in-pictures-b34ce2f1e898)
- [SOLID Principles with Code](https://blog.algomaster.io/p/solid-principles-explained-with-code)



## Example 
What design principle(s) below class is breaking? 
- this is adaopted from https://x.com/SumitM_X 
```cpp
class FeeCalculator {
public:
    double calculateFee(Instrument* instrument) {
        if (dynamic_cast<Stock*>(instrument)) {
            return 1.5;
        } else if (dynamic_cast<Bond*>(instrument)) {
            return 2.0;
        } else {
            return 0.0;
        }
    }
};
```

<details>
  <summary>  `FeeCalculator` class is breaking **multiple core OOP design principles**. Here are the main ones: </summary>

##  **1. Violation of the Open–Closed Principle (OCP)**

**OCP:** *Classes should be open for extension, but closed for modification.*

Your `calculateFee()` method must be **edited every time you add a new instrument type**:

```cpp
else if (dynamic_cast<Option*>(instrument)) ...
```

This means your class is **not closed for modification**.
A single new instrument forces changes in this class.

---

##  **2. Violation of the Single Responsibility Principle (SRP)**

**SRP:** *A class should have only one reason to change.*

`FeeCalculator` is now responsible for:

* Knowing about all instrument types
* Deciding how to compute fee for each instrument

This mixes **instrument type logic** with **fee logic** → one class handling multiple responsibilities.

---

##  **3. Violation of Polymorphism / Liskov Substitution Principle (LSP)**

Instead of **using dynamic dispatch** (virtual methods), the class:

* Checks object types explicitly using `dynamic_cast`
* Branches based on concrete types

This breaks proper polymorphism, because:

* The base class `Instrument` cannot be substituted for its subclasses without special handling.
* Each subclass should define its **own fee behavior**, not the calculator guessing.

---

##  **4. Violation of the Dependency Inversion Principle (DIP)**

**DIP:** *Depend on abstractions, not concrete types.*

This class depends directly on the concrete classes:

```cpp
Stock
Bond
```

Making it rigid and fragile.

---

##  **Correct OOP version (polymorphism)**

Let each instrument compute its own fee:

```cpp
class Instrument {
public:
    virtual ~Instrument() = default;
    virtual double fee() const = 0;
};

class Stock : public Instrument {
public:
    double fee() const override { return 1.5; }
};

class Bond : public Instrument {
public:
    double fee() const override { return 2.0; }
};

class FeeCalculator {
public:
    double calculateFee(const Instrument* instrument) const {
        return instrument->fee();   // polymorphic call
    }
};
```

</details>


