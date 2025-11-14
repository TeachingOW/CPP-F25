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
