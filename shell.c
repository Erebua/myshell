#include "shell.h"

void Init(){
	argc = 0;
	memset(argv,0x00,sizeof(argv));

};

void cat_array(int argc,char **argv){
	printf("argc:%d",argc);
	printf(" %s\n",argv[argc+1]);
}


void parse(char* buf,char **argv){ //buf中存放输入的命令
	argc = 0;
  int i, flg = OUT; //0

  for(i = 0; buf[i] != '\0'; i++){
    // 进入单词
    if(flg == OUT && !isspace(buf[i])){ //如果不是空格
      // 状态设置为 IN 
      flg = IN;
      // argv 成员指向 buf 字符数组中单词的开始
      argv[argc++] = buf + i; //先用后加
    }
    // 离开单词
    else if(flg == IN && isspace(buf[i])){ //遇到\x00结束字符
      // 状态设置为 OUT 
      flg = OUT;
      // 单词结束处设置终止字符
      buf[i] = '\0';
    }
    if(argv[argc-1] != NULL){
    	argv[argc] = NULL;
    }
  }
}


int call_command(int argc,char *argv[]){
	if(strcmp(argv[0],"pwd\x00")==0){
		char buf[LEN];
        getcwd(buf, sizeof(buf));
        // get current directory

        printf("%s\n\n", buf);
        return 1;

	}else if(strcmp(argv[0],"cd\x00")==0){
		mycd(argc,argv);
		return 1;

	}else if(strcmp(argv[0],"ls\x00")==0){
		myls(argc,argv);
		return 1;

	}else if(strcmp(argv[0],"whoami\x00")==0){
		struct passwd *user_info;
		user_info = getpwuid(getuid());
		printf("%s\n",user_info->pw_name);
		return 1;
	}else if(strcmp(argv[0],"cat\x00")==0){

		char *cat_buf;
		cat_buf = (char *)malloc(4096);
		char *write_buf;
		write_buf = (char *)malloc(4096);
		memset(cat_buf,0x00,4096);
		memset(write_buf,0x00,4096);
		mycat(cat_buf,write_buf,argv);
		return 1;
	}
}


int main(){
	char buf[MAX];



	Init();
	fflush(stdout);

	while(1){
		show();
		fgets(buf, BUFFSIZE, stdin);
		parse(buf,argv);
		call_command(argc,argv);
		//break;
	}
	return 0;
}