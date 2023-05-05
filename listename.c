#include"listename.h"
#include<stdlib.h>
#include<assert.h>
#include<string.h>
// initialisation
struct liste* initialisation()
{
    struct liste* l;
    l=(struct liste*)malloc(sizeof(struct liste));
    assert(l!=NULL);
    l->first=NULL;
    l->last=NULL;
    l->dim=0;
    return l;
}
// test
int vide(struct liste l)
{
    return (l.first==NULL && l.last==NULL);
}

//ajouter
void add_empty_liste(struct liste* l,char* n)
{
    assert(l!=NULL);
    struct element* e;
    e=(struct element*)malloc(sizeof(struct element));
    assert(e!=NULL);
    assert(vide(*l));
    e->next=NULL;
    strcpy((e->name),n);
    l->first=e;
    l->last=e;
    l->dim++;
}

void add_first_liste(struct liste*l,char* n)
{
    assert(l!=NULL);
    struct element* e;
    e=(struct element*)malloc(sizeof(struct element));
    assert(e!=NULL);
    assert(!vide(*l));
    strcpy((e->name),n);
    e->next=l->first;
    l->first=e;
    l->dim++;
}

void add_last_liste(struct liste* l,char* n)
{
    assert(l!=NULL);
    struct element* e;
    e=(struct element*)malloc(sizeof(struct element));
    assert(e!=NULL);
    assert(!vide(*l));
    strcpy((e->name),n);
    e->next=NULL;
    l->last->next=e;
    l->last=e;
    l->dim++;
}

void add_in_pos(struct liste* l,char* n,int x)
{
    assert(l!= NULL);
    assert(!vide(*l));
    assert((x>0) && (x<=l->dim+1));
    int i;
    struct element* pre;
    struct element* suivant;
    struct element* e;
    e=(struct element*)malloc(sizeof(struct element));
    strcpy((e->name),n);
    if(x==1)
        add_first_liste(l,n);
    else
    {
    pre=l->first;
    for(i=1;i<x-1;i++)
    {
        pre=pre->next;
    }
    suivant=pre->next;

    e->next=suivant;
    pre->next=e;
    if(x==(l->dim+1))
        l->last=e;
    l->dim++;
    }
}

// affichage
void affiche_first(struct liste l)
{
    printf("1er element est : %s\n",l.first->name);
}

void affiche_last(struct liste l)
{
    printf("dernier elemenet est : %s\n",l.last->name);
}

void affiche(struct liste l)
{
    printf("\n ************* \n");
    int i;
    for(i=0;i<l.dim;i++)
    {
        printf("%s\n",l.first->name);
        l.first=l.first->next ;
    }
}

void supp_first(struct liste* l)
{
    assert(l!=NULL);
    struct element* es;
    es=(struct element*)malloc(sizeof(struct element));
    assert(es!=NULL);
    assert(!vide(*l));
    es=l->first;
    l->first=l->first->next;
    if(l->first==NULL)
        l->last=NULL;
    free(es);
    l->dim--;
}

void supp_last(struct liste* l)
{
    assert(l!=NULL);
    struct element* pre;
    struct element* es;
    es=l->last;
    if(l->dim==1)
    {
        es=l->first;
        l->first=NULL;
        l->last=NULL;
    }
    else
    {
    pre=l->first;
    while(pre->next!=l->last)
    {
        pre=pre->next;
    }
    pre->next=NULL;
    l->last=pre;
    }
    free(es);
}


void supp_in_post(struct liste* l,int x)
{
    assert(l!=NULL);
    assert((x>0)&&(x<l->dim+1));
    int i;
    struct element* es;
    struct element* pre;
    struct element* suivant;
        if(x==1)
        {
            es=l->first;
            suivant=es->next;
            l->first=suivant;
            free(es);
        }
        else
        {
            pre=l->first;
            for(i=1;i<x-1;i++)
            {
                pre=pre->next;
            }
            es=pre->next;
            suivant=es->next;
            pre->next=suivant;
            if(x==l->dim)
                l->last=pre;
            free(es);
        }
        l->dim--;
}


void supp_liste(struct liste* l)
{
    assert(l!=NULL);
    struct element *es;
    int i;
    for(i=0;i<l->dim;i++)
    {
    es=l->first;
    l->first=l->first->next;
    free(es);
    }
    l->last=NULL;
}

//recherche
void rech(struct liste l,char* n)
{
    int i;
    int x=0;
    for(i=0;i<l.dim;i++)
    {
        if(strcmp(n,l.first->name)==0)
            x=1;
        l.first=l.first->next;
    }
    if(x==1)
        printf("%s existe dans la liste \n",n);
    else
        printf("%s n'existe pas dans la liste \n",n);
}










