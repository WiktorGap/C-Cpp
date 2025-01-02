#include <iostream>
#include <string>

class Computer{
    private:
        std::string manufacturer;
        std::string model;
        std::string cpu;
        unsigned int ramMemory;
        unsigned int diskMemory;
    public:
        Computer(std::string _manufacturer , std::string _model, std::string _cpu, unsigned int _ramMemory, unsigned int _diskMemory):manufacturer(_manufacturer), model(_model), cpu(_cpu), ramMemory(_ramMemory), diskMemory(_diskMemory){}
        virtual void print() const {
            std::cout<<manufacturer<<"  "<<model<<" /" <<ramMemory<<"/"<<cpu<<"/ "<<" /  "<<diskMemory<<std::endl;
        }

        void setMan(std::string &manufacturer){this->manufacturer=manufacturer;}
        void setMod(std::string &model){this->model=model;}
        void setCpu(std::string &cpu){this->cpu=cpu;}
        void setRam(unsigned int  &ramMemory){this->ramMemory= ramMemory;}
        void setDiskMem(unsigned int  &diskMemory){this->diskMemory= diskMemory;}

};

class Laptop:public Computer{
    private:
        unsigned int  screen;
        unsigned int battery;
    public:
        Laptop(const Computer& _base, unsigned int _screen , unsigned int _battery) : Computer(_base), screen(_screen), battery(_battery){}
        void print() const{
            std::cout<<"Screen"<< screen <<" '' "<<"battery"<<battery<<" Wh"<<std::endl;
        }
        void setScreen(unsigned int &screen){this->screen=screen;}
        void setBattery(unsigned int &battery){this->battery=screen;}
};


class Desktop: public Computer{
    protected:
        std::string formFactor;
        std::string psu;
    public:
    Desktop(std::string _manufacturer , std::string _model, std::string _cpu, unsigned int _ramMemory, unsigned int _diskMemory, std::string _formFactor, std::string _psu)
    : Computer(_manufacturer,_model,_cpu,_ramMemory,_diskMemory) , formFactor(_formFactor), psu(_psu){}
        void print() const{
            std::cout<<"costamcostam"<<formFactor<<"psu"<<psu<<std::endl;
        }
        void setFactor(std::string &formFactor){this->formFactor=formFactor;}
        void setPsu(std::string &form){this->psu=psu;}
};

void show(const Computer &computer) {
    computer.print();
}

int main(){
    Computer c("SNSV", "Longitude 555", "i11-1234X", 16, 512);
    Laptop l(c, 15, 50);
    Desktop d("Optimus", "PW-000", "i13-4321X", 96, 4096, "SFF", "550W 80 Plus Gold");
    show(c);
    show(l);
    show(d);

}