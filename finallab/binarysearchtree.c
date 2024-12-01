#include <stdio.h>
#include <stdlib.h>

typedef struct _tnode{
    int data;
    struct _tnode *left, *right;
} *TNODE;

typedef struct _bst{
    TNODE root;
} *BST;

typedef struct _queue{
    TNODE *storage;
    int front, rear, count;
} *QUEUE;

QUEUE createQ()
{
    QUEUE q = (QUEUE)malloc(sizeof(struct _queue));
    q->storage = (TNODE*)malloc(sizeof(TNODE) * 1000);
    q->front = q->rear = q->count = 0;
    return q;
}

int isEmpty(QUEUE q)
{
    return q->count == 0;
}

void enqueue(QUEUE q, TNODE node)
{
    if(q->count<1000)
    {
        q->storage[q->rear] = node;
        q->rear = (q->rear + 1) % 1000;
        q->count++;
    }
}

TNODE dequeue(QUEUE q)
{
    if(q->count)
    {
        TNODE x = q->storage[q->front];
        q->front = (q->front + 1) % 1000;
        q->count--;
        return x;
    }
    else
        return NULL;
}

BST createBST()
{
    BST bst = (BST)malloc(sizeof(struct _bst));
    bst->root = NULL;
    return bst;
}

TNODE createNode(int data)
{
    TNODE node = (TNODE)malloc(sizeof(struct _tnode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void insertBSTNode(TNODE node, int data)
{
    if(data >= node->data)
    {
        if(node->right == NULL)
            node->right = createNode(data);
        else
            insertBSTNode(node->right, data);

    }
    else
    {
        if(node->left == NULL)
            node->left = createNode(data);
        else
            insertBSTNode(node->left, data);
    }
}

void insertData(BST bst, int data)
{
    if(bst->root)
        insertBSTNode(bst->root, data);
    else
        bst->root = createNode(data);
}

// Recursive Approach
int findHeightRec(TNODE node)
{
    if(!node) return 0;
    int leftHeight = findHeightRec(node->left);
    int rightHeight = findHeightRec(node->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}


// Iterative Approach
int findHeightIter(TNODE node)
{
    if(!node) return 0;

    int height = 0;
    QUEUE tracker = createQ();
    enqueue(tracker, node);

    while(!isEmpty(tracker))
    {
        int nodeCount = tracker->rear - tracker->front;
        while(nodeCount--)
        {
            TNODE current = dequeue(tracker);
            if(current->left!=NULL) enqueue(tracker, current->left);
            if(current->right!=NULL) enqueue(tracker, current->right);
        }
        height++;
    }
    return height;
}

int findNodeLvl(TNODE node, int data)
{
    if(!node) return -1;
    
    if(node->data == data) 
        return 0;
    else
    {
        if(data > node->data){
            int level = findNodeLvl(node->right, data);
            return (level==-1) ? -1 : 1 + level;
        }
        else{
            int level = findNodeLvl(node->left, data);
            return (level==-1) ? -1 : 1 + level;
        }
    }
}

void preorder(TNODE node)
{
    if(node==NULL) return;
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

void inorder(TNODE node)
{
    if(node==NULL) return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

void postorder(TNODE node)
{
    if(node==NULL) return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

int main()
{
    BST bst = createBST();
    insertData(bst, 14);
    insertData(bst, 28);
    insertData(bst, 5);
    insertData(bst, 9);
    insertData(bst, 13);
    insertData(bst, 4);
    insertData(bst, 5);
    insertData(bst, 4);
    insertData(bst, 3);
    insertData(bst, 27);
    insertData(bst, 32);
    insertData(bst, 29);

    printf("Preorder: ");
    preorder(bst->root);
    printf("\nInorder: ");
    inorder(bst->root);
    printf("\nPostorder: ");
    postorder(bst->root);
    printf("\n\nHeight (Recursive): %d", findHeightRec(bst->root));
    printf("\nHeight (Iterative): %d", findHeightIter(bst->root));

    printf("\n\nEnter Number to Find in BST: ");
    int num;
    scanf("%d", &num);
    
    if(findNodeLvl(bst->root, num) != -1)
        printf("Level: %d", findNodeLvl(bst->root, num));
    else  
        printf("Data not Found");
}