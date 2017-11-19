#include<stdio.h>

void main()
{
  char val[20],n[20];
FILE *fp1;
fp1=fopen("hi.txt","r");
fscanf(fp1,"%s\t%s",val,n);
printf("\nValue : %s %s\n",val,n);



}
