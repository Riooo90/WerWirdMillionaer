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
	antwortenHintergrundA(123456);
	antwortenHintergrundB(555555);
	antwortenHintergrundC(555555);
	antwortenHintergrundD(555555);
	einlogButton();
	getchar();
}
