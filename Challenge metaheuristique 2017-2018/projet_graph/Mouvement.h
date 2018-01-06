#pragma once
#include "Anneau.h"

class Mouvement
{
public:
	static Anneau inverse(Anneau s, int e1, int e2);
	static vector<Anneau> transition(Anneau a, Fichiers data);
	static vector<Anneau> deplacement(Anneau a, Fichiers data);
};