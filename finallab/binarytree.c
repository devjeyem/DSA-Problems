#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _tnode 
{
    char data;
    struct _tnode* left;
    struct _tnode* right;
} *TNODE;

typedef struct _tree 
{
    TNODE root;
} *TREE;

typedef struct _stack 
{
    TNODE* storage;
    int top;
} *STACK;

STACK createStack() 
{
    STACK stack = (STACK)malloc(sizeof(struct _stack));
    stack->storage = (TNODE*)malloc(sizeof(TNODE) * 100);
    stack->top = 0;
    return stack;
}

void push(STACK stack, TNODE node) 
{
    if (stack->top < 100) 
        stack->storage[stack->top++] = node;
}

TNODE pop(STACK stack) 
{
    return (!stack->top) ? NULL : stack->storage[--(stack->top)]; 
}

TNODE peek(STACK stack) 
{ 
    return (!stack->top) ? NULL : stack->storage[(stack->top)-1]; 
}

int isEmpty(STACK stack) 
{
    return stack->top == 0;
}

TNODE createNode(char data) {
    TNODE node = (TNODE)malloc(sizeof(struct _tnode));
    if (!node) return NULL;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TREE createTree(char* input) {
    TREE tree = (TREE)malloc(sizeof(struct _tree)); 
    tree->root = NULL;

    STACK tracker = createStack();
    TNODE current = NULL;
    int isLeft = 1; 

    for (int i = 0; input[i] != '\0'; i++) 
    {
        char c = input[i];

        if (c == '(') 
        {
            push(tracker, current);
            isLeft = 1;
        } 
        else if (c == ')')
            current = pop(tracker);
        else if (c == '-') 
        {
            if (isLeft && current)
                current->left = NULL;
            isLeft = 0; 
        } 
        else 
        {
            TNODE newNode = createNode(c);
            if (tree->root == NULL) 
                tree->root = newNode;
            else 
            {
                TNODE parent = peek(tracker);
                if (isLeft)
                    parent->left = newNode;
                else
                    parent->right = newNode;
            }
            current = newNode;
            isLeft = 0;
        }
    }
    return tree;
}

void preorderTraversal(TNODE node) 
{
    if (node == NULL) return;
    printf("%c ", node->data);
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void inorderTraversal(TNODE node) 
{
    if (node == NULL) return;
    inorderTraversal(node->left);
    printf("%c ", node->data);
    inorderTraversal(node->right);
}

void postorderTraversal(TNODE node) 
{
    if (node == NULL) return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    printf("%c ", node->data);
}

int findHeight(TNODE node)
{
    if(!node) return 0;
    int leftHeight = findHeight(node->left);
    int rightHeight = findHeight(node->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main() 
{
    char* parNot = (char*)malloc(sizeof(char) * 100);
    if (!parNot) return 1;

    printf("Input: ");
    scanf("%99s", parNot);

    TREE tree = createTree(parNot);
    if (!tree) return 1;

    printf("Preorder: ");
    preorderTraversal(tree->root);
    printf("\n");

    printf("Inorder: ");
    inorderTraversal(tree->root);
    printf("\n");

    printf("Postorder: ");
    postorderTraversal(tree->root);
    printf("\n");

    printf("\n\nHeight: %d", findHeight(tree->root));

    free(parNot);
    return 0;
}