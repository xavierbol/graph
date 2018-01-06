#pragma once
#include "Fichiers.h"

class Depot
{
private:
	int _client;
	int _depot;
	int _cout;
public:
	Depot();
	Depot(int client, vector<int> anneau, vector<int> data);

	int getClient();
	void setClient(int client);

	int getDepot();
	void setDepot(int depot);
	
	int getCout();
	void setCout(int cout);

	void setDepot(Depot d);

	void afficher();

	~Depot();
};

