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

// class Armor : public Item
// {
// private:
//     bool isArmor;

// public:
//     Armor(string name, int power, int count, int price, bool armor) : Item(name, power, count, price), isArmor(armor) {}

//     Armor() = default;

//     bool isArmorItem() const
//     {
//         return isArmor;
//     }
// };

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
    vector<Weapon> Weapons = {};
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

    vector<StaminaPotion> Staminaitems = {};
    vector<HPDrink> HPitems = {};
    vector<Fruitage> Fruitageitems = {};

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

    Human(int stamina, int hp, int power, vector<Weapon> weapons, vector<StaminaPotion> staminaitems, vector<HPDrink> hpitems, vector<Fruitage> fruitageitems, int warmskill, int coldskill) : Character(stamina, hp, power, weapons)
    {
        Warmskill = warmskill;
        Coldskill = coldskill;
        Staminaitems = staminaitems;
        HPitems = hpitems;
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

    // void addArmorItem(Armor newArmoritem)
    // {
    //     Armoritems.push_back(newArmoritem);
    // }
    // void setArmorItems(vector<Armor> newArmoritems)
    // {
    //     Armoritems = newArmoritems;
    // }
    // vector<Armor> getArmorItems()
    // {
    //     return Armoritems;
    // }
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

    void useFruitage(int i)
    {
        Stamina += Fruitageitems[i].getPower();
        HP += Fruitageitems[i].getCapability();
    }

    int damagePower(int i, Human enemy)
    {
        int result;
        if (Weapons[i].getModel() == 'c')
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

class Store
{
private:
    vector<StaminaPotion> Stamina;
    vector<HPDrink> HP;
    vector<Weapon> weapon;
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
    Store() = default;
    //////               ///////                      //////

    ///// Shop items based on player level(crafted items) /////

    void addStaminaByLevel(int playerLevel)
    {
        int power = 10 + floor(sqrt(playerLevel)) * 2;
        int price = 10 + floor(sqrt(playerLevel)) * 1;
        int count = 1;
        srand(time(NULL));
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
        srand(time(NULL));
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

    void addFruitageByLevel(int playerLevel)
    {
        if (playerLevel > 7)
        {
            srand(time(NULL));
            int power = 10 + floor(sqrt(playerLevel)) * (rand() % 3);
            int capability = 10 + floor(sqrt(playerLevel)) * (rand() % 3);
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

    vector<Weapon> getWeapons()
    {
        return weapon;
    }
    vector<StaminaPotion> getStamina()
    {
        return Stamina;
    }
    vector<HPDrink> getHP()
    {
        return HP;
    }
    vector<Fruitage> getFruitage()
    {
        return fruitage;
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
        cout << "\"WELCOME TO OUR STORE!\"\nWhich one do you want?\n1. Weapon\n2. First aid box(To increse Stamina)\n3. Edible(To increase Hp)\n4. Fruitage(To increase Stamina and Hp)\n5. Exit."
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
                cout << i + 1 << "- " << Stamina[i].getName() << endl
                     << "- Price: " << Stamina[i].getPrice() << endl
                     << "- Power:" << Stamina[i].getPower() << endl;
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
                cout << i + 1 << "- " << HP[i].getName() << endl
                     << "- Price: " << HP[i].getPrice() << endl
                     << "- Power: " << HP[i].getPower() << endl;
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
            cout << "Fruitage : \n";
            for (int i = 0; i < fruitage.size(); i++)
            {
                cout << i + 1 << ". " << fruitage[i].getName() << endl
                     << "- Price: " << fruitage[i].getPrice() << endl
                     << "- Power:" << fruitage[i].getPower() << endl;
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

        case 5:
            return;

        default:
            cerr << "Invalid command!\n";
            break;
        }
    }
};

class Factory
{
private:
    Human human;
    Player player;
    string EnemyType;
    Model *model;
    Store store;

public:
    Factory() = default;
    Factory(Human human1, Player player1, Model *model1, string enemyType, Store store1)
    {
        human = human1;
        player = player1;
        // enemyType = enemyType1;
        model = model1;
        store = store1;
        EnemyType = enemyType;
        model->setHuman(human);
        model->setPlayer(player);
    }

    void factory()
    {

        if (player.getLevel() < 10)
        {
            EnemyType = "Zambie";
        }
        else
        {
            srand(time(NULL));
            vector<string> names = {"Shadowblade", "Nightshade", "Inferno", "Frostbite", "Venomous", "Grimreaper", "Darkheart", "Bloodfang", "Doombringer", "Warlock"};
            int i = rand() % 10;
            EnemyType = names[i];
        }
        if (EnemyType == "Zambie")
        {
            srand(time(NULL));
            double a1 = 0.7 + (rand() % 100) / 100;
            double a2 = 0.7 + (rand() % 100) / 100;
            double a3 = 0.7 + (rand() % 100) / 100;
            Weapon w("fist", 5, 1, 0, 'p', 'c');
            Human enemy(int(a1 * human.getStamina()), int(a2 * human.getHP()), int(a3 * human.getPower()), 0, 0);

            enemy.setName(EnemyType);
            model->setEnemy(enemy);
        }
        else
        {
            srand(time(NULL));
            double a1 = 0.7 + (rand() % 100) / 100;
            double a2 = 0.7 + (rand() % 100) / 100;
            double a3 = 0.7 + (rand() % 100) / 100;
            double a4 = 0.7 + (rand() % 100) / 100;
            double a5 = 0.7 + (rand() % 100) / 100;
            int a6 = rand() % 7 - 2;
            vector<Weapon> w = {};
            for (int i = 0; i < human.getWeapon().size() + a6; i++)
            {
                int j = rand() % store.getWeapons().size();
                w.push_back(store.getWeapons()[j]);
            }
            a6 = rand() % 7 - 2;
            vector<StaminaPotion> sp = {};
            for (int i = 0; i < human.getStaminaItems().size() + a6; i++)
            {
                int j = rand() % store.getStamina().size();
                sp.push_back(store.getStamina()[j]);
            }
            a6 = rand() % 7 - 2;
            vector<HPDrink> hp = {};
            for (int i = 0; i < human.getHPItems().size() + a6; i++)
            {
                int j = rand() % store.getHP().size();
                hp.push_back(store.getHP()[j]);
            }
            a6 = rand() % 7 - 2;
            vector<Fruitage> fr = {};
            for (int i = 0; i < human.getFruitageItems().size() + a6 + 1; i++)
            {
                int j = rand() % store.getFruitage().size();
                fr.push_back(store.getFruitage()[j]);
            }
            Human enemy(a1 * human.getStamina(), a2 * human.getHP(), a3 * human.getPower(), w, sp, hp, fr, a4 * human.getWarmskill(), a5 * human.getColdskill());
            model->setEnemy(enemy);
            enemy.setName(EnemyType);
        }
    }
};

class Controller
{
private:
    Model *model;
    Store *store;

public:
    Controller(Model *model1, Store *store1)
    {
        model = model1;
        store = store1;
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

                else
                {
                    int newHP = model->getEnemy().getHP() - model->getEnemy().getWeapon()[index].getPower();
                    model->enemy.setHP(newHP);
                }

                // attakerPower "+" weaponPower

                model->human.setStamina(model->getEnemy().damagePower(index, model->enemy));

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

                    Factory factory1(model->human, model->player, model, "Zambie", *store);
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
            int HP = model->getEnemy().getHP();
            int Hstamina = model->getHuman().getStamina();

                    cout << model->enemy.getName() << " Attacked!" << endl
                         << "-Enemy: " << endl
                         << " Stamina: " << model->getEnemy().getStamina() << endl
                         << " HP: " << model->getEnemy().getHP() << " (" << HP << ")" << endl
                         << "-You: " << endl
                         << " Stamina: " << model->getHuman().getStamina() << " (" << Hstamina << ")" << endl
                         << " HP: " << model->getHuman().getHP() << endl
                         << endl;
                    return;
                }
            }
            return;
        }
        else
        {
            if (model->getEnemy().getWeapon().empty())
            {
                cout << "The enemy surrendered!" << endl;
                return;
            }
            int Hstamina = model->getHuman().getStamina();
            int fruitSize = model->getEnemy().getFruitageItems().size();
            int staminaSize = model->getEnemy().getStaminaItems().size();
            int Stamina = model->getEnemy().getStamina();
            int HPsize = model->getEnemy().getHPItems().size();
            int HP = model->getEnemy().getHP();
            if (staminaSize > 0 || fruitSize > 0)
            {
                bool healthy = 1;
                for (int i = 0; i < model->getHuman().getWeapon().size(); i++)
                {
                    if (model->getHuman().damagePower(i, model->human) > Stamina)
                    {
                        healthy = 0;
                    }
                }
                if (!healthy)
                {
                    if (!model->getEnemy().getStaminaItems().empty())
                        model->getEnemy().useStamina(0);
                    else
                    {
                        model->getEnemy().useFruitage(0);
                        cout << model->getEnemy().getName() << " used HP drink!" << endl
                             << "new HP: " << model->getEnemy().getHP() << "(" << HP << ")" << endl;
                    }
                    cout << model->getEnemy().getName() << " used Stamina potion!" << endl
                         << "new Stamina: " << model->getEnemy().getStamina() << "(" << Stamina << ")" << endl;
                    enemyAttack();
                }
            }
            if (HPsize > 0 || fruitSize > 0)
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
                    if (!model->getEnemy().getHPItems().empty())
                        model->getEnemy().useHP(0);
                    else
                    {
                        model->getEnemy().useFruitage(0);
                        cout << model->getEnemy().getName() << " used Stamina potion!" << endl
                             << "new Stamina: " << model->getEnemy().getStamina() << "(" << Stamina << ")" << endl;
                    }
                    cout << model->getEnemy().getName() << " used HP drink!" << endl
                         << "new HP: " << model->getEnemy().getHP() << "(" << HP << ")" << endl;
                    enemyAttack();
                }
            }

            for (int i = 0; i < model->getEnemy().getWeapon().size(); i++)
            {
                if (Attack('A', i))
                {
                    cout << model->enemy.getName() << " Attacked!" << endl
                         << "-Enemy: " << endl
                         << " Stamina: " << model->getEnemy().getStamina() << endl
                         << " HP: " << model->getEnemy().getHP() << " (" << HP << ")" << endl
                         << "-You: " << endl
                         << " Stamina: " << model->getHuman().getStamina() << " (" << Hstamina << ")" << endl
                         << " HP: " << model->getHuman().getHP() << endl
                         << endl;
                    return;
                }
            }
            cout << "The enemy surrendered!" << endl;
            return;
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
             << "3. Level up" << endl
             << "4. exit" << endl;
        int YourHp = model->getHuman().getHP();
        int YourStamina = model->getHuman().getStamina();
        int EnemyStamina = model->getEnemy().getStamina();
        int EnemyHP = model->getEnemy().getHP();

        int command;
        cin >> command;
        switch (command)
        {
        case 1:
            if (model->getHuman().getWeapon().empty())
            {
                cout << "No Weapons available!\n";
                round();
            }
            else
            {
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
                        controller.enemyAttack();
                    }
                }

                else
                {
                    cerr << "Out of range!";
                    round();
                }
            }
            break;

        case 2:
            int choice;
            cout << "Choose an item to use:\n";
            cout << "21. Stamina Potion\n";
            cout << "22. HP Drink\n";
            cout << "23. Fruitage\n";
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
                break;
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
                break;
            case 23:

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
                break;
            }
            round();
            break;
        case 3:
            if (model->getPlayer().getExperience() <= model->getPlayer().getLevel())
            {
                cerr << "Level up is not possible.\n";
                round();
            }
            else
            {
                srand(time(NULL));
                int level = model->player.getExperience();
                model->player.setLevel(level);
                model->human.setPower(model->human.getPower() + 5 * floor(level / 10));
                model->human.setColdskill(model->human.getColdskill() + (rand() % 4) * level);
                model->human.setWarmskill(model->human.getWarmskill() + (rand() % 4) * level);
                store->addFruitageByLevel(level);
                store->addHPByLevel(level);
                store->addStaminaByLevel(level);
                store->addWeaponByLevel(level);
            }
            break;
        case 4:
            return;
        default:
            cerr << "Incorrect command";
            round();
            break;
        }
    }
};

int main()
{
    string name;
    cout << "Enter your name" << endl;
    cin >> name;

    int age;
    cout << "Enter your age" << endl;
    cin >> age;

    char gender;
    cout << "Enter your gender (m/w)" << endl;
    cin >> gender;

    int power; 
    cout << "Enter a power" << endl;
    cin >> power;

    int stamina;
    cout << "Enter a Stamina" << endl;
    cin >> stamina;

    int hp;
    cout << "Enter a HP" << endl;
    cin >> hp;

    int level;
    cout << "Enter a Level"<< endl;
    cin >> level;

    int money;
    cout << "Enter money" << endl;
    cin >> money;

    Human zahra(stamina, hp, power, power/2, power/2);
    Player zar(name, age, gender, level, money);
    Model model1;
    Model *model = &model1;

    int playerLevel = 1;

    vector<StaminaPotion> Stamina = {};
    vector<HPDrink> HP = {};
    Weapon Knife("Knife ", 10, 2, 8, 'p', 'c');
    Weapon Bomb("Bomb ", 20, 1, 15, 't', 'w');
    vector<Weapon> weaponsToAdd{Knife, Bomb};
    zahra.setWeapon(weaponsToAdd);
    vector<Fruitage> fruitage = {};

    Store store(Stamina, HP, weaponsToAdd, model);
    store.addStaminaByLevel(playerLevel);
    store.addHPByLevel(playerLevel);
    store.addWeaponByLevel(playerLevel);

    Factory factory1(zahra, zar, model, "Zambie", store);
    factory1.factory();
    Controller controller(model, &store);
    view view1(model, controller, &store);
    int randomAction = 1;
    srand(time(NULL));
    while (model->getHuman().isAlive())
    {
        randomAction = rand() % 2;
        if (randomAction == 0)
        {
            store.store();
        }
        else
        {
            view1.round();
        }
    }
}
