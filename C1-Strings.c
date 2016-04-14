#include <stdio.h> /*printf*/
#include <stdlib.h> /*malloc*/

void basic(){
	char *s = "hola";
	char r[] = {'h','o','l','a',0};
	//char r[] = {'h','o','l','a'}; //r: hola+á@
	char t[5] = {0};
	
	printf("s: %s \n",s);
	printf("r: %s \n",r);
	printf("t: %s \n",t);
	
	//s[0] = 'H'; //SegFault, cierra el programa;
	r[0] = 'H';
	printf("r[0] = H: %s \n",r);
}

int main(){
	basic();
	
}