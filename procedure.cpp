#include <iostream>
#include "declaration.h"
#include "outils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;

void Sup_tete(FileAttente &li) {
	maillon *ap = new maillon;
	if (li.tete != NULL) {
		ap = li.tete;
		ap = ap->suivant;
		delete li.tete;
		li.tete = ap;
	}
}


int Longueur(FileAttente li, int &l) {
	int l;
	maillon *sp = new maillon;
	l = 0;
	sp = li.tete;
	while (sp != NULL) {
		sp = sp->suivant;
		l = l + 1;
	}
	return l;
}