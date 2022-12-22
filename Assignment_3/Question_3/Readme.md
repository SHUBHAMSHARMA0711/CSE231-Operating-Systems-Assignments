# Implementing Kernel Module that Reads Task Struct Entries

    In this Question we have to Implement a Kernel Module that take PID as Command Line Input while loading the Module.

    For Taking Input there is a "module_param()" function that stores a input PID in input_PID variable.

    After that I find the corresponding Task Struct to the Entered PID with the help of "task_pid()" function.

    Then with the help of printk() function , I print all the Required Entries of the Task Struct.

    After that there is Exit fucntion that function will execute when we remove the module from the kernel.

# Commands for Compiling , Loading and Removing Module

    "make" command for compiling

    "sleep 120 &" for generating random process (this will give a PID that we will pass to our Module) [This is a Optional Command only run if you don't have any Process PID]

    "insmod Module.ko input_PID= pid generated from previous command" for loading Module

    "dmesg | tail" for checking the output

    "rmmod Module.ko" for removing Module

    "make clean" for deleting all files except Module.c file