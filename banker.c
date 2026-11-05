#include<stdio.h>
#include<stdlib.h>
int m=5,n=3;
int allocation[m][n]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
int maxi[m][n]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
int available[3]={3,3,2};
int need[m][n];
void calcneed()
{
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      need[i][j]=maxi[i][j]-allocation[i][j];
    }
  }
}
void printneed()
{
  printf("\n the need matrix\n");
  printf("thread A B C\n");
  for(int i=0;i<m;i++)
  {
    printf("T%d  %d  %d  %d\n",i,need[i][0],need[i][1],need[i][2]);
  }
}
int issafe(int alloc[m][n],int reqneed[n][m],int avail[n],int sequence[m])
{
  int work[n];
  int done[n]={0};
  for(int i=0;i<n;i++)
  {
    work[i]=avail[i];
  }
  int p=0;
  int count=0;
  while(count<5)
  { 
    int found=0;
    for(int i=0;i<5;i++)
    {
      if(done[i])continue;
      int ok=1;
      for(int j=0;j<3;j++)
      {
        if(work[j]<reqneed[i][j])
          ok=0;
          break;
      }
      if(ok)
      {
        for(int j=0;j<3;j++)
        {
          work[j]+=alloc[i][j];
        }
        seq[count++]=i;
        done[i]=1;
        found=1;
      }
    }
      if(!found)
      {
        return 0;
      }
    }
        return 1;
     }
void request(int t,int req[])
{
  int seq[5];
  printf("Request (%d,%d,%d) by T%d: ", req[0], req[1], req[2], t);
  for(int j=0;j<3;j++)
  {if(seq[j]>need[t][j]){printf("request cant be granted\n");return;}
  if(seq[j]>avail[j]){printf("request cant be granted\n");return;}
  }
  for(int j=0;j<3;j++)
  {
    avail[j]-=req[j];
    alloc[t][j]+=req[j]
    head[t][j]-=req[j];
  }
  if(issafe(seq)){
  printf("granted,safe,sequences:");
  for(int i=0;i<5;i++)
  {printf("T%d",seq[i]);
  }
  printf("\n");
  }
  else{
  for(int j=0;j<3;j++){
  available[j]-=req[j];
  alloc[t][j]+=req[j];
  need[t][j]-=req[j];
  }
  printf("denied,state would be unsafe\n");
  }
}
int main()
{
  calcneed();
  printneed();
  int seq[5];
  if(issafe(seq))
  {
    printf("the system is safe\n");
    for(int i=0;i<5;i++)printf("T%d".seq[i]);
  }
  else{
  printf("\nsystem is not safe\n");
  return 0;
  }
  int r1[R] = {1,0,2}, r2[R] = {3,3,0}, r3[R] = {0,2,0};
    request(1, r1);
    request(4, r2);
    request(0, r3);
    return 0;
  }
