
    #include <stdio.h>  
    #include <string.h>  
    #include <sys/socket.h>  
    #include <netinet/in.h>  
      
    int main()  
    {  
        int sockfd;  
        struct sockaddr_in servaddr;  
      
        sockfd = socket(PF_INET, SOCK_DGRAM, 0);  
      
        bzero(&servaddr, sizeof(servaddr));  
        servaddr.sin_family = AF_INET;  
        servaddr.sin_addr.s_addr = htonl(INADDR_ANY);  
        servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");  
        //servaddr.sin_addr.s_addr = inet_addr("192.168.1.238");
        servaddr.sin_port = htons(5000);  
      
        bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));  

        struct position_packet {
            //注意server定义的结构体（声明数组大小）应该和client相同
            float pos_x[10];
            float pos_y[10];
            float pos_z[10];
            int   arr_count; //确认client发送单个struct时，包含的坐标数
        }pwm_pkt;

        while(1)
        {
            //int recvfrom（int sockfd，void *buf，int len，unsigned int lags，struct sockaddr *from，int *fromlen）； 
            recvfrom(sockfd, (char*)&pwm_pkt, sizeof(pwm_pkt), 0, NULL, NULL); 
            printf("test sizeof(pwm_pkt)=%lu strlen＝%lu \n",sizeof(pwm_pkt),sizeof(sockfd)); 
            
            int i=0;
            for (i = 0; i < pwm_pkt.arr_count; ++i)//注意这里的包数(50)因该和client发送的相同，并且随着变化而变化。
            {

                printf("i=%d \n", i);

                printf("udp prot recv x=%.2f y=%.2f,z=%.2f arr_count=%d\n",
                    pwm_pkt.pos_x[i],
                    pwm_pkt.pos_y[i],
                    pwm_pkt.pos_z[i],
                    pwm_pkt.arr_count );
            }


        }   
        close(sockfd);  
    }  
