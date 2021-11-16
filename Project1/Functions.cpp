#include<iostream>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

#include"Entity.h"
#include"Functions.h"

using namespace std;

namespace myfunc {

    void menu(player p1) {

        string elements[] = { "Hunt","Load","Save","Help","Exit"};

        cout << "//********************************************************//" << endl;                           // decoracion

        for (int i = 0; i < sizeof(elements) / sizeof(elements[0]); i++) {                                        // se limita la variable i al tamaño del array
            switch (i) {                                                                                          // se imprime todo el contenido del array
            case 0:
                cout << "//   # (" << i + 1 << ")" << elements[i] << "                    STATS                   //" << endl;
                break;
            case 1:
                cout << "//   # (" << i + 1 << ")" << elements[i] << "               HP:" << p1.getHP() << "     Atk:"<<p1.getAtk()<< "              //" << endl;
                break;
            case 2:
                if (p1.getXP() < 10) {
                    cout << "//   # (" << i + 1 << ")" << elements[i] << "               Lvl:" << p1.getlvl() << "     XP:" << p1.getXP() << "/100           //" << endl;
                }
                else if (p1.getXP() > 9) {
                    cout << "//   # (" << i + 1 << ")" << elements[i] << "               Lvl:" << p1.getlvl() << "     XP:" << p1.getXP() << "/100          //" << endl;
                }
                break;
            default:
                cout << "//   # (" << i + 1 << ")" << elements[i] << "                                            //" << endl;

            }
        }

        cout << "//********************************************************//" << endl;                           // decoracion

    }

    void load() {

        try {

        }
        catch (exception e) {
            cout<<"Hubo un error al cargar la partida" << endl;
        }

    }

    void save() {

        try {

        }
        catch (exception e) {
            cout << "Hubo un error al guardar la partida" << endl;
        }

    }

    int battle(player p1) {

        srand(time(NULL));

        bool run = false;
        
        char command;

        int random, level = 0, boss, pFHP, eFHP;

        random = rand() % 13;

        if (random > 11) {
            boss = rand() % (5 - 2);
        }
        else {
            boss = 0;
        }

        random = rand() % (121 - 1); // se define el nivel del enemigo con un numero aleatorio

        if (random < 2) {
            level = 11;
        }else if (random > 1 && random < 7) {
            level = 10;
        }else if (random > 6 && random < 13) {
            level = 9;
        }else if (random > 12 && random < 20) {
            level = 8;
        }else if (random > 19 && random < 28) {
            level = 7;
        }else if (random > 27 && random < 37) {
            level = 6;
        }else if (random > 36 && random < 47) {
            level = 5;
        }else if (random > 46 && random < 58) {
            level = 4;
        }else if (random > 57 && random < 70) {
            level = 3;
        }else if (random > 69 && random < 83) {
            level = 2;
        }else if (random > 82) {
            level = 1;
        }


        if (boss != 0) {
            enemy e(level, boss);
            
            cout << "//********************************************************//" << endl;
            cout << "//                                                        //" << endl;
            cout << "//       # Has encontrado un "<<e.getSuffix(boss) << " " << e.getName(level) << " lvl " << e.getlvl() << " salvje!       //" << endl;
            cout << "//                                                        //" << endl;
            cout << "//                 Quieres Combatir? Y/N.                 //" << endl;
            cout << "//                                                        //" << endl;
            cout << "//********************************************************//" << endl;
            cout << ">> ";
            cin >> command;

            if (command == 'Y' || command == 'y') {

                pFHP = p1.getHP();
                eFHP = e.getHP();

                while (p1.getHP() > 0 && e.getHP() > 0 && !run) {

                    cout << "//********************************************************//" << endl;
                    cout << "//                                                        //" << endl;
                    cout << "//          " <<e.getSuffix(boss) <<" "<< e.getName(level) << " HP:" << e.getHP() << "//" << eFHP << "    Player HP:" << p1.getHP() << "/" << pFHP << "          //" << endl;
                    cout << "//                                                        //" << endl;
                    cout << "//                   (A)Attack / (R)Run                   //" << endl;
                    cout << "//                                                        //" << endl;
                    cout << "//********************************************************//" << endl;
                    cout << ">> ";
                    cin >> command;

                    if (command == 'A' || command == 'a') {
                        e.setHP(p1.getAtk());
                        p1.setHP(e.getAtk());
                    }
                    else if (command == 'R' || command == 'r') {
                        run = true;
                    }
                }

                if (e.getHP() < 1 && p1.getHP() > 0) {
                    victory();
                    return e.Drop(level);
                }
                else if (p1.getHP() < 1 && e.getHP() > 0) {
                    youdied();
                    return 0;
                }
                else {
                    runaway();
                    return 0;
                }

            }

            e.~enemy();

        }
        else {
            enemy e(level);

            cout << "//********************************************************//" << endl;
            cout << "//                                                        //" << endl;
            cout << "//         # Has encontrado un " << e.getName(level) << " lvl " << e.getlvl() << " salvje!         //" << endl;
            cout << "//                                                        //" << endl;
            cout << "//                 Quieres Combatir? Y/N.                 //" << endl;
            cout << "//                                                        //" << endl;
            cout << "//********************************************************//" << endl;
            cout << ">> ";
            cin >> command;

            if (command == 'Y' || command == 'y') {

                pFHP = p1.getHP();
                eFHP = e.getHP();

                while (p1.getHP() > 0 && e.getHP() > 0 && !run) {

                    cout << "//********************************************************//" << endl;
                    cout << "//                                                        //" << endl;
                    cout << "//            " << e.getName(level) << " HP:" << e.getHP() << "/" << eFHP << "    Player HP:" << p1.getHP() << "/" << pFHP << "            //" << endl;
                    cout << "//                                                        //" << endl;
                    cout << "//                   (A)Attack / (R)Run                   //" << endl;
                    cout << "//                                                        //" << endl;
                    cout << "//********************************************************//" << endl;
                    cout << ">> ";
                    cin >> command;

                    if (command == 'A' || command == 'a') {
                        e.setHP(p1.getAtk());
                        p1.setHP(e.getAtk());
                    }
                    else if (command == 'R' || command == 'r') {
                        run = true;
                    }
                }

                if (e.getHP() < 1 && p1.getHP() > 0) {
                    victory();
                    return e.Drop(level);
                }
                else if (p1.getHP() < 1 && e.getHP() > 0) {
                    youdied();
                    return 0;
                }
                else {
                    runaway();
                    return 0;
                }

            }

            e.~enemy();
        }
    }

    void help() {

        cout << "//********************************************************//" << endl;
        cout << "//                                                        //" << endl;
        cout << "//                      <COMO JUGAR>                      //" << endl;
        cout << "//                                                        //" << endl;
        cout << "//        #En la pantalla de inicio podras ver las        //" << endl;
        cout << "//         opciones principales a la izquierda y          //" << endl;
        cout << "//         estadisticas a la derecha, ten en cuenta       //" << endl;
        cout << "//         esta informacion ya que al momento de          //" << endl;
        cout << "//         un combate esto definira quien sera el         //" << endl;
        cout << "//         ganador.                                       //" << endl;
        cout << "//                                                        //" << endl;
        cout << "//        #Trata de combatir con enemigos que sean        //" << endl;
        cout << "//         de un nivel igual o menor al tuyo para         //" << endl;
        cout << "//         asegurar la victoria!                          //" << endl;
        cout << "//                                                        //" << endl;
        cout << "//        #Ten cuidado con los enemigos especiales!       //" << endl;
        cout << "//         estos apareceran como una version mas          //" << endl;
        cout << "//         poderosa que los normales, puedes iden-        //" << endl;
        cout << "//         tificarlos por tener un sufijo antes de        //" << endl;
        cout << "//         su nombre y estos pueden ser hasta 3           //" << endl;
        cout << "//         veces mas fuertes que su version normal        //" << endl;
        cout << "//         segun el sufijo que posean.                    //" << endl;
        cout << "//                                                        //" << endl;
        cout << "//         *Super >> lvl +2, HP x2 +2, Atk +2             //" << endl;
        cout << "//         *Hyper >> lvl +3, HP x2 +3, Atk +3             //" << endl;
        cout << "//         *Ultra >> lvl +4, HP x2 +4, Atk +4             //" << endl;
        cout << "//                                                        //" << endl;
        cout << "//                        <ABOUT>                         //" << endl;
        cout << "//                                                        //" << endl;
        cout << "//           Developed by Alfonso Lozano Piedra           //" << endl;
        cout << "//                                                        //" << endl;
        cout << "//********************************************************//" << endl;
        system("pause");

    }

    void lvlup(int lvl) {

        cout << "//********************************************************//" << endl;
        cout << "//                                                        //" << endl;
        cout << "//            Felicidades, has subido a Lvl " << lvl << "!            //" << endl;
        cout << "//                                                        //" << endl;
        cout << "//********************************************************//" << endl;
        system("pause");
    }

    void runaway() {

        cout << "//********************************************************//" << endl;
        cout << "//                                                        //" << endl;
        cout << "//              Haz abandonado el combate...              //" << endl;
        cout << "//                                                        //" << endl;
        cout << "//********************************************************//" << endl;
        system("pause");
    }

    void victory() {

        cout << "//********************************************************//" << endl;
        cout << "//                                                        //" << endl;
        cout << "//                      Haz ganado!!                      //" << endl;
        cout << "//                                                        //" << endl;
        cout << "//********************************************************//" << endl;
        system("pause");
    }

    void youdied() {

        cout << "//********************************************************//" << endl;
        cout << "//                                                        //" << endl;
        cout << "//                      Haz muerto!!                      //" << endl;
        cout << "//                                                        //" << endl;
        cout << "//********************************************************//" << endl;
        system("pause");
    }
    
}
