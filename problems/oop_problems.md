
##  **1. Parking Lot System**

### **Description**

Design a system to manage a parking lot that supports multiple vehicle types and parking spot sizes.
Each vehicle type occupies a different space size, and the lot must track available and occupied spots.

---

### **Class Design**

#### **Class: `Vehicle` (Abstract)**

| Attribute     | Type          | Description                |
| ------------- | ------------- | -------------------------- |
| `plateNumber` | `std::string` | Unique vehicle ID          |
| `size`        | `VehicleSize` | Enum: SMALL, MEDIUM, LARGE |

**Methods:**

* `getPlateNumber() const` → `std::string`
* `getSize() const` → `VehicleSize`

**Derived Classes:**

* `Bike`, `Car`, `Truck` – each defines its size in the constructor.

---

#### **Class: `ParkingSpot`**

| Attribute | Type          | Description                       |
| --------- | ------------- | --------------------------------- |
| `size`    | `VehicleSize` | Max vehicle size it can hold      |
| `vehicle` | `Vehicle*`    | Pointer to current parked vehicle |

**Methods:**

* `bool canFit(const Vehicle& v)` – checks if a vehicle can fit
* `bool park(Vehicle& v)` – parks vehicle if possible
* `void removeVehicle()` – frees the spot
* `bool isOccupied() const`

---

#### **Class: `ParkingLot`**

| Attribute | Type                       | Description                  |
| --------- | -------------------------- | ---------------------------- |
| `spots`   | `std::vector<ParkingSpot>` | All parking spots in the lot |

**Methods:**

* `bool parkVehicle(Vehicle& v)` – attempts to find and assign a spot
* `void removeVehicle(const std::string& plate)` – removes by plate
* `int availableSpots() const` – returns count of free spots

---

### **Design Notes**

* **Inheritance** for vehicle hierarchy (`Vehicle → Car/Bike/Truck`)
* **Composition**: `ParkingLot` *has many* `ParkingSpot`s
* **Encapsulation** hides state and validation logic in each class

---

##  **2. Online Shopping Cart System**

### **Description**

Model an online shopping cart where customers add items, view totals, and choose payment methods.

---

### **Class Design**

#### **Class: `Product`**

| Attribute | Type          | Description        |
| --------- | ------------- | ------------------ |
| `id`      | `int`         | Product identifier |
| `name`    | `std::string` | Product name       |
| `price`   | `double`      | Unit price         |

**Methods:**

* `getId() const`
* `getName() const`
* `getPrice() const`

---

#### **Class: `CartItem`**

| Attribute  | Type      | Description         |
| ---------- | --------- | ------------------- |
| `product`  | `Product` | Product in the cart |
| `quantity` | `int`     | Quantity selected   |

**Methods:**

* `getSubtotal() const` → `price * quantity`
* `increaseQuantity(int)`
* `decreaseQuantity(int)`

---

#### **Class: `ShoppingCart`**

| Attribute | Type                    | Description        |
| --------- | ----------------------- | ------------------ |
| `items`   | `std::vector<CartItem>` | List of cart items |

**Methods:**

* `void addItem(const Product&, int quantity)`
* `void removeItem(int productId)`
* `double calculateTotal() const`
* `void clearCart()`

---

#### **Abstract Class: `PaymentProcessor`**

| Method                                | Return | Description                |
| ------------------------------------- | ------ | -------------------------- |
| `virtual void pay(double amount) = 0` | —      | Abstract payment interface |

**Derived Classes:**

* `CreditCardPayment`
* `PayPalPayment`
* `GiftCardPayment` (optional)

Each implements `pay(double amount)` differently.

---

### **Design Notes**

* Uses **composition** (`ShoppingCart` → `CartItem`s)
* Uses **polymorphism** for different payment strategies
* Easily extensible with new payment types or discount logic

---

##  **3. Library Management System**

### **Description**

Manage books, members, and borrowing transactions in a small library.

---

### **Class Design**

#### **Class: `Book`**

| Attribute     | Type          | Description       |
| ------------- | ------------- | ----------------- |
| `id`          | `int`         | Book ID           |
| `title`       | `std::string` | Title             |
| `author`      | `std::string` | Author name       |
| `isAvailable` | `bool`        | Availability flag |

**Methods:**

* `getTitle() const`
* `getAuthor() const`
* `bool available() const`
* `void setAvailable(bool)`

---

#### **Class: `Member`**

| Attribute       | Type                 | Description            |
| --------------- | -------------------- | ---------------------- |
| `name`          | `std::string`        | Member’s name          |
| `borrowedBooks` | `std::vector<Book*>` | List of borrowed books |

**Methods:**

* `bool borrow(Book&)`
* `void returnBook(Book&)`
* `int totalBorrowed() const`

---

#### **Class: `Library`**

| Attribute | Type                | Description      |
| --------- | ------------------- | ---------------- |
| `books`   | `std::vector<Book>` | Catalog of books |

**Methods:**

* `void addBook(const Book&)`
* `std::vector<Book*> searchByTitle(const std::string&)`
* `void displayAvailableBooks() const`

---

### **Design Notes**

* **Aggregation:** `Member` holds references to `Book` (does not own them)
* **Encapsulation:** borrow/return logic checks availability internally
* Could be extended to track **due dates** and **fines**

---

##  **4. Chat Application**

### **Description**

Design a chat room system where users can join rooms, send messages, and view chat history.

---

### **Class Design**

#### **Class: `User`**

| Attribute  | Type          | Description    |
| ---------- | ------------- | -------------- |
| `username` | `std::string` | User’s name    |
| `status`   | `std::string` | Online/Offline |

**Methods:**

* `getName() const`
* `setStatus(const std::string&)`

---

#### **Class: `Message`**

| Attribute   | Type          | Description           |
| ----------- | ------------- | --------------------- |
| `sender`    | `User`        | Sender of the message |
| `content`   | `std::string` | Message text          |
| `timestamp` | `std::time_t` | Time sent             |

**Methods:**

* `getFormattedTime() const`
* `getText() const`
* `getSender() const`

---

#### **Class: `ChatRoom`**

| Attribute  | Type                   | Description     |
| ---------- | ---------------------- | --------------- |
| `roomName` | `std::string`          | Room identifier |
| `users`    | `std::vector<User*>`   | Active users    |
| `messages` | `std::vector<Message>` | Chat log        |

**Methods:**

* `void join(User&)`
* `void leave(User&)`
* `void sendMessage(User&, const std::string&)`
* `void showChatHistory() const`

---

### **Design Notes**

* **Association:** Users belong to multiple ChatRooms
* **Composition:** ChatRoom contains its Messages
* Can evolve to support **private messages**, **attachments**, or **timestamps per message**

---


# Youtube Mock Interview
- [link](https://www.youtube.com/watch?v=1qw5ITr3k9E)(Interview is in Python)
