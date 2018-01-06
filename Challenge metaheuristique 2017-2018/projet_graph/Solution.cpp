#include "stdafx.h"
#include "Solution.h"


Solution::Solution()
{
}

Solution::Solution(Anneau a)
{
	_anneau.setAnneau(a);
	_cout = a.getCout();
}

Solution::Solution(Anneau a, vector<Depot> tab)
{
	_anneau.setAnneau(a);
	_tabDepot = tab;
}

Solution::Solution(Anneau a, Fichiers data)
{
	int position = 0;
	//on attribue l'anneau à la variable
	_anneau.setAnneau(a);
	//on attirbue le coût à la variable
	_cout = _anneau.getCout();
	//on initialise un vecteur dépot de nos futurs sommets
	_tabDepot = vector<Depot>(data.getNbrSommets() - a.getTaille());
	//on va rechercher les "clients" vers le "dépot"
	for (int i = 0; i < data.getNbrSommets(); i++) {
		if (a.contains(i) == false) {
			_tabDepot[position] = Depot(i, a.getTabSommet(), data.getAssignmentCost()[i]); //création d'un dépot
			_cout += _tabDepot[position].getCout(); //ajout du coût du client au dépot à la "somme"
			position += 1; // on va à l'indice suivant
		}
	}
}

Solution::Solution(Anneau a, vector<Depot> tab, int cout)
{
	_anneau.setAnneau(a);
	_tabDepot = vector<Depot>(tab.size());

	for (int i = 0; i < tab.size(); i++) {
		_tabDepot[i].setDepot(tab[i]);
	}

	_cout = cout;
}

Anneau Solution::getAnneau()
{
	return _anneau;
}

void Solution::setAnneau(Anneau a)
{
	_anneau.setAnneau(a);
}

vector<Depot> Solution::getTabDepot()
{
	return _tabDepot;
}

Depot Solution::getDepot(int position)
{
	return _tabDepot[position];
}

void Solution::setDepot(int position, Depot d)
{
	_tabDepot[position].setDepot(d);
}

int Solution::getCout()
{
	return _cout;
}

void Solution::setCout(int cout)
{
	_cout = cout;
}

void Solution::setSolution(Solution s)
{
	_anneau.setAnneau(s.getAnneau());
	_tabDepot = s.getTabDepot();
	_cout = s.getCout();
}

void Solution::calculerCout()
{
	_cout = _anneau.getCout();

	for (int i = 0; i < _tabDepot.size(); i++) {
		_cout += _tabDepot[i].getCout();
	}
}

//on écrit l'anneau dans le fichier
// on écrit donc les clients et les dépots dans le fichier			
void Solution::afficher()
{
	//on ouvre en écriture le fichier de sortie, en précisant qu'il peut réecrire le contenu
	ofstream monFluxWrite("../Sortie_Metaheuristique.txt", ios::out | ios::app);
	//on affiche l'anneau
	_anneau.afficher();
	//cout << "STAR" << endl;
	for (int i = 0; i < _tabDepot.size(); i++) {
		_tabDepot[i].afficher();
	}
	//on vérifie si on peut écrire
	if (monFluxWrite)
	{
		//on écrit...
		monFluxWrite << "COST " << _cout << endl;
	}
	else
	{
		cout << "Impossible d'ouvrir le fichier !" << endl;
	}

	//cout << "COST " << _cout << endl;
}

Solution::~Solution()
{
}
