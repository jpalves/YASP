#include "algo_ciclicas.h"


struct arco{

	double arcosup [2];
	double arcoprob[2];
}; 

void main(){		
	Random r;
	int dim;
	int k = 0,j;
	
	arco ar[] = { {{21.127,22.2658,67.7888,78.1951,89.835},{,,,,}}  ,{{1,5},{0.5,0.5}} , {{1,17},{0.5,0.5}} , {{2,9},{0.5,0.5}},{{2,17}, {0.5,0.5}},{{1,2}, {0.5,0.5}}, {{10,20}, {0.5,0.5}} };
	Rede rede(5,10);


 	for(int i=0;i<rede.dist.getDim();i++){
 		rede.dist[i].setDim(5); 		
 		for(int j=0;j<rede.dist[i].getDim();j++){ 
 		        rede.dist[i].VarArcoSup [j]  = ar[i].arcosup [j] ;
 		        rede.dist[i].VarArcoProb[j]  = ar[i].arcoprob[j] ;
 	}
 	        rede.dist[i].calculaMedia();
 	}	
 	rede.distAux=rede.dist;
 	//for(int i=0;i<a.getDim();i++) ordena(a[i].VarArcoSup,0,a[i].VarArcoSup.getDim()-1,a[i].VarArcoProb);
	//rede.dist[0].ordena(0,rede.dist[0].dim-1);
	rede.terminal = 5;
	rede.inicial = 1;
	
 	/*for(int i=0;i<rede.dist.getDim();i++){
		cout << endl;
 		for(int j=0;j<rede.dist[i].VarArcoSup.getDim();j++){
 			cout<<rede.dist[i].VarArcoSup [j]<<"\t"<<rede.dist[i].VarArcoProb[j]<<endl; 
 		}
 		cout<<" "<<rede.dist[i].VarArcoMedia<<endl;
 	}cout<<" "<<endl;*/
 
 	/*
	a[0].ordena(0,a[0].VarArcoSup.getDim()-1);
 */
	//VarArco  aux,aux1;
	/*
	aux=a[0];
	//aux.setDim(3000);
	//aux1.setDim(3000);
	
	for(int j=0;j<aux.getDim();j++){
 			cout<<aux.VarArcoSup [j]<<"\t"<<aux.VarArcoProb[j]<<endl; 
 	}cout<<"------> "<<aux.VarArcoMedia<<endl;
	
	*/
	int ppoint[] ={2,2,4,6,8,8};
	int prpoint[]={8,7,6,4,2,1};
	int pant[]   ={2,3,4,3,2,1,,,,};
	int psuc[]   ={2,3,4,1,4,3,5};
	
	
	
	
	
	for(int i=0;i<rede.point.getDim();i++) rede.point[i] = ppoint[i];
	for(int i=0;i<rede.rpoint.getDim();i++) rede.rpoint[i] = prpoint[i];
	for(int i=0;i<rede.suc.getDim();i++) rede.suc[i] = psuc[i];
	for(int i=0;i<rede.ant.getDim();i++) rede.ant[i] = pant[i];
	rede.MaxSup = 100;
	
			rede.trajecto.meteAZero(rede.trajecto.getDim());  	//limpeza dos vectores
			rede.rotulo.meteAZero(rede.rotulo.getDim());
	
	rede.rotula_ant();
	
	
	
	cout<<"rotulos no fim do rotula sem inicialização"<<endl;
	for(int i=0;i<rede.rotulo.getDim();i++) cout<< rede.rotulo[i]<<" ";
	cout<<endl;
	
 	
 	cout<<"trajecto no fim do rotula sem inicialização"<<endl;
	for(int i=0;i < rede.trajecto.getDim();i++) cout <<rede.trajecto[i]<<" ";
	cout<<endl;
	
	rede.trajecto.meteAZero(rede.trajecto.getDim());  	//limpeza dos vectores
	rede.rotulo.meteAZero(rede.rotulo.getDim());
	
	rede.rotula();
	
	cout<<"rotulos no fim do rotula com inicialização"<<endl;
	for(int i=0;i<rede.rotulo.getDim();i++) cout<< rede.rotulo[i]<<" ";
	cout<<endl;
	
	cout<<"trajecto no fim do rotula com inicialização"<<endl;
	for(int i=0;i < rede.trajecto.getDim();i++) cout <<rede.trajecto[i]<<" ";
	cout<<endl;

	
}
