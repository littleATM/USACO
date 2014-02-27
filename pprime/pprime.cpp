
/*
ID: yang.su1
PROG:pprime
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int prime(int a);
int pal(int a,int h);
int p[100000];
int x1=0,x2=0,x3=0,x4=0,x=0;
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("pprime.in");
    outFile.open("pprime.out");
    int a,b,i,j;
    inFile>>a>>b;
    inFile.close();
    j=1;
    for(i=10;b/i!=0;i=i*10)
    j++;
    pal(j,b/(i/10));
    for(i=0;i!=x;i++)
                     if(prime(p[i])&&p[i]>=a&&p[i]<=b)
    outFile<<p[i]<<endl;
    return 0;
}
int prime(int a)
{
    int i;
    for(i=2;a%i!=0&&i*i<a;i++);
                                 if(i*i>a)
                                 return 1;
                                 return 0;
}
int pal(int n,int h)
{
    int i,j,m;
    m=1;
    for(i=1;i!=n;i++)
    m=m*10;
    if(n>1)
        pal(n-1,9);
        if(n%2==1)
        {
           for(i=0;i<=h;i++)
           {
                    for(j=x1;j<=x2;j++)
                    {
                    p[x]=(n==1?i:(p[j]*10+i+i*m));
                    x++;
                    }
            }
            x1=x4+1;
            if(n==1)
            x1=0;
            x2=x-1;
        }
        else
        {
            for(i=0;i<=h;i++)
            {
                    for(j=x3;j<=x4;j++)
                    {
                    p[x]=(n==2?(i+i*m):(p[j]*10+i+i*m));
                    x++;
                    }
             }
             x3=x2+1;
             x4=x-1;
        }
        return 0;
}
