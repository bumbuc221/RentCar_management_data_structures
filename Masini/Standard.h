
#ifndef PROIECT_STANDARD_H
#define PROIECT_STANDARD_H
class Standard:public Masini {
    int locuri_bagaje;
    char *reducere;
    char *navigatie;
public:
    Standard(int,char *categorie, int locuri, char *nume, char *cutie, char *combustibil, double pret, int nr_usi,int locuri_bagaje,char* reducere,char* navigatie);
    Standard(const Standard&a);
    Standard& operator=(const Standard&a);
    char* get_reducere(){return reducere;}
    ostream& afisare(ostream& a)const;
    int get_loc_bagaje(){return locuri_bagaje;}
    friend ostream& operator<<(ostream& st,const Standard&a);
    ~Standard();
    char* get_navigatie(){return navigatie;}
    friend void update(ofstream &f, Standard &a);
};



#endif //PROIECT_STANDARD_H
