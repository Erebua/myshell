#ifndef _SHELL_H
#define _SHELL_H

#include<stdio.h>
#include<pwd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<dirent.h>
#include<grp.h>
#include<time.h>
#include<fcntl.h>
#include<malloc.h>

#include"mycd.c"
#include"myls.c"
#include"mycat.c"

#define MAX 1024
#define LEN 128
#define BUFFSIZE 1024
#define OUT 0
#define IN 1


int argc = 0;
char *argv[MAX];
char pwd[LEN];



#endif