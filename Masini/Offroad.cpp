#include "Offroad.h"
Offroad::Offroad(int ID,char *categorie, int locuri, char *nume, char *cutie, char *combustibil, double pret, int nr_usi,char *troliu, char *carlig, double motor, double inaltime)
        : Masini(ID,categorie,locuri,nume,cutie,combustibil,pret,nr_usi){
    this->inaltime=inaltime;
    this->motor=motor;
    this->troliu=new char[strlen(troliu)+1];
    strcpy(this->troliu,troliu);
    this->carlig=new char[strlen(carlig)+1];
    strcpy(this->carlig,carlig);
}

//constructor de copiere
Offroad::Offroad(const Offroad&a): Masini(a)
{
    this->inaltime=a.inaltime;
    this->motor=a.motor;
    this->troliu=new char[strlen(a.troliu)+1];
    strcpy(this->troliu,a.troliu);
    this->carlig=new char[strlen(a.carlig)+1];
    strcpy(this->carlig,a.carlig);
}

//operator de copiere = pentru clasa Offroad
Offroad& Offroad::operator=(const Offroad&a)
{
    if(&a==this)
        return *this;
    delete_();
    delete []this->troliu;
    delete []this->carlig;
    init(a);
    this->inaltime=a.inaltime;
    this->motor=a.motor;
    this->troliu=new char[strlen(a.troliu)+1];
    strcpy(this->troliu,a.troliu);
    this->carlig=new char[strlen(a.carlig)+1];
    strcpy(this->carlig,a.carlig);
    return *this;
}

//functia de afisare pentru clasa offroad
ostream& Offroad::afisare(ostream& st)const{
    st<<" ID-ul: "<<this->get_id()<<endl;
    st<<" Categorie: "<<categorie<<endl;
    st<<" Nume: "<<nume<<endl<<" Pret: "<<pret<<endl<<" Combustibil: "<<combustibil<<endl;
    st<<" Cutie de viteze: "<<cutie<<endl<<" Locuri: "<<locuri<<endl<<" Usi: "<<nr_usi<<endl;
    st<<" Troliu: "<<troliu<<endl<<" Carlig de remorcare: "<<carlig<<endl;
    st<<" Capacitate Motor: "<<motor<<endl<<" Inaltime: "<<inaltime<<endl;
    st<<endl;
    return st;
}
void update(ofstream &f,Offroad &b)
{

    f<<b.get_id()<<","<<"B"<<","<<b.get_nume()<<","<<b.get_cutie()<<","<<b.get_combustibil()<<","<<b.get_pret()<<","<<b.get_usi()<<",";
    f<<b.get_locuri()<<","<<b.get_troliu()<<","<<b.get_carlig()<<","<<b.get_inaltime()<<","<<b.get_motor()<<",";
    if(b.get_valid())
        f<<"VALID\n";
    else
        f<<"INVALID\n";
}
//operatorul de afisare la clasa Offroad
ostream& operator<<(ostream& st,const Offroad& a)
{
    return a.afisare(st);
}

//destructor clasa Offroad
Offroad::~Offroad(){
    delete []troliu;
    delete []carlig;
}
