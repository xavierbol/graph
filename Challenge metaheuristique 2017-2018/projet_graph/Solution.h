#pragma once
#include "Anneau.h"
#include "Depot.h"

class Solution
{
private:
	Anneau _anneau;
	vector<Depot> _tabDepot;
	int _cout;
public:
	Solution();
	Solution(Anneau a);
	Solution(Anneau a, vector<Depot> tab);
	Solution(Anneau a, Fichiers data);
	Solution(Anneau a, vector<Depot> tab, int cout);

	Anneau getAnneau();
	void setAnneau(Anneau a);
	vector<Depot> getTabDepot();
	Depot getDepot(int position);
	void setDepot(int position, Depot d);
	int getCout();
	void setCout(int cout);

	void setSolution(Solution s);
	void calculerCout();

	void afficher();
	~Solution();
};

