#include<iostream>
#include <cmath>
#include <unistd.h>
#include "TPcolors.h"
using namespace std;

void TP_bar(string icon, float lengt, float time){ // Icono █, Largo, Tiempo 
	string x = icon;float porc = 1; float timer = time * 1000000;
	string v = "";
	for(int i=0; i<=lengt; i++){
		system("/bin/clear");
		if(i%2 == 0){
			v = "\\";
		}else{
			v = "/";
		}
		porc = (100/lengt) * i;cout<<WHITE<<"["<<CYAN<<v<<WHITE<<"] Cargando "<<CYAN<<lround(porc)<<"%"<<WHITE<<": "<<GREEN<<x<<endl;x += icon;
		usleep(timer);
	}
}

void TP_loading(){ // Icono █, Largo, Tiempo 
	string icon = ".";
	float porc = 1; 
	float timer = 0.005 * 1000000;
	string v = "";
	for(int i=0; i<=100; i++){
		if(i%2 == 0){
			v = "->";
		}else{
			v = "<-";
		}
		porc = (1/1) * i;
		cout<<WHITE<<"\r["<<CYAN<<v<<WHITE<<"] Cargando "<<CYAN<<lround(porc)<<"%"<<WHITE<<""<<GREEN;
		usleep(timer);
	}
}
