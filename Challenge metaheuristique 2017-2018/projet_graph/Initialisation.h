#pragma once
#include "Mouvement.h"
#include "Anneau.h"
#include "time.h"

class Initialisation
{
public:
	static Anneau init(int taille, Fichiers data);
	static Anneau init(int taille, Fichiers data, float pourcentage);
};