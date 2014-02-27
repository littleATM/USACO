/*
ID: yang.su1
PROG: dualpal
LANG: C++
*/
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int judge(string a);
string transform(int p,int n);
int main()
{
    ifstream inFile;
    ofstream outFile;
    int N,S;
    inFile.open("dualpal.in");
    outFile.open("dualpal.out");
    inFile>>N;
    inFile>>S;
    int i,n,j=1;
    int q=0;
    for(i=S+1;j<=N;i++)
    { 
                      for(n=2;n<=10;n++)
                      {
                                        if(judge(transform(i,n)))
                                        {
                                                                 q++;
                                        }
                                        if(q==2)
                                        {
                                               j++;
                                               outFile<<i<<endl;
                                               break;
                                        }
                      }
                      q=0;
    }
    return 0;
} 
int judge(string a)
{
    int i,n;
    int j=1;
    string b;
    n=a.size();
    for(i=0;i!=n;i++)
    {
                     b[n-i-1]=a[i];
    }
    for(i=0;i!=n;i++)
    {
                     if(b[i]!=a[i])
                     {
                                   j=0;
                                   break;
                     }
    }
    return j;
}
string transform(int p,int n)
{
       string str1,str2;
       int remainder,division,x,i;
       for(division=p;division!=0;)
       {
                 remainder=(division%n);
                 division=(division/n);
                 x=remainder+48;
                 str2=x;
                 str1=str1+str2;
                
        }
        str2=str1;
        for(i=0;i!=str1.size();i++)
        str2[str1.size()-i-1]=str1[i];
        return str2;
       
}
