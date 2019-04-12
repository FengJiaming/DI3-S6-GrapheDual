#include "stdafx.h"
#include "COperationGraphe.h"

/****************************************
*  @brief: constructeur par default
*  @param:  rien
*  @return : rien
****************************************/
COperationGraphe::COperationGraphe(void)
{
}

/****************************************
*  @brief: destructeur
*  @param:  rien
*  @return : rien
****************************************/
/*
COperationGraphe::COperationGraphe(COperationGraphe & graGrapheOperation) : CGraphe(graGrapheOperation)
{
}
*/
COperationGraphe::~COperationGraphe(void)
{
}

/****************************************
*  @brief: Operation pour Inverser un graphe
*  @param:  GRAGraphe
*  @return : CGraphe    le graphe inverse
****************************************/
CGraphe & COperationGraphe::OPGInverserGraphe(CGraphe & GRAGraphe)
{
	//Extraire les sommets du graphe initial
	CSommet ** ppOPGSommets = GRAGraphe.GRALireSommets();
	unsigned int uiOPGNBSommet = GRAGraphe.GRALireNBSommets();

	// Creation des sommets
	for (unsigned int uiBoucleSommets = 0 ; uiBoucleSommets < uiOPGNBSommet ; uiBoucleSommets++)
		OperationGrapheInverse.GRAAjouterSommet(ppOPGSommets[uiBoucleSommets]->SOMLireNumSommet());

	// Creation des arcs
	for (unsigned int uiBoucleSommets = 0 ; uiBoucleSommets < uiOPGNBSommet ; uiBoucleSommets++) {
		
		//Extraire les arcs partant des sommets
		CArc ** ppOPGArcPartant = ppOPGSommets[uiBoucleSommets]->SOMLireArcsPartant();
		unsigned int uiNBArcPartant = ppOPGSommets[uiBoucleSommets]->SOMLireNBArcPartant();

		//Inverser les arcs de chaque sommets
		for (unsigned int uiBoucleArcs = 0 ; uiBoucleArcs < uiNBArcPartant ; uiBoucleArcs++) {
			unsigned int uiArcInverse = ppOPGArcPartant[uiBoucleArcs]->ARCLireDestination();
			OperationGrapheInverse.GRAAjouterArc(uiArcInverse, ppOPGSommets[uiBoucleSommets]->SOMLireNumSommet());
		}
	}
	cout << "Tous les arcs du graphe est inversé!" << endl;
	return OperationGrapheInverse;
}

/****************************************
*  @brief: Operation pour convertir un graphe à  graphe non orienté
*  @param:  GRAGraphe
*  @return : CGraphe    le graphe non orienté
****************************************/
CGraphe & COperationGraphe::OPGConvertirGraphe(CGraphe & GRAGraphe)
{
	//Copier du graphe
	OperationGraphe = GRAGraphe;

	CSommet ** ppOPGSommets = OperationGraphe.GRALireSommets();
	unsigned int uiOPGNBSommet = OperationGraphe.GRALireNBSommets();
	
	//Ajouter les arcs
	for (unsigned int uiBoucleSommets = 0 ; uiBoucleSommets < uiOPGNBSommet ; uiBoucleSommets++){

		unsigned int uiNBArcArrivant = ppOPGSommets[uiBoucleSommets]->SOMLireNBArcArrivant();
		for (unsigned int uiBoucleArcs = 0 ; uiBoucleArcs < uiNBArcArrivant ; uiBoucleArcs++) {
			CArc ** ppOPGArcArrivant = ppOPGSommets[uiBoucleSommets]->SOMLireArcsArrivant();
			unsigned int uiNumArrivee = ppOPGArcArrivant[uiBoucleArcs]->ARCLireDestination();
			if (OperationGraphe.GRATrouverArcPartant(ppOPGSommets[uiBoucleSommets], uiNumArrivee) == nullptr){
				CArc * ARCPartant = new CArc(uiNumArrivee);
				ppOPGSommets[uiBoucleSommets]->SOMAjouterArcPartant(ARCPartant);
			}
		}

		unsigned int uiNBArcPartant = ppOPGSommets[uiBoucleSommets]->SOMLireNBArcPartant();
		for (unsigned int uiBoucleArcs = 0 ; uiBoucleArcs < uiNBArcPartant ; uiBoucleArcs++) {
			CArc ** ppOPGArcPartant = ppOPGSommets[uiBoucleSommets]->SOMLireArcsPartant();
			unsigned int uiNumPartant = ppOPGArcPartant[uiBoucleArcs]->ARCLireDestination();
			if (OperationGraphe.GRATrouverArcArrivant(ppOPGSommets[uiBoucleSommets], uiNumPartant) == nullptr){
				CArc * ARCPartant = new CArc(uiNumPartant);
				ppOPGSommets[uiBoucleSommets]->SOMAjouterArcArrivant(ARCPartant);
			}
		}
	}
	return OperationGraphe;
}

/****************************************
*  @brief: Operation pour calculer le graphe dual d'un graphe donné
*  @param:  GRAGraphe
*  @return : CGraphe    le graphe dual
****************************************/
CGraphe & COperationGraphe::OPGCalculerGrapheDual(CGraphe & GRAGraphe)
{
	
	CSommet ** ppOPGSommets = GRAGraphe.GRALireSommets();
	unsigned int uiOPGNBSommet = GRAGraphe.GRALireNBSommets();

	unsigned int puiArrayA[50], puiArrayB[50]; //Pour stocker séparément le premier numéro de sommet et le deuxième numéro de sommet
	unsigned int uiNBSommetDual = 0;	//Incrément de nombre du sommet
	bool flag = true;
	//Creation des sommets dans le graphe dual.
	for(unsigned int uiBoucleSommets = 0 ; uiBoucleSommets < uiOPGNBSommet ; uiBoucleSommets++ ) {
		//Parcourir tous les arcs partants de 
		unsigned int uiNBArcPartant = ppOPGSommets[uiBoucleSommets]->SOMLireNBArcPartant(); 
		unsigned int uiValeurA,  uiValeurB = 0 ;
		for(unsigned int uiBoucleArcs = 0 ; uiBoucleArcs < uiNBArcPartant ; uiBoucleArcs++ ) {
			CArc ** ppOPGArcPartant = ppOPGSommets[uiBoucleSommets]->SOMLireArcsPartant();

			//Chaque arrête du graphe G correspond à un sommet dans le graphe dual
			uiValeurA = ppOPGSommets[uiBoucleSommets]->SOMLireNumSommet();
			uiValeurB = ppOPGArcPartant[uiBoucleArcs]->ARCLireDestination();

			//Pour éviter la répétition d'insertion,par example A12, A21
			for(int i = 0 ; i < uiNBSommetDual; i++ ) {
				if((uiValeurA == puiArrayB[i]) && (uiValeurB == puiArrayA[i])){
					flag = false;
					break;
				}
				else{
					flag = true;
				}
			}	
			if(flag == true){
				OperationGrapheDual.GRAAjouterSommet(10 * uiValeurA + uiValeurB);	//On transforme l'arrête en le sommet: "1-2"->"12"
				//On stocke chaque chiffre de sommet pour ajouter des arcs
				puiArrayA[uiNBSommetDual] = uiValeurA;
				puiArrayB[uiNBSommetDual] = uiValeurB;
				uiNBSommetDual++;
			}
		}
	}
	
	//Creation des arcs dans le graphe dual
	for(unsigned int uiBoucleI = 0 ; uiBoucleI < uiNBSommetDual ; uiBoucleI++ ) {
		for(unsigned int uiBoucleJ = uiBoucleI + 1 ; uiBoucleJ < uiNBSommetDual ; uiBoucleJ++ ) {
			unsigned int uiNumSommet1 = 10 * puiArrayA[uiBoucleJ] + puiArrayB[uiBoucleJ];	//Numéro de sommet
			unsigned int uiNumSommet2 = 10 * puiArrayA[uiBoucleI] + puiArrayB[uiBoucleI];
			//Si deux arrête Aij et Akn du graphe G sont telles que (i=k)ou(i=n)ou(j=k)ou(j=n) alors il y a une arrête dans le graphe dual.
			//Si i=k
			if(puiArrayA[uiBoucleI] == puiArrayA[uiBoucleJ]) {  
				//Ajouter deux arcs orientés pour représenter un arc non orienté
				OperationGrapheDual.GRAAjouterArc(uiNumSommet1, uiNumSommet2);
				OperationGrapheDual.GRAAjouterArc(uiNumSommet2, uiNumSommet1);
			}
			//Si j=n
			if(puiArrayB[uiBoucleI] == puiArrayB[uiBoucleJ]) {
				OperationGrapheDual.GRAAjouterArc(uiNumSommet1, uiNumSommet2);
				OperationGrapheDual.GRAAjouterArc(uiNumSommet2, uiNumSommet1);
			}
			//Si j=k
			if(puiArrayB[uiBoucleI] == puiArrayA[uiBoucleJ]) {
				OperationGrapheDual.GRAAjouterArc(uiNumSommet1, uiNumSommet2);
				OperationGrapheDual.GRAAjouterArc(uiNumSommet2, uiNumSommet1);
			}
			//Si i=n
			if(puiArrayA[uiBoucleI] == puiArrayB[uiBoucleJ]) {
				OperationGrapheDual.GRAAjouterArc(uiNumSommet1, uiNumSommet2);
				OperationGrapheDual.GRAAjouterArc(uiNumSommet2, uiNumSommet1);
			}
		}
	}
	//Car on utiliser le fonction d'ajouter l'arc orienté, le nombre d'arc doit être divisé par 2
	OperationGrapheDual.GRAModifierNBArcs(OperationGrapheDual.GRALireNBArcs() / 2); 
	
	return OperationGrapheDual;
}

/****************************************
*  @brief: detruire la memoire du graphe pendant qu'on inverse le graphe
*  @param:  rien
*  @return : rien
****************************************/
void COperationGraphe::OPGDetruireGraphe()
{
	OperationGraphe.GRADetruireMemoire();
	OperationGrapheDual.GRADetruireMemoire();
	OperationGrapheInverse.GRADetruireMemoire();
}

