#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;

//////////////////////////////////////////////////////////Item

class Item
{
protected:
    string Name;
    int Power;
    int Count;
    int Price;

public:
    Item(string name, int power, int count, int price)
    {
        Name = name;
        Power = power;
        Count = count;
        Price = price;
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
    void addCount(int count)
    {
        Count += count;
    }
    int getCount()
    {
        return Count;
    }
    int getPrice() const
    {
        return Price;
    }
    // void use()
    // {
    //     // cout << "Using " << name << endl;
    // }
};

class Weapon : public Item
{
private:
    char Model;
    // 't' : throwable
    char Type;
    // 'c' : coldskill

public:
    Weapon(string name, int power, int count, int price) : Item(name, power, count, price) {}
    Weapon(string name, int power, int count, int price, char model, char type) : Item(name, power, count, price)
    {
        Model = model;
        Type = type;
    }
    Weapon() = default;

    void attack()
    {
        // cout << "Attacking with " << getName() << " (Power: " << power << ")" << endl;
    }
    char getModel()
    {
        return Model;
    }
    char getType()
    {
        return Type;
    }
};

class StaminaPotion : public Item
{
public:
    StaminaPotion(string name, int power, int count, int price) : Item(name, power, count, price) {}
    StaminaPotion() = default;

    // void heal()
    // {
    //     // cout << "Healing with " << getName() << " (Stamina Points: " << StaminaPoints << ")" << std::endl;
    // }
};

class HPDrink : public Item
{
public:
    HPDrink(string name, int power, int count, int price) : Item(name, power, count, price) {}
    HPDrink() = default;

    // void boostHP()
    // {
    //     // cout << "Boosting hp with " << getName() << " (HP Points: " << HPPoints << ")" << endl;
    // }
};

class Armor : public Item
{
private:
    bool isArmor;

public:
    Armor(string name, int power, int count, int price, bool armor) : Item(name, power, count, price), isArmor(armor) {}

    Armor() = default;

    bool isArmorItem() const
    {
        return isArmor;
    }
};

class Fruitage : public Item
{
public:
    int Capability;
    Fruitage(string name, int power, int count, int price, int capability) : Item(name, power, count, price), Capability(capability) {}
    Fruitage() = default;

    void setCapability(int capability)
    {
        Capability = capability;
    }
    int getCapability()
    {
        return Capability;
    }
};

/////////////////////////////////////////////// Charcater

class Character
{
protected:
    int Stamina;
    int HP;
    int Power;
    int Capability;
    vector<Weapon> Weapons;
    string Name;

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

    Character(int stamina, int hp, int power, vector<Weapon> weapons, string name)
    {
        Stamina = stamina;
        HP = hp;
        Power = power;
        Weapons = weapons;
        Name = name;
    }

    void setStamina(int stamina)
    {
        if (stamina < 0)
            Stamina = 0;
        else
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

    string getName()
    {
        return Name;
    }

    void setName(string name)
    {
        Name = name;
    }

    virtual void attack()
    {
    }

    bool isAlive()
    {
        return Stamina > 0;
    }

    friend class Controller;
    friend class view;
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
    vector<Armor> Armoritems;
    vector<Fruitage> Fruitageitems;

public:
    bool isArmor = 0;
    bool Bulletproof = 0;
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

    Human(int stamina, int hp, int power, vector<Weapon> weapons, vector<StaminaPotion> staminaitems, vector<HPDrink> hpitems, vector<Armor> armoritems, vector<Fruitage> fruitageitems, int warmskill, int coldskill) : Character(stamina, hp, power, weapons)
    {
        Warmskill = warmskill;
        Coldskill = coldskill;
        Staminaitems = staminaitems;
        HPitems = hpitems;
        Armoritems = armoritems;
        Fruitageitems = fruitageitems;
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

    void addArmorItem(Armor newArmoritem)
    {
        Armoritems.push_back(newArmoritem);
    }
    void setArmorItems(vector<Armor> newArmoritems)
    {
        Armoritems = newArmoritems;
    }
    vector<Armor> getArmorItems()
    {
        return Armoritems;
    }
    void addFruitageItem(Fruitage newFruitageitem)
    {
        Fruitageitems.push_back(newFruitageitem);
    }
    void setFruitageItems(vector<Fruitage> newFruitageitems)
    {
        Fruitageitems = newFruitageitems;
    }
    vector<Fruitage> getFruitageItems()
    {
        return Fruitageitems;
    }

    void useHP(int i)
    {
        HP += HPitems[i].getPower();
    }

    void useStamina(int i)
    {
        Stamina += Staminaitems[i].getPower();
    }

    int damagePower (int i, Human enemy)
    {
        int result;
        if (Weapons[i].getModel()=='c')
            result = Weapons[i].getPower() + Coldskill;
        else 
            result = Weapons[i].getPower() + Warmskill;
        if (enemy.isArmor)
            result /= 2;
        if (enemy.Bulletproof)
        {
            result = 0;
            enemy.Bulletproof = 0;
        }
        return result;
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
    int Experience;

public:
    Player(string name, int age, char gender, int level, int money)
    {
        Name = name;
        Age = age;
        Gender = gender;
        Level = level;
        Experience = level;
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

    int getExperience()
    {
        return Experience;
    }

    void setExperience(int experience)
    {
        Experience = experience;
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
    Human enemy;

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

    void setEnemy(Human enemy1)
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

    Human getEnemy()
    {
        return enemy;
    }
    friend class Controller;
    friend class view;
    friend class Store;
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
        if (EnemyType == "Zambie")
        {
            Human enemy(human.getStamina(), human.getHP(), human.getPower(), 0, 0);
            Weapon w("fist", 5, 1, 0, 'p', 'c');
            enemy.addWeapon(w);
            enemy.setName(EnemyType);
            model->setEnemy(enemy);
        }
        else
        {
            Human enemy(human.getStamina(), human.getHP(), human.getPower(), human.getWeapon(), human.getWarmskill(), human.getColdskill());
            model->setEnemy(enemy);
        }
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

    bool Attack(char command, int index)
    {
        // if c == A
        // attacker = Enemy
        // else
        // attacker = human
        // attackerHP =- weaponPower
        if (command == 'A')
        {
            if (model->getEnemy().getWeapon()[index].getCount() < 1)
            {
                // cerr << "\nNo Weapon! \nTry Again. \n";
                return false;
            }

            else
            {
                if (model->getEnemy().getHP() < model->getEnemy().getWeapon()[index].getPower())
                {
                    // cerr << "\nLow Enargy! \nTry Again. \n";
                    return false;
                }
                if (model->getHuman().getArmorItems()[index].isArmorItem())
                {
                    return true;
                }

                else
                {
                    int newHP = model->getEnemy().getHP() - model->getEnemy().getWeapon()[index].getPower();
                    model->enemy.setHP(newHP);
                }

                // attakerPower "+" weaponPower

                model->human.setStamina(model->getEnemy().damagePower(index , model->enemy));

                if (model->getEnemy().Weapons[index].getModel() == 't')
                {
                    model->enemy.Weapons[index].addCount(-1);
                }
                if (!model->getHuman().isAlive())
                {
                    cout << "\nGame Over! :(\n";
                    exit(0);
                }

                return true;
            }
        }

        else
        {
            if (model->getHuman().getWeapon()[index].getCount() < 1)
            {
                cerr << "\nNo Weapon! \nTry Again. \n";
                return false;
            }

            else
            {
                if (model->getHuman().getHP() < model->getHuman().getWeapon()[index].getPower())
                {
                    cerr << "\n Low Enargy! \n Try Again. \n";
                    return false;
                }

                else
                {
                    int newHP = model->getHuman().getHP() - model->getHuman().getWeapon()[index].getPower();
                    model->human.setHP(newHP);
                }

                // weapon.power + human.warm/cold Skill
                model->enemy.setStamina(model->getHuman().damagePower(index, model->enemy));

                if (model->getHuman().Weapons[index].getModel() == 't')
                {
                    model->human.Weapons[index].addCount(-1);
                }

                if (!model->getEnemy().isAlive())
                {
                    cout << "\nThe enemy was defeated!\n";
                    int newStamina = model->getHuman().getStamina() + 5;
                    model->human.setStamina(newStamina);

                    int newHp = model->getHuman().getHP() + 10;
                    model->human.setHP(newHp);

                    int newmoney = model->getPlayer().getMoney() + 100;
                    model->player.setMoney(newmoney);

                    int newExperience = model->getPlayer().getLevel() + 1;
                    model->player.setExperience(newExperience);

                    Factory factory1(model->human, model->player, model, "Zambie");
                }
                return true;
            }
        }
    }

    void enemyAttack()
    {
        if (model->getEnemy().getName() == "Zambie")
        {
            for (int i = 0; i < model->getEnemy().getWeapon().size(); i++)
            {
                if (Attack('A', i))
                {
                    return;
                }
            }
            return;
        }
        else
        {

            int staminaSize = model->getEnemy().getStaminaItems().size();
            int Stamina = model->getEnemy().getStamina();
            if (staminaSize > 0)
            {
                bool healthy = 1;
                for (int i = 0; i < model->getHuman().getWeapon().size(); i++)
                {
                    if (model->getHuman().damagePower(i , model->human) > Stamina)
                    {
                        healthy = 0;
                    }
                }
                if (!healthy)
                {
                    model->getEnemy().useStamina(0);
                    cout << model->getEnemy().getName() << " used Stamina potion!" << endl
                         << "new Stamina: " << model->getEnemy().getStamina() << "(" << Stamina << ")";
                    enemyAttack();
                }
            }

            int HPsize = model->getEnemy().getHPItems().size();
            int HP = model->getEnemy().getHP();
            if (HPsize > 0)
            {
                bool attack = 1;
                for (int i = 0; i < model->getEnemy().getWeapon().size(); i++)
                {
                    if (model->getEnemy().getWeapon()[i].getPower() > HP)
                    {
                        attack = 0;
                    }
                }
                if (!attack)
                {
                    model->getEnemy().useHP(0);
                    cout << model->getEnemy().getName() << " used HP drink!" << endl
                         << "new HP: " << model->getEnemy().getHP() << "(" << HP << ")";
                    enemyAttack();
                }
            }

            
        }
    }
};

class Store
{
private:
    vector<StaminaPotion> Stamina;
    vector<HPDrink> HP;
    vector<Weapon> weapon;
    vector<Armor> armor;
    vector<Fruitage> fruitage;
    Model *model;

public:
    Store(vector<StaminaPotion> stamina, vector<HPDrink> hp, vector<Weapon> weapon1, Model *model1)
    {
        Stamina = stamina;
        HP = hp;
        weapon = weapon1;
        model = model1;
    //////          Basic shop items             //////

        Weapon Knife("Knife ", 10, 2, 8, 'p', 'c');
        Weapon Bomb("Bomb ", 20, 1, 15, 't', 'w');
        vector<Weapon> weaponsToAdd{Knife, Bomb};
        addToWeaponList(weaponsToAdd);

        StaminaPotion Patch("Patch ", 8, 1, 5);
        StaminaPotion Splint("Splint ", 10, 1, 8);
        vector<StaminaPotion> StaminaToAdd{Patch, Splint};
        addToStaminaList(StaminaToAdd);

        HPDrink Milk("Milk ", 8, 1, 8);
        HPDrink Spaghetti("Spaghetti ", 10, 1, 9);
        vector<HPDrink> HPToAdd{Milk, Spaghetti};
        addToHPList(HPToAdd);

        Fruitage OrangeJuice("Orange Juice", 15, 12, 1, 18);
        Fruitage Pumpkin("Pumpkin", 12, 10, 1, 15);
        vector<Fruitage> FruitageToAdd{OrangeJuice, Pumpkin};
        addToFruitageList(FruitageToAdd);
    }
    //////               ///////                      //////

    ///// Shop items based on player level(crafted items) /////

    void addStaminaByLevel(int playerLevel)
    {
        int power = 10 + floor(sqrt(playerLevel)) * 2;
        int price = 10 + floor(sqrt(playerLevel)) * 1;
        int count = 1;

        vector<string> staminaNames = {"Bandage", "Elixir", "Painkiller", "Drug", "Quickening", "Blood", "Boosting Ampoule", "Health Elixir"};
        int randomIndex = rand() % staminaNames.size();
        string randomName = staminaNames[randomIndex];

        StaminaPotion newStamina(randomName, power, count, price);
        addToStaminaList(newStamina);
    }

    void addHPByLevel(int playerLevel)
    {
        int power = 10 + floor(sqrt(playerLevel)) * 3;
        int price = 10 + floor(sqrt(playerLevel)) * 1;
        int count = 1;

        vector<string> hpNames = {"Pizza", "Cracker", "Kebab", "Smoothie", "Chocolate", "Coffee", "Dough", "Nuts"};
        int randomIndex = rand() % hpNames.size();
        string randomName = hpNames[randomIndex];

        HPDrink newHp(randomName, power, count, price);
        addToHPList(newHp);
    }

    void addWeaponByLevel(int playerLevel)
    {
        int power = 10 + floor(sqrt(playerLevel)) * 3;
        int price = 10 + floor(sqrt(playerLevel)) * 2;
        int count = 1;

        vector<string> weaponNames = {"Sword", "Handgun", "Axe", "Hammer", "Shotgun", "Pistol", "Bow", "Shovel"};
        int randomIndex = rand() % weaponNames.size();
        string randomName = weaponNames[randomIndex];

        if (rand() % 10 == 4)
        {
            Weapon newWeapon(randomName, power, count, 2 * price, 'p', char(99 + ((playerLevel % 2) * 14)));
            addToWeaponList(newWeapon);
        }
        else
        {
            Weapon newWeapon(randomName, power, count, price, 't', char(199 + ((playerLevel % 2) * 14)));
            addToWeaponList(newWeapon);
        }
    }

    void addFruitageByLevel(int playerLevel, int capability)
    {
        if (playerLevel > 7)
        {
            int power = 10 + floor(sqrt(playerLevel)) * 3;
            int price = 10 + floor(sqrt(playerLevel)) * 1;
            int count = 1;

            vector<string> fruitNames = {"Broccoli", "Pineapple", "Turnip", "Spinach", "Carrot", "Melon", "Lettuce", "Apple"};
            int randomIndex = rand() % fruitNames.size();
            string randomName = fruitNames[randomIndex];

            Fruitage newFruitage(randomName, power, capability, count, price);
            addToFruitageList(newFruitage);
        }
    }
    /////                  //////                     //////

    vector<Weapon> &getWeapons()
    {
        return weapon;
    }
    /////  Add basic and crafted items to the store   //////
    void addToWeaponList(Weapon item)
    {
        weapon.push_back(item);
    }
    void addToWeaponList(const vector<Weapon> &items)
    {
        for (const auto &item : items)
        {
            weapon.push_back(item);
        }
    }

    void addToStaminaList(StaminaPotion item)
    {
        Stamina.push_back(item);
    }

    void addToStaminaList(const vector<StaminaPotion> &items)
    {
        for (const auto &item : items)
        {
            Stamina.push_back(item);
        }
    }

    void addToHPList(HPDrink item)
    {
        HP.push_back(item);
    }
    void addToHPList(const vector<HPDrink> &items)
    {
        for (const auto &item : items)
        {
            HP.push_back(item);
        }
    }
    void addToFruitageList(Fruitage item)
    {
        fruitage.push_back(item);
    }
    void addToFruitageList(const vector<Fruitage> &items)
    {
        for (const auto &item : items)
        {
            fruitage.push_back(item);
        }
    }
    //////               ///////                      //////


    /////////////////////////////////////////////////////////////////////////////

    void store()
    {
        cout << "\"WELCOME TO OUR STORE!\"\nWhich one do you want?\n1. Weapon\n2. First aid box(To increse Stamina)\n3. Edible(To increase Hp)\n4. Armor\n5. Fruitage(To increase Stamina and Hp)\n6. Exit."
             << endl;
        int command;
        cin >> command;
        switch (command)
        {
        case 1:
            cout << "Weapon:\n";
            for (int i = 0; i < weapon.size(); i++)
            {
                string type1;
                if (weapon[i].getType() == 't')
                {
                    type1 = "Throwable";
                }
                else
                {
                    type1 = "Permanent";
                }
                string model1;
                if (weapon[i].getType() == 'c')
                {
                    model1 = "ColdWeapon";
                }
                else
                {
                    model1 = "WarmWeapon";
                }
                cout << i + 1 << ". " << weapon[i].getName() << endl
                     << " -Price: " << weapon[i].getPrice() << endl
                     << " -Power: " << weapon[i].getPower() << endl
                     << " -model : " << model1 << endl
                     << " -type : " << type1 << endl;
            }
            cin >> command;
            if (command > 0 && command <= weapon.size())
            {
                if (model->player.getMoney() >= weapon[command - 1].getPrice())
                {
                    model->human.addWeapon(weapon[command - 1]); ///////////////////
                    model->player.setMoney(model->player.getMoney() - weapon[command - 1].getPrice());
                    cout << "The item you bought:" << endl
                         << "- " << weapon[command - 1].getName()
                         << " (Power: " << weapon[command - 1].getPower() << ", Price: " << weapon[command - 1].getPrice() << ")\n"
                         << "\n Your Balance : " << model->player.getMoney() << endl
                         << endl;
                }
                else
                {
                    cout << "You do not have enough money to buy this item.\n";
                }
            }
            else
            {
                cerr << "Invalid Number!";
            }
            break;

        case 2:
            cout << "First aid box :\n"
                 << endl;
            for (int i = 0; i < Stamina.size(); i++)
            {
                cout << i + 1 << "- " << Stamina[i].getName() << " (Price: " << Stamina[i].getPrice() << " , Power:" << Stamina[i].getPower() << ")" << endl;
            }
            cin >> command;
            if (command > 0 && command <= Stamina.size())
            {
                if (model->player.getMoney() >= Stamina[command - 1].getPrice())
                {
                    model->human.addStaminaItem(Stamina[command - 1]);
                    model->player.setMoney(model->player.getMoney() - Stamina[command - 1].getPrice());
                    cout << "The items you bought:" << endl
                         << "- " << Stamina[command - 1].getName()
                         << " (Power: " << Stamina[command - 1].getPower() << ", Price: " << Stamina[command - 1].getPrice() << ")"
                         << "\n Your Balance : " << model->player.getMoney()
                         << endl;
                }
                else
                {
                    cout << "You don not have enough money to buy this item.\n";
                }
            }
            else
            {
                cerr << "Invalid Number!";
            }
            break;

        case 3:
            cout << "Edible :" << endl;
            for (int i = 0; i < HP.size(); i++)
            {
                cout << i + 1 << "- " << HP[i].getName() << " (Price: " << HP[i].getPrice() << " , Power:" << HP[i].getPower() << ")" << endl;
            }
            cin >> command;
            if (command > 0 && command <= HP.size())
            {
                if (model->player.getMoney() >= HP[command - 1].getPrice())
                {
                    model->human.addHPItem(HP[command - 1]);
                    model->player.setMoney(model->player.getMoney() - HP[command - 1].getPrice());
                    cout << "The items you bought:" << endl
                         << "- " << HP[command - 1].getName()
                         << " (Power: " << HP[command - 1].getPower() << ", Price: " << HP[command - 1].getPrice() << ")"
                         << "\n Your Balance : " << model->player.getMoney() << endl;
                }
                else
                {
                    cout << "You don not have enough money to buy this item.\n";
                }
            }
            else
            {
                cerr << "Invalid Number!";
            }
            break;

        case 4:
            cout << "Armors\n";
            for (int i = 0; i < armor.size(); i++)
            {
                cout << i + 1 << ". " << armor[i].getName() << " (Price: " << armor[i].getPrice() << " , Power:" << armor[i].getPower() << ")" << endl;
            }
            cin >> command;

            if (command > 0 && command <= armor.size())
            {
                if (model->player.getMoney() >= armor[command - 1].getPrice())
                {

                    model->human.addArmorItem(armor[command - 1]);
                    model->player.setMoney(model->player.getMoney() - armor[command - 1].getPrice());
                    cout << "The items you bought:" << endl
                         << "- " << armor[command - 1].getName()
                         << " (Power: " << armor[command - 1].getPower() << ", Price: " << armor[command - 1].getPrice() << ")"
                         << "\n Your Balance : " << model->player.getMoney() << endl;
                }
                else
                {
                    cout << "You don't have enough money to buy this item.\n";
                }
            }
            else
            {
                cerr << "Invalid Number!";
            }
            break;
        case 5:
            cout << "Fruitage\n : ";
            for (int i = 0; i < fruitage.size(); i++)
            {
                cout << i + 1 << ". " << fruitage[i].getName() << " (Price: " << fruitage[i].getPrice() << " , Power:" << fruitage[i].getPower() << ")" << endl;
            }
            cin >> command;
            if (command > 0 && command <= fruitage.size())
            {
                if (model->player.getMoney() >= fruitage[command - 1].getPrice())
                {

                    model->human.addFruitageItem(fruitage[command - 1]);
                    model->player.setMoney(model->player.getMoney() - fruitage[command - 1].getPrice());
                    cout << "The items you bought:" << endl
                         << "- " << fruitage[command - 1].getName()
                         << " (Power: " << fruitage[command - 1].getPower() << ", Price: " << fruitage[command - 1].getPrice() << ")"
                         << "\n Your Balance : " << model->player.getMoney() << endl;
                }
                else
                {
                    cout << "You don't have enough money to buy this item.\n";
                }
            }
            else
            {
                cerr << "Invalid Number!";
            }
            break;

        case 6:
            return;

        default:
            cerr << "Invalid command!\n";
            break;
        }
    }
};

class view
{
private:
    Model *model;
    Controller controller;
    Store *store;

public:
    view(Model *model1, Controller controller1, Store *store1)
    {
        model = model1;
        controller = controller1;
        store = store1;
    }

    void round()
    {
        cout << "status: " << endl
             << "Stamina: " << model->getHuman().getStamina() << endl
             << "HP: " << model->getHuman().getHP() << endl
             << "enemy Stamina: " << model->getEnemy().getStamina() << endl
             << "enemy HP: " << model->getEnemy().getHP() << endl
             << "1. Attack" << endl
             << "2. Using items" << endl
             << "3. Level up" << endl;
        int YourHp = model->getHuman().getHP();
        int YourStamina = model->getHuman().getStamina();
        int EnemyStamina = model->getEnemy().getStamina();
        int EnemyHP = model->getEnemy().getHP();

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
                     << "   - count : " << model->getHuman().getWeapon()[i].getCount() << endl
                     << "   - model : " << model->getHuman().getWeapon()[i].getModel() << endl;
            }
            int i;
            cin >> i;
            if (i <= model->getHuman().getWeapon().size())
            { // human
                if (controller.Attack('B', i - 1))
                {
                    cout << "-You: " << endl
                         << " Stamina: " << model->getHuman().getStamina() << endl
                         << " HP: " << model->getHuman().getHP() << " (" << YourHp << ")" << endl
                         << "-Enemy:" << endl
                         << " Stamina: " << model->getEnemy().getStamina() << " (" << EnemyStamina << ")" << endl
                         << " HP: " << model->getEnemy().getHP() << endl
                         << endl;
                    cout << "Do you want to Attack?\n1. yes\n2. no\n";
                    cin >> command;
                    if (command == 2)
                    {
                        model->enemy.setStamina(EnemyStamina);
                        model->human.setHP(YourHp);
                        if (model->human.Weapons[i].getModel() == 't')
                            model->human.Weapons[i].addCount(1);
                        round();
                    }

                    // enemy
                    if (controller.Attack('A', 0))
                    {
                        cout << model->enemy.getName() << "Attacked!" << endl
                             << "-Enemy: " << endl
                             << " Stamina: " << model->getEnemy().getStamina() << endl
                             << " HP: " << model->getEnemy().getHP() << " (" << EnemyHP << ")" << endl
                             << "-You: " << endl
                             << " Stamina: " << model->getHuman().getStamina() << " (" << YourStamina << ")" << endl
                             << " HP: " << model->getHuman().getHP() << endl
                             << endl;
                    }
                }
            }

            else
            {
                cerr << "Out of range!";
                round();
            }
            break;

        case 2:
            int choice;
            cout << "Choose an item to use:\n";
            cout << "21. Stamina Potion\n";
            cout << "22. HP Drink\n";
            cout << "23. Armor\n";
            cout << "24. Fruitage\n";
            cin >> choice;
            switch (choice)
            {
            case (21):
                // if StaminaPotion was chosen:
                if (model->getHuman().getStaminaItems().empty())
                {
                    cout << "No Stamina Potion available!\n";
                }
                else
                {
                    cout << "Available Stamina Potions:\n";
                    for (int i = 0; i < model->getHuman().getStaminaItems().size(); i++)
                    {
                        if (model->getHuman().getStaminaItems()[i].getCount() > 0)
                            cout << i + 1 << ". " << model->getHuman().getStaminaItems()[i].getName() << endl
                                 << " -power: " << model->getHuman().getStaminaItems()[i].getPower() << endl
                                 << " -count: " << model->getHuman().getStaminaItems()[i].getCount() << endl;
                    }
                    int potionChoice;
                    cin >> potionChoice;
                    if (potionChoice > 0 && potionChoice <= model->getHuman().getStaminaItems().size())
                    {

                        if (model->getHuman().getStaminaItems()[potionChoice - 1].getPower() > 0)
                            model->human.setStamina(model->getHuman().getStamina() + model->getHuman().getStaminaItems()[potionChoice - 1].getPower());
                        else
                            cerr << "Not available!\n";
                    }
                    else
                    {
                        cerr << "Invalid choice!\n";
                    }
                }

            case (22):

                // if HPdrink was chosen:

                if (model->getHuman().getHPItems().empty())
                {
                    cout << "No HP Drink available!\n";
                }
                else
                {

                    cout << "Available HP Drinks:\n";
                    for (int i = 0; i < model->getHuman().getHPItems().size(); i++)
                    {
                        cout << i + 1 << ". " << model->getHuman().getHPItems()[i].getName() << endl
                             << " -power: " << model->getHuman().getHPItems()[i].getPower() << endl
                             << " -count: " << model->getHuman().getHPItems()[i].getCount() << endl;
                    }
                    int drinkChoice;
                    cin >> drinkChoice;
                    if (drinkChoice > 0 && drinkChoice <= model->getHuman().getHPItems().size())
                    {

                        model->human.setHP(model->getHuman().getHP() + model->getHuman().getHPItems()[drinkChoice - 1].getPower());
                    }
                    else
                    {
                        cerr << "Invalid choice!\n";
                    }
                }

            case 23:

                // if Armor was chosen:
                if (model->getHuman().getHPItems().empty())
                {
                    cout << "No Armors available!\n";
                }
                else
                {
                    cout << "Available HP Drinks:\n";
                    for (int i = 0; i < model->getHuman().getArmorItems().size(); i++)
                    {
                        cout << i + 1 << ". " << model->getHuman().getArmorItems()[i].getName() << endl
                             << " -power: " << model->getHuman().getArmorItems()[i].getPower() << endl
                             << " -count: " << model->getHuman().getArmorItems()[i].getCount() << endl;
                    }
                    int armorChoice;
                    cin >> armorChoice;
                    if (armorChoice > 0 && armorChoice <= model->getHuman().getArmorItems().size())
                    {
                        if (model->getHuman().getArmorItems()[armorChoice - 1].getPower() > 0)
                        {
                            model->human.setHP(model->getHuman().getHP() + model->getHuman().getHPItems()[armorChoice - 1].getPower());
                        }
                        else
                        {
                            cerr << "Not available!\n";
                        }
                    }

                    else
                    {
                        cerr << "Invalid choice!\n";
                    }
                }

            case 24:

                // if Fruitage was chosen:
                if (model->getHuman().getFruitageItems().empty())
                {
                    cout << "No Fruitage available!\n";
                }
                else
                {
                    cout << "Available Fruitage :\n";
                    for (int i = 0; i < model->getHuman().getFruitageItems().size(); i++)
                    {
                        cout << i + 1 << ". " << model->getHuman().getFruitageItems()[i].getName() << endl
                             << " -power: " << model->getHuman().getFruitageItems()[i].getPower() << endl
                             << " -count: " << model->getHuman().getFruitageItems()[i].getCount() << endl;
                    }

                    int fruitageChoice;
                    cin >> fruitageChoice;
                    if (fruitageChoice > 0 && fruitageChoice <= model->getHuman().getFruitageItems().size())
                    {
                        if (model->getHuman().getFruitageItems()[fruitageChoice - 1].getCapability() > 0)
                        {
                            model->human.setStamina(model->getHuman().getStamina() + model->getHuman().getStaminaItems()[fruitageChoice - 1].getPower());
                            //////////add capability
                            model->human.setHP(model->getHuman().getHP() + model->getHuman().getFruitageItems()[fruitageChoice - 1].getCapability());
                        }
                        else
                        {
                            cerr << "Not available!\n";
                        }
                    }
                }
            }
            round();
            break;
        case 3:
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
    //  Weapon Knife("w1", 5, 1, 10, 't', 'c');

    // Weapon w2("w2", 4, 1, 10, 'p', 'w');
    //   Weapon w3("w3", 10, 1, 10, 't', 'c');
    //  Weapon Knife()
    //  vector<Weapon> weapons = {w1, w2, w3};

    Player zar("zar", 19, 'w', 1, 100);
    Model model1;
    Model *model = &model1;
    Factory factory1(zahra, zar, model, "Zambie");
    factory1.factory();

    // Character enemy = factory1.factory();
    // model.setEnemy(factory1.factory());
    // model.setHuman(zahra);
    Controller controller(model);
    // controller.Attack('A', 0);
    // model->setEnemy(enemy);
    // model.setHuman(zahra);
    
    // view1.round();

    int playerLevel = 1;

    vector<StaminaPotion> Stamina = {};
    vector<HPDrink> HP = {};
    vector<Weapon> weapons = {};
    zahra.setWeapon(weapons);
    vector<Fruitage> fruitage = {};
    // zahra.setWeapon(weapons);
    Store store(Stamina, HP, weapons, model);
    store.addStaminaByLevel(playerLevel);
    store.addHPByLevel(playerLevel);
    store.addWeaponByLevel(playerLevel);

    view view1(model, controller, &store);
    // store.setCapability(capability);
    // store.addFruitageByLevel(playerLevel, capability);

    //   StaminaPotion s1("s1", 10, 1, 5);
    // StaminaPotion s2("s2", 12, 1, 6);
    // StaminaPotion s3("s3", 14, 1, 7);
    // StaminaPotion s4("s4", 16, 1, 8);
    // HPDrink h1("h1", 10, 1, 5);
    // HPDrink h2("h2", 12, 1, 6);
    // HPDrink h3("h3", 14, 1, 7);
    // HPDrink h4("h4", 18, 1, 8);
    // vector<StaminaPotion> Stamina = {s1, s2, s3, s4};
    // vector<HPDrink> HP = {h1, h2, h3, h4};
    // // Armor a1("a1", 10, 1, 10);
    // Fruitage f1("f1", 25, 10, 1, 20);

    int i = 0;
    while (model->getHuman().isAlive())
    {
        if (i % 2 == 0)
            store.store();
        else
            view1.round();
        i++;
    }
}