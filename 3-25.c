#include <stdio.h>

int F(int n);
int main(){
	int i;
	scanf("%d",&i);
	printf("%d",F(i));
	return 0;
}

int F(int n){
	if(n==0)
		return n+1;
	else if(n>0)
		return n*F(n/2);
}