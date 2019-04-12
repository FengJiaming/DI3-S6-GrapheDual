#pragma once

#include "CGraphe.h"

class CFichier
{
private:
	char * pcFICNom_Fichier;    // le nom de fichier.
	CGraphe  Graphe;             // l'objet de la classe CGraphe
public:
	/****************************************
	*  @brief: constructeur par default
	*  @param:  rien
	*  @return : rien
	****************************************/
	CFichier(void);
	/****************************************
	*  @brief: constructeur
	*  @param:  pcNom
	*  @return : rien
	****************************************/
	CFichier(char * pcNom);
	/****************************************
	*  @brief: destructeur
	*  @param:  rien
	*  @return : rien
	****************************************/
	~CFichier(void);
	/****************************************
	*  @brief: lire le fihcier et les stocker dans un objet de CGraphe
	*  @param:  rien
	*  @return : un objet de la classe  CGraphe
	****************************************/
	CGraphe & FICLire_Fichier();
	/****************************************
	*  @brief: lire les elements de chaque ligne dans le fichier
	*  @param:  pcLine
	*  @param:  cDelimiter
	*  @param:  uiNBElement
	*  @return : le tableau qui est utilise pour stocker  de chaque searches
	****************************************/
	char ** FICLireValeur(char * pcLigne, char cDelimiter, unsigned int uiNBElement);
	/****************************************
	*  @brief: detruire la memoire
	*  @param:  rien
	*  @return : rien
	****************************************/
	void FICDetruireGraphe();
};

