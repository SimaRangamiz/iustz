#include <iostream>
#include <string>
using namespace std;

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
