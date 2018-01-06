#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Fichiers
{

private:
	int _nbrLignes = 0;
	int _nbrColonnes = 0;
	int _nbrSommets = 0;
	string _fichier;
	vector<vector<int>> _tabMatrice;
	vector<vector<int>> _ringCost;
	vector<vector<int>> _assignmentCost;

public:
	Fichiers(); //Constructeur
	Fichiers(std::string url); //Constructeur de lecture
	int getnbrLignes(); //Récupère le nombre de lignes
	int getnbrColonnes(); //Récupère le nombre de colonnes
	int getElement(int ligne, int colonne); //Récupère un élément dans le vecteur
	int getNbrSommets(); // Récupère le nombre de sommet
	vector<vector<int>> getRingCost() { return _ringCost; };
	int getElementRingCost(int ligne, int colonne);
	vector<vector<int>> getAssignmentCost(){ return _assignmentCost; };
	vector<vector<int>> getMatrice() {return _tabMatrice;}
	void splitArray();

	~Fichiers();
};

