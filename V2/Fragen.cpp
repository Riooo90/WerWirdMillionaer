#include "stdafx.h"

static char* frage;
static char* antwort;

//Schrittweite 1
char *fragen[] = { "Wenn das Wetter gut ist, wird der Bauer bestimmt den Eber, das Ferkel und...?",
"Was ist meist ziemlich viel?",
"Wessen Genesung schnell voran schreitet der erholt sich...",
"Welche Neuerung hielt das Jahr 1984 für deutsche Fernsehzuschauer bereit?",
"Wer in Dover wohnt,",
"Johann Wolfgang von Goethes Autobiographie kennt man unter dem Titel...?",
"Was findet man bei Autos meist in den Varianten gleichlaufend oder gegenlaeufig?",
"Wessen Ansprüche sollen hierzulande gesetzlich neu geregelt werden?",
"Wobei besteht die oberste Schicht oft aus dem sogenannten Fondant?",
"Welcher Buchstabe kam in der Entstehungsgeschichte unseres heute gebraeuchlichen Alphabets erst im Mittelalter hinzu?",
"Welche Pflanzen zaehlen zur selbsen Familie und sind fue manchen Hobbygaertner zum Verwechseln aehnlich?",
"Womit machte sich der 2012 verstorbene Inder Ravi Shankar zur Legende?",
"Bei welchen beiden Staaten findet man im Ländernamen wie auch im Namen der Hauptstadt keinen anderen Vokal als das A?",
"Wer muss beim Urlaub im Schwarzwald grundsatzlich die sogenannte Zwei-Meter-Regel beachten?",
"Welchen Eintrag findet man im Urduden von 1880 nicht?" };

//Schrittweite 4
char *antworten[]= { "...einen draufmachen", "...die Nacht durchzechen", "...die Sau rauslassen", "...auf die Kacke hauen",
"stolze Summe", "selbstbewusste Differenz", "arroganter Quotient", "hochmuetiges Produkt",
"...hinguckends", "...anschauends", "zusehends","glotzends",
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

/*
a = 4, 33
b = 36, 33
c = 4, 22
d = 36, 22
*/
char* loesung[] = { "4, 22", "4, 33", "4, 22", "4, 22", "36, 33", "4, 22", "36, 33", "4, 22", "4, 33", "36, 33", "4, 33", "4, 33", "36, 22", "4, 22", "36, 33" };


//lesen Fragen ein und schreiben Sie in eine globale Var
void frageEinlesen(int aktiveStufe) {
	frage = fragen[aktiveStufe];
	frageHintergrund(frage);
}

void antwortenEinlesen(int aktiveStufe) {
	//damit wir alle vier Antworten auslesen koennen
		//zeichne die antwort Buttons mit der passenden antwort
		antwort = antworten[(aktiveStufe * 4)];
		antwortenHintergrundA(BLUE, antwort);

		antwort = antworten[(aktiveStufe * 4) + 1];
		antwortenHintergrundB(BLUE, antwort);

		antwort = antworten[(aktiveStufe * 4) + 2];
		antwortenHintergrundC(BLUE, antwort);

		antwort = antworten[(aktiveStufe * 4) + 3];
		antwortenHintergrundD(BLUE, antwort);
}

