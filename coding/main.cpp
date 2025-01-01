#include <iostream>
#include <cstring>

class Car
{
    public:
        virtual void showInfo()=0;
        virtual ~Car(){};
};

class Params: public Car
{
    public:

        int static id;

        Params(const std::string &_fuel, const char *_model, const int &_hp, const int &_maxspeed) 
            : fuel(_fuel), hp(_hp), maxSpeed(_maxspeed)
        {
            model = new char[strlen(_model) + 1]; 
            strcpy(model, _model); 
        };

        ~Params()
        {
            delete[] model;
        };

        Params(const Params &source)
            : fuel(source.fuel), hp(source.hp), maxSpeed(source.maxSpeed) 
        {
            model = new char[strlen(source.model) + 1]; 
            strcpy(model, source.model); 
        }

        friend std::ostream& operator<<(std::ostream& out, const Params &p)
        {
            out<<"Fuel"<<p.fuel<<"Hp:"<<p.hp<<"Model: "<<p.model<<"Max speed"<<p.maxSpeed;
            return out;
        }


        bool operator==(const Params &other) const
        {
            return fuel == other.fuel && hp == other.hp && model == other.model && maxSpeed == other.maxSpeed;
            

        }

        const Params& operator=(const Params& source)
        {
            if(this != &source)
            {
                fuel = source.fuel;
                hp = source.hp;
                maxSpeed = source.maxSpeed;
                delete [] model;
                model = new char[strlen(source.model)+1];
                strcpy(model,source.model);


                
            }
            return *this;
        };





    private:
        std::string fuel;
        char* model; // ZMIANA: zmieniono typ model z std::string* na char*
        int hp;
        int maxSpeed;
};

int Params::id=290;

int main()
{
    return 0;
}