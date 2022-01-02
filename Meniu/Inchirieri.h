
#ifndef PROIECT_INCHIRIERI_H
#define PROIECT_INCHIRIERI_H
#include <string>
using namespace std;
class Inchirieri {
    int id,zile;
    string nume,seria,cnp,data,numar;
public:
    Inchirieri(int,int,string a,string b,string c,string d,string f);
    Inchirieri(Inchirieri&);
    friend ostream& operator<<(ostream& f,const Inchirieri&a);
    friend void update(ofstream &f,Inchirieri &a);
    int getId()
    {
        return id;
    }
    int getZile()
    {
        return zile;
    }
    string getNume()
    {
        return nume;
    }
    string getCnp()
    {
        return cnp;
    }
    string getData()
    {
        return data;
    }
    string getNumar()
    {
        return numar;
    }
    string getSeria()
    {
        return seria;
    }
};


#endif //PROIECT_INCHIRIERI_H
