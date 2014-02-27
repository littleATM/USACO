
/*
ID: yang.su1
PROG:lamps
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
struct lamp
{
       int l[1001];
};
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("lamps.in");
    outFile.open("lamps.out");
    int N,C;
    inFile>>N>>C;
    lamp lamps[2];
    lamp outPut[9];
    outPut[0].l[1]=-1;
    int i,j,k,m,n,m1,m2,m3,m4,p;
    j=0;
    for(i=1;i<=N;i++)
    lamps[0].l[i]=2;
    for(;;)
    {
                     inFile>>j;
                     if(j==-1)
                     break;
                     lamps[0].l[j]=1;
    }
    for(;;)
    {
                     inFile>>j;
                     if(j==-1)
                     break;
                     lamps[0].l[j]=0;
    }
    inFile.close();
    m=0;
    for(m1=0;m1<=1;m1++)
    for(m2=0;m2<=1;m2++)
    for(m3=0;m3<=1;m3++)
    for(m4=0;m4<=1;m4++)
    if(m1+m2+m3+m4<=C&&(m1+m2+m3+m4)%2==C%2)
    {
                                            k=1;
                                            for(i=1;i<=N;i++)
                                            {
                                                             lamps[1].l[i]=1;
                                                             if(m1==1)
                                                             lamps[1].l[i]=!lamps[1].l[i];
                                                             if(m2==1&&i%2==1)
                                                             lamps[1].l[i]=!lamps[1].l[i];
                                                             if(m3==1&&i%2==0)
                                                             lamps[1].l[i]=!lamps[1].l[i];
                                                             if(m4==1&&i%3==1)
                                                             lamps[1].l[i]=!lamps[1].l[i];
                                                             if(lamps[0].l[i]<2&&lamps[1].l[i]!=lamps[0].l[i])
                                                             {
                                                                                                              k=0;
                                                                                                              break;
                                                             }
                                            }
                                            if(k==1)
                                            {
                                                    for(i=0;i<=m;i++)
                                                    for(j=1;j<=N;j++)
                                                    {
                                                                     if(outPut[i].l[j]<lamps[1].l[j])
                                                                     break;
                                                                     if(outPut[i].l[j]>lamps[1].l[j])
                                                                     {
                                                                                                     for(p=m;p>=i;p--)
                                                                                                     outPut[p+1]=outPut[p];
                                                                                                     outPut[i]=lamps[1];
                                                                                                     m++;
                                                                                                     i=m+2;
                                                                                                     break;
                                                                     }
                                                    }
                                                    if(i==m+1)
                                                    {
                                                              m++;
                                                              outPut[m]=lamps[1];
                                                    }
                                            }
    }
    if(m==0)
    {
            outFile<<"IMPOSSIBLE"<<endl;
    }
    for(i=1;i<=m;i++)
    {
                     for(j=1;j<=N;j++)
                     outFile<<outPut[i].l[j];
                     outFile<<endl;
    }
    return 0;
    
} 
