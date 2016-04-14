#include <stdio.h> /*printf*/
#include <stdlib.h> /*malloc*/

void basic(){
	char *s = "hola";
	char r[] = {'h','o','l','a',0};
	char t[5] = {0};
	
	printf("s: %s \n",s);
	printf("r: %s \n",r);
	printf("t: %s \n",t);
}

int main(){
	basic();
	
}