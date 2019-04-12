#include "stdafx.h"
#include "CFichier.h"

/****************************************
*  @brief: constructeur par default
*  @param:  rien
*  @return : rien
****************************************/
CFichier::CFichier(void)
{
	pcFICNom_Fichier = "";
}

/****************************************
*  @brief: constructeur
*  @param:  pcNom
*  @return : rien
****************************************/
CFichier::CFichier(char * pcNom)
{
	pcFICNom_Fichier = pcNom;
}

/****************************************
*  @brief: destructeur
*  @param:  rien
*  @return : rien
****************************************/
CFichier::~CFichier(void)
{
}

/****************************************
*  @brief: lire le fihcier et les stocker dans un objet de CGraphe
*  @param:  rien
*  @return : un objet de la classe  CGraphe
****************************************/
CGraphe & CFichier::FICLire_Fichier()
{
	
	ifstream File;
	File.open(pcFICNom_Fichier);
	if (!File.is_open()) {
		throw CException(ERREUR_OUVERTURE_FICHIER, "Ne peux pas ouvrir le fichier, verifiez le nom de fichier.");
	}

	char buffer[1024];		//Stocker tout le contenu de chaque ligne
	unsigned int uiNumFichierLigne = 1;		//Le nombre de lignes de fichier en cours de lecture
	unsigned int uiNBSommets;
	unsigned int uiNBArcs;

	cout << "Read from file: " << pcFICNom_Fichier << endl;
	
	while (File.getline(buffer, 1024)) {

		cout << "Ligne " << uiNumFichierLigne << " = " << buffer << endl;

		//NBSommets  extraire nombre de sommets du graphe
		if (uiNumFichierLigne == 1) {
			if (strstr(buffer, "NBSommets=") == nullptr) {
				throw CException(ERREUR_SYNTAXIQUE, "Syntaxiquee erreur sur ligne 1.");
			}
			else {
				char ** ppcElement = FICLireValeur(buffer, '=', 2);
				char *pcNBSommets = ppcElement[1];
				uiNBSommets = atoi(pcNBSommets);

				if ( uiNBSommets == 0 ) 
					throw CException(ERREUR_VIDE_GRAPHE,"Le nombre des sommets dans le fichier est zéro.");

				for (int i=0;i<2;i++) {
					free(ppcElement[i]);
				}
				free(ppcElement);
			}
		}

		//NBArcs extraire nombre de arcs du graphe
		if (uiNumFichierLigne == 2) {
			if (strstr(buffer, "NBArcs=") == nullptr) {
				throw CException(ERREUR_SYNTAXIQUE, "Syntaxique erreur sur ligne 2.");
			}
			else {
				char ** ppcElement = FICLireValeur(buffer, '=', 2);
				char *pcNBArcs = ppcElement[1];
				uiNBArcs = atoi(pcNBArcs);

				for (int i=0;i<2;i++) {
					free(ppcElement[i]);
				}
				free(ppcElement);
			}
		}

		//Sommets=[
		if (uiNumFichierLigne == 3) {
			if (strstr(buffer, "Sommets=[") == nullptr) {
				throw CException(ERREUR_SYNTAXIQUE, "Syntaxique erreur sur ligne 3.");
			}
		}
		
		//Extraire les sommets du graphe
		if ((uiNumFichierLigne > 3) && (uiNumFichierLigne <= (4 + uiNBSommets))) {
			if (strstr(buffer, "]") == nullptr) {
				char ** ppcElement = FICLireValeur(buffer, ' ', 1);
				Graphe.GRAAjouterSommet(atoi(ppcElement[0]));  //Ajouter un sommet

				free(ppcElement[0]);
				free(ppcElement);	
			}
		}
		//Arcs=[
		if (uiNumFichierLigne == 5 + uiNBSommets) {
			if (strstr(buffer, "Arcs=[") == nullptr) {
				char pcMsg[1024];
				//Préparation du message d'erreur
				sprintf_s(pcMsg, "Syntaxique erreur sur ligne %d.", uiNumFichierLigne);
				throw CException(ERREUR_SYNTAXIQUE,pcMsg); 
			}

		}
		
		//Extraire les arcs du graphe
		if ((uiNumFichierLigne > (5 + uiNBSommets)) && (uiNumFichierLigne <= (5 + uiNBSommets + uiNBArcs))) {
			if (strstr(buffer, "]") == nullptr) {
				char ** ppcElement = FICLireValeur(buffer, ' ', 2);
				Graphe.GRAAjouterArc(atoi(ppcElement[0]),atoi(ppcElement[1]));	//

				for (int i=0;i<2;i++) {
					free(ppcElement[i]);
				}
				free(ppcElement);	
			}
		}

		uiNumFichierLigne++;

	}

	Graphe.GRAModifierNBSommets(uiNBSommets);
	Graphe.GRAModifierNBArcs(uiNBArcs);

	cout << "Le graphe associé est créé!\n" << endl; 
	return Graphe;
}

/****************************************
*  @brief: lire les elements de chaque ligne dans le fichier
*  @param:  pcLine
*  @param:  cDelimiter
*  @param:  uiNBElement
*  @return : le tableau qui est utilise pour stocker  de chaque searches
****************************************/
char ** CFichier::FICLireValeur(char * pcLigne, char cDelimiter, unsigned int uiNBElement)
{
	char **ppcLigneElement = (char **)malloc((uiNBElement) * sizeof(char *));
	char * pcStart = pcLigne;
	char * pcEnd = pcLigne;

	for (unsigned int uiBoucleI = 0; uiBoucleI < uiNBElement; uiBoucleI++) {
		while (*pcEnd != '\0' && *pcEnd != cDelimiter) { 	   //search "=" or "\0"  
			pcEnd++;
		}
		
		char pcTemp[100];
		unsigned int uiLength = pcEnd - pcStart;

		memcpy(pcTemp, pcStart, uiLength);	//copy the string with length  
		pcTemp[uiLength] = '\0';

		pcStart = pcEnd;
		pcStart++;
		pcEnd++;

		ppcLigneElement[uiBoucleI] = _strdup(pcTemp);

	}

	return ppcLigneElement;
}

/****************************************
*  @brief: detruire la memoire du graphe pendant qu'on lire le fichier
*  @param:  rien
*  @return : rien
****************************************/
void CFichier::FICDetruireGraphe()
{
	Graphe.GRADetruireMemoire();
}
