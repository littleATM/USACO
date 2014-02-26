
/*
ID: yang.su1
PROG:concom
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("concom.in");
    outFile.open("concom.out");
    int N;
    inFile>>N;
    int company[101][101];

    int i,j,k,m,n,max;
    max=0;

    for(i=0;i<=100;i++)
    for(j=0;j<=100;j++)
    company[i][j]=0;
    for(k=1;k<=N;k++)
    {
                     inFile>>i>>j;
                     inFile>>company[i][j];
                     max=(max>i?max:i);
                     max=(max>j?max:j);         
    }
    for(i=1;i<=max;i++)
    for(j=1;j<=max;j++)
    {
                       if(company[i][j]>50&&i!=j)
                       {
                                           company[i][j]=-1;
                                           for(k=1;k<=max;k++)
                                           if(company[i][k]!=-1)
                                           {
                                                                if(company[j][k]!=-1)
                                                                company[i][k]+=company[j][k];
                                                                else
                                                                company[i][k]=-1;
                                           }
                                           j=0;
                       }
                       
    }
    for(i=1;i<=max;i++)
    for(j=1;j<=max;j++)
    if(i!=j&&company[i][j]==-1)
    outFile<<i<<" "<<j<<endl;
    return 0;
} 
