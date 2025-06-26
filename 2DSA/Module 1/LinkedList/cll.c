typedef struct cnode
{
        Element data;
        struct cnode *next;
} *CNODE;

typedef struct cll
{
        CNODE tail,head;
        int size;
} *CLL;

CLL createCLL()
{
        CLL c = (CLL) malloc(sizeof(struct cll));
        c->head = NULL;
        c->size = 0;
        return c;
}

void printCLL(CLL cll)
{
        if(cll->head != NULL)
        {
                CNODE p = cll->head;
                do
                {
                        printf("%d->", p->data);
                        p = p->next;
                } while(p != cll->head);
                printf("\n");
        }
}

void CLL_deleteTail(CLL list)
{
    if(list->size == 1)
    {
        free(list->tail);
        list->tail = NULL;
        list->size--;
    }
	else if(list->size > 0)
	{
	    CNODE p = list->tail;
	    while(p->next != list->tail)
	        p = p->next;
	    CNODE d = list->tail;
	    p->next = d->next;
	    free(d);
	    list->tail = p;
	    list->size--;
	}
}

void CLL_addFirst(CLL cll, Element data)
{
    if(cll->size == 0)
    {
        cll->head = (CNODE)malloc(sizeof(struct cnode));
        cll->head->next = cll->head;
        cll->head->data = data;
    }
    else
    {
        CNODE newNode =  (CNODE)malloc(sizeof(struct cnode));
        newNode->data = data;
        CNODE p = cll->head;
        while (p->next != cll->head)
        {
            p = p->next;
        }
        newNode->next = cll->head;
        p->next = newNode;
        cll->head = newNode;
    }
    cll->size++;
}



void CLL_addLast(CLL cll, Element data)
{
	if(cll->size == 0)
	{
		cll->head = (CNODE) malloc(sizeof(struct cnode));
		cll->head->next = cll->head;
		cll->head->data = data;
	}
	else
	{
		CNODE c = (CNODE) malloc(sizeof(struct cnode));
		c->data = data;
		CNODE p = cll->head;
		while(p->next != cll->head)
			p = p->next;

		c->next = cll->head;
		p->next = c;
	}
	cll->size++;
}

void CLL_rotateRight(CLL l, int n) 
{
    if (l == NULL || l->tail == NULL ||l->size<=1||n<=0)
        return;
    n = n % l->size;

    if (n == 0)
        return;

    CNODE newTail = l->tail;
    for (int i = 1; i < l->size-n ; i++)
        newTail = newTail -> next;

    l->tail = newTail;    
}

void CLL_rotateLeft(CLL l, int n) 
{
    if (l == NULL || l->tail == NULL || n <= 0 || l->size <= 1) 
    {
        return; // No rotation needed if list is empty, single-element, or no effective rotations
    }

    // Step 1: Calculate effective rotations
    n = n % l->size;
    if (n == 0) 
    {
        return; // No rotation needed if n is a multiple of the list's size
    }

    // Step 2: Find the new tail position
    CNODE newTail = l->tail;

    // Traverse `n` times to find the new tail (n steps from current tail)
    for (int i = 0; i < n; i++) {
        newTail = newTail->next;
    }

    // Step 3: Update the tail
    l->tail = newTail;
}

CLL createCLLHex(int n) {
    // Step 1: Create the circular linked list structure in the heapCNw
        CLL list = (CLL)malloc(sizeof(struct cll));
        list->head = NULL;
        list->size = 0;
    // Edge case: If n is 0, add a single node with '0' and return
    if (n == 0) {
        CNODE newNode = (CNODE)malloc(sizeof(struct cnode));
        newNode->data = '0';
        newNode->next = newNode;  // Point to itself, making it circular
        list->head = newNode;
        list->size = 1;
        return list;
    }

    // Step 2: Convert n to hexadecimal and add each digit to the list in correct order
    CNODE tail = NULL;  // Track the last node to form the circular link

    // Temporary array to store hex digits
    char hexDigits[16];
    int digitCount = 0;

    while (n > 0) {
        int hexDigit = n % 16;
        hexDigits[digitCount++] = (hexDigit < 10) ? '0' + hexDigit : 'A' + (hexDigit - 10);
        n /= 16;
    }

    // Step 3: Add each digit from the array to the list (from most significant to least significant)
    for (int i = digitCount - 1; i >= 0; i--) {
        CNODE newNode = (CNODE)malloc(sizeof(struct cnode));
        newNode->data = hexDigits[i];

        if (list->head == NULL) {
            //A
            list->head = newNode;
            newNode->next = newNode;  // Point to itself initially
        } else {
            // Insert at the end and make it circular
            newNode->next = list->head;
            tail->next = newNode;
        }

        tail = newNode;  // Update tail to the new node
        list->size++;
    }

    // Step 4: Make sure the last node links back to the head to complete the circular structure
    if (tail != NULL) {
        tail->next = list->head;
    }

    return list;
}
