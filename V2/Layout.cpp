/*grundlegende Variablen für Layout definieren:  */
#include "stdafx.h"
int startShowGeldliste = 55;
int aktiveStufe = 0;
int i;
char* GeldStufen[15] = { "50 EURO", "100 EURO", "200 EURO", "300 EURO", "500 EURO", "1000 EURO", "2000 EURO", "4000 EURO", "8000 EURO", "16000 EURO", "32000 EURO", "64000 EURO", "125000 EURO", "500000 EURO", "1 MILLION" };


//Geldliste zeichnen:
void zeichneFortschrittsanzeige(int aktiveStufe) {
	for (int i = 0; i < 15; i++) {
		text(startShowGeldliste + i * 2 * 30, GeldStufen[i]);
		if (i == aktiveStufe) {
			farbe(startShowGeldliste - 1 + i * 2 * 30, GREEN);
			farbe(startShowGeldliste + 1 + i * 2 * 30, GREEN);
			farbe(startShowGeldliste + i * 2 * 30, GREEN);
		}
	}	senkrechtBeides(20, 0, 30, BLUE, "s");
}

//Einlog Button

void einlogButton() {
	for (i = 2; i<9; i++) {
		farbe(i, BLUE);
	}
	for (i = 21; i<29; i++) {
		farbe(i, BLUE);
		//text(i; 'Einloggen');
	}
	for (i = 41; i<49; i++) {
		farbe(i, BLUE);
	}

}

