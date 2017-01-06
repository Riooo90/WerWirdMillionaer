// V2.cpp : Defines the entry point for the console application.

#include "stdafx.h"

static int feld, ix, iy; //Positionen der Klicks

//int zustand = 0; //Zustand 0 ist der Startzustand

void bereiteSpielfeldVor() {
	// jetzt Schriftgroesse veraendern, gilt dann fuer alle neue Texte:
	char befehl[100];
	sprintf_s(befehl, 100, "fontsize %d \n", 18);
	sendMessage(befehl);
	//alle vorhandenen Texte und Farben loeschen
	loeschen();
	sprintf_s(befehl, 100, "clearAllText \n");
	sendMessage(befehl);

	// Test mit Bild (Bild-Datei wird relativ zum jserver-Verzeichnis gesucht)
	//form2(3, 4, "none");
	//symbolGroesse2(3, 4, 3.0);
	//sendMessage("image 3 4 wwm.png \n");

	groesse(50, 50);
	formen("s");
	frageHintergrund();
	zeichneAntwortenHintergrundA(BLUE);
	zeichneAntwortenHintergrundB(BLUE);
	zeichneAntwortenHintergrundC(BLUE);
	zeichneAntwortenHintergrundD(BLUE);

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
	int aktiveStufe = 0; //globale Variable für die Fragen zum auslesen	
	int spielende = 0;
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
				printf("%d", richtig(ix, iy, aktiveStufe));
				switch (richtig(ix, iy, aktiveStufe)) {
				case 1:
					aktiveStufe += 1;
					leseNaechsteFrage(ix, ix, aktiveStufe);
					break;
				case 0:// Null als Default 
					zeichneNeustartButton();
					Sleep(1000);
					spielende = 1;
					break;
				case 2:
					//Joker
					nutzeJoker5050();
				}
			}
		}
		else {
			if (spielende == 1) {
				printf("%s", "Spielende");
				aktiveStufe = 0;
				Sleep(1000);
				bereiteSpielfeldVor();
				
			}
			Sleep(100);
		}
	}
	getchar();
}
