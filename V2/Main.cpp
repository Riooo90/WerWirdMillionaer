// V2.cpp : Defines the entry point for the console application.

#include "stdafx.h"

static int feld, ix, iy; //Positionen der Klicks
int aktiveStufe = 0; //globale Variable für die Fragen zum auslesen					 
int zustand = 0; //Zustand 0 ist der Startzustand

void bereiteSpielfeldVor() {
	// jetzt Schriftgroesse veraendern, gilt dann fuer alle neue Texte:
	char befehl[100];
	sprintf_s(befehl, 100, "fontsize %d \n", 18);
	sendMessage(befehl);
	//alle vorhandenen Texte und Farben loeschen
	loeschen();
	sprintf_s(befehl, 100, "clearAllText \n");
	sendMessage(befehl);
	groesse(50, 50);
	formen("s");
}

/**
ermittelt die Positon des geklickten Feldes und setzt in die globalen Variablen ix und iy die Positionen des aktuellen Feldes

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
}**/

void main()
{
	bereiteSpielfeldVor();

	//Zeichne das Spielfeld
	zeichneFortschrittsanzeige(aktiveStufe);
	zeichneJokerbereich();
	frageEinlesen(aktiveStufe);
	antwortenEinlesen(aktiveStufe);


	for (;;) {
		//hier bekommen wir unseren Klick, bis Abfrage > 0, also etwas geklickt wurde:
		char *a = abfragen();
		if (strlen(a) > 0) {
			printf("Nachricht: %s\n", a);
			if (a[0] == '#') {
				sscanf_s(a, "# %d %d %d", &feld, &ix, &iy);
				//printf_s("# %i %i", ix, iy);
				if (richtig(ix, iy, aktiveStufe) == 1) {
					zeichneWeiterButton();
					klickeWeiterButton(ix, ix, aktiveStufe);
					printf("%i", richtig(ix, iy, aktiveStufe));
					//frageEinlesen(aktiveStufe);
					//antwortenEinlesen(aktiveStufe);
				}
				else if (richtig(ix, iy, aktiveStufe) == 0) {
					zeichneNeustartButton();
				}
			}
		}
		else {
			Sleep(100);
		}
	}
	getchar();
}
