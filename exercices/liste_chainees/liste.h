// Element de la liste
typedef struct node {
    int data;
    struct node *next;
} Node;

// Entete de la liste
typedef struct liste {
    int count;
    Node *first;
} Liste;


// Prototypes de fonctions
void liste_init( Liste *liste );
void liste_print_entete( Liste *liste );
void liste_print( Liste *liste);
Node *node_create(int data);
void node_set_next(Node *node, Node *next);
void liste_free(Liste *liste);