
/*
ID: yang.su1
PROG:runround
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int check(unsigned int m);
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("runround.in");
    outFile.open("runround.out");
    int M;
    inFile>>M;
    inFile.close();
    unsigned int m;
    for(m=M+1;check(m)==0;m++);
    outFile<<m<<endl;
    return 0;
}
int check(unsigned int m)
{
    int round[10];
    int i,j,k,J;
    if(m==0)
    return 0;
    for(i=0;m%10!=0;m=m/10)
    {
                                i++;
                                round[i]=m%10;
    }
    if(m!=0)
    return 0;
    for(j=1;j<=i;j++)
    for(k=1;k<=i;k++)
    if(round[j]==round[k]&&j!=k)
    return 0;
    k=0;
        for(j=i;;k++)
        {
                  if((j==i&&k!=0)||k==i)
                  {
                                 if(k==i&&j==i)
                                 return 1;
                                 else
                                 return 0;
                  }
                  else
                  {
                      J=j;
                      j=(j+11*i-round[j])%i==0?i:(j+10*i-round[j])%i;
                      if(round[J]==round[j])
                      return 0;
                  } 
        }
}
