#include <iostream>
#include <cstdlib>
#include <string>

class Item
{
public:
    std::string& getName() { return name; }
    unsigned int getID() { return id; }
    static unsigned int getCount() { return count; }

protected:
    Item(const std::string &name) : name(name), id(count++) {}

private:
    unsigned int id;
    std::string name;
    static unsigned int count;
};

// Definicja statycznego członka count
unsigned int Item::count = 0;

class Weapon : public Item
{
public:
    Weapon(const std::string &name) : Item(name) {}
    virtual float getDamage() = 0;
    virtual bool isBroken() = 0;
    virtual void use() = 0;
    virtual void repair() = 0;

    void print()
    {
        if (isBroken())
        {
            std::cout << "Your weapon: " << getName() << " of id#" << getID() << " is broken and can't be used again" << std::endl;
        }
        else
        {
            std::cout << "Your weapon: " << getName() << " Get damage: " << getDamage() << std::endl;
        }
    }

    virtual ~Weapon() {}
};

class Sword : public Weapon
{
public:
    Sword() : Weapon("Sword") {}
    ~Sword() { std::cout << "Sword object is being destroyed..." << std::endl; }

    virtual float getDamage() override
    {
        return baseDamage * sharpness;
    }

    virtual bool isBroken() override
    {
        return sharpness <= 0;
    }

    virtual void use() override
    {
        print();
        sharpness -= 0.1;
    }

    virtual void repair() override
    {
        if (sharpness < 1.0)
        {
            sharpness *= 1.1;
            std::cout << "Sword repaired." << std::endl;
        }
    }

private:
    const float baseDamage = 8.125;
    float sharpness = 0.5;
};

class Hammer : public Weapon
{
public:
    Hammer() : Weapon("Hammer") {}
    ~Hammer() { std::cout << "Hammer object is being destroyed..." << std::endl; }

    virtual float getDamage() override
    {
        if (durability > 0)
        {
            return damage;
        }
        return 0;
    }

    virtual bool isBroken() override
    {
        return durability == 0;
    }

    virtual void use() override
    {
        print();
        if (durability > 0)
        {
            durability--;
        }
    }

    virtual void repair() override
    {
        if (durability < defaultDurability)
        {
            durability = defaultDurability;
            std::cout << "Hammer repaired." << std::endl;
        }
    }

private:
    const unsigned int defaultDurability = 4;
    const float damage = 3.5;
    unsigned int durability = defaultDurability;
};

int main()
{
    Weapon *equipment[4] = {
        new Sword,
        new Hammer,
        new Sword,
        new Hammer
    };

    srand(time(NULL));

    for (int i = 0; i < 4; i++)
    {
        if (!equipment[i]->isBroken())
        {
            equipment[i]->use();
            bool shouldRepair = (rand() % 10) == 0;
            if (shouldRepair)
            {
                equipment[i]->repair();
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        delete equipment[i];
    }

    return 0;
}
