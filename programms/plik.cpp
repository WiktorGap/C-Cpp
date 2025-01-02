#include <iostream>
#include <cstdlib>
#include <cstring>
class TimeLenght
{
public:
    TimeLenght(const char *SecondsString);
    TimeLenght(const TimeLenght &obj);
    ~TimeLenght();

    friend std::ostream& operator << (std::ostream& out,const TimeLenght &source);
    const char* getString()const;


    static TimeLenght createZeroLenght();


private:
    char *copy;
    unsigned long hours;
    unsigned long minutes;
    unsigned long seconds;

};



TimeLenght::TimeLenght(const char *SecondsString)
    {
        copy = strdup(SecondsString);
        unsigned long value = strtoul(SecondsString,NULL,10);
        hours = value /3600;
        value %= 3600;
        minutes = value /60;
        seconds = value % 60;



    };

TimeLenght::TimeLenght(const TimeLenght& obj)
    {
        copy = strdup(obj.copy);
        hours = obj.hours;
        minutes = obj.minutes;
        seconds = obj.seconds;

    };

TimeLenght::~TimeLenght()
    {
        free(copy);
    };



const char* TimeLenght:: getString() const
    {
        return copy;
    };
TimeLenght TimeLenght::createZeroLenght()
{
    return TimeLenght("0");
};


std::ostream& operator << (std::ostream& out,const TimeLenght &source)
{
    out<<source.hours<<"H "<<source.minutes<<"min "<<source.minutes<<"sec ";
    return out;
}


int main()
{
    TimeLenght uptime("19592");
    std::cout<<uptime<<std::endl;
    std::cout<<uptime.getString()<<std::endl;
    TimeLenght zero = TimeLenght::createZeroLenght();
    std::cout<<"Zero lenght"<<zero;

    return 0;
}