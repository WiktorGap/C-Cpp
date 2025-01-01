#include <iostream>
#include <cstring>

class Pokemon 
{
public:
    virtual void showInfo() = 0;
    virtual ~Pokemon () {};
};


class Ability : public Pokemon 
{
private:
    int attack_damage;
    std::string ultimate;
    int HP;
    std::string name;
    char* tier;

public:
    Ability(const int _attack_damage, const std::string& _ultimate, const int _HP, const std::string& _name, const char* _tier) : 
    attack_damage(_attack_damage), ultimate(_ultimate), HP(_HP), name(_name)
    {
        tier = new char[strlen(_tier)+1];
        strcpy(tier,_tier);
    }



};