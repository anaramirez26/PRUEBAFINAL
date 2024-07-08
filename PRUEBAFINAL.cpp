/*LIBRERIAS*/
#include "iostream"
#include "string"
#include "ctime"
#include "cstdlib"
#include "unistd.h"
using namespace std;

/*PROTOTIPO DE FUNCION*/
bool yaColocado(int, int mat[3][3]);
void marcarNumero(int, int mat[3][3]);

/*FUNCION MAIN*/
int main(void)
{   
    srand(time(0)); /*INICIALIZANDO EL GENERADOR DE NUMEROS ALEATORIOS*/
    /*VARIABLES DECLARADAS*/
    int opc, numAl; /* VARIABLE PARA SWITCH PRINCIPAL Y NUMEROS ALEATORIOS*/
    string arrjug[2]; /* ARREGLO PARA NOMBRES DE JUGADORES */
    int mat[2][3][3] = {0}; /*MATRICES PARA CADA JUGADOR*/

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
            case 1: {
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
                for (int k = 0; k < 2; k++) {
                    cout << "Tablero del jugador " << arrjug[k] << " : " << endl << endl;

                    /*GENERAR NUMEROS ALEATORIOS UNICOS PARA CADA TABLERO*/
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            do {
                                numAl = 1 + rand() % 20;
                            } while (yaColocado(numAl, mat[k]));
                            mat[k][i][j] = numAl;
                        }
                    }

                    /*MOSTRAR EL TABLERO DE CADA JUGADOR*/
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            cout << mat[k][i][j] << "  ";
                        }
                        cout << endl << endl;
                    }

                }

                /*PAUSA Y PRESIONAR ENTER PARA QUE EL BOT COMIENCE A GENERAR NUMEROS*/
                cout << "Presione Enter para que el bot genere el primer numero..." << endl;
                cin.ignore();
                cin.get();

                cout << endl << "LA PARTIDA HA COMENZADO!" << endl;

                /*BUCLE MIENTRAS EL JUEGO NO ESTE TERMINADO*/
                bool juegoTerminado = false;
                while(!juegoTerminado) {

                    /*BOT GENERA NUMEROS ALEATORIOS*/
                    numAl = 1 + rand() % 20;
                    cout << endl << endl << "Numero generado por el bot: " << numAl << endl << endl;

                    /*LLAMA A LA FUNCION MARCAR NUMERO*/
                    for (int k = 0; k < 2; k++) {
                        marcarNumero(numAl, mat[k]);
                    }

                    /*MOSTRAR LOS TABLEROS ACTUALIZADOS*/
                    for (int k = 0; k < 2; k++) {
                        cout << "Tablero del jugador " << arrjug[k] << " actualizado : " << endl << endl;
                        for (int i = 0; i < 3; i++) {
                            for (int j = 0; j < 3; j++) {
                                cout << mat[k][i][j] << "  ";
                            }
                            cout << endl << endl;
                        }
                    }
                    
                    /*PAUSA ENTRE GENERACIONES DE NUMEROS*/
                    sleep(1);

                }

                break;
            }
            
            case 2: {
                cout << endl << "REGISTRO DE PARTIDAS" << endl << endl;
                break; 
            }

            case 3: {
                cout << endl << "REGISTRO DE GANADORES" << endl << endl;
                break;
            }
            
            case 4: {
                cout << endl << "INTEGRANTES DE MAX" << endl << endl;
                cout << endl << "Ana Belen Ramirez Flores 00183224" << endl;
                cout << endl << "Xochill Guissell Miguel Miranda 00114924" << endl;
                cout << endl << "Maria Fernanda Ramirez Portillo 00127724" << endl;
                cout << endl << endl;
                break;
            }

            case 5: {
                cout << endl << "INSTRUCCIONES DEL JUEGO" << endl << endl;
                break;
            }

            case 6: {
                cout << "SALIR " << endl;
                break;
            }

            default: {
            
                break;
            }
        }
    } while (opc != 6);

    return 0;
}

/*FUNCION PARA VERIFICAR SI UN NUMERO YA HA SIDO COLOCADO EN EL TABLERO*/
bool yaColocado(int num, int mat[3][3]) 
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mat[i][j] == num) {
                return true;
            }
        }
    }
    return false;
}

/*FUNCION PARA MARCAR UN NUMERO EN EL TABLERO REEMPLAZANDOLO POR CERO*/
void marcarNumero(int num, int mat[3][3])
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mat[i][j] == num) {
                mat[i][j] = 0;
            }
        }
    }
}