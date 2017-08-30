
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
        servaddr.sin_addr.s_addr = inet_addr("192.168.1.238");  
        servaddr.sin_port = htons(5000);  
      
        bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));  

        // struct position_packet {
        //     float pos_x;
        //     float pos_y;
        //     float pos_z;
        // }pwm_pkt[3];
        struct position_packet {
            float pos_x[1000];
            float pos_y[1000];
            float pos_z[1000];
        }pwm_pkt;

        // pwm_pkt.pos_x = 0.0f;
        // pwm_pkt.pos_y = 0.0f;
        // pwm_pkt.pos_z = 0.0f;

        //size = _sock.recv(&pwm_pkt, sizeof(pwm_pkt), 0);
    
        ssize_t size = 0;
        ssize_t total_size = 32;
        ssize_t need_size = total_size;
        
        while(1)
        {
            recvfrom(sockfd, (char*)&pwm_pkt, 1024, 0, NULL, NULL);  
            //printf("svo:received need_size: %zd \n", need_size);
            //size = read(nFd , (char*)&pwm_pkt + (total_size - need_size), need_size );
            //printf("svo:received data: %zd \n", size);
            //need_size = need_size - size;
            //printf("svo:received need_size: %zd \n", need_size);
            // printf("udp port recv data:%llu,%u,%f,%f,%f,%f,%f\n",
            //     pwm_pkt.timestamp,
            //     pwm_pkt.targets_tag,
            //     pwm_pkt.size_width,
            //     pwm_pkt.size_height,
            //     pwm_pkt.pos_x,
            //     pwm_pkt.pos_y,
            //     pwm_pkt.pos_z
            //     );
            for (int i = 0; i < 100; ++i)
            {
                // printf("udp port recv data:x=%f,y=%f,z=%f \n",
                //     pwm_pkt.pos_x[i],
                //     pwm_pkt.pos_y[i],
                //     pwm_pkt.pos_z[i]
                //     );
         printf("udp prot recv x=%.2f y=%.2f,z=%.2f \n",pwm_pkt.pos_x[i],pwm_pkt.pos_y[i],pwm_pkt.pos_z[i]);

            }

        }   
        close(sockfd);  
}  





/*
// struct 内存放单个元素

int main()  
    {  
        int sockfd;  
        struct sockaddr_in servaddr;  
      
        sockfd = socket(PF_INET, SOCK_DGRAM, 0);  
      
        bzero(&servaddr, sizeof(servaddr));  
        servaddr.sin_family = AF_INET;  
        servaddr.sin_addr.s_addr = htonl(INADDR_ANY);  
        servaddr.sin_addr.s_addr = inet_addr("192.168.1.238");  
        servaddr.sin_port = htons(5000);  
      
        bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));  

        struct position_packet {
            uint64_t timestamp;
            uint8_t targets_tag; //0 for out range ;1for effective
            float size_width;
            float size_height;
            float pos_x;
            float pos_y;
            float pos_z;
            int compass_plane;
        }pwm_pkt;
 
        pwm_pkt.timestamp = 0;
        pwm_pkt.targets_tag = 0;
        pwm_pkt.pos_x = 0.0f;
        pwm_pkt.pos_y = 0.0f;
        pwm_pkt.pos_z = 0.0f;
        pwm_pkt.size_width = 0.0f;
        pwm_pkt.size_height = 0.0f;
        //size = _sock.recv(&pwm_pkt, sizeof(pwm_pkt), 0);
    
        ssize_t size = 0;
        ssize_t total_size = 32;
        ssize_t need_size = total_size;
        
        while(1)
        {
            recvfrom(sockfd, (char*)&pwm_pkt, 1024, 0, NULL, NULL);  
            printf("svo:received need_size: %zd \n", need_size);
            //size = read(nFd , (char*)&pwm_pkt + (total_size - need_size), need_size );
            printf("svo:received data: %zd \n", size);
            need_size = need_size - size;
            printf("svo:received need_size: %zd \n", need_size);
            // printf("udp port recv data:%llu,%u,%f,%f,%f,%f,%f\n",
            //     pwm_pkt.timestamp,
            //     pwm_pkt.targets_tag,
            //     pwm_pkt.size_width,
            //     pwm_pkt.size_height,
            //     pwm_pkt.pos_x,
            //     pwm_pkt.pos_y,
            //     pwm_pkt.pos_z
            //     );
             printf("udp port recv data:x=%f,y=%f,z=%f,int compass_plane=%d \n",
                pwm_pkt.pos_x,
                pwm_pkt.pos_y,
                pwm_pkt.pos_z,
                pwm_pkt.compass_plane
                );    
            
        }   
        close(sockfd);  
    }  


*/