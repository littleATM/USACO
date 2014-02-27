
/*
ID: yang.su1
PROG:nocows
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int N,K;
int move(int i,int j);
int rank[100][201];
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("nocows.in");
    outFile.open("nocows.out");
    inFile>>N>>K;
    inFile.close();
    int i,j;
    for(i=0;i!=100;i++)
    for(j=0;j!=201;j++)
                       rank[i][j]=-1;
    rank[1][1]=1;
    outFile<<move(K,N)<<endl;
    return 0;
}
int move(int i,int j)
{
    int p,q,k;
    if(rank[i][j]==-1)
    {
                       rank[i][j]=0;
                       k=0;
                       for(p=1;p<=i;p++)
                       {
                                        k+=1;
                                        k=k*2-1;
                                        if(k>=j)
                                        break;
                       }
                       if(p<=i&&j>=2*i-1)
                       for(p=1;p<=i-1;p++)
                       for(q=2;q<j;q=q+2)
                       { 
                                         if(p<i-1)
                                         rank[i][j]=(rank[i][j]+(move(p,q-1)*move(i-1,j-q))*2)%9901; 
                                         if(p==i-1)
                                         rank[i][j]=(rank[i][j]+move(p,q-1)*move(i-1,j-q))%9901;
                       }                    
    }
    return rank[i][j];
}
