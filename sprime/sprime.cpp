
/*
ID: yang.su1
PROG:sprime
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int s=0;
int outPut[1000];
int sprime(int n,int m);
int prime(int a);
int main()
{

    ifstream inFile;
    ofstream outFile;
    inFile.open("sprime.in");
    outFile.open("sprime.out");
    int N;
    inFile>>N;
    inFile.close();
    int i;
    sprime(N,0);
    for(i=0;i!=s;i++)
    outFile<<outPut[i]<<endl;
    return 0;
    
}
int sprime(int n,int m)
{
    int i;
    if(n==0)
    {
            outPut[s]=m;
            s++;
    }
    else
    for(i=1;i<=9;i++)
    if(prime(m*10+i))
    sprime(n-1,m*10+i);
    return 0; 
}
int prime(int a)
{
    int i;
    for(i=2;a%i!=0&&i*i<a;i++);
                                 if(i*i>a&&a!=1)
                                 return 1;
                                 return 0;
}
