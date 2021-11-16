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

bool mloop = true, run = false;

string rname[] = { "Rata","Mono","Buho","Toro","Leon","Ente","Mago","Ogro","DINO","DRGN","HYDR" };

char charcomm;

int intcomm = 10, randnum, boss, pFHP, eFHP;

//**********************************//

int main() {

    srand(time(NULL));

    do {

        myfunc::menu();
        cout << ">> ";
        cin >> intcomm;

        switch (intcomm) {

        case 1:
            randnum = rand() % 12;

            if (randnum > 10) {
                randnum = rand() % 11;
                boss = rand() % 5 - 2;
            }
            else {
                boss = 0;
            }

            if (boss > 0) {
                enemy e(randnum, boss);
            }
            else {
                enemy e(randnum);

                cout << "//********************************************************//" << endl;
                cout << "//                                                        //" << endl;
                cout << "//         # Has encontrado un " << rname[randnum] << " lvl " << e.getlvl() << " salvje!         //" << endl;
                cout << "//                                                        //" << endl;
                cout << "//                 Quieres Combatir? Y/N.                 //" << endl;
                cout << "//                                                        //" << endl;
                cout << "//********************************************************//" << endl;
                cout << ">> ";
                cin >> charcomm;

                if (charcomm == 'Y' || charcomm == 'y') {

                    pFHP = p1.getHP();
                    eFHP = e.getHP();

                    while (p1.getHP() > 0 && e.getHP() > 0 && !run) {

                        cout << "//********************************************************//" << endl;
                        cout << "//                                                        //" << endl;
                        cout << "//            " << rname[randnum] << " HP:" << e.getHP() << "/" << eFHP << "    Player HP:" << p1.getHP() << "/" << pFHP << "            //" << endl;
                        cout << "//                                                        //" << endl;
                        cout << "//                   (A)Attack / (R)Run                   //" << endl;
                        cout << "//                                                        //" << endl;
                        cout << "//********************************************************//" << endl;
                        cout << ">> ";
                        cin >> charcomm;

                        if (charcomm == 'A') {
                            e.setHP(p1.getAtk());
                            p1.setHP(e.getAtk());
                            if (e.getHP() < 1) {
                                p1.setXP(e.Drop(randnum));
                                victory();
                            }
                        }
                        else if (charcomm == 'R') {
                            e.setHP(999);
                            runaway();
                        }
                    }

                    if (p1.getXP() >= 100) {
                        p1.lvlup();
                        p1.setXP(0);
                        lvlup(p1.getlvl());
                    }

                }

                cout << "Volviendo al menu principal...";

                system("pause");

                e.~enemy();
            }

            break;
        case 2:
            save();
            break;
        case 3:
            mloop = false;
            break;
        default:
            cout << "Opcion no valida, vuelve a intentarlo. ";
            system("pause");
        }

        intcomm = 10;
        charcomm = 'Z';

        system("cls");

    } while (mloop);


    return 0;
}