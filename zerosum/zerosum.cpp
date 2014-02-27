
/*
ID: yang.su1
PROG:zerosum
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int move(int i);
int N;
char outPut[11];
ifstream inFile;
ofstream outFile;
int main()
{
    inFile.open("zerosum.in");
    outFile.open("zerosum.out");
    inFile>>N;
    inFile.close();
    outPut[1]='+';
    outPut[N+1]='+';
    move(2);
    return 0;
}
int move(int i)
{
    int f,h,x,j;
    int sum=0;
    if(i!=N+1)
    {
              outPut[i]=' ';
              move(i+1);
              outPut[i]='+';
              move(i+1);
              outPut[i]='-';
              move(i+1);
    }
    else
    {
        for(j=1;j<=N;j++)
        {
                         x=j;
                         for(f=j;outPut[f]==' ';f--);
                         for(h=j+1;outPut[h]==' ';h++)
                         x*=10;
                         if(outPut[f]=='-')
                         sum-=x;
                         else
                         sum+=x;
                         
                         
        }
        if(sum==0)
        {
                  outFile<<1;
                  for(j=2;j<=N;j++)
                  outFile<<outPut[j]<<j;
                  outFile<<endl;
        }
    }
    return 0;
} 
