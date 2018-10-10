#include <iostream>
#include <stdio.h>
#include <string>
#include  <cstdio> 
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////
// Programme permettant de saisr une variable enti�re et ceux entre les bornes choisi
//  entr� : le message souhaitant �tre afficher, les deux borne (borne inf�rieur borneinf et 
//   borne sup�rieur bornesup 
// Sorti : le nombre souhaitant �tre saisi 
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


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Structure de donn�es repr�sentant un maillon (avec chaine)
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct Personne {
	string name;
	Personne *suivant;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Structure de donn�es repr�sentantla file d'attente
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct FileAttentePerso {
	Personne *tete;
	Personne *queue;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Proc�dure permettant d'ajouter un entier en queue de file c'est-�-dire � la fin de la file d'attente
//	ENTREE : une variable numero de type entier qui est la valeur � ins�rer dans la file
//	SORTIE : une variable li de type FileAttente qui repr�sente la file d'attente
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ajouterEnQueuePerso(FileAttentePerso &li, string name) {
	Personne *sp;
	sp = new Personne;
	if (li.tete != NULL) {
		sp->name = name;
		if (li.queue != NULL) {
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
		li.tete = new Personne;
		li.tete->name = name;
		li.tete->suivant = NULL;
	}

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Proc�dure permettant de supprimer l'�lement en tete de file c'est-�-dire en premi�re position
//	ENTREE : rien
//	SORTIE : une variable li de type FileAttente
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Sup_tetePerso(FileAttentePerso &li) {
	if (li.tete != NULL) {
		Personne *ap = li.tete->suivant;
		delete li.tete;
		li.tete = ap;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Proc�dure permettant de calculer la longueur de la liste
//	ENTREE : une variable li de type FileAttente
//	RETOUR :une varaible l de type entier qui correspond � la longueur de la liste
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int LongueurPerso(FileAttentePerso li) {
	int l;
	Personne *sp = new Personne;
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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Proc�dure permettant de consulter le premier �l�ment de la liste c'est -�-dire voir le contenu de li.tete
//	ENTREE : une variable li de type FileAttente
//	SORTIE : rien
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ConsulterPerso(FileAttentePerso li) {
	if (li.tete != NULL)
		cout << "le premier element est " << li.tete->name << endl;
	else
		cout << "il n y a pas d element dans la file" << endl;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//			PROGRAMME PRINCIPAL DE L'EXO 2
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
	int exo;
	string element;
	FileAttentePerso li;
	li.tete = NULL;
	li.queue = NULL;
	do {
		saisirControleEntierBorne("\n1 ajouter \n2 -retirer \n3 -consulter \n4 longueur \n5 quitter", 0, 5, exo);
		switch (exo)
		{
		case 1:
			
			cout << " tapez une chaine " << endl;
			cin >> element;
			ajouterEnQueuePerso(li, element);
			break;
		case 2:
			Sup_tetePerso(li);
			break;
		case 3:
			ConsulterPerso(li);
			break;
		case 4: cout << "la longeur est de " << LongueurPerso(li) << endl;
		default:
			cout << "Quitter" << endl;
			break;
		}
	} while (exo != 5);

	system("pause");

	return 0;
}



