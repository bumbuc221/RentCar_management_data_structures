#include "Standard.h"
#include <cstring>
#include <fstream>
#include <conio.h>
Standard::Standard(int ID,char *categorie, int locuri, char *nume, char *cutie, char *combustibil, double pret, int nr_usi,int locuri_bagaje, char *reducere, char *navigatie)
        : Masini(ID,categorie,locuri,nume,cutie,combustibil,pret,nr_usi){
    this->locuri_bagaje=locuri_bagaje;
    this->reducere=new char[strlen(reducere)+1];
    strcpy(this->reducere, reducere);
    this->navigatie=new char[strlen(navigatie)+1];
    strcpy(this->navigatie,navigatie);
}

//constructorul de copiere clasei Standard
Standard::Standard(const Standard &a): Masini(a) {
    this->locuri_bagaje=a.locuri_bagaje;
    this->reducere=new char[strlen(a.reducere)+1];
    strcpy(this->reducere,a.reducere);
    this->navigatie=new char[strlen(a.navigatie)+1];
    strcpy(this->navigatie,a.navigatie);
}

//operatorul de copiere = al clase Standard
Standard& Standard::operator=(const Standard &a) {
    if(&a==this)
        return *this;
    this->delete_();
    if(this->reducere)
        delete []this->reducere;
    if(this->navigatie)
        delete []this->navigatie;
    this->init(a);
    this->reducere=new char[strlen(a.reducere)+1];
    strcpy(this->reducere,a.reducere);
    this->navigatie=new char[strlen(a.navigatie)+1];
    strcpy(this->navigatie,a.navigatie);
    return *this;
}

//destructorul
Standard::~Standard(){
    delete[] navigatie;
    delete[] reducere;
}

//functia de afisare suprascrisa
ostream& Standard::afisare(ostream& st)const{
    st<<" ID-ul: "<< this->get_id()<<endl;
    st<<" Categorie: "<<categorie<<endl;
    st<<" Nume: "<<nume<<endl<<" Pret: "<<pret<<endl<<" Combustibil: "<<combustibil<<endl;
    st<<" Cutie de viteze: "<<cutie<<endl<<" Locuri: "<<locuri<<endl<<" Usi: "<<nr_usi<<endl;
    st<<" Nr locuri bagaje: "<<locuri_bagaje<<endl<<" Reducere: "<<reducere<<endl;
    st<<" Navigatie: "<<navigatie<<endl;
    st<<endl;
    return st;
}
void update(ofstream &f, Standard &a)
{
    f<<a.get_id()<<","<<"A"<<","<<a.get_nume()<<","<<a.get_cutie()<<","<<a.get_combustibil()<<","<<a.get_pret()<<","<<a.get_usi()<<",";
    f<<a.get_locuri()<<","<<a.get_loc_bagaje()<<","<<a.get_reducere()<<","<<a.get_navigatie()<<",";
    if(a.get_valid())
        f<<"VALID\n";
    else
        f<<"INVALID\n";
}
//operatorul de afisare la clasa Standard
ostream& operator<<(ostream& st,const Standard& a)
{
    return a.afisare(st);
}
