/*
ID: yang.su1
PROG:barn1
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("barn1.in");
    outFile.open("barn1.out");
    int M,S,C,i,j,max,n;
    int sum=0;
    inFile>>M>>S>>C;
    int *stall=new int[C];
    for(i=0;i!=C;i++)
    inFile>>stall[i];
    for(i=1;i<=C;i++)
    {
                     for(j=1,max=stall[0];j!=C-i+1;j++)
                     {
                               if(max<=stall[j])
                               {
                                                stall[j-1]=max;
                                                max=stall[j];
                               }
                               else
                               stall[j-1]=stall[j];       
                     }
                     stall[C-i]=max;
    }
    int *mid=new int[C-1];
    for(i=0;i!=C-1;i++)
    {
                       mid[i]=stall[i+1]-stall[i]-1;
    }
    for(i=1;i<=M-1&&i<=C-1;i++)
    {
             for(j=0,max=0;j!=C-1;j++)
             {
                                      if(max<=mid[j])
                                      {
                                                     max=mid[j];
                                                     n=j;
                                      }
                                      
             }
             mid[n]=0;
             sum=sum+max;      
    }
    outFile<<stall[C-1]-stall[0]+1-sum<<endl;
    return 0;
    
    
} 
