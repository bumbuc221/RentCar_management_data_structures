
#include "Premium.h"
Premium::Premium(int id,char *categorie, int locuri, char *nume, char *cutie, char *combustibil, double pret, int nr_usi,int putere, int capacitate_cilindrica, char *transmisie, char *pilot_automat)
        : Masini(id,categorie,locuri,nume,cutie,combustibil,pret,nr_usi){
    this->putere=putere;
    this->capacitate_cilindrica=capacitate_cilindrica;
    this->transmisie=new char[strlen(transmisie)+1];
    strcpy(this->transmisie,transmisie);
    this->pilot_automat=new char[strlen(pilot_automat)+1];
    strcpy(this->pilot_automat,pilot_automat);
}

//constructorul de copiere
Premium::Premium(const Premium &a): Masini(a){
    this->putere=a.putere;
    this->capacitate_cilindrica=a.capacitate_cilindrica;
    this->transmisie=new char[strlen(a.transmisie)+1];
    strcpy(this->transmisie,a.transmisie);
    this->pilot_automat=new char[strlen(a.pilot_automat)+1];
    strcpy(this->pilot_automat,a.pilot_automat);
}

//operatorul de copiere = al clasei Premium
Premium& Premium::operator=(const Premium &a) {
    if(&a==this)
        return *this;
    delete_();
    delete []this->transmisie;
    delete []this->pilot_automat;
    init(a);
    this->putere=a.putere;
    this->capacitate_cilindrica=a.capacitate_cilindrica;
    this->transmisie=new char[strlen(a.transmisie)+1];
    strcpy(this->transmisie,a.transmisie);
    this->pilot_automat=new char[strlen(a.pilot_automat)+1];
    strcpy(this->pilot_automat,a.pilot_automat);
    return *this;
}
//functia de afisare
ostream & Premium::afisare(ostream &st) const {
    st<<" ID-ul: "<<this->get_id()<<endl;
    st<<" Categorie: "<<categorie<<endl;
    st<<" Nume: "<<nume<<endl<<" Pret: "<<pret<<endl<<" Combustibil: "<<combustibil<<endl;
    st<<" Cutie de viteze: "<<cutie<<endl<<" Locuri: "<<locuri<<endl<<" Usi: "<<nr_usi<<endl;
    st<<" Putere: "<<putere<<" CP"<<endl<<" Capacitate cilindrica: "<<capacitate_cilindrica<<endl;
    st<<" Transmisie: "<<transmisie<<endl<<" Pilot automat: "<<pilot_automat<<endl;
    st<<endl;
    return st;
}
void update(ofstream &f,Premium &c)
{
    f<<c.get_id()<<","<<"C"<<","<<c.get_nume()<<","<<c.get_cutie()<<","<<c.get_combustibil()<<","<<c.get_pret()<<","<<c.get_locuri()<<",";
    f<<c.get_usi()<<","<<c.get_transmisie()<<","<<c.get_pilot()<<","<<c.get_putere()<<","<<c.get_capacitate()<<",";
    if(c.get_valid())
        f<<"VALID\n";
    else
        f<<"INVALID\n";
}
//operatorul de afisare pt clasa Premium
ostream& operator<<(ostream& st,const Premium& a)
{
    return a.afisare(st);
}

//Destructor al clasei Premium
Premium::~Premium(){
    delete []transmisie;
    delete []pilot_automat;
}

