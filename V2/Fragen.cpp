#include "stdafx.h"

static char* frage;
static char* antwort;

//Loesung 0 = falsch, 1 = richtig, in der main wird ausgelesen was FKR zurück gibt

//Schrittweite 1
char *fragen[] = { "Wenn das Wetter gut ist, wird der Bauer bestimmt den Eber, das Ferkel und...?",
"Was ist meist ziemlich viel?",
"Wessen Genesung schnell voran schreitet der erholt sich...",
"Welche Neuerung hielt das Jahr 1984 fuer deutsche Fernsehzuschauer bereit?",
"Wer in Dover wohnt,",
"Johann Wolfgang von Goethes Autobiographie kennt man unter dem Titel...?",
"Was findet man bei Autos meist in den Varianten gleichlaufend oder gegenlaeufig?",
"Wessen Ansprueche sollen hierzulande gesetzlich neu geregelt werden?",
"Wobei besteht die oberste Schicht oft aus dem sogenannten Fondant?",
"Welcher Buchstabe kam in der Entstehungsgeschichte unseres heute gebraeuchlichen \n Alphabets erst im Mittelalter hinzu?",
"Welche Pflanzen zaehlen zur selben Familie und sind fuer manchen Hobbygaertner \n zum Verwechseln aehnlich?",
"Womit machte sich der 2012 verstorbene Inder Ravi Shankar zur Legende?",
"Bei welchen beiden Staaten findet man im Ländernamen wie auch im Namen der Hauptstadt keinen anderen Vokal als das A?",
"Wer muss beim Urlaub im Schwarzwald grundsatzlich die sogenannte Zwei-Meter-Regel beachten?",
"Welchen Eintrag findet man im Urduden von 1880 nicht?" };

//Schrittweite 4
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
"Sitar", "Yagakurse", "Currygerichte", "Kricketschlaeger",
"Katar und Tschad", "Japan und Madagaskar", "Kanada und Bahamas", "Ghana und Kasachstan",
"Nichtschwimmer", "Hundebesitzer", "Mountainbiker", "Wohnmobilfahrer",
"Dynamit", "Gluehlampe", "Batterie", "Mikrophon" };

//lesen Fragen ein und schreiben Sie in eine globale Var
void frageEinlesen(int aktiveStufe) {
	frage = fragen[aktiveStufe];
	frageText(frage);
	resetNachsteFrageKommtButton();
}

void antwortenEinlesen(int aktiveStufe) {
	//damit wir alle vier Antworten auslesen koennen
		//zeichne die antwort Buttons mit der passenden antwort
	antwort = antworten[(aktiveStufe * 4)];
	//zeichneAntwortenHintergrundA(BLUE); Sonst malt immer blau drüber obwohl da
	setzeAntworttextA(antwort);

	antwort = antworten[(aktiveStufe * 4) + 1];
	//zeichneAntwortenHintergrundB(BLUE);
	setzeAntworttextB(antwort);

	antwort = antworten[(aktiveStufe * 4) + 2];
	//zeichneAntwortenHintergrundC(BLUE);
	setzeAntworttextC(antwort);

	antwort = antworten[(aktiveStufe * 4) + 3];
	//zeichneAntwortenHintergrundD(BLUE);
	setzeAntworttextD(antwort);
}
//Vergleicht die Texte aus den KLicks, an der Stelle Stufe, ix und iy kommen vom KLick, aktive Stufe übergeben, da abhängig davon, nicht in der fkt als for drin!
int richtig(int ix, int iy, int aktiveStufe) {
	/*	a = 4, 33
	b = 36, 33
	c = 4, 22
	d = 36, 22
	es gehört immer ein zweier Paar zusammen*/
	int loesung[] = { 4, 22, 4, 33, 4, 22, 4, 22, 36, 33, 4, 22, 4, 22, 4, 22, 4, 33, 36, 33, 4, 33, 4, 33, 36, 22, 4, 22, 36, 33 };
	//mal zwei weil ein zweierpaar zusammen gehört für das loesungsarray
	if (ix == loesung[aktiveStufe*2] && iy == loesung[(aktiveStufe *2)+ 1]) {
		if (ix == 4 && iy == 33) {
			zeichneAntwortenHintergrundA(GREEN);
			zeichneNachsteFrageKommtButton();
			setzeNaechsteFrageKommtText();
			return 1;
		}
		if (ix == 36 && iy == 33) {
			zeichneAntwortenHintergrundB(GREEN);
			zeichneNachsteFrageKommtButton();
			setzeNaechsteFrageKommtText();
			return 1;
		}
		if (ix == 4 && iy == 22) {
			zeichneAntwortenHintergrundC(GREEN);
			zeichneNachsteFrageKommtButton();
			setzeNaechsteFrageKommtText();
			//printf("%s", antwort);
			return 1;
		}
		if (ix == 36, iy == 22) {
			zeichneAntwortenHintergrundD(GREEN);
			zeichneNachsteFrageKommtButton();
			setzeNaechsteFrageKommtText();
			return 1;
		}
	}
	else {
		if (ix == 4 && iy == 33) {
			zeichneAntwortenHintergrundA(RED);
			return 0;
		}
		if (ix == 36 && iy == 33) {
			zeichneAntwortenHintergrundB(RED);
			return 0;
		}
		if (ix == 4 && iy == 22) {
			zeichneAntwortenHintergrundC(RED);
			return 0;
		}
		if (ix == 36 && iy == 22) {
			zeichneAntwortenHintergrundD(RED);
			return 0;
		}
	}
}

void resetFrageButtons() {
	zeichneAntwortenHintergrundA(BLUE);
	zeichneAntwortenHintergrundB(BLUE);
	zeichneAntwortenHintergrundC(BLUE);
	zeichneAntwortenHintergrundD(BLUE);
}

void leseNaechsteFrage(int ix, int iy, int aktiveStufe) {
	//if (ix == 16 && iy == 3) {
	resetFrageButtons();
	zeichneFortschrittsanzeige(aktiveStufe);
	Sleep(1000);
	frageEinlesen(aktiveStufe);
	antwortenEinlesen(aktiveStufe);
	//}
}