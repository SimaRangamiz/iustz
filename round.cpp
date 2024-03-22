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

    vector<StaminaPotion> Staminaitems;
    vector<HPDrink> HPitems;

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

    Human(int stamina, int hp, int power, vector<Weapon> weapons, vector<StaminaPotion> staminaitems, vector<HPDrink> hpitems, int warmskill, int coldskill) : Character(stamina, hp, power, weapons)
    {
        Warmskill = warmskill;
        Coldskill = coldskill;
        Staminaitems = staminaitems;
        HPitems = hpitems;
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

    void addStaminaItem(StaminaPotion newStaminaitem)
    {
        Staminaitems.push_back(newStaminaitem);
    }

    void setStaminaItems(vector<StaminaPotion> newStaminaitems)
    {
        Staminaitems = newStaminaitems;
    }

    vector<StaminaPotion> getStaminaItems()
    {
        return Staminaitems;
    }

    void addHPItem(HPDrink newHpitem)
    {
        HPitems.push_back(newHpitem);
    }

    void setHPItems(vector<HPDrink> newHpitems)
    {
        HPitems = newHpitems;
    }

    vector<HPDrink> getHPItems()
    {
        return HPitems;
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

    void setHuman(Human human1)
    {
        human = human1;
    }

    void setPlayer(Player player1)
    {
        player = player1;
    }

    void setEnemy(Character enemy1)
    {
        enemy = enemy1;
    }

    Human getHuman()
    {
        return human;
    }

    Player getPlayer()
    {
        return player;
    }

    Character getEnemy()
    {
        return enemy;
    }
    friend class Controller;
    friend class view;
};

class Factory
{
private:
    Human human;
    Player player;
    string EnemyType;
    Model *model;

public:
    Factory(Human human1, Player player1, Model *model1, string enemyType)
    {
        human = human1;
        player = player1;
        // enemyType = enemyType1;
        model = model1;
        EnemyType = enemyType;
        model->setHuman(human);
        model->setPlayer(player);
    }

    Factory() = default;

    void factory()
    {
        // خودشو میذاریم جلوی خودش
        if (EnemyType == "Human")
        {
            Human enemy(human.getStamina(), human.getHP(), human.getPower(), human.getWeapon(), human.getWarmskill(), human.getColdskill());
            model->setEnemy(enemy);
        }
        else
        {
            Zambie enemy(human.getStamina(), human.getHP(), human.getPower(), human.getWeapon());
            model->setEnemy(enemy);
        }
        // Character enemy(human.getStamina(), human.getHP(), human.getPower(), human.getWeapon());
        // model->setEnemy(enemy);
    }
};

class Controller
{
private:
    Model *model;

public:
    Controller(Model *model1)
    {
        model = model1;
    }
    Controller() = default;
    // simple rols
    // // Attack
    void Attack(char command, int index)
    {
        // if c== A
        // attacker = Enemy
        // else
        // attacker = Human
        // attackerHP =- weaponPower
        if (command == 'A')
        {
            if (model->getEnemy().getHP() < model->getEnemy().getWeapon()[index].getPower())
            {
                cerr << "\n Low Enargy! \n Try Again. \n";
                return;
            }

            else
            {
                int newHP = model->getEnemy().getHP() - model->getEnemy().getWeapon()[index].getPower();
                model->enemy.setHP(newHP);
            }

            // attakerPower "+" weaponPower

            if ((model->getEnemy().getPower() + model->getEnemy().getWeapon()[index].getPower()) > model->getHuman().getStamina())
            {
                model->human.setStamina(0);
            }
            else
            {
                int newStamina = model->getHuman().getStamina() - (model->getEnemy().getPower() + model->getEnemy().getWeapon()[index].getPower());
                model->human.setStamina(newStamina);
            }
        }

        else
        {
            if (model->getHuman().getHP() < model->getHuman().getWeapon()[index].getPower())
            {
                cerr << "\n Low Enargy! \n Try Again. \n";
                return;
            }

            else
            {
                int newHP = model->getHuman().getHP() - model->getHuman().getWeapon()[index].getPower();
                model->human.setHP(newHP);
            }

            // attakerPower "+" weaponPower

            if ((model->getHuman().getPower() + model->getHuman().getWeapon()[index].getPower()) > model->getEnemy().getStamina())
            {
                model->enemy.setStamina(0);
            }
            else
            {
                int newStamina = model->getEnemy().getStamina() - (model->getHuman().getPower() + model->getHuman().getWeapon()[index].getPower());
                model->enemy.setStamina(newStamina);
            }
        }
    }
};

class view
{
private:
    Model *model;
    Controller controller;

public:
    view(Model *model1, Controller controller1)
    {
        model = model1;
        controller = controller1;
    }

    void round()
    {
        cout << "status :" << endl
             << "Stamina :" << model->getHuman().getStamina() << endl
             << "HP :" << model->getHuman().getHP() << endl
             << "enemy Stamina : " << model->getEnemy().getStamina() << endl
             << "eney HP : " << model->getEnemy().getHP() << endl
             << "1. Attack" << endl
             << "2. Using items" << endl;
        int hp = model->getHuman().getHP();
        int stamina = model->getHuman().getStamina();
        int enemyStamina = model->getEnemy().getStamina();
        int enemyHP = model->getEnemy().getHP();
        //  cout << "3. Level up" << endl;
        int command;
        cin >> command;
        switch (command)
        {
        case 1:
            cout << "Weapons :" << endl;
            for (int i = 0; i < model->getHuman().getWeapon().size(); i++)
            {
                cout << i + 1 << ". " << model->getHuman().getWeapon()[i].getName() << endl
                     << "   - power : " << model->getHuman().getWeapon()[i].getPower() << endl
                     << "   - count : " << model->getHuman().getWeapon()[i].getCount() << endl;
            }
            int i;
            cin >> i;
            if (i <= model->getHuman().getWeapon().size())
            {
                controller.Attack('B', i - 1);
                cout << "Stamina: " << model->getHuman().getStamina() << endl
                     << "HP: " << model->getHuman().getHP() << " (" << hp << ")" << endl
                     << "enemy Stamina: " << model->getEnemy().getStamina() << " (" << enemyStamina << ")" << endl
                     << "enemy HP: " << model->getEnemy().getHP() << endl;
            }
            else
            {
                cerr << "Out of range!";
                round();
            }
            break;

        case 2:
            cout << "1. HP Drink (" << model->getHuman().getHPItems().size() << ")" << endl
                 << "2. Stamina Potion (" << model->getHuman().getStaminaItems().size() << ") \n";
            // cin >> i;
            // if (i == 1)
            // {
            //     for (int i = 0; i < model->getHuman().getHPItems().size(); i++)
            //     {
            //         cout << i + 1 << ". " << model->getHuman().getHPItems()[i].getName() << endl;
            //     }
            //     cin >> i;
            //     model->getHuman().setHP(model->getHuman().getHP() + model->getHuman().getHPItems()[i - 1].getPower());
            // }

            // else if (i == 2)
            // {
            //     for (int i = 0; i < model->getHuman().getStaminaItems().size(); i++)
            //     {
            //         cout << i + 1 << ". " << model->getHuman().getStaminaItems()[i].getName() << endl;
            //     }
            //     cin >> i;
            //     model->getHuman().setStamina(model->getHuman().getHP() + model->getHuman().getHPItems()[i - 1].getPower());
            // }
            break;

        default:
            cerr << "Incorrect command";
            round();
            break;
        }
    }
};

int main()
{
    Human zahra(50, 40, 10, 5, 4);
    Weapon w1("w1", 5, 1);
    Weapon w2("w2", 4, 1);
    vector<Weapon> weapons = {w1, w2};
    zahra.setWeapon(weapons);
    Weapon w3("w3", 10, 1);
    zahra.addWeapon(w3);

    Player zar("zar", 19, 'w', 1, 100);
    Model model1;
    Model *model = &model1;
    Factory factory1(zahra, zar, model, "Human");
    factory1.factory();
    // Character enemy = factory1.factory();
    // model.setEnemy(factory1.factory());
    // model.setHuman(zahra);

    Controller controller(model);
    // controller.Attack('A', 0);
    // model->setEnemy(enemy);
    // model.setHuman(zahra);
    view view1(model, controller);
    view1.round();
}
