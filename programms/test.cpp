/*#include <iostream>
#include <cstring>

class Computer
{
public:
    virtual void showInfo()=0;
    virtual ~Computer(){};

};

class Komponents : public Computer
{
public:
    static int id;

    Komponents(const int &_screen_lenght, const int &_screen_width, const char* _name, const std::string _producent):screen_lenght(_screen_lenght),screen_width(_screen_width),producent(_producent)
    {
        name = new char[strlen(_name)+1];
        strcpy(name,_name);
        id++;
    };
    ~Komponents()
    {
        delete [] name;
    };
    Komponents(const Komponents &source):screen_lenght(screen_lenght),screen_width(source.screen_width),producent(source.producent)
    {

        name = new char[strlen(source.name)+1];
        strcpy(name,source.name);
        id++;
    }

    friend std::ostream& operator<<(std::ostream& out, const Komponents &other)
    {
        std::cout<<"Components of your computer";
        out<<"Lenght: "<<other.screen_lenght<<"Width: "<<other.screen_width<<" Name: "<<other.name<<" Producent  "<<other.producent;
        return out;
    }

    const Komponents& operator=(const Komponents& source)
    {
        if(this != &source)
        {
            screen_lenght = source.screen_lenght;
            screen_width = source.screen_width;
            producent = source.producent;
            delete [] name;
            name = new char[strlen(source.name)+1];
            strcpy(name,source.name);
            id++;
        }
            return *this;
    };

    bool operator==(const Komponents &source)const
    {
        return screen_lenght == source.screen_lenght && screen_width == source.screen_width && producent == source.producent && strcmp(name,source.name)==0;
    }

    const int calcScreen()
    {
        std::cout<<"Screen size in inches:  ";
        int size_inch = screen_width * screen_lenght;
        std::cout<<"Result "<<size_inch;
        return 0;
    };

    void showInfo()override
    {
        std::cout<<"Info about yout computer"<<"of id: "<< id<<*this;
    }

private:
    int screen_lenght;
    int screen_width;
    char* name;
    std::string producent;

};

int Komponents::id = 0;


int main()
{
    Komponents komputer_1(20,30,"moj_komputer","lenovo");
    komputer_1.showInfo();
    komputer_1.calcScreen();

    Komponents komputer_2(50,70,"lalala","asus");
    std::cout<<komputer_2;
    Computer* ptr = &komputer_2;
    std::cout<<"Wywołanie wskaźnikowe";
    ptr->showInfo();

    Komponents komputer_4(13,45,"siema","lol");
    komputer_4 = komputer_2;
    std::cout<<"Comp 4 is the same as 2 \n";
    komputer_4.showInfo();
    Komponents comp5 = komputer_1;
    std::cout<<"Test konstr kopiujacy: "<<comp5;




    return 0;
};
*/
#include <iostream>
#include <cstring>

class Computer
{
public:
    virtual void showInfo()=0;
    virtual ~Computer(){};
};

class Komponents : public Computer
{
public:
    static int id;

    Komponents(const int &_screen_lenght, const int &_screen_width, const char* _name, const std::string _producent)
        : screen_lenght(_screen_lenght), screen_width(_screen_width), producent(_producent)
    {
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
        objectId = id++;  // Przypisanie unikalnego ID dla każdego obiektu
    }

    ~Komponents()
    {
        delete [] name;
    }

    Komponents(const Komponents &source)
        : screen_lenght(source.screen_lenght), screen_width(source.screen_width), producent(source.producent)
    {
        name = new char[strlen(source.name) + 1];
        strcpy(name, source.name);
        objectId = id++;  // Przypisanie nowego unikalnego ID
    }

    friend std::ostream& operator<<(std::ostream& out, const Komponents &other)
    {
        out << "Components of your computer (ID: " << other.objectId << ")\n";
        out << "Length: " << other.screen_lenght << ", Width: " << other.screen_width 
            << ", Name: " << other.name << ", Producer: " << other.producent << "\n";
        return out;
    }

    const Komponents& operator=(const Komponents& source)
    {
        if (this != &source)
        {
            screen_lenght = source.screen_lenght;
            screen_width = source.screen_width;
            producent = source.producent;
            delete [] name;
            name = new char[strlen(source.name) + 1];
            strcpy(name, source.name);
            objectId = id++;  // Nowe ID dla przypisanego obiektu
        }
        return *this;
    }

    bool operator==(const Komponents &source) const
    {
        return screen_lenght == source.screen_lenght && screen_width == source.screen_width 
               && producent == source.producent && strcmp(name, source.name) == 0;
    }

    const int calcScreen()
    {
        std::cout << "Screen size in inches: ";
        int size_inch = screen_width * screen_lenght;
        std::cout << "Result: " << size_inch << "\n";
        return size_inch;
    }

    void showInfo() override
    {
        std::cout << "Info about your computer (ID: " << objectId << ")\n" << *this;
    }

private:
    int screen_lenght;
    int screen_width;
    char* name;
    std::string producent;
    int objectId;  // Unikalny identyfikator dla każdego obiektu
};

int Komponents::id = 1;

int main()
{
    Komponents komputer_1(20, 30, "moj_komputer", "lenovo");
    komputer_1.showInfo();
    komputer_1.calcScreen();

    Komponents komputer_2(50, 70, "lalala", "asus");
    std::cout << komputer_2;
    Computer* ptr = &komputer_2;
    std::cout << "Wywołanie wskaźnikowe\n";
    ptr->showInfo();

    Komponents komputer_4(13, 45, "siema", "lol");
    komputer_4 = komputer_2;
    std::cout << "Comp 4 is the same as 2\n";
    komputer_4.showInfo();

    Komponents comp5 = komputer_1;
    std::cout << "Test konstruktora kopiującego:\n" << comp5;

    return 0;
}






