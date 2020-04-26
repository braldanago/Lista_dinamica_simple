#include <iostream>

using namespace std;

struct Nodo{
	int dato;
	Nodo *sig;
};


///////////////////// LISTADINAMICA //////////////////////////////
class ListaDinamica{
	protected: Nodo *cabeza;
	//Métodos
	public:
		ListaDinamica();
		void agregar(int);
		void mostrar();	
		int burbuja();
		int eliminar();
		int eliminarElemento(int);
		int buscar(int);
		bool vacia();
		void agregarDerecha(int, int);
		void agregarIzquierda(int,int);
};

ListaDinamica::ListaDinamica(){
	cabeza = NULL;
}

void ListaDinamica::agregar(int dato){
	Nodo *p=new Nodo;
	(*p).dato = dato;
	(*p).sig = cabeza;
	cabeza =p;
		
}

void ListaDinamica::agregarDerecha(int dato, int elemento){
	Nodo *p=cabeza;	
	while(p!=NULL){
		if((*p).dato==elemento){
			Nodo *q = new Nodo;
			(*q).sig=(*p).sig;
			(*q).dato=dato;
			(*p).sig=q;
			p=NULL;
		}
		else{
			p=p->sig;
		}
		
	}	
} 	

void ListaDinamica::agregarIzquierda(int dato, int elemento){
	Nodo *p=cabeza;	
	Nodo *r=NULL;
	while(p!=NULL){
		if((*p).dato==elemento){
			Nodo *q = new Nodo;
			q->dato=dato;
			
			if(cabeza==p){
				cabeza=q;
				cabeza->sig=p;
			}else{
				q->sig=p;
				r->sig=q;
			}
			p=p->sig;
		}
		else{
			r=p;		
			p=p->sig;
		}
	}	
}
	
//		if((*p).sig!=NULL){
//			cout<<"DATO\t"<<(*p).dato<<endl;
//			p=p->sig;		
//		}
//		else{
//			cout<<"Llego a "<<(*p).dato<<" dato"<<endl;
//			Nodo *q=new Nodo;
//			(*p).sig=q;
//			(*q).dato=dato;
//			(*q).sig=NULL;	
//			p=NULL;
//		}		


void ListaDinamica::mostrar(){
	Nodo *p=cabeza;
	while(p!=NULL){ //while(p)
		cout<<p->dato<<" ";
		p=p->sig;
	
	}
}

int ListaDinamica::burbuja(){
	int aux,operaciones=0;
	Nodo *q = cabeza;		
	
	while(q!=NULL){
		Nodo *r = q->sig;
		while(r!=NULL){
			if((q->dato) > (r->dato)){
				aux=q->dato;
				(*q).dato = (*r).dato;
				(*r).dato = aux;
			}
			r=r->sig;
		}
		q=q->sig;		
	}
}

int ListaDinamica::eliminar(){///ELIMINA EL ULTIMO
	int num=0;
	Nodo *p=cabeza;
	Nodo *q=p;
	
	while(p->sig!=NULL){
		q=p;
		p=p->sig;
		q->sig=p;
		num=p->dato;
	}
	q->sig=NULL;
	delete p;
	return num;

} 

int ListaDinamica::eliminarElemento(int elemento){
	Nodo *p = cabeza;	
	Nodo *q=p;
	Nodo *r=p;
	int k;
	
	k=buscar(elemento);
	if(k==-1){
		return k;
	}else{
		for(int i=0;i<k;i++){
			q=p;
			p=(*p).sig;
			r=p->sig;
			q->sig=p;
		}
		if(p->sig==NULL){
			q->sig=NULL;
			delete p;
		}else if(k!=0){
			q->sig=r;
			delete p;
		}else{
			cabeza=p->sig;
			delete p;
		}
		return k;
	}
}

int ListaDinamica::buscar(int elemento){
	int k=0;
	Nodo *q = cabeza;	
	while(q!=NULL){				
		if((*q).dato == elemento){
			return k;			
		}
		k++;
		q=(*q).sig;
	}
	return -1;
}

bool ListaDinamica::vacia(){
	return cabeza==NULL;
}
///// FIN LISTADINAMICA ////////////////////////////////////////////////////



////////////////////////CLASE COLA /////////////////////////////////////////
class Cola: public ListaDinamica{
	private: Nodo *fin;
	public:
		Cola();
		void agregar(int);
		int eliminar();
};
Cola::Cola(){
	cabeza=fin=NULL;
}

void Cola::agregar(int dato){
	Nodo *p= new Nodo;
	p->dato=dato;
	p->sig=NULL;		

	if(!cabeza){
		cabeza=p;
	}else{
		
		fin->sig=p;
	}
	fin=p;
}

int Cola::eliminar(){
	int dato=cabeza->dato;
	Nodo *p=cabeza;
	cabeza=cabeza->sig;
	delete p;
	return dato;
}
/////////// FIN COLA ///////////////////////////////////

///CLASE PILA///////////////////////////////////////////

class Pila: public ListaDinamica{
	private : Nodo *fin;
	public:
		Pila();
		int eliminar();
		
};
Pila::Pila(){
	cabeza=NULL;
}

int Pila::eliminar(){
	Nodo *q = cabeza;				
	if(q!=NULL){
		cabeza= (*q).sig;
		delete q;		
	}
	
}

//////// FIN PILA ////////////////////////////////////////




char menuLista();
char menuPrincipal();
char menuCola();
char menuPila();




/////////////////////////////////////////////////////  MAIN /////////////////////////////////////////////////////////////////
int main(){
	
	//Cola lista;
	char opcion;
	int dato,posicion, elemento;
	do{
		opcion= menuPrincipal();
		switch(opcion){
			case 'l':
			case 'L':{ ///////     LISTA DINAMICA      //////////
				ListaDinamica lista;
				do{
					opcion= menuLista();
					if(opcion=='a' || opcion=='A'){
						cout<<"Digite el elemento a agregar: ";						
						cin>>dato;
						lista.agregar(dato);
					}else if(opcion=='b' || opcion=='B'){
						cout<<"Digite el elemento a buscar: ";				
						cin>>dato;
						posicion=lista.buscar(dato);
						if(posicion!=-1){
							cout<<"El elemento se encuentra en la posicion: "<<posicion<<endl;
						}else{
							cout<<"El elemento no se encontro \n";
						}
					}else if(opcion=='e'||opcion=='E'){
						if(!lista.vacia()){
						cout<<"Se elimino el ultimo elemento: \n"<<lista.eliminar()<<endl;
						}else{
							cout<<"La lista se encuentra vacia.";
						}	
						lista.mostrar();						
					}else if(opcion=='l' || opcion=='L'){
						cout<<"Digite el elemento a eliminar: ";						
						cin>>dato;
						
						posicion=lista.eliminarElemento(dato); 
						if(posicion!=-1){
							cout<<"Se elimino el elemento \n";
						}else{
							cout<<"El elemento no se encontro \n";
						}
					}else if(opcion=='d' || opcion=='D'){//INSERTAR DERECHA						
						cout<<"Digite el elemento a agregar: ";						
						cin>>dato;
						cout<<"Digite a la derecha de cual elemento quiere agregar: ";						
						cin>>elemento;
						lista.agregarDerecha(dato,elemento);
						
					}else if(opcion=='i' || opcion=='I'){//INSERTAR IZQUIERDA
						cout<<"Digite el elemento a agregar: ";						
						cin>>dato;
						cout<<"Digite a la izquierda de cual elemento quiere agregar: ";						
						cin>>elemento;
						lista.agregarIzquierda(dato,elemento);
						
						
					}else if(opcion=='o' || opcion=='O'){
						lista.burbuja();									
						cout<<"La lista ha sido ordenada \n ";					
					}else if(opcion=='m' ||opcion=='M'){
						cout<<"Los elementos almacenados\n ";										
						lista.mostrar();
					}
				}while(opcion != 'r' && opcion != 'R');
				break;
			}
			case 'c':///////////////////  COLA //////////////////
			case 'C':{
				Cola lista;
				do{
					opcion=menuCola();
					if(opcion=='a' || opcion=='A'){
						cout<<"Digite el elemento a agregar: ";						
						cin>>dato;
						lista.agregar(dato);
					}else if(opcion=='e'||opcion=='E'){ //// REVISAR /// ?¿? ELIMINAR DE ESTA FORMA? o el numero que uno ingrese?
						if(!lista.vacia()){
						cout<<"Se elimino el ultimo? elemento: "<<lista.eliminar()<<endl;
						}else{
							cout<<"La cola se encuentra vacia.";
						}	
						lista.mostrar();
					}else if(opcion=='b' || opcion=='B'){
						cout<<"Digite el elemento a buscar: ";				
						cin>>dato;
						posicion=lista.buscar(dato);
						if(posicion!=-1){
							cout<<"El elemento se encuentra en la posicion: "<<posicion<<endl;
						}else{
							cout<<"El elemento no se encontro \n";
						}
					}else if(opcion=='b' || opcion=='B'){
						cout<<"Digite el elemento a buscar: ";				
						cin>>dato;
						posicion=lista.buscar(dato);
						if(posicion!=-1){
							cout<<"El elemento se encuentra en la posicion: "<<posicion<<endl;
						}else{
							cout<<"El elemento no se encontro \n";
						}
					}else if(opcion=='m' ||opcion=='M'){
						cout<<"Los elementos almacenados\n ";										
						lista.mostrar();
					}
				}while(opcion != 'r' && opcion != 'R');
				break;
			}
			case 'p':/// PILA //////
			case 'P':{
				Pila lista;
				do{
					opcion=menuPila();
					if(opcion=='a' || opcion=='A'){
						cout<<"Digite el elemento a agregar: ";						
						cin>>dato;
						lista.agregar(dato);
					}else if(opcion=='e'||opcion=='E'){ //// REVISAR /// ?¿? ELIMINAR DE ESTA FORMA? o el numero que uno ingrese?
						if(!lista.vacia()){
						cout<<"Se elimino el ultimo? elemento: "<<lista.eliminar()<<endl;
						}else{
							cout<<"La pila se encuentra vacia.";
						}	
						lista.mostrar();
					}else if(opcion=='b' || opcion=='B'){
						cout<<"Digite el elemento a buscar: ";				
						cin>>dato;
						posicion=lista.buscar(dato);
						if(posicion!=-1){
							cout<<"El elemento se encuentra en la posicion: "<<posicion<<endl;
						}else{
							cout<<"El elemento no se encontro \n";
						}
					}else if(opcion=='b' || opcion=='B'){
						cout<<"Digite el elemento a buscar: ";				
						cin>>dato;
						posicion=lista.buscar(dato);
						if(posicion!=-1){
							cout<<"El elemento se encuentra en la posicion: "<<posicion<<endl;
						}else{
							cout<<"El elemento no se encontro \n";
						}
					}else if(opcion=='m' ||opcion=='M'){
						cout<<"Los elementos almacenados\n ";										
						lista.mostrar();
					}
				}while(opcion != 'r' && opcion != 'R');
				break;
			}
			case 't':
			case 'T':{
				exit(0);
				break;
			}
			default:{
				cout<<"Ingrese alguna opcion del menu"<<endl;
				break;
			}
		}
		
			
		/*
		opcion= menu();
		switch(opcion){
			case 'a':
			case 'A':
				cout<<"Digite el elemento a agregar: ";						
				cin>>dato;
				lista.agregar(dato);
				break;				
			case 'b':
			case 'B':
				cout<<"Digite el elemento a buscar: ";				
				cin>>dato;
				posicion=lista.buscar(dato);
				if(posicion!=-1){
					cout<<"El elemento se encuentra en la posicion: "<<posicion<<endl;
				}else{
					cout<<"El elemento no se encontro \n";
				}
				break;		
				
			case 'e':
			case 'E':
				if(!lista.vacia()){
					cout<<"Se elimino el ultimo elemento: \n"<<lista.eliminar()<<endl;
				}else{
					cout<<"La lista se encuentra vacia. Perro";
				}	
				lista.mostrar();						
				break;				
				
			case 'l':
			case 'L':
				cout<<"Digite el elemento a eliminar: ";						
				cin>>dato;
				
				posicion=lista.eliminarElemento(dato); ///////////// REVISAR
				if(posicion!=-1){
					cout<<"Se elimino el elemento \n";
				}else{
					cout<<"El elemento no se encontro \n";
				}
				break;
				
			case 'o':
			case 'O':
				lista.burbuja();									
				cout<<"La lista ha sido ordenada \n ";					
				break;				
			
			case 'm':
			case 'M':
				cout<<"Los elementos almacenados\n ";										
				lista.mostrar();
				break;				
		}*/
	}
	while(opcion != 't' && opcion != 'T');
}
//////////////////////////////////// FIN MAIN ///////////////////////////////////////////////////


char menuPrincipal(){
	char opcion;
	cout<<"\n\tMENU\n";
	cout<<"\nIngrese una opcion\n";
	cout<<"(L)ista dinamica \n";
	cout<<"(C)ola \n";
	cout<<"(P)ila \n";
	cout<<"(T)erminar\n";
	
	cin>>opcion;
	return opcion;
}

char menuLista(){
	char opcion;
	cout<<"\n\tMENU LISTA\n";
	cout<<"(A)gregar\n";
	cout<<"(B)uscar\n";
	cout<<"(E)liminar Ultimo\n";
	cout<<"(L)Eliminar Elemento\n";
	cout<<"Insertar a la (D)erecha\n";
	cout<<"Insertar a la (I)zquierda\n";
	cout<<"(O)rdenar\n";
	cout<<"(M)ostrar\n";
	cout<<"(R)egresar\n";
	
	cin>>opcion;
	return opcion;
}

char menuCola(){
	char opcion;
	cout<<"\n\tMENU COLA\n";
	cout<<"(A)gregar\n";
	cout<<"(E)liminar\n";
	cout<<"(B)uscar\n";
	cout<<"(M)ostrar\n";
	cout<<"(R)egresar\n";
	
	cin>>opcion;
	return opcion;
}

char menuPila(){
	char opcion;
	cout<<"\n\tMENU PILA\n";
	cout<<"(A)gregar\n";
	cout<<"(E)liminar\n";
	cout<<"(B)uscar\n";
	cout<<"(M)ostrar\n";
	cout<<"(R)egresar\n";
	
	cin>>opcion;
	return opcion;
}


