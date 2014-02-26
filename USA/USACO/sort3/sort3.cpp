
/*
ID: yang.su1
PROG:sort3
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("sort3.in");
    outFile.open("sort3.out");
    int N;
    int sort[1100];
    inFile>>N;
    int i,j,k,p,q,x1,x2,x3,x12,x13,x21,x23,x31,x32,t;
    x1=0;
    x2=0;
    x3=0;
    x12=0;
    x13=0;
    x21=0;
    x23=0;
    x31=0;
    x32=0;
    for(i=1;i<=N;i++)
    {
                     inFile>>sort[i];
                     if(sort[i]==1)
                     x1++;
                     if(sort[i]==2)
                     x2++;
                     if(sort[i]==3)
                     x3++;
    }
    inFile.close();
    for(i=1;i<=N;i++)
    {
                     if(i<=x1)
                     {
                              if(sort[i]==2)
                              x12++;
                              if(sort[i]==3)
                              x13++;
                              
                     }
                     if(i<=x1+x2&&i>x1)
                     {
                              if(sort[i]==1)
                              x21++;
                              if(sort[i]==3)
                              x23++;
                              
                     }
                     if(i>x2+x1)
                     {
                              if(sort[i]==2)
                              x32++;
                              if(sort[i]==1)
                              x31++;
                              
                     }
                     
    }
    t=x12+x13;
    if(x31>=x13)
    t+=x32+x31-x13;
    else
    t+=x23+x21-x12;
    outFile<<t<<endl;
    return 0;
} 
