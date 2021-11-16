#include<iostream>

#include"Entity.h"
#include"Functions.h"

using namespace std;

namespace myfunc {

    void menu() {

        string elements[] = { "Hunt","Save","Exit" };

        cout << "//********************************************************//" << endl;                           // decoracion

        for (int i = 0; i < sizeof(elements) / sizeof(elements[0]); i++) {                                           // se limita la variable i al tamaño del array
            cout << "//   # (" << i + 1 << ")" << elements[i] << "                                            //" << endl;  // se imprime todo el contenido del array
        }

        cout << "//********************************************************//" << endl;                           // decoracion

    }

    void save() {



    }

    void lvlup(int lvl) {

        cout << "//********************************************************//" << endl;
        cout << "//                                                        //" << endl;
        cout << "//       Felicidades, has subido a nivel " << lvl << "!       //" << endl;
        cout << "//                                                        //" << endl;
        cout << "//********************************************************//" << endl;

    }

    void runaway() {

        cout << "//********************************************************//" << endl;
        cout << "//                                                        //" << endl;
        cout << "//              Haz abandonado el combate...              //" << endl;
        cout << "//                                                        //" << endl;
        cout << "//********************************************************//" << endl;

    }

    void victory() {

        cout << "//********************************************************//" << endl;
        cout << "//                                                        //" << endl;
        cout << "//                      Haz ganado!!                      //" << endl;
        cout << "//                                                        //" << endl;
        cout << "//********************************************************//" << endl;

    }

}

