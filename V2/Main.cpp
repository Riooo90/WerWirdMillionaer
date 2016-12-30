// V2.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "Main.h"

//Spielfeld Groesse
int a = 50, b = 50;


void main()
{
	loeschen();
	groesse(a, b);
	formen("s");
	zeichneFortschrittsanzeige(0);
	frageHintergrund();
	antwortenHintergrund();
	einlogButton();
	getchar();
}
