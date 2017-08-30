#include <stdio.h>  
#include <unistd.h>  
#include <fcntl.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
   
const char *pathName = "/root/log11.txt";   
  
int main(void)   
{   
    int in, out, flag;   
    char buffer[1024];  
      
    in = open("in.txt", O_RDONLY,S_IRUSR);  
    if (-1 == in) // 打开文件失败,则异常返回  
    {      
        return -1;   
    }     
  
    out = open(pathName, O_WRONLY|O_CREAT);  
    if (-1 == out) // 创建文件失败,则异常返回  
    {     
        return -1;   
    }     
      
    while ((flag = read(in, buffer, 1024)) > 0)  
    {  }   
        write(out, buffer, flag);  
         
    close(in);  
    close(out);  
      
    return 0;  
}  