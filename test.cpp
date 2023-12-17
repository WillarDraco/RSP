#include <iostream>
#include "linkedlist.h"

list* search_list(list *l, int x) {
            if (l == NULL) {
                return NULL;
            }

            if (l->data == x) {
                return l;
            } else {
                return search_list(l->next, x);
            }
}

void insert_list(list** l, int x) {
    list* p = new list;
    p->data = x;
    p->next = *l;
    *l = p;
}

list* predecessor(list* l, int x) {
    if ((l == NULL) || (l->next == NULL)) {
        std::cout << "Error: Empty List\n";
        }

    if ((l->next)->data == x) {
            return l;
        } else {
            return predecessor(l->next, x);
        }
}

void deleteList(list** l, int x) {
    list* p;
    list* pred;

    p = search_list(*l, x);
        if (p != NULL) {
        pred = predecessor(*l, x);
            if (pred == NULL) {
            *l = p->next;
        } else {
            pred->next = p->next;
        }
        delete p;
    }
}

int main(void) {
    list *test = new list;
    test->next = NULL;
    test->data = 1;

    insert_list(&test, 2);

    std::cout << search_list(test, 2)->data << "\n";
}



