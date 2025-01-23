#include <iostream>
#include <cstring>

class DataBase
{
public:
    virtual void showInfo() = 0; // funkcja abstrakcyjna
    virtual ~DataBase() {}; // wirtualny destruktor
};

class Table : public DataBase 
{
public:
    static int pesel;

    
    Table(const std::string &_name, const int &_id, const std::string &_surname, const char* _militaryCategory)
        : name(_name), id(_id), surname(_surname)
    {
        militaryCategory = new char[strlen(_militaryCategory) + 1];
        strcpy(militaryCategory, _militaryCategory);
    };


    ~Table()
    {
        delete[] militaryCategory;
    }

   
    Table(const Table &source)
        : name(source.name), surname(source.surname), id(source.id) 
    {
        militaryCategory = new char[strlen(source.militaryCategory) + 1]; // alokacja pamięci dla głębokiej kopii
        strcpy(militaryCategory, source.militaryCategory); // kopiowanie zawartości militaryCategory
    }

    // Poprawka: dodano typ zwracany dla funkcji checkId (powinna zwracać bool)
    bool checkId(int id)
    {
        if(id < 0)
        {
            std::cout << "Id: " << id << " can not be less than 0\n"; // dodano nową linię
            return false; 
        }
        return true; 
    }

    Table& operator=(const Table& source)
    {
        if(this != &source)
        {
            name = source.name;
            surname = source.surname;
            id = source.id;
            delete [] militaryCategory;
            militaryCategory = new char[strlen(source.militaryCategory) + 1]; 
            strcpy(militaryCategory, source.militaryCategory); 
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const Table &other)
    {
        out << "Name: " << other.name << " surname: " << other.surname << " id: " << other.id << " military category: " << other.militaryCategory; 
        return out;
    }

    bool operator==(const Table &source) const
    {
        return name == source.name && id == source.id && surname == source.surname && strcmp(militaryCategory, source.militaryCategory) == 0;
    }

    void showInfo() override
    {
        std::cout << "Personal information\n";
        std::cout << *this; 
    }

private:
    std::string name;
    int id;
    std::string surname;
    char *militaryCategory;
};

int Table::pesel = 361894710;

int main()
{
    
    Table person("Marcin",15,"Kozak","A");
    //person.showInfo();
    /*
    Table person2 = person;
    std::cout<<"\nKopia Marcina: ";
    person2.showInfo();

   // std::cout<<person;

    Table person3("Czesiek",14,"Elegancki","B");
    person3 =person2;
    if(person3==person2)
    {
        std::cout<<"the same person";
    }else
    {
        std::cout<<"diffrient person";
    }
    */
    DataBase *ptr = &person;
    ptr->showInfo();
    return 0;
}
