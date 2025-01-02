#include <iostream>
#include <cstring>

class Pokemon
{
public:
    virtual void showInfo()=0;
    virtual ~Pokemon(){};
};

class Species: public Pokemon
{
public:
    static int pokedexId;

    Species(const std::string &_name, const int &_attackDamage, const int &_hp, const char* _tier)
        : name(_name), attackDamage(_attackDamage), hp(_hp)
    {
        tier = new char[strlen(_tier) + 1];
        strcpy(tier, _tier);
        
        // Inkrementacja pokedexId przy tworzeniu nowego obiektu
        pokedexId++;
    }

    ~Species()
    {
        delete[] tier;
    }

    Species(const Species &source)
        : name(source.name), attackDamage(source.attackDamage), hp(source.hp)
    {
        tier = new char[strlen(source.tier) + 1];
        strcpy(tier, source.tier);
    }

    const Species& operator=(const Species& source)
    {
        if (this != &source)
        {
            name = source.name;
            attackDamage = source.attackDamage;
            hp = source.hp;
            delete[] tier;
            tier = new char[strlen(source.tier) + 1];
            strcpy(tier, source.tier);
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const Species &other)
    {
        out << "----Pokemon stats----\n";
        out << "Pokedex ID: " << pokedexId << "\n";
        out << "Name: " << other.name << "  Attack Damage: " << other.attackDamage
            << "  HP: " << other.hp << "  Tier: " << other.tier << "\n";
        return out;
    }

    const int pokemonAttack(int attackDamage)
    {
        std::cout << "Ultimate attack of your pokemon\n";
        int ultimateAttack = 2 * attackDamage;
        return ultimateAttack;
    }

    bool operator==(const Species &source) const
    {
        return name == source.name && attackDamage == attackDamage && hp == source.hp
               && strcmp(tier, source.tier) == 0;
    }

    void showInfo() override
    {
        std::cout << "Info about your pokemon\n" << *this;
    }

private:
    std::string name;
    int attackDamage;
    int hp;
    char* tier;
};

int Species::pokedexId = 4280;

int main()
{
    Species pokemon_1("Charmander", 50, 80, "A");
    Species pokemon_4("Bulbasaur", 90, 120, "B");
    pokemon_1.showInfo();
    Species pokemon_2 = pokemon_1;
    std::cout << pokemon_4;
    std::cout << pokemon_2;

    Pokemon* ptr = &pokemon_1;
    ptr->showInfo();

    if (pokemon_1 == pokemon_4)
    {
        std::cout << "Pokemons are the same\n";
    }
    else
    {
        std::cout << "Pokemons are different\n";
    }

    return 0;
}
