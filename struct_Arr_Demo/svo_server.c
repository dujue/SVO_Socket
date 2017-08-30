
#include <stdio.h>  
#include <string.h>  
#include <sys/socket.h>  
#include <netinet/in.h> 
#include <time.h> //获取系统时间
#include <stdlib.h>

// #include <iostream>


#define FILENAME ("/Users/maocong90/Desktop/mysocket/struct_Arr_Demo/") 
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
    sprintf(date_filename,"%s %d-%d-%d %2d:%2d:%2d.txt",FILENAME,YEAR,MONTH,DAY,HOUR,MIN,SECOND);

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
    servaddr.sin_addr.s_addr = inet_addr("192.168.1.238");  
    //servaddr.sin_addr.s_addr = inet_addr("192.168.1.238");
    servaddr.sin_port = htons(5000);  
    
    bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));  

    struct position_packet {
        //注意server定义的结构体（声明数组大小）应该和client相同
        int   id_f;       //frame id
        float pos_r[200];//特征点距离相机的模
        float pos_x[200];
        float pos_y[200];
        float pos_z[200];
        int   count_pre;  //特征点过滤前
        int   count_after;//特征点过滤后
        int   compass_plane[200];//坐标点在平面上的象限
        int   arr_count; //确认client发送单个struct时，包含的坐标数
    }udp_pkt;
        udp_pkt.count_pre = 0;
        udp_pkt.count_after = 0;
        // udp_pkt.compass_plane[200]={0};
        // udp_pkt.arr_count = 0;
        // udp_pkt.pos_x[200]={0};
        // udp_pkt.pos_y[200]={0};
        // udp_pkt.pos_z[200]={0};
        // udp_pkt.pos_r[200]={0};
        // udp_pkt.id_f = 0;

    while(1)
    {
        //int recvfrom（int sockfd，void *buf，int len，unsigned int lags，struct sockaddr *from，int *fromlen）； 
        recvfrom(sockfd, (char*)&udp_pkt, sizeof(udp_pkt), 0, NULL, NULL); 
        //printf("test sizeof(udp_pkt)=%lu strlen＝%lu \n",sizeof(udp_pkt),sizeof(sockfd));  
        if (udp_pkt.arr_count==0)
        {
            // printf("arr_count=%d-----pre=%d data_to_write=%s\n",udp_pkt.arr_count,udp_pkt.count_pre,data_to_write);
            sprintf(data_to_write,"svo_server:id_f=%d, pre=%d \n",udp_pkt.id_f,udp_pkt.count_pre);
            write_length = fwrite(data_to_write, 1, strlen(data_to_write), fp);
        }
        else
        {
            int i=0;
            for (i = 0; i < udp_pkt.arr_count; ++i)//注意这里的包数(50)因该和client发送的相同，并且随着变化而变化。
            {
                //printf("i=%d \n", i);
                // printf("arr_count=%d-----pre=%d data_to_write=%s\n",udp_pkt.arr_count,udp_pkt.count_pre,data_to_write);

                // sprintf(data_to_write,"svo_server: x=%.2f, y=%.2f, z=%.2f count=%d compass=%d pre=%d after=%d\n",udp_pkt.pos_x[i],
                //     udp_pkt.pos_y[i],
                //     udp_pkt.pos_z[i],
                //     udp_pkt.arr_count,
                //     udp_pkt.compass_plane[i],
                //     udp_pkt.count_pre,
                //     udp_pkt.count_after);

                sprintf(data_to_write,"svo_server:id_f=%d, x=%.2f, y=%.2f, z=%.2f,r=%.2f, count=%d, compass=%d, pre=%d, after=%d\n",
                    udp_pkt.id_f,
                    udp_pkt.pos_x[i],
                    udp_pkt.pos_y[i],
                    udp_pkt.pos_z[i],
                    udp_pkt.pos_r[i],
                    udp_pkt.arr_count,
                    udp_pkt.compass_plane[i],
                    udp_pkt.count_pre,
                    udp_pkt.count_after);
                write_length = fwrite(data_to_write, 1, strlen(data_to_write), fp);
            }
        } 
        //printf("size = %lu \n", sizeof(data_to_write));  
        //printf("write_length = %d\n", write_length); 
        fflush(fp);//fwrite()函数写到用户空间缓冲区，并未同步到文件中，所以修改后要将内存与文件同步可以用fflush（FILE *fp）函数同步。
        //linked:http://blog.csdn.net/yf210yf/article/details/9074357
        printf("写入成功 write_length=%d \n", write_length);
    } 
    fclose(fp); 
    fp = NULL;  
    close(sockfd);  
}  
