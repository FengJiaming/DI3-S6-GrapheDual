#include "stdafx.h"
#include "CException.h"

/****************************************
*  @brief: constructeur par default
*  @param:  rien
*  @return : rien
****************************************/
CException::CException()
{
	uiEXCValeur = 0;
	pcEXCMessage = _strdup("");
}

/****************************************
*  @brief: constructeur
*  @param:  uivaleur
*  @param : pcMessage
*  @return : rien
****************************************/
CException::CException(unsigned int uiValeur, char * pcMessage)
{
	uiEXCValeur = uiValeur;
	pcEXCMessage = _strdup(pcMessage);
}

/****************************************
*  @brief: constructeur de recopie
*  @param:  EXCParam
*  @return : rien
****************************************/
CException::CException(CException & EXCParam)
{
	uiEXCValeur = EXCParam.uiEXCValeur;
	pcEXCMessage = _strdup(EXCParam.pcEXCMessage);
}

/****************************************
*  @brief: destructeur
*  @param:  rien
*  @return : rien
****************************************/
CException :: ~CException()
{
	free(pcEXCMessage);
}

/****************************************
*  @brief: Modofier le numero d'erreur
*  @param:  uiValeur
*  @return : rien
****************************************/
void CException::EXCModifierValeur(unsigned int uiValeur)
{
	uiEXCValeur = uiValeur;
}

/****************************************
*  @brief: Lire le numero d'erreur
*  @param:  rien
*  @return :  le numero d'erreur
****************************************/
unsigned int CException::EXCLireValeur()
{
	return uiEXCValeur;
}

/****************************************
*  @brief: Lire le numero d'erreur
*  @param:  rien
*  @return :  le message d'erreur
****************************************/
char *  CException::EXCLireMessage()
{
	return pcEXCMessage;
}

