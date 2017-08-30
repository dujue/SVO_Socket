    #include <stdio.h>  
    #include <string.h>  
    #include <sys/socket.h>  
    #include <netinet/in.h>  
    #include <string.h>

//产生随机数
#include <stdlib.h> 
#include <time.h>
    int main()  
    {  
        int sockfd;  
        struct sockaddr_in servaddr;   //结构体：http://blog.csdn.net/huqinwei987/article/details/23625823
      
        sockfd = socket(PF_INET, SOCK_DGRAM, 0);  
      
        bzero(&servaddr, sizeof(servaddr));  
        servaddr.sin_family = AF_INET;  
        servaddr.sin_port = htons(5000);  
        servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");  
              
        struct position_packet {
          float pos_x[10];
          float pos_y[10];
          float pos_z[10];
          int   arr_count;
        }test_pkt;
        //for test udp send
        printf("sizeof test_pkt:%lu\n",sizeof(test_pkt));
        int i,number,y;
        srand(time(NULL));

        for (y = 0; y < 3; ++y)
        {
            
            number = rand()%9+1;
            test_pkt.arr_count = number;

             
            printf("number = %d \n", number);
            for ( i = 0; i < number; ++i)
            {
                //产生随机数
                test_pkt.pos_x[i] = 1;
                test_pkt.pos_y[i] = 2;
                test_pkt.pos_z[i] = 3; 

                // printf("send x =%.2f,y=%.2f ,z=%.2f ,arr_count=%d\n", 
                //   test_pkt.pos_x[i],
                //   test_pkt.pos_y[i],
                //   test_pkt.pos_z[i],
                //   test_pkt.arr_count=number );      
            } 

            //sendto(sockfd, (char*)&test_pkt, sizeof(test_pkt), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));  
            int state_send = sendto(sockfd, (char*)&test_pkt, sizeof(test_pkt), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));  
            //printf("sizeof test_pkt2:%lu and state_send=%d \n",sizeof(servaddr),state_send);
        }

        
        printf("send end !\n");     
        close(sockfd);   
        return 1;        
    }  





