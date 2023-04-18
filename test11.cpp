#include "algo_ciclicas.h"
#include <iomanip.h>

struct arco{

	double arcosup [5];
	double arcoprob[5];
}; 

void main(){		
	Random r;
	int dim;
	int k = 0,j;

	arco ar[] = { 8.850943883147772695,
		      12.66982904301719337,
                      17.93352237644920422,
		      57.99473484884824614, 
                      70.03169227136105235, 

                      0.1079412194275818221,
                      0.135057927316632076, 
                      0.3377632851160437544,
                      0.1561915800102114671, 
                      0.2630459881295308944,

                      18.17563341073125116,
		      24.10181097618812274,
		      38.57382473223233888,
		      80.65091514928521122,
                      90.2654955725338084,

                      0.253018879353296644,
                      0.3115419752146060262,
                      0.1977339332668097138,
                      0.1037596152339003569,
                      0.1339455969313872174,

                      42.64087523162385196,
		      72.66214391488166768,
                      78.49641904595689823,
                      80.55007586268477837,
                      89.04216158204762621,

                      0.1198194245045814538,
                      0.4305650765484586584,
                      0.0640161889149184482,
                      0.319184341188311016,
                      0.06641496884373042364,

                      15.68178893129383411,
			26.46384405402091034,
			32.38281026165532239,
			46.53119707655422132,
			99.90625771901250118,
			
		     0.2820093698844172159,
		     0.2578594288756245745,
		     0.1603457585484095171,
		     0.1527876314638492439,
		     0.1469978112276994486,

                     27.5730600714620877,
                     55.62481347392890996,
                     72.29415991071010694,
                     82.4727903407702172,
                     84.16538287959187414,
                     
                     0.1345466671110555901,
                     0.4370498282167886717,
                     0.1193739866381776371,
                     0.04301525038911322568,
                     0.2660142676448649102,

                     11.95787066522935582,
                     15.16052525238145776,
                     62.2452786930942139,
                     64.88918466584038924,
                     65.33243252368001208,
                     
                     0.2917848786530141125,
                     0.1128884347568793467,
                     0.4059064936550246805,
                     0.06472934178950597028,
                     0.1246908511455758345,

                     12.24695056147103855,
                     37.15936894508995891,
                     80.63409472527776245,
                     83.38312446986863336,
                     85.89391868512470296,
                     
                     0.09861944789283356994,
                     0.2624903829920422482,
                     0.2945234457353843038,
                     0.2778888748188614866,
                     0.06647784856087834982,

                     4.560486899586507548,
                     60.05730127241864835,
                     60.12279272594554414,
                     96.06163946261202113,
                     97.20687969918523663,
                     0.09132941445215127241,
                     0.3458381165324539985,
                     0.01238108466771067895,
                     0.495175947012941986,
                     0.05527543733474209186,

                     12.32980702382740468,
                     15.75722123606996661,
                     59.33988854087420606,
                     70.61852724980994367,
                     78.71114743983166306,
                     0.02185104328482951816,
                     0.3215683125292245204,
                     0.04110007116933506177,
                     0.3441637973312350329,
                     0.2713167756853758772,

                     4.719971489794540176,
                     8.210246939493863749,
                     18.94333061900533011,
                     41.9518050444200199,
                     51.45404789467669104,
                     0.1883110076756953632,
                     0.3232298024713791684,
                     0.2533236509496327171,
                     0.1812968517029928395,
                     0.05383868720029988398,
};
	Rede rede(5,10),rede1(5,10);


 	for(int i=0;i<rede.dist.getDim();i++){
 		rede.dist[i].setDim(5);
 		for(int j=0;j<rede.dist[i].getDim();j++){ rede.dist[i].VarArcoSup [j]  = ar[i].arcosup [j] ;rede.dist[i].VarArcoProb[j]  = ar[i].arcoprob[j] ;}
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

	int ppoint[] ={1,2,5,9,10,11};
	int prpoint[]={11,8,6,5,4,1};
	int pant[]   ={2,3,4,3,2,1,3,2,3,5};
	int psuc[]   ={2,1,3,5,1,2,4,5,5,1};
	
	
	
	
	
	for(int i=0;i<rede.point.getDim();i++) rede.point[i] = ppoint[i];
	for(int i=0;i<rede.rpoint.getDim();i++) rede.rpoint[i] = prpoint[i];
	for(int i=0;i<rede.suc.getDim();i++) rede.suc[i] = psuc[i];
	for(int i=0;i<rede.ant.getDim();i++) rede.ant[i] = pant[i];
	rede.MaxSup = 999999;
	
			rede.trajecto.meteAZero(rede.trajecto.getDim());  	//limpeza dos vectores
			rede.rotulo.meteAZero(rede.rotulo.getDim());


	//cout<<setprecision(30)<<setiosflags(ios::fixed)<<endl;
        for(int i=0;i < rede.dist.getDim();i++){
                for(int j = 0;j<rede.dist[i].getDim();j++)
                        cout<<rede.dist[i].VarArcoSup[j]<<" "<<rede.dist[i].VarArcoProb[j]<<endl;
                        cout<<endl<<rede.dist[i].VarArcoMedia<<endl<<"novo sup"<<endl;
        }

        rede1.MaxSup=999999;
        rede1.dist     = rede.dist;
        rede1.distAux  = rede1.dist;
        rede1.suc      = rede.suc;
        rede1.ant      = rede.ant;
        rede1.point    = rede.point;
        rede1.rpoint   = rede.rpoint;
        rede1.terminal = rede.terminal;
        rede1.inicial  = rede.inicial;


	rede.rotula();
        cout<< "rotulo[inicial] = "<<rede.rotulo[rede.inicial-1]<<endl;
	cout<<endl;

	
	cout<<"rotulos no fim do rotula com inicialização"<<endl;
	for(int i=0;i<rede.rotulo.getDim();i++) cout<< rede.rotulo[i]<<" ";
	cout<<endl;


 	cout<<"trajecto no fim do rotula com inicialização"<<endl;
	for(int i=0;i < rede.trajecto.getDim();i++) cout <<rede.trajecto[i]<<" ";
	cout<<endl;

	rede1.trajecto.meteAZero(rede.trajecto.getDim());  	//limpeza dos vectores
	rede1.rotulo.meteAZero(rede.rotulo.getDim());


	rede1.rotula_ant();

        cout<< "rotulo[inicial] = "<<rede1.rotulo[rede1.inicial-1]<<endl;
	cout<<endl;

	cout<<"rotulos no fim do rotula sem inicialização"<<endl;
	for(int i=0;i<rede1.rotulo.getDim();i++) cout<< rede1.rotulo[i]<<" ";
	cout<<endl;

	cout<<"trajecto no fim do rotula sem inicialização"<<endl;
	for(int i=0;i < rede1.trajecto.getDim();i++) cout <<rede1.trajecto[i]<<" ";
	cout<<endl;

	
}
