#include <stdio.h>  
#include <string.h>  
  
#define FILENAME ("/Users/maocong90/Desktop/mysocket/createLog2/log.txt")  
//#define BUF ("Hello world!\n")  
  
int main()  
{  
    FILE *fp = NULL;  
    int write_length = 0;  
    fp = fopen(FILENAME, "w+");  
    if(fp == NULL)  
    {  
        printf("未成功打开日志文件 \n");
        return 0;  
    }  
    struct svo_test
    {
        int timestamp;
        int pos_x;   
    }test_pkt;

    test_pkt.timestamp = 100;
    test_pkt.pos_x = 10;

    char data_to_write[256]={0};
    sprintf(data_to_write,":recv data:%d,%d\n",test_pkt.timestamp,test_pkt.pos_x);

    printf("size = %lu \n", sizeof(data_to_write));  
    write_length = fwrite(data_to_write, 1, strlen(data_to_write), fp);
    //write_length = fwrite(data_to_write, sizeof(data_to_write), 1, fp); //二进制文件 
    printf("write_length = %d\n", write_length);  
    fclose(fp);  
    fp = NULL;  
    return 0;     
}  
/*
在文件操作时，需要注意以下几点问题
1、在定义文件指针时，要将文件指针指向空；如 FILE *fp = NULL;
2、文件操作完成后，需要将文件关闭，一定要注意，否则会造成文件所占用内存泄露和在下次访问文件时出现问题。
3、文件关闭后，需要将文件指针指向空，这样做会防止出现游离指针，而对整个工程造成不必要的麻烦；如：fp = NULL;
*/