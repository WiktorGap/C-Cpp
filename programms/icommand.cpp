#include <iostream>
#include <cstring>


class Icommand
{
public:
    virtual char getCommand() const= 0;
    virtual ~Icommand(){};
};

class SystemUptime: public Icommand
{
public:

    SystemUptime()
    {
        std::cout<<"Konstuktor klasy uptime";
    }
    ~SystemUptime()
    {
        std::cout<<"Destruktor klasy uptime";
    }

    char getCommand() const override
    {
        return 'U';
    }

};


class SystemMemory: public Icommand
{
public:
    SystemMemory(){std::cout<<"To jest konstruktor klasy SystemMemory";};
    ~SystemMemory(){std::cout<<"Destruktor klasy SystemMemory";};

    char getCommand() const override
    {
        return 'M';
    }



};





void PrintCommand(const Icommand *c)
{
    std::cout<<"Komend: "<<c->getCommand()<<std::endl;
}

int main()
{
    Icommand* uptime_ptr = new SystemUptime();
    Icommand* memory_ptr = new SystemMemory();
    PrintCommand(uptime_ptr);
    PrintCommand(memory_ptr);
    delete memory_ptr;
    delete uptime_ptr;



}
