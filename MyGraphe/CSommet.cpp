#include "stdafx.h"
#include "CSommet.h"


/****************************************
*  @brief: constructeur par default
*  @param:  rien
*  @return : rien
****************************************/
CSommet::CSommet()
{
}

/****************************************
*  @brief: constructeur de recopie
*  @param: & SOMSommet
*  @return : rien
****************************************/
CSommet::CSommet(CSommet & SOMSommet)
{	
	
	//Initialiser le nombre des arcs
	uiSOMNBArcArrivant = SOMSommet.SOMLireNBArcArrivant();
	uiSOMNBArcPartant = SOMSommet.SOMLireNBArcPartant();

    // Affectation du numéro du sommet
	uiSOMNumSommet = SOMSommet.SOMLireNumSommet();

    // Initialisation
    ppSOMArcArrivant = nullptr;
    ppSOMArcPartant = nullptr;

	// Allocation des arcs arrivant
	if(uiSOMNBArcArrivant > 0) {
		ppSOMArcArrivant = (CArc **)malloc(sizeof(CSommet *) * uiSOMNBArcArrivant);
		if(ppSOMArcArrivant == nullptr)
			throw CException(ERREUR_ALLOCATION, "Echec de l'allocation");

		//Ajouter des arcs arrivants du sommet passé en paramètre
		for(unsigned int uiBoucleI = 0 ; uiBoucleI < uiSOMNBArcArrivant ; uiBoucleI++)
			ppSOMArcArrivant[uiBoucleI] = new CArc(*SOMSommet.ppSOMArcArrivant[uiBoucleI]);
	}
        
    // Allocation des arcs partant
    if (uiSOMNBArcPartant > 0) {
		ppSOMArcPartant = (CArc **)malloc(sizeof(CSommet *) * uiSOMNBArcPartant);
        if(ppSOMArcPartant == nullptr)
			throw CException(ERREUR_ALLOCATION, "Echec de l'allocation");

        //Ajouter des arcs partants du sommet passé en paramètre    
		for(unsigned int uiBoucleI = 0 ; uiBoucleI < uiSOMNBArcPartant ; uiBoucleI++)
			ppSOMArcPartant[uiBoucleI] = new CArc(*SOMSommet.ppSOMArcPartant[uiBoucleI]);
	}
}

/****************************************
*  @brief: constructeur
*  @param:  uiNumSommet
*  @return : rien
****************************************/
CSommet::CSommet(unsigned int uiNumSommet)
{
	uiSOMNumSommet = uiNumSommet;
	uiSOMNBArcArrivant = 0;
	uiSOMNBArcPartant = 0;
	ppSOMArcArrivant = nullptr;
	ppSOMArcPartant = nullptr;
}

/****************************************
*  @brief: destructeur
*  @param:  rien
*  @return : rien
****************************************/
CSommet::~CSommet()
{
}

/****************************************
*  @brief: detruire la memoire
*  @param:  rien
*  @return : rien
****************************************/
void CSommet::SOMDetruireMemoire()
{
	for(unsigned int uiBoucleI = 0 ; uiBoucleI < uiSOMNBArcArrivant ; uiBoucleI++)
		delete ppSOMArcArrivant[uiBoucleI];

	free(ppSOMArcArrivant);

	for(unsigned int uiBoucleI = 0 ; uiBoucleI < uiSOMNBArcPartant; uiBoucleI++)
		delete ppSOMArcPartant[uiBoucleI];

	free(ppSOMArcPartant);
}

/****************************************
*  @brief: Modifier le numero du sommet 
*  @param:  uiNumSommet
*  @return : rien
****************************************/
void CSommet::SOMModifierNumSommet(unsigned int uiNumSommet)
{
	uiSOMNumSommet = uiNumSommet;
}

/****************************************
*  @brief: Obtenir le numero du sommet
*  @param:  rien
*  @return : le numero du sommet
****************************************/
unsigned int CSommet::SOMLireNumSommet()
{
	return uiSOMNumSommet;
}

/****************************************
*  @brief: Obtenir le nombre du SOMArcArrivant
*  @param:  rien
*  @return : le nombre du SOMArcArrivant
****************************************/
unsigned int CSommet::SOMLireNBArcArrivant()
{
	return uiSOMNBArcArrivant;
}

/****************************************
*  @brief: Obtenir le nombre du SOMArcPartant
*  @param:  rien
*  @return : le nombre du SOMArcPartant
****************************************/
unsigned int CSommet::SOMLireNBArcPartant()
{
	return uiSOMNBArcPartant;
}

/****************************************
*  @brief: Modifier le nombre du SOMArcPartant
*  @param:  uiValeur
*  @return : rien
****************************************/
void CSommet::SOMModifierNBArcArrivant(unsigned int uiValeur)
{
	uiSOMNBArcArrivant = uiValeur;
}

/****************************************
*  @brief: Modifier le nombre du SOMArcArrivant
*  @param:  uiValeur
*  @return : rien
****************************************/
void CSommet::SOMModifierNBArcPartant(unsigned int uiValeur)
{
	uiSOMNBArcPartant = uiValeur;
}

/****************************************
*  @brief: Ajouter un SOMArcArrivant
*  @param:  ARCArc
*  @return : rien
****************************************/
void CSommet::SOMAjouterArcArrivant(CArc * ARCArc)
{
	if (ARCArc == nullptr)
		throw new CException(ERREUR_ARGUMENT, "L'argument arc ne peut pas être nul"); 
	if(ppSOMArcArrivant == nullptr) {
		ppSOMArcArrivant = (CArc **) malloc(sizeof(CArc * ));
	}
	else{
		ppSOMArcArrivant = (CArc **) realloc(ppSOMArcArrivant, (uiSOMNBArcArrivant + 1) * sizeof(CArc *) );
	}

	ppSOMArcArrivant[uiSOMNBArcArrivant] = ARCArc;
	uiSOMNBArcArrivant++;
}

/****************************************
*  @brief: Ajouter un SOMArcPartant
*  @param:  ARCArc
*  @return : rien
*****************************************/
void CSommet::SOMAjouterArcPartant(CArc * ARCArc)
{
	if (ARCArc == nullptr)
		throw new CException(ERREUR_ARGUMENT, "L'argument arc ne peut pas être nul"); 

	if(ppSOMArcPartant == nullptr) {
		ppSOMArcPartant =(CArc **)malloc(sizeof(CArc *));
	}
	else{
		ppSOMArcPartant = (CArc **) realloc(ppSOMArcPartant, (uiSOMNBArcPartant + 1) * sizeof(CArc *));
	}

	ppSOMArcPartant[uiSOMNBArcPartant] = ARCArc;
	uiSOMNBArcPartant++;
}

/****************************************
*  @brief: Supprimer un arc arrivant 
*  @param:  rien
*  @return : rien
*****************************************/
void CSommet::SOMSupprimerArcArrivant(unsigned int uiArcDestination)
{
	for(unsigned int uiBoucleArcs = 0 ; uiBoucleArcs < uiSOMNBArcArrivant ; uiBoucleArcs++ ) {
		CArc * ARCArrivant = ppSOMArcArrivant[uiBoucleArcs];
		if(uiArcDestination == ARCArrivant->ARCLireDestination()) {
			uiSOMNBArcArrivant = uiSOMNBArcArrivant - 1;
			delete(ARCArrivant);
			while (uiBoucleArcs < uiSOMNBArcArrivant) {
				ppSOMArcArrivant[uiBoucleArcs] = ppSOMArcArrivant[uiBoucleArcs + 1];
				uiBoucleArcs++;
			}	
			break;
		}
	}
}

/****************************************
*  @brief: Supprimer un arc partant 
*  @param:  rien
*  @return : rien
*****************************************/
void CSommet::SOMSupprimerArcPartant(unsigned int uiArcDestination)
{
	for(unsigned int uiBoucleArcs = 0 ; uiBoucleArcs < uiSOMNBArcPartant ; uiBoucleArcs++ ) {
		CArc * ARCPartant = ppSOMArcPartant[uiBoucleArcs];
		if(uiArcDestination == ARCPartant->ARCLireDestination()) {
			uiSOMNBArcPartant = uiSOMNBArcPartant - 1;
			delete(ARCPartant);
			while (uiBoucleArcs < uiSOMNBArcPartant) {
				ppSOMArcPartant[uiBoucleArcs] = ppSOMArcPartant[uiBoucleArcs + 1];
				uiBoucleArcs++;
			}	
			break;
		}
	}
}

/****************************************
*  @brief: Obtenir tous les SOMArcArrivant
*  @param:  rien
*  @return : un tableau de la classe CArc qui est SOMArcArrivant
*****************************************/
CArc ** CSommet::SOMLireArcsArrivant()
{
	return ppSOMArcArrivant;
}

/****************************************
*  @brief: Obtenir tous les SOMArcPartant
*  @param:  rien
*  @return : un tableau de la classe CArc qui est SOMArcPartant
*****************************************/
CArc ** CSommet::SOMLireArcsPartant()
{
	return ppSOMArcPartant;
}

/****************************************
*  @brief: Supprimer tous les sommets et leur memoire
*  @param:  rien
*  @return : rien
*****************************************/
void CSommet::SOMViderSommet()
{
	//Supprimer des arcs arrivant et libérer la mémoire
	for (unsigned int uiBoucle = 0 ; uiBoucle < uiSOMNBArcArrivant ; uiBoucle++)
		delete(ppSOMArcArrivant[uiBoucle]);
	uiSOMNBArcArrivant = 0;
	free(ppSOMArcArrivant);
	// Supprimer des arcs partant et libérer la mémoire
	for (unsigned int uiBoucle = 0 ; uiBoucle < uiSOMNBArcPartant ; uiBoucle++)
		delete(ppSOMArcPartant[uiBoucle]);
	uiSOMNBArcPartant = 0;
	free(ppSOMArcPartant);
}