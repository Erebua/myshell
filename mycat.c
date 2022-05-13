#include"shell.h"

void mycat(char *cat_buf,char *write_buf,char *argv[]){


    if(argv[1] != NULL){
        int fd = open(argv[1],O_RDWR);
        //printf("%d\n", fd);
        if(fd == -1){
            printf("文件打开失败！\n");
        }else{
        	struct stat st;
  			fstat(fd, &st);
  			//printf("size: %ld\n",st.st_size);

  			read(fd,cat_buf,st.st_size);
  			write(1,cat_buf,st.st_size);
  			printf("\n");
        }


    }else{
        printf("参数不正确！\n");
    }
}