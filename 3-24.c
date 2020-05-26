#include <stdio.h>

int g(int x,int y);
int main(){
	int m,n;
	scanf("%d,%d",&m,&n);
	printf("%d",g(m,n));
	return 0;
} 

int g(int x,int y){
	if(x==0 && y>=0)
		return 0;
	else
		return g(x-1,2*y)+y;
}