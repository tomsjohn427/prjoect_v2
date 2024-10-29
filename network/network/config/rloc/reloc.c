#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
  char add [6],length[10],input[10],binary[12],bitmask[12],relocbit;
  int start,len,i,address,opcode,addr,actualadd;
  FILE*fp1,*fp2;
  printf("Enter the actual starting address: ");
  scanf("%d",&start);
  fp1=fopen("relinput.dat","r");
  if(fp1==NULL)
  {
    perror("Error opening relinput.dat");
    return EXIT_FAILURE;
  }
  fp2=fopen("reloutput.dat","w");
  if(fp2==NULL)
  {
    perror("Error opening reloutput.dat");
    fclose(fp1);
    return EXIT_FAILURE;
  }
  fscanf(fp1,"%s",input);
  while(strcmp(input,"E")!=0)
  {
    if(strcmp(input,"H")==0)
    {
      fscanf(fp1,"%s %s",add,length);
      fscanf(fp1,"%s",input);
    }
    else if(strcmp(input,"T")==0)
    {
      fscanf(fp1,"%d %s",&address,bitmask);
      address +=start;
      len=strlen(bitmask);
      for(i+0;i<len;i++)
      {
         fscanf(fp1,"%d %d",&opcode,&addr);
         relocbit=bitmask[i];
         actualadd=(relocbit=='0')?addr:addr+start;
         fprintf(fp2,"%d\t%d\t%d\n",address,opcode,actualadd);
         address+=3;
         //Assuming each instruction has a fixed size of 3 
      }
      fscanf(fp1,"%s",input);
    }
    else
    {
      fprintf(stderr,"Unexpected input: %s\n",input);
      break;
    }
  }
  fclose(fp1);
  fclose(fp2);
  printf("FINISHED\n");
  return 0;
}
