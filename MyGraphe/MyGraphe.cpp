// MyGraphe.cpp : définit le point d'entrée pour l'application console.
//


#include "stdafx.h"
#include "CFichier.h"
#include "COperationGraphe.h"
#include "CTestsUnitaires.h"

int main(int argc, char* argv[])
{

	if(argc == 2){
		
		//Creér un objet CFichier pour passer le nom de fichier
		CFichier * FICFichier = new CFichier(argv[1]); 

		// Declaration des graphes
		//Stocker le graphe lit par le fichier
		CGraphe * GRAGraphe = new CGraphe();
		//Pour stocker le nouveau graphe inversé
		CGraphe * GRAGrapheNonOriente = new CGraphe();

		CGraphe * GRAGrapheDual = new CGraphe();

		//Générer l'operation pour inverser le graphe
		COperationGraphe * OPGOperation = new COperationGraphe();;

		try{
			//Lire le fichier et creér le graphe associé
			*GRAGraphe = FICFichier->FICLire_Fichier();

			//Afficher le graphe associé à écran
			cout <<  "\n-----------GRAPHE INITIAL----------- \n" << endl;
			GRAGraphe->GRAAfficherGraphe();
			
			//Convertir la graphe orienté à non orienté
			*GRAGrapheNonOriente = OPGOperation->OPGConvertirGraphe(*GRAGraphe);

			//Afficher le graphe non orienté à écran
			cout <<  "\n---------GRAPHE NON ORIENTE--------- \n" << endl;
			GRAGrapheNonOriente->GRAAfficherGrapheNonOriente();

			//Calculer le graphe dual
			*GRAGrapheDual = OPGOperation->OPGCalculerGrapheDual(*GRAGrapheNonOriente);
			
			//Afficher le graphe dual à écran
			cout <<  "\n------------GRAPHE DUAL------------- \n" << endl;
			GRAGrapheDual->GRAAfficherGrapheDual();
		}
		catch(CException EXCLevee){
			cout << "Exception numero " <<EXCLevee.EXCLireValeur() << ": "<< EXCLevee.EXCLireMessage() << endl;

		}
		//Libérer mémoire
		GRAGraphe->GRADetruireMemoire();
		GRAGrapheNonOriente->GRADetruireMemoire();
		GRAGrapheDual->GRADetruireMemoire();

		delete GRAGraphe;
		delete GRAGrapheNonOriente;
		delete GRAGrapheDual;

		//Libérer le mémoire du graphe temporaire pendant qu'on lire le fichier
		FICFichier->FICDetruireGraphe();  
		delete FICFichier;

		//Libérer le mémoire du graphe temporaire pendant qu'on inverse le graphe
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
	
	//Détecter les fuites de mémoire
	_CrtDumpMemoryLeaks();

    return 0;
	
}

