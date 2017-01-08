#include "stdafx.h"
/* grundlegende Variablen um das Layout zu definieren:  */
int i;
char* GeldStufen[15] = { "50 EURO", "100 EURO", "200 EURO", "300 EURO", "500 EURO", "1000 EURO", "2000 EURO", "4000 EURO", "8000 EURO", "16000 EURO", "32000 EURO", "64000 EURO", "125000 EURO", "500000 EURO", "1 MILLION" };
char* GeldStufenFrage[15] = { "50 EURO - Frage", "100 EURO - Frage", "200 EURO - Frage", "300 EURO - Frage", "500 EURO - Frage", "1000 EURO - Frage", "2000 EURO - Frage", "4000 EURO - Frage", "8000 EURO - Frage", "16000 EURO - Frage", "32000 EURO - Frage", "64000 EURO - Frage", "125000 EURO - Frage", "500000 EURO - Frage", "1 MILLIONEN EURO - Frage" };

void resetAntwortenButtons() {
	zeichneAntwortenHintergrundA(DEEPSKYBLUE);
	zeichneAntwortenHintergrundB(DEEPSKYBLUE);
	zeichneAntwortenHintergrundC(DEEPSKYBLUE);
	zeichneAntwortenHintergrundD(DEEPSKYBLUE);
}

//Fortschrittsanzeige:
void zeichneFortschrittsanzeige(int aktiveStufe) {
	for (int i = 0; i < 15; i++) {
		text2(45, 1 + i * 2, GeldStufen[i]);
		if (i == aktiveStufe - 1) {
			waagrechtBeides(43, 1 + i * 2, 5, YELLOW, "s");
		}
		if (i == 4 || i == 9) {
			form2(42, 1 + i * 2, "*");
			farbe2(42, 1 + i * 2, DEEPSKYBLUE);
			hintergrund2(42, 1 + i * 2, SILVER);
			form2(48, 1 + i * 2, "*");
			farbe2(48, 1 + i * 2, DEEPSKYBLUE);
			hintergrund2(48, 1 + i * 2, SILVER);
		}
	}
	senkrechtBeides(40, 0, 50, DEEPSKYBLUE, "s");
}

void zeichneSpitzen(int pos, char* formS, int farbeS) {
	farbe(pos, farbeS);
	form(pos, formS);
	hintergrund(pos, farbeS);
}

//Joker-Bereich:
void zeichneJokerbereich() {
	form(1893, "c");
	form(1993, "c");
	form(2093, "c");
	farbe(1893, DEEPSKYBLUE);
	farbe(1993, DEEPSKYBLUE);
	farbe(2093, DEEPSKYBLUE);
	hintergrund(1893, SILVER);
	hintergrund(1993, SILVER);
	hintergrund(2093, SILVER);
	text(1896, "50:50-Joker");
	text(1996, "Telefon-Joker");
	text(2096, "Publikums-Joker");

	waagrechtBeides(91, 33, 9, DEEPSKYBLUE, "s");
}

//Super, die naechste Frage kommt
void zeichneNachsteFrageKommtButton() {
	
	waagrechtForm(7, 1, 27, "s");
	waagrechtFarbe(7, 1, 27, DEEPSKYBLUE);
	waagrechtForm(7, 2, 27, "s");
	waagrechtFarbe(7, 2, 27, DEEPSKYBLUE);
	waagrechtForm(7, 3, 27, "s");
	waagrechtFarbe(7, 3, 27, DEEPSKYBLUE);
	waagrechtForm(7, 4, 27, "s");
	waagrechtFarbe(7, 4, 27, DEEPSKYBLUE);

	//Spitzen links und rechts
	zeichneSpitzen(106, "s", DEEPSKYBLUE);
	zeichneSpitzen(156, "s", DEEPSKYBLUE);
	zeichneSpitzen(134, "s", DEEPSKYBLUE);
	zeichneSpitzen(184, "s", DEEPSKYBLUE);
}

void setzeNaechsteFrageKommtText() {
	text(170, "Super gemacht! Die naechste Frage kommt!");
}

//Reset nachsteFrageKommtButton
void resetNachsteFrageKommtButton() {

	waagrechtForm(7, 1, 27, "s");
	waagrechtFarbe(7, 1, 27, SILVER);

	waagrechtForm(7, 2, 27, "s");
	waagrechtFarbe(7, 2, 27, SILVER);

	waagrechtForm(7, 3, 27, "s");
	waagrechtFarbe(7, 3, 27, SILVER);

	waagrechtForm(7, 4, 27, "s");
	waagrechtFarbe(7, 4, 27, SILVER);

	//Spitzen links und rechts
	zeichneSpitzen(106, "s", SILVER);
	zeichneSpitzen(156, "s", SILVER);
	zeichneSpitzen(134, "s", SILVER);
	zeichneSpitzen(184, "s", SILVER);

	text(170, "");
}

/*Neustart Button*/
void zeichneNeustartButton(int aktiveStufe) {

	zeichneRechteck(14, 1, 13, 4, DEEPSKYBLUE, "s");
	text(170, "Das Spiel wird neu gestartet");

	//Spitzen links und rechts
	zeichneSpitzen(113, "s", DEEPSKYBLUE);
	zeichneSpitzen(163, "s", DEEPSKYBLUE);
	zeichneSpitzen(127, "s", DEEPSKYBLUE);
	zeichneSpitzen(177, "s", DEEPSKYBLUE);

	//Block für Geldbetrag:
	zeichneRechteck(14, 8, 13, 4, LIMEGREEN, "s");

	if (aktiveStufe < 4) {
		text(470, "Du hast 0 Euro gewonnen");
	}
	else if (aktiveStufe < 9) {
		text(170, "Du hast 500 Euro gewonnen");
	}
	else if (aktiveStufe < 14) {
		text(470, "Du hast 16000 Euro gewonnen");
	}
	else {
		text(470, "Du hast 1 Mio Euro gewonnen");
	}
}

void zeichneAbbruchButton() {
	zeichneRechteck(14, 8, 13, 4, BLUE, "s");
	form(570, "c");
	farbe(570, DEEPSKYBLUE);
	hintergrund(570, BLUE);
	text(470, "Aussteigen");
}

void gebeAbbruchSummeAus(int aktiveStufe) {
	form(570, "s");
	farbe(570, LIMEGREEN);
	text(470, "");
	text(467, "Gewinnsumme:");
	if (aktiveStufe > 0) {
		text(472, GeldStufen[aktiveStufe - 1]);
	}
	else {
		text(472, "0 EURO");
	}
}

/*Fragen Zeile*/
void frageHintergrund() {
	zeichneSpitzen(2254, "s", DEEPSKYBLUE);
	zeichneSpitzen(2204, "s", DEEPSKYBLUE);
	zeichneSpitzen(2236, "s", DEEPSKYBLUE);
	zeichneSpitzen(2286, "s", DEEPSKYBLUE);
	zeichneRechteck(5, 41, 31, 8, DEEPSKYBLUE, "s");
}

void frageText(char* frage, int aktiveStufe) {
	text2(20, 45, frage);
	text2(20, 42, GeldStufenFrage[aktiveStufe]);
}

/*Antwort Zeilen, farbe als Parameter, da die Farbe variabel ist*/
void zeichneAntwortenHintergrundA(int farbe) {
	zeichneRechteck(5, 30, 14, 6, farbe, "s");
	zeichneSpitzen(1604, "s", farbe);
	zeichneSpitzen(1654, "s", farbe);
	zeichneSpitzen(1669, "s", farbe);
	zeichneSpitzen(1619, "s", farbe);
	text(1654, "A");
}

void setzeAntworttextA(char* antwort) {
	text2(11, 32, antwort);
}

void zeichneAntwortenHintergrundB(int farbe) {
	zeichneRechteck(22, 30, 14, 6, farbe, "s");
	zeichneSpitzen(1621, "s", farbe);
	zeichneSpitzen(1671, "s", farbe);
	zeichneSpitzen(1686, "s", farbe);
	zeichneSpitzen(1636, "s", farbe);
	text(1686, "B");
}

void setzeAntworttextB(char* antwort) {
	text2(29, 32, antwort);
}

void zeichneAntwortenHintergrundC(int farbe) {
	zeichneRechteck(5, 19, 14, 6, farbe, "s");
	zeichneSpitzen(1054, "s", farbe);
	zeichneSpitzen(1104, "s", farbe);
	zeichneSpitzen(1069, "s", farbe);
	zeichneSpitzen(1119, "s", farbe);
	text(1104, "C");
}

void setzeAntworttextC(char* antwort) {
	text2(11, 21, antwort);
}

void zeichneAntwortenHintergrundD(int farbe) {
	zeichneRechteck(22, 19, 14, 6, farbe, "s");
	zeichneSpitzen(1071, "s", farbe);
	zeichneSpitzen(1121, "s", farbe);
	zeichneSpitzen(1086, "s", farbe);
	zeichneSpitzen(1136, "s", farbe);
	text(1136, "D");
}

void setzeAntworttextD(char* antwort) {
	text2(29, 21, antwort);
}
