// pointer arithmetic
#include<stdio.h>
int main(){
    int arr[]={1,2,3,4,5};
    int n=5;
    int *ptr=arr;
    int *ptr2=ptr;
    for(int i=0;i<n;i++){
        ptr+=1;
    }
    printf("The size of the array is %d",ptr-ptr2);
}
// int x=12;
// printf("%d\n",x);  //signed int                  [ DIFFERENT FORMAT SPECIFIERS ]
// printf("%u\n",x);  //unsigned int
// printf("%x\n",x);  //unsigned int in hexa
// printf("%o\n",x);  //unsigned int in octal


