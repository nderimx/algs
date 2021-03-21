#include <stdio.h>
#include <stdlib.h>

struct ll {
    int value;
    struct ll *next;
};
typedef struct ll linkedlist;

struct stck {
    linkedlist *first;
    linkedlist *last;
};
typedef struct stck stack;

// ad -> dc -> cb -> ba -> null
void cut_add(linkedlist *l, int val) {
    linkedlist old_first = *(linkedlist *)malloc(sizeof(linkedlist));
    old_first = *(l);
    l -> value = val;
    l -> next = &old_first;
}

// aa -> null
void push(stack *s, int val) {
    linkedlist top = *(linkedlist *)malloc(sizeof(linkedlist));
    top.value=val;
    top.next=NULL;
    s->last->next=&top;
    s->last=&top;
}

void print_node(linkedlist *l) {
    printf("%p: %d -> %p\n", l, l->value, l->next);
}

void slow_add(linkedlist *l, int val) {
    linkedlist *new = (linkedlist *)malloc(sizeof(linkedlist));
    new->value=val;
    new->next=NULL;
    linkedlist *current = l;
    while(current->next!=NULL) {
        current=current->next;
    }
    current->next=new;
}

// convert this to a generalized enumeration function
int print_list(linkedlist *l) {
    linkedlist *current=l;
    while(current->next!=0) {
        print_node(current);
        if(current==current->next) {
            return 1;
        }
        current=current->next;
    }
    print_node(current);
    return 0;
}