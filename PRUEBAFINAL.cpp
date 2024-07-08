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
    srand(time(0)); /*INICIALIZANDO EL GENERADOR DE NUMEROS ALEATORIOS*/
    /*VARIABLES DECLARADAS*/
    int opc, numAl, mat[3][3]; /* VARIABLE PARA SWITCH PRINCIPAL, NUMEROS ALEATORIOS, MATRIZ DE JUGADORES */
    string arrjug[2]; /* ARREGLO PARA NOMBRES DE JUGADORES */

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

                /* INGRESAR NOMBRE DE JUGADORES */
                for (int i = 0; i < 2; i++) {
                    cout << "Ingrese el nombre del jugador " << (i + 1) << " : ";
                    cin >> arrjug[i];
                }
                
                /* LISTA DE NOMBRES DE JUGADORES */
                cout << endl << "Los nombres de los jugadores son: " << endl;
                for (int i = 0; i < 2; i++) {
                    cout << "Jugador " << (i + 1) << " : " << arrjug[i] << endl;
                }

                cout << endl << endl;

                cout << endl << "TABLEROS DE JUGADORES" << endl << endl;
                /* GENERAR Y MOSTRAR LOS TABLEROS PARA CADA JUGADOR */
                for (int i = 0; i < 2; i++) {
                    cout << "Tablero del jugador " << arrjug[i] << " : " << endl << endl;

                    for (int k = 0; k < 3; k++) {
                        for (int j = 0; j < 3; j++) {
                            numAl = 1 + rand() % 20; 
                            mat[k][j] = numAl;       
                        }
                    }

                    for (int k = 0; k < 3; k++) {
                        for (int j = 0; j < 3; j++) {
                            cout << mat[k][j] << "  "; 
                        }
                        cout << endl << endl; 
                    }
                }
                
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