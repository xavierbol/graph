#include "stdafx.h"
#include "Voisins.h"
#include "Mouvement.h"

Voisins::Voisins(Anneau s, Fichiers data)
{
	_taille = s.getTaille() - 1;
	//en fonction du nombre de sommet on effectue un mouvement ou l'autre
	// plus lent mais avec une meilleure solution si on a < 90 sommets sinon
	// plus rapide mais avec une solution moins bonne (car contrainte)
	if (data.getNbrSommets() > 90) {
		_tabVoisins = vector<Anneau>(_taille);

		for (int i = 0; i < _taille; i++)
		{
			_tabVoisins[i].setAnneau(Mouvement::inverse(s, i, i + 1));
			_tabVoisins[i].calculerCout(data);
		}
	}
	else if (data.getNbrSommets() < 90 && data.getNbrSommets() > 60) {
		_tabVoisins = Mouvement::transition(s, data);
		//_tabVoisins = Mouvement::deplacement(s, data);
		// historique de test...

	}
	else {
		//_tabVoisins = Mouvement::deplacement(s, data);
		_tabVoisins = Mouvement::transition(s, data);
	}
}

vector<Anneau> Voisins::getTabVoisins()
{
	return _tabVoisins;
}

Anneau Voisins::getVoisin(int position)
{
	return _tabVoisins[position];
}

void Voisins::setVoisin(int position, Anneau s)
{
	_tabVoisins[position] = s;
}

int Voisins::getTaille()
{
	return _taille;
}

void Voisins::setTaille(int taille)
{
	_taille = taille;
}
// sélection du meilleur voisin
Anneau Voisins::selectionnerOptimale(Anneau AnneauOptimale)
{
	Anneau optimale=Anneau();
	optimale.setAnneau(AnneauOptimale);

	for (int i = 0; i < _taille; i++) {
		if (optimale.getCout() > _tabVoisins[i].getCout()) {
			optimale = _tabVoisins[i];
		}
	}
	return optimale;
}

void Voisins::afficher()
{
	for (int i = 0; i < _taille; i++) {
		cout << "Voisin a la position " + i << " : " << endl;
		_tabVoisins[i].afficher();
	}
}

Voisins::~Voisins()
{
}
