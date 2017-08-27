#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 9000

int num1[MAX_SIZE],num2[MAX_SIZE],sum[MAX_SIZE];
int *memoryBuff;
long long totlen=0;
void populateArray(int,int[]);
int main()
{
    long long inplen;
    char inputNum;
    printf("enter num1: ");
    inplen=0;
    while(1){
        inputNum=getchar();
        if(inputNum=='\n'||inputNum=='\r'){
            break;
        }
        num1[inplen++]=inputNum;
    }
    totlen+=lengthArray(num1);
    printf("enter num2: ");
    inplen=0;
    while(1){
        inputNum=getchar();
        if(inputNum=='\n'||inputNum=='\r'){
            break;
        }
        num2[inplen++]=inputNum;
    }
    totlen+=lengthArray(num2);
    memoryBuff=malloc(sizeof(int)*lengthArray(num2)*totlen);
    multiply();
    free(memoryBuff);
    return 0;
}
int length(int number){
    int counter=0;
    while(number){
        counter++;
        number/=10;
    }
    return counter;
}
int lengthArray(int array[]){
    int i=0;
    while(array[i]!='\0'){
        i++;
    }
    return i;
}
void populateArray(int source,int array[]){
    int i=0,remainder;
    //size=length(source);
    for(i=0;source>0;i++){
        remainder=source%10;
        source/=10;
        array[i]=remainder+'0';
    }
    array[i]='\0';
}
void multiply(){
    int len1=lengthArray(num1),len2=lengthArray(num2);
    int i,j,k,p,q;
    for(j=len2-1;j>=0;j--){
        //leading zero
        for(p=0;p<j;p++){
            memoryBuff[k++]='0';
        }
        for(i=0;i<=len1-1;i++){
            memoryBuff[k++]=((num1[i]-'0')*(num2[j]-'0'))+'0';
        }
        //trailing zero
        for(p=len2-1-j;p>0;p--){
            memoryBuff[k++]='0';
        }
    }
    memoryBuff[k]='\0';
    //printArray(memoryBuff);
    adder();
}
void adder(){
    int k,i,j,adder,size=lengthArray(num2),carry,loopCounter,pos=0;
    carry=0;
    for(k=totlen-2;k>=0;k--){
        adder=carry;
        loopCounter=0;
        for(i=k;loopCounter<size;i+=(totlen-1)){
            loopCounter++;
            adder+=memoryBuff[i]-'0';
        }
        carry=adder/10;
        sum[pos++]=adder%10;
    }
    sum[pos++]=carry;
    loopCounter=0;
    printf("\nproduct : ");
    for(i=pos-1;i>=0;i--){
        printf("%d",sum[i]);
        loopCounter++;
        if(loopCounter==3){
            printf(" ");
            loopCounter=0;
        }
    }
    printf("\n");
}
void printArray(int array[]){
    int size=lengthArray(array),i,counter=0;
    printf("\n");
    for(i=0;i<size;i++){
        counter++;
        printf("%2d ",array[i]-'0');
        if(counter>=totlen-1){
            printf("\n");
            counter=0;
        }
    }
}
