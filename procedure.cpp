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


int Longueur(FileAttente &li) {

}