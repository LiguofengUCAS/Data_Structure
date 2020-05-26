#include <stdio.h>
#include <stdlib.h>

int main(){
	char va[1000],vb[1000],vc[1000],vs[1000],v[1000];
	int judge=0;
	int i,j,s,k;
	int la,lb,lc,ls;
	i=0;
	while(judge==0 && scanf("%c",&va[i])!=EOF){
		if(va[i]==';'){
			judge=1;
			va[i]='\0';
		}else
			i++;
	}
	la=i;
	
	i=0;
	while(judge==1 && scanf("%c",&vb[i])!=EOF){
		if(vb[i]==';'){
			judge=2;
			vb[i]='\0';
		}else
			i++;
	}
	lb=i;
	
	i=0;
	while(judge==2 && scanf("%c",&vc[i])!=EOF){
		i++;
	}
	vc[i]='\0';
	lc=i-1;
	
	s=0;
	for(i=0;i<lb;i++){
		for(j=0;j<lc;j++){
			if(vc[j]==vb[i] && vc[j]!=','){
				vs[s]=vc[j];
				s++;
			}
		}
	}
	vs[s++]='\0';
	ls=s;

	
    k=0;
    i=0;
    while(i<la){
    	for(j=0;j<ls;j++){
    		if(va[i]==vs[j])
    			goto next;
		}
		if(va[i]!=','){
			v[k]=va[i];
			k++;	
		}
		next:k=k;
		i++;
	}
	
	v[k]='\0';
	 
	 
	
	for(i=0;i<k;i++)
		printf("%c%s",v[i],(i==k-1)?"":",");
		
	return 0;
}