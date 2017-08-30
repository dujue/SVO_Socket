#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
//#include <windows.h>  


//linked:http://blog.csdn.net/u013571487/article/details/37073357
int main()  
{  
FILE *fp ;  
time_t t;  
struct tm *st;  
char buffer[1024];  
int index=0;  
    fp=fopen("log22.txt","r");  
if (fp!=NULL)  
{  
   while(!feof(fp))  
    fgets(buffer,1024,fp);  
   sscanf(buffer,"%d",&index);  
   index++;  
   fclose(fp);  
}  
    fp=fopen("log22.txt","a");  
while(1)  
{  
   t=time(NULL);  
   st=localtime(&t); 
   printf("打印 t = %ld  ,st ＝ %ld  \n", t ,st); 
   fprintf(fp,"%d %d-%d-%d %2d:%2d:%2d\n",index,st->tm_year+1900,st->tm_mon+1,st->tm_mday,st->tm_hour,st->tm_min,st->tm_sec);  
   
// 12 2017-6-22 13:44:20
// 13 2017-6-22 13:44:20
// 14 2017-6-22 13:44:20
   index++;  
   fflush(NULL);  
   //Sleep(1000);  
}  
return 0;  
} 