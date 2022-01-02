
#ifndef PROIECT_MASINI_H
#define PROIECT_MASINI_H


#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;

class Masini {
protected:
    int id_v;
    char* categorie;
    int locuri;
    char* nume,*cutie,*combustibil;
    double pret;
    int nr_usi;
    int valid;
public:
    static int id;
    Masini(int ID,char*categorie,int locuri,char*nume,char*cutie,char* combustibil,double pret,int nr_usi);
    Masini(const Masini& a);
    Masini& operator=(const Masini&a);
    int get_locuri();
    char* get_cutie();
    char* get_combustibil();
    void delete_();
    virtual ~Masini();
    virtual ostream& afisare(ostream&a)const;
    int get_usi();
    void init(const Masini&a);
    virtual int get_id()const{return id_v;}
    char* get_categorie(){return categorie;}
    friend ostream& operator<<(ostream&st,const Masini&a);
    char* get_nume()
    {
        return nume;
    }
    double get_pret()
    {
        return pret;
    }
    void set_valid(int n)
    {
        if(n==0)
            valid=0;
        else
            valid=1;
    }
    int get_valid()
    {
        return valid;
    }
    void set_id(int n)
    { id_v=n;}
};


#endif //PROIECT_MASINI_H
