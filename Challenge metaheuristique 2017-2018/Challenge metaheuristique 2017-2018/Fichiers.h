#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


class Fichiers
{
	private:

		int _nbrLignes = 0;
		int _nbrColonnes = 0;
		std::string _fichier;
		std::vector<std::vector<int>> _tabMatrice;

	public:
		
		Fichiers(std::string url); //Constructeur
		int getnbrLignes(); //Récupère le nombre de lignes
		int getnbrColonnes(); //Récupère le nombre de colonnes
		int getElement(int ligne, int colonne); //Récupère un élément dans le vecteur

};