#include <stdio.h>

int main(){
	int p,q;
	int c;
	p=q=0;
	
	while((c=getchar())!=EOF){
		if(c=='(')
			p++;
		else if(c==')')
			q++;
		else
			;
	}
	
	printf((p==q)?"1":"0");
}