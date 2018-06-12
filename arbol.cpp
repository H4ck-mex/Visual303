#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
using namespace std;

struct Nodo{
	int dat;
	Nodo *der;
	Nodo *izq;
	Nodo *pa;
};

Nodo *crearNodo(int);
void insNodo(Nodo *&,int,Nodo *);
Nodo *ar = NULL;
void mos(Nodo *,int);
bool busq(Nodo*,int);
void preO(Nodo *);
void inO(Nodo *);
void posO(Nodo *);
void elim(Nodo *,int);
void elimNodo(Nodo*);
Nodo* min(Nodo *);
void rempl(Nodo*, Nodo *);
void destNodo(Nodo *);


int main(){
	int dat, opc,cont=0;
	while (opc!=8){
		printf("********************\n\n");
		printf("*       MENU       *\n\n");
		printf("********************\n\n");
		
		printf(" Seleccione una opcion:\n\n 1) Insertar Nodo\n 2) Mostrar el Arbol\n 3) buscar un dato\n 4)recorrer en preorden\n 5)recorrer en inorden\n 6)recorrer en postorden\n 7)eliminar Nodo \n 8) Salir\n");
		scanf("%i",&opc);
		switch (opc){
		case 1:
			cout<<"ingrese un numero: ";
			cin>>dat;
			insNodo(ar,dat,NULL);
			system("pause");	
			printf("\n");
			break; 
		
		case 2:
			cout<<"mostrando arbol"<<endl;
			mos(ar,cont);
			printf("\n");
			system("pause");
			break;
			
		case 3:
			cout<<"elija un num para buscar: ";
				cin>>dat;
			if(busq(ar,dat)==true){
				cout<<"\nel"<<dat<<"ha sido encontrado en el arbol\n";
			}
			else{
				cout<<"el elemento no se encontro\n";
			}
			system("pause");
			break;
			
			
		case 4: 
			cout<<"recorrido preorden: ";
		preO(ar);
		cout<<"\n";
		system("pause");
			break;
		
		case 5:
			cout<<"recorrido inorden: \n";
			inO(ar);
			system("pause");
			break;
			
		case 6:
			cout<<"recorrido en postorden: \n";
			posO(ar);
			system("pause");
		
		case 7:
			cout<<"elija que nodo eliminar: \n";
			cin>>dat;
			elim(ar,dat);
			system("pause");
			break;
		}
		
		system("cls");
	} 
	return 0; 
}

Nodo *crearNodo(int n,Nodo *pa){
	Nodo *novonodo = new Nodo();
	
	novonodo->dat = n;
	novonodo->der = NULL;
	novonodo->izq = NULL;
	novonodo->pa =pa;
	return novonodo;
}



void mos(Nodo *ar, int cont){
if(ar == NULL){
	return;

}
else{
	mos(ar->der,cont+1);
	for(int x=0; x<cont; x++){
		printf("	");
	}
	cout<<ar->dat<<endl;
	
	mos(ar->izq,cont+1);
}
}


void insNodo(Nodo *&ar, int n,Nodo *pa){
	
	if(ar == NULL){
		Nodo *novonodo = crearNodo(n,pa);
		ar = novonodo;
	}else{
		int valRa = ar->dat;
		if(n == valRa){
			cout<<"Este numero ya existe"<<endl;
		}else if(n<valRa){
			insNodo(ar->izq,n,ar);
		}else{
			insNodo(ar->der,n,ar);
		}
	}
} 

bool busq(Nodo*ar, int x){
	if(ar == NULL){
		return false;
	}
	else if( ar->dat ==x){
		return true;
	}
	else if(x<ar ->dat){
		return busq(ar ->izq,x);
		}
	else{
		return busq(ar->der,x);
	}
}

void preO(Nodo*ar){
	if(ar==NULL){
		return;
	}
	else{
		cout<<ar->dat<<" - ";
		preO(ar->izq);
		preO(ar->der);
	}
}

void inO(Nodo*ar){
	if(ar== NULL){
		return;
}
	else{
		inO(ar->izq);
		cout<<ar->dat<<"-";
		inO(ar->der);	
	}
}

void posO(Nodo *ar){
	if(ar ==NULL){
		return;
	}
	else{
		posO(ar->izq);
		posO(ar->der);
		cout<<ar->dat<<"-";
	}
}

void elim(Nodo * ar, int x){
	if(ar == NULL){
		return;
	}
	else if(x <ar ->dat){
		elim(ar->izq,x);
	}
	else if(x>ar->dat){
		elim(ar->der,x);
	}
	else{
		elimNodo(ar);
	}
}

Nodo *min(Nodo *ar){
	if(ar == NULL){
		return NULL;
	}
	if(ar->izq){
		return min(ar->izq);
	}
	else{
		return ar;
	}
}

void elimNodo(Nodo*nodoelim){
	if(nodoelim->izq && nodoelim->der){
		Nodo *menor =min(nodoelim->der);
		nodoelim->dat=menor->dat;
	    elimNodo(menor);
	}
	else if(nodoelim->izq){
		rempl(nodoelim,nodoelim->izq);
		destNodo(nodoelim);
	}
	else if(nodoelim->der){
		rempl(nodoelim,nodoelim->der);
		destNodo(nodoelim);
	}
	else{
		rempl(nodoelim,NULL);
		destNodo(nodoelim);
	}
}

void rempl(Nodo *ar, Nodo *novonodo ){
		if(ar->pa){
			if(ar->dat == ar ->pa->izq->dat){
				ar->pa->izq =novonodo;
			}
			else if(ar ->dat ==ar ->pa->der->dat){
				ar->pa->der =novonodo;
			}
		}
		if(novonodo){
			
		}
	}

void destNodo(Nodo *nodo){
	nodo->izq=NULL;
	nodo->der=NULL;
	delete nodo;
}
