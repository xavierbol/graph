#include "Fichiers.h"


using namespace std;

Fichiers::Fichiers(string url)
{
	this->_fichier = url;

	ifstream monFluxRead(this->_fichier);

	if (monFluxRead)
	{
		string liste;

		monFluxRead >> _nbrColonnes; // récupère le nombre de colonnes

		while (getline(monFluxRead, liste)) //récupère le nombre de ligne dans le tableau
		{
			_nbrLignes++;
		}
		monFluxRead.close();
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture" << endl;
	}


	try {
		_tabMatrice = vector<vector<int>>(_nbrLignes - 1, vector<int>(_nbrColonnes));
	}
	catch(exception const& msg)
	{
		cout << "Impossible de creer la matrice" << endl;
		// exit(EXIT_FAILURE);
	}
	

	monFluxRead.open(_fichier);
	if (monFluxRead)
	{
		int nombre;
		int i = -1;
		int j = 0;
		bool passage_first = false;

		while (monFluxRead >> nombre) //récupère les nombres sauf le premier (nbrColonnes) et écris les valeurs dans un vecteur 2D
		{
			if (nombre == _nbrColonnes && passage_first == false)
			{
				passage_first = true;
			}
			else
			{
				i++;
				if (i < _nbrColonnes)
				{
					_tabMatrice[j][i] = nombre;

					if (i == _nbrColonnes - 1)
					{
						i = -1;
						j++;
					}
				}
			}
		}
		monFluxRead.close();
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture" << endl;
	}
}

int Fichiers::getnbrLignes() // donne le nombre de lignes de la matrice
{
	return this->_nbrLignes-1;
}

int Fichiers::getnbrColonnes() // donne le nombre de colonnes de la matrice
{
	return this->_nbrColonnes;
}

int Fichiers::getElement(int ligne, int colonne)
{
	try
	{
		return this->_tabMatrice[ligne][colonne];
	}
	catch (exception const& msg)
	{
		cout << "Matrice vide" << endl;
	}
	
}