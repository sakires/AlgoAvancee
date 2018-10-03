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
typedef struct {
	int numero;
	maillon *suivant;
}maillon;

typedef struct {
	maillon *tete;
	maillon *queue;
}FileAttente;


void ajouterEnQueue(FileAttente li , int numero) {
	maillon *sp;
	sp = new maillon;
	sp->numero = numero;
	li.queue->suivant = sp;
	li.queue = sp;
}

int Consulter(FileAttente li) {
	return li.tete->numero;
}

int main() {
	int exo;

	do {
		saisirControleEntierBorne("\n1 recurcivite \n2 -puissance \n3 -PGCD \n4 quitter", 0, 4, exo);
		switch (exo)
		{
		case 1:
			exercice1();
			break;
		case 2:
			exercice2();
			break;
		case 3:
			//exercice3();
			break;

		default:
			cout << "Quitter" << endl;
			break;
		}
	} while (exo != 5);

	system("pause");

	return 0;
}