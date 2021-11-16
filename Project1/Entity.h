#pragma once

#include<iostream>

using namespace std;

class entity {

protected:
    int HP = 10; //HP = HEAL POINTS = Puntos de vida
    int lvl = 1; //lvl = Level = Nivel
    int Atk = 1; //Atk = Attack = ataque, cuan fuerte ataca
public:
    entity();
    ~entity();
    int getHP();
    int getlvl();
    int getAtk();
    void setHP(int);
    void lvlup();

};

class player : public entity {

private:
    int XP = 0;
    int baseHP = 15;
    int baseAtk = 8;
public:
    player();
    ~player();
    int getXP();
    void restock();
    void setXP(int);

};

class enemy : public entity {

private:
    string suffix[3] = {"Super","Hyper","Ultra"};
    string rname[11] = { "Rata","Mono","Buho","Toro","Leon","Ente","Mago","Ogro","DINO","DRGN","HYDR" };
public:
    enemy(int);
    enemy(int, int);
    ~enemy();
    int Drop(int);
    string getName(int i);
    string getSuffix(int i);

};
