#pragma once
#include <vector>
#include "Fichiers.h"
#include <time.h>

using namespace std;

class Anneau
{
private:
	vector<int> _tabSommet;
	int _cout, _taille;
	float _pourcentage = 1;

public:
	Anneau();
	Anneau(int taille, Fichiers data);
	Anneau(int taille, vector<int> tabS, int cout);
	Anneau(int taille, Fichiers data, float pourcentage);

	vector<int> getTabSommet();
	int getElement(int position);
	void setTabSommet(int position, int valeur);

	int getCout();
	void setCout(int cout);

	int getTaille();
	void setTaille(int taille);

	float getPourcentage();
	void setPourcentage(float pourcentage);

	void calculerCout(Fichiers data);
	void setAnneau(Anneau anneau);
	bool contains(int sommet);
	void afficher();
	void afficherWrite();

	static int aleatoire(int max, int min = 0);
	
	~Anneau();
};

