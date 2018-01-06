#include "stdafx.h"
#include "Anneau.h"

Anneau::Anneau()
{
}

Anneau::Anneau(int taille, Fichiers data)
{
	_taille = taille;
	_tabSommet = vector<int>(_taille);

	for (int i = 0; i < taille; i++) {
		_tabSommet[i] = i;
	}

	calculerCout(data);
}

Anneau::Anneau(int taille, vector<int> tabS, int cout)
{
	_taille = taille;
	_tabSommet = vector<int>(_taille);

	for (int i = 0; i < _taille; i++) {
		_tabSommet[i] = tabS[i];
	}

	_cout = cout;
}

Anneau::Anneau(int taille, Fichiers data, float pourcentage)
{
	srand((unsigned)time(NULL));
	int nbreAleatoire = aleatoire(data.getNbrSommets());
	_pourcentage = pourcentage;
	_taille = taille * pourcentage;
	
	_tabSommet = vector<int>(_taille);

	for (int i = 0; i < _taille; i++) {
		while (std::find(_tabSommet.begin(), _tabSommet.end(), nbreAleatoire) != _tabSommet.end()) {
			nbreAleatoire = aleatoire(data.getNbrSommets());
		}
		_tabSommet[i] = nbreAleatoire;
	}
}

vector<int> Anneau::getTabSommet()
{
	return _tabSommet;
}

int Anneau::getElement(int position)
{
	return _tabSommet[position];
}

void Anneau::setTabSommet(int position, int valeur)
{
	_tabSommet[position] = valeur;
}

int Anneau::getCout()
{
	return _cout;
}

void Anneau::setCout(int cout)
{
	_cout = cout;
}

int Anneau::getTaille()
{
	return _taille;
}

void Anneau::setTaille(int taille)
{
	_taille = taille;
}

float Anneau::getPourcentage()
{
	return _pourcentage;
}

void Anneau::setPourcentage(float pourcentage)
{
	_pourcentage = pourcentage;
}

void Anneau::calculerCout(Fichiers data)
{
	int i = 0, j = 1;
	_cout = 0;

	while (j < _taille) {
		_cout += data.getElement(_tabSommet[i], _tabSommet[j]);
		i += 1;
		j += 1;
	}
}

void Anneau::setAnneau(Anneau anneau)
{
	_taille = anneau.getTaille();
	_tabSommet = anneau.getTabSommet();
	_cout = anneau.getCout();
	_pourcentage = anneau.getPourcentage();
}

bool Anneau::contains(int sommet)
{
	int res = false;

	for (int i = 0; i < _taille; i++) {
		if (res != true) {
			if (_tabSommet[i] == sommet) {
				res = true;
			}
		}
	}

	return res;
}

void Anneau::afficher()
{
	ofstream monFluxWrite("../Sortie_Metaheuristique.txt", ios::out | ios::trunc);

	if (monFluxWrite)
	{
		monFluxWrite << "RING " << _taille << endl;
		monFluxWrite << _tabSommet[0] + 1;
		for (int i = 1; i < _taille; i++) {
			monFluxWrite << ", " << _tabSommet[i] + 1;
		}
		monFluxWrite << endl;
		monFluxWrite << "STAR" << endl;
	}
	else
	{
		cout << "Impossible d'ouvrir le fichier !" << endl;
	}

	/*cout << "RING " << _taille << endl;
	cout << _tabSommet[0] + 1;

	for (int i = 1; i < _taille; i++) {
		cout << ", " << _tabSommet[i] + 1;
	}
	cout << endl;*/
}

int Anneau::aleatoire(int max, int min)
{
	return rand() % ((max - 1) - min) + min;
}


Anneau::~Anneau()
{
}
