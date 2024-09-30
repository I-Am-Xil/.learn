/*
	Juego de naves en C++
*/

#include <stdio.h>
#include <windows.h>
/*Biblioteca de deteccion de teclas*/
#include <conio.h>
/*biblioteca para booleanos*/
#include <stdbool.h>
#include <stdlib.h>
#include <list>
using namespace std;

/*Definicion de teclas*/
#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80

void gotoxy(int x, int y)
{
	HANDLE hCon;

	/*Recuperar la funcion de la consola con un parametro*/
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	
	/*Estructura de datos*/
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;

	/*Funcion de 2 parametros
	1- Handle: nombre que le da el sistema a una ventana
	2- Estructura de datos de 2 variables 'X','Y'*/
	SetConsoleCursorPosition(hCon, dwPos);
}

void OcultarCursor()
{
	HANDLE hCon;

	/*Recuperar la funcion de la consola con un parametro*/
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	/*Estructura de datos*/
	CONSOLE_CURSOR_INFO cci;
	/*Controla tamaño del cursor*/
	cci.dwSize = 50;
	/*Controla visibilidad del cursor*/
	cci.bVisible = FALSE;


	SetConsoleCursorInfo(hCon,&cci);
}

void pintar_limites()
{
	for (int i = 2; i < 78; ++i)
	{
		gotoxy(i,3); printf("%c",205);
		gotoxy(i,32); printf("%c",205);

	}

	for (int i = 4; i < 32; ++i)
	{
		gotoxy(2,i); printf("%c",186);
		gotoxy(77,i); printf("%c",186);
	}
	gotoxy(2,3); printf("%c", 201);
	gotoxy(2,32); printf("%c", 200);
	gotoxy(77,3); printf("%c", 187);
	gotoxy(77,32); printf("%c", 188);
}

class NAVE
{
	int x,y;
	int corazones;
	int vidas;
public:
	/*Declaracion de parametros de la nave*/
	NAVE(int _x,int _y,int _corazones,int _vidas): x(_x),y(_y),corazones(_corazones),vidas(_vidas){}
	/*Puntos de acceso para consulta de datos privados*/
	int X(){return x;}
	int Y(){return y;}
	int VID(){return vidas;}
	void COR(){corazones--;}
	/*Funciones del objeto*/
	void pintar();
	void borrar();
	void mover();
	void pintar_corazones();
	void morir();
};

void NAVE::pintar()
{
	gotoxy(x,y); printf("  %c",219);
	gotoxy(x,y+1); printf(" %c%c%c\n",219,219,219);
	gotoxy(x,y+2); printf("%c%c %c%c\n",219,219,219,219);
}

void NAVE::borrar()
{
	gotoxy(x,y); printf("        ");
	gotoxy(x,y+1); printf("        ");
	gotoxy(x,y+2); printf("        ");
}

void NAVE::mover()
{
	if (kbhit())
	{
		char tecla = getch();
		borrar();
		if (tecla == IZQUIERDA && x > 3) x--;
		if (tecla == DERECHA && x+5 < 77) x++;
		if (tecla == ARRIBA && y > 4) y--;
		if (tecla == ABAJO && y+3 < 32) y++;
		if (tecla == 'e') corazones--;
		pintar();
		pintar_corazones();
	}
}

void NAVE::pintar_corazones()
{
	gotoxy(50,2); printf("VIDAS %d", vidas);
	gotoxy(64,2); printf("Salud");
	gotoxy(70,2); printf("     ");
	for (int i = 0; i < corazones; ++i)
	{
		gotoxy(70+i,2); printf("%c",3);
	}
}

void NAVE::morir()
{
	if (corazones == 0)
	{
		/*Animacion cutre*/
		borrar();
		gotoxy(x,y);   printf("   **   ");
		gotoxy(x,y+1); printf("  ****  ");
		gotoxy(x,y+2); printf("   **   ");
		Sleep(200);

		borrar();
		gotoxy(x,y);   printf(" * ** *");
		gotoxy(x,y+1); printf("  ****");
		gotoxy(x,y+2); printf(" * ** *");
		Sleep(200);

		borrar();

		vidas--;
		corazones = 3;
		pintar_corazones();
		pintar();
	}
}

class AST{
	int x,y;
public:
	/*Declaracion de parametros del asteroide*/
	AST(int _x,int _y):x(_x),y(_y){}
	/*Puntos de acceso para consulta de datos privados*/
	int X(){return x;}
	int Y(){return y;}
	/*Funciones del objeto*/
	void choque(NAVE &N);
	void pintar();
	void mover();
};

void AST::pintar()
{
	gotoxy(x,y); printf("%c",184);
}

void AST::mover()
{
	gotoxy(x,y); printf(" ");
	y++;
	if (y > 31)
	{
		x = rand()%71 + 4;
		y = 4;
	}
	pintar();
}

void AST::choque(NAVE &N)
{
	if (x >= N.X() && x < N.X()+6 && y >= N.Y() && y <= N.Y()+2)
	{
		N.COR();
		N.borrar();
		N.pintar();
		N.pintar_corazones();
		x = rand()%71 + 4;
		y = 4;
	}
}

class BALA
{
	int x,y;
public:
	/*Declaracion de parametros de la bala*/
	BALA(int _x, int _y): x(_x),y(_y){}
	/*Puntos de acceso para consulta de datos privados*/
	int X(){return x;}
	int Y(){return y;}
	/*Funciones del objeto*/
	void mover();
	bool fuera();
	
};

void BALA::mover()
{
	gotoxy(x,y); printf(" ");
	if (y > 4)
	{
		y--;
	}
	gotoxy(x,y); printf("|");
}

bool BALA::fuera()
{
	if (y == 4)
	{
		return true;
	}else{
		return false;
	}
}

int main()
{
	/*Llamado de funciones para caracteristicas del cursor*/
	OcultarCursor();
	pintar_limites();
	/*Parametros de la nave*/
	NAVE N(37,29,3,3);
	N.pintar();
	N.pintar_corazones();

	/*Lista de asteroides bajo asignacion dinamica*/
	list<AST*> A;
	list<AST*>::iterator itA;
	/*Generador de objetos a lista*/
	for (int i = 0; i < 5; ++i)
	{
		A.push_back(new AST(rand()%75+3, rand()%5+4));
	}

	/*Lista de balas bajo asignacion dinamica*/
	list<BALA*> B;
	list<BALA*>::iterator it;

	/*Indicadores de juego*/
	bool game_over = false;
	int puntos = 0;
	while(!game_over){

		gotoxy(4,2); printf("Puntos %d\n",puntos);

		if (kbhit())
		{
			/*Generador de objetos a lista*/
			if (GetAsyncKeyState(0x20))
			{
				B.push_back(new BALA(N.X()+2, N.Y()-1));
			}
			
		}

		/*Ciclo de movimiento y eliminacion de objeto bala de lista*/
		for (it = B.begin(); it != B.end(); it++)
		{
			(*it)->mover();
			if ((*it)->fuera())
			{
				gotoxy((*it)->X(), (*it)->Y()); printf(" ");
				delete(*it);
				it = B.erase(it);
			}
		}

		/*Ciclo de movimiento de asteroide y colisionador nave-asteroide*/
		for (itA = A.begin(); itA != A.end(); itA++)
		{
			(*itA)->mover();
			(*itA)->choque(N);
		}

		/*Ciclo de colision asteroide-bala*/
		for (itA = A.begin(); itA != A.end(); itA++)
		{
			for (it = B.begin(); it != B.end(); it++)
			{
				if ((*itA)->X() == (*it)->X() && ((*itA)->Y()+1 == (*it)->Y() || (*itA)->Y() == (*it)->Y()))
				{
					/*Eliminacion del objeto bala de lista*/
					gotoxy((*it)->X(),(*it)->Y()); printf(" ");
					delete(*it);
					it = B.erase(it);

					/*Generacion de asteroide de remplazo*/
					A.push_back(new AST(rand()%75+3,4));
					gotoxy((*itA)->X(),(*itA)->Y()); printf(" ");
					delete(*itA);
					itA = A.erase(itA);


					/*Marcador*/
					puntos+=5;
				}
			}
		}

		/*Finalizador del juego*/
		if (N.VID() == 0)
		{
			game_over = true;
		}
		/*Llamado de funciones del objeto NAVE*/
		N.morir();
		N.mover();
		/*Descanso del procesador && solucion a error con balas*/
		Sleep(30);

	}
	gotoxy(32,15); printf("Juego terminado.\n");
	gotoxy(34,17); printf("Presione F para salir\n");
	/*Mantiene abierta la ventana del programa*/
	system("PAUSE>nul");
		return 0;
}