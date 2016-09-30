#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    switch (fork()){
        case 0:{
            printf("2) pid = %d ppid = %d\n", getpid(), getppid());
            switch (fork()){
                case 0:{
                    printf("3) pid = %d ppid = %d\n", getpid(), getppid());
                } break;
                default:{
                    switch (fork()){
                        case 0:{
                            printf("3) pid = %d ppid = %d\n", getpid(), getppid());
                        } break;
                        default: wait(); break;
                    }
                } break;
            }
        } break;
        default:{
            printf("1) pid = %d ppid = %d\n", getpid(), getppid());
            switch (fork()){
                case 0:{
                    printf("2) pid = %d ppid = %d\n", getpid(), getppid());
                    switch (fork()){
                        case 0:{
                            printf("3) pid = %d ppid = %d\n", getpid(), getppid());
                        } break;
                        default: wait(); break;
                    }
                } break;
                default: wait(); break;
            }
            wait();
        } break;
    }
    return 0;
}