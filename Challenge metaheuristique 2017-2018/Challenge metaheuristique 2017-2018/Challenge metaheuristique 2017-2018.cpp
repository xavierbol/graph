// Challenge metaheuristique 2017-2018.cpp : Defines the entry point for the console application.
//

#include "Fichiers.h"


using namespace std;

int main()
{
	int nbrLignes = 0;
	int nbrColonnes=0;
	string url = "D:/Users/Nicolas/Desktop/data9.dat";//emplacement du fichier


		Fichiers data(url);

		cout << data.getnbrColonnes() << endl;
		cout << data.getnbrLignes() << endl;
		cout << data.getElement(101, 0) << endl;

	

	system("pause >NUL"); //met le programme en pause sans le "Appuyer sur une touche pour continuer"
}

