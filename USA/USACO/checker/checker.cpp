
/*
ID: yang.su1
PROG:checker
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int pad[13][13];
int outPut[3][13];
int move(int i,int n);
int s=0;
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("checker.in");
    outFile.open("checker.out");
    int N;
    inFile>>N;
    int i,j;
    for(i=0;i!=13;i++)
    for(j=0;j!=13;j++)
    pad[i][j]=0;
    move(0,N);
    for(i=0;i!=3;i++)
    { 
                     for(j=0;j!=N;++j)
                     if(j<N-1)
                     outFile<<outPut[i][j]+1<<" ";
                     else
                     outFile<<outPut[i][j]+1;
                     outFile<<endl; 
    }
    outFile<<s<<endl;
} 
int move(int i,int n)
{
    int j,k,p,q;
    if(i==n)
    {
            if(s<3)
                   for(p=0;p!=n;p++)
                   for(q=0;q!=n;q++)
                                     if(pad[p][q]>18)
                                     {
                                                     outPut[s][p]=q;
                                                     break;
                                     }
            s++;
    }
    else
    for(j=0;j!=n;j++)
    {
                    if(pad[i][j]==0)
                    {
                                  pad[i][j]+=100;
                                  for(p=i;p<n;p++)
                                  {
                                                   pad[p][j]+=1;
                                                   if((j+i-p)>=0)
                                                   pad[p][j+i-p]+=1;
                                                   if((j+p-i)<n)
                                                   pad[p][j+p-i]+=1;
                                  }
                                  move(i+1,n);
                                  pad[i][j]-=100;
                                  for(p=i;p<n;p++)
                                  {
                                                   pad[p][j]-=1;
                                                   if((j+i-p)>=0)
                                                   pad[p][j+i-p]-=1;
                                                   if((j+p-i)<n)
                                                   pad[p][j+p-i]-=1;
                                  }
                    }
    }
    return 0;
}
