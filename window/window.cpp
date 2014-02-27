
/*
ID: yang.su1
PROG:window
LANG: C++
*/
#include<stdio.h>
#include<stdlib.h>
FILE *fin,*fout; 

struct window{
       int x1,y1,x2,y2;
       bool valid;
       int rank;
       };
window base[63];
int convert(char x){
    if(x<='z'&&x>='a')
        return x-'a'+1;
    if(x<='9'&&x>='0')
        return x-'0'+27;
    if(x<='Z'&&x>='A')
        return  x-'A'+37;
    }
double get_per(window x){ //recursion is very important  though
       int i,j; 
       window temp1=x,temp2=x;
       for(i=1;i<=62;i++)
           if(base[i].valid==1&&base[i].rank>x.rank&&!(x.x1>=base[i].x2||x.x2<=base[i].x1||x.y1>=base[i].y2||x.y2<=base[i].y1)){
               if(base[i].y2<x.y2){
                   temp1.y1=base[i].y2;
                   temp2.y2=base[i].y2;
                   return get_per(temp1)+get_per(temp2);
                   }
               if(base[i].y1>x.y1){
                   temp1.y1=base[i].y1;
                   temp2.y2=base[i].y1;
                   return get_per(temp1)+get_per(temp2);
                   }
               if(base[i].x1>x.x1){
                   temp1.x2=base[i].x1;
                   temp2.x1=base[i].x1;
                   return get_per(temp1)+get_per(temp2);
                   }
               if(base[i].x2<x.x2){
                   temp1.x2=base[i].x2;
                   temp2.x1=base[i].x2;
                   return get_per(temp1)+get_per(temp2);
                   }
               return 0;
               }
       return (x.x2-x.x1)*(x.y2-x.y1);
       }

int main(){
     fin=fopen("window.in","r");
     fout=fopen("window.out","w");
     int i,j,k,x1,y1,x2,y2,num;
     char x;
     int top=0,buttom=0;
     for(i=1;i<=62;i++)
         base[i].valid=0;
     while(1){
         x=fgetc(fin);
         fgetc(fin);
         num=convert(fgetc(fin));
         switch(x){
             case 'w':
                  fgetc(fin);
                  fscanf(fin,"%d",&x1);
                  fgetc(fin);
                  fscanf(fin,"%d",&y1);
                  fgetc(fin);
                  fscanf(fin,"%d",&x2);
                  fgetc(fin);
                  fscanf(fin,"%d",&y2);
                  base[num].x1=(x1<x2?x1:x2);
                  base[num].x2=(x1>x2?x1:x2);
                  base[num].y1=(y1<y2?y1:y2);
                  base[num].y2=(y1>y2?y1:y2);
                  base[num].valid=1;
                  base[num].rank=++top;
                  break;
             case 't':
                  base[num].rank=++top;
                  break;
             case 'b':
                  base[num].rank=--buttom;
                  break;
             case 'd':
                  base[num].valid=0;
                  break;
             case 's':
                  //fprintf(fout,"%d",base[num].rank);
                  fprintf(fout,"%.3f\n",get_per(base[num])*100/((base[num].x2-base[num].x1)*(base[num].y2-base[num].y1)));
                  break;
             default:
                     break;
             }
         fgetc(fin);
         if(fgetc(fin)==EOF)
             break;
         }
     return 0;
    }
