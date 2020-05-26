#include <stdio.h>

int main(){
	char va[1000],vb[1000];
	char c;
	int judge=1;
	int i1=0,i2=0,j=0;
	while(scanf("%c",&c)!=EOF){
		if(c==';')
			judge=2;
		if(c!=',' && c!='\n' && c!=';'){
			if(judge==1){
				va[i1]=c;
				i1++;
			}
			else if(judge==2){
				vb[i2]=c;
				i2++;
			}
		}
	}
/*judge determine where the numbers inputted are supposed to go
*/
	va[i1]='\0';
	vb[i2]='\0';
	for(j=0;va[j]==vb[j] && va[j]!='\0';j++){
		;
/*seek for the first different character
*/
	}
	if(va[j]=='\0' && vb[j]=='\0')
		printf("0");
	else if(va[j]=='\0' && vb[j]!='\0')
		printf("1");
	else
		printf("2");
	
	return 0;
}