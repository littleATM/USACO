/*
ID: yang.su1
PROG:camelot
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int R,C;
int inPut[800][2]={0};
int kingInPut[2];
int kingGraph();
int knightGraph(int r,int c);
int king[31][327]={0};
int knight[31][27][31][27]={0};
int knightSum[31][27]={0};
bool knightjudge[31][27]={0};
int minSum=999999999;
int END;
int move();
int main(){
    ifstream inFile;
    ofstream outFile;
    inFile.open("camelot.in");
    outFile.open("camelot.out");
    inFile>>R>>C;
    int i,j,k;
    char x;
    END=-1;
    while(inFile>>x>>k){
        END++;
        if(END==0){
            kingInPut[1]=x-'A'+1;
            kingInPut[0]=k;
            }
        else{
             inPut[END][1]=x-'A'+1;
             inPut[END][0]=k;
            }     
        }
    kingGraph();
    for(k=1;k<=END;k++){
        knightGraph(inPut[k][0],inPut[k][1]);
        knightjudge[inPut[k][0]][inPut[k][1]]=1;
        for(i=1;i<=R;i++)
            for(j=1;j<=C;j++)
                knightSum[i][j]+=knight[inPut[k][0]][inPut[k][1]][i][j];
        }
    for(i=1;i<=R;i++)
        for(j=1;j<=C;j++)
            minSum=(minSum<knightSum[i][j]+king[i][j]?minSum:knightSum[i][j]+king[i][j]);
    move();
    outFile<<minSum<<endl;    
        return 0;
    }
int kingGraph(){
    int i,j,k,end;
    for(i=1;i<=R;i++)
        for(j=1;j<=C;j++)
            king[i][j]=9999999;
    int queue[8000][3]={0};
    end=1;
    queue[1][0]=kingInPut[0];
    queue[1][1]=kingInPut[1];
    queue[1][2]=0;
    for(k=1;k<=end;k++)
        if(king[queue[k][0]][queue[k][1]]>queue[k][2]){
            king[queue[k][0]][queue[k][1]]=queue[k][2];
            for(i=-1;i<=1;i++)
                for(j=-1;j<=1;j++)
                    if(!(i==0&&j==0)&&(queue[k][0]+i)>0&&(queue[k][0]+i)<=R&&(queue[k][1]+j)>0&&(queue[k][1]+j)<=C){
                        end++;
                        queue[end][0]=queue[k][0]+i;
                        queue[end][1]=queue[k][1]+j;
                        queue[end][2]=queue[k][2]+1;
                        }
            }
    return 0;
    }
int knightGraph(int r,int c){
    int i,j,k,end;
    for(i=1;i<=R;i++)
        for(j=1;j<=C;j++)
            knight[r][c][i][j]=9999999;
    int queue[8000][3]={0};
    end=1;
    queue[1][0]=r;
    queue[1][1]=c;
    queue[1][2]=0;
    for(k=1;k<=end;k++)
        if(knight[r][c][queue[k][0]][queue[k][1]]>queue[k][2]){
            knight[r][c][queue[k][0]][queue[k][1]]=queue[k][2];
            for(i=-2;i<=2;i++)
                for(j=-2;j<=2;j++)
                    if(i!=0&&j!=0&&(i+j==3||i+j==-3||i+j==1||i+j==-1)&&(queue[k][0]+i)>0&&(queue[k][0]+i)<=R&&(queue[k][1]+j)>0&&(queue[k][1]+j)<=C){
                        end++;
                        queue[end][0]=queue[k][0]+i;
                        queue[end][1]=queue[k][1]+j;
                        queue[end][2]=queue[k][2]+1;
                        }
            }
    return 0;    
    }
int move(){
    int i,j,m,n,r,c,k,w;
    for(i=1;i<=R;i++)
        for(j=1;j<=C;j++)
            if(knightSum[i][j]<minSum)
                for(r=1;r<=R;r++)
                    for(c=1;c<=C;c++)
                        if(knightSum[i][j]+king[r][c]<minSum){
                            if(knightjudge[r][c]==0){
                                knightGraph(r,c);
                                knightjudge[r][c]=1;
                                }
                            for(k=1;k<=END;k++)
                                if(knightSum[i][j]+king[r][c]+knight[r][c][i][j]+knight[r][c][inPut[k][0]][inPut[k][1]]-knight[inPut[k][0]][inPut[k][1]][i][j]<minSum)
                                    minSum=knightSum[i][j]+king[r][c]+knight[r][c][i][j]+knight[r][c][inPut[k][0]][inPut[k][1]]-knight[inPut[k][0]][inPut[k][1]][i][j];
                            }
    return 0;
    }
