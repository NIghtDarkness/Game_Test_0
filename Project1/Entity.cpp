#include<iostream>

#include"Entity.h"

using namespace std;

// Entity

entity::entity() {}
entity::~entity() {}
int entity::getHP() {
    return HP;
}
int entity::getlvl() {
    return lvl;
}
int entity::getAtk() {
    return Atk;
}
void entity::setHP(int dmg) {
    HP -= dmg;
}
void entity::lvlup() {
    lvl++;
}

// Player

player::player() {

    HP = baseHP*lvl;
    Atk = baseAtk*lvl;

}
player::~player() {}
int player::getXP() {
    return XP;
}
void player::setXP(int x) {
    XP += x;
}
void player::restock() {
    HP = baseHP * lvl;
}

// Enemy

enemy::enemy(int level) {

    lvl *= (level);
    HP += (level) * 2;
    Atk += (level) * 3;

}

enemy::enemy(int level, int boss) {

    lvl *= (level) + boss;
    HP += (level) * 2 + boss;
    Atk += (level) + boss;

}

enemy::~enemy() {}

int enemy::Drop(int x) {
    x += x * 10;
    return x;
}

string enemy::getName(int i){
    return rname[i-1];
}

string enemy::getSuffix(int i) {
    return suffix[i];
}
