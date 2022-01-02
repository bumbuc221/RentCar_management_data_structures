

#include "Meniu.h"
int Meniu::nr=0;
Meniu::Meniu() {
    l=lungime();
    h=new HashMap(l);
    t=new RBTree();
    in=new RBTreeInt();
    citireFisier();
    citireFisierInchirieri();
}

int Meniu::lungime() {
    int l=0;
    char linie[200];
    char lini2[200];
    ifstream f("masini.txt");
    while(f.getline (linie,200)) {
        strcpy(lini2,linie);
        l++;
    }
    char* s = strtok(lini2,",");
    while(s)
    {
        Meniu::nr= atoi(s);
        s=strtok(nullptr,",");
        break;
    }
    Meniu::nr++;
    return l;
}

Standard* Meniu::citire_standard(char *linie) {
    Standard* a;
    int k;
    char categorie[5];
    int locuri;
    char nume[50],cutie[20],combustibil[20];
    double pret;
    int nr_usi;
    char reducere[20],navigatie[30];
    int nr_bagaje;
    char*p = strtok(linie,",\n");
    int j=0,ok=1;
    while(p)
        {
            switch (j) {
                case 0:
                    k= atoi(p);
                    break;
                case 1:
                    strcpy(categorie,p);
                    break;
                case 2:
                    strcpy(nume,p);
                    break;
                case 3:
                    strcpy(cutie,p);
                    break;
                case 4:
                    strcpy(combustibil,p);
                    break;
                case 5:
                    pret= atoi(p);
                    break;
                case 6:
                    nr_usi=atoi(p);
                    break;
                case 7:
                    locuri= atoi(p);
                    break;
                case 8:
                    nr_bagaje=atoi(p);
                    break;
                case 9:
                    strcpy(reducere,p);
                    break;
                case 10:
                    strcpy(navigatie,p);
                    break;
                case 11:
                    if(strcmp(p,"VALID"))
                        ok=0;
                    break;
            }
            j++;
            p=strtok(nullptr,",\n");
        }
        a=new Standard(k,categorie,locuri,nume,cutie,combustibil,pret,nr_usi,nr_bagaje,reducere,navigatie);
        if(!ok)
            a->set_valid(0);
    return a;
}
Offroad* Meniu::citire_offroad(char *linie)
{
    Offroad* a;
    int k;
    char categorie[5];
    int locuri;
    char nume[50],cutie[20],combustibil[20];
    double pret;
    int nr_usi;
    char troliu[20],carlig[30];
    double inaltime,motor;
    ifstream f("masini_offroad.txt");
     char*p = strtok(linie,",\n");
        int j=0,ok=1;
        while(p)
        {
            switch (j) {
                case 0:
                    k= atoi(p);
                case 1:
                    strcpy(categorie,p);
                    break;
                case 2:
                    strcpy(nume,p);
                    break;
                case 3:
                    strcpy(cutie,p);
                    break;
                case 4:
                    strcpy(combustibil,p);
                    break;
                case 5:
                    pret= atoi(p);
                    break;
                case 6:
                    nr_usi=atoi(p);
                    break;
                case 7:
                    locuri= atoi(p);
                    break;
                case 8:
                    strcpy(troliu,p);
                    break;
                case 9:
                    strcpy(carlig,p);
                    break;
                case 10:
                    inaltime=atoi(p);
                    break;
                case 11:
                    motor=atoi(p);
                    break;
                case 12:
                    if(strcmp(p,"VALID"))
                        ok=0;
                    break;
            }
            j++;
            p= strtok(nullptr,",\n");
        }
        a=new Offroad(k,categorie,locuri,nume,cutie,combustibil,pret,nr_usi,troliu,carlig,motor,inaltime);
        if(!ok)
            a->set_valid(0);
    return a;
}
Premium* Meniu::citire_premium(char *linie)
{
    Premium* a;
    int k;
    char categorie[5];
    int locuri;
    char nume[50],cutie[20],combustibil[20];
    double pret;
    int nr_usi;
    char transmisie[20],pilot_automat[30];
    double putere,capacitate_cilindrica;
        char*p = strtok(linie,",\n");
        int j=0,ok=1;
        while(p)
        {
            switch (j) {
                case 0:
                    k= atoi(p);
                    break;
                case 1:
                    strcpy(categorie,p);
                    break;
                case 2:
                    strcpy(nume,p);
                    break;
                case 3:
                    strcpy(cutie,p);
                    break;
                case 4:
                    strcpy(combustibil,p);
                    break;
                case 5:
                    pret= atoi(p);
                    break;
                case 6:
                    nr_usi=atoi(p);
                    break;
                case 7:
                    locuri= atoi(p);
                    break;
                case 8:
                    strcpy(transmisie,p);
                    break;
                case 9:
                    strcpy(pilot_automat,p);
                    break;
                case 10:
                    putere=atoi(p);
                    break;
                case 11:
                    capacitate_cilindrica=atoi(p);
                    break;
                case 12:
                    if(strcmp(p,"VALID"))
                        ok=0;
                    break;
            }
            j++;
            p= strtok(nullptr,",\n");
        }
        a=new Premium(k,categorie,locuri,nume,cutie,combustibil,pret,nr_usi,putere,capacitate_cilindrica,transmisie,pilot_automat);
        if(!ok)
            a->set_valid(0);
    return a;
}
Inchirieri* Meniu::citire_inchiriere(char* linie)
{
    int id,zile;
    string nume,seria,cnp,data,numar;
        char*p = strtok(linie,",\n");
        int j=0;
        while(p) {
            switch (j) {
                case 0:
                    id = atoi(p);
                    break;
                case 1:
                    seria=p;
                    break;
                case 2:
                    cnp=p;
                    break;
                case 3:
                    nume=p;
                    break;
                case 4:
                    numar=p;
                    break;
                case 5:
                    data=p;
                    break;
                case 6:
                    zile= atoi(p);
                    break;
            }
            j++;
            p = strtok(nullptr, ",\n");
        }
        Inchirieri *a=new Inchirieri(id,zile,seria,cnp,nume,numar,data);
    return a;
    }
void Meniu::citireFisierInchirieri()
{
    char *linie=new char[200];
    ifstream f("inchirieri.txt");
    while(f.getline(linie,200)) {
        char linie2[200];
        strcpy(linie2, linie);
        int j = 0;
        int key = 0;
        char *p = strtok(linie, ",");
        while (p) {
            if (j == 0)
                key = atoi(p);
            else {
                if (j == 1) {
                    Inchirieri *x = citire_inchiriere(linie2);
                    Node *aux = new Node(key, x);
                    this->in->RBInsert(aux);
                    break;
                }
            }
            j++;
            p = strtok(nullptr, ",");
        }
    }
    f.close();
}
void Meniu::citireFisier() {
    char *linie=new char[200];
    ifstream f("masini.txt");
    while(f.getline(linie,200))
    {
        char linie2[200];
        strcpy(linie2,linie);
        int j=0;
        int key=0;
        bool valid=false;
        char *p= strtok(linie,",");
        while(p)
        {
            if(j==0)
                key= atoi(p);
            else {
                if (j == 1) {
                    if (strcmp(p, "A") == 0) {
                        Standard *s = citire_standard(linie2);
                        h->Insert(key, s);
                        if (s->get_valid())
                            valid = true;
                        string nume(s->get_nume());
                        RBNode *x = new RBNode(nume, key, valid);
                        t->RBInsert(x, key, valid);
                        break;
                    } else {
                        if (strcmp(p, "B") == 0) {
                            Offroad *s2 = citire_offroad(linie2);
                            h->Insert(key, s2);
                            if (s2->get_valid())
                                valid = true;
                            string nume(s2->get_nume());
                            RBNode *x = new RBNode(nume, key, valid);
                            t->RBInsert(x, key, valid);
                            break;
                        } else {
                            Premium *e = citire_premium(linie2);
                            h->Insert(key, e);
                            if (e->get_valid())
                                valid = true;
                            string nume(e->get_nume());
                            RBNode *x = new RBNode(nume, key, valid);
                            t->RBInsert(x, key, valid);
                            break;
                        }
                    }
                }
            }
            j++;
            p=strtok(nullptr,",");
        }
    }
}
void Meniu::scriereFisier() {
    ofstream f("masini.txt");
    for(int i=0;i<h->getN();i++) {
        if (h->getP()[i]!= nullptr) {
            if (dynamic_cast<Standard *>(h->getP()[i]->v)) {
                Standard *x = dynamic_cast<Standard *>(h->getP()[i]->v);
                update(f, *x);
            } else if (dynamic_cast<Offroad *>(h->getP()[i]->v)) {
                Offroad *x = dynamic_cast<Offroad *>(h->getP()[i]->v);
                update(f, *x);
            } else if (dynamic_cast<Premium *>(h->getP()[i]->v)) {
                Premium *x = dynamic_cast<Premium *>(h->getP()[i]->v);
                update(f, *x);
            }
        }
    }
    f.close();
}
void Meniu::scriereFisierInchirieri()
{
    ofstream f("inchirieri.txt");
    in->actualizare(f,in->root);
    f.close();
}

Standard* citire1(int n)
{
    Standard* a;
    int locuri;
    char c[5];
    strcpy(c,"A");
    char nume[50],cutie[20],combustibil[20];
    double pret;
    int nr_usi;
    char reducere[20],navigatie[30];
    int nr_bagaje;
        cout<<"Nume: ";cin.getline(nume,50);
        cout<<"Cutie: ";cin.getline(cutie,20);
        cout<<"Combustibil: ";cin.getline(combustibil,20);
        cout<<"Navigatie: ";cin.getline(navigatie,30);
        cout<<"Reducere: ";cin.getline(reducere,20);
        cout<<"Pret: ";cin>>pret;
        cout<<"Locuri: ";cin>>locuri;
        cout<<"Numar usi: ";cin>>nr_usi;
        cout<<"Numar loc bagaje: ";cin>>nr_bagaje;
        cin.get();
        a=new Standard(n,c,locuri,nume,cutie,combustibil,pret,nr_usi,nr_bagaje,reducere,navigatie);
    return a;
}
Offroad* citire2(int n)
{
    Offroad * a;
    int locuri;
    char nume[50],cutie[20],combustibil[20];
    double pret;
    int nr_usi;
    char c[5];
    strcpy(c,"B");
    char troliu[20],carlig[10];double motor,inaltime;
    cout<<" Nume: ";cin.getline(nume,50);
    cout<<" Cutie: ";cin.getline(cutie,20);
    cout<<" Combustibil: ";cin.getline(combustibil,20);
    cout<<" Troliu: ";cin.getline(troliu,20);
    cout<<" Carling: ";cin.getline(carlig,10);
    cout<<" Pret: ";cin>>pret;
    cout<<" Locuri: ";cin>>locuri;
    cout<<" Numar usi: ";cin>>nr_usi;
    cout<<" Motor capacitate: ";cin>>motor;
    cout<<" Inaltime: ";cin>>inaltime;
    cin.get();
    a=new Offroad(n,c,locuri,nume,cutie,combustibil,pret,nr_usi,troliu,carlig,motor,inaltime);
    return a;
}

Premium* citire3(int n)
{
    Premium * a;
    int locuri;
    char nume[50],cutie[20],combustibil[20];
    double pret;
    int nr_usi;
    char c[5];
    strcpy(c,"C");
    int putere,capacitate_cilindrica;
    char transmisie[20];
    char pilot_automat[20];
    cout<<" Nume: ";cin.getline(nume,50);
    cout<<" Cutie: ";cin.getline(cutie,20);
    cout<<" Combustibil: ";cin.getline(combustibil,20);
    cout<<" Transmisie: ";cin.getline(transmisie,20);
    cout<<" Pilot automat: ";cin.getline(pilot_automat,20);
    cout<<" Pret: ";cin>>pret;
    cout<<" Locuri: ";cin>>locuri;
    cout<<" Numar usi: ";cin>>nr_usi;
    cout<<" Motor capacitate: ";cin>>capacitate_cilindrica;
    cout<<" Motor Putere: ";cin>>putere;
    cin.get();
    a=new Premium(n,c,locuri,nume,cutie,combustibil,pret,nr_usi,putere,capacitate_cilindrica,transmisie,pilot_automat);
    return a;
}


void meniu()
{
    cout<<endl<<"      Inchirieri masini"<<endl<<endl;
    cout<<" ---------------------------"<<endl;
    cout<<" |           Meniu         |"<<endl;
    cout<<" | 1.  Masini disponibile. |"<<endl;
    cout<<" | 2.  Cautare dupa nume.  |"<<endl;
    cout<<" | 3.  Informatii masini.  |"<<endl;
    cout<<" | 4.  Inchiriere masina.  |"<<endl;
    cout<<" | 5.  Returnare masina.   |"<<endl;
    cout<<" | 6.  Adaugare masina.    |"<<endl;
    cout<<" | 7.  Stergere masina.    |"<<endl;
    cout<<" |     Exit, apasa ESC.    |"<<endl;
    cout<<" ---------------------------"<<endl<<endl;
    cout<<"     Alegeti o optiune: ";

}

void optiuni() {
    Meniu *a=new Meniu();
    char key;
    int ok = 1;
    int cod_ascii;
    while (ok) {
        meniu();
        while (true) {
            key = getch();
            cod_ascii = key;
            if (cod_ascii == 27 || cod_ascii == 49 || cod_ascii == 50 || cod_ascii == 51 || cod_ascii == 52 || cod_ascii == 53 || cod_ascii == 54 || cod_ascii == 55 || cod_ascii == 56)
                break;
            system("cls");
            meniu();
        }
        switch (cod_ascii) {
            case 49: {
                system("cls");
                char s[5];
                cout<<endl<<"           Masini disponibile  "<<endl<<endl<<endl<<endl;
                cout << " Avem urmatoarele categorii:" << endl << endl;
                cout << " Seria A Standard cu pretul intre 50-500 lei/zi." << endl;
                cout << " Seria B Offroad" << endl;
                cout << " Seria C Premium cu pretul intre 500-1000 lei/zi" << endl << endl;
                cout << " Introduceti seria: ";
                cin.getline(s, 5);
                bool afirma = false;
                while (true) {
                    if (strcmp(s, "A") == 0 || strcmp(s, "B") == 0 || strcmp(s, "C") == 0) {
                        system("cls");
                        cout<<"           Masini disponibile  "<<endl<<endl<<endl<<endl;
                        afirma = a->get_HasMap()->disponibile(s);
                        break;
                    } else {
                        cout << " Introduceti seria corecta: ";
                        cin.getline(s, 5);
                    }
                }
                if (!afirma)
                    cout << endl << " Nu avem masini disponibile din seria aceasta." << endl;
                cout << endl << " Apasati enter pentru a continua.";
                cin.get();
                system("cls");
                break;
            }
            case 50:
            {
                system("cls");
                char s1[100];
                cout<<endl<<"          Cautare masina   "<<endl<<endl<<endl<<endl;
                cout<<" Introduceti numele masinii: ";
                cin.getline(s1,100);
                RBNode *fd=a->get_RBTree()->search(a->get_RBTree()->root,s1);
                if(fd!= nullptr) {
                    if(fd==RBNode::Nil)
                        cout<<" Nu exista masina cu acest nume!"<<endl;
                    else if (fd->verificaDisponibilitate())
                        fd->afis();
                    else
                        cout << " Nu exista masini disponibile!"<<endl;
                }
                else
                    cout<<" Nu exista masina cu acest nume!"<<endl;
                cout<<endl<<" Apasati enter pentru a continua.";
                cin.get();
                system("cls");
                break;
            }
            case 51:
            {
                int n;
                system("cls");
                cout<<endl<<"          Informatii masini  "<<endl<<endl<<endl<<endl;
                cout<<endl<<" Introduceti id-ul masinii: ";cin>>n;cin.get();
                cout<<endl;
                a->get_HasMap()->SearchKey(n);
                cout<<endl<<" Apasati enter pentru a continua.";
                cin.get();
                system("cls");
                break;
            }
            case 52:
            {
                system("cls");
                cout<<endl<<"          Inchiriere masina  "<<endl<<endl<<endl<<endl;
                int id,zile;
                string data,nume,cnp,numar,serie;
                cout<<" Introduceti id-ul masinii: ";cin>>id;cin.get();
                while (true) {
                    if (id<=Meniu::nr && a->get_HasMap()->Search(id)!= nullptr) {
                        if(a->get_HasMap()->Search(id)->get_valid()==0)
                        {
                            cout<<endl<<" Masina indisponibila!";
                            break;
                        }
                       cout<<" Nume: ";cin>>nume;
                       cout<<" CNP: ";cin>>cnp;
                       while(true)
                       {
                           if(cnp.size()<13) {
                               cout<<" CNP prea scurt!"<<endl;
                               cout << " CNP: ";
                               cin >> cnp;
                           }
                           else
                               break;
                       }
                       cout<<" Nr. telefon: ";cin>>numar;
                       data=__DATE__;
                       cout<<" Nr de zile: ";cin>>zile;cin.get();
                       if(a->get_HasMap()->serie(id)!= nullptr)
                       serie=a->get_HasMap()->serie(id);
                       a->get_HasMap()->Search(id)->set_valid(0);
                       Inchirieri *x=new Inchirieri(id,zile,serie,cnp,nume,numar,data);
                       Node *d=new Node(id,x);
                       a->get_Rb()->RBInsert(d);
                       Masini *g=a->get_HasMap()->Search(id);
                       cout<<endl<<endl<<endl<<"       Tichet"<<endl<<endl;
                       cout<<" Nume masina: "<<g->get_nume()<<endl;
                       cout<<" Id: "<<id<<endl;
                       cout<<" Pret/zi: "<<g->get_pret()<<endl;
                       cout<<" Pret "<<zile<<"/zile "<<zile*g->get_pret()<<" lei"<<endl;
                       cout<<" Nume: "<<nume<<endl;
                       cout<<" Nr. telefon: "<<numar<<endl;
                       cout<<" Data inchiriere: "<<data<<endl<<endl;
                       a->scriereFisierInchirieri();
                       break;
                    } else {
                        cout << " Introduceti id-ul corect: ";cin>>id;cin.get();
                    }
                }
                cout<<endl<<" Apasati enter pentru a continua.";
                cin.get();
                system("cls");
                break;
            }
            case 53: {
                system("cls");
                int id;
                string cnp;
                cout<<endl<<"          Returnare masina"<<endl<<endl<<endl<<endl;
                cout<<" Introduceti id-ul masini: ";cin>>id;
                Node* aux=a->get_Rb()->search(a->get_Rb()->root,id);
                if(aux!=Node::Nil)
                {
                    cin.get();
                    cout<<" Introduceti cnp:";cin>>cnp;
                    while(true)
                    {
                        if(cnp.size()<13) {
                            cout<<" CNP prea scurt!"<<endl;
                            cout << " Introduceti cnp: ";
                            cin >> cnp;
                        }
                        else
                            break;
                    }
                    while(true)
                    {
                        if(cnp.compare(aux->in->getCnp()))
                        {
                            cout<<" CNP incorect ! "<<endl;
                            cout << " Introduceti cnp: ";
                            cin >> cnp;
                        }
                        else
                            break;
                    }
                    cin.get();
                    system("cls");
                    cout<<endl<<endl<<endl<<"       Tichet"<<endl;
                    cout<<endl<<endl<<"     Nume:"<<aux->in->getNume()<<endl;
                    cout<<"     CNP: "<<cnp<<endl;
                    cout<<"     Nr zile inchiriere: "<<aux->in->getZile()<<endl;
                    cout<<endl<<endl<<endl<<endl<<endl<<endl<<"          Returnat cu succes!"<<endl;
                    Masini *x=a->get_HasMap()->Search(id);
                    x->set_valid(1);
                    string nume(x->get_nume());
                    RBNode *aux2=a->get_RBTree()->search(a->get_RBTree()->root,nume);
                    aux2->p1->Search(id)->set(1);
                    a->get_Rb()->del(aux);
                    a->scriereFisierInchirieri();
                    a->scriereFisier();
                }
                else
                    system("cls"),cout<<endl<<" Id masina incorect, nu exista inchiriere pe acest id!"<<endl,cin.get();
                cout<<endl<<" Apasati enter pentru a continua.";
                cin.get();
                system("cls");
                break;
            }
            case 54:
            {
                system("cls");
                char s[5];
                cout<<endl<<"          Adaugare masina"<<endl<<endl<<endl<<endl;
                cout << " Introduceti seria: ";
                cin.getline(s, 5);
                while (true) {
                    if (strcmp(s, "A") == 0 || strcmp(s, "B") == 0 || strcmp(s, "C") == 0) {
                        {
                            system("cls");
                            cout<<endl<<"          Adaugare masina"<<endl<<endl<<endl<<endl;
                            if(strcmp(s,"A")==0)
                            {
                                Standard *x= citire1(Meniu::nr);
                                a->get_HasMap()->Insert(Meniu::nr,x);
                                string nume(x->get_nume());
                                RBNode *aux=new RBNode(nume,Meniu::nr,true);
                                a->get_RBTree()->RBInsert(aux,Meniu::nr, true);
                            }
                            else
                            {
                                if(strcmp(s,"B")==0) {
                                    Offroad *x = citire2(Meniu::nr);
                                    a->get_HasMap()->Insert(Meniu::nr,x);
                                    string nume(x->get_nume());
                                    RBNode *aux=new RBNode(nume,Meniu::nr,true);
                                    a->get_RBTree()->RBInsert(aux,Meniu::nr, true);
                                }
                                else
                                {
                                    Premium *x= citire3(Meniu::nr);
                                    a->get_HasMap()->Insert(Meniu::nr,x);
                                    string nume(x->get_nume());
                                    RBNode *aux=new RBNode(nume,Meniu::nr,true);
                                    a->get_RBTree()->RBInsert(aux,Meniu::nr, true);
                                }
                            }
                            Meniu::nr++;
                            cout<<endl<<" Adaugat cu succes cu id-ul "<<Meniu::nr-1<<" !"<<endl;
                            a->scriereFisier();
                            break;
                        }
                    } else {
                        cout << " Introduceti seria corecta: ";
                        cin.getline(s, 5);
                    }
                }
                cout<<endl<<" Apasati enter pentru a continua.";
                cin.get();
                system("cls");
                break;
            }
            case 55:{
                system("cls");
                int id;
                string cnp;
                cout<<endl<<"          Stergere masina"<<endl<<endl<<endl<<endl;
                cout<<" Introduceti id-ul masini: ";cin>>id;cin.get();
                Masini *aux=a->get_HasMap()->Search(id);
                if(aux!= nullptr) {
                    char s[5];
                    cout << " Doriti sa stergeti masina cu id-ul " << id << "? " << endl;
                    cout << endl<<" Introduceti DA daca doriti sa continuati sau NU daca doriti sa iesiti: ";
                    cin.getline(s, 5);
                    while (true) {
                        if (strcmp(s, "DA") == 0 || strcmp(s, "NU") == 0) {
                            {
                                if(strcmp(s,"DA")==0) {
                                    system("cls");
                                    a->get_RBTree()->search(a->get_RBTree()->root, aux->get_nume())->p1->Remove(id);
                                    a->get_HasMap()->Remove(id);
                                    a->scriereFisier();
                                    cout << " Masina a fost stearsa cu succes!" << endl;
                                    break;
                                }
                                else
                                    break;
                            }
                        } else {
                            cout << " Introduceti DA daca doriti sa continuati sau NU daca doriti sa iesiti: ";
                            cin.getline(s, 5);
                        }

                    }
                }
                else
                {
                    system("cls"),cout<<endl<<" Id masina incorect, nu exista masina cu acest id!"<<endl,cin.get();
                }
                cout<<endl<<" Apasati enter pentru a continua.";
                cin.get();
                system("cls");
                break;
            }
            case 27:
                a->scriereFisier();
                system("cls");
                ok=0;
                break;
        }

    }
}