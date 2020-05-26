#include <stdio.h>

int square(int x,int y); 
int main(){
	int n,m;
	int i,a,t;
	scanf("%d %d",&n,&m);
	for(i=0,t=0;i<n;i++){
		scanf("%d",&a);
		t+=a*square(m,i);
	}
	printf("%d",t);
	return 0;
} 

int square(int x,int y){
	int s,i;
	for(i=1,s=1;i<=y;i++)
		s*=x;
	return s;
}