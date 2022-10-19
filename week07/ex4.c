#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

void* myrealloc(void *ptr, size_t new_size) {
    if (ptr == NULL)
        ptr = malloc(new_size);
    
    if (new_size == 0)
        free(ptr);
    
    if (new_size > 0) {
        void *new_ptr = malloc(new_size);

        if (new_size < malloc_usable_size(ptr)) {
            for (int i = 0 ; i < new_size; i++) {
                ((char *)new_ptr)[i] = ((char *)ptr)[i];
            }
        }
        else {
            for (int i = 0 ; i < malloc_usable_size(ptr); i++) {
                ((char *)new_ptr)[i] = ((char *)ptr)[i];
            }
        }
        ptr = new_ptr;
    }
    return ptr;
}

int main() {
    int *ptr = malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        ptr[i] = i;
        printf("%d ", ptr[i]);
    }
    printf("\n");
    
    ptr = myrealloc(ptr, 15 * sizeof(int));
    for (int i = 0; i < 30; i++)
        printf("%d ", ptr[i]);
    
    free(ptr);
    return 0;
}
