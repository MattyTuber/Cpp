#include <iostream>
#include <list>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>

#define e_number 2.718281828459045

using namespace std;

struct data_s
{
    int giorno;
    string mese;
    int anno;
};

typedef data_s data;

typedef struct misura_s
{
    data giorno_rilevazione;
    double temperatura;
} misura;

double rand_interval(double a, double b){
	double pi = atan(1)*4;
    double sigma_2 = (b-a)*(b-a)/100.;
    double mean = (b+a)/2;
    double x_var = (b - a)*rand()/RAND_MAX + a;
    double y_var = 1./(sqrt(2* pi )*sigma_2)*rand()/RAND_MAX;

    while (y_var > 1./(sqrt(2*pi)*sigma_2) * pow(e_number, -1. *(x_var-mean)*(x_var-mean)/(2. * sigma_2 ))){
        x_var = (b - a)*rand()/RAND_MAX + a;
        y_var = 1./(sqrt(2*pi)*sigma_2)*rand()/RAND_MAX ;
    }
    
    return x_var;
}

double misura_temperatura (data giorno_misura ) {
    double temperatura;

    if(giorno_misura.mese == "Gennaio" || giorno_misura.mese == "Febbraio" || giorno_misura.mese == "Dicembre")
        temperatura = rand_interval(-20, 15);
    if(giorno_misura.mese == "Marzo" || giorno_misura.mese == "Aprile")
        temperatura = rand_interval(-5, 25);
    if(giorno_misura.mese == "Maggio"  || giorno_misura.mese == "Giugno")
        temperatura = rand_interval(7, 37);
    if(giorno_misura.mese == "Luglio"  || giorno_misura.mese == "Agosto")
        temperatura = rand_interval(20, 45);
    if(giorno_misura.mese == "Settembre" || giorno_misura.mese == "Ottobre" || giorno_misura.mese == "Novembre")
        temperatura = rand_interval(-5, 20);

    return temperatura;
}

void aggiorna_data(data& giorno_misura) {
    if(giorno_misura.mese == "Gennaio" ){
        if(giorno_misura.giorno < 31 )
            giorno_misura.giorno ++;
        else {
            giorno_misura.giorno = 0;
            giorno_misura.mese = "Febbraio";   
        }
    }

    if(giorno_misura.mese == "Febbraio" ){
        if(giorno_misura.giorno < (28 + (int) (giorno_misura.anno%4 == 0)  ))
            giorno_misura.giorno ++;
        else {
            giorno_misura.giorno = 0;
            giorno_misura.mese = "Marzo";  
        }
    }

    if(giorno_misura.mese == "Marzo" ){
        if(giorno_misura.giorno < 31 )
            giorno_misura.giorno ++;
        else {
            giorno_misura.giorno = 0;
            giorno_misura.mese = "Aprile";
        }  
    }

    if(giorno_misura.mese == "Aprile" ){
        if(giorno_misura.giorno < 30 )
            giorno_misura.giorno ++;
        else {
            giorno_misura.giorno = 0;
            giorno_misura.mese = "Maggio"; 
        }  
    }

    if(giorno_misura.mese == "Maggio"){
        if(giorno_misura.giorno < 31 )
            giorno_misura.giorno ++;
        else {
            giorno_misura.giorno = 0;
            giorno_misura.mese = "Giugno";  
        }
    }

    if(giorno_misura.mese == "Giugno" ){
        if(giorno_misura.giorno < 30 )
            giorno_misura.giorno ++;
        else {
            giorno_misura.giorno = 0;
            giorno_misura.mese = "Luglio";
        }
    }

    if(giorno_misura.mese == "Luglio" ){
        if(giorno_misura.giorno < 31 )
            giorno_misura.giorno ++;
        else{
            giorno_misura.giorno = 0;
            giorno_misura.mese = "Agosto";
        }  
    }
    if(giorno_misura.mese == "Agosto" ){
        if(giorno_misura.giorno < 30 )
            giorno_misura.giorno ++;
        else {
            giorno_misura.giorno = 0;
            giorno_misura.mese = "Settembre";
        }
    }

    if(giorno_misura.mese == "Settembre" ){
        if(giorno_misura.giorno < 30 )
            giorno_misura.giorno ++;
        else {
            giorno_misura.giorno = 0;
            giorno_misura.mese = "Ottobre";  
        }
    }

    if(giorno_misura.mese == "Ottobre" ){
        if(giorno_misura.giorno < 31 )
            giorno_misura.giorno ++;
        else {
            giorno_misura.giorno = 0;
            giorno_misura.mese = "Novembre";
        }  
    }

    if(giorno_misura.mese == "Novembre" ){
        if(giorno_misura.giorno < 30 )
            giorno_misura.giorno ++;
        else {
            giorno_misura.giorno = 0;
            giorno_misura.mese = "Dicembre";  
        }
    }
    if(giorno_misura.mese == "Dicembre" ){
        if(giorno_misura.giorno < 31 )
            giorno_misura.giorno ++;
        else {
            giorno_misura.giorno = 1;
            giorno_misura.mese = "Gennaio" ;
            giorno_misura.anno ++;  
        }
    }

}

void stampa_data(data data_print) {
    cout << data_print.giorno << "\t" << data_print.mese << "\t" <<  data_print.anno ;
}

void genera_misure (data data_inizio, data data_fine, list<misura>& lista){
    data data_app;
    data_app.anno = data_inizio.anno;
    data_app.mese = data_inizio.mese;
    data_app.giorno = data_inizio.giorno;

    misura misura_temp;

    while(data_app.anno != data_fine.anno ||  data_app.mese != data_fine.mese || data_app.giorno != data_fine.giorno) {
        misura_temp.giorno_rilevazione.giorno = data_app.giorno;
        misura_temp.giorno_rilevazione.mese = data_app.mese;
        misura_temp.giorno_rilevazione.anno = data_app.anno;

        misura_temp.temperatura = misura_temperatura(misura_temp.giorno_rilevazione);

        lista.push_back(misura_temp);

        aggiorna_data(data_app);
    }
}

void stampa_misure(list <misura> lista) {
    for(auto element : lista) {
        stampa_data(element.giorno_rilevazione);
        cout << "\t" << element.temperatura << endl;
    }
}

double media(list<misura> lista) {
    double media = 0;

    for(auto element : lista)
    	media = media + element.temperatura/lista.size();

    return media;
}

list<misura> over_mean(list<misura> lista) {
    double mean = media(lista);
    list <misura> lista_over;
    
	for(auto element : lista )
        if(element.temperatura > mean)
            lista_over.push_back(element);

    return lista_over;
}



int main() {
    srand(time(NULL));

    list<misura> misure_temperature;
    data data_inizio;
    data data_fine;

    cout << "Inserire data inizio (gg mese aa) --> ";
    cin >> data_inizio.giorno;
    cin >> data_inizio.mese;
    cin >> data_inizio.anno;

    cout << "Inserire data fine (gg mese aa) --> ";
    cin >> data_fine.giorno;
    cin >> data_fine.mese;
    cin >> data_fine.anno;

    genera_misure(data_inizio, data_fine, misure_temperature);

    stampa_misure(misure_temperature);

    cout << "\n\n\nDate sopra la media: " << media(misure_temperature) << endl;

    stampa_misure(over_mean(misure_temperature));
    
    return 0;
}
