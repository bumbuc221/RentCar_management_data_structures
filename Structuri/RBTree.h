#ifndef PROIECT_RBTREE_H
#define PROIECT_RBTREE_H


#include <string>
#include <iostream>
#include <sstream>
#include <deque>
#include "HashMapInt.h"

using namespace std;


struct RBNode
{
    string key;
    int n;
    HashMapInt *p1=new HashMapInt(100);
    RBNode *p;
    RBNode *left;
    RBNode *right;
    enum color { RED, BLACK };
    color col;

    static RBNode* Nil; // sentinel leaf node

    RBNode(string k,int g=0,bool t= false, RBNode *l = Nil, RBNode *r = Nil, RBNode *parent = Nil, color c = RBNode::BLACK) :
    p(parent), left(l), right(r), col(c)
    {
        n=0;
        key=k;
        if(t)
            p1->Insert2(g,1);
        else
            p1->Insert2(g,0);
        n++;
    }
    bool verificaDisponibilitate()
    {
        return p1->verifica();
    }

    string toString()
    {
        ostringstream os;
        os << key << ((col == RBNode::RED) ? ":r" : ":b");
        return os.str();
    }
    void afis()
    {
        cout<<"Nume: "<<key<<endl;
        p1->afis();
    }

    ~RBNode()
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

RBNode* RBNode::Nil = new RBNode("0");


struct RBTree {
    RBNode *root;
    void afisare(RBNode *x)
    {
        RBNode *u=x;
        if(u!=RBNode::Nil) {
            afisare(u->left);
            u->afis();
            afisare(u->right);
        }
    }
    void LeftRotate(RBNode *x) {
        RBNode *y = x->right;
        x->right = y->left;
        if (y->left != RBNode::Nil)
            y->left->p = x;
        y->p = x->p;
        if (x->p == RBNode::Nil)
            root = y;
        else if (x == x->p->left)
            x->p->left = y;
        else
            x->p->right = y;
        y->left = x;
        x->p = y;
    }

    void RightRotate(RBNode *y) {
        RBNode *x = y->left;
        y->left = x->right;
        if (x->right != RBNode::Nil)
            x->right->p = y;
        x->p = y->p;
        if (y->p == RBNode::Nil)
            root = x;
        else if (y == y->p->left)
            y->p->left = x;
        else
            y->p->right = x;
        x->right = y;
        y->p = x;
    }

    RBTree() {
        root = RBNode::Nil;
    }

    ~RBTree() {
        delete root;
    }

    RBNode *createNode(string key) {
        return new RBNode(key);
    }

    bool isNil(RBNode *n) {
        return (n == RBNode::Nil);
    }

    RBNode *search(RBNode *w, string key) {
        if (isNil(w) || w->key.compare(key)==0)
            return w;
        return search((key < w->key) ? w->left : w->right, key);
    }

    void RBInsert(RBNode *z,int k,bool t) {
        int ok=0;
        RBNode *y = RBNode::Nil;
        RBNode *x = root;
        while (!isNil(x)) {
            y = x;
            if(x->key==z->key)
            {
                ok=1;
                if(t)
                    x->p1->Insert2(k,1);
                else
                    x->p1->Insert2(k,0);
                x->n++;
                break;
            }
            x = (z->key < x->key) ? x->left : x->right;
        }
        if(!ok) {
            z->p = y;
            if (isNil(y))
                root = z;
            else if (z->key < y->key)
                y->left = z;
            else
                y->right = z;
            z->left = z->right = RBNode::Nil;
            z->col = RBNode::RED;
            RBInsertFixup(z);
        }
    }

    void RBInsertFixup(RBNode *z) {
        while (z->p->col == RBNode::RED)
            if (z->p == z->p->p->left) {
                RBNode *y = z->p->p->right;
                if (y->col == RBNode::RED) {
                    z->p->col = RBNode::BLACK;
                    y->col = RBNode::BLACK;
                    z->p->p->col = RBNode::RED;
                    z = z->p->p;
                } else {
                    if (z == z->p->right) {
                        z = z->p;
                        LeftRotate(z);
                    }
                    z->p->col = RBNode::BLACK;
                    z->p->p->col = RBNode::RED;
                    RightRotate(z->p->p);
                }
            } else {
                RBNode *y = z->p->p->left;
                if (y->col == RBNode::RED) {
                    z->p->col = RBNode::BLACK;
                    y->col = RBNode::BLACK;
                    z->p->p->col = RBNode::RED;
                    z = z->p->p;
                } else {
                    if (z == z->p->left) {
                        z = z->p;
                        RightRotate(z);
                    }
                    z->p->col = RBNode::BLACK;
                    z->p->p->col = RBNode::RED;
                    LeftRotate(z->p->p);
                }
            }
        root->col = RBNode::BLACK;
    }

    RBNode* del(RBNode* z)
    {
        RBNode *y = (isNil(z->left) || isNil(z->right)) ? z : successor(z);
        RBNode *x = !isNil(y->left) ? y->left : y->right;
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
        }
        if (y->col == RBNode::BLACK)
            RBDeleteFixup(x);
    }

    void RBDeleteFixup(RBNode* x)
    {
        RBNode* w;
        while ((x != root) && (x->col == RBNode::BLACK))
        {
            if (x == x->p->left)
            {
                w = x->p->right;
                if(w->col == RBNode::RED)
                {
                    w->col = RBNode::BLACK;
                    x->p->col = RBNode::RED;
                    LeftRotate(x->p);
                    w = x->p->right;
                }
                if((w->left->col == RBNode::BLACK) && (w->right->col == RBNode::BLACK))
                {
                    w->col = RBNode::RED;
                    x = x->p;
                }
                else
                {
                    if(w->right->col == RBNode::BLACK)
                    {
                        w->left->col = RBNode::BLACK;
                        w->col = RBNode::RED;
                        RightRotate(w);
                        w = x->p->right;
                    }
                    w->col = x->p->col;
                    x->p->col = RBNode::BLACK;
                    w->right->col = RBNode::BLACK;
                    LeftRotate(x->p);
                    x = root;
                }
            }
            else
            {
                w = x->p->left;
                if(w->col == RBNode::RED)
                {
                    w->col = RBNode::BLACK;
                    x->p->col = RBNode::RED;
                    RightRotate(x->p);
                    w = x->p->left;
                }
                if((w->left->col == RBNode::BLACK) && (w->right->col == RBNode::BLACK))
                {
                    w->col = RBNode::RED;
                    x = x->p;
                }
                else
                {
                    if(w->left->col == RBNode::BLACK)
                    {
                        w->right->col = RBNode::BLACK;
                        w->col = RBNode::RED;
                        LeftRotate(w);
                        w = x->p->left;
                    }
                    w->col = x->p->col;
                    x->p->col = RBNode::BLACK;
                    w->left->col = RBNode::BLACK;
                    RightRotate(x->p);
                    x = root;
                }
            }
        }
        x->col = RBNode::BLACK;
    }

    RBNode* successor(RBNode* w)
    {
        if(isNil(w)) return w;
        RBNode* x = w;
        if (!isNil(x->right))
            return minimum(x->right);
        RBNode* y = x->p;
        while (!isNil(y) && x == y->right)
        {
            x = y;
            y = x->p;
        }
        return y;
    }

    RBNode* minimum(RBNode* w)
    {
        RBNode* x = w;
        while (!isNil(x->left))
            x = x->left;
        return x;
    }


};
#endif //PROIECT_RBTREE_H
