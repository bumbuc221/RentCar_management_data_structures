
#ifndef PROIECT_HASHMAPINT_H
#define PROIECT_HASHMAPINT_H
class Id{
public:
    int k;
    int v;
    friend ostream& operator<<(ostream &c,const Id &a)
    {
        c << "Id: " <<a.k << "  ";
        if (a.v == 0)
            c<<"Indisponibil"<<endl;
        else
            c<<"Disponibil"<<endl;
        return c;
    }
    Id(int a,int b)
    {
        k=a;
        v=b;
    }
    Id(const Id &a)
    {
        this->k=a.k;
        this->v=a.v;
    }
    void set(int i)
    {
        v=i;
    }
};

class HashMapInt  {
private:
    int n;
    int size;
    Id **t;
public:
    HashMapInt(int n) {
        this->n=n;
        size=0;
        t = new Id * [n];
        for (int i = 0; i< n; i++) {
            t[i] = nullptr;
        }
    }
    int getN()
    {
        return n;
    }
    Id** getP()
    {
        return t;
    }
    void afis()
    {
        for(int i=0;i<n;i++)
            if(t[i]!= nullptr)
                cout<<*t[i]<<endl;
    }
    int HashFunc(int k) {
        return k % n;
    }
    void Insert2(int k,int v) {
        int h = HashFunc(k);
        while (t[h] != nullptr && t[h]->k != k) {
            h = HashFunc(h + 1);
        }
        if (t[h] != nullptr)
            delete t[h];
        t[h]=new Id(k,v);
        this->size++;
    }
    void Insert(int k, Id *v) {
        int h = HashFunc(k);
        while (t[h] != nullptr && t[h]->k != k) {
            h = HashFunc(h + 1);
        }
        if(t[h]== nullptr)
            size++;
        else
        if(t[h]->k!=k)
            size++;
        t[h]=new Id(*v);
        if(size==n)
        {
            int a=2*n;
            HashMapInt *aux= resize(a,*this);
            delete this;
            this->n=aux->n;
            this->t=new Id*[this->n];
            for(int i=0;i<this->n;i++)
            {
                if(aux->t[i]!= nullptr)
                    t[i]=new Id(*aux->t[i]);
                else
                    t[i]= nullptr;
            }
        }
    }
    friend HashMapInt* resize(int a,const HashMapInt &x)
    {
        HashMapInt *aux=new HashMapInt(a);
        for(int i=0;i<x.n;i++) {
            if(x.t[i]!= nullptr)
                aux->Insert2(x.t[i]->k, x.t[i]->v);
        }
        return aux;
    }
    bool verifica()
    {
        for(int i=0;i<n;i++)
            if(t[i]!= nullptr)
                if(t[i]->v!=0)
                    return true;
        return false;
    }
    Id* Search(int k) {
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
            return t[h];
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
    ~HashMapInt() {
        for (int i = 0; i < n; i++) {
            if (t[i] != nullptr) {
                delete &t[i];
            }
            delete[] t;
        }
    }
};
#endif //PROIECT_HASHMAPINT_H
