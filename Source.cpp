#include <iostream>
#include <stdio.h>
#include <string>
#include  <cstdio> 
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////
// Programme permettant de saisr une variable entière et ceux entre les bornes choisi
//  entré : le message souhaitant être afficher, les deux borne (borne inférieur borneinf et 
//   borne supérieur bornesup 
// Sorti : le nombre souhaitant être saisi 
///////////////////////////////////////////////////////////////////////////////////////////////

void saisirControleEntierBorne(string message, int borneinf, int bornesup, int& nombre)
{
	cout << message << endl;
	cin >> nombre;
	while (nombre < borneinf || nombre > bornesup)
	{
		cout << "Erreur, " << message << endl;
		cin >> nombre;
	}
}
typedef struct maillon  {
	int numero;
	maillon *suivant;
};

typedef struct FileAttente {
	maillon *tete;
	maillon *queue;
};


void ajouterEnQueue( FileAttente &li , int numero) {
	maillon *sp;
	sp = new maillon;
	if (li.tete != NULL) {
		sp->numero = numero;
		if (li.queue != NULL){
			li.queue->suivant = sp;
			li.queue = sp;
		}
		else {
			li.tete->suivant = sp;
			li.queue = sp;
		}

		sp->suivant = NULL;
	}
	else {
		li.tete = new maillon;
		li.tete->numero = numero;
		li.tete->suivant = NULL;
	}

}
void Sup_tete(FileAttente &li) {
	if (li.tete != NULL) {
		maillon *ap = li.tete->suivant;
		delete li.tete;
		li.tete = ap;
	}
}


int Longueur(FileAttente li) {
	int l;
	maillon *sp = new maillon;
	l = 0;
	if (li.tete != NULL) {
		l++;
		sp = li.tete;
		while (sp->suivant != NULL) {
			sp = sp->suivant;
			l = l + 1;
		}
	}
	return l;
}
void Consulter(FileAttente li) {
	if (li.tete != NULL)
		cout <<"le premier element est"<< li.tete->numero<<endl;
	else
		cout << "il n y a pas d element dans la file" << endl;
}

int main() {
	int exo;
	FileAttente li ;
	li.tete = NULL;
	li.queue = NULL;
	do {
		saisirControleEntierBorne("\n1 ajouter \n2 -retirer \n3 -consulter \n4 longueur \n5 quitter", 0, 5, exo);
		switch (exo)
		{
		case 1:
			int element;
			cout << " tapez un entier " << endl;
			cin >> element;
			ajouterEnQueue(li , element);
			break;
		case 2:
			Sup_tete(li);
			break;
		case 3:
			Consulter(li);
			break;
		case 4: cout <<"la longeur est de "<< Longueur(li) << endl;
		default:
			cout << "Quitter" << endl;
			break;
		}
	} while (exo != 5);

	system("pause");

	return 0;
}