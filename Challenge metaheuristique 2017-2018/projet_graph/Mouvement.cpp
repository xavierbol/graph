#include "stdafx.h"
#include "Mouvement.h"

Anneau Mouvement::inverse(Anneau s, int e1, int e2)
{
	//Anneau res(s.getTaille(), s.getTabSommet(), s.getCout());
	int tmp = s.getElement(e1);

	s.setTabSommet(e1, s.getElement(e2));
	s.setTabSommet(e2, tmp);

	return s;
}

vector<Anneau> Mouvement::transition(Anneau a, Fichiers data)
{
	vector<Anneau> tab = vector<Anneau>(a.getTaille() * (a.getTaille() - 1) / 2);
	int k = 0, j;
	for (int i = 0; i < a.getTaille(); i++) {
		j = i + 1;
		while (j < a.getTaille()) {
			tab[k] = inverse(a, i, j++);
			tab[k++].calculerCout(data);
		}
	}

	return tab;
}

vector<Anneau> Mouvement::deplacement(Anneau a, Fichiers data)
{
	vector<Anneau> tab = vector<Anneau>(a.getTaille() * (a.getTaille() - 1));

	int k = 0;
	for (int i = 0; i < a.getTaille(); i++) {
		for (int j = 0; j < a.getTaille(); j++) {
			if (i != j) {
				tab[k] = inverse(a, i, j);
				tab[k++].calculerCout(data);
			}
		}
	}

	return tab;
}
