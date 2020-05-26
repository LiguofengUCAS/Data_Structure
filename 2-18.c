#include <stdio.h>

int main(){
	int len,x,i,j,item;
	scanf("%d %d",&len,&x);
	int List[len];
	while(scanf("%d",List+i)!=EOF){
		i++;
	}
	
	if(len>1){
		if(x<len-1){
			for(j=x;j+1<len;j++)
				*(List+j)=*(List+j+1);
		
			for(i=0;i<len-1;i++)
				printf("%d%s",*(List+i),(i==len-2)?"":" ");
		}
		else{
			for(i=0;i<len-1;i++)
				printf("%d%s",*(List+i),(i==len-2)?"":" ");
		}
	}
	else
		printf("NULL");
	
	return 0;
	
}