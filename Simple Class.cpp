#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Character
{
protected:
    int Health;
    int Energy;
    int Power;

public:
    Character() = default;

    Character(int health, int energy, int power)
    {
        Health = health;
        Energy = energy;
        Power = power;
    }

    void setHealth(int health)
    {
        Health = health;
    }

    int getHealth()
    {
        return Health;
    }
    void setEnergy(int energy)
    {
        Energy = energy;
    }

    int getEnergy()
    {
        return Energy;
    }

    void setPower(int power)
    {
        Power = power;
    }

    int getPower()
    {
        return Power;
    }

    virtual void attack()
    {
    }

    bool isAlive()
    {
        return Health > 0;
    }
};

class Zambie : public Character
{
public:
    Zambie(int health, int energy, int power) : Character(health, energy, power) {}
    Zambie() = default;
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
private:
    int Warmskill;
    int Coldskill;

public:

    Human(int health, int energy, int power, int warmskill, int coldskill) : Character(health, energy, power)
    {
        Warmskill = warmskill;
        Coldskill = coldskill;
    }
    Human() = default;

    void setWarmskill(int warmskill)
    {
        Warmskill = warmskill;
    }

    int getWarmskill()
    {
        return Warmskill;
    }

    void setColdskill(int coldskill)
    {
        Coldskill = coldskill;
    }

    int getColdskill()
    {
        return Coldskill;
    }

    void attack() override
    {
    }
};

class Player
{
private:
    string Name;
    int Age;
    char Gender;
    int Level;
    int Money;

public:
    Player(string name, int age, char gender, int level, int money)
    {
        Name = name;
        Age = age;
        Gender = gender;
        Level = level;
        Money = money;
    }
    Player() = default;

    void setName(string name)
    {
        Name = name;
    }

    string getName()
    {
        return Name;
    }

    void setAge(int age)
    {
        Age = age;
    }

    int getAge()
    {
        return Age;
    }

    void setGender(char gender)
    {
        Gender = gender;
    }

    char getGender()
    {
        return Gender;
    }

    void setLevel(int level)
    {
        Level = level;
    }

    int getLevel()
    {
        return Level;
    }

    void setMoney(int money)
    {
        Money = money;
    }

    int getMoney()
    {
        return Money;
    }

    virtual void attack()
    {
    }
};

//////////////////////////////////////////////////////////Item

class Item
{
protected:
    string Name;
    int Power;
    int Count;

public:
    Item(string name, int power, int count)
    {
        Name = name;
        Power = power;
        Count = count;
    }

    Item() = default;

    string getName()
    {
        return Name;
    }
    void setName(string name)
    {
        Name = name;
    }

    void setPower(int power)
    {
        Power = power;
    }
    int getPower()
    {
        return Power;
    }
    void setCount(int count)
    {
        Count = count;
    }
    int getCount()
    {
        return Count;
    }

    void use()
    {
        // cout << "Using " << name << endl;
    }
};

class Weapon : public Item
{
public:
    Weapon(string name, int power, int count) : Item(name, power, count) {}
    Weapon() = default;

    void attack()
    {
        // cout << "Attacking with " << getName() << " (Power: " << power << ")" << endl;
    }
};

class HealthPotion : public Item
{
public:
    HealthPotion(string name, int power, int count) : Item(name, power, count) {}
    HealthPotion() = default;

    void heal()
    {
        // cout << "Healing with " << getName() << " (Health Points: " << healthPoints << ")" << std::endl;
    }
};

class EnergyDrink : public Item
{
public:
    EnergyDrink(string name, int power, int count, int energyPoints) : Item(name, power, count) {}
    EnergyDrink() = default;

    void boostEnergy()
    {
        // cout << "Boosting energy with " << getName() << " (Energy Points: " << energyPoints << ")" << endl;
    }
};

//////////////////////////////////////////////////////////round

class Factory
{
public:
    Human human;
    Player player;
    string enemyType;

    Character factory()
    {
        // خودشو میذاریم جلوی خودش
        if (enemyType == "Human")
        {
            Human enemy(human.getHealth(), human.getEnergy(), human.getPower(), human.getWarmskill(), human.getColdskill());
        }
        else
        {
            Zambie enemy(human.getHealth(), human.getEnergy(), human.getPower());
        }
    }
};

class Controller
{
public:
    

    // simple rols
    // // Attack
    void Attack(Character &attacker, Character &attacked, Weapon &weapon)
    {
        // attackerEnergy - weaponPower
        if (attacker.getEnergy() < weapon.getPower())
        {
            cerr << "\n Low Enargy! \n Try Again. \n";
            return;
        }

        else
        {
            int newEnergy = attacker.getEnergy() - weapon.getPower();
            attacker.setEnergy(newEnergy);
        }

        // attakerPower "+" weaponPower

        if ((attacker.getPower() + weapon.getPower()) > attacked.getHealth())
        {
            attacked.setHealth(0);
        }
        else
        {
            int newHealth = attacked.getHealth() - (attacker.getPower() + weapon.getPower());
            attacked.setHealth(newHealth);
        }
    }
};

// ناقصه
// void round(Human human, Player player, Character enemy, vector<Weapon> weapon, vector<EnergyDrink> energyDrink, vector<HealthPotion> healthPotion)
// {
//     // int enemyHealthy = enemy.getHealth();
//     // int Health = human.getHealth();
//     // int Energy = human.getEnergy();
//     // int playerPower = human.getPower();
//     cout << "status :" << endl
//          << "Health :" << human.getHealth() << endl
//          << "Energy :" << human.getEnergy() << endl
//          << "enemy Health" << enemy.getHealth() << endl
//          << "1. Attack" << endl
//          << "2. Using items" << endl;
//     //  cout << "3. Level up" << endl;
//     int command;
//     cin >> command;
//     switch (command)
//     {
//     case 1:
//         cout << "Weapons :" << endl;
//         for (int i = 0; i < weapon.size(); i++)
//         {
//             cout << i + 1 << ". " << weapon[i].getName() << endl;
//         }
//         int i;
//         cin >> i;
//         if (i <= weapon.size())
//             enemy.setHealth(enemy.getHealth() - (human.getPower() + weapon[i - 1].getPower()));
//         break;

//     case 2:
//         cout << "1. Energy Drink (" << energyDrink.size() << ")" << endl
//              << "2. Health Potion (" << healthPotion.size() << ") \n";
//         int i;
//         cin >> i;
//         if (i == 1)
//         {
//             for (int i = 0; i < energyDrink.size(); i++)
//             {
//                 cout << i + 1 << ". " << energyDrink[i].getName() << endl;
//             }
//             cin >> i;
//             enemy.setHealth(human.getEnergy() + energyDrink[i - 1].getPower());
//         }

//         else if (i == 2)
//         {
//             for (int i = 0; i < healthPotion.size(); i++)
//             {
//                 cout << i + 1 << ". " << healthPotion[i].getName() << endl;
//             }
//             cin >> i;
//             enemy.setHealth(human.getHealth() + healthPotion[i - 1].getPower());
//         }
//         break;

//     default:
//         cerr << "Incorrect command";
//         break;
//     }
// }

int main()
{
}
