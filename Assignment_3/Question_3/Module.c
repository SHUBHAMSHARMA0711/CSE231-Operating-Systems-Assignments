#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched/signal.h>

int input_PID = 0;
module_param(input_PID, int, 0644);

int Kernel_Module_init(void)
{
	struct task_struct *task_struct = pid_task(find_get_pid(input_PID), PIDTYPE_PID);

	printk(KERN_INFO "PID  : %d\n", task_struct -> pid);
	printk(KERN_INFO "UID  : %d\n", from_kuid_munged(task_struct -> cred -> user_ns , task_struct -> cred -> uid));
	printk(KERN_INFO "PGID : %d\n", pid_vnr(task_pgrp(task_struct)));
	printk(KERN_INFO "Command Path : %s\n", task_struct -> comm);

	return 0;
}

void Kernel_Module_exit(void)
{
	printk(KERN_INFO "Module Removed Successfully");
}

module_init(Kernel_Module_init);
module_exit(Kernel_Module_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("SHUBHAM SHARMA 2021099");
MODULE_DESCRIPTION("Simple Module that take PID as Input and Prints its Task Struct Details");