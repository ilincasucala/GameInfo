#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct juc
{
    char jucator1[50];
    char jucator2[50];
    juc *urm;
};
juc *primj=NULL;

struct nod
{
    int inf;
    nod *urm;
};
nod *prim=NULL;

struct nod1
{
    int carte;
    nod1 *urm;
    nod1 *ant;
};
nod1 *prim1=NULL;
nod1 *ultim1=NULL;

struct nod2
{
    int carte;
    nod2 *urm;
    nod2 *ant;
};
nod2 *prim2=NULL;
nod2 *ultim2=NULL;

void creare_pachet(nod *&prim, int v)
{
    nod *q;
    q=new nod;
    q->inf=v;
    q->urm=NULL;
    if(prim==NULL)
        prim=q;
    else
    {
        q->urm=prim;
        prim=q;
    }

}


void afisare(nod *prim)
{
    nod *q;
    if(prim==NULL) cout<<"lisata vida";
    q=prim;
    while(q!=NULL)
    {
        cout<<q->inf<<" ";
        q=q->urm;
    }
}


void impartire_carti(nod *prim,nod1 *&prim1,nod1 *&ultim1,nod2 *&prim2,nod2 *&ultim2)
{
    nod *q;
    q=prim;
    while(q!=NULL)
    {
       nod1 *p;
       nod2 *s;
       p=new nod1;
       s=new nod2;
       p->carte=q->inf;
       p->urm=NULL;
       p->ant=NULL;
       if(prim1==NULL) prim1=ultim1=p;
       else
       {
           p->urm=prim1;
           prim1->ant=p;
           prim1=p;
       }
       s->carte=q->urm->inf;
       s->urm=NULL;
       s->ant=NULL;
       if(prim2==NULL) prim2=ultim2=s;
       else
       {
           s->urm=prim2;
           prim2->ant=s;
           prim2=s;
       }
       q=q->urm->urm;
    }
}


void afisare_stiva1(nod1 *prim1)
{
    nod1 *q;
    if(prim1==NULL) cout<<"lisata vida";
    q=prim1;
    while(q!=NULL)
    {
        cout<<q->carte<<" ";
        q=q->urm;
    }
}
void afisare_stiva2(nod2 *prim2)
{
    nod2 *q;
    if(prim2==NULL) cout<<"lisata vida";
    q=prim2;
    while(q!=NULL)
    {
        cout<<q->carte<<" ";
        q=q->urm;
    }
}
bool verificare(nod1 *prim1,nod2 *prim2) //verificam daca este egalitate
{
    nod1 *q;
    nod2 *p;
    q=new nod1;
    p=new nod2;
    q=prim1;
    p=prim2;
    while(q!=NULL)
    {
        if(q->carte!=p->carte) return 1;
        else q=q->urm;
    }
    return 0;
}/
void adaugare1(nod1 *&prim1,nod1 *&ultim1,int x)
{
    nod1 *q;
    q=new nod1;
    q->carte=x;
    q->urm=NULL;
    if(prim1==NULL) prim1=ultim1=q;
    else
    {
        ultim1->urm=q;
        ultim1=q;
    }
}
void adaugare2(nod2 *&prim2,nod2 *&ultim2,int x)
{
    nod2 *q;
    q=new nod2;
    q->carte=x;
    q->urm=NULL;
    if(prim2==NULL) prim2=ultim2=q;
    else
    {
        ultim2->urm=q;
        ultim2=q;
    }
}
void stergere1(nod1 *&prim1)
{
    nod1 *q;
    if(prim1->urm==NULL) prim1=NULL;
    else
    {
        q=prim1;
        prim1=prim1->urm;
        delete(q);
    }
}
lalalal


void stergere2(nod2 *&prim2)
{
    nod2 *q;
    if(prim2->urm==NULL) prim2=NULL;
    else
    {
        q=prim2;
        prim2=prim2->urm;
        delete(q);
    }
}
int carte_potrivita(nod1 *&prim1,nod2 *&prim2,nod1 *&ultim1,nod2 *&ultim2,int x)
{
    int a=prim1->carte;
    int b=prim2->carte;

    if(a==b)
    {
        stergere1(prim1,ultim1);
        stergere2(prim2,ultim2);
        return 0;
    }
    if(a>=x && b<x)
    {
        adaugare1(prim1,ultim1,a);
        adaugare1(prim1,ultim1,b);
        stergere1(prim1,ultim1);
        stergere2(prim2,ultim2);
        return 1;

    }
    if(a<x && b>=x)
    {
        adaugare2(prim2,ultim2,b);
        adaugare2(prim2,ultim2,a);
        stergere1(prim1,ultim1);
        stergere2(prim2,ultim2);
        return 2;

    }
    if(a<x && b<x)
    {
        if(a>b)
        {
            adaugare1(prim1,ultim1,a);
            adaugare1(prim1,ultim1,b);
            stergere1(prim1,ultim1);
        stergere2(prim2,ultim2);
            return 1;

        }
        if(a<b)
        {
             adaugare2(prim2,ultim2,b);
             adaugare2(prim2,ultim2,a);
             stergere1(prim1,ultim1);
        stergere2(prim2,ultim2);
             return 2;

        }
    }
    if(a>x && b>x)
    {
        if(a>b)
        {
            adaugare2(prim2,ultim2,b);
             adaugare2(prim2,ultim2,a);
             stergere1(prim1,ultim1);
        stergere2(prim2,ultim2);
             return 2;

        }
        if(a<b)
        {
             adaugare1(prim1,ultim1,a);
            adaugare1(prim1,ultim1,b);
            stergere1(prim1,ultim1);
        stergere2(prim2,ultim2);
            return 1;
        }
    }
}/
void joc(nod1 *&prim1,nod1 *&ultim1,nod2 *&prim2,nod2 *&ultim2,int x)
{
    int x;
    srand(time(NULL));
    x=rand()%6+1;
    cout<<"numarul primit este:"<<" "<<x<<endl;
    nod1 *q;
    nod2 *p;
    q=new nod1;
    p=new nod2;
    q=prim1;

}

void verificare_carte()
{
    int x;
    srand(time(NULL));
            x=rand()%5+1;
            cout<<"numarul primit este:"<<" "<<x<<endl;
}


int mai_mare(nod1 *prim1,nod1 *ultim1,nod2 *prim2,nod2 *ultim2,int x)
{
    nod1 *q;
    q=new nod1;
    nod2 *p;
    p=new nod2;
    while()
}*/
void meniu(juc *&primj)
{
    juc *q;
    q=new juc;
    cout<<"jucator 1:";
    cin>>q->jucator1;
    cout<<endl;
    cout<<"jucator 2:";
    cin>>q->jucator2;
    cout<<endl;
    int v,n=20;
    srand(time(NULL));
    while(n!=0)
    {
        v=rand()%10+1;
        creare_pachet(prim,v);
        n--;
    }
    cout<<"pachet:"<<endl;
    afisare(prim);
    cout<<endl;
    impartire_carti(prim,prim1,ultim1,prim2,ultim2);
    cout<<"stiva jucator1:"<<endl;
    afisare_stiva1(prim1);
    cout<<endl;
    cout<<"stiva jucator2:"<<endl;
    afisare_stiva2(prim2);/
    cout<<endl;
    cout<<endl;
    cout<<"Exista posibilitatea de castig?"<<endl;
    if(verificare(prim1,prim2)==1)
    {
        cout<<"DA. SA JUCAM!"<<endl;
        cout<<endl;/
        int x;
        int a=10,b=10;//marimea fiecarei stive
        while(prim1!=NULL && prim2!=NULL && a>=x)
        {
            srand(time(NULL));
            x=rand()%5+1;
            cout<<"numarul primit este:"<<" "<<x<<endl;
            if(a<x && b>=x) cout<<"A castigat 2";
            if(a>=x && b<x)

        }
    }
    else cout<<"NU. EGALITATE. INCERCATI DINNOU";*/

}

///punem pachetul in stiva principala
int main()
{/*
    int x;
    srand(time(NULL));
            x=rand()%5+1;
            cout<<"numarul primit este:"<<" "<<x<<endl;*/
    meniu(primj);/*
    int v,n=20;
    srand(time(NULL));
    while(n!=0)
    {
        v=rand()%10+1;
        creare_pachet(prim,v);
        n--;
    }
    impartire_carti(prim,prim1,ultim1,prim2,ultim2);
    afisare(prim);
    cout<<endl;
    afisare_stiva1(prim1);
    cout<<endl;
    afisare_stiva2(prim2);*/
}




/*int main()
{
    int x;
    ///introducerea numelui jucatorilor
    numejucatori(prim);
    ///numar oarecare
    srand(time(NULL));
    x=rand()%5+1;
    cout<<"numarul primit este:"<<" "<<x;
    ///sfarsit numar oarecare


    return 0;
}
*/
