#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "Header.h"
#define MAX_LINE 80 /* The maximum length of command */ 


int main(void)
{
char *args[MAX_LINE/2 + 1]; /* command line arguments */ 
int should_run = 1; /* flag to determine when to exit program */ 
int i = 0;
char command[MAX_LINE];
pid_t pid;
int flag = 0;//no &
int check = 0;
int j;
int count = 0;
char* save[MAX_LINE/2 + 1];
char* save_command;
char* res_command;
int x;

    while (should_run) 
	{
		i = 0;
		flag = 0;//no &
		check = 0;
		label:
		fflush(stdout);
		fflush(stdin);
		command[0] = '\0';
        memset(command, 0, MAX_LINE);

		//empty args array
		for( j = 0; j <(MAX_LINE/2 + 1);j++)
				args[j] = '\0';
    	printf("osh>");

		//read user input
		//read a command, separate by space into command parts
        //wait here
		fgets (command, MAX_LINE, stdin);
		//remove the last \n !!!!
		strtok(command, "\n");
        //printf("%c %c %c %c %c %c %c \n",command[0],command[1],command[2],command[3],command[4],command[5],command[6]);
        if(strcmp(command,"exit") == 0)
            should_run = 0;


        //count the number of commands
        save_command = command;
        //strcpy(save_command,command);
        //exit
        if(strcmp(save_command,"exit") == 0)
            break;
        //handle history
        if (strcmp(save_command,"history") != 0 && (save_command[0] != '!'))
        {
            save[count++] = strdup(save_command);
        }
        else if (strcmp(save_command,"history") == 0)
        {
            if (count == 0)
            {
                printf("No commands in history\n");
                continue;
            }
            print_history(save,count);
            continue;
        }
        //handle !!
        if((strcmp(save_command,"!!") == 0))
        {
            if (count == 0)
            {
                printf("No commands in history\n");
                continue;
            }
             res_command = strdup(run_last_cmd(save,count));
             save[count++] = strdup(res_command);
             strcpy(command,res_command);
        }
        //handle !
        else if(save_command[0] == '!')
        {
            
            int index = save_command[1] - '0';
            if(save_command[2] - '0' == 0)
                index = 10;
            if (count == 0 || index > count)
            {
                printf("No command in history\n");
                continue;
            }
            res_command = strdup(run_specific_cmd(save,count,index));
            //printf(">>>>%s\n",res_command );
            save[count++] = strdup(res_command);
            strcpy(command,res_command);
        }


		char *token;
    	token = strtok(command, " ");
    	while(token != NULL)
    	{
    		//puts(token);
    		args[i++] = token;
    		token = strtok(NULL, " ");
    		

    	}
    	args[i] = NULL;
    	//check the tail of &
    	//You can't (usefully) compare strings using != or ==, you need to use strcmp:
    	if((strcmp(args[i-1],"&") == 0))
    	{
    		flag = 1;
    		args[i-1] = NULL;
    	}
 		//create a process
    	//exit
    	if((strcmp(args[0],"exit") == 0))
    			break;

       //handle fork
    	pid = fork();

    	if(pid < 0)
    	{
    		fprintf(stderr,"Frok failed");
    		return 1;
    	}
    	else if (pid == 0)
    	{
            
    	//child
            if(strcmp(save_command,"exit") == 0)
                    break;

            if(strcmp(save_command,"history") == 0 || strcmp(save_command,"!!") == 0 || (save_command[0] == '!'))
            {
                //print_history(save,count);
            }
            else
            {
                
                //add command to history   
                execvp(args[0],args);

            }
            
		}
    	else
    	{
    	//parent
            if(strcmp(save_command,"exit") == 0)
                    break;

    		if (flag)
    		{
            //sleep until seconds seconds have elapsed
    			sleep(1);
    			printf("&\tDone\n");

    		}
    		else
    		{
    			wait(NULL);
    			//printf(">>>Wait Unitl Child Complete\n");
    		}
    		
    	}
    	
	}
return 0; 

			
}