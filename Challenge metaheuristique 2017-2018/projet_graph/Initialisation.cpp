#include "stdafx.h"
#include "Initialisation.h"
#include <thread>
using namespace std;
Anneau Initialisation::init(int taille, Fichiers data)
{
	Anneau anneau = Anneau(taille, data);
	srand((unsigned)time(NULL));
		for (int i = 0; i < taille; i++) {
			anneau.setAnneau(Mouvement::inverse(anneau, Anneau::aleatoire(taille), Anneau::aleatoire(taille)));
			anneau.calculerCout(data);
	}
		

	return anneau;
}

Anneau Initialisation::init(int taille, Fichiers data, float pourcentage)
{
	Anneau s = Anneau(taille, data, pourcentage);
	s.calculerCout(data);

	return s;
}
