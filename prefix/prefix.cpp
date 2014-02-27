
/*
ID: yang.su1
PROG:prefix
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("prefix.in");
    outFile.open("prefix.out");
    string str[301];
    str[0]=' ';
    int N,S;
    int i,j,k,m,n,max;
    for(N=1;str[N-1]!=".";N++)
    inFile>>str[N];
    N-=2;
    max=0;
    string str1,str2;
    str1="a";
    for(;inFile>>str2;)
    str1+=str2;
    S=str1.size();
    int fix[250000];
    for(i=0;i!=250000;i++)
    fix[i]=0;
    for(i=1;i<=S;i++)
    for(j=1;j<=N;j++)
    for(k=i;str1[k]==str[j][str[j].size()-1-i+k]&&i>=str[j].size();k--);
    if((i-k)==str[j].size())
    fix[i]=(fix[i]>(fix[i-str[j].size()]+str[j].size())?fix[i]:(fix[i-str[j].size()]+str[j].size()));
    for(i=1;i<=S;i++)
    {
                      if(fix[i]==i)
                      max=(max>i?max:i);
    }
    outFile<<max<<endl;
    return 0;
} 
