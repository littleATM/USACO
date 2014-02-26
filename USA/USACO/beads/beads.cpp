
/*
ID: yang.su1
PROG: beads
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;

    int i=0,j=0;
    int N;
    int length=0;
    int lengthMax=0;
    char behandColour='r';
int main()
{

    ifstream inFile;
    inFile.open("beads.in");
    inFile>>N;
    char *beads=new char[2*N];
    for(i=0;i!=N;i++)
    {
                     inFile>>beads[i];
                     beads[i+N]=beads[i];
    }
    for(i=0;i!=2*N;i++)
    {
                     if(beads[i]!=behandColour&&beads[i]!='w')
                     {
                                                             if(lengthMax>length)
                                                             ;
                                                             else
                                                             lengthMax=length;
                                                             length=0;
                                                             for(j=i;j>0&&(beads[j-1]==behandColour||beads[j-1]=='w');j--)
                                                             {
                                                                                                                        length++;
                                                             }
                                                             behandColour=beads[i];
                     }
                      length++;                
    }
    if(lengthMax>length)
    ;
    else
    lengthMax=length;
    ofstream outFile;
    outFile.open("beads.out");
    if(lengthMax>N)
    lengthMax=N;
    outFile<<lengthMax<<endl;
    return 0;
    
    
    
}

