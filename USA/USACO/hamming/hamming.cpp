
/*
ID: yang.su1
PROG:hamming
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("hamming.in");
    outFile.open("hamming.out");
    int N,B,D;
    inFile>>N>>B>>D;
    inFile.close();
    int i,j,k,m,n,a,b,x;
    int outPut[600];
    outPut[0]=0;
    b=0;
    for(j=1;b!=N-1;j++)
    {
                       for(a=0;a<=b;a++)
                       {
                                        x=0;
                                        m=outPut[a];
                                        n=j;
                                        for(k=1;k<=B&&x<D;k++)
                                        {
                                                               if(m%2!=n%2)
                                                               x++;
                                                               m=m/2;
                                                               n=n/2;
                                        }
                                        if(x<D)
                                        break;
                       }
                       if(a>b)
                       {
                                 b++;
                                 outPut[b]=j;
                       }
    }
    for(i=0;i!=N;i++)
    {
                     if(i%10!=9&&i!=N-1)
                     outFile<<outPut[i]<<" ";
                     if(i%10==9)
                     outFile<<outPut[i]<<endl;
                     if(i%10!=9&&i==N-1)
                     outFile<<outPut[i]<<endl;
    }

                              
    return 0;
} 
