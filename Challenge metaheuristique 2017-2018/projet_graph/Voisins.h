#pragma once
#include "Anneau.h"
class Voisins
{

	private: 
		vector<Anneau> _tabVoisins;
		int _taille;

	public:
		Voisins(Anneau s, Fichiers data);

		vector<Anneau> getTabVoisins();
		Anneau getVoisin(int position);
		void setVoisin(int position, Anneau s);

		int getTaille();
		void setTaille(int taille);

		Anneau selectionnerOptimale(Anneau AnneauOptimale);
		void afficher();

		~Voisins();
};

