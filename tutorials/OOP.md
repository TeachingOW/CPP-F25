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
 this is adopted from <a href="https://x.com/SumitM_X">https://x.com/SumitM_X</a></p>

```cpp
class FeeCalculator {
public:
    double calculateFee(Instrument* instrument) {
        if (dynamic_cast&lt;Stock*&gt;(instrument)) {
            return 1.5;
        } else if (dynamic_cast&lt;Bond*&gt;(instrument)) {
            return 2.0;
        } else {
            return 0.0;
        }
    }
};
```

  
### 1. Violation of the Open–Closed Principle (OCP)
  <p><em>OCP:</em> Classes should be open for extension, but closed for modification.</p>
  <p>Your <code>calculateFee()</code> method must be <strong>edited every time you add a new instrument type</strong>:</p>

  ```cpp
else if (dynamic_cast&lt;Option*&gt;(instrument)) ...
  ```

  <p>This means your class is <strong>not closed for modification</strong>. A single new instrument forces changes in this class.</p>

  <hr>

### 2. Violation of the Single Responsibility Principle (SRP)
  <p><em>SRP:</em> A class should have only one reason to change.</p>
  
  <ul>
    <li>Knowing about all instrument types</li>
    <li>Deciding how to compute fee for each instrument</li>
  </ul>
  <p>This mixes <strong>instrument type logic</strong> with <strong>fee logic</strong> → one class handling multiple responsibilities.</p>

  <hr>

###  3. Violation of Polymorphism / Liskov Substitution Principle (LSP)
  <p>Instead of <strong>using dynamic dispatch</strong>, the class:</p>
  <ul>
    <li>Checks object types explicitly using <code>dynamic_cast</code></li>
    <li>Branches based on concrete types</li>
  </ul>
  <p>This breaks proper polymorphism because:</p>
  <ul>
    <li>The base class <code>Instrument</code> cannot be substituted for its subclasses without special handling.</li>
    <li>Each subclass should define its <strong>own fee behavior</strong>, not the calculator guessing.</li>
  </ul>

  <hr>

### 4. Violation of the Dependency Inversion Principle (DIP)
  <p><em>DIP:</em> Depend on abstractions, not concrete types.</p>
  <p>This class depends directly on the concrete classes:</p>

  ```cpp
Stock
Bond
  ```

  <p>Making it rigid and fragile.</p>

  <hr>

  <h3>Correct OOP version (polymorphism)</h3>

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
        return instrument-&gt;fee();   // polymorphic call
    }
};
```