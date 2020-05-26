#include <stdio.h>

#define SIZE 100
int main(){
	char array_a[SIZE],array_b[SIZE];
	int i,judge,len;
	char c;
	i=0;
	judge=0;
	while((c=getchar())!=EOF){
		if(c=='&'){
			judge=1;
			array_a[i]='\0';
			i=0;
		}
		
		if(judge==0){
			array_a[i]=c;
			i++;
		}else{
			if(c!='@' && c!='&'){
				array_b[i]=c;
				i++;
			}else
				array_b[i]='\0';
		}
	}
	len=i-1;
	//printf("len=%d\n",len);
	
	/*for(i=0;i<len;i++){
		printf("%c",array_a[i]);
	}
	printf("\n");
	for(i=0;i<len;i++){
		printf("%c",array_b[i]);
	}
	
	printf("\n");*/
	
	for(i=0;i<len;i++){
		if(array_a[i]!=array_b[len-i-1]){
			printf("0");
			break;
		}
	}
	if(i==len)
		printf("1");
}