#include<iostream>

#include"Entity.h"

// Entity

entity::entity() {}
entity::~entity() {}
int entity::lvlup() {
    lvl++;
}
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

// Player

player::player() {

    HP = 15;
    Atk = 2;

}
player::~player() {}
int player::getXP() {
    return XP;
}
void player::setXP(int x) {
    XP += x;
}

// Enemy

enemy::enemy(int randnum) {

    lvl *= (randnum + 1);
    HP += (randnum + 1) * 2;
    Atk += (randnum + 1) * 3;

}
enemy::enemy(int randnum, int boss) {

    lvl *= (randnum + 1) * boss;
    HP += (randnum + 1) * 2 + boss;
    Atk += (randnum + 1) * 3 + boss;

}
enemy::~enemy() {}
int enemy::Drop(int x) {
    x += x * 10;
    return x;
}
