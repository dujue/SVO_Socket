    #include <stdio.h>  
    #include <string.h>  
    #include <sys/socket.h>  
    #include <netinet/in.h>  
    #include <string.h>
 
 /*


 */     
    int main()  
    {  
        int sockfd;  
        struct sockaddr_in servaddr;   //结构体：http://blog.csdn.net/huqinwei987/article/details/23625823
      
        sockfd = socket(PF_INET, SOCK_DGRAM, 0);  
      
        bzero(&servaddr, sizeof(servaddr));  
        servaddr.sin_family = AF_INET;  
        servaddr.sin_port = htons(5000);  
        servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");  
      
        char sendline[30];
        //using std::string str = "1111";
        //c 拼接字符串 http://www.cnblogs.com/lvchaoshun/p/5936168.html
        //strcpy (sendline,"12356");
        //strcat (sendline,"12356");
        //strcat (sendline,"12356");

        /**/
        int i, y,nCount=0;
       
        for ( i = 0; i < 300; ++i)
        {
            sendline[0]='1';
            sendline[1]='2';
            sendline[2]='3'; 
            for ( y = 0; y < strlen(sendline); ++y)//c  数组长度：https://zhidao.baidu.com/question/187071815.html
            {
                printf("打输出的值%d ：%c   \n",y ,sendline[y] );               
            }
            printf("dayin---%d \n",nCount++);
            sendto(sockfd, sendline, strlen(sendline), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));  
        }    
        //strcpy(sendline,("123456"+"123456234"+"123456234"));
        //sprintf(sendline, "134AWweasd2983462813087");  
           
        close(sockfd);  
      
        return 1;  
      
    }  
