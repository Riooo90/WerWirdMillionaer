#pragma once

int sendMessage(char *sendbuf);
int sendMessageI2(int, int);
char *getAnswer(void);

//Eigene:
void waagrechtFarbe(int s, int z, int n, int f);
void waagrechtForm(int s, int z, int n, char* f);
void waagrechtBeides(int s, int z, int n, int farbe, char* form);
void senkrechtFarbe(int s, int z, int n, int f);
void senkrechtForm(int s, int z, int n, char* f);
void senkrechtBeides(int s, int z, int n, int farbe, char* form);

void zeichneRechteck(int s, int z, int breite, int hoehe, int farbe, char* form);

//WWM-Funktionen:
void zeichneFortschrittsanzeige(int aktiveStufe);
void zeichneNachsteFrageKommtButton();
void zeichneNeustartButton(int aktiveStufe);
void frageHintergrund();
void frageText(char* frage, int aktiveStufe);

void zeichneAntwortenHintergrundA(int farbe);
void setzeAntworttextA(char* antwort);

void zeichneAntwortenHintergrundB(int farbe);
void setzeAntworttextB(char* antwort);

void zeichneAntwortenHintergrundC(int farbe);
void setzeAntworttextC(char* antwort);

void zeichneAntwortenHintergrundD(int farbe);
void setzeAntworttextD(char* antwort);

void leseNaechsteFrage(int ix, int iy, int aktiveStufe);
void setzeNaechsteFrageKommtText();
void resetNachsteFrageKommtButton();

void zeichneJokerbereich();
void frageEinlesen(int aktiveStufe);
void antwortenEinlesen(int aktiveStufe);
int pruefeKlickAktion(int ix, int iy, int aktiveStufe);

void resetAntwortenButtons();
/*void nutzeJoker5050();
int nutzeJokerTelefon(int ix, int iy, int aktiveStufe);
void nutzeJokerPublikum(int ix, int iy, int aktiveStufe);*/
void resetJoker();
void zeichneAbbruchButton();
void gebeAbbruchSummeAus(int aktiveStufe);

//grundlegende BOS-Funktionen
void groesse(int x, int y);
void hintergrund(int i, int f);
void hintergrund2(int i, int j, int f);
void flaeche(int f);
void rahmen(int f);
void loeschen();
void farben(int f);
void farbe(int i, int f);
void grau(int i, int g);
void farbe2(int i, int j, int f);
void grau2(int i, int j, int g);
void formen(char* f);
void form(int i, char* f);
void form2(int i, int j, char* f);
void symbolGroesse(int i, double s);
void symbolGroesse2(int i, int j, double s);
void text(int i, char* f);
void text2(int i, int j, char* f);
void zeichen(int i, char c);
void zeichen2(int i, int j, char c);
void statusText(char * s);
char *abfragen();