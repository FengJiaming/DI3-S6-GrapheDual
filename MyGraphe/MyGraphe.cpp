// MyGraphe.cpp�: d�finit le point d'entr�e pour l'application console.
//


#include "stdafx.h"
#include "CFichier.h"
#include "COperationGraphe.h"
#include "CTestsUnitaires.h"

int main(int argc, char* argv[])
{

	if(argc == 2){
		
		//Cre�r un objet CFichier pour passer le nom de fichier
		CFichier * FICFichier = new CFichier(argv[1]); 

		// Declaration des graphes
		//Stocker le graphe lit par le fichier
		CGraphe * GRAGraphe = new CGraphe();
		//Pour stocker le nouveau graphe invers�
		CGraphe * GRAGrapheNonOriente = new CGraphe();

		CGraphe * GRAGrapheDual = new CGraphe();

		//G�n�rer l'operation pour inverser le graphe
		COperationGraphe * OPGOperation = new COperationGraphe();;

		try{
			//Lire le fichier et cre�r le graphe associ�
			*GRAGraphe = FICFichier->FICLire_Fichier();

			//Afficher le graphe associ� � �cran
			cout <<  "\n-----------GRAPHE INITIAL----------- \n" << endl;
			GRAGraphe->GRAAfficherGraphe();
			
			//Convertir la graphe orient� � non orient�
			*GRAGrapheNonOriente = OPGOperation->OPGConvertirGraphe(*GRAGraphe);

			//Afficher le graphe non orient� � �cran
			cout <<  "\n---------GRAPHE NON ORIENTE--------- \n" << endl;
			GRAGrapheNonOriente->GRAAfficherGrapheNonOriente();

			//Calculer le graphe dual
			*GRAGrapheDual = OPGOperation->OPGCalculerGrapheDual(*GRAGrapheNonOriente);
			
			//Afficher le graphe dual � �cran
			cout <<  "\n------------GRAPHE DUAL------------- \n" << endl;
			GRAGrapheDual->GRAAfficherGrapheDual();
		}
		catch(CException EXCLevee){
			cout << "Exception numero " <<EXCLevee.EXCLireValeur() << ": "<< EXCLevee.EXCLireMessage() << endl;

		}
		//Lib�rer m�moire
		GRAGraphe->GRADetruireMemoire();
		GRAGrapheNonOriente->GRADetruireMemoire();
		GRAGrapheDual->GRADetruireMemoire();

		delete GRAGraphe;
		delete GRAGrapheNonOriente;
		delete GRAGrapheDual;

		//Lib�rer le m�moire du graphe temporaire pendant qu'on lire le fichier
		FICFichier->FICDetruireGraphe();  
		delete FICFichier;

		//Lib�rer le m�moire du graphe temporaire pendant qu'on inverse le graphe
		OPGOperation->OPGDetruireGraphe();
		delete OPGOperation;
		
	}
	else{
		cout << "Veuillez entrer UN nom de fichier" << endl;
	}
	
	//Tests Unitaires
	/*
	CTestsUnitaires TUNITests;	
	TUNITests.TUNIStart();
	*/
	system("pause");
	
	//D�tecter les fuites de m�moire
	_CrtDumpMemoryLeaks();

    return 0;
	
}

