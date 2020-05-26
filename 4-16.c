#include <stdio.h>
#include <string.h>

#define MAXSIZE 100

typedef char String;

int strCompare(String *s,String *t);
int main(){
	String s[MAXSIZE],t[MAXSIZE];
	int i=0,j=0;
	int judge=0;
	int c;
	while((c=getchar())!=EOF){
		if(c==' '){
			judge=1;
			*(s+i)='\0';
		}
		if(c=='\n'){
			*(t+j)='\0';
			break;
		}
		if(judge==0){
			*(s+i)=c;
			i++;
		}
		if(judge==1 && c!=' '){
			*(t+j)=c;
			j++;
		}
	}
	printf("%d",strCompare(s,t));
	return 0;
}

int strCompare(String *s,String *t){
	int i=0;
	while(*(s+i)==*(t+i) && *(s+i)!='\0')
		i++;
	if(*(s+i)>*(t+i))
		return 1;
	if(*(s+i)==*(t+i))
		return 0;
	if(*(s+i)<*(t+i))
		return -1;
}