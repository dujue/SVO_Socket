
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
        //	servaddr.sin_addr.s_addr = inet_addr("192.168.1.60");  
        servaddr.sin_port = htons(5000);  
      
        bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));  
      
        int n = 100;  
        char recvline[1024];  
        int count ,x,y,z,nCount=0;

        while (1){  

            /**/ 

            recvfrom(sockfd, recvline, 1024, 0, NULL, NULL);  
            for (count = 0; count < strlen(recvline); ++count)
            {
                if (count==0  )
                {
                    x=recvline[0];
                }else if (count==1)
                {
                    y=recvline[1];
                }else if (count==2)
                {
                    z=recvline[2];
                }else
                {
                    printf("接收错误，返回\n");
                    return 0;
                }
                printf("server.c-接收到坐标(%d)，x=%c ,y=%c ,z=%c \n",nCount++, x,y,z);
            }

            n--;  
        }  
      
        close(sockfd);  
    }  
