# Firstly Editing the Files in linux-6.0.9

Firtsly I Edit the /home/kernel/linux-6.0.9/arch/x86/entry/syscalls/syscall_64.tbl and here at 451 I listed my Custom SYSCALL.

Then I Edit the /home/kernel/linux-6.0.9/kernel/sys.c and In this file I added the Code of my Custom Syscall.

After Doing All above mentioned Stuff I compiles the Kernel with below mentioned Commands.
1. make -j$(nproc)
2. make modules_install
3. cp -v arch/x86/boot/bzImage /boot/vmlinuz-linux_custom_final

Then I Rebooted the System.


# Testing the Custom System Call

After Rebooting I write a C Code for Testing My Custom Syscall.

In this code I'm printing the Source Array before Invoking the System Call and Printing the Destination Array after Invoking the System Call.

Both the Arrays Printing The same Floating Point Numbers. 

Hence, It is Tested that My Custom SysCall in Working Fine.


# Making Patch File 

I run the "diff" command in between the Stock Kernel and Patched Kernel Files and Stored the Output in the Question_2.patch file.