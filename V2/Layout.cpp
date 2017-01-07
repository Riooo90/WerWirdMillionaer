#include "stdafx.h"
/* grundlegende Variablen für Layout definieren:  */
int startShowGeldliste = 95;
int i;
char* GeldStufen[15] = { "50 EURO", "100 EURO", "200 EURO", "300 EURO", "500 EURO", "1000 EURO", "2000 EURO", "4000 EURO", "8000 EURO", "16000 EURO", "32000 EURO", "64000 EURO", "125000 EURO", "500000 EURO", "1 MILLION" };


void resetAntwortenButtons() {
	zeichneAntwortenHintergrundA(BLUE);
	zeichneAntwortenHintergrundB(BLUE);
	zeichneAntwortenHintergrundC(BLUE);
	zeichneAntwortenHintergrundD(BLUE);
}

//Fortschrittsanzeige:
void zeichneFortschrittsanzeige(int aktiveStufe) {
	for (int i = 0; i < 15; i++) {
		text2(45, 1 + i * 2, GeldStufen[i]);
		if (i == aktiveStufe-1) {
			waagrechtFarbe(43, 1 + i * 2, 5, YELLOW);
			/*if (aktiveStufe == 4 || aktiveStufe == 9) {
				farbe2(42, 1 + i * 2, GREEN);
			}*/
		}
		if (i == 4 || i == 9) {
			form2(42, 1 + i * 2, "*");
			farbe2(42, 1 + i * 2, BLUE);
			hintergrund2(42, 1 + i * 2, SILVER);
			form2(48, 1 + i * 2, "*");
			farbe2(48, 1 + i * 2, BLUE);
			hintergrund2(48, 1 + i * 2, SILVER);
		}
	}
	senkrechtBeides(40, 0, 50, BLUE, "s");
}

//Joker-Bereich:
void zeichneJokerbereich() {
	form(1893, "c");
	form(1993, "c");
	form(2093, "c");
	farbe(1893, BLUE);
	farbe(1993, BLUE);
	farbe(2093, BLUE);
	hintergrund(1893, SILVER);
	hintergrund(1993, SILVER);
	hintergrund(2093, SILVER);
	text(1896, "50:50-Joker");
	text(1996, "Telefon-Joker");
	text(2096, "Publikums-Joker");

	waagrechtBeides(91, 33, 9, BLUE, "s");
}

//Super, die naechste Frage kommt
void zeichneNachsteFrageKommtButton() {

	for (i = 57; i < 84; i++) {
		farbe(i, BLUE);
	}
	for (i = 107; i < 134; i++) {
		farbe(i, BLUE);
	}
	for (i = 157; i < 184; i++) {
		farbe(i, BLUE);
	}
	for (i = 207; i < 234; i++) {
		farbe(i, BLUE);
	}

	//Spitzen links und rechts
	farbe(106, BLUE);
	form(106, "tru");
	hintergrund(106, SILVER);

	farbe(156, BLUE);
	form(156, "trd");
	hintergrund(156, SILVER);

	farbe(134, BLUE);
	form(134, "tlu");
	hintergrund(134, SILVER);

	farbe(184, BLUE);
	form(184, "tld");
	hintergrund(184, SILVER);

}

void setzeNaechsteFrageKommtText() {
	text(170, "Super gemacht! Die naechste Frage kommt!");
}

//Reset nachsteFrageKommtButton
void resetNachsteFrageKommtButton() {

	for (i = 57; i < 84; i++) {
		farbe(i, SILVER);
	}
	for (i = 107; i < 134; i++) {
		farbe(i, SILVER);
	}
	for (i = 157; i < 184; i++) {
		farbe(i, SILVER);
	}
	for (i = 207; i < 234; i++) {
		farbe(i, SILVER);
	}

	//Spitzen links und rechts
	farbe(106, SILVER);
	form(106, "tru");
	hintergrund(106, SILVER);

	farbe(156, SILVER);
	form(156, "trd");
	hintergrund(156, SILVER);

	farbe(134, SILVER);
	form(134, "tlu");
	hintergrund(134, SILVER);

	farbe(184, SILVER);
	form(184, "tld");
	hintergrund(184, SILVER);

	text(170, "");
}

/*Neustart Button*/
void zeichneNeustartButton(int aktiveStufe) {
	printf("%s", "zeichne Neustart");
	for (i = 65; i < 76; i++) {
		farbe(i, BLUE);
	}
	for (i = 115; i < 126; i++) {
		farbe(i, BLUE);
	}
	for (i = 165; i < 176; i++) {
		farbe(i, BLUE);
	}
	for (i = 215; i < 226; i++) {
		farbe(i, BLUE);
	}

	text(170, "Das Spiel wird neu gestartet");

	//Spitzen links und rechts
		farbe(114, BLUE);
		form(114, "tru");
		hintergrund(114, SILVER);
	
		farbe(164, BLUE);
		form(164, "trd");
		hintergrund(164, SILVER);
	
		farbe(126, BLUE);
		form(126, "tlu");
		hintergrund(126, SILVER);

		farbe(176, BLUE);
		form(176, "tld");
		hintergrund(176, SILVER);
	

	if (aktiveStufe < 4) {
		for (i = 415; i < 426; i++) {
			farbe(i, GREEN);
		}
		for (i = 465; i < 476; i++) {
			farbe(i, GREEN);
		}
		for (i = 515; i < 526; i++) {
			farbe(i, GREEN);
		}
		for (i = 565; i < 576; i++) {
			farbe(i, GREEN);
		}
		text(470, "Du hast 0 Euro gewonnen");
	}
	else if (aktiveStufe < 9) {
		for (i = 415; i < 426; i++) {
			farbe(i, GREEN);
		}
		for (i = 465; i < 476; i++) {
			farbe(i, GREEN);
		}
		for (i = 515; i < 526; i++) {
			farbe(i, GREEN);
		}
		for (i = 565; i < 576; i++) {
			farbe(i, GREEN);
		}
		text(170, "Du hast 500 Euro gewonnen");
	}

	else if (aktiveStufe < 15) {
		for (i = 415; i < 426; i++) {
			farbe(i, GREEN);
		}
		for (i = 465; i < 476; i++) {
			farbe(i, GREEN);
		}
		for (i = 515; i < 526; i++) {
			farbe(i, GREEN);
		}
		for (i = 565; i < 576; i++) {
			farbe(i, GREEN);
		}
		text(470, "Du hast 16000 Euro gewonnen");
	}
	else {
		for (i = 415; i < 426; i++) {
			farbe(i, GREEN);
		}
		for (i = 465; i < 476; i++) {
			farbe(i, GREEN);
		}
		for (i = 515; i < 526; i++) {
			farbe(i, GREEN);
		}
		for (i = 565; i < 576; i++) {
			farbe(i, GREEN);
		}
		text(470, "Du hast 1 Mio Euro gewonnen");
	}
}


/*Fragen Zeile*/
void frageHintergrund() {
	/*waagrechtFarbe(5, 48, 31, BLUE);
	waagrechtFarbe(5, 47, 31, BLUE);
	waagrechtFarbe(5, 46, 31, BLUE);
	waagrechtFarbe(5, 45, 31, BLUE);
	waagrechtFarbe(5, 44, 31, BLUE);*/
	waagrechtBeides(4, 45, 1, BLUE, "trd");
	waagrechtBeides(36, 45, 1, BLUE, "tld");
	hintergrund(2254, SILVER);
	hintergrund(2204, SILVER);

	waagrechtBeides(4, 44, 1, BLUE, "tru");
	waagrechtBeides(36, 44, 1, BLUE, "tlu");
	hintergrund(2236, SILVER);
	hintergrund(2286, SILVER);
	/*waagrechtFarbe(5, 43, 31, BLUE);
	waagrechtFarbe(5, 42, 31, BLUE);
	waagrechtFarbe(5, 41, 31, BLUE);*/

	zeichneRechteck(5, 41, 31, 8, BLUE, "s");
}

void frageText(char* frage) {
	text2(20, 45, frage);
}

/*Antwort Zeilen, farbe Param, da Farbe variabel*/
void zeichneAntwortenHintergrundA(int farbe) {
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

void setzeAntworttextA(char* antwort) {
	text2(11, 32, antwort);
}

void zeichneAntwortenHintergrundB(int farbe) {
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

void setzeAntworttextB(char* antwort) {
	text2(29, 32, antwort);
}

void zeichneAntwortenHintergrundC(int farbe) {
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

void setzeAntworttextC(char* antwort) {
	text2(11, 21, antwort);
}

void zeichneAntwortenHintergrundD(int farbe) {
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

void setzeAntworttextD(char* antwort) {
	text2(29, 21, antwort);
}
