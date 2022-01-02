
#ifndef PROIECT_RBTreeIntINT_H
#define PROIECT_RBTreeIntINT_H


#include <string>
#include <iostream>
#include <sstream>
#include <deque>
#include "../Meniu/Inchirieri.cpp"

using namespace std;


struct Node
{
    int  key;
    Inchirieri *in;
    Node *p;
    Node *left;
    Node *right;
    enum color { RED, BLACK };
    color col;

    static Node* Nil; // sentinel leaf node

    Node(int k,Inchirieri *in= nullptr, Node *l = Nil, Node *r = Nil, Node *parent = Nil, color c = Node::BLACK) :
    p(parent), left(l), right(r), col(c)
    {
        key=k;
        if(in!= nullptr)
        this->in=new Inchirieri(*in);
        else
            this->in= nullptr;
    }
    
    string toString()
    {
        ostringstream os;
        os << key << ((col == Node::RED) ? ":r" : ":b");
        return os.str();
    }
    void afis()
    {
        cout<<*in<<endl;
    }

    ~Node()
    {
        if (this != Nil)
        {
            if(left != Nil)
                delete left;
            if(right != Nil)
                delete right;
        }
    }

};

Node* Node::Nil = new Node(0);


struct RBTreeInt {
    Node *root;
    void afisare(Node *x)
    {
        Node *u=x;
        if(u!=Node::Nil) {
            afisare(u->left);
            u->afis();
            afisare(u->right);
        }
    }
    void actualizare(ofstream &f,Node *x)
    {
        Node *u=x;
        if(u!=Node::Nil) {
            actualizare(f,u->left);
            update(f,*(u->in));
            actualizare(f,u->right);
        }
    }
    void LeftRotate(Node *x) {
        Node *y = x->right;
        x->right = y->left;
        if (y->left != Node::Nil)
            y->left->p = x;
        y->p = x->p;
        if (x->p == Node::Nil)
            root = y;
        else if (x == x->p->left)
            x->p->left = y;
        else
            x->p->right = y;
        y->left = x;
        x->p = y;
    }

    void RightRotate(Node *y) {
        Node *x = y->left;
        y->left = x->right;
        if (x->right != Node::Nil)
            x->right->p = y;
        x->p = y->p;
        if (y->p == Node::Nil)
            root = x;
        else if (y == y->p->left)
            y->p->left = x;
        else
            y->p->right = x;
        x->right = y;
        y->p = x;
    }

    RBTreeInt() {
        root = Node::Nil;
    }

    ~RBTreeInt() {
        delete root;
    }

    Node *createNode(int key) {
        return new Node(key);
    }

    bool isNil(Node *n) {
        return (n == Node::Nil);
    }

    Node *search(Node *w, int  key) {
        if (isNil(w) || w->key==key)
            return w;
        return search((key < w->key) ? w->left : w->right, key);
    }

    void RBInsert(Node *z) {
        Node *y = Node::Nil;
        Node *x = root;
        while (!isNil(x)) {
            y = x;
            x = (z->key < x->key) ? x->left : x->right;
        }
            z->p = y;
            if (isNil(y))
                root = z;
            else if (z->key < y->key)
                y->left = z;
            else
                y->right = z;
            z->left = z->right = Node::Nil;
            z->col = Node::RED;
            RBInsertFixup(z);
    }

    void RBInsertFixup(Node *z) {
        while (z->p->col == Node::RED)
            if (z->p == z->p->p->left) {
                Node *y = z->p->p->right;
                if (y->col == Node::RED) {
                    z->p->col = Node::BLACK;
                    y->col = Node::BLACK;
                    z->p->p->col = Node::RED;
                    z = z->p->p;
                } else {
                    if (z == z->p->right) {
                        z = z->p;
                        LeftRotate(z);
                    }
                    z->p->col = Node::BLACK;
                    z->p->p->col = Node::RED;
                    RightRotate(z->p->p);
                }
            } else {
                Node *y = z->p->p->left;
                if (y->col == Node::RED) {
                    z->p->col = Node::BLACK;
                    y->col = Node::BLACK;
                    z->p->p->col = Node::RED;
                    z = z->p->p;
                } else {
                    if (z == z->p->left) {
                        z = z->p;
                        RightRotate(z);
                    }
                    z->p->col = Node::BLACK;
                    z->p->p->col = Node::RED;
                    LeftRotate(z->p->p);
                }
            }
        root->col = Node::BLACK;
    }

    void del(Node* z)
    {
        Node *y = (isNil(z->left) || isNil(z->right)) ? z : successor(z);
        Node *x = !isNil(y->left) ? y->left : y->right;
        x->p = y->p;
        if(isNil(y->p))
        {
            root = x;
        }
        else
        {
            if (y == y->p->left)
                y->p->left = x;
            else
                y->p->right = x;
        }
        if (y != z)
        {
            z->key = y->key;
            z->in=new Inchirieri(*(y->in));
        }
        if (y->col == Node::BLACK)
            RBDeleteFixup(x);
    }

    void RBDeleteFixup(Node* x)
    {
        Node* w;
        while ((x != root) && (x->col == Node::BLACK))
        {
            if (x == x->p->left)
            {
                w = x->p->right;
                if(w->col == Node::RED)
                {
                    w->col = Node::BLACK;
                    x->p->col = Node::RED;
                    LeftRotate(x->p);
                    w = x->p->right;
                }
                if((w->left->col == Node::BLACK) && (w->right->col == Node::BLACK))
                {
                    w->col = Node::RED;
                    x = x->p;
                }
                else
                {
                    if(w->right->col == Node::BLACK)
                    {
                        w->left->col = Node::BLACK;
                        w->col = Node::RED;
                        RightRotate(w);
                        w = x->p->right;
                    }
                    w->col = x->p->col;
                    x->p->col = Node::BLACK;
                    w->right->col = Node::BLACK;
                    LeftRotate(x->p);
                    x = root;
                }
            }
            else
            {
                w = x->p->left;
                if(w->col == Node::RED)
                {
                    w->col = Node::BLACK;
                    x->p->col = Node::RED;
                    RightRotate(x->p);
                    w = x->p->left;
                }
                if((w->left->col == Node::BLACK) && (w->right->col == Node::BLACK))
                {
                    w->col = Node::RED;
                    x = x->p;
                }
                else
                {
                    if(w->left->col == Node::BLACK)
                    {
                        w->right->col = Node::BLACK;
                        w->col = Node::RED;
                        LeftRotate(w);
                        w = x->p->left;
                    }
                    w->col = x->p->col;
                    x->p->col = Node::BLACK;
                    w->left->col = Node::BLACK;
                    RightRotate(x->p);
                    x = root;
                }
            }
        }
        x->col = Node::BLACK;
    }

    Node* successor(Node* w)
    {
        if(isNil(w)) return w;
        Node* x = w;
        if (!isNil(x->right))
            return minimum(x->right);
        Node* y = x->p;
        while (!isNil(y) && x == y->right)
        {
            x = y;
            y = x->p;
        }
        return y;
    }

    Node* minimum(Node* w)
    {
        Node* x = w;
        while (!isNil(x->left))
            x = x->left;
        return x;
    }


};


#endif //PROIECT_RBTreeIntINT_H
