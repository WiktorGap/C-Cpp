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

    Params(const unsigned int &_hpa, const  int &_temp, const char* _categoryOfFall, const std::string &_cloudiness)
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

    const int absoluteValOfTemp( int temp)
    {
        if(temp<0)
        {
            unsigned int absoluteVal = temp * (-1);
            return absoluteVal;
        }
        return temp;
    }



    //zwracany_typ_ & operator =( const _typ_ & );

    Params& operator=(const Params& source)
    {
        if(this != &source)
        {
            hpa = source.hpa;
            temp = source.temp;
            cloudiness = source.cloudiness;
            delete []categoryOfFall;
            categoryOfFall = new char[strlen(source.categoryOfFall)+1];
            strcpy(categoryOfFall,source.categoryOfFall);
        }
        return *this;
    }

    
    bool operator==(const Params &other)const
    {
        return hpa == other.hpa && temp ==other.temp && categoryOfFall ==other.categoryOfFall && cloudiness == other.cloudiness;
    }

    friend std::ostream& operator<<(std::ostream &out, const Params &p)
    {
        out<<"HPA:"<<p.hpa<<"Temp"<<p.temp<<"CategorOfFall"<<p.categoryOfFall<<"Cloudiness"<<p.cloudiness;
        return out;
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
    return 0;
}
