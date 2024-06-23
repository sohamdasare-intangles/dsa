struct node* init_node(struct node *temp, int val);

void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);


struct node* bst_insert(struct node *root, int ikey);
struct node* bst_delete(struct node *root, int dkey);
struct node* bst_search(struct node *root, int skey);
int bst_search_val(struct node *root, int skey);


int bst_min(struct node *root);
int bst_max(struct node* root);
int bst_height(struct node *root);

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

enum deletion_cases {
    TWO_CHILD,
    NO_CHILD,
    ONE_CHILD
};

enum subtree_pos {
    LEFT, 
    RIGHT
};