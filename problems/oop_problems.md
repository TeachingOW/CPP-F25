
## 🧩 **1. Parking Lot System**

### **Description**

Design a parking lot that supports multiple types of vehicles (`Car`, `Bike`, `Truck`) and parking spots of different sizes.
Each spot can only accommodate a vehicle of equal or smaller size.
The parking lot must manage available spots and handle vehicle entry/exit.

### **General Design**

* **Classes:**

  * `Vehicle` (base class): stores plate number and size
  * `Car`, `Bike`, `Truck`: derived classes
  * `ParkingSpot`: represents an individual parking spot
  * `ParkingLot`: manages a collection of parking spots
* **Concepts Used:** Inheritance, composition, encapsulation, enums for size

---

<details>
<summary>▶️ C++ Implementation</summary>

```cpp
#include <iostream>
#include <vector>
#include <memory>

enum class VehicleSize { SMALL, MEDIUM, LARGE };

class Vehicle {
protected:
    std::string plate;
    VehicleSize size;
public:
    Vehicle(std::string p, VehicleSize s) : plate(p), size(s) {}
    virtual ~Vehicle() = default;
    VehicleSize getSize() const { return size; }
    std::string getPlate() const { return plate; }
};

class Car : public Vehicle {
public:
    Car(std::string p) : Vehicle(p, VehicleSize::MEDIUM) {}
};
class Bike : public Vehicle {
public:
    Bike(std::string p) : Vehicle(p, VehicleSize::SMALL) {}
};
class Truck : public Vehicle {
public:
    Truck(std::string p) : Vehicle(p, VehicleSize::LARGE) {}
};

class ParkingSpot {
    VehicleSize size;
    Vehicle* vehicle = nullptr;
public:
    ParkingSpot(VehicleSize s) : size(s) {}
    bool canFit(const Vehicle& v) const {
        return !vehicle && static_cast<int>(v.getSize()) <= static_cast<int>(size);
    }
    bool park(Vehicle& v) {
        if (canFit(v)) { vehicle = &v; return true; }
        return false;
    }
    void removeVehicle() { vehicle = nullptr; }
};

class ParkingLot {
    std::vector<ParkingSpot> spots;
public:
    ParkingLot(int n) {
        for (int i = 0; i < n; ++i)
            spots.emplace_back(VehicleSize::MEDIUM);
    }

    bool parkVehicle(Vehicle& v) {
        for (auto& spot : spots)
            if (spot.park(v)) return true;
        return false;
    }
};
```

</details>

---

## 🛒 **2. Online Shopping Cart System**

### **Description**

Build a system that simulates an online shopping cart.
Users can add products, compute totals, and pay using different payment methods.

### **General Design**

* **Classes:**

  * `Product`: stores ID, name, and price
  * `CartItem`: wraps a product with a quantity
  * `ShoppingCart`: holds multiple `CartItem` objects and calculates total
  * `PaymentProcessor` (interface): base class for payment methods
  * `CreditCardPayment`, `PayPalPayment`: implement different payment strategies
* **Concepts Used:** Composition, polymorphism, abstraction

---

<details>
<summary>▶️ C++ Implementation</summary>

```cpp
#include <iostream>
#include <vector>
#include <memory>

class Product {
    int id;
    std::string name;
    double price;
public:
    Product(int id, std::string n, double p) : id(id), name(n), price(p) {}
    double getPrice() const { return price; }
    int getId() const { return id; }
    std::string getName() const { return name; }
};

class CartItem {
    Product product;
    int quantity;
public:
    CartItem(Product p, int q) : product(p), quantity(q) {}
    double total() const { return product.getPrice() * quantity; }
};

class ShoppingCart {
    std::vector<CartItem> items;
public:
    void addItem(const Product& p, int q) { items.emplace_back(p, q); }
    double total() const {
        double sum = 0;
        for (auto& i : items) sum += i.total();
        return sum;
    }
};

class PaymentProcessor {
public:
    virtual void pay(double amount) = 0;
    virtual ~PaymentProcessor() = default;
};

class CreditCardPayment : public PaymentProcessor {
public:
    void pay(double amount) override {
        std::cout << "Paid $" << amount << " using Credit Card.\n";
    }
};

class PayPalPayment : public PaymentProcessor {
public:
    void pay(double amount) override {
        std::cout << "Paid $" << amount << " using PayPal.\n";
    }
};
```

</details>

---

## 📚 **3. Library Management System**

### **Description**

Design a simple library management system to track books, availability, and borrowed items by members.

### **General Design**

* **Classes:**

  * `Book`: represents a book with title and availability
  * `Member`: can borrow or return books
  * `Library`: contains a catalog of books and supports searching
* **Concepts Used:** Encapsulation, aggregation, data management

---

<details>
<summary>▶️ C++ Implementation</summary>

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

class Book {
    int id;
    std::string title;
    bool available = true;
public:
    Book(int i, std::string t) : id(i), title(t) {}
    bool isAvailable() const { return available; }
    void setAvailable(bool val) { available = val; }
    std::string getTitle() const { return title; }
};

class Member {
    std::string name;
    std::vector<Book*> borrowed;
public:
    Member(std::string n) : name(n) {}
    bool borrow(Book& b) {
        if (b.isAvailable()) {
            borrowed.push_back(&b);
            b.setAvailable(false);
            return true;
        }
        return false;
    }
    void returnBook(Book& b) {
        borrowed.erase(std::remove(borrowed.begin(), borrowed.end(), &b), borrowed.end());
        b.setAvailable(true);
    }
};

class Library {
    std::vector<Book> books;
public:
    void addBook(const Book& b) { books.push_back(b); }
    std::vector<Book*> search(const std::string& keyword) {
        std::vector<Book*> result;
        for (auto& b : books)
            if (b.getTitle().find(keyword) != std::string::npos)
                result.push_back(&b);
        return result;
    }
};
```

</details>

---

##  **4. Chat Application**

### **Description**

Design a simple chat system where users can join a room, send messages, and display chat history.

### **General Design**

* **Classes:**

  * `User`: represents a participant
  * `Message`: contains sender, text, and timestamp
  * `ChatRoom`: manages users and messages
* **Concepts Used:** Association, composition, time-based operations

---

<details>
<summary>▶️ C++ Implementation</summary>

```cpp
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

class User {
    std::string username;
public:
    User(std::string u) : username(u) {}
    std::string getName() const { return username; }
};

class Message {
    User sender;
    std::string text;
    std::time_t timestamp;
public:
    Message(const User& u, std::string t)
        : sender(u), text(t), timestamp(std::time(nullptr)) {}
    void display() const {
        std::tm* tm = std::localtime(&timestamp);
        std::cout << "[" << std::put_time(tm, "%H:%M") << "] "
                  << sender.getName() << ": " << text << "\n";
    }
};

class ChatRoom {
    std::string name;
    std::vector<User*> users;
    std::vector<Message> messages;
public:
    ChatRoom(std::string n) : name(n) {}
    void join(User& u) { users.push_back(&u); }
    void send(User& u, const std::string& text) {
        if (std::find(users.begin(), users.end(), &u) != users.end())
            messages.emplace_back(u, text);
    }
    void show() const {
        for (auto& m : messages) m.display();
    }
};
```

</details>

