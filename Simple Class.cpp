#include <iostream>
#include <string>
#include <vector>
using namespace std;

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
private:
    char Model;

public:
    Weapon(string name, int power, int count) : Item(name, power, count) {}
    Weapon() = default;

    void attack()
    {
        // cout << "Attacking with " << getName() << " (Power: " << power << ")" << endl;
    }
};

class StaminaPotion : public Item
{
public:
    StaminaPotion(string name, int power, int count) : Item(name, power, count) {}
    StaminaPotion() = default;

    void heal()
    {
        // cout << "Healing with " << getName() << " (Stamina Points: " << StaminaPoints << ")" << std::endl;
    }
};

class HPDrink : public Item
{
public:
    HPDrink(string name, int power, int count, int HPPoints) : Item(name, power, count) {}
    HPDrink() = default;

    void boostHP()
    {
        // cout << "Boosting hp with " << getName() << " (HP Points: " << HPPoints << ")" << endl;
    }
};
/////////////////////////////////////////////// Charcater
class Character
{
protected:
    int Stamina;
    int HP;
    int Power;
    vector<Weapon> Weapons;

public:
    Character() = default;
    Character(int stamina, int hp, int power)
    {
        Stamina = stamina;
        HP = hp;
        Power = power;
    }
    Character(int stamina, int hp, int power, vector<Weapon> weapons)
    {
        Stamina = stamina;
        HP = hp;
        Power = power;
        Weapons = weapons;
    }

    void setStamina(int stamina)
    {
        Stamina = stamina;
    }

    int getStamina()
    {
        return Stamina;
    }
    void setHP(int hp)
    {
        HP = hp;
    }

    int getHP()
    {
        return HP;
    }

    void setPower(int power)
    {
        Power = power;
    }

    int getPower()
    {
        return Power;
    }

    void addWeapon(Weapon newWeapon)
    {
        Weapons.push_back(newWeapon);
    }

    void setWeapon(vector<Weapon> weapons)
    {
        Weapons = weapons;
    }

    vector<Weapon> getWeapon()
    {
        return Weapons;
    }

    virtual void attack()
    {
    }

    bool isAlive()
    {
        return Stamina > 0;
    }
};

class Zambie : public Character
{
public:
    Zambie(int stamina, int hp, int power) : Character(stamina, hp, power) {}
    Zambie(int stamina, int hp, int power, vector<Weapon> weapons) : Character(stamina, hp, power, weapons) {}
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
    Human(int stamina, int hp, int power, int warmskill, int coldskill) : Character(stamina, hp, power)
    {
        Warmskill = warmskill;
        Coldskill = coldskill;
    }
    Human(int stamina, int hp, int power, vector<Weapon> weapons, int warmskill, int coldskill) : Character(stamina, hp, power, weapons)
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

//////////////////////////////////////////////////////////round
class Model
{
private:
    Human human;
    Player player;
    Character enemy;

public:
    // Model(Human human1, Player player1)
    // {
    //     human = human1;
    //     player = player1;
    // }
    Model() = default;

    void setHuman (Human human1)
    {
        human = human1;
    }

    void setPlayer (Player player1)
    {
        player = player1;
    }

    void setEnemy(Character enemy1)
    {
        enemy = enemy1;
    }

    Human getHuman ()
    {
        return human;
    }

    Player getPlayer ()
    {
        return player;
    }

    Character getEnemy ()
    {
        return enemy;
    }
};

class Factory
{
private:
    Human human;
    Player player;
    string enemyType;
    Model model;

public:
    Factory(Human human1, Player player1, string enemyType1, Model model1)
    {
        human = human1;
        player = player1;
        enemyType = enemyType1;
        model = model1;
        model.setHuman(human);
        model.setPlayer(player);
    }

    Factory() = default;

    Character factory()
    {
        // خودشو میذاریم جلوی خودش
        if (enemyType == "Human")
        {
            Human enemy(human.getStamina(), human.getHP(), human.getPower(), human.getWeapon(), human.getWarmskill(), human.getColdskill());
            return enemy;
        }
        else
        {
            Zambie enemy(human.getStamina(), human.getHP(), human.getPower(), human.getWeapon());
            return enemy;
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
        // attackerHP =- weaponPower
        if (attacker.getHP() < weapon.getPower())
        {
            cerr << "\n Low Enargy! \n Try Again. \n";
            return;
        }

        else
        {
            int newHP = attacker.getHP() - weapon.getPower();
            attacker.setHP(newHP);
        }

        // attakerPower "+" weaponPower

        if ((attacker.getPower() + weapon.getPower()) > attacked.getStamina())
        {
            attacked.setStamina(0);
        }
        else
        {
            int newStamina = attacked.getStamina() - (attacker.getPower() + weapon.getPower());
            attacked.setStamina(newStamina);
        }
    }
};

// class view
// {
// private:
//     Human human;
//     Player player;
//     Character enemy;
//     Controller controller;

// public:
//     view(Human human1, Player player1, Character enemy1, Controller controller1)
//     {
//         human = human1;
//         player = player1;
//         enemy = enemy1;
//         controller = controller1;
//     }

//     void round()
//     {
//         cout << "status :" << endl
//              << "Stamina :" << human.getStamina() << endl
//              << "HP :" << human.getHP() << endl
//              << "enemy Stamina : " << enemy.getStamina() << endl
//              << "eney HP : " << enemy.getHP() << endl
//              << "1. Attack" << endl
//              << "2. Using items" << endl;
//         //  cout << "3. Level up" << endl;
//         int command;
//         cin >> command;
//         switch (command)
//         {
//         case 1:
//             cout << "Weapons :" << endl;
//             for (int i = 0; i < human.getWeapon().size(); i++)
//             {
//                 cout << i + 1 << ". " << human.getWeapon()[i].getName() << endl
//                      << "   - power : " << human.getWeapon()[i].getPower()
//                      << "   - count : " << human.getWeapon()[i].getCount();
//             }
//             int i;
//             cin >> i;
//             if (i <= human.getWeapon().size())

//                 break;
//         case 2:
//             cout << "1. HP Drink (" << HPDrink.size() << ")" << endl
//                  << "2. Stamina Potion (" << StaminaPotion.size() << ") \n";
//             int i;
//             cin >> i;
//             if (i == 1)
//             {
//                 for (int i = 0; i < HPDrink.size(); i++)
//                 {
//                     cout << i + 1 << ". " << HPDrink[i].getName() << endl;
//                 }
//                 cin >> i;
//                 enemy.setStamina(human.getHP() + HPDrink[i - 1].getPower());
//             }

//             else if (i == 2)
//             {
//                 for (int i = 0; i < StaminaPotion.size(); i++)
//                 {
//                     cout << i + 1 << ". " << StaminaPotion[i].getName() << endl;
//                 }
//                 cin >> i;
//                 enemy.setStamina(human.getStamina() + StaminaPotion[i - 1].getPower());
//             }
//             break;

//         default:
//             cerr << "Incorrect command";
//             break;
//         }
//     }
// };

int main()
{
    Human zahra(50, 40, 10, 5, 4);
    Weapon w1("w1", 5, 2);
    Weapon w2("w2", 4, 1);
    vector<Weapon> weapons = {w1, w2};
    zahra.setWeapon(weapons);
    Weapon w3("w3", 10, 1);
    zahra.addWeapon(w3);

    Player zar("zar", 19, 'w', 1, 100);
    Model model;
    Factory factory1(zahra, zar, "Human", model);
    Character enemy = factory1.factory();
    model.setEnemy(enemy);
    cout << model.getEnemy().getHP() << endl
         << enemy.getWeapon()[2].getName();
}
