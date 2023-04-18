#include "rand.h"
#include "array.h"
#include <iostream.h>
#include <stdio.h>
#include <conio.h>

#define MIN(a,b) (a > b ? b : a)
#define PROBSUP 1
#define ARCOSUP 2
#define MAXINT  0x7FFFFFFF

//declaração do objecto que contém as definicões de suporte dos arcos
struct VarArco{ 
	//---------------------declaração dos campos da estrutura de dados--------------------------
	int	dim;		//dimensão do objecto
	Array <double> 	VarArcoSup,  	//pontos do suporte
			VarArcoProb; 	//probabilidades dos pontos do suporte
	double 		VarArcoMedia;
	//--------------------------------------fim-------------------------------------------------
	
	
	//--------declaração dos métodos "funções" que actuam sobre a estrutura de dados------------
	inline 	void 		modificaDim(int dim){			//falsificador da dimensão
					if(dim < this->dim) this->dim = dim;
	}	
	inline 	void 		recovDim(){dim = VarArcoSup.getDim();}     	//devolve a dimensão dos vectores a este objecto
		void 		meteAZero(int i);				//limpa o lixo dos vectores
		//void 		ordena(int lo,int up);
		void 		ordena(int lo,int up);
		void 		calculaMedia();	   					
	inline 	void 		setDim(int dim){ 				//dimensiona os vectores
					this->dim = dim;
					VarArcoSup.setDim (this->dim);  	//atribuição da dim ao vector dos pontos do suporte
					VarArcoProb.setDim(this->dim);  	//atribuição da dim ao vector das probabilidades dos pontos do suporte
	}
	inline 	int	getDim(){return this->dim;}			//devolve a dim deste "this->" objecto 
		
	//--------------------------------------fim-------------------------------------------------
	
	VarArco(VarArco &in);
	VarArco(){}
	//----declaração do operador que permite a passagem da estrutura como arg. de saida---------
	VarArco operator  =(VarArco in);
	//--------------------------------------fim-------------------------------------------------
};//fim da declaração do objecto que contém as definicões de suporte dos arcos


//em esboço
//--------------------------------------------------------------------------------------------------      
void VarArco::ordena(int lo, int up){
	register int i, j;
     	double temp,temp1;

	while( up > lo){
		i = lo; j = up; temp = VarArcoSup[lo];temp1 = VarArcoProb[lo];
		
		while ( i < j ) {
	       		for (;VarArcoSup[j] > temp; j-- );
	       		for ( VarArcoSup[i] = VarArcoSup[j],VarArcoProb[i] = VarArcoProb[j]; i < j && VarArcoSup[i] <= temp; i++ );
	       		VarArcoSup[j] =  VarArcoSup[i];
	       		VarArcoProb[j] = VarArcoProb[i];
	  	}
	  	
	  	VarArcoSup [i] = temp;
	  	VarArcoProb[i] = temp1;
	  	
	  	if ( i-lo < up-i ) {
	     		ordena(lo,i - 1);
	     		lo = i + 1;
	  	}else{
	     		ordena(i + 1,up);
	     		up = i - 1;
	  	}
     	}
}
//--------------------------------------------------------------------------------------------------
void VarArco::calculaMedia(){
 
 	VarArcoMedia=0;
	for(register int i=0;i < dim ;i++) VarArcoMedia += VarArcoSup[i] * VarArcoProb[i];		
}
//--------------------------------------------------------------------------------------------------
void VarArco::meteAZero(int i){
	
	switch(i){
		case 1:	VarArcoProb.meteAZero(dim);
         	break;
         	case 3:	VarArcoSup .meteAZero(dim);        	
         	  	VarArcoProb.meteAZero(dim);	
         	break;
	}
}
//--------------------------------------------------------------------------------------------------
//está em análise
VarArco VarArco::operator = (VarArco in){

	dim = in.dim;                                   //entrega da dimensão
	VarArcoMedia = in.VarArcoMedia;
	VarArcoSup. setDim(dim);   
	VarArcoProb.setDim(dim);
	in.VarArcoSup .copiaPara(VarArcoSup);
	in.VarArcoProb.copiaPara(VarArcoProb);
	//cout<<"fui igualado"<<endl;
	return *this;
}	


VarArco::VarArco(VarArco &in){

	dim = in.dim;                                   //entrega da dimensão
	VarArcoMedia = in.VarArcoMedia;
	VarArcoSup. setDim(dim);   
	VarArcoProb.setDim(dim);
	in.VarArcoSup .copiaPara(VarArcoSup);
	in.VarArcoProb.copiaPara(VarArcoProb);
	//cout<<"fui igualado"<<endl;
	//return *this;
}	


//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
//estrutura da rede
struct Rede{
	int		n_nos, 
			n_arcos,
			MaxSup,//ainda não sei o que fazer
			terminal,inicial;	
	
	//
	Array <int>	point, 
			rpoint, 
			suc, 
			ant, 
			listRotulos, 
			trajecto;
	Array <double> 	rotulo;
	Array <VarArco> dist,
			distAux;
	
	//construtor
	Rede(int n_nos,int n_arcos):n_nos(n_nos),n_arcos(n_arcos){
		
		point.      setDim(n_nos+1); 			//atribuição das dimensões aos vectores  
		rpoint.     setDim(n_nos+1);      
		suc.        setDim(n_arcos);         
		ant.        setDim(n_arcos);         
		listRotulos.setDim(n_nos+1);
		trajecto.   setDim(n_nos);  
		rotulo.     setDim(n_nos);
		dist.       setDim(n_arcos);
		//distAux.      setDim(n_arcos);
		
		//trajecto.meteAZero(trajecto.getDim());  	//limpeza dos vectores
		//rotulo.meteAZero(rotulo.getDim());
		
		//listRotulos[0] = suc.getDim();	
		//for(int i=1;i < listRotulos.getDim();i++) listRotulos[i]=0;

	}
	//-----------------------------------Métodos-----------------------------------------------
	void		inicializaRotulos();
	double		actualizaRotulos(int novo);
	double		actualizaRotulos_ant(int novo);
	int             MineCasa(int inicio,int fim,double &aux);
	//void actualizaRotulos(int novo);
	void		rotula();
	void		rotula_ant();
	VarArco		comparaDois    (int a,VarArco *b);
	VarArco 	comparaDois_ant(int a,VarArco *b);
};

/*
int MineCasa(double *a,double &aux){
	int casa=0;
	aux = a[0];
	for(int m = 1;m < 4;m++){ //4 porque sim mas é até à dimensão do vectorMedia
		if(aux >  MIN(aux,a[m]) ){
				aux = MIN(aux,a[m]);
				casa = m;
		}
	}
	return casa;
}*/

int Rede::MineCasa(int inicio,int fim,double &aux){
	int casa=0;
	
	//cout <<inicio<<" "<<fim<<endl;
	aux = dist[inicio -1].VarArcoMedia;
	for(int m =inicio;m < fim ; m++){ //4 porque sim mas é até à dimensão do vectorMedia
		if(aux >  MIN(aux,dist[m].VarArcoMedia) ){
				aux = MIN(aux,dist[m].VarArcoMedia);
				casa = m;
		}
	}
	return casa;
}


void Rede::inicializaRotulos(){
	register int inicio,fim,k,i,l,inicio_j,fim_j,m,casaMinMedia,j,novo,cauda,aux;
	register double MinMedia;
	
	
	cout<<"entrei"<<endl;
	for (l = 0; l < n_nos; l++)rotulo[l] = MAXINT;
	
	rotulo[terminal-1] = 0;
	
	for(int i=0;i < listRotulos.getDim();i++) listRotulos[i]=0;
		
	cauda = terminal;
	listRotulos[cauda] = MAXINT;
	j = terminal;
	
	while(j != MAXINT){ //j =/= MAXINT
		inicio = rpoint[j];
		
		fim    = rpoint[j-1]-1;
		
		for(int k = inicio - 1;k < fim;k++){
			
			novo = ant[k];
			
			for (l = point[novo-1] - 1 ; l < point[novo]-1;l++){
				
			   if (suc[l] == j){
				if (dist[l].VarArcoMedia + rotulo[j-1] < rotulo[novo-1]){
			    		rotulo[novo-1] = dist[l].VarArcoMedia + rotulo[j-1];
			    				    		
			    		trajecto[novo-1]= j;	
					
					if (listRotulos[novo] == 0){/*...e esse nó nao estava na lista logo é inserido*/
						listRotulos[cauda] = novo;
						cauda = novo;
					}
				}
			    }
			}		
		}
		
		listRotulos[cauda] = MAXINT;
		/* Remocao de um no ,no principio, da lista para ser usado na iteracao seguinte */
		aux = j;
		//if(listRotulos[j]==inicial) return;
       		j = listRotulos[j];
       		listRotulos[aux] = 0;
       		//cout<<"j="<<j<<" ";
       		//cout<<endl;
       		
       		
	}
	cout<<"sai"<<endl;
}


double Rede::actualizaRotulos(int novo){
	/*register*/ int inicio,fim,i,m;
	VarArco aux;

	inicio = (int)point[novo - 1];					
	fim    = (int)point[novo]-1;     
	
	for(i = inicio-1;i < fim;i++){
		//fim_i = suc[i];
		//cout<<i<<" "<<suc[i]<<" "<<endl;
	    	for(m = 0;m < dist[i].getDim();m++){distAux[i].VarArcoSup[m] = dist[i].VarArcoSup[m] + rotulo[suc[i]-1];
	    						//cout<<"i="<<i<<endl;
	    						//cout<<"dist[i].VarArcoSup[0]"<<" "<<distAux[i].VarArcoSup[0]<<endl;
							//cout<<"dist[i].VarArcoSup[1]"<<" "<<distAux[i].VarArcoSup[1]<<endl;
		}
		
	}
	
	if(fim==inicio){
		//cout<<"entrei"<<endl;
		//cout<<dist[inicio -1].VarArcoMedia<<" "<<endl;
		return distAux[inicio -1].VarArcoMedia + rotulo[suc[inicio - 1] - 1];
		
	}else    if((fim -inicio) == 1){
			
			//cout<<"entrei no igual 1"<<endl;
			aux = comparaDois(inicio - 1,&distAux[inicio]);
			aux.calculaMedia();
			return aux.VarArcoMedia;
						
		}else{
			aux = comparaDois(inicio - 1,&distAux[inicio]);
			for(m = inicio + 1;m < fim; m++) aux = comparaDois(m,&aux);
			aux.calculaMedia();
			return aux.VarArcoMedia;
		}
		return 0;	
}




void Rede::rotula(){
	int l=0,j= suc[suc.getDim()-1],m = 0,novo,inicio,fim,cauda,aux;
	double a;
	int flag;

	inicializaRotulos();

	/*cout<<"rotulos no fim da inicialização"<<endl;
	for(int i=0;i<rotulo.getDim();i++) cout<< rotulo[i]<<" ";
	cout<<endl;

	cout<<"trajecto no fim da inicialização"<<endl;
	for(int i=0;i < trajecto.getDim();i++) cout <<trajecto[i]<<" ";
	cout<<endl;
	//cout<< rotulo[377]<<endl;*/

	for(int i=0;i < listRotulos.getDim();i++) listRotulos[i]=0;//04__01


	cauda = terminal;
	listRotulos[cauda] = MAXINT;
	j = terminal;
	//cout<<"j="<<j<<" ";
	while(j != MAXINT || j == -1){ //j =/= MAXINT
		inicio = rpoint[j];
		fim    = rpoint[j-1]-1;
		flag = 1;

		for(int k = inicio - 1;k < fim;k++){
			novo = ant[k];
			//cout<<"novo="<<novo<<endl;
			a=actualizaRotulos(novo);
			//cout<<"a="<<a<<endl;
			//if (rotulo[novo-1]>= a)/*O rotulo do no j foi melhorado*/{
			if (rotulo[novo-1] > a){/*foi mudado mim*/
				rotulo[novo-1] = a;
				trajecto[novo-1]= j;

				//cout<<"trajecto[novo]="<<trajecto[novo-1]<<endl;

				if (listRotulos[novo] == 0)/*...e esse nó nao estava na lista logo é inserido*/{
					listRotulos[cauda] = novo;
					cauda = novo;
				}

			}
			else {
				if (rotulo[novo-1]  == a ){
			      		if (trajecto[novo-1] == j){
			     		        flag = 0;
			     		        if (listRotulos[novo] == 0){/*...e esse nó nao estava na lista logo é inserido*/
						        listRotulos[cauda] = novo;
						        cauda = novo;
					        }
					}
				}
			}

		}

		listRotulos[cauda] = MAXINT;
		/* Remocao de um no ,no principio, da lista para ser usado na iteracao seguinte */
		aux = j;
       		j = listRotulos[j];
       		if (flag != 0) listRotulos[aux] = 0;
       		else listRotulos[aux] = -1;
	}
	cout << rotulo[inicial-1]<<endl;
	/*cout<< "nó inicial = "<<inicial<<endl;
        cout<< "nó terminal = "<<terminal<<endl;
        cout<<"trajecto corrigido??"<<endl;
	for(int i=0;i < trajecto.getDim();i++){
		if (trajecto[i]){
			 cout<<"i = "<<i<<"--->";
			 cout <<trajecto[i]<<" "<<endl;
		}
	}
	cout<<endl;*/
	//for (j = 0;j < rotulo.getDim();j++)cout<<rotulo[j]<< " ";
}


void Rede::rotula_ant(){
	int l=0,j = suc[suc.getDim()-1],m = 0,novo,inicio,fim,cauda,aux;
	double a;
	int flag;
		
	//inicializaRotulos();
	for (l = 0; l < n_nos; l++)rotulo[l] = MAXINT;
	
	rotulo[terminal-1] = 0;
	cout<<"sem inicialização"<<endl;
	for(int i=0;i < listRotulos.getDim();i++) listRotulos[i]=0;	 
	
	cauda = terminal;
	listRotulos[cauda] = MAXINT;
	j = terminal;
	//cout<<"j="<<j<<" ";
	while(j != MAXINT || j == -1){ //j =/= MAXINT
		inicio = rpoint[j];
		fim    = rpoint[j-1]-1;
		flag = 1;
		
		for(int k = inicio - 1;k < fim;k++){
			novo = ant[k];
			
			//cout<<"novo="<<novo<<endl;
			
			a=actualizaRotulos(novo);
			//cout<<"a="<<a<<endl;
			if (rotulo[novo-1]>= a)/*O rotulo do no j foi melhorado*/{
				rotulo[novo-1] = a;
				trajecto[novo-1]= j;
				
				//cout<<"trajecto[novo]="<<trajecto[novo-1]<<endl;
				
				if (listRotulos[novo] == 0)/*...e esse nó nao estava na lista logo é inserido*/{
					listRotulos[cauda] = novo;
					cauda = novo;
				}
			}
			else {if (rotulo[novo-1]  == a){//o rótulo não melhora mas pode melhorar outros
			      	if (trajecto[novo-1] == j){
			     	        flag = 0;
			                //cout<<"e igual"<<endl;
			     	        if (listRotulos[novo] == 0){//...e esse nó nao estava na lista logo é inserido
					        listRotulos[cauda] = novo;
					        cauda = novo;
			     	        }
			        }
			        
			     }
			}		
		}
		
		listRotulos[cauda] = MAXINT;
		/* Remocao de um no ,no principio, da lista para ser usado na iteracao seguinte */
		aux = j;
		//if(listRotulos[j]==inicial) return;
       		j = listRotulos[j];
       		//listRotulos[aux] = 0;
       		if (flag != 0) listRotulos[aux] = 0;
       		else listRotulos[aux] = -1;
       		//cout<<"j="<<j<<" ";
	}
	cout << rotulo[inicial-1]<<endl;
	/*cout<< "nó inicial = "<<inicial<<endl;
        cout<< "nó terminal = "<<terminal<<endl;
        cout<<"trajecto corrigido??"<<endl;
	for(int i=0;i < trajecto.getDim();i++){
		if (trajecto[i]){
			 cout<<"i = "<<i<<"--->";
			 cout <<trajecto[i]<<" "<<endl;
		}
	}
	cout<<endl;*/
	//for (j = 0;j < rotulo.getDim();j++)cout<<rotulo[j]<< " ";
}


VarArco Rede::comparaDois(int a,VarArco *b){
	register int k=0,i,j,aDim = distAux[a].getDim(),bDim = b->getDim();
	VarArco  VarMin;
	double aux;
		
	VarMin.setDim(aDim*bDim);
	VarMin.meteAZero(PROBSUP);
		

	if (distAux[a].VarArcoSup[aDim - 1] <= b->VarArcoSup[0]){
		VarMin = distAux[a];
		VarMin.modificaDim(aDim);
		return VarMin; 
	}else{ if ( b->VarArcoSup[bDim - 1] <= distAux[a].VarArcoSup[0]){
			VarMin = *b;
			VarMin.modificaDim(bDim);
			return VarMin;
	
	}else{
		
	//fim alteração 15/11/2004
	for(i = 0;i < aDim;i++){
		VarMin.VarArcoSup[k] = MIN(distAux[a].VarArcoSup[i],b->VarArcoSup[0]);
		for(j = 0;j < bDim;j++){
			aux = MIN(distAux[a].VarArcoSup[i],b->VarArcoSup[j]);
			if(VarMin.VarArcoSup[k] != aux){
				k++;
				VarMin.VarArcoSup[k] = aux;
			}
			VarMin.VarArcoProb[k] += distAux[a].VarArcoProb[i]*b->VarArcoProb[j];
		}k++;
	}VarMin.modificaDim(k);			

        
        
	VarMin.ordena(0,VarMin.getDim()-1);
	//este código não está óptimizado nem acabado
	aux = VarMin.VarArcoSup[0];
	for(i=1;i < VarMin.dim ;i++){
		if(aux == VarMin.VarArcoSup[i]){
			VarMin.VarArcoProb[i]  += VarMin.VarArcoProb[i-1];
			VarMin.VarArcoSup [i-1] = 10*MaxSup;
		}
		aux = VarMin.VarArcoSup[i];
	}
	VarMin.ordena(0,VarMin.getDim()-1);
	
	k = VarMin.getDim();
	for(i = MIN(aDim,bDim)-1;i < VarMin.dim ;i++){
		if(VarMin.VarArcoSup[i] > MaxSup)
		k--;
	}VarMin.modificaDim(k);
	VarMin.calculaMedia();
	return VarMin;
}}
}

void geraProbArcos(Array <double> &p,Random &r){
	double sum=0;
	
	for (int i= 0;i<p.getDim();i++){ p[i]  = (double) r.Rand(); sum  += p[i];}
	for (int i= 0;i<p.getDim();i++)  p[i]  = p[i]/sum;
}
//------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------
//

