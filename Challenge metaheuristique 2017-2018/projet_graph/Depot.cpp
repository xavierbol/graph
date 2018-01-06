#include "stdafx.h"
#include "Depot.h"


Depot::Depot()
{
}

Depot::Depot(int client, vector<int> anneau, vector<int> assignmentCost)
{
	// on crée un objet dépot avec les variables passées...
	_cout = assignmentCost[anneau[0]];
	_depot = anneau[0];
	_client = client;
	// on recherche le cout minimum d'un client vers un dépôt
	for (int i = 1; i < anneau.size(); i++) {
		if (_cout > assignmentCost[anneau[i]]) {
			_cout = assignmentCost[anneau[i]];
			_depot = anneau[i];
		}
	}
}

int Depot::getClient()
{
	return _client;
}

void Depot::setClient(int client)
{
	_client = client;
}

int Depot::getDepot()
{
	return _depot;
}

void Depot::setDepot(int depot)
{
	_depot = depot;
}

int Depot::getCout()
{
	return _cout;
}

void Depot::setCout(int cout)
{
	_cout = cout;
}

void Depot::setDepot(Depot d)
{
	_client = d.getClient();
	_depot = d.getDepot();
	_cout = d.getCout();
}

void Depot::afficher()
{
	ofstream monFluxRead("../Sortie_Metaheuristique.txt", ios::out | ios::app);

	if (monFluxRead)
	{
		monFluxRead << _client + 1 << " " << _depot + 1 << endl;
	}
	else
	{
		cout << "Impossible d'ouvrir le fichier !" << endl;
	}

	//cout << _client << " " << _depot << endl;
}


Depot::~Depot()
{
}
