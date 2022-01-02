
#include "../Masini/Masini.h"
#include "../Masini/Offroad.h"
#include "../Masini/Premium.h"
#include "../Masini/Standard.h"
#ifndef PROIECT_HASHMAP_H
#define PROIECT_HASHMAP_H

class Pereche{
public:
    int k;
    Masini *v;
    friend ostream& operator<<(ostream &c,const Pereche &a)
    {
        c<<*a.v;
        return c;
    }
    Pereche(int k, Premium *v) {
        this->k= k;
        this->v = new Premium(*v);
    }
    Pereche(int k, Offroad *v) {
        this->k= k;
        this->v = new Offroad(*v);
    }
    Pereche(int k,Standard *v) {
        this->k= k;
        this->v = new Standard(*v);
    }
    Pereche(const Pereche &a)
    {
        this->k=a.k;
        this->v=a.v;
    }
     ~Pereche()
    {
        delete v;
    }
    Masini* getMasina()
    {
        return v;
    }
};

class HashMap {
private:
    int n;
    int size;
    Pereche **t;
public:
    HashMap(int n) {
        this->n=n;
        size=0;
        t = new Pereche * [n];
        for (int i = 0; i< n; i++) {
            t[i] = nullptr;
        }
    }
    int getN()
    {
        return n;
    }
    Pereche** getP()
    {
        return t;
    }
    char* serie(int z)
    {
        for(int i=0;i<n;i++)
            if(t[i]!= nullptr)
            if(t[i]->k==z)
            {
                return t[i]->v->get_categorie();
            }
        return nullptr;
    }
    void afis()
    {
        for(int i=0;i<n;i++)
            if(t[i]!= nullptr)
            cout<<*t[i]<<endl;
    }
    bool disponibile(char *d)
    {
        bool ok=false;
        for(int i=0;i<n;i++)
        {
            if(t[i]!= nullptr && strcmp(t[i]->v->get_categorie(),d)==0 && t[i]->v->get_valid()) {
                cout << *t[i];
                ok = true;
            }
        }
        return ok;
    }
    int HashFunc(int k) {
        return k % n;
    }
    void Insert2(int k, Masini *v) {
        int h = HashFunc(k);
        while (t[h] != nullptr && t[h]->k != k) {
            h = HashFunc(h + 1);
        }
        if (t[h] != nullptr)
            delete t[h];
        if (dynamic_cast<Standard *>(v))
            t[h] = new Pereche(k, dynamic_cast<Standard *>(v));
        else if (dynamic_cast<Premium *>(v))
            t[h] = new Pereche(k, dynamic_cast<Premium *>(v));
        else
            t[h] = new Pereche(k, dynamic_cast<Offroad *>(v));
        this->size++;
    }
    void Insert(int k, Masini *v) {
        int h = HashFunc(k);
        while (t[h] != nullptr && t[h]->k != k) {
            h = HashFunc(h + 1);
        }
        if(t[h]== nullptr)
            size++;
        else
        if(t[h]->k!=k)
            size++;
        if (t[h] != nullptr)
            delete t[h];
        if(dynamic_cast<Standard*>(v))
            t[h] = new Pereche(k,dynamic_cast<Standard *>(v));
        else
            if(dynamic_cast<Premium*>(v))
                t[h]=new Pereche(k,dynamic_cast<Premium*>(v));
            else
                t[h]=new Pereche(k,dynamic_cast<Offroad*>(v));
        if(size==n)
        {
            int a=2*n;
            HashMap *aux= resize(a,*this);

            this->n=aux->n;
            this->t=new Pereche*[aux->n];
            for(int i=0;i<this->n;i++)
            {
                if(aux->t[i]!= nullptr)
                t[i]=new Pereche(*aux->t[i]);
                else
                    t[i]= nullptr;
            }
        }
    }
    friend HashMap* resize(int a,const HashMap &x)
    {
        HashMap *aux=new HashMap(a);
        for(int i=0;i<x.n;i++) {
            if(x.t[i]->v!= nullptr)
            aux->Insert2(x.t[i]->k, x.t[i]->v);
        }
        return aux;
    }
    void SearchKey(int k) {
        int ok=0;
        int h = HashFunc(k);
        while (t[h] != nullptr && t[h]->k != k) {
            if(h==n-1)
            {ok=1;break;}
            h = HashFunc(h + 1);
        }
        if (t[h] == nullptr || ok==1)
            cout<<"Nu exista";
        else
            cout<<*t[h]->v;
    }
    Masini* Search(int k)
    {
        int ok=0;
        int h = HashFunc(k);
        while (t[h] != nullptr && t[h]->k != k) {
            if(h==n-1)
            {ok=1;break;}
            h = HashFunc(h + 1);
        }
        if (t[h] == nullptr || ok==1)
            return nullptr;
        else
            return t[h]->v;
    }
    void Remove(int k) {
        int h = HashFunc(k);
        while (t[h] != nullptr) {
            if (t[h]->k == k)
                break;
            h = HashFunc(h + 1);
        }
        if (t[h] == nullptr) {
            cout<<"Nu exista masina cu id-ul "<<k<<endl;
            return;
        } else {
            t[h]= nullptr;
        }
    }
    ~HashMap() {
        for (int i = 0; i < n; i++) {
            if (t[i] != nullptr) {
                delete &t[i];
            }
            delete[] t;
        }
    }
};
#endif //PROIECT_HASHMAP_H
