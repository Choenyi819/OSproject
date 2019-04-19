#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
int avall[3];
struct process{
  int all[3];
  int max[3];
  int need[3];
  int flag;
  char processes[3];
  int aval[3];
}p[10];
void table(process p[],int n);
int main()
{
	system("COLOR 5");
  int i, j, n=5,c=0;
  int sq[10],ava[3];
  //allocation
  p[0].all[0]=0; p[0].all[1]=1; p[0].all[2]=0;
  p[1].all[0]=2; p[1].all[1]=0; p[1].all[2]=0;
  p[2].all[0]=3; p[2].all[1]=0; p[2].all[2]=2;
  p[3].all[0]=2; p[3].all[1]=1; p[3].all[2]=1;
  p[4].all[0]=0; p[4].all[1]=0; p[4].all[2]=2;
// max
  p[0].max[0]=7; p[0].max[1]=5; p[0].max[2]=3;
  p[1].max[0]=3; p[1].max[1]=2; p[1].max[2]=2;
  p[2].max[0]=9; p[2].max[1]=0; p[2].max[2]=2;
  p[3].max[0]=2; p[3].max[1]=2; p[3].max[2]=2;
  p[4].max[0]=4; p[4].max[1]=3; p[4].max[2]=3;
  //need=max-all;
  for(i=0;i<n;i++)
  {
    //printf("\n");
    for(j=0;j<3;j++)
      {p[i].need[j]=p[i].max[j]-p[i].all[j];
        //printf("%d ",p[i].need[j]);
      }

    p[i].flag=0;
    //printf("\n%d",p[i].flag);
  }
  ava[0]=3; ava[1]=3; ava[2]=2;
  avall[0]=ava[0];avall[1]=ava[1];avall[2]=ava[2];
  printf("\n+----------------+\n");
  printf("|   *Available*  |\n");
  printf("+----------------+\n");
  i=0,j=0;
  //Tenzin's bankers algorithm
  while(c<(n-1))
  {
  for(i=0;i<n;i++)
  { 
    if(p[i].flag==0)
    {
      if((p[i].need[j]<=ava[j]) && (p[i].need[j+1]<=ava[j+1] )&& (p[i].need[j+2]<=ava[j+2]))
      {
        ava[j]+=p[i].all[j]; ava[j+1]+=p[i].all[j+1]; ava[j+2]+=p[i].all[j+2];
        p[i].flag=1;
        p[i].aval[0]=ava[j];
        p[i].aval[1]=ava[j+1];
		p[i].aval[2]=ava[j+2];
        sq[c++]=i;
        printf("| %d  |  %d  |  %d  |",p[i].aval[0],p[i].aval[1],p[i].aval[2]);
        //printf("| %d  ",p[i].aval[1]);
        //printf("| %d  \n",p[i].aval[2]);
        printf("\n+----------------+\n");
      }
      if(c>n-1)
        break;
    }
  }
  if(c>n-1)
    break;
  }table(p,n);
  if(c==5){
    printf("\nSystem is in safestate.\nSequence of process is:");
    for(i=0;i<n;i++){
      printf("\nP[%d]",sq[i]);
    }
  }
  //table(p,n);
return 0;
} 
void table(process p[], int n)
{
    int i;

    puts("\n\n+-----------+-----------+------------+-----------+-----------+");
    puts("| Available | Processes | Allocation |    Max    |    Need   |");
    puts("+-----------+           +------------+-----------+-----------+");
    puts("| A | B | C |           | A | B | C  | A | B | C | A | B | C |");
    puts("+-----------+-----------+------------+-----------+-----------+");

    for(i=0; i<6; i++) {
    	if(i==0){
    		printf("|  %d  %d  %d  |    P[%d]   |  %d  %d  %d   |  %d  %d  %d  |  %d  %d  %d  |\n",avall[0],avall[1],avall[2], i,
		p[i].all[0],p[i].all[1], p[i].all[2], p[i].max[0],p[i].max[1] ,p[i].max[2], p[i].need[0],p[i].need[1],p[i].need[2] ); 
		puts("+-----------+-----------+------------+-----------+-----------+");
		}
		else if(i==5){
		printf("|  %d  %d  %d  |      0    |  %d  %d  %d   |  %d  %d  %d  |  %d  %d  %d  |\n",p[i-1].aval[0], p[i-1].aval[1], p[i-1].aval[2],
		p[i].all[0],p[i].all[1], p[i].all[2], p[i].max[0],p[i].max[1] ,p[i].max[2], p[i].need[0],p[i].need[1],p[i].need[2] );
	 	puts("+-----------+-----------+------------+-----------+-----------+");	}
		else{		
        printf("|  %d  %d  %d  |    P[%d]   |  %d  %d  %d   |  %d  %d  %d  |  %d  %d  %d  |\n",p[i-1].aval[0], p[i-1].aval[1], p[i-1].aval[2], i,
		p[i].all[0],p[i].all[1], p[i].all[2], p[i].max[0],p[i].max[1] ,p[i].max[2], p[i].need[0],p[i].need[1],p[i].need[2] ); 
		puts("+-----------+-----------+------------+-----------+-----------+");
		}
	}

}

