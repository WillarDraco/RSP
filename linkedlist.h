#ifndef LINKEDLIST_H


#include <iostream>
#include <string>

class list {
    private:
        int data;
        list *next;
    public:
        list() {
            data = NULL;
            next = NULL;
        }

        list(int x) {
            data = x;
            next = NULL;
        }
        
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
            if ((l = NULL) || (l->next = NULL)) {
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
                pred = predecessor(l, x);
                if (pred == NULL) {
                    *l = p->next;
                } else {
                    pred->next = p->next;
                }
                free(p);
            }

        }
};
#endif