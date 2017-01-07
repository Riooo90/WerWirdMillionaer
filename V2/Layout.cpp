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

void mittelButtonHintergrund() {
	waagrechtBeides(14, 8, 13, BLUE, "s");
	waagrechtBeides(14, 9, 13, BLUE, "s");
	waagrechtBeides(14, 10, 13, BLUE, "s");
	waagrechtBeides(14, 11, 13, BLUE, "s");
}
/*Neustart Button*/
void zeichneNeustartButton(int aktiveStufe) {
	mittelButtonHintergrund();
	text(170, "Das Spiel wird neu gestartet");

	//Spitzen links und rechts
	zeichneSpitzen(113, "s", DEEPSKYBLUE);
	zeichneSpitzen(163, "s", DEEPSKYBLUE);
	zeichneSpitzen(126, "s", DEEPSKYBLUE);
	zeichneSpitzen(176, "s", DEEPSKYBLUE);

	//Block f�r Geldbetrag:
	for (i = 414; i < 427; i++) {
		farbe(i, LIMEGREEN);
	}
	for (i = 464; i < 477; i++) {
		farbe(i, LIMEGREEN);
	}
	for (i = 514; i < 527; i++) {
		farbe(i, LIMEGREEN);
	}
	for (i = 564; i < 577; i++) {
		farbe(i, LIMEGREEN);
	}
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
	mittelButtonHintergrund();
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
	waagrechtBeides(4, 45, 1, DEEPSKYBLUE, "s");
	waagrechtBeides(36, 45, 1, DEEPSKYBLUE, "s");
	hintergrund(2254, DEEPSKYBLUE);
	hintergrund(2204, DEEPSKYBLUE);

	waagrechtBeides(4, 44, 1, DEEPSKYBLUE, "s");
	waagrechtBeides(36, 44, 1, DEEPSKYBLUE, "s");
	hintergrund(2236, DEEPSKYBLUE);
	hintergrund(2286, DEEPSKYBLUE);
	zeichneRechteck(5, 41, 31, 8, DEEPSKYBLUE, "s");
}

void frageText(char* frage, int aktiveStufe) {
	text2(20, 45, frage);
	text2(20, 42, GeldStufenFrage[aktiveStufe]);
}

/*Antwort Zeilen, farbe als Parameter, da die Farbe variabel ist*/
void zeichneAntwortenHintergrundA(int farbe) {
	waagrechtBeides(5, 35, 14, farbe, "s");
	waagrechtBeides(5, 34, 14, farbe, "s");
	waagrechtBeides(5, 33, 14, farbe, "s");
	waagrechtBeides(4, 33, 1, farbe, "s");
	hintergrund(1654, farbe);
	waagrechtBeides(19, 32, 1, farbe, "s");
	hintergrund2(19, 32, farbe);
	text(1654, "a");
	waagrechtBeides(5, 32, 14, farbe, "s");
	waagrechtBeides(4, 32, 1, farbe, "s");
	hintergrund(1604, farbe);
	waagrechtBeides(19, 33, 1, farbe, "s");
	hintergrund2(19, 33, farbe);
	waagrechtBeides(5, 31, 14, farbe, "s");
	waagrechtBeides(5, 30, 14, farbe, "s");

}

void setzeAntworttextA(char* antwort) {
	text2(11, 32, antwort);
}

void zeichneAntwortenHintergrundB(int farbe) {
	waagrechtBeides(22, 35, 14, farbe, "s");
	waagrechtBeides(22, 34, 14, farbe, "s");
	waagrechtBeides(22, 33, 14, farbe, "s");
	waagrechtBeides(36, 33, 1, farbe, "s");
	hintergrund(1686, farbe);
	waagrechtBeides(21, 32, 1, farbe, "s");
	hintergrund2(21, 32, farbe);
	text(1686, "b");
	waagrechtBeides(22, 32, 14, farbe, "s");
	waagrechtBeides(36, 32, 1, farbe, "s");
	hintergrund(1636, farbe);
	waagrechtBeides(21, 33, 1, farbe, "s");
	hintergrund2(21, 33, farbe);
	waagrechtBeides(22, 31, 14, farbe, "s");
	waagrechtBeides(22, 30, 14, farbe, "s");
}

void setzeAntworttextB(char* antwort) {
	text2(29, 32, antwort);
}

void zeichneAntwortenHintergrundC(int farbe) {
	waagrechtBeides(5, 24, 14, farbe, "s");
	waagrechtBeides(5, 23, 14, farbe, "s");
	waagrechtBeides(5, 22, 14, farbe, "s");
	waagrechtBeides(4, 22, 1, farbe, "s");
	hintergrund(1104, farbe);
	waagrechtBeides(19, 21, 1, farbe, "s");
	hintergrund2(19, 21, farbe);
	text(1104, "c");
	waagrechtBeides(5, 21, 14, farbe, "s");
	waagrechtBeides(4, 21, 1, farbe, "s");
	hintergrund(1054, farbe);
	waagrechtBeides(19, 22, 1, farbe, "s");
	hintergrund2(19, 22, farbe);
	waagrechtBeides(5, 20, 14, farbe, "s");
	waagrechtBeides(5, 19, 14, farbe, "s");
}

void setzeAntworttextC(char* antwort) {
	text2(11, 21, antwort);
}

void zeichneAntwortenHintergrundD(int farbe) {
	waagrechtBeides(22, 24, 14, farbe, "s");
	waagrechtBeides(22, 23, 14, farbe, "s");
	waagrechtBeides(22, 22, 14, farbe, "s");
	waagrechtBeides(36, 22, 1, farbe, "s");
	hintergrund(1136, farbe);
	waagrechtBeides(21, 21, 1, farbe, "s");
	hintergrund2(21, 21, farbe);
	text(1136, "d");
	waagrechtBeides(22, 21, 14, farbe, "s");
	waagrechtBeides(36, 21, 1, farbe, "s");
	hintergrund(1086, farbe);
	waagrechtBeides(21, 22, 1, farbe, "s");
	hintergrund2(21, 22, farbe);
	waagrechtBeides(22, 20, 14, farbe, "s");
	waagrechtBeides(22, 19, 14, farbe, "s");
}

void setzeAntworttextD(char* antwort) {
	text2(29, 21, antwort);
}
