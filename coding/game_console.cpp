#include <cstring>
#include <iostream>

class Console 
{
    public:
        virtual void showInfo()=0;
        virtual ~Console(){};
};

class Data: public Console
{
public:
    static int id;

    Data(const int &_ram,const std::string &_name,const char* _series, const std::string &_user):ram(_ram),name(_name),user(_user)
    {
        series = new char[strlen(_series)+1];
        strcpy(series,_series);
    }
    ~Data()
    {
        delete [] series;
    };
    Data(const Data &source): ram(source.ram),name(source.name),user(source.user)
    {
        series = new char[strlen(source.series)+1];
        strcpy(series,source.series);
    }

    const Data& operator=(const Data& source)
    {
        if(this != &source)
        {
            ram = source.ram;
            name = source.name;
            user = source.user;
            delete [] series;
            series = new char[strlen(source.series)+1];
            strcpy(series,source.series);

        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const Data &other)
    {
        out<<"";
        return out;
    }

    bool operator==(const Data &source)
    {
        return ;
    }



private:
    int ram;
    std::string name;
    char* series;
    std::string user;


};

int Data::id = 1245;

int main()
{
    return 0;
}
