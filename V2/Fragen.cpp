#include "stdafx.h"

int joker5050 = 1, jokerTel = 1, jokerPublikum = 1; //Verfügbarkeit der Joker: 1=vorhanden, 0 = benutzt

/* Positionen der richtigen Antworten: a = 4, 33 ; b = 36, 33; c = 4, 22; d = 36, 22
Es gehört immer ein zweier Paar zusammen */
int loesung[] = { 4, 22, 4, 33, 4, 22, 4, 22, 36, 33, 4, 22, 4, 22, 4, 22, 4, 33, 36, 33, 4, 33, 4, 33, 36, 22, 4, 22, 36, 33 };

//Loesung 0 = falsch, 1 = richtig, in der main wird ausgelesen was FKR zurück gibt

//15 Fragen für jede Stufe eine: Schrittweite 1
char *fragen[] = { "Wenn das Wetter gut ist, wird der Bauer bestimmt den Eber, das Ferkel und...?",
"Was ist meist ziemlich viel?",
"Wessen Genesung schnell voran schreitet der erholt sich...",
"Welche Neuerung hielt das Jahr 1984 fuer deutsche Fernsehzuschauer bereit?",
"Wer in Dover wohnt,",
"Johann Wolfgang von Goethes Autobiographie kennt man unter dem Titel...?",
"Was findet man bei Autos meist in den Varianten gleichlaufend oder gegenlaeufig?",
"Wessen Ansprueche sollen hierzulande gesetzlich neu geregelt werden?",
"Wobei besteht die oberste Schicht oft aus dem sogenannten Fondant?",
"Welcher Buchstabe kam in unserem Aplhabet erst im Mittelalter hinzu?",
"Welche Pflanzen zaehlen zur selben Familie und sehen sich zum Verwechseln aehnlich?",
"Womit machte sich der 2012 verstorbene Inder Ravi Shankar zur Legende?",
"Bei welchen beiden Staaten findet man im Laendernamen wie auch im Namen der Hauptstadt keinen anderen Vokal als das A?",
"Wer muss beim Urlaub im Schwarzwald grundsaetzlich die sogenannte Zwei-Meter-Regel beachten?",
"Welchen Eintrag findet man im Urduden von 1880 nicht?" };

//60 Antowerten für jede Stufe vier: Schrittweite 4
char *antworten[] = { "...einen draufmachen", "...die Nacht durchzechen", "...die Sau rauslassen", "...auf die Kacke hauen",
"stolze Summe", "selbstbewusste Differenz", "arroganter Quotient", "hochmuetiges Produkt",
"...hinguckends", "...anschauends", "...zusehends","...glotzends",
"Seilsendungen", "Leitungskanaele","Kabelprogramme", "Drahtshows",
"sussex Sussex.", "kennt Kent.","yorkshire Yorkshire.", "cornwall Cornwall.",
"Ablfuss und Tatsache", "Stoepsel und Wirklichkeit","Dichtung und Wahrheit", "Ventil und Realitaet" ,
"Rueckbank", "Tank","Scheibenwischer", "Schneeketten",
"Muenzmuetter", "Kreditkartenfamilien", "Scheinvaeter", "Bargeldeltern",
"Festtagstorte", "Kaltschaummatratze", "Strassenbelag", "Komposthaufen",
"C", "W", "V", "D",
"Lavendel und Rosmarin","Hibiskus und Krokus", "Eibe und Ulme", "Hortensie und Azalee",
"Sitar", "Yogakurse", "Currygerichte", "Kricketschlaeger",
"Katar und Tschad", "Japan und Madagaskar", "Kanada und Bahamas", "Ghana und Kasachstan",
"Nichtschwimmer", "Hundebesitzer", "Mountainbiker", "Wohnmobilfahrer",
"Dynamit", "Gluehlampe", "Batterie", "Mikrophon" };

/* liest die Frage fuer die aktuelle Stufe aus dem Frage-Array ein und schreibt sie in den Frage-Button */
void frageEinlesen(int aktiveStufe) {
	frageText(fragen[aktiveStufe], aktiveStufe);
	if (aktiveStufe != 0) {
		resetNachsteFrageKommtButton();
	}
}

/* liest die 4 Antworten fuer die aktuelle Stufe aus dem Antworten-Array ein und schreibt sie in die Buttons */
void antwortenEinlesen(int aktiveStufe) {
	setzeAntworttextA(antworten[(aktiveStufe * 4)]);
	setzeAntworttextB(antworten[(aktiveStufe * 4) + 1]);
	setzeAntworttextC(antworten[(aktiveStufe * 4) + 2]);
	setzeAntworttextD(antworten[(aktiveStufe * 4) + 3]);
}

/* Vergleicht die Texte aus den Klicks, an der Stelle aktiveStufe, ix und iy kommen vom Klick, aktiveStufe übergeben, die Fkt abhängig davon ist, nicht in der fkt als for drin!*/
int pruefeKlickAktion(int ix, int iy, int aktiveStufe) {
	if (ix == 20 && iy == 11) {
		return 3;
	}
	else {

		//BEGINN ----- Jokerbutton-Klicks abfragen:
		if (ix == 43 && iy == 37 && joker5050 == 1) { //50:50-JOKER
			int counter = 0;
			ix = loesung[aktiveStufe * 2];
			iy = loesung[(aktiveStufe * 2) + 1];

			if (ix == 4 && iy == 33) {
				setzeAntworttextB("");
				setzeAntworttextD("");
			}
			else if (ix == 36 && iy == 33) {
				setzeAntworttextA("");
				setzeAntworttextD("");
			}
			else if (ix == 4 && iy == 22) {
				setzeAntworttextA("");
				setzeAntworttextB("");
			}
			else if (ix == 36 && iy == 22) {
				setzeAntworttextA("");
				setzeAntworttextB("");
			}

			joker5050 = 0;
			farbe2(43, 37, CRIMSON);
		}
		else {
			if (ix == 43 && iy == 39 && jokerTel == 1) { //TELEFONJOKER
				ix = loesung[aktiveStufe * 2];
				iy = loesung[(aktiveStufe * 2) + 1];
				jokerTel = 0;
				farbe2(43, 39, CRIMSON);
			}
			else if (ix == 43 && iy == 41 && jokerPublikum == 1) { //PUBLIKUMSJOKER
				ix = loesung[aktiveStufe * 2];
				iy = loesung[(aktiveStufe * 2) + 1];
				jokerPublikum = 0;
				farbe2(43, 41, CRIMSON);
			}
			//ENDE ----- Jokerbutton-Klicks abfragen

			if (ix == loesung[aktiveStufe * 2] && iy == loesung[(aktiveStufe * 2) + 1]) {	//*2 weil ein Zweierpaar im Loesungsarray zusammen gehört
				if (ix == 4 && iy == 33) {
					zeichneAntwortenHintergrundA(LIMEGREEN);
					zeichneNachsteFrageKommtButton();
					setzeNaechsteFrageKommtText();
					return 1;
				}
				if (ix == 36 && iy == 33) {
					zeichneAntwortenHintergrundB(LIMEGREEN);
					zeichneNachsteFrageKommtButton();
					setzeNaechsteFrageKommtText();
					return 1;
				}
				if (ix == 4 && iy == 22) {
					zeichneAntwortenHintergrundC(LIMEGREEN);
					zeichneNachsteFrageKommtButton();
					setzeNaechsteFrageKommtText();
					return 1;
				}
				if (ix == 36, iy == 22) {
					zeichneAntwortenHintergrundD(LIMEGREEN);
					zeichneNachsteFrageKommtButton();
					setzeNaechsteFrageKommtText();
					return 1;
				}
			}
			else {
				if (ix == 4 && iy == 33) {
					zeichneAntwortenHintergrundA(CRIMSON);
					return 0;
				}
				if (ix == 36 && iy == 33) {
					zeichneAntwortenHintergrundB(CRIMSON);
					return 0;
				}
				if (ix == 4 && iy == 22) {
					zeichneAntwortenHintergrundC(CRIMSON);
					return 0;
				}
				if (ix == 36 && iy == 22) {
					zeichneAntwortenHintergrundD(CRIMSON);
					return 0;
				}
			}
		}
	}
	return 10; //Fehler
}


void leseNaechsteFrage(int ix, int iy, int aktiveStufe) {
	resetAntwortenButtons();
	zeichneFortschrittsanzeige(aktiveStufe);
	Sleep(1000);
	frageEinlesen(aktiveStufe);
	antwortenEinlesen(aktiveStufe);
}

void resetJoker() {
	joker5050 = 1;
	jokerPublikum = 1;
	jokerTel = 1;
}
