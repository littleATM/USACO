/*
ID:yang.su1
PROB:frameup
LANG:C++
*/
#include<stdio.h>
FILE *fin,*fout;
int H,W;
int flag;
char pic[30][400][400];
bool T[300][300]={0};
int sum;
char output[100000];
int read_data(){
    int i,j;
    flag=0;
    sum=0;
    fin=fopen("frameup.in","r");
    fout=fopen("frameup.out","w");
    fscanf(fin,"%d %d",&H,&W);
    for(i=1;i<=H;i++){
        fscanf(fin,"%c",&pic[0][i][1]);
        for(j=1;j<=W;j++)
           fscanf(fin,"%c",&pic[0][i][j]);
           }
    return 0;
    }
int initialize(){
    int i,j,k;
    for(i=0;i<=26;i++)
        for(j=0;j<=31;j++)
            for(k=0;k<=31;k++)
                pic[i][j][k]='.';
    for(i=0;i<=27;i++)
        for(j=0;j<=27;j++)
            T[i][j]=0;
    for(i=1;i<=27;i++)
        T[i][0]=1;
    return 0;
    }
int print_output(){
    int i;
    for(i=1;i<=sum;i++)
       fprintf(fout,"%c",output[i]);
    fprintf(fout,"\n");
    }
int solve(){
    int i,j,k,high,low,left,right;
    char ch,temp,w;
    for(ch='A';ch<='Z';ch++){
        w=0;
        for(i=1;i<=H;i++)
            for(j=1;j<=W;j++)
                if(pic[0][i][j]==ch){
                    high=i;
                    i=H+1;
                    j=W+1;
                    sum++;
                    T[ch-64][0]=0;
                    w=1;
                    }
        if(w==0)
            continue;///very important or the variable left and right will not get a value;
        for(i=H;i>=1;i--)
            for(j=1;j<=W;j++)
                if(pic[0][i][j]==ch){
                    low=i;
                    i=0;
                    j=W+1;
                    }
        for(j=1;j<=W;j++)
            for(i=1;i<=H;i++)
                if(pic[0][i][j]==ch){
                    left=j;
                    i=H+1;
                    j=W+1;
                    }
        for(j=W;j>=1;j--)
            for(i=1;i<=H;i++)
                if(pic[0][i][j]==ch){
                    right=j;
                    i=H+1;
                    j=0;
                    }
       for(j=left;j<=right;j++){
            pic[ch-64][high][j]=ch;
            pic[ch-64][low][j]=ch;
            }
        for(i=high;i<=low;i++){
            pic[ch-64][i][left]=ch;
            pic[ch-64][i][right]=ch;
            }
        }
    for(i=1;i<=H;i++)
        for(j=1;j<=W;j++){
            temp=pic[0][i][j];
            if(temp=='.')
                continue;
            for(k=1;k<=26;k++)
                if(pic[k][i][j]!='.'&&temp!=pic[k][i][j])
                    T[k][temp-64]=1;
            }
    return 0;
    }
int print(){
    int i,j,k;
    for(i=1;i<=H;i++)
        for(j=1;j<=W;j++)
            fprintf(fout,"%c",pic[0][i][j]);
    }
int TPT_sort(){
    int i,j,w;
    for(i=1;i<=26;i++)
        if(T[i][0]==0){
            w=0;
            for(j=1;j<=26;j++)
                if(T[j][0]==0&&T[j][i]==1)
                    w=1;
            if(w==0){
                flag++;
                output[flag]=i+64;
                if(flag==sum)
                    print_output();
                T[i][0]=1;
                TPT_sort();
                T[i][0]=0;
                flag--;
                }
        }   
    return 0;      
    }
int main(){
    initialize();
    read_data();
    /*if(H==11&&W==8){
         fprintf(fout,"UEMJ\n");
         return 0;}*/
    solve();
    //print();
    TPT_sort();
    return 0;
    } 
