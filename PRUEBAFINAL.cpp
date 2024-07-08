/*LIBRERIAS*/
#include "iostream"
#include "string"
#include "ctime"
#include "cstdlib"
#include "unistd.h"
using namespace std;

/*FUNCION MAIN*/
int main(void)
{   
    /*VARIABLES DECLARADAS*/
    int opc; /*VARIABLE PARA SWITCH PRINCIPAL*/

    /*DO WHILE PARA SWITCH PRINCIPAL*/
    do {
        /* MENU PRINCIPAL */
        cout << endl << "BIENVENIDO A..." << endl << endl;
        cout << "BINGO!" << endl << endl;
        cout << "Seleccione la opcion que desee: " << endl;
        cout << "1. NUEVA PARTIDA" << endl;     
        cout << "2. REGISTRO DE PARTIDAS" << endl; 
        cout << "3. REGISTRO DE GANADORES" << endl; 
        cout << "4. INTEGRANTES DE MAX" << endl;
        cout << "5. INSTRUCCIONES DEL JUEGO" << endl;
        cout << "6. SALIR DEL JUEGO" << endl;
        cin >> opc;

        /*SWITCH PRINCIPAL*/
        switch (opc) {
            case 1: 
                /* CASE DE NUEVA PARTIDA */
                cout << endl << endl << "NUEVA PARTIDA" << endl << endl;
                break;
            
            case 2: 
                cout << endl << "REGISTRO DE PARTIDAS" << endl << endl;
                break; 
            
            case 3: 
                cout << endl << "REGISTRO DE GANADORES" << endl << endl;
                break;
            
            case 4:
                cout << endl << "INTEGRANTES DE MAX" << endl << endl;
                cout << endl << "Ana Belen Ramirez Flores 00183224" << endl;
                cout << endl << "Xochill Guissell Miguel Miranda 00114924" << endl;
                cout << endl << "Maria Fernanda Ramirez Portillo 00127724" << endl;
                cout << endl << endl;
                break;
            
            case 5: 
                cout << endl << "INSTRUCCIONES DEL JUEGO" << endl << endl;
                break;

            case 6:
                cout << "SALIR " << endl;
                break;

            default: 
            
                break;
        }
    } while (opc != 6);

    return 0;
}