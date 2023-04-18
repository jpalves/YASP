#if !defined (__cplusplus)
	#error Para Compilar em C++  
#endif

#if !defined (_MYSTRING_H)
	#define _MYSTRING_H 
#endif

#if !defined (__IOSTREAM_H)
	#include <iostream.h>
#endif

#if !defined (_STRING_H)
	int strlen(char *str){
		char *ptr=str;

		for(;*ptr;ptr++);
		return ptr - str;
	}
	void strcpy(char *dest,char *src){
		char *ptr_dest=dest,*ptr_src=src;

		for(;*ptr_src;ptr_dest++,ptr_src++) *ptr_dest=*ptr_src;
		*ptr_dest=NULL;
	}

	bool strcmp(char *a,char *b){
		char *ptr1 = a,*ptr2 = b;
		bool cmp = true;

		for(;*ptr1&&*ptr2&&cmp;ptr1++,ptr2++)
		if(*ptr1 != *ptr2) cmp = false;

	       return cmp;
	}

	void strcat(char *dest,char *src){
		char *ptr_dest=dest+strlen(dest),*ptr_src=src;

		for(;*ptr_src;ptr_dest++,ptr_src++)*ptr_dest=*ptr_src;
		*ptr_dest=NULL;
	}

#endif
//---------------------------------------------------------------------------
//		                    classe MyString
//---------------------------------------------------------------------------
class MyString {
	
	//private: não é obrigatório visto uma classe ser privada por defeito
		char *Data;
		//operadores friend
		friend MyString operator+(MyString in,char *str);
		friend MyString operator+(char *str,MyString in);
		friend ostream &operator << (ostream &stream,MyString in);
		friend istream &operator >> (istream &stream,MyString &in);
	public:
		//construtores
		MyString(char *str=""){
			Data = new char[strlen(str)+1];

			if(Data) strcpy(Data,str);
		}
		//cópia do objecto
		MyString(const MyString &in){
			Data = new char[strlen(in.Data)+1];

			if(Data) strcpy(Data,in.Data);
		}
		//destrutor
		~MyString(){if(Data){delete Data; Data=NULL;}}

		//operadores
		//concatenação
		MyString operator +=(MyString in);
		//soma
		MyString operator + (MyString in);
		//atribuição
		MyString operator = (MyString in);
		
		bool operator == (MyString in);
		bool operator != (MyString in);
		//MyString operator  =(char *in);
		
		//indexação
		char   &operator [](int i);

		//métodos
		char   *c_str(){return Data;}
		int    length(){return strlen(Data);}
};
//---------------------------------------------------------------------------
MyString MyString::operator+=(MyString in){
	char *aux = new char[strlen(Data)+strlen(in.Data)+1];

	strcpy(aux,Data);
	strcat(aux,in.Data);
	delete Data;
	Data=aux;
	return *this;
}
//---------------------------------------------------------------------------
MyString MyString::operator+(MyString in){
	char *aux = new char[strlen(Data)+strlen(in.Data)+1];

	strcpy(aux,Data);
	strcat(aux,in.Data);
	MyString temp;
	temp.Data=aux;
	return temp;
}
//---------------------------------------------------------------------------
MyString operator+(MyString in,char *str){
	char *aux = new char[strlen(str)+strlen(in.Data)+1];

	strcpy(aux,in.Data);
	strcat(aux,str);
	MyString temp(aux);
	return temp;
}
//---------------------------------------------------------------------------
MyString operator+(char *str,MyString in){
	char *aux = new char[strlen(str)+strlen(in.Data)+1];

	strcpy(aux,in.Data);
	strcat(aux,str);
	MyString temp(aux);
	return temp;
}
//---------------------------------------------------------------------------
MyString MyString::operator=(MyString in){

	delete Data;
	Data = new char[strlen(in.Data)+1];
	strcpy(Data,in.Data);
	return *this;
}
//---------------------------------------------------------------------------
char &MyString::operator[](int i){
	return Data[i];
}
//---------------------------------------------------------------------------
ostream &operator << (ostream &stream,MyString in){
	stream<<in.Data;
	return stream;
}
//---------------------------------------------------------------------------
istream &operator >> (istream &stream,MyString &in){
		in.Data = new char[256];
	
	stream>>in.Data;
	return stream;
}
//---------------------------------------------------------------------------
bool MyString::operator == (MyString in){return strcmp(Data,in.Data);}
bool MyString::operator != (MyString in) {return !(this->operator ==(in));}