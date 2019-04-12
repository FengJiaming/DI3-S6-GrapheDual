#include "CException.h"
#pragma once
class CArc
{
private:
	unsigned int uiARCDestination;      // le numero de sommet associe avec l' arc
public:
	/****************************************
	*  @brief: constructeur par default
	*  @param:  rien
	*  @return : rien
	****************************************/
	CArc();
	/****************************************
	*  @brief: constructeur de recopie
	*  @param:  ARCArc
	*  @return : rien
	****************************************/
	CArc(CArc & ARCArc);
	/****************************************
	*  @brief: constructeur
	*  @param:  uiDestination
	*  @return : rien
	****************************************/
	CArc(unsigned int uiDestination);
	/****************************************
	*  @brief: destructeur
	*  @param:  rien
	*  @return : rien
	****************************************/
	~CArc();
	/****************************************
	*  @brief: obtenir le numero de sommet associe avec l' arc
	*  @param:  rien
	*  @return : le numero de sommet associe avec l' arc
	****************************************/
	unsigned int ARCLireDestination();
	/****************************************
	*  @brief: Modifier le numero de sommet associe avec l' arc
	*  @param:  uiDestination
	*  @return : rien
	****************************************/
	void ARCModifierDestination(unsigned int uiDestination);
};
