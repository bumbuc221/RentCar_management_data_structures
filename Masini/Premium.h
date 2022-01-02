
#ifndef PROIECT_PREMIUM_H
#define PROIECT_PREMIUM_H


class Premium:public Masini{
    int putere,capacitate_cilindrica;
    char* transmisie;
    char* pilot_automat;
public:
    int get_putere(){return putere;}int get_capacitate(){return capacitate_cilindrica;}
    Premium(int,char *categorie, int locuri, char *nume, char *cutie, char *combustibil, double pret, int nr_usi,int putere,int capacitate_cilindrica,char* transmisie,char* pilot_automat);
    Premium(const Premium&a);
    char* get_transmisie(){return transmisie;}
    Premium& operator=(const Premium&a);
    ostream& afisare(ostream& a)const;
    char* get_pilot(){return pilot_automat;}
    friend ostream& operator<<(ostream& st,const Premium&a);
    ~Premium();
    friend void update(ofstream &f,Premium &a);
};

#endif
