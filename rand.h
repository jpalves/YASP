/*
AUTOR	João Pedro Alves 09/06/2001
VERSAO  1.0
	gerador linear congruencial
	numerical recipes in c (pag 284)
*/

#define TEMPORIZADOR


#define MULTIPLICADOR 1664525L
#define INCREMENTO 1013904223L

#ifndef __MATH_H
	#include <math.h>
#endif
#ifdef TEMPORIZADOR
	#include <time.h>
#endif

//vai ser alterado
//classe geradora de nºs aleatórios
class Random{
		unsigned long 	semente;
		#ifndef TEMPORIZADOR
			unsigned short 	geraSemente();
		#endif
		double 		q,sqratio;
		int 		normal_result;
	public:
			//construtores
			Random(){
				#ifndef TEMPORIZADOR
					semente=geraSemente();
				#else
					semente=time(0);
				#endif
				normal_result=0;
			}
			Random(unsigned short semente){this->semente=semente; normal_result=0;}
			//métodos
		void   	init(unsigned short semente){this->semente=semente; q=0;normal_result=0;}
		//gera n§s aleat¢rios de acordo com a destribu‡Æo Gaussiana
		double 	Normal(double media,double desvio_padrao);
		//gera n£meros aleat¢rios pertencentes [0,1]
		double 	rand(){
			semente = semente*MULTIPLICADOR + INCREMENTO;
			return (double)semente/0xFFFFFFFF;
		}
		//gerador de nº's aleatórios vulgar
		unsigned long Rand(){
			semente = semente*MULTIPLICADOR + INCREMENTO;
			return semente;
		}
		//gera inteiros num intervalo perdefinido
		long NoIntervaloInteiro(long a,long b){
			return Rand()%(b-a+1)+a;
		}
		
		double NoIntervalo(double a,double b){
			double prob = rand();
			
			return a*(prob) + b*(1-prob);
		}
		//gera inteiros para aceder a elementos de matrizes
		unsigned RandArray(unsigned tamanho){
		      return Rand()%tamanho;
		}
		int Flip(float Prob){
			return (rand()<=Prob);
		}


};
#ifndef TEMPORIZADOR

//gera a semente a patrir do contador que controla o relógio e calendário
unsigned short Random::geraSemente(){
	asm{//ATENÇÂO CÓDIGO em assembly só para compiladores da borland (testado no C++ builder 3 Borland C++ 3.1 e 5.0)
		xor ax,ax;
		int 0x1A;
	}
	return _DX;
}
#endif

double Random::Normal(double media,double desvio_padrao){
	double p,v;

	if(normal_result){
		normal_result=0;
		return sqratio * q * desvio_padrao + media;
	}else {
		do{
			p = rand()*2-1;
			q = rand()*2-1;
			v = p*p + q*q;
		} while(v > 1.0 || v <0.25);
		normal_result=1;
		sqratio = sqrt(-2*log(rand()) / v);
		return (sqratio * p * desvio_padrao) + media;
	}
}

//------------------------------------------------------------------------------
