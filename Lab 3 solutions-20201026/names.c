#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

struct name {
    const char * first_name;
    const char * last_name;
};
typedef struct name name;

int compare_first(const void* a, const void* b){
    name * arg1_ptr = (name *) a;
    name * arg2_ptr = (name *) b;
 
    return strcmp(arg1_ptr->first_name, arg2_ptr->first_name);
}

int compare_last(const void* a, const void* b){
    name * arg1_ptr = (name *) a;
    name * arg2_ptr = (name *) b;
 
    return strcmp(arg1_ptr->last_name, arg2_ptr->last_name);
}

void print_array (name * n, int size){
    int i; 
    for (i = 0; i < size; i++) {
        printf("%s %s\n", n[i].first_name, n[i].last_name);
    }
    printf("\n");
}

int main() {
	name names[4] = {
        {"Grace", "Hopper"},
        {"Dennis", "Ritchie"},
        {"Ken", "Thompson"},
        {"Bjarne", "Stroustrup"},
    };

    size_t len = sizeof(names) / sizeof(name);

    // sort array using qsort by first name
    qsort(names, len, sizeof(name), compare_first);
    // print array
    print_array(names,len);
    // sort array using qsort by last name
    qsort(names, len, sizeof(name), compare_last);
    // print array
    print_array(names,len);
}

