#include <stdio.h>
#include <stdlib.h>

struct buffer {
 int * ptr;
 int size;
 int nu_elements; 
 // … maybe store some meta data
 // constructor
 buffer(int initial_size) {
 // … allocate enough memory for the given initial_size
   size = initial_size;
   ptr = (int*)malloc(sizeof(int) * size);
   if (!ptr) 
   	size = 0; 
   nu_elements = 0;
 }
 ~buffer() {
 // … free memory
   free(ptr); 
   size = 0; 
   nu_elements = 0; 
 }

 void add(int element) {
 // check if there is enough room left.
   if (nu_elements < size) {
	ptr[nu_elements++] = element; 
	return;
   } 
 // If not, allocate new memory with enough space and
   int new_size = size + 1; 
   int * ptr_new = (int*)malloc(sizeof(int) * new_size);
 // copy all elements from the old memory over.
   for (int i=0; i< size; i++)
	ptr_new[i] = ptr[i];
   ptr_new[nu_elements++] = element;
   size +=1;  
 // Ensure to not leak memory!
   free(ptr); 
   ptr = ptr_new;
 }
 void print_buffer(){
    int i; 
    for (i=0; i < nu_elements; i++)
	printf("%d ", ptr[i]);
    printf("\n");
 }
};

typedef struct buffer buffer;


int main() {
 buffer b(3); // allocate space for 3 ints
 b.add(1);
 b.print_buffer();

 b.add(2);
 b.print_buffer();

 b.add(3);
 b.print_buffer();
 b.add(4); // this call must allocate new memory
 b.print_buffer();
 
}
