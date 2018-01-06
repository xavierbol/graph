#include "stdafx.h"
#include "Fichiers.h"


using namespace std;
Fichiers::Fichiers() {};

Fichiers::Fichiers(string url)
{
	//attribution du nom du fichier à la variable privée fichier
	_fichier = url;
	// la lecture en entrée du fichier
	ifstream monFluxRead(_fichier);
	//vérifie si on sait ouvrir le fichier
	if (monFluxRead)
	{
		string liste;
	
		monFluxRead >> _nbrColonnes; // récupère le nombre de colonnes

		while (getline(monFluxRead, liste)) //récupère le nombre de ligne dans le tableau
		{
			_nbrLignes++;
		}
		//on ferme le fichier
		monFluxRead.close();
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture" << endl;
	}


	try {
		_tabMatrice = vector<vector<int>>(_nbrLignes - 1, vector<int>(_nbrColonnes));
		/*création des vecteurs en fonction de la taille de _tabMatrice*/
		/*prend la première moitié en taille tabMatrice*/
		_ringCost = vector<vector<int>>(((_nbrLignes) / 2), vector<int>(_nbrColonnes));
		/*prend la seconde moitié en taille de tabMatrice*/
		_assignmentCost = vector<vector<int>>((_nbrLignes + 1) / 2, vector<int>(_nbrColonnes));
	}
	catch (exception const& msg)
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
		//permet de récupérer le nombre de sommet
		bool passage_first = false;

		while (monFluxRead >> nombre) //récupère les nombres sauf le premier (nbrColonnes) et écrit les valeurs dans un vecteur 2D
		{
			//vérifie si on est dans la première ligne du fichier
			if (nombre == _nbrColonnes && passage_first == false)
			{
				//on exclut le passage pour la ligne suivante
				passage_first = true;
				_nbrSommets = nombre;
			}
			else
			{
				i++;
				if (i < _nbrColonnes)
				{
					//on ajoute le nombre dans la matrice
					_tabMatrice[j][i] = nombre;

					if (i == _nbrColonnes - 1)
					{
						i = -1;
						j++;
					}
				}
			}
		}
		//on ferme le fichier
		monFluxRead.close();
		/*On split le tableau en deux pour avoir les coûts de l'anneau et le cout d'assignement(pour l'étoile -depot)*/
		splitArray();
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture" << endl;
	}
}

int Fichiers::getnbrLignes() // donne le nombre de lignes de la matrice
{
	return _nbrLignes - 1;
}

int Fichiers::getnbrColonnes() // donne le nombre de colonnes de la matrice
{
	return _nbrColonnes;
}

int Fichiers::getElement(int ligne, int colonne)
{
	try
	{
		return _tabMatrice[ligne][colonne];
	}
	catch (exception const& msg)
	{
		cout << "Matrice vide" << endl;
	}

}

int Fichiers::getNbrSommets() {
	return _nbrSommets;
}

int Fichiers::getElementRingCost(int ligne, int colonne)
{
	return _ringCost[ligne][colonne];
}

void Fichiers::splitArray() {
	/*On split le tableau en deux pour avoir les co�ts de l'anneau et le cout d'assignement(pour l'�toile -depot)*/

	int halfArraySize = _nbrLignes / 2;

	for (int i = 0; i < halfArraySize; i++)
	{
		for (int j = 0; j < _nbrColonnes; j++)
		{
			_ringCost[i][j] = _tabMatrice[i][j];
			//cout << _ringCost[i][j] << endl;
		}
	}
	//variable pour d�marrer � 0 le vecteur
	int l = 0;
	/*tableau pour les couts d'assignements*/
	for (int i = halfArraySize; i < _nbrLignes - 1; i++)
	{
		//cout << "ligne : " << l << endl;
		for (int j = 0; j < _nbrColonnes; j++)
		{

			_assignmentCost[l][j] = _tabMatrice[i][j];
			//cout << "valeur : " << _assignmentCost[l][j] << endl;

		}
		l = l + 1;
	}
}

Fichiers::~Fichiers()
{
}
