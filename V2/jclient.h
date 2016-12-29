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

void zeichneFortschrittsanzeige(int aktiveStufe);

//vorhandene:
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

void einlogButton();
