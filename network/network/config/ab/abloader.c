#include<stdio.h>
#include<string.h>
int main()
{
char input[10];
int start=0,length=0,address=0;
FILE*fp1,*fp2;
fp1=fopen("input.dat","r");
if(fp1==NULL)
{
  perror("Error opening input.dat");
  return 1;
}
fp2=fopen("output.dat","w");
if(fp2==NULL)
{
  perror("Error opening output.dat");
  fclose(fp1);
  return 1;
}
fscanf(fp1,"%s",input);
while(strcmp(input,"E")!=0)
{
  if(strcmp(input,"H")==0)
  {
    fscanf(fp1,"%d",&start);
    fscanf(fp1,"%d",&length);
    fscanf(fp1,"%s",input);
  }
  else if(strcmp(input,"T")==0)
  {
    fscanf(fp1,"%d",&address);
    fscanf(fp1,"%s",input);
    fprintf(fp2,"%d\t%c%c\n",address,input[0],input[1]);
    fprintf(fp2,"%d\t%c%c\n",(address+1),input[2],input[3]);
    fprintf(fp2,"%d\t%c%c\n",(address+2),input[4],input[5]);
    address+=3;
    fscanf(fp1,"%s",input);
  }
  else
  {
    fprintf(fp2,"%d\t%c%c\n",address,input[0],input[1]);
    fprintf(fp2,"%d\t%c%c\n",(address + 1),input[2],input[3]);
    fprintf(fp2,"%d\t%c%c\n",(address + 2),input[4],input[5]);
    address+=3;
    fscanf(fp1,"%s",input);
  }
}
fclose(fp1);
fclose(fp2);
printf("FINISHED\n");
return 0;
}
