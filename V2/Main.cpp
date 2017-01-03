// V2.cpp : Defines the entry point for the console application.

#include "stdafx.h"

//Spielfeld Groesse
int a = 50, b = 50;
static int feld, ix, iy;

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
	bekommeKlickPosition();
	printf_s("# %i %i %i", feld, ix, iy);
	zeichneRechteck(5, 5, 10, 5, 123456, "s");
	zeichneFortschrittsanzeige(0);
	frageHintergrund();
	antwortenHintergrundA(123456);
	antwortenHintergrundB(555555);
	antwortenHintergrundC(555555);
	antwortenHintergrundD(555555);
	zeichneEinlogButton();
	zeichneJokerbereich();
	getchar();
}
