#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int main(){
	char c;
	int i,len;
	char array[SIZE];
	i=0;
	while((c=getchar())!=EOF){
		if(c!='@'){
			array[i]=c;
			//printf("%d\n",i);
			i++;
			//printf("%c",c);
			//printf("%d %c\n",i);
		}else
			array[i]='\0';
	}
	len=i-1;
	
	/*printf("%d\n",len);
	
	for(i=0;i<len;i++)
		printf("%c",array[i]);
		
	printf("\n");*/
	
	for(i=0;i<=len/2;i++){
		if(array[i]!=array[len-1-i]){
			printf("0");
			goto finish;
		}
	}
		printf("1");
		finish:i=0;
	
	
	return 0;
}