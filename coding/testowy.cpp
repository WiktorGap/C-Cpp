#include <iostream>
#include <cstring>

class Storage
{
public:
    virtual void showInfo()=0;
    virtual ~Storage();


};


class Weapoen : public Storage
{
public:
    static int unique_id;

    Weapoen(int &damage_, int &health_, char*  &category_, std::string &nameOfWeapon_): damage(damage) , health(health_),nameOfWeapon(nameOfWeapon_)
    {
        category = new char[strlen(category_)+1];
        strcpy(category,category_);

    }
    ~Weapoen()
    {
        delete [] category;
    };
    Weapoen(const Weapoen &source): damage(source.damage), health(source.health), nameOfWeapon(source.nameOfWeapon)
    {
        category = new char[strlen(source.category)+1];
        strcpy(category,source.category);
    }

    bool operator==(const Weapoen &source)const
    {
        return damage==source.damage && health == source.health && strcmp(category,source.category)==0 && nameOfWeapon==nameOfWeapon;
    }

    Weapoen& operator=(const Weapoen &source)
    {
        if(this != &source)
        {
            damage = source.damage;
            health = source.health;
            nameOfWeapon= source.nameOfWeapon;
            delete [] category;
            category = new char[strlen(category)+1];
            category = strcpy(category,source.category);
        }
        return *this;
    }


    friend std::ostream& operator<<(std::ostream& out, const Weapoen &obj)
    {
        out<<"Damage"<<obj.damage<<"HEalth"<<obj.health<<"Name "<< obj.nameOfWeapon<<"Category"<<obj.category;
        return out;
    }

    virtual void showInfo() override
    {
        std::cout<<"Info about your object\n";
        std::cout<<*this;
    }

private:
    int damage;
    int health;
    char* category;
   std::string nameOfWeapon;

};


int  Weapoen::unique_id=123;


int main()
{

    return 0;
}