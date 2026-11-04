#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int head=50;
int req[7]={82,170,43,140,24,16,190};
void sort(int arr[])
{
  for(int i=0;i<6;i++)
  {
    int min=arr[i];
    int index=i;
    for(int j=i+1;j<7;j++)
    {
      if(arr[j]<min)
      {
        min=arr[j];
        index=j;
      }
    }
    int temp=arr[i];
    arr[i]=min;
    arr[index]=temp;
  }
}
void scan()
{ int requests[7];
int pos=head;
  for(int i=0;i<7;i++)
  {
    requests[i]=req[i];
  }
  sort(requests);
  int seek=0;
  for(int i=0;i<7;i++)
  {
    if(requests[i]>head)
    {
      seek+=abs(pos-requests[i]);
      pos=requests[i];
    }
  }
  if(pos!=200)
  {
    seek+=abs(pos-200);
    pos=200;
  }
  for(int i=6;i>=0;i--)
  {
    if(requests[i]<head)
    {
      seek+=abs(pos-requests[i]);
      pos=requests[i];
    }
  }
  printf("%d",seek);
}
void cscan()
{ int requests[7];
int pos=head;
  for(int i=0;i<7;i++)
  {
    requests[i]=req[i];
  }
  sort(requests);
  int seek=0;
  for(int i=0;i<7;i++)
  {
    if(requests[i]>head)
    {
      seek+=abs(pos-requests[i]);
      pos=requests[i];
      printf("%d-->",pos);
    }
  }
  if(pos!=200)
  {
    seek+=abs(pos-200);
    printf("%d-->",200);
    pos=200;
  }
  seek+=200;
  printf("%d-->",0);
  pos=0;
  for(int i=0;i<=6;i++)
  {
    if(requests[i]<head)
    {
      seek+=abs(pos-requests[i]);
      pos=requests[i];
      printf("%d-->",pos);
    }
  }
  printf("\n%d\n",seek);
}
    
void sstf()
{
  int pos=head;
  int seek=0;
  int done[7]={0};
  for(int k=0;k<7;k++)
  {
    int min=200;
    int best=-1;
    for(int i=0;i<7;i++)
    {
      if(done[i]==0 && abs(pos-req[i])<min)
      {
        min=abs(pos-req[i]);
        best=i;
      }
    }
    done[best]=1;
    seek+=min;
    pos=req[best];
}
printf("%d",seek);
}
      
void fcfs()
{ 
int pos=head;
int seek=0;
  for(int i=6;i>=0;i--)
  {
    seek+=abs(pos-req[i]);
    pos=req[i];
  }
  printf("%d",seek);
}
int main()
{
  fcfs();
  printf("\n");
  sstf();
  printf("\n");
  scan();
  printf("\n");
  cscan();
  return 0;
}
