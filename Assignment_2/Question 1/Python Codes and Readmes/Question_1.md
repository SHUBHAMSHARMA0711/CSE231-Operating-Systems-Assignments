# Logic For 1.1

Firstly I Launched 3 Three Threads each of the Thread is counting from 1 to 2^32 in thier respective fucntions.

Immediately after Entering in the function I set the start clock using clock_gettime() function and put the end time clock just before leaving from the function.

In each functions before starting the counting I set the Priority and Scheduling Policy of each Thread by using pthread_setschedparam() function.

I put all these stuff in a for loop that run it 10 times.

So, then I Write all the times in text file and used that times for plotting the Bar Graph Using the seprate Python program.


# Logic for 1.2

In this part I put the start clock just before doing Each fork() and in its Child Process I used execvp() to run the bash file.

Important point to note here is I used return 0; in child process after execvp() for returning immdiately after finishing the execvp() command.

Now, comes to the wait part in this part I used 3 waitpid() functions  and pass -1 in this function and so it can detects which process is finished and returns its pid by the help of pid I detect which process is finished and then I stops the time for the process by using clock_gettime() function.

Same as 1.1 I write all times in a text file and used to plot graph.


# Outcomes

It is very predictable that SCHED_OTHER will finsish lastly and SCHED_RR and SCHED_FIFO have very minimum time differences.