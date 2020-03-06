#include "libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    t_list *help= NULL, *store=list, *tmp = list;
    void *swap_data;

    while(list) {
        help=store;
        while(help) {
            if(help->next && cmp(help->data,help->next->data)) {
                swap_data = help->data;
                help->data = help->next->data;
                help->next->data = swap_data;
            }
        help=help->next;
    }
        list = list->next;
    }
    return tmp;
}
