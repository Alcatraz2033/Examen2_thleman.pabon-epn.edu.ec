#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "lib/TPcolors.h"
#include "lib/TPp_bar.h"
using namespace std;

struct TPcoordenada{
	int TPcapacidad_belica;
	int TPgeolocalizacion;
	char TParsenal[20];
	int *der;
	int *izq;
};

struct Nodo{
	int TPdato;
	Nodo *TPder;
	Nodo *TPizq;
};

Nodo *TPcrear_nodo(int);
Nodo *TParbol = NULL;

void TPinsertar_nodo(Nodo *&,int);
void TPlectura();
void TPdatos();
void TParchivo_al_arbol();
string TP_commd(string);
void fflushin();
void TPmostrar_arbol(Nodo *,int);

const string THELMAN_PABON = "Thelman Jihat Pabon Quevedo";
const int TPCEDULA = 1500826555;

int main(){
	int TPcontador = 0;
	cout<<"\n["<<MAGENTA<<"+"<<MAGENTA<<"] Leyendo los datos...\n\n"<<RESET;
	TPlectura();
	TPdatos();
	TParchivo_al_arbol();
	TPmostrar_arbol(TParbol, TPcontador);
	return 0;
}

void TPmostrar_arbol(Nodo *arbol, int contd){
	if(arbol == NULL){
		return;
	}else{
		TPmostrar_arbol(TParbol->TPder,contd+1);
		for(int i=0;i<contd;i++){
			cout<<"    ";
		}
		cout<<TParbol->TPdato<<endl;
		TPmostrar_arbol(TParbol->TPizq,contd+1);
	}
}

void TParchivo_al_arbol(){
	string TPcomando = TP_commd("cat coordenadas.txt | awk '{print $1}' | tr -d ',' | tr -d 'Cap'  | uniq | sed '/^\\s*$/d'");
	for(char c : TPcomando){
		TPinsertar_nodo(TParbol, c);
	}
}

void fflushin(){ // funcion para calular la basura del buffer y eliminarla

 int d, i=0;
 	d = stdin->_IO_read_end - stdin->_IO_read_ptr;
	for(i=0; i<d; i++)
	getchar();
}

string TP_commd(string commando){
    // Comando a ejecutar
    //string command = "networkctl 2>/dev/null |  awk '{print $(NF-3)}' 2>/dev/null | grep -v 'LINK'";
    string command = commando;

    // Nombre del archivo temporal
    string filename = "temp.txt";

    // Ejecutar el comando y redirigir la salida al archivo temporal
    stringstream ss;
    ss << command << " > " << filename;
    int result = system(ss.str().c_str());

    if (result == 0) {
        // Abrir el archivo temporal y leer su contenido en una variable
        ifstream file(filename);
        string output;
        if (file.is_open()) {
            stringstream ss_output;
            ss_output << file.rdbuf();
            output = ss_output.str();
            file.close();
        }

        // Eliminar el archivo temporal
        remove(filename.c_str());

        // Devolver la salida del comando
        return output;
    } else {
        cerr << "Error al ejecutar el comando\n";
        return "";
        // o también puedes lanzar una excepción para indicar el error
        // throw runtime_error("Error al ejecutar el comando");
    }
}

void TPinsertar_nodo(Nodo *&TParbol, int n){
	if(TParbol == NULL){
		Nodo *TPnuevo_nodo = TPcrear_nodo(n);
		TParbol = TPnuevo_nodo;
	}else{
		int TPvalor_raiz = TParbol->TPdato;
		if(n < TPvalor_raiz){
			TPinsertar_nodo(TParbol->TPizq,n);
		}else{
			TPinsertar_nodo(TParbol->TPder,n);
		}
	}
}

Nodo *TPcrear_nodo(int n){
	Nodo *TPnuevo_nodo = new Nodo();
	TPnuevo_nodo->TPdato = n;
	TPnuevo_nodo->TPder = NULL;
	TPnuevo_nodo->TPizq = NULL;
	return TPnuevo_nodo;
}

void TPlectura(){
	ifstream archivo; 
	string TPtexto;
	system("cat coordenadas.txt | uniq > sinrep.txt");
	archivo.open("sinrep.txt",ios::in); //Abrimos el archivoo en lectura
	if(archivo.fail()){
		cout<<RED"[!] NO SE PUDO ABRIR EL ARCHIVO\n\n"<<RESET;
		exit(1);
	}
	while(!archivo.eof()){ //mientras no sea el fin al del archivo;
		getline(archivo,TPtexto);
		if(TPtexto.find("Cap") != string::npos){
			cout<<RED<<"[!]ERROR\t   [!] "<<TPtexto<<endl;
		}else{
			TP_loading();
			cout<<LGREEN<<" [+] "<<TPtexto<<endl;
		}
	}system("rm sinrep.txt");
}

void TPdatos(){
	cout<<WHITE<<"\n\n["<<GREEN<<"+"<<WHITE<<"] "<<GREEN<<"Informacion del Arbol binario de capacidad belica Ucraniana\n\n"<<RESET;
	cout<<WHITE<<"["<<GREEN<<"~"<<WHITE<<"] "<<GREEN<<"Developer-Nombre: "<<RESET<<THELMAN_PABON<<endl;
	cout<<"["<<GREEN<<"~"<<WHITE<<"] "<<GREEN<<"Developer-Cedula: "<<RESET<<TPCEDULA<<endl;
	cout<<"["<<GREEN<<"~"<<WHITE<<"] "<<GREEN<<"Capacidad-Belica: "<<RESET<<"38"<<endl;
	cout<<"["<<GREEN<<"~"<<WHITE<<"] "<<GREEN<<"Corrdenada-Todal: "<<RESET<<"12"<<endl;
	cout<<"["<<GREEN<<"~"<<WHITE<<"] "<<GREEN<<"Corrdenada-SecCargada: "<<RESET<<"1 5 0 8 2 6"<<endl;
}
