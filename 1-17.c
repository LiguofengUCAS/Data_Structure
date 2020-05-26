#include <stdio.h>

int febnum(int k,int m);
int main(){
	int i,j;
	int f;
	scanf("%d %d",&i,&j);
	f=febnum(i,j);
	printf("%d",f);
	return 0;
} 

int febnum(int k,int m){
	int t;
	int s;
	if(m==k || m==k-1)
 		t=1;
	else if(m<k-1)
        t=0;
	else if(m>k){
	    for(s=1,t=0;s<=k;s++){
				t+=febnum(k,m-s);
	    }
	}
	return t;
}