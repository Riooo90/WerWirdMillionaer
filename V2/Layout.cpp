
/*grundlegende Variablen für Layout definieren:  */
#include "stdafx.h"
int startShowGeldliste = 95;
int i;
char* GeldStufen[15] = { "50 EURO", "100 EURO", "200 EURO", "300 EURO", "500 EURO", "1000 EURO", "2000 EURO", "4000 EURO", "8000 EURO", "16000 EURO", "32000 EURO", "64000 EURO", "125000 EURO", "500000 EURO", "1 MILLION" };

int aktiveStufe = 0;

//Geldliste zeichnen:
void zeichneFortschrittsanzeige(int aktiveStufe) {
	for (int i = 0; i < 15; i++) {
		text(startShowGeldliste + i * 2 * 50, GeldStufen[i]);
		if (i == aktiveStufe) {
			farbe(startShowGeldliste - 1 + i * 2 * 50, GREEN);
			farbe(startShowGeldliste + 1 + i * 2 * 50, GREEN);
			farbe(startShowGeldliste + i * 2 * 50, GREEN);
		}
	}	senkrechtBeides(90, 0, 30, BLUE, "s");
}

//Einlog Button

void einlogButton() {
	for (i = 67; i < 74; i++) {
		farbe(i, BLUE);
		//text(i; 'Einloggen');
	}
	for (i = 117; i < 124; i++) {
		farbe(i, BLUE);
	}
	for (i = 167; i < 174; i++) {
		farbe(i, BLUE);
	}
	for (i = 217; i < 224; i++) {
		farbe(i, BLUE);
	}

	text(170, "Einloggen");

	//Spitzen links und rechts
	for (i = 116; i < 117; i++) {
		farbe(i, BLUE);
		form(i, "tru");
		hintergrund(i, SILVER);
	}
	for (i = 166; i < 167; i++) {
		farbe(i, BLUE);
		form(i, "trd");
		hintergrund(i, SILVER);
	}
	for (i = 124; i < 125; i++) {
		farbe(i, BLUE);
		form(i, "tlu");
		hintergrund(i, SILVER);
	}
	for (i = 174; i < 175; i++) {
		farbe(i, BLUE);
		form(i, "tld");
		hintergrund(i, SILVER);
	}
}

/*Fragen Zeile*/

void frageHintergrund() {
	waagrechtFarbe(5, 48, 31, BLUE);
	waagrechtFarbe(5, 47, 31, BLUE);
	waagrechtFarbe(5, 46, 31, BLUE);
	waagrechtFarbe(5, 45, 31, BLUE);
	waagrechtBeides(4, 45, 1, BLUE, "trd");
	waagrechtBeides(36, 45, 1, BLUE, "tld");
	hintergrund(2254, SILVER);
	hintergrund(2204, SILVER);
	waagrechtFarbe(5, 44, 31, BLUE);
	waagrechtBeides(4, 44, 1, BLUE, "tru");
	waagrechtBeides(36, 44, 1, BLUE, "tlu");
	hintergrund(2236, SILVER);
	hintergrund(2286, SILVER);
	waagrechtFarbe(5, 43, 31, BLUE);
	waagrechtFarbe(5, 42, 31, BLUE);
	waagrechtFarbe(5, 41, 31, BLUE);
}


/*Antwort Zeilen*/
void antwortenHintergrundA(int farbe) {
	waagrechtFarbe(5, 35, 14, farbe);
	waagrechtFarbe(5, 34, 14, farbe);
	waagrechtFarbe(5, 33, 14, farbe);
	waagrechtBeides(4, 33, 1, farbe, "trd");
	hintergrund(1654, SILVER);
	text(1654, "a");
	waagrechtFarbe(5, 32, 14, farbe);
	waagrechtBeides(4, 32, 1, farbe, "tru");
	hintergrund(1604, SILVER);
	waagrechtFarbe(5, 31, 14, farbe);
	waagrechtFarbe(5, 30, 14, farbe);
}
void antwortenHintergrundB(int farbe) {
	waagrechtFarbe(22, 35, 14, farbe);
	waagrechtFarbe(22, 34, 14, farbe);
	waagrechtFarbe(22, 33, 14, farbe);
	waagrechtBeides(36, 33, 1, farbe, "tld");
	hintergrund(1686, SILVER);
	text(1686, "b");
	waagrechtFarbe(22, 32, 14, farbe);
	waagrechtBeides(36, 32, 1, farbe, "tlu");
	hintergrund(1636, SILVER);
	waagrechtFarbe(22, 31, 14, farbe);
	waagrechtFarbe(22, 30, 14, farbe);
}
void antwortenHintergrundC(int farbe) {
	waagrechtFarbe(5, 24, 14, farbe);
	waagrechtFarbe(5, 23, 14, farbe);
	waagrechtFarbe(5, 22, 14, farbe);
	waagrechtBeides(4, 22, 1, farbe, "trd");
	hintergrund(1104, SILVER);
	text(1104, "c");
	waagrechtFarbe(5, 21, 14, farbe);
	waagrechtBeides(4, 21, 1, farbe, "tru");
	hintergrund(1054, SILVER);
	waagrechtFarbe(5, 20, 14, farbe);
	waagrechtFarbe(5, 19, 14, farbe);
}
void antwortenHintergrundD(int farbe) {
	waagrechtFarbe(22, 24, 14, farbe);
	waagrechtFarbe(22, 23, 14, farbe);
	waagrechtFarbe(22, 22, 14, farbe);
	waagrechtBeides(36, 22, 1, farbe, "tld");
	hintergrund(1136, SILVER);
	text(1136, "d");
	waagrechtFarbe(22, 21, 14, farbe);
	waagrechtBeides(36, 21, 1, farbe, "tlu");
	hintergrund(1086, SILVER);
	waagrechtFarbe(22, 20, 14, farbe);
	waagrechtFarbe(22, 19, 14, farbe);
}
