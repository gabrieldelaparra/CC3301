#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
      
/* ordena datos de cualquier tipo usando Quicksort */

void sort(void *ptr, int left, int right,
          Comparator compare, Swapper swap) {
  int i, last;

  if (left>=right)
    return;

  (*swap)(ptr, left, (left+right)/2);
  last= left;

  /*
    +--+-----------+--------+--------------+
    |  |///////////|\\\\\\\\|              |
    +--+-----------+--------+--------------+
    left        last         i         right
  */

  for (i= left+1; i<=right; ++i)
    if ((*compare)(ptr, i, left)<0)
      (*swap)(ptr, ++last, i);
  (*swap)(ptr, left, last);

  sort(ptr, left, last-1, compare, swap);
  sort(ptr, last+1, right, compare, swap);
}

void read_line(FILE *file, char *line, int i) {
  if (fseek(file, i*LINE_WIDTH, SEEK_SET)!=0) {
    perror("compare_file_lines");
    exit(1);
  }
  if (fread(line, 1, LINE_WIDTH, file)!=LINE_WIDTH) {
    perror("compare_file_lines");
    exit(1);
  }
}

void write_line(FILE *file, char *line, int i) {
  if (fseek(file, i*LINE_WIDTH, SEEK_SET)!=0) {
    perror("compare_file_lines");
    exit(1);
  }
  if (fwrite(line, 1, LINE_WIDTH, file)!=LINE_WIDTH) {
    perror("compare_file_lines");
    exit(1);
  }
}

int compare_file_lines(void *ptr, int i, int j) {
  FILE *file= ptr;
  char line_i[LINE_WIDTH], line_j[LINE_WIDTH];
  read_line(file, line_i, i);
  read_line(file, line_j, j);
  return strncmp(line_i, line_j, 10);
}

void swap_file_lines(void *ptr, int i, int j) {
  FILE *file= ptr;
  char line_i[LINE_WIDTH], line_j[LINE_WIDTH];
  read_line(file, line_i, i);
  read_line(file, line_j, j);
  write_line(file, line_i, j);
  write_line(file, line_j, i);
}

