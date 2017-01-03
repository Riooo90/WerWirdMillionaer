// V2.cpp : Defines the entry point for the console application.

#include "stdafx.h"

//Spielfeld Groesse
int a = 50, b = 50;
static int feld, ix, iy;

//globale Variable für die Fragen zum auslesen

int aktiveStufe = 0;

void loescheAlles() {
	loeschen();
	// jetzt Schriftgroesse veraendern, gilt dann fuer alle neue Texte
	char befehl[100];
	sprintf_s(befehl, 100, "fontsize %d \n", 18);
	sendMessage(befehl);
	sprintf_s(befehl, 100, "clearAllText \n");
	sendMessage(befehl);
}

/**
ermittelt die Positon des geklickten Feldes und setzt in die globalen Variablen ix und iy die Positionen des aktuellen Feldes
**/
void bekommeKlickPosition() {
	for (;;) {
		char *a = abfragen();
		if (strlen(a) > 0) {
			printf("Nachricht: %s\n", a);
			if (a[0] == '#') {
				sscanf_s(a, "# %d %d %d", &feld, &ix, &iy);
				//printf_s("# %i %i", ix, iy);
			}
		}
		else {
			Sleep(100);
		}
	}
}

void main()
{
	int position;
	loescheAlles();
	groesse(a, b);
	formen("s");
	/*bekommeKlickPosition();
	printf_s("# %i %i %i", feld, ix, iy);
	zeichneRechteck(5, 5, 10, 5, 123456, "s");*/

	//Zeichne das Spielfeld
	zeichneFortschrittsanzeige(0);
	zeichneJokerbereich();

	//Zustand 0 ist der Startzustand
	int zustand = 0;

	//hier bekommen wir unseren KLick, bis abfrage > 0, also etwas geklickt wurde

	frageEinlesen(aktiveStufe);
	antwortenEinlesen(aktiveStufe);
	for (;;) {
		char *a = abfragen();
		if (strlen(a) > 0) {
			printf("Nachricht: %s\n", a);
			if (a[0] == '#') {
				sscanf_s(a, "# %d %d %d", &feld, &ix, &iy);
				//printf_s("# %i %i", ix, iy);
				if (richtig(ix, iy, aktiveStufe) == 1) {
					zeichneWeiterButton();
					//frageEinlesen(aktiveStufe);
					//antwortenEinlesen(aktiveStufe);
				}
				else if (richtig(ix, iy, aktiveStufe) == 0) {
					zeichneNeustartButton();
				}
			}
		}
		else { Sleep(100); }
	}
	getchar();
}
