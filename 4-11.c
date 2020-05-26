#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef char String; 

int lookup(String s[],String t[]);
/*look for elements that are in s but not in t
return the place where each element first appears*/
void simplify(String r[]);
/*delete repetitive elements*/
int repetitive(String r[],char c);     
/*judge whether r includes c or not*/
int locate(String r[],char c);
/*get the location of c in r*/


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
	//initial s and t
	lookup(s,t);
	return 0;
}

int lookup(String s[],String t[]){
	int i=0,j=0,k=0;
	String r[MAXSIZE];
	for(i=0;*(s+i)!='\0';i++){
		for(j=0;*(t+j)!='\0';j++){
			if(*(s+i)==*(t+j)){
				goto jump;
			}
		}
		if(*(t+j)=='\0'){
			*(r+k)=*(s+i);
			k++;
		}
		jump:j=0;
	}
	*(r+k)='\0';
	if(k==0){
		printf("-1");
		return 0;
	}
	k=0;
	simplify(r);
	printf("%s ",r);

	for(j=0;*(r+j)!='\0';j++)
		printf("%d",locate(s,*(r+j)));
	
	return 0;
}

void simplify(String r[]){
	String temp[MAXSIZE];
	int i,j;
	j=0;
	for(i=0;*(r+i)!='\0';i++){
		if(repetitive(temp,*(r+i))==0){
			*(temp+j)=*(r+i);
			j++;
		}
	}
	*(temp+j)='\0';
	strcpy(r,temp);
	//copy temp to r
}

int repetitive(String r[],char c){
	int i;
	for(i=0;*(r+i)!='\0';i++){
		if(*(r+i)==c)
			return 1;
	}
	return 0;
}

int locate(String r[],char c){
	int i;
	for(i=0;*(r+i)!='\0';i++){
		if(*(r+i)==c)
			return i;
	}
	return -1;
}