#include <stdio.h>
int main(){
    int a,b,c;
    printf("enter a phone number:");
    scanf("(%d)%d-%d",&a,&b,&c);
    printf("you entered phone number is:%d.",a);
    printf("%d.",b);
    printf("%d",c);
    return 0;}
