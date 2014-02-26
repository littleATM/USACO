
/*
ID: yang.su1
PROG:ariprog
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("ariprog.in");
    outFile.open("ariprog.out");
    int M,N,i,j,k,n,m,t,s;
    inFile>>N>>M;
    inFile.close();
    int *bis=new int[70000];
    bis[1]=0;
    k=1;
    for(i=0;i<=M;i++)
    for(j=i;j<=M;j++)
    for(t=1;t<=k;)
    {
                  if((i*i+j*j)<bis[t])
                  t++;
                  if((i*i+j*j)==bis[t])
                  break;
                  if((i*i+j*j)>bis[t])
                  {
                                      for(s=k;s>=t;s--)
                                      {
                                                       bis[s+1]=bis[s];
                                      }
                                      bis[t]=i*i+j*j;
                                      k++;
                  }
    }
    n=0;
    int*BIS=new int[125000];
    for(i=0;i!=bis[1];i++)
                     BIS[i]=0;
    for(i=1;i<=k;i++)
                     BIS[bis[i]]=1;

    for(j=1;(N-1)*j<=bis[1];j++)
                                    for(i=k;(bis[i]+(N-1)*j)<=bis[1]&&i>=1;i--)
                                                       for(s=1;s<=N-1&&BIS[bis[i]+s*j]==1;s++)
                                                                          if(s==N-1)
                                                                          {                                                                                                                                                                  
                                                                                    outFile<<bis[i]<<" "<<j<<endl;
                                                                                    n=1;
                                                                          }
    if(n==0)
    outFile<<"NONE"<<endl;
    return 0;
} 
