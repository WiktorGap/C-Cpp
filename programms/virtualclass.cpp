#include <iostream>
#include <string>

class Car {
    public:
        Car(const std::string &_man, const std::string &_mod, const std::string &_vin)
            : manufacturer(_man), model(_mod), vin(_vin) {}
        void drive() { std::cout << "Brum brum " << vin << std::endl; }
        void setVin(const std::string &_vin) { this->vin = _vin; }
    protected:
        Car() {}  // chroniony konstruktor domyślny
    private:
        std::string manufacturer;
        std::string model;
        std::string vin;
};

class PetrolCar : virtual public Car {
    public:
        PetrolCar(const std::string &_man, const std::string &_mod, const std::string &_vin)
            : Car(_man, _mod, _vin) {}
};

class ElectricCar : virtual public Car {
    public:
        ElectricCar(const std::string &_man, const std::string &_mod, const std::string &_vin)
            : Car(_man, _mod, _vin) {}
};

class HybridCar : public PetrolCar, public ElectricCar {
    public:
        HybridCar(const std::string &_man, const std::string &_mod, const std::string &_vin)
            : Car("","",""), PetrolCar("","",""), ElectricCar(_man, _mod, _vin) {}
};

int main() {
    HybridCar hc("Toyota", "Prius", "000111222333");
    PetrolCar &pc = static_cast<PetrolCar&>(hc);  // Pokazujemy, że istnieje tylko jeden obiekt klasy `Car`
    ElectricCar &ec = static_cast<ElectricCar&>(hc);

    pc.drive();
    ec.drive();
    
    pc.setVin("40285278352");  // Zmiana tego samego VIN
    ec.drive();

    return 0;
}
