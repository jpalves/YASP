#include "ficheiro.h"
#include "MyString.h"
#include "algo_ciclicas.h"
#include <windows.h>
#include <iomanip.h>

SYSTEMTIME mytime;
double tempo_antes,tempo_depois,tempo_antes1,tempo_depois1;

//------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
template <class T> void ordena(Array <T> &r,int lo,int up,Array <T> &outro){
			int i, j;
     			T temp,temp1;

			while( up > lo){
	  			i = lo; j = up; temp = r[lo];temp1 = outro[lo];
		
	  			while ( i < j ) {
	       				for ( ; r[j] > temp; j-- );
	       				for ( r[i] = r[j],outro[i] = outro[j]; i < j && r[i] <= temp; i++ );
	       				r[j] =  r[i];
	       				outro[j] = outro[i];
	  			}
	  			r[i]     = temp;
	  			outro[i] = temp1;
	  			if ( i-lo < up-i ) {
	     				ordena(r,lo,i - 1,outro);
	     				lo = i + 1;
	  			}else{
	     				ordena(r,i + 1,up,outro);
	     				up = i - 1;
	  			}
     			}
}
//------------------------------------------------------------------------------------------------
void viralo(Array <int> &a,Array <int> &b){
	int aux,aux1;
	
	for(int i = 0;i < a.getDim()/2;i++){
		aux  			= a[i];
		a[i] 			= a[(a.getDim()-1)-i]; 
		a[(a.getDim()-1)-i]	= aux;
		aux  			= b[i];
		b[i] 			= b[(a.getDim()-1)-i]; 
		b[(a.getDim()-1)-i]	= aux;
	}
	
}






void main(int argc,char *argv[]){
	FileStream fonte,saida;
	MyString a;
	Random r;
	int n_nos,n_arcos,inicial,terminal,lixo,i=0,cauda,cabeca,aux;//point_i;
	bool andala =false;
	double l_inf,l_sup,tempo[30];
	Array <int> 	entraArco, //transforma-se em suc depois da ordena��o
			saiArco,
			point,
			rpoint,
			suc;
	Array <VarArco>	dist;


       if(argc<5){
                cout <<"limite sup";
                if(argc<4){ cout <<" j� agora limite inf";
                        if(argc<2)cout <<" que mais faltar� humm";
                }cout <<endl;
                exit(1);
       }

       if(!(fonte.abreFicheiro(argv[1]))){
		        cout << "Erro ao Abrir "<<argv[1]<<endl;
		        exit(1);
       }
       //estou aqui
       if(!(saida.abreFicheiro(argv[2],FileStream::EscritaAcrescentar))){
		        cout << "Erro ao Criar "<<argv[2]<<endl;
		        exit(1);
       }

	for(;;){
		fonte>> a;
	        if(a=="N")fonte>> n_nos;
		if(a=="A"){
			fonte>> n_arcos;
			andala =true;
			entraArco.setDim(n_arcos);
			saiArco.setDim(n_arcos);
		}
		if(andala&&a =="s") fonte >> inicial;
		if(andala&&a =="t") fonte >> terminal;
		if(andala&&a =="a"){
			fonte>>saiArco[i];
			fonte>>entraArco[i];
			fonte>>lixo;
			i++;
		}
		if(fonte.eof())break;
	}
	//------------------------------------------------------------------------------------------------
		point.setDim(n_nos+1);
		rpoint.setDim(n_nos+1);
		dist.setDim(n_arcos);
		
		point[0] = 1;
		for (int i = 1 ;i<point.getDim();i++) point[i] = 0;
	//-------------------------------------------------------------------------------------------------
		
		ordena(saiArco,0,n_arcos-1,entraArco);		
		
		
		cauda = cabeca = 0;
		aux=saiArco[0];
		for(i=1;i<n_arcos;i++){
			if(aux != saiArco[i]){
				cauda = i;
				ordena(entraArco,cabeca,cauda-1,saiArco);
				point[aux] = cauda - cabeca;	
			}
			cabeca = cauda;
			aux = saiArco[i];			
		}ordena(saiArco,cabeca,saiArco.getDim()-1,entraArco);
		
				
		point[aux] = i - cabeca;
		for (int i = 1 ;i<point.getDim();i++) point[i] += point[i-1];
		suc = entraArco;

		for (int i = 0 ;i<rpoint.getDim()-1;i++) rpoint[i] = 0;
		rpoint[n_nos] = 1;

		ordena(entraArco,0,n_arcos-1,saiArco);
		cauda = cabeca = entraArco.getDim()-1;
		aux=entraArco[entraArco.getDim()-1];
		//cout <<aux<<endl;
		for(i = n_arcos - 2;i > -1;i--){
			//cout <<"--->"<<cauda <<" "<<cabeca<<endl;
			if(aux != entraArco[i]){
				cabeca = i;
				//cout <<aux<<"--->"<<cauda <<" "<<cabeca<<endl;
				ordena(saiArco,cabeca+1,cauda,entraArco);
				rpoint[aux-1] =  cauda - cabeca;
			}
			//cout <<"--->"<<cauda <<" "<<cabeca<<aux<<" "<<entraArco[i]<<endl;
			cauda = cabeca;
			aux   = entraArco[i];
			//if(i==0)break;
		}ordena(saiArco,0,cauda,entraArco);
		rpoint[aux-1] = cauda+1;
		//rpoint[n_nos] = 1;
		for (int i = rpoint.getDim()-2 ;i > -1;i--) rpoint[i] += rpoint[i+1];

		viralo(entraArco,saiArco);
		cauda = cabeca = 0;
		aux=entraArco[0];
		for(i=1;i<n_arcos;i++){
			if(aux != entraArco[i]){
				cauda = i;
				ordena(saiArco,cabeca,cauda-1,entraArco);
				//point[aux] = cauda - cabeca;
			}
			cabeca = cauda;
			aux = entraArco[i];
		}//point[aux] = i - cabeca;
		//suc = entraArco;*/
		ordena(saiArco,cabeca,saiArco.getDim()-1,entraArco);
		//------------------------------------------------------------------------------------------------
		//------------------------------------------------------------------------------------------------
                /*   verificar
		cout<<"mete ai o limite inferior "<<endl;
		cin>>l_inf;
		cout<<"mete ai o limite superior "<<endl;
		cin>>l_sup;
                */
                l_inf = atof(argv[3]);
                l_sup = atof(argv[4]);

		for(int w = 0;w < 1;w++){
			for(int i=0;i < dist.getDim();i++){
			  	dist[i].setDim(2);
			  	for(int j = 0;j<dist[i].getDim();j++) dist[i].VarArcoSup[j]=r.NoIntervalo(l_inf,l_sup);
 			  	geraProbArcos(dist[i].VarArcoProb,r);
 			  	//15/11/2004
 			  	dist[i].ordena(0,dist[i].getDim()-1);
 			  	//15/11/2004
 			  	dist[i].calculaMedia();
			}

                        saida<<setprecision(30)<<setiosflags(ios::fixed)<<endl;
                        for(int i=0;i < dist.getDim();i++){
			  	for(int j = 0;j<dist[i].getDim();j++)
 			  	        saida<<dist[i].VarArcoSup[j]<<" "<<dist[i].VarArcoProb[j]<<endl;
                                saida<<endl<<dist[i].VarArcoMedia<<endl<<"novo sup"<<endl;
                        }
			Rede rede(n_nos,n_arcos);
			Rede rede1(n_nos,n_arcos);

			rede.MaxSup=999999;
			rede.dist = dist;
			rede.distAux=rede.dist;
			rede.suc  = suc;
			rede.ant  = saiArco;
			rede.point = point;
			rede.rpoint = rpoint;
			rede.terminal = terminal;
			rede.inicial  = inicial;


			rede1.MaxSup=999999;
			rede1.dist = dist;
			rede1.distAux = rede1.dist;
			rede1.suc     = suc;
			rede1.ant     = saiArco;
			rede1.point   = point;
			rede1.rpoint  = rpoint;
			rede1.terminal = terminal;
			rede1.inicial  = inicial;

                        saida<<endl<<"ficheiro: " <<argv[1]<<endl;
 			GetSystemTime(&mytime);
			tempo_antes  = mytime.wMilliseconds + mytime.wSecond*1000 + mytime.wMinute*60000 + mytime.wHour*3600000;
 			rede.rotula();
 			GetSystemTime(&mytime);
			tempo_depois = mytime.wMilliseconds + mytime.wSecond*1000 + mytime.wMinute*60000 + mytime.wHour*3600000;
			tempo[w] = tempo_depois - tempo_antes;
        		saida<<"tempo com inicializa��o: "<<tempo[w]<<endl;


			GetSystemTime(&mytime);
			tempo_antes1 = mytime.wMilliseconds + mytime.wSecond*1000 + mytime.wMinute*60000 + mytime.wHour*3600000;;
 			rede1.rotula_ant();
 			GetSystemTime(&mytime);
			tempo_depois1 = mytime.wMilliseconds + mytime.wSecond*1000 + mytime.wMinute*60000 + mytime.wHour*3600000;
			tempo[w] = tempo_depois1 - tempo_antes1;
			saida<<"tempo sem inicializa��o: "<<tempo[w]<<endl;
		}
}