#include "Masini.h"
#include <cstring>
#include <fstream>
#include <conio.h>

int Masini::id=0;
char* Masini::get_combustibil() {
    return  combustibil;
}
char* Masini::get_cutie() { return cutie;}
int Masini::get_locuri() {return locuri;}
int Masini::get_usi() {return nr_usi;}
Masini::Masini(int ID,char*categorie,int locuri,char*nume,char*cutie,char* combustibil,double pret,int nr_usi)
{
    this->categorie=new char[strlen(categorie)+1];
    strcpy(this->categorie,categorie);
    this->locuri=locuri;
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
    this->cutie=new char[strlen(cutie)+1];
    strcpy(this->cutie,cutie);
    this->combustibil=new char[strlen(combustibil)+1];
    strcpy(this->combustibil,combustibil);
    this->pret=pret;
    this->nr_usi=nr_usi;
    id_v=ID;
    valid=1;
    id++;
}

void Masini::init(const Masini &a) {
    this->categorie=new char[strlen(a.categorie)+1];
    strcpy(this->categorie,a.categorie);
    this->locuri=a.locuri;
    this->nume=new char[strlen(a.nume)+1];
    strcpy(this->nume,a.nume);
    this->cutie=new char[strlen(a.cutie)+1];
    strcpy(this->cutie,a.cutie);
    this->combustibil=new char[strlen(a.combustibil)+1];
    strcpy(this->combustibil,a.combustibil);
    this->pret=a.pret;
    this->nr_usi=a.nr_usi;
    this->valid=a.valid;
    this->id_v=a.id_v;
}
//constructor copiere clasa de baza Masini
Masini::Masini(const Masini &a) {
    init(a);
}

//operatorul de copiere al clasei de baza
Masini& Masini::operator=(const Masini &a) {
    if(&a==this)
        return *this;
    delete_();
    init(a);
    return *this;
}
void Masini::delete_() {
    if(categorie!= nullptr)
        delete []categorie;
    if(nume!= nullptr)
        delete []nume;
    if(cutie!= nullptr)
        delete []cutie;
    if(combustibil!= nullptr)
        delete []combustibil;
}
//Destructorul pt clasa de baza Masini
Masini::~Masini() {
    delete_();
}

//functia de afisare al clasei de baza
ostream& Masini::afisare(ostream& st)const{
    st<<"Categorie:"<<categorie<<endl;
    st<<"Nume:"<<nume<<endl<<"Pret:"<<pret<<endl<<"Combustibil:"<<combustibil<<endl;
    st<<"Cutie de viteze:"<<cutie<<endl<<"Locuri:"<<locuri<<endl<<"Usi: "<<nr_usi<<endl;
    st<<endl;
    return st;
}

//operatorul de scriere
ostream& operator<<(ostream& st,const Masini& a)
{
    return a.afisare(st);
}
