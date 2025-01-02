#include <iostream>
#include <cstring>

class Smartphone
{
public:
    virtual void showInfo() const = 0;
    virtual ~Smartphone() {};
};

class Params : public Smartphone
{
public:
    static int id;
    
    Params(const std::string &_company, const unsigned int &_price, const std::string &_model, const char *_energyCategory, bool _factory) 
        : company(_company), price(_price), model(_model), usage(_factory)
    {
        energyCategory = new char[strlen(_energyCategory) + 1];
        strcpy(energyCategory, _energyCategory);
        id++;
    }

    ~Params()
    {
        delete[] energyCategory;
    }

    Params(const Params &source) 
        : company(source.company), price(source.price), model(source.model), usage(source.usage)
    {
        energyCategory = new char[strlen(source.energyCategory) + 1];
        strcpy(energyCategory, source.energyCategory);
    }

    Params& operator=(const Params &source)
    {
        if (this == &source)
            return *this;
        delete[] energyCategory;
        energyCategory = new char[strlen(source.energyCategory) + 1];
        strcpy(energyCategory, source.energyCategory);
        company = source.company;
        model = source.model;
        price = source.price;
        usage = source.usage;
        return *this;
    }

    const bool inUsage() const
    {
        return usage;
    }

    void showInfo() const override
    {
        std::cout << "Company: " << company << ", Model: " << model << ", Price: $" << price 
                  << ", Energy Category: " << energyCategory << ", Usage: " 
                  << (usage ? "New" : "Used") << std::endl;
    }

    friend std::ostream& operator<<(std::ostream &os, const Params &a)
    {
        os << "Company: " << a.company << ", Model: " << a.model << ", Price: $" << a.price 
           << ", Energy Category: " << a.energyCategory << ", Usage: " 
           << (a.usage ? "New" : "Used");
        return os;
    }

    bool operator==(const Params &other) const
    {
        return model == other.model && company == other.company && price == other.price 
            && strcmp(energyCategory, other.energyCategory) == 0;
    }

private:
    char *energyCategory;
    bool usage;
    std::string company;
    unsigned int price;
    std::string model;
};

int Params::id = 0;

int main()
{
    Params phone1("Apple", 1200, "iPhone 14", "A++", true);
    Params phone2("Samsung", 1000, "Galaxy S23", "A+", false);
    Params phone3(phone1); // test konstruktora kopiującego

    std::cout << "Phone 1:\n" << phone1 << std::endl;
    std::cout << "Phone 2:\n" << phone2 << std::endl;
    std::cout << "Phone 3 (copy of Phone 1):\n" << phone3 << std::endl;

    std::cout << "\nUsing assignment operator to copy Phone 2 to Phone 1\n";
    phone1 = phone2;

    std::cout << "After assignment:\nPhone 1:\n" << phone1 << std::endl;
    std::cout << "Phone 2:\n" << phone2 << std::endl;

    std::cout << "\nComparing Phone 1 and Phone 2:\n";
    if (phone1 == phone2) 
    {
        std::cout << "Phone 1 and Phone 2 are identical.\n";
    } 
    else 
    {
        std::cout << "Phone 1 and Phone 2 are different.\n";
    }

    std::cout << "\nPolymorphic behavior:\n";
    Smartphone *smartphone = &phone1;
    smartphone->showInfo();

    return 0;
}
