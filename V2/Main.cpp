// V2.cpp : Defines the entry point for the console application.

#include "stdafx.h"

//Spielfeld Groesse
int a = 50, b = 50;

void deleteAll() {
	loeschen();
	// jetzt Schriftgroesse veraendern, gilt dann fuer alle neue Texte
	char befehl[100];
	sprintf_s(befehl, 100, "fontsize %d \n", 18);
	sendMessage(befehl);
	sprintf_s(befehl, 100, "clearAllText \n");
	sendMessage(befehl);
}

void main()
{
	deleteAll();
	groesse(a, b);
	formen("s");
	//zeichneRechteck(5, 5, 10, 5, 123456, "s");
	zeichneFortschrittsanzeige(0);
	frageHintergrund();
	antwortenHintergrundA(123456);
	antwortenHintergrundB(555555);
	antwortenHintergrundC(555555);
	antwortenHintergrundD(555555);
	zeichneEinlogButton();
	zeichneJokerbereich();
	getchar();
}
