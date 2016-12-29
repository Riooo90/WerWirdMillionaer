// V2.cpp : Defines the entry point for the console application.

#include "stdafx.h"

//Test
//Hallo Reni

	/*grundlegende Variablen für Layout definieren: */
int startShowGeldliste = 55;
int aktiveStufe = 0;
char* GeldStufen[15] = { "50 EURO", "100 EURO", "200 EURO", "300 EURO", "500 EURO", "1000 EURO", "2000 EURO", "4000 EURO", "8000 EURO", "16000 EURO", "32000 EURO", "64000 EURO", "125000 EURO", "500000 EURO", "1 MILLION" };
int a = 30, b = 30;

//Geldliste zeichnen:
void zeichneFortschrittsanzeige(int aktiveStufe) {
	for (int i = 0; i < 15; i++) {
		text(startShowGeldliste + i * 2 * a, GeldStufen[i]);
		if (i == aktiveStufe) {
			farbe(startShowGeldliste-1 + i * 2 * a, GREEN);
			farbe(startShowGeldliste+1 + i * 2 * a, GREEN);
			farbe(startShowGeldliste + i * 2 * a, GREEN);
		}
	}	senkrechtBeides(20, 0, 30, BLUE, "s");
}

void main()
{
	loeschen();
	groesse(a, b);
	formen("s");
	zeichneFortschrittsanzeige(0);
	getchar();
	zeichneFortschrittsanzeige(3);
	getchar();
}
