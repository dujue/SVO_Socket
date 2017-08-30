#include <sys/stat.h>
#include <stdio.h>
// #include <time.h>
// #include <sys/types.h>

int main()
{
    // char txtname[10];
    // *txtname="005";//这句将结果转变为字符串
 
    if(access("flow123",0)==-1)//access函数是查看文件是不是存在
    {
        if (mkdir("flow123",0777))//如果不存在就用mkdir函数来创建
        {
            printf("creat file bag failed!!!");
        }
    }

    // char pathname[100];
    // pathname[0]='f';
    // pathname[1]='l';
    // pathname[2]='o';
    // pathname[3]='w';
    // pathname[4]='/';
    // pathname[5]='/';
    
    // int i;
    // for(i=0;txtname[i]!='\0';i++)
    // {
    //     int j=6+i;
    //     pathname[j]=txtname[i];
    // }
    // pathname[i+6]='.'; //这几句是加上后缀 .txt的

    // pathname[i+8]='t';
    // pathname[i+9]='x';
    // pathname[i+10]='t';
    // pathname[i+11]='\0';//最后别忘记加上这个
    
    // FILE  *fp;
    // if((fp=fopen(pathname,"w"))==NULL)//打开文件 没有就创建
    // {
    //     printf("文件还未创建!\n");
    // }

    // fprintf(fp,"创建成功");
    // fclose(fp);
    return 0;
}
