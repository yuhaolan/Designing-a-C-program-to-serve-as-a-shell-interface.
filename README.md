# Designing-a-C-program-to-serve-as-a-shell-interface.
• Implemented a shell interface to allow parent process read the entered on the command line

• Created a separate child process that performs the command

• Generated history feature to print 10 most recent commands.

• Entered a single ! followed by integer N, the Nth command in the history was executed.


Usage: 
	>make
	
	>.Proj2
	


1.if history is more than 10, keep track the most recent 10 commands, update the index(order number) for commands. The most recent command has the biggest number.


2.command !number and !! also add into the history part. For example, !3 is ls, then add ls to history.


3.error checking, for example no history in !number or !! or history commands


4.enter exit to quit




Delete:

	>make clean
