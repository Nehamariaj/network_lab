#include<stdio.h>
#include<unistd.h>
void main(){
int pd;
pd=fork(); 
if(pd==0){
wait(); 
printf("I am a child process\n");
printf("Process ID=%d\n",getpid());  
printf("Parent's ID=%d\n",getppid());
}
else if(pd>0){
wait();
printf("I am a parent process\n");
printf("Parent's ID=%d\n",getppid());
}
else{
printf("fork failed\n");
}
}
