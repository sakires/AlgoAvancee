#include <iostream>
#include <string>

using namespace std;
///////////////////////// Constante //////////////////////////////////////
const int MININT = -2147483630; // On ne met pas au maximum pour la compatibilite entre PC.
const int MAXINT = 2147483630;

///////////////////////////////////////////////////////////////////////////////////////////////
// Programme permettant de saisr une variable entiere et ceux entre les bornes choisi
// Entree : le message souhaitant etre afficher, les deux borne (borne inferieur borneinf et 
//   borne superieur bornesup 
// Sortie : le nombre souhaitant etre saisi 
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
/*exercice 1*/
void exercice1() {
	int n;
	int somme(int n);
	saisirControleEntierBorne("choisir un n entier", 0, MAXINT, n);
	cout << "la somme des "<<n<<"premier entier vaut vaut " << somme(n) << endl;
}
/* que pour entier positif*/
int somme(int n) {
	if (n == 0) {
		return 0;
	}
	else {
		return n + somme(n - 1);
	}
}

/*Exercice 2*/
void exercice2(){
	int n;
	int a;
	int pow(int a, int n);
	saisirControleEntierBorne("choisir un a entier", 0, MAXINT, a);
	saisirControleEntierBorne("choisir un n entier", 0, MAXINT, n);
	cout<<a << " puissance "<<n<<" vaut " << pow(a,n) << endl;
}
int pow(int a, int n) {
	int an, an2;
	if (n == 0) return 1;
	if (n == 1)return a;
	else {
		if (n % 2 == 0) {
			an = pow(a, n / 2);
			return an*an;
		}
		else {
			an2 = pow(a, (n - 1) / 2);
			return a * an2*an2;
		}
	}
}

/*Exercice 3*/
void exercice3() {
	int a;
	int b;
	int PGCD(int a, int b);
	saisirControleEntierBorne("choisir un a entier", 0, MAXINT, a);
	saisirControleEntierBorne("choisir un b entier", 0, MAXINT, b);
	cout << "le PGCD de "<<a <<" et "<<b<<" est "<< PGCD(a, b) << endl;
}
int PGCD(int a, int b) {
	if (a == b)return a;
	else {
		if (a > b) {
			return PGCD(a - b, b);
		}
		else {
			return PGCD(a, b-a);
		}
	}
}
/*facultatif */
void facultatif() {
	int exo;
	int a;
	int b;
	int n;
	int sommeSansRec(int n);
	int powSansRec(int a, int n);
	int PGCDsansRec(int a, int b);
	do {
		saisirControleEntierBorne("\n1 recurcivite \n2 -puissance \n3 -PGCD  \n4 quitter", 0, 4, exo);
		switch (exo)
		{
		case 1:
			saisirControleEntierBorne("choisir un n entier", 0, MAXINT, n);
			cout << "la somme sans recurence des " << n << "premier entier vaut vaut " << sommeSansRec(n) << endl;
			break;
		case 2:
			saisirControleEntierBorne("choisir un a entier", 0, MAXINT, a);
			saisirControleEntierBorne("choisir un n entier", 0, MAXINT, n);
			cout << a << " puissance sans recurence " << n << " vaut " << powSansRec(a, n) << endl;
			break;
		case 3:
			saisirControleEntierBorne("choisir un a entier", 0, MAXINT, a);
			saisirControleEntierBorne("choisir un b entier", 0, MAXINT, b);
			cout << "le PGCD sans recurence de " << a << " et " << b << " est " << PGCDsansRec(a, b) << endl;
			break;
		default:
			cout << "Quitter" << endl;
			break;
		}
	} while (exo != 4);
}
int sommeSansRec(int n) {
	int res = 0;
	while (n != 0) {
		res = res + n;
		n--;
	}
	return res;
}
int powSansRec(int a, int n) {
	int res = 1;
	for (int i = 0; i < n; i++) {
		res = res * a;
	}
	return res;
}
int PGCDsansRec(int a, int b) {
	int res = a%b;
	while (res!=0) {
		a = b;
		b = res;
		res = a % b;
	}
	return b;
}

int main(){
	int exo;

	do {
		saisirControleEntierBorne("\n1 recurcivite \n2 -puissance \n3 -PGCD \n4 -facultatif \n5 quitter", 0, 5, exo);
		switch (exo)
		{
		case 1:
			exercice1();
			break;
		case 2:
			exercice2();
			break;
		case 3:
			exercice3();
			break;
		case 4:
			facultatif();
			break;
		default:
			cout << "Quitter" << endl;
			break;
		}
	} while (exo != 5);
	
	system("pause");

	return 0;
}