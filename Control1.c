int minus(int x){
	return 1+~x;
}

int isNeg(int x){
	return ((1<<31)&x)>>31;
}

int abs(int x){
	if(isNeg(x)) return minus(x);
	else return x;
}


int main()
{
	
}