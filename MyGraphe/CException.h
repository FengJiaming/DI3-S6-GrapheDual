#pragma once

#include <iostream>
#include "stdio.h"
#include <string.h>
#include <stdlib.h>
#include <fstream>

#define ERREUR_OUVERTURE_FICHIER 1
#define ERREUR_ALLOCATION 2
#define ERREUR_SYNTAXIQUE 3
#define ERREUR_VIDE_GRAPHE 4
#define ERREUR_SOMMET_DOUBLE 5
#define ERREUR_SOMMET_INEXISTANT 6
#define ERREUR_ARC_DOUBLE 7
#define ERREUR_ARC_INEXISTANT 8
#define ERREUR_ARGUMENT	 9

using namespace std;

class CException
{
private:
	unsigned int uiEXCValeur;	//le numero d'erreur.
	char * pcEXCMessage;	// le message d'erreur.

public:
	/****************************************
	*  @brief: constructeur par default
	*  @param:  rien
	*  @return : rien
	****************************************/
	CException(void);
	/****************************************
	*  @brief: constructeur
	*  @param:  uivaleur
	*  @param : pcMessage
	*  @return : rien
	****************************************/
	CException(const unsigned int uivaleur, char * pcMessage);
	/****************************************
	*  @brief: constructeur de recopie
	*  @param:  EXCParam
	*  @return : rien
	****************************************/
	CException(CException & EXCParam);
	/****************************************
	*  @brief: destructeur
	*  @param:  rien
	*  @return : rien
	****************************************/
	~CException(void);
	/****************************************
	*  @brief: Modofier le numero d'erreur
	*  @param:  uiValeur
	*  @return : rien
	****************************************/
	void EXCModifierValeur(unsigned int uiValeur);
	/****************************************
	*  @brief: Lire le numero d'erreur
	*  @param:  rien
	*  @return :  le numero d'erreur
	****************************************/
	unsigned int EXCLireValeur();
	/****************************************
	*  @brief: Lire le numero d'erreur
	*  @param:  rien
	*  @return :  le message d'erreur
	****************************************/
	char * EXCLireMessage();
};


