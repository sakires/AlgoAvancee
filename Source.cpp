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
		li.queue->suivant = sp;
		li.queue = sp;
	}
	else {
		li.tete = new maillon;
		li.queue = new maillon;
		li.tete->numero = numero;
		li.tete->suivant = li.queue;
	}

}

int Consulter(FileAttente li) {
	if (li.tete != NULL)
		return li.tete->numero;
	else
		return 0;
}

int main() {
	int exo;
	FileAttente li ;
	li.tete = NULL;
	li.queue = NULL;
	do {
		saisirControleEntierBorne("\n1 ajouter \n2 -// \n3 -consulter \n4 // \n5 quitter", 0, 5, exo);
		switch (exo)
		{
		case 1:
			int element;
			cout << " tapez un entier " << endl;
			cin >> element;
			ajouterEnQueue(li , element);
			break;
		case 2:
			//exercice2();
			break;
		case 3:
			cout << Consulter(li);
			break;

		default:
			cout << "Quitter" << endl;
			break;
		}
	} while (exo != 5);

	system("pause");

	return 0;
}