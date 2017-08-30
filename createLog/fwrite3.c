#include <stdio.h>  
#include <unistd.h>  
#include <fcntl.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
//#include <stdio.h>  
#include <string.h> 
   
const char *pathName = "/Users/maocong90/Desktop/mysocket/createLog/logs.txt";   
  
int main(void)   
{   
    int in, out, flag;   
    char buffer[1024];  
      
    in = open(pathName, O_CREAT);
    in = open(pathName, O_RDWR);
    if (-1 == in) // 打开文件失败,则异常返回  
    {      
        return -1;   
    }     
  printf("end and in =%d \n",in);
  sprintf(buffer,"sdfa s fsf");
    // out = open(pathName, O_WRONLY|O_CREAT);  
    // if (-1 == out) // 创建文件失败,则异常返回  
    // {     
    //     return -1;   
    // }    
        printf(" buffer =%s \n",buffer);      
        write(in, buffer, strlen(buffer));
       // fsync(in);  
       

    close(in);  
    close(out);  
      
    return 0;  
}  