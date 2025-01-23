#include <iostream>
#include <cstring>
class Smartphone
{
public:
    //virtual void inUsage()const =0;
    virtual void showInfo()const=0;
    virtual ~Smartphone(){};
};

class Params: public Smartphone
{
public:
    static int id;
    Params(const std::string &_company, const unsigned int &_price, const std::string &_model, const char *_energyCategory, bool &_factory ):company(_company),price(_price),model(_model)
    {
        energyCategory = new char[strlen(energyCategory)+1];
        strcpy(energyCategory,_energyCategory);
    };
    ~Params(){delete [] energyCategory;};

    Params(const Params &source):price(source.price), model(source.model),company(source.company),usage(source.usage)
    {
        energyCategory = new char[strlen(source.energyCategory)+1];
        strcpy(energyCategory,source.energyCategory);
        usage=source.usage;
    };


    const bool inUsage(bool usage)
    {
        if(usage !=true)
        {
            std::cout<<"This phone was used before new"<<std::endl;
        }
        return 0;
    }

    Params& operator=(const Params &source) {
        if (source == *this)
            return *this;
        delete [] energyCategory;
        energyCategory = new char[strlen(source.energyCategory)+1];
        strcpy(energyCategory,source.energyCategory);
        company = source.company;
        model = source.model;
        price = source.price;
        usage=source.usage;
        return *this;
    }
    
    friend std::ostream& operator<<(std::ostream &os, const Params &a);

    bool operator ==( const Params &other) const
    {
        if(model == other.model && company == other.company &&  price ==other.price && strcmp(energyCategory, other.energyCategory) == 0)
        {
            return true;
        }
        return false;
    };

private:
    char *energyCategory;
    bool usage = false;
    std::string company;
    unsigned int price;
    std::string model;

};

    std::ostream& operator<<(std::ostream &os, const Params &a)
    {
        return os;
    }

int Params::id=0;


