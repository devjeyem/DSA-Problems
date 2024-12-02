#include <stdio.h>
#include <stdlib.h>

typedef int Element;
#define EMPTY -1

typedef struct node
{
    Element data;
    struct node *left, *right;
}*NODE;

typedef struct bst
{
    NODE root;
}*BST;

BST createBST();
NODE createNode();

void insert(NODE root, Element data);
void insertBST(BST tree, Element data);
void deleteBST(BST tree, Element target);
NODE delete(NODE root, Element target);
int searchBST(BST tree, Element target);
NODE search(NODE root, Element target, int* ctr);

void preorderBST(BST tree);
void preorder(NODE root);
void inorderBST(BST tree);
void inorder(NODE root);
void postorderBST(BST tree);
void postorder(NODE root);\
void compute_heightBST(BST tree);
int compute_height(NODE root);
int total_nodes(NODE root);
void total_nodesBST(BST tree);

int main()
{
    BST tree = createBST();

    insertBST(tree, 10);
    insertBST(tree, 12);
    insertBST(tree, 8);
    insertBST(tree, 9);
    insertBST(tree, 2);
    insertBST(tree, 3);
    insertBST(tree, 7);

    preorderBST(tree);
    inorderBST(tree);
    postorderBST(tree);

    //deleteBST(tree, 8);
    //preorderBST(tree);
    searchBST(tree, 7);
    compute_heightBST(tree);
    total_nodesBST(tree);

    return 0;
}

BST createBST()
{
    BST x = (BST)malloc(sizeof(struct bst));
    x->root = NULL;
    return x;
}

NODE createNode()
{
    NODE x = (NODE)malloc(sizeof(struct node));
    x->left = x->right = NULL;
    return x;
}

void insert(NODE root, Element data)
{
    NODE new = createNode();
    new->data = data;
    if (data > root->data)
    {
        if (root->right == NULL)
            root->right = new;
        else    
            insert(root->right,data);
    }
    else
    {
        if (root->left == NULL)
            root->left = new;
        else    
            insert(root->left,data);       
    }
}


void insertBST(BST tree, Element data)
{
    if (tree->root == NULL)
    {
        NODE new = createNode();
        new->data = data;
        tree->root = new;
    }
    else{
        insert(tree->root,data);
    }
}

void deleteBST(BST tree, Element target)
{
    if(tree->root == NULL) return;
    tree->root = delete(tree->root, target);
}

NODE delete(NODE root, Element target)
{
    if(root == NULL) return root;

    if(target < root->data)
        root->left = delete(root->left, target);
    else if(target > root->data)
        root->right = delete(root->right, target);
    else
    {
        if(root->left == NULL)
        {
            NODE temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            NODE temp = root->left;
            free(root);
            return temp;
        }

        NODE largest_left = root->left;
        while(largest_left->right != NULL)
            largest_left = largest_left->right;
        
        root->data = largest_left->data;
        root->left = delete(root->left, largest_left->data);
    }
    return root;
}

int searchBST(BST tree, Element target)
{
    int counter = 0;
    NODE temp = search(tree->root, target, &counter);
    if(temp->data == target)
    {
        printf("Data Found: It took %d comparisons.\n", counter);
        return 1;
    }
    printf("Data Not Found.");
    return 0;
}



NODE search(NODE root, Element target, int* ctr)
{
    if (root == NULL) return NULL;

    (*ctr)++;
    if (target<root->data)
    {
        return search(root->left,target,ctr);
    }
    else if (target>root->data)
    {
        return search(root->right, target,ctr);
    }
    else    
        return root;
}

void preorderBST(BST tree)
{
    printf("Preorder: ");
    preorder(tree->root);
    printf("\n");
}

void preorder(NODE root)
{
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorderBST(BST tree)
{
    printf("Inorder: ");
    inorder(tree->root);
    printf("\n");
}

void inorder(NODE root)
{
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorderBST(BST tree)
{
    printf("Postorder: ");
    postorder(tree->root);
    printf("\n");
}

void postorder(NODE root)
{
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void compute_heightBST(BST tree)
{
    printf("Height of Tree: %d\n", compute_height(tree->root));
}

int compute_height(NODE root)
{
    if(root == NULL) return 0;

    int hl = compute_height(root->left);
    int hr = compute_height(root->right);
    return ((hl > hr) ? hl : hr) + 1;
}

void total_nodesBST(BST tree)
{
    printf("Total Number of Nodes: %d\n", total_nodes(tree->root));
}

int total_nodes(NODE root)
{
    if(root == NULL) return 0;

    int l = total_nodes(root->left);
    int r = total_nodes(root->right);

    return l + r + 1;
}