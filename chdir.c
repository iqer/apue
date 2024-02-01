#include "include/apue.h"
#include "include/myerror.h"

int main()
{
    if (chdir("/dmo") < 0)
    {
        err_sys("chdir failed");
    }
    printf("chdir to /tmp succeeded\n");
    exit(0);
}