#include <cstring>
#include <iostream>

class Microwave
{
public:
    virtual void showInfo()=0;
    virtual ~Microwave(){};

};

class Params : public Microwave
{
public:
    static int unique_id;
    Params(const int &_lenght, const int &_width, const std::string _name, const char* _energyCategory ):lenght(_lenght), width(_width),name(_name)
    {
        enegryCategory = new char[strlen(_energyCategory)+1];
        strcpy(enegryCategory,_energyCategory);
    }
    ~Params()
    {
        delete [] enegryCategory;
    }

    Params(const Params &source):lenght(source.lenght),width(source.width), name(source.name)
    {
        enegryCategory = new char[strlen(source.enegryCategory)+1];
        strcpy(enegryCategory,source.enegryCategory);  
    }

//_zwracany_typ_ & operator =( const _typ_ & );

    Params& operator=(const Params& source)
    {
        if(this != &source)
        {
            lenght = source.lenght;
            width = source.width;
            name = source.name;
            delete [] enegryCategory;
            enegryCategory = new char[strlen(source.enegryCategory)+1];
            strcpy(enegryCategory,source.enegryCategory);

        }
        return *this;
    } 

    const int  screenFielied()
    {
        int screen = lenght * width;
        return screen;
    }

    friend std::ostream& operator<<(std::ostream& out,const Params &other)
    {
        out<<"Lenght: "<<other.lenght<<" Width : "<<other.width<<" Name: "<<other.name<< " Energy category: "<<other.enegryCategory<<std::endl;
        return out;
    }

    bool operator==(const Params &source)const
    {
        return lenght == source.lenght && width == source.width && name == source.name && strcmp(enegryCategory, source.enegryCategory)==0 ;
    }

    virtual void showInfo()override
    {
        std::cout<<"Info about your microfala: \n";
        std::cout<<*this<<std::endl;
    }



private:
    int lenght;
    int width;
    std::string name;
    char* enegryCategory;        

};

int Params::unique_id = 1245;



int main()
{

    Params mikrofala(20,30,"niggerTrigger","A");
    mikrofala.showInfo();

    Params mikrofala_2(40,30,"pozdro","C");
    std::cout<<"Mikrofala przed kopią";
    mikrofala_2.showInfo();

    //Operator przypisania "=" , głębokie kopie
    std::cout<<"Mikrofala po kopii: ";
    mikrofala_2 = mikrofala;
    mikrofala_2.showInfo();

    //Konstruktor kopiujący 
    Params mikrofala_3 = mikrofala_2;
    std::cout<<"Mikrofala III ma parametry mikrofali II która ma parametry mikrofali I : ";
    mikrofala_3.showInfo();
    
    //operator porównania

    if(mikrofala == mikrofala_2)
    {
        std::cout<<"Są takie same";
        return true;
    }else
    {
        std::cout<<"Nie są takie same";
        return false;
    }

    //Test polimorfizm 
    std::cout<<"Moja mikrofala polimorficzna";
    Microwave* ptr = &mikrofala;
    ptr->showInfo();

    return 0;
}
