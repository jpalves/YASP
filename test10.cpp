#include "algo_ciclicas.h"
#include <iomanip.h>

struct arco{

	double arcosup [2];
	double arcoprob[2];
}; 

void main(){		
	Random r;
	int dim;
	int k = 0,j;
        /*
	arco ar[] = { 7.155607467553481982,
                      16.53407097759984623,
                      16.73149929515354018,
                      17.59531450285466647,
                      50.5258070301557396,

                      0.141451799847382681,
                      0.3896543487909919778,
                      0.3210289008153230928,
                      0.01743987003588610973,
                      0.1304250805104161248,

                      25.90647801568417208,
                      46.10379913568120003,
                      47.3015042858434569,
                      73.07108770033137546,
                      93.97704250155413774,

                      0.2790550390801770364,
                      0.1093544043302538266,
                      0.2193059721559039998,
                      0.1583866703456013603,
                      0.233897914088063763,

                      1.060594223919467449,
                      13.31744064188502996,
                      56.26818442909703322,
                      62.54729839124421176,
                      96.33306179645775558,

                      0.3269618907227214155,
                      0.3623336617503749579,
                      0.008807418824950874122,
                      0.2750380145065416948,
                      0.02685901419541104202,

                      11.30729854044208516,
                      33.76667311013831352,
                      42.21359254191946064,
                      50.59991088081149258,
                      71.7775044345244595,

                      0.1656544083614499563,
                      0.08306235647033434477,
                      0.2465945859745531654,
                      0.2515021972110353943,
                      0.2531864519826271254,

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
};        */
        arco ar[] = {  80492368.84817768634,
                       83384451.47578242421,
                       0.3819892584243245737,
                       0.6180107415756753708,

                       21394720.02661664411,
                       22775970.4279657416,
                       0.56149923203960872,
                       0.4385007679603913355,

                       37806934.12707348913,
                       63445172.77633891254,
                       0.3650970898168101053,
                       0.6349029101831898947,

                       13135787.00952599011,
                       22298898.3900982216,
                       0.4833824704423771434,
                       0.5166175295576228566,

                       3951667.366538113914,
                       62349936.19433370232,
                       0.2796727780463353352,
                       0.7203272219536646092,

                       40871759.23419924826,
                       41455423.49234582484,
                       0.6128262359048788354,
                       0.3871737640951211645,

                       16104453.43332934566,
                       41776829.15278171003,
                       0.7745576475154549722,
                       0.2254423524845450555,

                       25317529.05932197347,
                       65423979.15977612138,
                       0.5970390697608581876,
                       0.4029609302391418679,

                       26664882.64842538163,
                       36573346.89902453124,
                       0.4745585160951367732,
                       0.5254414839048632268,

                       81396748.237637043,
                       98760665.25437884033,
                       0.2160026166707043616,
                       0.783997383329295583,
};
	Rede rede(5,10),rede1(5,10);


 	for(int i=0;i<rede.dist.getDim();i++){
 		rede.dist[i].setDim(2);
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
