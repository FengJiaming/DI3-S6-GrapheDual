#pragma once

#include "CGraphe.h"
#include "CFichier.h"
#include "COperationGraphe.h"
#include <cassert>
class CTestsUnitaires
{
public:
	/****************************************
	*  @brief: constructeur par default
	*  @param:  rien
	*  @return : rien
	****************************************/
	CTestsUnitaires(void);
	/****************************************
	*  @brief: destructeur
	*  @param:  rien
	*  @return : rien
	****************************************/
	~CTestsUnitaires(void);
	/****************************************
	*  @brief: Fonction d'appel des tests unitaires des fonctions
	*  @param:  rien
	*  @return : rien
	****************************************/
	void TUNIStart();
	/****************************************
	*  @brief: Tester de la fonction d'ajouter un sommet
	*  @param:  rien
	*  @return : rien
	****************************************/
	void TUNITest_GRAAjouterSommet();
	/****************************************
	*  @brief: Tester de la fonction de modifier un sommet
	*  @param:  rien
	*  @return : rien
	****************************************/
	void TUNITest_GRAModifierSommet();
	/****************************************
	*  @brief: Tester de la fonction de supprimer un sommet
	*  @param:  rien
	*  @return : rien
	****************************************/
	void TUNITest_GRASupprimerSommet();
	/****************************************
	*  @brief: Tester de la fonction d'ajouter un arc
	*  @param:  rien
	*  @return : rien
	****************************************/
	void TUNITest_GRAAjouterArc();
	/****************************************
	*  @brief: Tester de la fonction de modifier un arc
	*  @param:  rien
	*  @return : rien
	****************************************/
	void TUNITest_GRAModifierArc();
	/****************************************
	*  @brief: Tester de la fonction de supprimer un arc
	*  @param:  rien
	*  @return : rien
	****************************************/
	void TUNITest_GRASupprimerArc();

};

