
/*
ID: yang.su1
PROG:castle
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
struct module
{
       int walls;
       int roomNumber;
};
int s=1;
int a=0;
int b=0;
module base[51][51];
int castle(int i,int j);
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("castle.in");
    outFile.open("castle.out");
    int M,N,i,j,p,q,I,J;
    char x;
    I=0;
    J=0;
    inFile>>M>>N;
    for(i=0;i!=51;i++)
    for(j=0;j!=51;j++)
                     base[i][j].roomNumber=1;
    for(i=0;i!=N;i++)
    for(j=0;j!=M;j++)
    {
                     inFile>>base[i][j].walls;
                     base[i][j].roomNumber=0;
    }
     for(j=0;j!=M;j++)
     for(i=N-1;i>=0;i--)
     if(base[i][j].roomNumber==0)
     {
                                 a=0;
                                 castle(i,j);
                                 b=(b>=a?b:a);
                                 s++;
     }
    for(i=0;i!=N;i++)
    for(j=0;j!=M;j++)
    base[i][j].roomNumber=0;
     outFile<<s-1<<endl<<b<<endl;
    for(p=0;p!=M;p++)
    for(q=N-1;q>=0;q--)
    {
                       if((base[q][p].walls/2)%2==1&&q!=0)
                       {
                                                    base[q][p].walls-=2;
                                                    base[q-1][p].walls-=8;
                                                    for(j=0;j!=M;j++)
                                                    for(i=N-1;i>=0;i--)
                                                    if(base[i][j].roomNumber==0)
                                                    {
                                                                                a=0;
                                                                                castle(i,j);
                                                                                if(a>b)
                                                                                {
                                                                                       b=a;
                                                                                       I=q;
                                                                                       J=p;
                                                                                       x='N';
                                                                                }
                                                    }
                                                    for(i=0;i!=N;i++)
                                                    for(j=0;j!=M;j++)
                                                    base[i][j].roomNumber=0;
                                                    base[q][p].walls+=2;
                                                    base[q-1][p].walls+=8;
                       }
                       if(((base[q][p].walls/2)/2)%2==1&&p!=M-1)
                       {
                                                        base[q][p].walls-=4;
                                                        base[q][p+1].walls-=1;
                                                        for(j=0;j!=M;j++)
                                                        for(i=N-1;i>=0;i--)
                                                        if(base[i][j].roomNumber==0)
                                                        {
                                                                                    a=0;
                                                                                    castle(i,j);
                                                                                    if(a>b)
                                                                                    {
                                                                                           b=a;
                                                                                           I=q;
                                                                                           J=p;
                                                                                           x='E';
                                                                                    }
                                                        }
                                                        for(i=0;i!=N;i++)
                                                        for(j=0;j!=M;j++)
                                                        base[i][j].roomNumber=0;
                                                        base[q][p].walls+=4;
                                                        base[q][p+1].walls+=1;
                       }
    }
    outFile<<b<<endl<<I+1<<" "<<J+1<<" "<<x<<endl;
    return 0;
}
int castle(int i,int j)
{
    if(i>=0&&base[i][j].roomNumber==0)
    {
                                a++;
                                base[i][j].roomNumber=s;
                                if(base[i][j].walls%2==0)
                                castle(i,j-1);
                                if((base[i][j].walls/2)%2==0)
                                castle(i-1,j);
                                if(((base[i][j].walls/2)/2)%2==0)
                                castle(i,j+1);
                                if((((base[i][j].walls/2)/2)/2)%2==0)
                                castle(i+1,j);
    }
}
