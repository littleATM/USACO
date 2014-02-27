
/*
ID: yang.su1
PROG:holstein
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
struct vit
{
       int v[25];
};
int move(int i,int j);
int V,G;
vit inPut[1001];
vit sum;
int x=0;
int outPut[16];
int I;
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("holstein.in");
    outFile.open("holstein.out");
    int i,j,k,p,q;
    inFile>>V;
    for(i=0;i!=V;i++)
                     inFile>>inPut[0].v[i];
    inFile>>G;
    for(i=1;i<=G;i++)
    for(j=0;j!=V;j++)
    inFile>>inPut[i].v[j];
    for(i=1;i<=G&&x==0;i++)
    {
                           I=i;
                           move(0,i);
    }
    outFile<<i-1<<" ";
    for(j=0;j<=i-3;j++)
    outFile<<outPut[j]<<" ";
    outFile<<outPut[i-2]<<endl;
    return 0;
    
}
int move(int i,int j)
{
    int k,m;
    if(j>0)
    for(k=i+1;k<=G-j+1&&x==0;k++)
    {
                                 outPut[I-j]=k;
                                 for(m=0;m!=V;m++)
                                 sum.v[m]+=inPut[k].v[m];
                                 move(k,j-1);
                                 if(x==0)
                                 for(m=0;m!=V;m++)
                                 sum.v[m]-=inPut[k].v[m];
    }
    if(j==0)
    {
            for(k=0;k!=V;k++)
            if(inPut[0].v[k]>sum.v[k])
            break;
            if(k==V)
            x=1;
    }
}
