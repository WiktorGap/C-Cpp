#include <iostream>
#include <cmath>  // dla M_PI
/*
class Bazowa {
    public:
        virtual void wirtualna() {
            std::cout << "Metoda wirtualna w klasie bazowej" << std::endl;
        }
        void normalna() {
            std::cout << "Metoda normalna w klasie bazowej" << std::endl;
        }
};

class Pochodna : public Bazowa {
    public:
        virtual void wirtualna()  {  // 'override' jest opcjonalne, ale zalecane
            std::cout << "Metoda wirtualna w klasie pochodnej" << std::endl;
        }
        void normalna() {
            std::cout << "Metoda normalna w klasie pochodnej" << std::endl;
        }
};
*/

class Shape {
    public:
        virtual ~Shape() {};  // destruktor wirtualny, pusty
        virtual double circum() = 0;  // metoda czysto wirtualna
        virtual double area() = 0;    // metoda czysto wirtualna
};

class Rectangular : public Shape {
    public:
        Rectangular(double w, double h) : width(w), height(h) {};
        double circum() override { return 2 * (width + height); }  // poprawiony brak nawiasów i 'return'
        double area() override { return width * height; }          // poprawiony brak nawiasów i 'return'
    private:
        double width, height;
};

class Circle : public Shape {
    public:
        Circle(double r) : radius(r) {};
        double circum() override { return 2 * M_PI * radius; }   // poprawione nawiasy
        double area() override { return M_PI * radius * radius; } // poprawione nawiasy
    private:
        double radius;
};

void print(Shape &s) {
    std::cout << "Obwód: " << s.circum() << ", Pole: " << s.area() << std::endl;
}

int main() {
    Rectangular rect(20, 10);
    Circle cir(20);  

    print(cir);      
    print(rect);
    



    Shape &shape = re;
    Circle &ref = dynamic_cast<Circle&>(shape);
    
    
    Shape &shape = rect;
    Circle &ref = dynamic_cast<Circle&>(shape);



    
    return 0;
}
