#include <cstring>
#include <iostream>

class Sensor
{
public:
    virtual void showInfo() = 0;
    virtual ~Sensor() {};
};

class Params : public Sensor
{
public:
    static std::string date;

    Params(const unsigned int &_hpa, const int &_temp, const char* _categoryOfFall, const std::string &_cloudiness)
        : hpa(_hpa), temp(_temp), cloudiness(_cloudiness)
    {
        categoryOfFall = new char[strlen(_categoryOfFall) + 1];
        strcpy(categoryOfFall, _categoryOfFall);
    }

    Params(const Params &source)
        : hpa(source.hpa), temp(source.temp), cloudiness(source.cloudiness)
    {
        categoryOfFall = new char[strlen(source.categoryOfFall) + 1];
        strcpy(categoryOfFall, source.categoryOfFall);
    }

    ~Params()
    {
        delete[] categoryOfFall;
    }

    const int absoluteValOfTemp(int temp)
    {
        if (temp < 0)
        {
            unsigned int absoluteVal = temp * (-1);
            return absoluteVal;
        }
        return temp;
    }

    Params& operator=(const Params& source)
    {
        if(this != &source)
        {
            hpa = source.hpa;
            temp = source.temp;
            cloudiness = source.cloudiness;
            delete[] categoryOfFall;
            categoryOfFall = new char[strlen(source.categoryOfFall) + 1];
            strcpy(categoryOfFall, source.categoryOfFall);
        }
        return *this;
    }

    bool operator==(const Params &other)const
    {
        return hpa == other.hpa && temp == other.temp && strcmp(categoryOfFall,other.categoryOfFall)==0 && cloudiness == other.cloudiness;
    }

    friend std::ostream& operator<<(std::ostream &out, const Params &p)
    {
        out << "HPA: " << p.hpa << " Temp: " << p.temp << " CategoryOfFall: " << p.categoryOfFall << " Cloudiness: " << p.cloudiness;
        return out;
    }

    void showInfo() override
    {
        std::cout << "Weather Information: " << std::endl;
        std::cout << *this << std::endl;
    }

private:
    int hpa;
    unsigned int temp;
    char *categoryOfFall;
    std::string cloudiness;
};

std::string Params::date = "30.10.2018";

int main()
{
    //tworzenie obiektu i testowanie funkcji;
    Params weather1(1013,5,"Rain","partly cloudly");
    std::cout<<"Orginal weather"<<weather1<<std::endl;
    weather1.showInfo();

    //testowanie konstruktora kopiującego;
    Params weather2 = weather1;
    std::cout<<"\nCopierd weather object: "<<weather2;
    weather2.showInfo();

    //testowanie operator przypisania głeboka kopia

    Params weather3(1020,10,"Snow","Clear sky");
    std::cout<<"\nOrginal object before assigment"<<std::endl;
    weather3.showInfo();


    //testowanie operatora przypisania
    weather3 = weather1;
    std::cout<<"Weather 3 is now weather1: ";
    weather3.showInfo();


    //testowanie polimorfizmu 
    Sensor* sensorPtr = &weather1;
    std::cout<<"Testowanie polimorfizmu wywołanie info wskaźnikiem";
    sensorPtr->showInfo();

    //testawanie operatora << dla weather1;
    std::cout << "\nTesting operator << for weather1:" << std::endl;
    std::cout<<weather1<<std::endl;

    //testowanie operatora ==

    std::cout<<"\nTestowanie czy weather 1 == weather 2 ";

    if(weather1 == weather2)
    {
        std::cout<<"sa takie same";
    }else
    {
        std::cout<<"sa rozne";
    }

    std::cout<<"\nTestowanie czy weather 1 == weather  ";
    if(weather1 == weather3)
    {
        std::cout<<"sa takie same";
    }else
    {
        std::cout<<"sa rozne";
    }



    return 0;
}
