
/*
ID: yang.su1
PROG: namenum
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int insert(char a[],char b[]);
int compare(char a[],char b[]);
int main()
{
    int i,j;
    int x=0;
    ifstream inFile;
    ifstream inFile2;
    ofstream outFile;
    inFile2.open("namenum.in");
    outFile.open("namenum.out");
    char CODE[13];
    char number[13];
    char NUMBER[13]="222222222222";
    inFile2>>number;
    inFile2.close();
    inFile.open("dict.txt");
    for(int i=0;i!=5000&&compare(number,NUMBER);i++)
    {
            inFile>>CODE;
            insert(CODE,NUMBER);
            for(j=0;NUMBER[j]==number[j]&&number[j]!='\0';j++);
            if(number[j]=='\0'&&NUMBER[j]=='\0')
            {
                                                outFile<<CODE<<endl;
                                                x=1;
            }
            
            
    }
    if(x==0)
    outFile<<"NONE"<<endl;
    return 0;
    
} 
int insert(char a[],char b[])
{
    int i;
    for(i=-1;a[i]!='\0'||i==-1;)
    {
                       i++;
                       if(a[i]<81&&a[i]>=65)
                       b[i]=(a[i]-65)/3+50;
                       if(a[i]>81&&a[i]<90)
                       b[i]=55+(a[i]-81)/3;
                       if(a[i]=='Z'||a[i]=='Q')
                       b[i]=48;
                       if(a[i]=='\0')
                       b[i]='\0';
    }
    return 0;
}
int compare(char a[],char b[])
{
    int B=1;
    if(b[0]!=a[0]&&a!='\0')
    B=(a[0]>b[0]);
    return B;
}
