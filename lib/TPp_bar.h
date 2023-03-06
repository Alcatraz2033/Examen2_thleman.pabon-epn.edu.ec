#include<iostream>
#include <cmath>
#include <unistd.h>
#include "TPcolors.h"
using namespace std;

void p_bar(string icon, float lengt, float time){ // Icono █, Largo, Tiempo 
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
