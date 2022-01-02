#ifndef PROIECT_OFFROAD_H
#define PROIECT_OFFROAD_H

class Offroad:public Masini{
    char* troliu;
    double motor,inaltime;
    char *carlig;
public:
    char* get_troliu(){return troliu;}
    Offroad(int,char *categorie, int locuri, char *nume, char *cutie, char *combustibil, double pret, int nr_usi,char* troliu,char* carlig,double motor,double inaltime);
    Offroad(const Offroad&a);
    double get_motor(){return motor;}double get_inaltime(){return inaltime;}
    Offroad& operator=(const Offroad&a);
    ostream& afisare(ostream& a)const;
    char* get_carlig(){return carlig;}
    friend ostream& operator<<(ostream& st,const Offroad&a);
    ~Offroad();
    friend void update(ofstream &f,Offroad &a);
};
#endif
