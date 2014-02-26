/*
ID: yang.su1
PROG:maze1
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
    inFile.open("maze1.in");
    outFile.open("maze1.out");
    int W,H;
    inFile>>W>>H;
    inFile.get();
    string maze[203];
    int i,j,k,i1,j1,i2,j2,max;
    i1=-1;
    for(i=0;i!=2*H+1;i++)
    getline(inFile,maze[i]);
    int move[102][40];
    for(i=0;i!=2*H+1;i++)
    for(j=0;j!=2*W+1;j++)
    if((j==0||j==2*W||i==0||i==2*H)&&maze[i][j]==' ')
    {
                                                   if(i1==-1)
                                                   {
                                                             i1=i;
                                                             j1=j;
                                                   }
                                                   else
                                                   {
                                                       i2=i;
                                                       j2=j;
                                                   }
                                                   maze[i][j]='-';                                                   
    }
    for(i=0;i!=H;i++)
    for(j=0;j!=W;j++)
    {
                     move[i][j]=3800;
                     if(((2*(i+1)==i1||2*i==i1)&&2*(j+1)-1==j1)||(2*(i+1)-1==i1&&(2*j==j1||2*(j+1)==j1)))
                     move[i][j]=1;
                     if(((2*(i+1)==i2||2*i==i2)&&2*(j+1)-1==j2)||(2*(i+1)-1==i2&&(2*j==j2||2*(j+1)==j2)))
                     move[i][j]=1;               
    }
    for(k=1;k<=3800;k++)
    for(i=0;i!=H;i++)
    for(j=0;j!=W;j++)
    {
                     if(maze[2*i][2*(j+1)-1]==' ')
                     move[i-1][j]=(move[i][j]+1<move[i-1][j]?move[i][j]+1:move[i-1][j]);
                     if(maze[2*(i+1)][2*(j+1)-1]==' ')
                     move[i+1][j]=(move[i][j]+1<move[i+1][j]?move[i][j]+1:move[i+1][j]);
                     if(maze[2*(i+1)-1][2*(j+1)]==' ')
                     move[i][j+1]=(move[i][j]+1<move[i][j+1]?move[i][j]+1:move[i][j+1]);
                     if(maze[2*(i+1)-1][2*j]==' ')
                     move[i][j-1]=(move[i][j]+1<move[i][j-1]?move[i][j]+1:move[i][j-1]);
    }
    max=0;
    for(i=0;i!=H;i++)
    for(j=0;j!=W;j++)
    max=(max>move[i][j]?max:move[i][j]);
    outFile<<max<<endl;
    return 0;  
}
