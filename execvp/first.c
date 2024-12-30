#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void main()
{
char *args[]={"./neha",NULL}; 
execvp(args[0],args); 
printf("End");
}
