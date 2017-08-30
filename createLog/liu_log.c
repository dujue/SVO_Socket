#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  

  
  
// int main(int argc, char *argv[])  
// {  
//     FILE *filp = NULL;  
//     char fileDir[] = "/Users/maocong90/Desktop/mysocket/createLog/log.txt";   
//     char dataPtr[] = "Helloworld";  
//     printf("sizeof(dataPtr) = %ld\n",sizeof(dataPtr));  
//     filp = fopen(fileDir,"w+");  /* 可读可写，不存在则创建 */  
//     int writeCnt = fwrite(dataPtr,sizeof(dataPtr),1,filp);  /* 返回值为1 */  
//     //int writeCnt = fwrite(dataPtr,1,sizeof(dataPtr),filp);  /* 返回值为11 */  
//     printf("writeCnt = %d\n",writeCnt);  
//     fclose(filp);  
  
//     FILE *fp = NULL;  
//     fp = fopen(fileDir,"r");  
//     char buffer[256];  
//     int readCnt = fread(buffer,sizeof(buffer),1,fp);  /* 返回值为0 */  
//     //int readCnt = fread(buffer,1,sizeof(buffer),fp);  /* 返回值为11 */      
//     printf("readCnt = %d\n",readCnt);  
//     fclose(fp);  
      
//     printf("%s\n",buffer);  
//     exit(0);  
// } 
/*
if(_log_fd != -1) {
            char data_to_write[256]={0};
            sprintf(data_to_write,"%ld:recv data:%llu,%u,%f,%f,%f\n",
                tEnd.tv_sec,
                test_pkt.timestamp,
                test_pkt.targets_tag,
                test_pkt.pos_x,
                test_pkt.pos_y,
                test_pkt.pos_z);
            write(_log_fd, data_to_write, strlen(data_to_write));
            fsync(_log_fd);
        }
*/



#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
int main()  
{  
    FILE *fp = NULL;  
    //int write_length = 0;  
    fp = open("/Users/maocong90/Desktop/mysocket/createLog/log.txt", "w+");  
    if(fp == NULL)  
    {  
        return 0;  
    }  
    struct svo_test
    {
        int timestamp;
        int pos_x;   
    }test_pkt;
    test_pkt.timestamp = 100;
    test_pkt.pos_x = 10;

    //if(_log_fd != -1) {}
        char data_to_write[256]={0};
        sprintf(data_to_write,":recv data:%d,%d\n",test_pkt.timestamp,test_pkt.pos_x);
            
        write(fp, data_to_write, strlen(data_to_write));
        fsync(fp);
        printf("%d %d data_to_write＝%s \n",test_pkt.timestamp, test_pkt.pos_x,data_to_write );

    //write_length = fwrite(BUF, 1, strlen(BUF), fp);  
    // write_length = fwrite(test_pkt, sizeof(test_pkt), 3, fp); 
    // printf("write_length = %d\n", write_length);  
     fclose(fp);  
    fp = NULL;  
    return 0;     
}  


// #include <stdio.h>  
// #include <stdlib.h>  
// #include <string.h>  
  
  
// int main(int argc, char *argv[])  
// {  
//     FILE *filp = NULL;  
//     char fileDir[] = "/Users/maocong90/Desktop/mysocket/createLog/test2.txt";   
//     char dataPtr[] = "Helloworld";  
//     //printf("sizeof(dataPtr) = %ld\n",sizeof(dataPtr));  
//     filp = fopen(fileDir,"w+");  /* 可读可写，不存在则创建 */  


//     //int writeCnt = fwrite(dataPtr,sizeof(dataPtr),1,filp);  /* 返回值为1 */  
//     //int writeCnt = fwrite(dataPtr,1,sizeof(dataPtr),filp);  /* 返回值为11 */  
//     //printf("writeCnt = %d\n",writeCnt);  

//         struct svo_test
//     {
//         int timestamp;
//         int pos_x;   
//     }test_pkt;
//     test_pkt.timestamp = 100;
//     test_pkt.pos_x = 10;


//     //if(_log_fd != -1) {}
//     //printf("fp=%d\n", fp);
//             char data_to_write[256]={0};
//             sprintf(dataPtr,":recv data:%d,%d\n",test_pkt.timestamp,test_pkt.pos_x);
//             //write(fp, data_to_write, strlen(data_to_write));
            
//             //fp = fopen(data_to_write,"wb+")
//             write(filp, dataPtr, strlen(dataPtr));

//     // if(writeCnt != -1) {
//     //         char data_to_write[256]={0};
//     //         sprintf(data_to_write,"%ld:recv data:%llu,%u,%f,%f,%f\n",
//     //             tEnd.tv_sec,
//     //             test_pkt.timestamp,
//     //             test_pkt.targets_tag,
//     //             test_pkt.pos_x,
//     //             test_pkt.pos_y,
//     //             test_pkt.pos_z);
//     //         write(_log_fd, data_to_write, strlen(data_to_write));
//     //         fsync(_log_fd);
//     //     }
//     fclose(filp);  
  
//     FILE *fp = NULL;  
//     fp = fopen(fileDir,"r");  
//     char buffer[256];  
//     int readCnt = fread(buffer,sizeof(buffer),1,fp);  /* 返回值为0 */  
//     //int readCnt = fread(buffer,1,sizeof(buffer),fp);  /* 返回值为11 */      
//     printf("readCnt = %d\n",readCnt);  
//     fclose(fp);  
      
//     printf("%s\n",buffer);  
//     exit(0);  
// }  




