#include "stdafx.h"
#include "jclient.h"

//Blatt5:

void waagrechtFarbe(int s, int z, int n, int f) {
	for (int i = 0; i < n; i++) {
		farbe2(s + i, z, f);
	}
}
void waagrechtForm(int s, int z, int n, char* f) {
	for (int i = 0; i < n; i++) {
		form2(s + i, z, f);
	}
}
void waagrechtBeides(int s, int z, int n, int farbe, char* form) {
	for (int i = 0; i < n; i++) {
		farbe2(s + i, z, farbe);
		form2(s + i, z, form);
	}
}
void senkrechtFarbe(int s, int z, int n, int f) {
	for (int i = 0; i < n; i++) {
		farbe2(s, z + i, f);
	}
}
void senkrechtForm(int s, int z, int n, char* f) {
	for (int i = 0; i < n; i++) {
		form2(s, z + i, f);
	}
}
void senkrechtBeides(int s, int z, int n, int farbe, char* form) {
	for (int i = 0; i < n; i++) {
		farbe2(s, z + i, farbe);
		form2(s, z + i, form);
	}
}

void zeichneRechteck(int s, int z, int breite, int hoehe, int farbe, char* form) {
	for (int j = 0; j < hoehe; j++) {
		for (int i = 0; i < breite; i++) {
			farbe2(s + i, z + j, farbe);
			form2(s + i, z + j, form);
		}
	}
}