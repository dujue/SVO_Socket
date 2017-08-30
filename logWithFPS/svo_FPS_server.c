
#include <stdio.h>  
#include <string.h>  
#include <sys/socket.h>  
#include <netinet/in.h> 
#include <time.h> //获取系统时间
#include <stdlib.h>

// #include <iostream>


#define FILENAME ("/Users/maocong90/Desktop/mysocket/logWithFPS/") 
// #define FILENAME ("/root/mao/mysocket/createLog2/") 
#define YEAR    st->tm_year+1900
#define MONTH   st->tm_mon+1
#define DAY     st->tm_mday
#define HOUR    st->tm_hour
#define MIN     st->tm_min
#define SECOND  st->tm_sec

int main()  
{  
    //sprintf(data_to_write,"recv data: x=%.2f, y=%.2f, z=%.2f count=%d\n",udp_pkt.pos_x[i],

    char date_filename[256]={0};
    //生成系统时间参数
    time_t t;  
    struct tm *st; 
    t=time(NULL);  
    st=localtime(&t); 
    //fprintf(fp,"%d %d-%d-%d %2d:%2d:%2d\n",index,st->tm_year+1900,st->tm_mon+1,st->tm_mday,st->tm_hour,st->tm_min,st->tm_sec);  
    sprintf(date_filename,"%s %d%d%d%2d%2d%2d.txt",FILENAME,YEAR,MONTH,DAY,HOUR,MIN,SECOND);

    //打开本地日志文件
    FILE *fp = NULL;  
    int write_length = 0;  
    fp = fopen(date_filename, "w+");  
    if(fp == NULL)  
    {  
        printf("未成功打开日志文件 \n");
        return 0;  
    }
    char data_to_write[256]={0};

    //svo_server
    int sockfd;  
    struct sockaddr_in servaddr;  
    
    sockfd = socket(PF_INET, SOCK_DGRAM, 0);  
    
    bzero(&servaddr, sizeof(servaddr));  
    servaddr.sin_family = AF_INET;  
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);  
    //servaddr.sin_addr.s_addr = inet_addr("192.168.4.102"); 
    servaddr.sin_addr.s_addr = inet_addr("192.168.1.227");  
    //servaddr.sin_addr.s_addr = inet_addr("192.168.1.238");
    servaddr.sin_port = htons(5000);  
    
    bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));  

    struct position_packet {
          
          double  fps_num; 
          long  track_num;
          int     drop_num;
        }udp_pkt;
        udp_pkt.fps_num = 0;
        udp_pkt.track_num = 0;
        udp_pkt.drop_num = 0;

    while(1)
    {
        //int recvfrom（int sockfd，void *buf，int len，unsigned int lags，struct sockaddr *from，int *fromlen）； 
        recvfrom(sockfd, (char*)&udp_pkt, sizeof(udp_pkt), 0, NULL, NULL); 
        //printf("test sizeof(udp_pkt)=%lu strlen＝%lu \n",sizeof(udp_pkt),sizeof(sockfd));  

        sprintf(data_to_write,"svo_fps_server:fps_ =%.2f, tracking=%ld, drop_=%d \n",
                    udp_pkt.fps_num,
                    udp_pkt.track_num,
                    udp_pkt.drop_num);
        write_length = fwrite(data_to_write, 1, strlen(data_to_write), fp);
    
         
        //printf("size = %lu \n", sizeof(data_to_write));  
        //printf("write_length = %d\n", write_length); 
        fflush(fp);//fwrite()函数写到用户空间缓冲区，并未同步到文件中，所以修改后要将内存与文件同步可以用fflush（FILE *fp）函数同步。
        //linked:http://blog.csdn.net/yf210yf/article/details/9074357
        printf("接收数据并写入log文件 write_length=%d \n", write_length);
    } 
    fclose(fp); 
    fp = NULL;  
    close(sockfd);  
}  
