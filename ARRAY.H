//Class Array
#ifndef __cplusplus
	#error Tem de compilar em C++ para utilizar o Array <gen�rico>
#endif
#if !defined(__IOSTREAM_H)
	#include <iostream.h>
#endif
#if !defined(__STDLIB_H)
	#include <stdlib.h>
#endif

//--------------------------------------------------------------------------------------------------------
//defini��o da classe Array <Tipo de dados> gen�rico
//--------------------------------------------------------------------------------------------------------
template <class Tipo> class Array{

		//Campos
		Tipo *array;
		int tamanho;
		//m�todos semi-privados
      protected:
		void aloca(int tamanho){

			if(!(int)(array = new Tipo[tamanho])){ //refazer para windows
				cout <<"Erro na Mem�ria"<<endl;
				exit(1);
			}
			this->tamanho=tamanho;
		}

		void remove(){if(array) delete[] array; array = NULL;}
	public:
		//Construtores
		//nulo
		Array(){array = NULL;tamanho=0;}
		//normal
		Array(int tamanho){aloca(tamanho);}
		//c�pia do objecto
		Array(Array<Tipo> &in);

		//destrutor
	       ~Array(){remove();}

		//m�todos
		//para variar a dimens�o durante o programa (depois de declarado)
		inline  void		setDim   (int tamanho){remove();aloca(tamanho);}
			void		meteAZero(int dim); 
			void		copiaPara(Array <Tipo> &in);
		//devolve a dimens�o
		inline  int	getDim   (){return tamanho;}
		inline  Tipo * 	       &cArray   (){return array;}
		
		//operadores reescritos
		//permite acesso aos elementos atraves do operador deslocamento (a[i])
		Tipo 		   &operator [](int i){return array[i];}
		Array<Tipo> 	    operator  =(Array <Tipo> in);
		

};
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//c�pia do objecto
template <class Tipo> Array<Tipo>::Array(Array<Tipo> &in){
	
       			aloca(in.tamanho);
       			for(register int i = 0;i < tamanho;i++) *(array+i) = *(in.array+i);
}
//--------------------------------------------------------------------------------------------------------
template <class Tipo> Array<Tipo> Array<Tipo>::operator  = (Array <Tipo> in){
			register Tipo *ptr1 = in.array;
			
			remove();
			aloca(in.tamanho); //fica com o tamanho do outro
			for(register Tipo *ptr = array;(ptr - array) -  tamanho;) *ptr ++ = *ptr1 ++;
	
			return *this;
}
//--------------------------------------------------------------------------------------------------------
template <class Tipo> void Array<Tipo>::meteAZero(int dim){
			register Tipo *ptr = array; 

			for(;(ptr - array) -  dim;) *ptr ++  =  (Tipo)NULL;
}
//--------------------------------------------------------------------------------------------------------
template <class Tipo> void Array<Tipo>::copiaPara(Array <Tipo> &in){
			register int i=0;
			
			for(;in.tamanho-i&&tamanho-i;i++) *(in.array+i) = *(array+i);
			for(;i<in.tamanho;) *(in.array + i++) = (Tipo)NULL;
}