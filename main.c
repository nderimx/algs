#include <stdio.h>
#include "linkedlists.c"

int main(int argc, char *argv) {
    linkedlist l;
    linkedlist n;
    l.value=111;
    l.next=&n;
    n.value=222;
    n.next=NULL;

    // stack s;
    // s.first=&l;
    // s.last=&n;
    // for(int i=0; i<10; i++) {
    //     push(&s, i);
    // }
    
    // for(int i=0; i<10; i++) {
    //     printf("%p: %d -> %p\n", s.first, s.first->value, s.first->next);
    //     s.first=s.first->next;
    // }
    // return 0;

    for(int i=0; i<10; i++) {
        cut_add(&l, i);
    }
    
    return print_list(&l);
}