#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include "Header.h"
#define MAX_LINE 80 /* The maximum length of command */ 


void print_history(char* array[],int count)
{
	int i = 10;
	//less than 10
	if(count <= 10)
	{
		while(count != 0)
		{
			printf("%d %s\n",count,array[count-1]);


			i++;
			if(i == 10)
				break;
			count--;
			//i++;
		}

	}
	//bigger than 10
	else
	{
		while(count != 0)
		{
			printf("%d %s\n",i,array[count-1]);


			i--;
			if(i == 0)
				break;
			count--;
			//i++;
		}

	}
}
char* run_last_cmd(char* array[],int count)
{

	int num = count-1;
	char* command = array[num];
	return command;

}
char* run_specific_cmd(char* array[],int count,int index)
{
	int i = 10;;
	char* command;
	//printf("%d\n",count);
	if(count <= 10)
	{
		
		 command = array[index-1];
	}
	else
	{
		//printf("><count%d + index%d =%d == %s\n",count,index,count+index-11,array[count+index-11]);
		 command = array[count+index-11];


	}
	return command;
}