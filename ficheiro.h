//----------------------------------------------------------------------------------------------------------------
#define __FICHEIRO_H

#if !defined(__FSTREAM_H)
	#include <fstream.h>
#endif
//----------------------------------------------------------------------------------------------------------------

//encapsulamento de fstream
struct FileStream:public fstream{//herda de (filha de) fstream ou seja fstream � classe base FileStream � derivada

       /*	pode-se fazer muitas combina��es.

		ios::ate	posiciona -se no fim do ficheiro
		ios::binary 	abre em modo bin�rio
		ios::trunc 	despresa o conteudo anterior
		e outras...
       */
	//public:  n�o � necess�rio pois o objecto � uma estrutura (struct)
		enum {	Leitura=ios::in,
			LeituraEscrita=ios::in|ios::out,
			Escrita=ios::out,
			EscritaAcrescentar=ios::out|ios::app
		};
		//incializa��o dos construtores de fstream
		FileStream():fstream(){}
		FileStream(char *nome,int modo=Leitura):fstream(nome,modo){}
	       ~FileStream(){close();}
		void *abreFicheiro(char *str,int modo=Leitura){

			open(str,modo);
			return this->operator void *();
		}

};
//----------------------------------------------------------------------------------------------------------------