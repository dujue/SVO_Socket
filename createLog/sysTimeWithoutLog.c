#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
//#include <windows.h>  


#define YEAR    st->tm_year+1900
#define MONTH   st->tm_mon+1
#define DAY     st->tm_mday
#define HOUR    st->tm_hour
#define MIN_TM     st->tm_min
#define SECOND  st->tm_sec


//linked:http://blog.csdn.net/u013571487/article/details/37073357
int main()  
{  
// FILE *fp ;  
time_t t;  
time_t beginTime;
struct tm *st;  
// char buffer[1024];  
int index=0;  
//     fp=fopen("log22.txt","r");  
// if (fp!=NULL)  
// {  
//    while(!feof(fp))  
//     fgets(buffer,1024,fp);  
//    sscanf(buffer,"%d",&index);  
//    index++;  
//    fclose(fp);  
// }  
    // fp=fopen("log22.txt","a");  
beginTime = time(NULL); 
while(1)  
{  
   t=time(NULL);  
   st=localtime(&t); 
   printf("打印 t = %ld  ,st ＝ %ld  ,time = %ld\n", t ,st,(t-beginTime)); 
   // sprintf(date_filename,"%s %d%d%d-%2d:%2d:%2d.txt",FILENAME,YEAR,MONTH,DAY,HOUR,MIN_TM,SECOND);

   // printf("%d%d%d%2d%2d%2d",YEAR,MONTH,DAY,HOUR,MIN_TM,SECOND);

// 12 2017-6-22 13:44:20
// 13 2017-6-22 13:44:20
// 14 2017-6-22 13:44:20
   index++;  
   // fflush(NULL);  
   sleep(1);  //mac 下是以秒为单位
}  
return 0;  
} 