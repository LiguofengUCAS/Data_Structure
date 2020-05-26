#include <stdio.h>

#define ARRIZE 300
#define MAXINT 65535

int stepmut(int x);
int square(int y);

int main(){
	int i,n;
	int k_0,k_1;
	i=0;
	k_0=k_1=1;
	scanf("%d",&n);
	
	while(i<n){
		k_0=k_1;                         
		k_1=stepmut(i)*square(i);
		i++;
		if(k_1>MAXINT)
			break;
	}
	if(i>=n)
		printf("%d",k_1);
	else
		printf("%d",k_0);
	
	return 0;
}
/* k_0 is the previous value of k_1, 
   if k_1 is over the boundary, output k_0
*/

int stepmut(int x){                   //to calculate x!
	int s,i;
	for(i=1,s=1;i<=x;i++)
		s*=i;
	return s;
}

int square(int y){                    //to calculate 2^y
	int s,i;
	if(y==0)
		return 1;

	for(i=1,s=1;i<=y;i++) 
		s*=2;
	return s;
}