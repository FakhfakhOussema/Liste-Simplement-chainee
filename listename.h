#ifndef listename_h
#define listename_h
struct element
{
    char name[20];
    struct element *next;
};

struct liste
{
    int dim;
    struct element *first;
    struct element *last;
};

/* service de creation*/
// initialisation
struct liste* initialisation();

/*services de modification*/
// ajouter
void add_empty_liste(struct liste*,char*);
void add_first_liste(struct liste*,char*);
void add_last_liste(struct liste*,char*);
void add_in_pos(struct liste*,char*,int);
//supprimer
void supp_liste(struct liste*);
void supp_first(struct liste*);
void supp_last(struct liste*);
void supp_in_post(struct liste*,int);

/*service de consultaion*/
//affichage
void affiche_first(struct liste);
void affiche_last(struct liste);
void affiche(struct liste);
//recherche
void rech(struct liste,char*);
//test
int vide(struct liste);

#endif // listename_h
