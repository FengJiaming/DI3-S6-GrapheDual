#pragma once
#include "CArc.h"
#include "CException.h"

class CSommet
{
private:
	unsigned int uiSOMNumSommet;         // le numero du sommet
	CArc ** ppSOMArcArrivant;            // un tableau du arc dont le point final est ce sommet
	CArc ** ppSOMArcPartant;             // un tableau du arc dont le point depart est ce sommet 
	unsigned int uiSOMNBArcArrivant;     // le nombre de SOMArcArrivant
	unsigned int uiSOMNBArcPartant;      // le nombre de SOMNBArcPartant
public:
	/****************************************
	*  @brief: constructeur par default
	*  @param:  rien
	*  @return : rien
	****************************************/
	CSommet();
	/****************************************
	*  @brief: constructeur de recopie
	*  @param: & SOMSommet
	*  @return : rien
	****************************************/
	CSommet(CSommet & SOMSommet);
	/****************************************
	*  @brief: constructeur
	*  @param:  uiNumSommet
	*  @return : rien
	****************************************/
	CSommet(unsigned int uiNumSommet);
	/****************************************
	*  @brief: destructeur
	*  @param:  rien
	*  @return : rien
	****************************************/
	~CSommet();
	/****************************************
	*  @brief: detruire la memoire
	*  @param:  rien
	*  @return : rien
	****************************************/
	void SOMDetruireMemoire();
	/****************************************
	*  @brief: Modifier le numero du sommet 
	*  @param:  uiNumSommet
	*  @return : rien
	****************************************/
	void SOMModifierNumSommet(unsigned int uiNumSommet);
	/****************************************
	*  @brief: Obtenir le numero du sommet
	*  @param:  rien
	*  @return : le numero du sommet
	****************************************/
	unsigned int SOMLireNumSommet();
	/****************************************
	*  @brief: Obtenir le nombre du SOMArcArrivant
	*  @param:  rien
	*  @return : le nombre du SOMArcArrivant
	****************************************/
	unsigned int SOMLireNBArcArrivant();
	/****************************************
	*  @brief: Obtenir le nombre du SOMArcPartant
	*  @param:  rien
	*  @return : le nombre du SOMArcPartant
	****************************************/
	unsigned int SOMLireNBArcPartant();
	/****************************************
	*  @brief: Modifier le nombre du SOMArcPartant
	*  @param:  uiValeur
	*  @return : rien
	****************************************/
	void SOMModifierNBArcPartant(unsigned int uiValeur);
	/****************************************
	*  @brief: Modifier le nombre du SOMArcArrivant
	*  @param:  uiValeur
	*  @return : rien
	****************************************/
	void SOMModifierNBArcArrivant(unsigned int uiValeur);
	/****************************************
	*  @brief: Ajouter un SOMArcArrivant
	*  @param:  ARCArc
	*  @return : rien
	****************************************/
	void SOMAjouterArcArrivant(CArc * ARCArc);
	/****************************************
	*  @brief: Ajouter un SOMArcPartant
	*  @param:  ARCArc
	*  @return : rien
	*****************************************/
	void SOMAjouterArcPartant(CArc * ARCArc);
	/****************************************
	*  @brief: Supprimer un arc arrivant 
	*  @param:  rien
	*  @return : rien
	*****************************************/
	void SOMSupprimerArcArrivant(unsigned int uiArcDestination);
	/****************************************
	*  @brief: Supprimer un arc partant 
	*  @param:  rien
	*  @return : rien
	*****************************************/
	void SOMSupprimerArcPartant(unsigned int uiArcDestination);
	/****************************************
	*  @brief: Obtenir tous les SOMArcArrivant
	*  @param:  rien
	*  @return : un tableau de la classe CArc qui est SOMArcArrivant
	*****************************************/
	CArc ** SOMLireArcsArrivant();
	/****************************************
	*  @brief: Obtenir tous les SOMArcPartant
	*  @param:  rien
	*  @return : un tableau de la classe CArc qui est SOMArcPartant
	*****************************************/
	CArc ** SOMLireArcsPartant();
	/****************************************
	*  @brief: Supprimer tous les sommets et leur memoire
	*  @param:  rien
	*  @return : rien
	*****************************************/
	void SOMViderSommet();

};

