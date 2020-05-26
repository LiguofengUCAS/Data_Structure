#include <stdio.h>

void sort(int arr[],int len);
int main(){
    int x,y,z;
    int bss[3];
    //printf("Plz input x,y,z:\n");
    scanf("%d %d %d",&x,&y,&z);          /*输入x,y,z的值*/ 
    bss[0]=x;
    bss[1]=y;
    bss[2]=z;
    sort(bss,3);                         /*调用排序算法*/ 
    printf("%d %d %d",bss[0],bss[1],bss[2]);
    return 0;
}

void sort(int arr[],int len){        /*冒泡排序算法*/ 
    int temp;
    int i,j;
    for(i=0;i<len-1;i++){                 /*外循环为排序趟数，len个数进行len-1趟 */ 
        for(j=0;j<len-1-i;j++){           /*内循环为每趟比较的次数，第i趟比较len-i次 */
          if(arr[j]<arr[j+1]){            /*相邻元素比较，若逆序则交换（升序为左大于右，降序反之） */
              temp=arr[j];
              arr[j]=arr[j+1];
              arr[j+1]=temp;
		    }
        }
   }
}