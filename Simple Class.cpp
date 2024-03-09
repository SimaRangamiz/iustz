#include <iostream>
#include <string>
using namespace std;

class Item { 
public: 
    Item(string name) : name(name) {} 
 
    void use() { 
        cout << "Using " << name << endl; 
    } 
 
    string getName() { 
        return name; 
    } 
 
private: 
    string name; 
}; 
 
 
class Weapon : public Item { 
public: 
    Weapon(string name, int power) : Item(name), power(power) {} 
 
    void attack() { 
        cout << "Attacking with " << getName() << " (Power: " << power << ")" << endl; 
    } 
 
    int getPower()  { 
        return power; 
    } 
 
private: 
    int power; 
}; 
 
 
class HealthPotion : public Item { 
public: 
    HealthPotion(string name, int healthPoints) : Item(name), healthPoints(healthPoints) {} 
 
    void heal() { 
        cout << "Healing with " << getName() << " (Health Points: " << healthPoints << ")" << std::endl; 
    } 
 
    int getHealthPoints()  { 
        return healthPoints; 
    } 
 
private: 
    int healthPoints; 
}; 
 
class EnergyDrink : public Item { 
public: 
    EnergyDrink(string name, int energyPoints) : Item(name), energyPoints(energyPoints) {} 
 
    void boostEnergy() { 
        cout << "Boosting energy with " << getName() << " (Energy Points: " << energyPoints << ")" << endl; 
    } 
 
    int getEnergyPoints() const { 
        return energyPoints; 
    } 
 
private: 
    int energyPoints; 
}; 


class Character
{
private:
    int healthy;
    int energy;
    int level;

public:
    Character(int healthy, int energy, int level)
    {
        this->healthy = healthy;
        this->energy = energy;
        this->level = level;
    }

    void sethealthy(int healthy)
    {
        this->healthy = healthy;
    }

    int gethealthy()
    {
        return healthy;
    }
    void setenergy(int energy)
    {
        this->energy = energy;
    }

    int getenergy()
    {
        return energy;
    }

    void setlevel(int lenel)
    {
        this->level = level;
    }

    int getlevel()
    {
        return level;
    }

    virtual void attack()
    {
    }

    bool isAlive()
    {
        return healthy > 0;
    }
};


class Player
{
private:
    string name;
    int age;
    char gender;
    int healthy;
    int energy;
    int level;
    int warmskill;
    int coldskill;

public:
    Player(string name, int age, char gender, int healthy, int energy, int level, int warmskill, int coldskill)
    {
        this->name = name;
        this->age = age;
        this->gender = gender;
        this->healthy = healthy;
        this->energy = energy;
        this->level = level;
        this->warmskill = warmskill;
        this->coldskill = coldskill;
    }

    void setname(string name)
    {
        this->name = name;
    }

    string getname()
    {
        return name;
    }

    void setage(int age)
    {
        this->age = age;
    }

    int getage()
    {
        return age;
    }

    void setgender(char gender)
    {
        this->gender = gender;
    }

    char getgender()
    {
        return gender;
    }

    void sethealthy(int healthy)
    {
        this->healthy = healthy;
    }

    int gethealthy()
    {
        return healthy;
    }
    void setenergy(int energy)
    {
        this->energy = energy;
    }

    int getenergy()
    {
        return energy;
    }

    void setlevel(int lenel)
    {
        this->level = level;
    }

    int getlevel()
    {
        return level;
    }

    void setwarmskill(int warmskill)
    {
        this->warmskill = warmskill;
    }

    int getwarmskill()
    {
        return warmskill;
    }

    void setcoldskill(int coldskill)
    {
        this->coldskill = coldskill;
    }

    int getcoldskill()
    {
        return coldskill;
    }

    virtual void attack()
    {
    }
};


class Zambie : public Character
{
public:
    void attack() override
    {
    }
};


class Strongerzambie : public Character
{
public:
    void attack() override
    {
    }
};


class Humanenemy : public Character
{
public:
    void attack() override
    {
    }
};
