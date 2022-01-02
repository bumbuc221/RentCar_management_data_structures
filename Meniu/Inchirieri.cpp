
#include "Inchirieri.h"
#include <string>
using namespace std;
Inchirieri::Inchirieri(int id,int zile,string a, string b, string c,string d,string f) {
    this->id=id;
    seria=a;
    cnp=b;
    nume=c;
    numar=d;
    data=f;
    this->zile=zile;
}
Inchirieri::Inchirieri(Inchirieri &a) {
    this->cnp=a.cnp;
    this->nume=a.nume;
    this->seria=a.seria;
    this->zile=a.zile;
    this->numar=a.numar;
    this->data=a.data;
    this->id=a.id;
    this->zile=a.zile;
}
ostream& operator<<(ostream& f,const Inchirieri&a)
{
    f<<"ID Masina: "<<a.id<<endl;
    f<<"Categorie: "<<a.seria<<endl;
    f<<"Nume Utilizator: "<<a.nume<<endl;
    f<<"CNP: "<<a.cnp<<endl;
    f<<"Nr. telefon: "<<a.numar<<endl;
    f<<"Nr. zile inchiriat: "<<a.zile<<endl;
    f<<"Data inchirierii: "<<a.data<<endl;
}
void update(ofstream &f,Inchirieri &a)
{
    f<<a.id<<","<<a.seria<<","<<a.cnp<<","<<a.nume<<","<<a.numar<<","<<a.data<<","<<a.zile<<"\n";
}