/*
ID: yang.su1
LANG:C++
TASK:hidden
*/
#include<stdio.h>
int L;
FILE *fin,*fout;
int s[200000];
int compare();
int main(){
    int i,j;
    fin=fopen("hidden.in","r");
    fout=fopen("hidden.out","w");
    fscanf(fin,"%d",&L);
    for(i=0;i<L;){
        char temp;
        while(1){
                temp=fgetc(fin);
            if(temp<='z'&&temp>='a'){
                s[i]=temp;
                s[i+L]=s[i];
                i++;
                break;
                }
            }
        }
    compare();
    }
int compare(){
    int i,j,k;
    i=0;j=1;
    for(k=0;k<L&&i<L&&j<L;){
        if(i==j){
            j++;
            continue;
            }
        if(s[i+k]==s[j+k]){
            if(k==L-1){
                       break;//?
                k=0;
                if(i>j)
                    i++;
                else
                   j++;  
                continue;
                }
            k++;

            }
        if(s[i+k]>s[j+k]){
            i=i+k+1;
            k=0;
            continue;
            }
        if(s[i+k]<s[j+k]){
            j=j+k+1;
            k=0;
            continue;
            }
        
        }
    fprintf(fout,"%d\n",i>j?j:i);
    }
