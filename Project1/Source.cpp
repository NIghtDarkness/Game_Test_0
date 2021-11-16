#include<iostream>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

#include"Entity.h"
#include"Functions.h"

//using namespace std;
using namespace myfunc;

// Declaracion de variables globales//

player p1;

bool mloop = true;

int command;

//**********************************//

int main() {

    do {

        menu(p1);
        cout << ">> ";
        cin >> command;

        switch (command) {

        case 1:
            p1.setXP(battle(p1));

            if (p1.getXP() >= 100) {
                p1.lvlup();
                p1.setXP(- p1.getXP());
                lvlup(p1.getlvl());
            }
            break;
        case 2:
            load();
            break;
        case 3:
            save();
            break;
        case 4:
            help();
            break;
        case 5:
            mloop = false;
            break;
        default:
            cout << "Opcion no valida, vuelve a intentarlo. ";
            command = 10;
            system("pause");
        }

        p1.restock();
        command = 10;
        //charcomm = NULL;

        system("cls");

    } while (mloop);

    return 0;
}