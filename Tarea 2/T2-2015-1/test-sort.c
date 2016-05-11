#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sort.h"

typedef struct {
  char *name;
  int age;
} Person;
      
int compare_strings(void *ptr, int i, int j) {
  char **strings= ptr;

  return strcmp(strings[i], strings[j]);
}

void swap_pointers(void *ptr, int i, int j) {
  void **v= ptr;
  void *aux;

  aux= v[i];
  v[i]= v[j];
  v[j]= aux;
}

int compare_nums(void *ptr, int i, int j) {
  double *nums= ptr;
  return nums[i]==nums[j] ? 0 :
         nums[i]<nums[j]  ? -1 : 1;
}

void swap_nums(void *ptr, int i, int j) {
  double *nums= ptr;
  double aux;
  aux= nums[i];
  nums[i]= nums[j];
  nums[j]= aux;
}

int compare_people(void *ptr, int i, int j) {
  Person *people= ptr;
  return people[i].age - people[j].age;
}

void swap_people(void *ptr, int i, int j) {
  Person *people= ptr;
  Person aux;
  aux= people[i];
  people[i]= people[j];
  people[j]= aux;
}

char *strings[]= { "pedro", "juan", "ana", "vero", "diego",
                   "jose", "monica", "alberto", "maria", "tatiana" };
double nums[]= { 5.0, 3.0, 10.0, 1.0, 4.0, 2.0, 7.0, 9.0, 8.0, 6.0};

Person people[]= {
  {"pedro", 5}, {"juan", 3}, {"ana", 10}, {"vero", 1}, {"diego", 4},
  {"jose", 2}, {"monica", 7}, {"alberto", 9}, {"maria", 8},
  {"tatiana", 6} };

int main() {
  int j;

  /* sort sirve para ordenar arreglos de strings */
  sort(strings, 0, 9, compare_strings, swap_pointers);

  for (j= 0; j<10; j++)
    printf("%s\n", strings[j]);

  /* Tambien puede ordenar arreglos de numeros de manera portable:
   * sin importar el tamanno de los punteros o de los longs en la
   * plataforma.
   */
  sort(nums, 0, 9, compare_nums, swap_nums);

  for (j= 0; j<10; j++)
    printf("%f\n", nums[j]);

  /* Ademas se pueden ordenar arreglos de estructuras.  No es necesario
   * que sean arreglos de punteros a estructuras como en los apuntes.
   */
  sort(people, 0, 9, compare_people, swap_people);

  for (j= 0; j<10; j++)
    printf("%s %d\n", people[j].name, people[j].age);

  /* Por ultimo se espera que sirva incluso para ordenar archivos
   * sin que tener que llevar el archivo completo a la memoria.
   */
  system("cp people.txt people-sort.txt");
  FILE *file= fopen("people-sort.txt", "r+");
  if (file==NULL) {
    perror("main");
    exit(1);
  }

  sort(file, 0, 9, compare_file_lines, swap_file_lines);

  char line[LINE_WIDTH+1];
  if (fseek(file, 0, SEEK_SET)!=0) {
    perror("compare_file_lines");
    exit(1);
  }

  for (j= 0; j<10; j++) {
    if (fread(line, 1, LINE_WIDTH, file)!=LINE_WIDTH) {
      perror("compare_file_lines");
      exit(1);
    }
    line[LINE_WIDTH]= 0; /* hay que colocar el fin de string! */
    printf("%s", line);  /* las lineas incluyen el \n */
  }

  fclose(file);

  return 0;
}
