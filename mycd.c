
#include"shell.h"
#define LEN 128

int mycd(int argc, char *arglist[])
{
    if (argc > 2)
    {
        printf("cd: too many arguments\n");
        return 1;
    }
    // cd: too many arguments

    char home[LEN];
    struct passwd *pass;
    pass = getpwuid(getuid());

    sprintf(home, "/home/%s", pass->pw_name);

    if (arglist[1] == NULL)
    {
        arglist[1] = (char *)malloc(sizeof(home));
        strcpy(arglist[1], home);
    }
    // Change to /~

    int sta = chdir(arglist[1]);
    if (sta < 0) // cannot find the file
    {
        printf("\e[31;1mcd: No such file or directory: %s\n\n\e[0m", arglist[1]);
        return 1;
    }
    printf("\n");
}

void show(){
	char pwd[LEN];
	char hostname[LEN];
	struct passwd *user_info;

	gethostname(hostname,sizeof(hostname-1));
	user_info = getpwuid(getuid());

	getcwd(pwd,sizeof(pwd)-1);
	printf("\e[32;1m[%s@%s %s]\n\e[0m\033[1;31m$ \033[0m", user_info->pw_name, hostname, pwd);
}
