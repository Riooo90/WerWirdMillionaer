// V2.cpp : Defines the entry point for the console application.

#include "stdafx.h"

static int feld, ix, iy; //Positionen der Klicks

void bereiteSpielfeldVor(int aktiveStufe) {
	// jetzt Schriftgroesse veraendern, gilt dann fuer alle neue Texte:
	char befehl[100];
	sprintf_s(befehl, 100, "fontsize %d \n", 18);
	sendMessage(befehl);
	//alle vorhandenen Texte und Farben loeschen
	loeschen();
	flaeche(SILVER);
	formen("none");
	sprintf_s(befehl, 100, "clearAllText \n");
	sendMessage(befehl);

	// Test mit Bild (Bild-Datei wird relativ zum jserver-Verzeichnis gesucht)
	// Anmerkung: Bilddatei wird in der Live-Demo gezeigt, um Probleme zu verhindern wird es hier nur als Text eingeblendet.
	text2(45, 46, "Wer wird Millionaer");
	// form2(45, 46, "none");
	// symbolGroesse2(45, 46, 3.0);
	// sendMessage("image 45 46 wwm.png \n");

	groesse(50, 50);
	frageHintergrund();
	resetAntwortenButtons();
	zeichneFortschrittsanzeige(aktiveStufe);
	zeichneJokerbereich();
	frageEinlesen(aktiveStufe);
	antwortenEinlesen(aktiveStufe);
	resetJoker();
	zeichneAbbruchButton();
}

void main()
{
	int aktiveStufe = 0; //globale Variable für die Fragen zum Auslesen	
	bereiteSpielfeldVor(aktiveStufe);
	int spielende = 0;

	for (;;) {	
		char *a = abfragen(); //hier bekommen wir unseren Klick
		if (strlen(a) > 0) {
			if (a[0] == '#') {
				sscanf_s(a, "# %d %d %d", &feld, &ix, &iy);
				switch (pruefeKlickAktion(ix, iy, aktiveStufe)) {
				case 3:
					gebeAbbruchSummeAus(aktiveStufe);
					spielende = 1;
					Sleep(10000);
					break;
				case 1: //Frage richtig beantwortet
					aktiveStufe += 1;
					if (aktiveStufe < 15) {
						leseNaechsteFrage(ix, ix, aktiveStufe);
					}
					else {
						zeichneNeustartButton(aktiveStufe);
						spielende = 1;
						Sleep(10000);
					}
					break;
				case 0: //Frage falsch beantwortet
					zeichneNeustartButton(aktiveStufe);
					Sleep(1000);
					spielende = 1;
					break;
				}
			}
		}
		else {
			if (spielende == 1) {
				aktiveStufe = 0;
				Sleep(1000);
				bereiteSpielfeldVor(aktiveStufe);
				spielende = 0;
			}
			Sleep(100);
		}
	}
	getchar();
}