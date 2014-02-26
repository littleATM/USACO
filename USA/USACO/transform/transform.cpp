/*
ID: yang.su1
PROG: transform 
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int rotate(char *now,int n);
int reflection(char *now,int n);
int contrast(char *now,char *latest,int n);

int main()
{
    int i=0,j=0,N=0;
    ifstream inFile;
    inFile.open("transform.in");
    ofstream outFile;
    outFile.open("transform.out");
    inFile>>N;
    char * transformNow=new char [N*N];
    char * transformLatest=new char [N*N];
    for(i=0;i!=N*N;i++)
    {
                       inFile>>transformNow[i];
    }
    for(i=0;i!=N*N;i++)
    {
                       inFile>>transformLatest[i];
    }

        for(i=1;i!=9;i++)
        {
                         rotate(transformNow,N);
                         if(i==4||i==8)
                         reflection(transformNow,N);
                         if(contrast(transformNow,transformLatest,N)==1)
                         break;
        }
        if(i<=5)
        outFile<<i;
        if(i==6||i==7)
        outFile<<5;
        if(i==8)
        outFile<<6;
        if(i==9)
        outFile<<7;
        outFile<<endl;
        return 0;   
}
int rotate(char *now,int n)
{
    int i=0;
    char *mid=new char[n*n];
    for(i=0;i!=n*n;i++)
    {
                       mid[((i+1)%n)*n+!((i+1)%n)*n*n-(i+1)/n+!((i+1)%n)-1]=now[i];//mid[m][n]:M=(i+1)modN+!((i+1)modN)
                       //n=(i+1)/N+1-!((i+1)modN)
    }
    for(i=0;i!=n*n;i++)
    {
                     now[i]=mid[i];
    }
    return 0; 
}
int reflection(char *now,int n) 
{
    int i=0;
    char *mid=new char[n*n];
    for(i=0;i!=n*n;i++)
    {
                       mid[i+1-(i+1)%n+(!(!((i+1)%n)))*(n-(i+1)%n)+(!((i+1)%n))*(-n)]=now[i];//fuck
    }
    for(i=0;i!=n*n;i++)
    {
                     now[i]=mid[i];
    }
    return 0;
}
int contrast(char *now,char *latest,int n)
{
    int even=1;
    int i=0;
    for(i=0;i!=n*n;i++)
    {
                             if(now[i]!=latest[i])
                             {
                                                  even=0;
                                                  break;
                             }
    }
    return even;
}
