#include "stdafx.h"
#include "Metaheuristiques.h"
#include "Initialisation.h"

Anneau Metaheuristiques::RechercheLocale(Fichiers data, float pourcentage)
{
	//Deux anneaux de base
	Anneau AnneauOptimale;
	Anneau AnneauBis;
	/*le pourcentage nous sert à déterminer le nbr de sommet dans le ring*/
	if (pourcentage == 1)
		AnneauBis.setAnneau(Initialisation::init(data.getNbrSommets(), data));
	else
		AnneauBis.setAnneau(Initialisation::init(data.getNbrSommets(), data, pourcentage)); // donc l'anneau sera plus réduit
		//l'algorithme de la recherche locale
	do {
		AnneauOptimale.setAnneau(AnneauBis); 
		Voisins v(AnneauOptimale,data); // génère le voisinage

		AnneauBis.setAnneau(v.selectionnerOptimale(AnneauOptimale));
	} while (AnneauOptimale.getCout() > AnneauBis.getCout()); // on compare les coûts tant que l'optimale est pas le mieux

	return AnneauOptimale;
}
