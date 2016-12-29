// V2.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "Main.h"

int a = 30, b = 30;

void main()
{
	loeschen();
	groesse(a, b);
	formen("s");
	zeichneFortschrittsanzeige(0);
	getchar();
	zeichneFortschrittsanzeige(3);
	getchar();
}
