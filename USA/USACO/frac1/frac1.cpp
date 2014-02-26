
/*
ID: yang.su1
PROG:frac1
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
struct frac
{
       int s;
       int m;
};
int check(int i,int j);
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("frac1.in");
    outFile.open("frac1.out");
    int N;
    inFile>>N;
    inFile.close();
    frac outPut[30000];
    int i,j,k,p,q;
    k=0;
    outPut[0].s=0;
    outPut[0].m=1;
    outPut[1].s=1;
    outPut[1].m=1;
    k=1;
    for(i=2;i<=N;i++)
    for(j=1;j!=i;j++)
    {
                     if(check(j,i))
                     {
                                     for(p=0;i*outPut[p].s<j*outPut[p].m;p++);
                                     for(q=k;q>=p;q--)
                                     outPut[q+1]=outPut[q];
                                     outPut[p].m=i;
                                     outPut[p].s=j;
                                     k++;
                     }
    }
    for(i=0;i<=k;i++)
    outFile<<outPut[i].s<<"/"<<outPut[i].m<<endl;
    return 0;
} 
int check(int i,int j)
{
    int p,q;
    for(p=2;p<=i/2+1;p++)
    if(i%p==0&&j%p==0||j%i==0)
    return 0;
    return 1;
}
