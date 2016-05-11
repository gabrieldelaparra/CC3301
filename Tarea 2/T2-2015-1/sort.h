
typedef int (*Comparator)(void *ptr, int i, int j);
typedef void (*Swapper)(void *ptr, int i, int j);
    
void sort(void *ptr, int left, int right, Comparator compare, Swapper swap);

#define LINE_WIDTH 14

int compare_file_lines(void *ptr, int i, int j);
void swap_file_lines(void *ptr, int i, int j);
