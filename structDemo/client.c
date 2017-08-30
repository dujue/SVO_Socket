    #include <stdio.h>  
    #include <string.h>  
    #include <sys/socket.h>  
    #include <netinet/in.h>  
#include <arpa/inet.h> //solve gcc inet_addr was not declared in this scope   
      
    int main()  
    {  
        int sockfd;  
        struct sockaddr_in servaddr;   //结构体：http://blog.csdn.net/huqinwei987/article/details/23625823
      
        sockfd = socket(PF_INET, SOCK_DGRAM, 0);  
      
        bzero(&servaddr, sizeof(servaddr));  
        servaddr.sin_family = AF_INET;  
        servaddr.sin_port = htons(5000);  
        servaddr.sin_addr.s_addr = inet_addr("192.168.0.238");  
              
        ssize_t size;
        struct position_packet {
            uint64_t timestamp;     
            uint8_t targets_tag;    //0 for out range ;1for effective
            float size_width;
            float size_height;
            float pos_x;
            float pos_y;
            float pos_z;
        } test_pkt;
        //for test udp send
        test_pkt.timestamp = 5557;
        test_pkt.targets_tag = 1;
        test_pkt.pos_x = 220.0f;
        test_pkt.pos_y = 0.0f;
        test_pkt.pos_z = 20.0f;
        test_pkt.size_width = 1.0f;
        test_pkt.size_height = 1.0f;

        printf("sizeof test_pkt:%lu\n",sizeof(test_pkt));
        int i,number;
        for ( i = 0; i < 300; ++i)
        {
            //产生随机数
            test_pkt.pos_x = 1;
            test_pkt.pos_y = 2;
            test_pkt.pos_z = 3;         
            //printf("随机数number=%f  \n", number);
              sendto(sockfd, (char*)&test_pkt, sizeof(test_pkt), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));   
        }     
        close(sockfd);   
        return 1;        
    }  
