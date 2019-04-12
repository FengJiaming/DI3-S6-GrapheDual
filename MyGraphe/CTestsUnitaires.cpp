#include "stdafx.h"
#include "CTestsUnitaires.h"

/****************************************
*  @brief: destructeur
*  @param:  rien
*  return : rien
	****************************************/
CTestsUnitaires::CTestsUnitaires(void)
{
}

/****************************************
*  @brief: destructeur
*  @param:  rien
*  @return : rien
****************************************/
CTestsUnitaires::~CTestsUnitaires(void)
{
}

/****************************************
*  @brief: Fonction d'appel des tests unitaires des fonctions
*  @param:  rien
*  @return : rien
****************************************/
void CTestsUnitaires::TUNIStart()
{
	cout << "\n----------------------------------" << endl;
	cout << "---------TESTS UNITAIRES----------\n" << endl;

	TUNITest_GRAAjouterSommet();
	TUNITest_GRAModifierSommet();
	TUNITest_GRASupprimerSommet();
	TUNITest_GRAAjouterArc();
	TUNITest_GRAModifierArc();
	TUNITest_GRASupprimerArc();

	cout << "--------TOUS LES TESTS OK!--------" << endl;
	cout << "----------------------------------\n" << endl;
}

/****************************************
*  @brief: Tester de la fonction d'ajouter un sommet
*  @param:  rien
*  @return : rien
****************************************/
void CTestsUnitaires::TUNITest_GRAAjouterSommet()
{
	cout << "----------------------------------" << endl;
	cout << "TESTSUNITAIRES : " << endl;
	cout << "AJOUTER UN SOMMET AU GRAPHE\n" << endl;

	CGraphe  GRATestGraphe;
	//Tester le constructeur
	assert(GRATestGraphe.GRALireNBSommets() == 0);

	//Tester le fonction de ajouter un sommet
	GRATestGraphe.GRAAjouterSommet(1);
	//Tester le fonction de lire nombre des sommets
	assert(GRATestGraphe.GRALireNBSommets() == 1);
	//Tester le fonction de lire les sommets
	assert(GRATestGraphe.GRALireSommets()[0]->SOMLireNumSommet() == 1);

	GRATestGraphe.GRAAjouterSommet(2);
	assert(GRATestGraphe.GRALireNBSommets() == 2);
	assert(GRATestGraphe.GRALireSommets()[1]->SOMLireNumSommet() == 2);
	
	//Tester l'exception
	try
	{
		GRATestGraphe.GRAAjouterSommet(1);
		assert(false);
	}
	catch(CException EXCLevee)
	{
		assert(EXCLevee.EXCLireValeur() == ERREUR_SOMMET_DOUBLE);
	}
	cout << "------------TEST OK !-------------" << endl;
	cout << "----------------------------------\n" << endl;
	GRATestGraphe.GRADetruireMemoire();
}

/****************************************
*  @brief: Tester de la fonction de modifier un sommet
*  @param:  rien
*  @return : rien
****************************************/
void CTestsUnitaires::TUNITest_GRAModifierSommet()
{
	cout << "----------------------------------" << endl;
	cout << "TESTSUNITAIRES : " << endl;
	cout << "MODIFIER UN SOMMET AU GRAPHE\n" << endl;

	CGraphe  GRATestGraphe;
	CSommet * SOMTestSommet = new CSommet(2);
	try
	{
		GRATestGraphe.GRAModifierSommet(1,SOMTestSommet);
		assert(false);
	}
	catch(CException EXCLevee)
	{
		assert(EXCLevee.EXCLireValeur() == ERREUR_VIDE_GRAPHE ); 
	}

	GRATestGraphe.GRAAjouterSommet(1);
	GRATestGraphe.GRAAjouterSommet(2);

	//Tester l'exception si le sommet dans ce graphe est doublé
	try
	{
		GRATestGraphe.GRAModifierSommet(1,SOMTestSommet);
	}
	catch(CException EXCLevee)
	{
		assert(EXCLevee.EXCLireValeur() == ERREUR_SOMMET_DOUBLE ); 
	}

	GRATestGraphe.GRAModifierSommet(3,GRATestGraphe.GRATrouverSommetParNum(2));
	assert(GRATestGraphe.GRALireNBSommets() == 2);   //Assertion le Nombre des sommets du graphe apres la modification
	assert(GRATestGraphe.GRALireSommets()[1]->SOMLireNumSommet() == 3);		////Assertion du sommet du graphe apres la modification

	cout << "------------TEST OK !-------------" << endl;
	cout << "----------------------------------\n" << endl;
	GRATestGraphe.GRADetruireMemoire();
	SOMTestSommet->SOMDetruireMemoire();
	delete SOMTestSommet;
}

/****************************************
*  @brief: Tester de la fonction de supprimer un sommet
*  @param:  rien
*  @return : rien
****************************************/
void CTestsUnitaires::TUNITest_GRASupprimerSommet()
{
	cout << "----------------------------------" << endl;
	cout << "TESTSUNITAIRES : " << endl;
	cout << "SUPPRIMER UN SOMMET AU GRAPHE\n" << endl;
	
	CGraphe  GRATestGraphe;
	CSommet * SOMTestSommet = new CSommet(4);
	//Tester l'exception si la liste des sommets est nul
	try{
		GRATestGraphe.GRASupprimerSommet(SOMTestSommet);
	}
	catch(CException EXCLevee)
	{
		assert(EXCLevee.EXCLireValeur() == ERREUR_VIDE_GRAPHE ); 
	}

	GRATestGraphe.GRAAjouterSommet(1);
	GRATestGraphe.GRAAjouterSommet(2);
	GRATestGraphe.GRAAjouterSommet(3);
	GRATestGraphe.GRAAjouterSommet(4);

	//Tester le fonction de supprimer un sommet
	GRATestGraphe.GRASupprimerSommet(GRATestGraphe.GRATrouverSommetParNum(3));
	assert(GRATestGraphe.GRALireNBSommets() == 3);
	assert(GRATestGraphe.GRATrouverSommetParNum(3) == nullptr);
	GRATestGraphe.GRASupprimerSommet(GRATestGraphe.GRATrouverSommetParNum(4));
	assert(GRATestGraphe.GRALireNBSommets() == 2);
	assert(GRATestGraphe.GRATrouverSommetParNum(4) == nullptr);
	
	//Tester l'exception si le sommet à supprimer ne trouve pas
	try{
		GRATestGraphe.GRASupprimerSommet(SOMTestSommet);
	}
	catch(CException EXCLevee)
	{
		assert(EXCLevee.EXCLireValeur() == ERREUR_SOMMET_INEXISTANT ); 
	}
	
	cout << "------------TEST OK !-------------" << endl;
	cout << "----------------------------------\n" << endl;
	GRATestGraphe.GRADetruireMemoire();
	SOMTestSommet->SOMDetruireMemoire();
	delete SOMTestSommet;
}

/****************************************
*  @brief: Tester de la fonction d'ajouter un arc
*  @param:  rien
*  @return : rien
****************************************/
void CTestsUnitaires::TUNITest_GRAAjouterArc()
{
	cout << "----------------------------------" << endl;
	cout << "TESTSUNITAIRES : " << endl;
	cout << "AJOUTER UN ARC AU GRAPHE\n" << endl;
	CGraphe  GRATestGraphe;

	GRATestGraphe.GRAAjouterSommet(1);
	GRATestGraphe.GRAAjouterSommet(2);
	GRATestGraphe.GRAAjouterSommet(3);
	GRATestGraphe.GRAAjouterSommet(4);
	assert(GRATestGraphe.GRALireNBSommets() == 4);

	//Tester de ajouter un arc
	GRATestGraphe.GRAAjouterArc(1,3);
	assert(GRATestGraphe.GRALireNBArcs() == 1);
	assert(GRATestGraphe.GRALireSommets()[0]->SOMLireArcsPartant()[0]->ARCLireDestination() == 3);
	assert(GRATestGraphe.GRALireSommets()[2]->SOMLireArcsArrivant()[0]->ARCLireDestination() == 1);
	GRATestGraphe.GRAAjouterArc(1,4);
	assert(GRATestGraphe.GRALireNBArcs() == 2);

	//Tester l'exception de verifier si le sommet est trouvé
	try{
		GRATestGraphe.GRAAjouterArc(1,5);
	}
	catch(CException EXCLevee)
	{
		assert(EXCLevee.EXCLireValeur() == ERREUR_SOMMET_INEXISTANT ); 
	}

	//Tester l'exception de verifier la répétition des arcs
	try{
		GRATestGraphe.GRAAjouterArc(1,3);
	}
	catch(CException EXCLevee)
	{
		assert(EXCLevee.EXCLireValeur() == ERREUR_ARC_DOUBLE ); 
	}
	cout << "------------TEST OK !-------------" << endl;
	cout << "----------------------------------\n" << endl;
	GRATestGraphe.GRADetruireMemoire();
}

/****************************************
*  @brief: Tester de la fonction de modifier un arc
*  @param:  rien
*  @return : rien
****************************************/
void CTestsUnitaires::TUNITest_GRAModifierArc()
{
	cout << "----------------------------------" << endl;
	cout << "TESTSUNITAIRES : " << endl;
	cout << "MODIFIER UN ARC AU GRAPHE\n" << endl;
	CGraphe  GRATestGraphe;
	GRATestGraphe.GRAAjouterSommet(1);
	GRATestGraphe.GRAAjouterSommet(2);
	GRATestGraphe.GRAAjouterSommet(3);
	GRATestGraphe.GRAAjouterArc(1,3);
	assert(GRATestGraphe.GRALireNBArcs() == 1);

	GRATestGraphe.GRAModifierArc(1,3,1,2);
	assert(GRATestGraphe.GRALireNBArcs() == 1);
	assert(GRATestGraphe.GRALireSommets()[0]->SOMLireArcsPartant()[0]->ARCLireDestination() == 2);    //verifier si l'arc est 1->2
	assert(GRATestGraphe.GRALireSommets()[1]->SOMLireArcsArrivant()[0]->ARCLireDestination() == 1);
	
	cout << "------------TEST OK !-------------" << endl;
	cout << "----------------------------------\n" << endl;
	GRATestGraphe.GRADetruireMemoire();
}

/****************************************
*  @brief: Tester de la fonction de supprimer un arc
*  @param:  rien
*  @return : rien
****************************************/
void CTestsUnitaires::TUNITest_GRASupprimerArc()
{
	cout << "----------------------------------" << endl;
	cout << "TESTSUNITAIRES : " << endl;
	cout << "SUPPRIMER UN ARC AU GRAPHE\n" << endl;
	CGraphe  GRATestGraphe;
	try{
		GRATestGraphe.GRASupprimerArc(1,3);
	}
	catch(CException EXCLevee)
	{
		assert(EXCLevee.EXCLireValeur() == ERREUR_SOMMET_INEXISTANT ); 
	}
	GRATestGraphe.GRAAjouterSommet(1);
	GRATestGraphe.GRAAjouterSommet(2);
	GRATestGraphe.GRAAjouterSommet(3);
	
	GRATestGraphe.GRAAjouterArc(1,2);
	GRATestGraphe.GRAAjouterArc(2,3);

	try{
		GRATestGraphe.GRASupprimerArc(1,3);
	}
	catch(CException EXCLevee)
	{
		assert(EXCLevee.EXCLireValeur() == ERREUR_ARC_INEXISTANT ); 
	}

	GRATestGraphe.GRASupprimerArc(1,2);
	assert(GRATestGraphe.GRALireNBArcs() == 1);
	assert(GRATestGraphe.GRATrouverArcArrivant(GRATestGraphe.GRATrouverSommetParNum(2),1) == nullptr);
	assert(GRATestGraphe.GRATrouverArcPartant(GRATestGraphe.GRATrouverSommetParNum(1),2) == nullptr);

	cout << "------------TEST OK !-------------" << endl;
	cout << "----------------------------------\n" << endl;
	GRATestGraphe.GRADetruireMemoire();
}