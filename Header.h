#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX_LINE 80 /* The maximum length of command */ 
 
void print_history(char* array[],int count);
char* run_last_cmd(char* array[],int count);
char* run_specific_cmd(char* array[],int count,int index);
#endif