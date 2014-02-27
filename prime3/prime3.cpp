
/*
ID: yang.su1
PROG:prime3
LANG: C++
*/
#include<stdio.h>
FILE *fin,*fout;
int sum;
int corner;
bool proper_hash[100000]={0};
bool hash[11][11][11][11][11]={0};
int read_data(){
    fin=fopen("prime3.in","r");
    fout=fopen("prime3.out","w");
    fscanf(fin,"%d%d",&sum,&corner);
    }
int initialize_hash(){
    int i;
    for(i=1;i<=99999;i++)
        proper_hash[i]=1;
    }
int eliminate_composite_namber(){
    int i,j,k;
    for(i=2;i<=99999;i++)
        if(proper_hash[i]==1)
           for(j=i+i;j<=99999;j=j+i)
               proper_hash[j]=0;    
    }
int get_sum(int n){
    int i;
    int s=0;
    for(i=10000;i>=1;i=i/10){
        s+=n/i;
        n=n%i;
        }
    return s;
    }
int eliminate_unsum(){
    int i;
    for(i=10000;i<=99999;i++)
        if(proper_hash[i]==1&&get_sum(i)!=sum)
            proper_hash[i]=0;
    }
/*int get_proper_subhash(){
    int i,j;
    for(i=0;i<=9999;i++)
        proper_hash[i]=0;
    for(i=10000;i<=99999;i++)
        if(proper_hash[i]==1){
            for(j=10000;j>=10;j=j/10)
                proper_hash[i/j]=1;
            }
    }*/
int get_number(int begin,int x,int a[6]){
    int i,j,k,temp;
    k=100000;
    temp=x;
    for(i=1;i<=begin;i++)
        k=k/10;
    temp=temp/k-((temp/k)/10)*10;
    a[begin]=temp;
    if(begin==5)
        hash[a[1]][a[2]][a[3]][a[4]][a[5]]=1;
    else
        get_number(begin+1,x,a);
    a[begin]=10;
    if(begin==5)
         hash[a[1]][a[2]][a[3]][a[4]][a[5]]=1;
    else
        get_number(begin+1,x,a);
    }
int get_hash(){
    int i,j,k;
    int a[6];
    for(i=10000;i<=99999;i++)
        if(proper_hash[i]==1)
            get_number(1,i,a);
    }
int pre(){
    initialize_hash();
    eliminate_composite_namber();
    eliminate_unsum();
    //get_proper_subhash();
    get_hash();
    }

//////////////////////////////////////////////////////
int table[6][6];
//int now[6][6][3];
int order[26][2];
int F=0;
int initialize_table(){
    int i,j,k;
    for(i=1;i<=5;i++)
        for(j=1;j<=5;j++)
            table[i][j]=10;
    table[1][1]=corner;
    /*for(i=0;i<=5;i++)
        for(j=0;j<=5;j++){
            now[i][j][1]=0;
            now[i][j][0]=0;
            now[i][j][2]=0;
            }
    now[1][1][1]=corner;
    now[1][1][0]=corner;
    now[1][1][2]=corner;*/
    order[1][0]=1;order[1][1]=1;order[2][0]=2;order[2][1]=2;order[3][0]=3;order[3][1]=3;order[4][0]=4;order[4][1]=4;order[5][0]=5;order[5][1]=5;
    order[6][0]=5;order[6][1]=1;order[7][0]=4;order[7][1]=2;order[8][0]=2;order[8][1]=4;order[9][0]=1;order[9][1]=5;order[10][0]=3;order[10][1]=1;
    order[11][0]=3;order[11][1]=2;order[12][0]=3;order[12][1]=4;order[13][0]=3;order[13][1]=5;order[14][0]=1;order[14][1]=3;order[15][0]=2;order[15][1]=3;
    order[16][0]=4;order[16][1]=3;order[17][0]=5;order[17][1]=3;order[18][0]=1;order[18][1]=2;order[19][0]=1;order[19][1]=4;order[20][0]=2;order[20][1]=1;
    order[21][0]=2;order[21][1]=5;order[22][0]=4;order[22][1]=1;order[23][0]=4;order[23][1]=5;order[24][0]=5;order[24][1]=2;order[25][0]=5;order[25][1]=4;
    }
struct unit{
      int  a[6][6];
       };
unit save[1000];
int num=0;
int save_table(){
    int i,j;
    num++;
    for(i=1;i<=5;i++)
        for(j=1;j<=5;j++)
            save[num].a[i][j]=table[i][j];
    }
int print_table(){
    unit x;
    int i,j,k,w,t,flag,first=1;
    for(k=1;k<=num;k++){
        for(i=1;i<=5;i++)
            for(j=1;j<=5;j++)
                x.a[i][j]=9;
        for(w=k;w<=num;w++){//because of print  use selection sort 
            flag=0;
            for(i=1;i<=5&&flag==0;i++)
                for(j=1;j<=5&&flag==0;j++){
                    if(x.a[i][j]>save[w].a[i][j]){
                        x=save[w];
                        t=w;
                        flag=1;
                        }
                    if(x.a[i][j]<save[w].a[i][j])
                        flag=1;
                    }           
            }
        save[t]=save[k];
        if(first==0)
            fprintf(fout,"\n");
        first=0;
        for(i=1;i<=5;i++){
            for(j=1;j<=5;j++)
                fprintf(fout,"%d",x.a[i][j]);
            fprintf(fout,"\n");
            }
        
        }
    }
int judge_table(int a,int b){
    int i,j,w,temp;
    if(hash[table[a][1]][table[a][2]][table[a][3]][table[a][4]][table[a][5]]!=1)
        return 0;
    if(hash[table[1][b]][table[2][b]][table[3][b]][table[4][b]][table[5][b]]!=1)
        return 0;
    if(a==b&&hash[table[1][1]][table[2][2]][table[3][3]][table[4][4]][table[5][5]]!=1)
        return 0;
    if(a+b==6&&hash[table[5][1]][table[4][2]][table[3][3]][table[2][4]][table[1][5]]!=1)
        return 0;
    return 1;
    /*if(a==b){
        w=6;
        temp=0;
        for(i=1;i<=5;i++)
            if(table[i][i]==-1){
                w=i;
                break;
                }
        if(w>a){
        for(i=1;i<=w-1;i++)
            temp=temp*10+table[i][i];
        if(proper_hash[temp]!=1)
            return 0;
            }
        }
    if(a+b==6){
        w=0;
        temp=0;
        for(i=5;i>=1;i--)
            if(table[i][6-i]==-1){
                w=i;
                break;
                }
        if(w<a){
        for(i=5;i>=w+1;i--)
            temp=temp*10+table[i][6-i];
        if(proper_hash[temp]!=1)
            return 0;
            }
        }
    w=6;
    temp=0;
    for(i=1;i<=5;i++)
        if(table[i][b]==-1){
            w=i;
            break;
            }
    if(w>a){
    for(i=1;i<=w-1;i++)
        temp=temp*10+table[i][b];
    if(proper_hash[temp]!=1)
        return 0;
        }
    w=6;
    temp=0;
    for(j=1;j<=5;j++)
        if(table[a][j]==-1){
            w=j;
            break;
            }
    if(w>b){
    for(j=1;j<=w-1;j++)
        temp=temp*10+table[a][j];
    if(proper_hash[temp]!=1)
        return 0;
        }
    return 1;
    
        
        /*temp=now[a-1][b][0]*10+table[a][b];
        if(proper_hash[temp]!=1)
            return 0;
        now[a][b][0]=temp;
        temp=now[a][b-1][1]*10+table[a][b];
        if(proper_hash[temp]!=1)
            return 0;
        now[a][b][1]=temp;
   if(a==b){
        temp=now[a-1][b-1][2]*10+table[a][b];
        if(proper_hash[temp]!=1)
            return 0;
        now[a][b][2]=temp;
        }
   temp=0;
   if(a+b==6){
       if(table[5][1]==-1)
           return 1;
       for(i=5;i>=1;i--){
            if(table[i][6-i]!=-1)
                temp=temp*10+table[i][6-i];
            else
                break;
        }
        if(proper_hash[temp]!=1)
            return 0;
        }
   return 1;*/
    }
int creat_table(int n){
    int i,j,k,w;
    i=order[n][0];
    j=order[n][1];
    if(n==1)
        if(judge_table(i,j)==0){
            return 0;
            }
        else
            creat_table(2);
    else{
    for(k=0;k<=9;k++){
        if(j==1&&k==0)
            continue;
        table[i][j]=k;
        if(judge_table(i,j)==0)
            continue;
        if(n!=25)
            creat_table(n+1);
        else
            save_table();
        } 
    table[order[n][0]][order[n][1]]=10;//important
    return 0;  //dont forget
        }
    }
int get_table(){
    initialize_table();
    creat_table(1);
    }

int main(){
    read_data();
    pre();
    get_table();
    print_table();
    if(num==0)
        fprintf(fout,"NONE\n");
    return 0;
    }
