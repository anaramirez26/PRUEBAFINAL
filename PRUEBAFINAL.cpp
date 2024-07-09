/*LIBRERIAS*/
#include "iostream"
#include "string"
#include "ctime"
#include "cstdlib"
#include "unistd.h"
#include "fstream"
using namespace std;

/*PROTOTIPO DE FUNCION*/
void nuevaPartida(string arrjug[2], int mat[2][3][3]);
bool yaColocado(int, int mat[3][3]);
void generarTablero(int mat[3][3]);
void mostrarTablero(int mat[3][3]);
bool yaDicho(int, int [], int);
void marcarNumero(int, int mat[3][3]);
void tableroActualizado(int mat[3][3]);
bool tableroCompleto(int mat[3][3]);
bool verificarEmpate(int mat[2][3][3]);
void mostrarGanador(int mat[2][3][3], string arrjug[2], bool &juegoTerminado);

int contadorPartidas = 1; /*INICIALIZANDO EN 1 LA VARIABLE CONTADOR DE PARTIDAS PARA REGISTRO DE PARTIDAS*/
int contadorPartidasGanadas = 1; /*INICIALIZANDO EN 1 LA VARIABLE CONTADOR DE PARTIDAS GANADAS PARA REGISTRO DE GANADORES*/
/*FUNCION MAIN*/
int main(void)
{   
    srand(time(0)); /*INICIALIZANDO EL GENERADOR DE NUMEROS ALEATORIOS*/
    /*VARIABLES DECLARADAS*/
    int opc, numAl, opcion; /*VARIABLES "OPC" PARA SWITCH PRINCIPAL, "NUMAL" PARA NUMEROS ALEATORIOS, "OPCION" PARA MOSTRAR AYUDA O CONTINUAR PARTIDA*/
    string arrjug[2]; /* ARREGLO PARA NOMBRES DE JUGADORES */
    int mat[2][3][3] = {0}; /*MATRICES PARA CADA JUGADOR*/
    int numerosDichos[20] = {0}; /*ARREGLO DE NUMEROS YA DICHOS POR EL BOT*/
    int contadorNumerosDichos = 0; /*CONTADOR DE NUMEROS YA DICHOS INICIALIZADO EN CERO*/

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
               nuevaPartida(arrjug, mat);
                break;
            }
            
            case 2: {
                cout << endl << "REGISTRO DE PARTIDAS" << endl << endl;

                 /*CREANDO ARCHIVO PARA REGISTRO DE PARTIDAS*/
                ofstream archivo("registropartidas.txt", ios::app);

                if (archivo.is_open()) {
                    /*REGISTRAR DENTRO DEL ARCHIVO LAS PARTIDAS, JUGADORES Y SUS PUNTUACIONES*/
                    archivo << "Partida #" << contadorPartidas << ":" << endl;
                    archivo << "Jugadores: " << arrjug[0] << " y " << arrjug[1] << endl;

                    int puntuacionJugador1 = 0, puntuacionJugador2 = 0;
                    /*FOR QUE CUENTA LA PUNTUACION DE LOS JUGADORES CON RESPECTO A LOS NUMEROS MARCADOS EN SU TABLERO*/
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            if (mat[0][i][j] == 0) {
                                puntuacionJugador1++;
                            }
                            if (mat[1][i][j] == 0) {
                                puntuacionJugador2++;
                            }
                        }
                    }
                    archivo << "Puntuacion de " << arrjug[0] << ": " << puntuacionJugador1 << "/9" << endl;
                    archivo << "Puntuacion de " << arrjug[1] << ": " << puntuacionJugador2 << "/9" << endl;
                    archivo << endl;

                    archivo.close();
                    cout << "Historial de partidas guardado en 'registropartidas.txt'" << endl << endl;
                } else {
                    cout << "Error al abrir el archivo 'registropartidas.txt'" << endl;
                }

                contadorPartidas++;

                /*LEYENDO ARCHIVO DE REGISTRO DE PARTIDAS*/
                ifstream archivoLectura("registropartidas.txt");

                if (archivoLectura.is_open()) {
                    string linea;
                    while (getline(archivoLectura, linea)) {
                        cout << linea << endl;
                    }
                    archivoLectura.close();
                } else {
                    cout << "No se pudo abrir el archivo 'registropartidas.txt'" << endl;
                }

                break; 
            }

            case 3: {
                cout << endl << "REGISTRO DE GANADORES" << endl << endl;
                 /*CREANDO ARCHIVO PARA REGISTRO DE GANADORES*/
                ofstream archivo("registroganadores.txt", ios::app);

                if (archivo.is_open()) {
                    if (verificarEmpate(mat)) {
                        archivo << "Partida #" << (contadorPartidasGanadas++) << ":" << endl;
                        archivo << "Empate entre " << arrjug[0] << " y " << arrjug[1] << endl;
                        archivo << endl;
                    } else {
                        if (tableroCompleto(mat[0])) {
                            archivo << "Partida #" << (contadorPartidasGanadas++) << ":" << endl;
                            archivo << "Ganador: " << arrjug[0] << endl;
                            archivo << endl;
                        } else if (tableroCompleto(mat[1])) {
                            archivo << "Partida #" << (contadorPartidasGanadas++) << ":" << endl;
                            archivo << "Ganador: " << arrjug[1] << endl;
                            archivo << endl;
                        }
                    }
                    cout << "Registro de ganador guardado en 'registroganadores.txt'" << endl << endl;
                    archivo.close();
                } else {
                    cout << "No se pudo abrir el archivo para guardar el registro de ganadores." << endl;
                }
                /*LEYENDO ARCHIVO DE REGISTRO DE GANADORES*/
                ifstream archivoLectura("registroganadores.txt");

                if (archivoLectura.is_open()) {
                    string linea;
                    while (getline(archivoLectura, linea)) {
                        cout << linea << endl;
                    }
                    archivoLectura.close();
                } else {
                    cout << "No se pudo abrir el archivo 'registroganadores.txt'" << endl;
                }

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
void nuevaPartida(string arrjug[2], int mat[2][3][3]) 
{
    int numAl, opcion; /*VARIABLES "NUMAL" PARA NUMEROS ALEATORIOS, "OPCION" PARA MOSTRAR AYUDA O CONTINUAR PARTIDA*/
    int numerosDichos[20] = {0}; /*ARREGLO DE NUMEROS YA DICHOS POR EL BOT*/
    int contadorNumerosDichos = 0; /*CONTADOR DE NUMEROS YA DICHOS INICIALIZADO EN CERO*/

    /*CASE DE NUEVA PARTIDA*/
    cout << endl << endl << "HAZ INICIADO UNA NUEVA PARTIDA!" << endl << endl;

    /*INGRESAR NOMBRE DE JUGADORES*/            
    for (int i = 0; i < 2; i++) {
        cout << "Ingrese el nombre del jugador " << (i + 1) << " : ";
        cin >> arrjug[i];
    }

    /*LISTA DE NOMBRES DE JUGADORES*/
    cout << endl << "Los nombres de los jugadores son: " << endl;
    for (int i = 0; i < 2; i++) {
        cout << "Jugador " << (i + 1) << " : " << arrjug[i] << endl;
    }

    cout << endl << endl;

    cout << endl << "TABLEROS DE JUGADORES" << endl << endl;
    /*GENERAR Y MOSTRAR LOS TABLEROS PARA CADA JUGADOR*/
    for (int k = 0; k < 2; k++) {
        cout << "Tablero del jugador " << arrjug[k] << " : " << endl << endl;

        /*LLAMA A LA FUNCION GENERAR TABLERO*/
        generarTablero(mat[k]);

        /*LLAMA A LA FUNCION MOSTRAR TABLERO DE CADA JUGADOR*/
        mostrarTablero(mat[k]);

    }

    /*PAUSA Y PRESIONAR ENTER PARA QUE EL BOT COMIENCE A GENERAR NUMEROS*/
    cout << "Presione Enter para que el bot genere el primer numero..." << endl;
    cin.ignore(); 
    cin.get();

    cout << endl << "LA PARTIDA HA COMENZADO!" << endl;

    /*BUCLE MIENTRAS EL JUEGO NO ESTE TERMINADO*/
    bool juegoTerminado = false;
    while(!juegoTerminado) {

        /*BOT GENERA NUMEROS ALEATORIOS DIFERENTES LLAMANDO A LA FUNCION YA DICHO*/
        do {
            numAl = 1 + rand() % 20;
        } while (yaDicho(numAl, numerosDichos, contadorNumerosDichos));

        cout << endl << endl << "Numero generado por el bot: " << numAl << endl << endl;

        numerosDichos[contadorNumerosDichos++] = numAl;

        /*LLAMA A LA FUNCION MARCAR NUMERO*/
        for (int k = 0; k < 2; k++) {
            marcarNumero(numAl, mat[k]);
        }

        /*LLAMA A LA FUNCION TABLERO ACTUALIZADO*/
        for (int k = 0; k < 2; k++) {
            cout << "Tablero del jugador " << arrjug[k] << " : " << endl << endl;
            tableroActualizado(mat[k]);
        }

        /*PAUSA ENTRE GENERACIONES DE NUMEROS*/
        sleep(1);

        /*DO WHILE QUE MUESTRA OPCION DE AYUDA O CONTINUAR CON LA PARTIDA DESPUES DE MOSTRAR LOS TABLEROS ACTUALIZADOS*/
        do {
            if (!juegoTerminado) {
                cout << "1. Mostrar la ayuda" << endl;
                cout << "2. Continuar con la partida" << endl;
                cin >> opcion;

                if (opcion == 1) {
                    cout << "AYUDA" << endl;
                    cout << "reglas" << endl;
                    /*ENTER PARA CONTINUAR CON LA PARTIDA LUEGO DE MOSTRAR LA AYUDA*/
                    cout << "Presione Enter para continuar con la partida..." << endl;
                    cin.ignore();
                    cin.get();
                } else if (opcion != 2) {
                    cout << "Opcion invalida. Por favor, seleccione 1 o 2" << endl;
                }
            }
        } while (opcion != 1 && opcion != 2);

        /*LLAMA A FUNCION VERIFICAR EMPATE*/
        if (verificarEmpate(mat)) {
            cout << endl << "EL JUEGO TERMINO EN EMPATE!" << endl;
            juegoTerminado = true;
            cout << endl << "LA PARTIDA HA TERMINADO..." << endl << endl;
        } else {
            /*LLAMA A FUNCION MOSTRAR GANADOR*/
            mostrarGanador(mat, arrjug, juegoTerminado);
        }

    }

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

/*FUNCION PARA GENERAR NUMEROS ALEATORIOS UNICOS PARA CADA TABLERO*/
void generarTablero(int mat[3][3])
{
    int numAl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            do {
                numAl = 1 + rand() % 20;
            } while (yaColocado(numAl, mat));
            mat[i][j] = numAl;
        }
    }
}

/*FUNCION PARA MOSTRAR EL TABLERO INICIAL DE CADA JUGADOR*/
void mostrarTablero(int mat[3][3])
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mat[i][j] << "  ";
        }
        cout << endl << endl;
    }
}

/*FUNCION PARA VERIFICAR SI UN NUMERO YA HA SIDO DICHO POR EL BOT*/
bool yaDicho(int num, int numerosDichos[], int contador)
{
    for (int i = 0; i < contador; i++) {
        if (numerosDichos[i] == num) {
            return true;
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

/*FUNCION PARA MOSTRAR TABLERO ACTUALIZADO DE CADA JUGADOR*/
void tableroActualizado(int mat[3][3])
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mat[i][j] << "  ";
        }
        cout << endl << endl;
    }
}

/*FUNCION PARA VERIFICAR SI EL TABLERO ESTA COMPLETAMENTE LLENO DE CEROS*/
bool tableroCompleto(int mat[3][3])
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mat[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

/*FUNCION PARA VERIFICAR EMPATE SI AMBOS TABLEROS ESTAN COMPLETAMENTE LLENOS DE CEROS*/
bool verificarEmpate(int mat[2][3][3])
{
    return tableroCompleto(mat[0]) && tableroCompleto(mat[1]);
}

/*FUNCION PARA MOSTRAR EL GANADOR SI SOLO UN JUGADOR TIENE SU TABLERO COMPLETO DE CEROS*/
void mostrarGanador(int mat[2][3][3], string arrjug[2], bool &juegoTerminado)
{
    if (tableroCompleto(mat[0])) {
        cout << endl << "EL JUGADOR " << arrjug[0] << " HA GANADO LA PARTIDA!" << endl;
        juegoTerminado = true;
        cout << endl << "LA PARTIDA HA TERMINADO..." << endl << endl;
    } else if (tableroCompleto(mat[1])) {
        cout << endl << "EL JUGADOR " << arrjug[1] << " HA GANADO LA PARTIDA!" << endl;
        juegoTerminado = true;
        cout << endl << "LA PARTIDA HA TERMINADO..." << endl << endl;
    }
}