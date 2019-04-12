#pragma once
#include"CGraphe.h"

class COperationGraphe
{
private:
	CGraphe OperationGraphe;
	CGraphe OperationGrapheDual;
	CGraphe OperationGrapheInverse;
public:
	/****************************************
	*  @brief: constructeur par default
	*  @param:  rien
	*  @return : rien
	****************************************/
	COperationGraphe(void);
	/****************************************
	*  @brief: destructeur
	*  @param:  rien
	*  @return : rien
	****************************************/
	~COperationGraphe(void);
	/****************************************
	*  @brief: Operation pour Inverser un graphe
	*  @param:  GRAGraphe
	*  @return : CGraphe    le graphe inverse
	****************************************/
	CGraphe & OPGInverserGraphe(CGraphe & GRAGraphe);
	/****************************************
	*  @brief: Operation pour convertir un graphe à  graphe non orienté
	*  @param:  GRAGraphe
	*  @return : CGraphe    le graphe non orienté
	****************************************/
	CGraphe & OPGConvertirGraphe(CGraphe & GRAGraphe);
	/****************************************
	*  @brief: Operation pour calculer le graphe dual d'un graphe donné
	*  @param:  GRAGraphe
	*  @return : CGraphe    le graphe dual
	****************************************/
	CGraphe & OPGCalculerGrapheDual(CGraphe & GRAGraphe);
	/****************************************
	*  @brief: detruire la memoire du graphe pendant qu'on inverse le graphe
	*  @param:  rien
	*  @return : rien
	****************************************/
	void OPGDetruireGraphe();
};

