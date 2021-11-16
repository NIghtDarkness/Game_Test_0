#pragma once
class entity {

protected:
    int HP = 10; //HP = HEAL POINTS = Puntos de vida
    int lvl = 1; //lvl = Level = Nivel
    int Atk = 1; //Atk = Attack = ataque, cuan fuerte ataca
public:
    entity();
    ~entity();
    int lvlup();
    int getHP();
    int getlvl();
    int getAtk();
    void setHP(int);

};

class player : public entity {

private:
    int XP = 0;
public:
    player();
    ~player();
    int getXP();
    void setXP(int);

};

class enemy : public entity {

private:
    int XPDropRate = 1;
public:
    enemy(int);
    enemy(int, int);
    ~enemy();
    int Drop(int);

};
