#include<stdio.h> 
#include<stdlib.h> 

struct Node
{
    int key;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
    int ech;
};


/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->ech = 0;  // new node is initially added at leaf
    return(node);
}

//function to get the height of a tree

int inaltime(struct Node* root)
{
    int lh, rh;
    if (root == NULL)
        return -1;
    
        lh = inaltime(root->left);
        rh = inaltime(root->right);
        if (lh > rh)
            return (lh + 1);
        else
            return (rh + 1);
    
}

// A utility function to right rotate subtree rooted with y 
// See the diagram given above. 
struct Node* rightRotate(struct Node* y)
{
    
    struct Node* x = y->left;
    struct Node* T2 = x->right;
    // Perform rotation 
    x->right = y;
    y->left = T2;
    if (T2 != NULL)
        y->left->parent = y;
    x->parent = NULL;
    x->left->parent = x;
    x->right->parent = x;
    // Update balance 
    y->ech = inaltime(y->left) - inaltime(y->right);
    x->ech = inaltime(x->left) - inaltime(x->right);

    // Return new root 
    return x;
}

// A utility function to left rotate subtree rooted with x 
// See the diagram given above. 
struct Node* leftRotate(struct Node* x)
{
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    // Perform rotation 
    y->left = x;
    x->right = T2;
    if (T2 != NULL)
        x->right->parent = x;
    y->parent = NULL;
    y->left->parent = y;
    y->right->parent = y;
    //  Update balance 
    x->ech = inaltime(x->left) - inaltime(x->right);
    y->ech = inaltime(y->left) - inaltime(y->right);

    // Return new root 
    return y;
}

struct Node* balansari(struct Node* node, int key) {
    
    node->ech = inaltime(node->left) - inaltime(node->right);
    if (node->ech > 1 && key < node->left->key) {
        return rightRotate(node);
    }
    if (node->ech < -1 && key > node->right->key) {
        return leftRotate(node);
    }
    if (node->ech > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (node->ech < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}


// Recursive function to insert a key in the subtree rooted 
// with node and returns the new root of the subtree. 
struct Node* insert(struct Node* node, int key)
{
    /* 1.  Perform the normal BST insertion */
    if (node == NULL) {
        return(newNode(key));
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
        node->left->parent = node;
    }
    else if (key > node->key) {
        node->right = insert(node->right, key);
        node->right->parent = node;
    }

    else // Equal keys are not allowed in BST 
        return node;
    balansari(node,key);
}




// A utility function to print preorder traversal 
// of the tree. 
// The function also prints height of every node 

struct Node* find(int key, struct Node* node) {
    if (node == NULL)
        return;
    if (node->key == key)
        return node;
    if (key > node->key)
        return find(key, node->right);
    else return find(key, node->left);
}

void delete(struct Node* nod,int key)
{
    if (nod == NULL) return;
    delete(nod->left,key);
    delete(nod->right,key);
    if (nod->parent->key < nod->key) 
        nod->parent->right = NULL;
    else
        nod->parent->left = NULL;
    free(nod);
}


struct Node* suprima_key(int key, struct Node* root)
{
    delete(find(key, root),key);
}




void preOrder(struct Node* root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}


void inOrder(struct Node* root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

/* Drier program to test above function*/
int main()
{
    struct Node* root = NULL;
    /* Constructing tree given in the above figure */
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    /* The constructed AVL Tree would be
              30
             /  \
           20   40
          /  \     \
         10  25    50
    */
    printf("\nAfisare in preodine: \n");
    preOrder(root);
    printf("\n");
    suprima_key(20, root);
    printf("\nAfisare in preordine dupa stergere: :\n");
    preOrder(root);
    return 0;
}
