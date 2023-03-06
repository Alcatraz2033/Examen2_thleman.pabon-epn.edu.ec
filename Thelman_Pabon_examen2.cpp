#include <iostream>
#include <fstream>
#include <string>
#include "lib/TPcolors.h"
#include "lib/TPp_bar.h"
using namespace std;

const string TPnomre = "Thelman Jihat Pabon Quevedo";
const int TPcedula = 1500826555;

void TPlectura();
void TPdatos();

int main(){
	//TP_loading();
	cout<<"\n["<<MAGENTA<<"+"<<MAGENTA<<"] Leyendo los datos...\n\n"<<RESET;
	TPlectura();
	TPdatos();
	return 0;
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
			TP_loading();
			cout<<RED<<" [!] "<<TPtexto<<endl;
		}else{
			TP_loading();
			cout<<LGREEN<<" [+] "<<TPtexto<<endl;
		}
	}system("rm sinrep.txt");
}

void TPdatos(){
	cout<<WHITE<<"\n\n["<<GREEN<<"+"<<WHITE<<"] "<<GREEN<<"Informacion del Arbol binario de capacidad belica Ucraniana\n\n"<<RESET;
	cout<<WHITE<<"["<<GREEN<<"~"<<WHITE<<"] "<<GREEN<<"Developer-Nombre: "<<RESET<<TPnomre<<endl;
	cout<<"["<<GREEN<<"~"<<WHITE<<"] "<<GREEN<<"Developer-Cedula: "<<RESET<<TPcedula<<endl;
}
