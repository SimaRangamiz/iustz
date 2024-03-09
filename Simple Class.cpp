#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Character
{
protected:
    int healthy;
    int energy;
    // change
    int power;

public:
    Character(int healthy, int energy, int power)
    {
        this->healthy = healthy;
        this->energy = energy;
        this->power = power;
    }
    // chech
    Character() = default;

    void setHealthy(int healthy)
    {
        this->healthy = healthy;
    }

    int getHealthy()
    {
        return healthy;
    }
    void setEnergy(int energy)
    {
        this->energy = energy;
    }

    int getEnergy()
    {
        return energy;
    }

    void setPower(int power)
    {
        this->power = power;
    }

    int getPower()
    {
        return power;
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
    // int healthy;
    // int energy;
    int level;

    int money;

public:
    Player(string name, int age, char gender, int level, int warmskill)
    {
        this->name = name;
        this->age = age;
        this->gender = gender;
        this->level = level;
        this->money = money;
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

    void setlevel(int level)
    {
        this->level = level;
    }

    int getlevel()
    {
        return level;
    }

    void setMoney(int coldskill)
    {
        this->money = money;
    }

    int getMoney()
    {
        // check
        return money;
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

class StrongerZambie : public Character
{
public:
    void attack() override
    {
    }
};

class Human : public Character
{
    int warmskill;
    int coldskill;

public:
    void attack() override
    {
    }
};

//////////////////////////////////////////////////////////Item

class Item
{
protected:
    string name;
    int power;
    int count;

public:
    // Item(string name) : name(name) {}

    // void use()
    // {
    //     cout << "Using " << name << endl;
    // }

    string getName()
    {
        return name;
    }
    void setPower(int power)
    {
        this->power = power;
    }
    int getPower()
    {
        return power;
    }
    void setCount(int count)
    {
        this->count = count;
    }
    int getPower()
    {
        return power;
    }
};

class Weapon : public Item
{
public:
    // check
    //  Weapon(string name, int power) : name(name), power(power) {}
    Weapon() = default;
    void attack()
    {
        // cout << "Attacking with " << getName() << " (Power: " << power << ")" << endl;
    }

    int getPower()
    {
        // check
        return this->power;
    }

    // private:
    //     int power;
};

class HealthPotion : public Item
{
public:
    // HealthPotion(string name, int healthPoints) : Item(name), healthPoints(healthPoints) {}
    HealthPotion() = default;
    void heal()
    {
        // cout << "Healing with " << getName() << " (Health Points: " << healthPoints << ")" << std::endl;
    }

    int getHealthPoints()
    {
        return healthPoints;
    }

private:
    int healthPoints;
};

class EnergyDrink : public Item
{
public:
    // EnergyDrink(string name, int energyPoints) : Item(name), energyPoints(energyPoints) {}
    EnergyDrink() = default;
    void boostEnergy()
    {
        // cout << "Boosting energy with " << getName() << " (Energy Points: " << energyPoints << ")" << endl;
    }

    int getEnergyPoints() const
    {
        return energyPoints;
    }

    int setEnergyPoints(int energy)
    {
        this->energyPoints = energy;
    }

private:
    int energyPoints;
};

void round(Human human, Player player, Character enemy, vector<Weapon> weapon, vector<EnergyDrink> energyDrink, vector<HealthPotion> healthPotion)
{
    int enemyHealthy = enemy.getHealthy();
    int Health = human.getHealthy();
    int Energy = human.getEnergy();
    int playerPower = human.getPower();
    cout << "status :" << endl
         << "Health :" << Health << endl
         << "Energy :" << Energy << endl
         << "enemy Health" << enemyHealthy << endl
         << "1. Attack" << endl
         << "2. Using items" << endl;
        //  cout << "3. Level up" << endl;
    int command;
    cin >> command;
    switch (command)
    {
    case 1:
        enemy.setHealthy(enemyHealthy - playerPower);
        break;
    case 2:
        cout << "1. Weapons (" << weapon.size() << ") \n 2. Energy Drink (" << energyDrink.size() << ") \n 3. Health Potion (" << healthPotion.size() << ") \n";
        int i;
        cin >> i;
        if (i == 1)
        {
            for (int i = 0; i < weapon.size(); i++)
            {
                cout << i + 1 << ". " << weapon[i].getName() << endl;
            }
            cin >> i;
            int weaponPow = weapon[i - 1].getPower();
            enemy.setHealthy(enemyHealthy - weaponPow);
        }

        else if (i == 2)
        {
            for (int i = 0; i < energyDrink.size(); i++)
            {
                cout << i + 1 << ". " << energyDrink[i].getName() << endl;
            }
            cin >> i;
            int drinkPow = energyDrink[i - 1].getPower();
            enemy.setHealthy(Energy + drinkPow);
        }

        else if (i == 3)
        {
            for (int i = 0; i < healthPotion.size(); i++)
            {
                cout << i + 1 << ". " << healthPotion[i].getName() << endl;
            }
            cin >> i;
            int drinkPow = healthPotion[i - 1].getPower();
            enemy.setHealthy(Health + drinkPow);
        }
        break;

    default:
        cerr << "Incorrect command";
        break;
    }
}

int main()
{
    
}
