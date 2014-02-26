/*
ID: yang.su1
PROG: milk2
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int max(int m,int n);
int min(int m,int n);
int main()
{
    int i=0;
    int j=0;
    int p=0;
    int N;
    int MAX=0;
    int maxNumber=0;
    int length=0;
    int oneMax=0;
    int noneMax=0;
    ifstream inFile;
    inFile.open("milk2.in");
    inFile>>N;
    int *milk=new int [N];
    int *milk2=new int [N];
    for(i=0;i!=2*N;i++)
    {
                     if(i%2==0)
                     {
                               inFile>>milk[i/2];
                     }
                     else
                     inFile>>milk2[(i-1)/2];
    }

    for(i=N-1;i>=0;i--)
    {
                       for(j=i+1;j<=N-1;j++)
                       {
                                            if((milk[j]>=0)&&(milk[j]<=milk2[i])&&(milk[i]<=milk2[j]))
                                            {
                                                                                              milk[i]=min(milk[i],milk[j]);
                                                                                              milk2[i]=max(milk2[i],milk2[j]);
                                                                                              milk[j]=-1;
                                            }
                       }
    }
           
    for(i=0;i!=N;i++)
    {
                     if(milk[i]>=0)
                     length++;
                     
    }
    int *MILK=new int[length];
    int *MILK2=new int[length];
    for(i=0;i!=length;i++)
    {
                          for(j=0;j!=N;j++)
                          {
                                           if(milk[j]>=MAX)
                                           {
                                                              MAX=milk[j];
                                                              maxNumber=j; 
                                           }   
                          }
                          MILK[p]=milk[maxNumber] ;
                          MILK2[p]=milk2[maxNumber];
                          milk[maxNumber]=-1;
                          p++;
                          MAX=0;
    }

    for(i=0;i!=length;i++)
    {
                          oneMax=max(oneMax,(MILK2[i]-MILK[i]));
                          if(i!=length-1)
                          noneMax=max(noneMax,(MILK[i]-MILK2[i+1]));
    }
    ofstream outFile;
    outFile.open("milk2.out");
    outFile<<oneMax<<" "<<noneMax<<endl;
    return 0;
    
    
    
    
}
int max(int n,int m)
{
    if(n>=m)
    {
            return n;
    }
    else
    return m;
} 
int min (int n,int m)
{
    if(n>=m)
    {
            return m;
    }
    else
    return n;
}
