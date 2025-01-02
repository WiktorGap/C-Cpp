#include <iostream>
/*class Bazowa
{
public:
    Bazowa(){
        std::cout<<"Konsturktor klasy bazowej"<<std::endl;
    }

    ~Bazowa(){
        std::cout<<"Desturktor klasy bazowej"<<std::endl;
    }

};

class Pochodna:Bazowa
{
public:
    Pochodna(){
        std::cout<<"Konsturktor klasy pochodnej"<<std::endl;
    }
    ~Pochodna(){
        std::cout<<"Destruktor klasy pochodnej"<<std::endl;
    }    
};
*/

class Person
{
public:
    Person(unsigned int _pesel,
            const std::string &_name,
            const std::string &_surname)
    : pesel(_pesel) , name(_name), _surname(_surname){};

protected:
    unsigned int psesel;
    std::string name;
    std::string suername;
};

class Employee:Person 
{
public:
    Employee(unsigned int _id,
            unsigned int _salary)
        : Person(psesel,name,suername),
        id(_id), _salary(_salary) {};

protected:
    unsigned int id;
    unsigned int salary;

};



int main()
{   
    Employee e(1234562456,"Czeseik","Wiesiek",1234,5781);
    std::cout<<e;
    return 0;
}