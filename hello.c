#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("GANESH");
MODULE_VERSION("0.0.1");
MODULE_DESCRIPTION("hello world kernel module ");

static int __init hello_init(void)
{
	printk(KERN_INFO "hello module initialized\n");
	return 0;
}
static void __exit hello_exit(void)
{
	printk(KERN_INFO "hello module exiting \n");
	
}
module_init(hello_init);//initializing module
module_exit(hello_exit);//exiting module 
