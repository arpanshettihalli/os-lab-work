#include<stdio.h>
#include<stdlib.h>
int b[] = {200,400,600,500,300,250},p[]={357,210,468,491};
void firstfit()
{
int alloc[6]={0};
  for(int i=0;i<4;i++)
  {
    int k=-1;
    for(int j=0;j<6;j++)
    {
      if(p[i]<=b[j] && alloc[j]!=1)
      {k=j;
      break;
      }
    }
    if(k<0)
    {printf("%d KB->not allocated\n",p[i]);
    }
    else{
    alloc[k]=1;
    printf("%d KB -> %d KB\n",p[i],b[k]);}
    }
  }
void bestfit()
{
  int alloc[6]={0};
  for(int i=0;i<4;i++)
  {
    int k=-1;
    for(int j=0;j<6;j++)
    {
      if(k<0 || b[j]<b[k] && p[i]<=b[j] && alloc[j]!=1)
      {k=j;
      break;
      }
    }
    if(k<0)
    {printf("%d KB->not allocated\n",p[i]);
    }
    else{
    alloc[k]=1;
    printf("%d KB -> %d KB\n",p[i],b[k]);}
    }
  }
void worstfit()
{
  int alloc[6]={0};
  for(int i=0;i<4;i++)
  {
    int k=-1;
    for(int j=0;j<6;j++)
    {
      if(k<0 || b[j]>b[k] && p[i]<=b[j] && alloc[j]!=1)
      {k=j;
      break;
      }
    }
    if(k<0)
    {printf("%d KB->not allocated\n",p[i]);
    }
    else{
    alloc[k]=1;
    printf("%d KB -> %d KB\n",p[i],b[k]);}
    }
  }
