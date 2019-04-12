#include "stdafx.h"
#include "CArc.h"

/****************************************
*  @brief: constructeur par default
*  @param:  rien
*  @return : rien
****************************************/
CArc::CArc()
{
	uiARCDestination = 0;
}

/****************************************
*  @brief: constructeur de recopie
*  @param:  ARCArc
*  @return : rien
****************************************/
CArc::CArc(CArc & ARCArc)
{
	uiARCDestination = ARCArc.uiARCDestination;
}
/****************************************
*  @brief: constructeur
*  @param:  uiDestination
*  @return : rien
****************************************/
CArc::CArc(unsigned int uiDestination)
{
	uiARCDestination = uiDestination;
}

/****************************************
*  @brief: destructeur
*  @param:  rien
*  @return : rien
****************************************/
CArc::~CArc()
{
}

/****************************************
*  @brief: obtenir le numero de sommet associe avec l' arc
*  @param:  rien
*  @return : le numero de sommet associe avec l' arc
****************************************/
unsigned int CArc::ARCLireDestination()
{
	return uiARCDestination;
}

/****************************************
*  @brief: Modifier le numero de sommet associe avec l' arc
*  @param:  uiDestination
*  @return : rien
****************************************/
void CArc::ARCModifierDestination(unsigned int uiDestination)
{
	uiARCDestination = uiDestination;
}
