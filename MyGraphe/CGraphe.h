#pragma once

#include "CException.h"
#include "CSommet.h"

class CGraphe
{
private:
	unsigned int uiGRANBSommets;     //le nombre de sommets de ce graph
	unsigned int uiGRANBArcs;        //le nombre de arcs de ce graph
	CSommet **ppGRASommets;          //un tableau de sommets de ce graph

public:
	/****************************************
	*  @brief: constructeur par default
	*  @param:  rien
	*  @return : rien
	****************************************/
	CGraphe();
	/****************************************
	*  @brief: constructeur de recopie
	*  @param:  & GRAGraphe
	*  @return : rien
	****************************************/
	CGraphe(CGraphe & GRAGraphe);
	/****************************************
	*  @brief: destructeur
	*  @param:  rien
	*  @return : rien
	****************************************/
	~CGraphe();
	/****************************************
	*  @brief: detruire la memoire
	*  @param:  rien
	*  @return : rien
	****************************************/
	void GRADetruireMemoire();
	/****************************************
	*  @brief: Obtenir le nombre de sommet
	*  @param:  rien
	*  @return : le nombre du sommet
	****************************************/
	unsigned int GRALireNBSommets();
	/****************************************
	*  @brief: Obtenir le nombre de arc
	*  @param:  rien
	*  @return : le nombre du arc
	****************************************/
	unsigned int GRALireNBArcs();
	/****************************************
	*  @brief: Modifier le nombre de sommet
	*  @param:  uiValeur
	*  @return : rien
	****************************************/
	void GRAModifierNBSommets(unsigned int uiValeur);
	/****************************************
	*  @brief: Modifier le nombre de arc
	*  @param:  uiValeur
	*  @return : rien
	****************************************/
	void GRAModifierNBArcs(unsigned int uiValeur);
	/****************************************
	*  @brief: Obtenir le tableau de sommet
	*  @param:  rien
	*  @return : le tableau de la classe CSommet
	****************************************/
	CSommet ** GRALireSommets();
	/****************************************
	*  @brief: Ajouter un sommet
	*  @param:  uiNumSommet
	*  @return : rien
	****************************************/
	void GRAAjouterSommet(unsigned int uiNumSommet);
	/****************************************
	*  @brief: Modifier un sommet du tableau ppGRASommets
	*  @param:  uiNumSommet, SOMSommet
	*  @return : rien
	****************************************/
	void GRAModifierSommet(unsigned int uiNumSommet, CSommet * SOMSommet);
	/****************************************
	*  @brief: Supprimer un sommet du tableau ppGRASommets
	*  @param: SOMSommet
	*  @return : rien
	****************************************/
	void GRASupprimerSommet(CSommet * SOMSommet);
	/****************************************
	*  @brief: Ajouter un arc
	*  @param:  uiNumDepart, uiNumArrivee
	*  @return : rien
	****************************************/
	void GRAAjouterArc(unsigned int uiNumDepart, unsigned int uiNumArrivee);
	/****************************************
	*  @brief: Modifier un arc
	*  @param:  uiNumDepartPre, uiNumArriveePre, uiNumDepartSuiv, uiNumArriveeSuiv
	*  @return : rien
	****************************************/
	void GRAModifierArc(unsigned int uiNumDepartPre, unsigned int uiNumArriveePre, unsigned int uiNumDepartSuiv, unsigned int uiNumArriveeSuiv);
	/****************************************
	*  @brief: Supprimer un arc
	*  @param:  uiNumDepart, uiNumArrivee
	*  @return : rien
	****************************************/
	void GRASupprimerArc(unsigned int uiNumDepart, unsigned int uiNumArrivee);
	/****************************************
	*  @brief: Trouver un sommet par le numero du sommet
	*  @param:  uiNumSommet
	*  @return : un objet de la classe CSommet
	****************************************/
	CSommet * GRATrouverSommetParNum(unsigned int uiNumSommet);
	/****************************************
	*  @brief: Trouver un ArcPartant 
	*  @param:  SOMDepart, uiDestination
	*  @return : un objet de la classe CArc
	****************************************/
	CArc * GRATrouverArcPartant(CSommet * SOMDepart, unsigned int uiDestination);
	/****************************************
	*  @brief: Trouver un ArcArrivan
	*  @param:  SOMArrivant, uiDestination
	*  @return : un objet de la classe CArc
	****************************************/
	CArc * GRATrouverArcArrivant(CSommet * SOMArrivant, unsigned int uiDestination);
	/****************************************
	*  @brief: Afficher tous les informations du tableau de sommet
	*  @param:  rien
	*  @return : rien
	****************************************/
	void GRAAfficherSommets();
	/****************************************
	*  @brief: Afficher le graphe non orienté
	*  @param:  rien
	*  @return : rien
	****************************************/
	void GRAAfficherGrapheNonOriente();
	/****************************************
	*  @brief: Afficher le graphe dual 
	*  @param:  rien
	*  @return : rien
	****************************************/
	void GRAAfficherGrapheDual();
	/****************************************
	*  @brief: Afficher le graph 
	*  @param:  rien
	*  @return : rien
	****************************************/
	void GRAAfficherGraphe();
	/****************************************
	*  @brief:  La surcharge d'operateur = de deux objets de la classe CGraphe
	*  @param: & GRAGraphe
	*  @return: un objet de la classe CGraphe
	****************************************/
	CGraphe & operator=(CGraphe & GRAGraphe);
};

