#pragma once
#include<iostream>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

namespace myfunc {

    void menu(player);
    void load();
    void save();
    int battle(player);
    void help();
    void lvlup(int);
    void runaway();
    void victory();
    void youdied();
}