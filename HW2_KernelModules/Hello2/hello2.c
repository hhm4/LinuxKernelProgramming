//Hello2.c
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

static int helloNum __initdata=2;

static int __init helloMessage(void){

	printk(KERN_INFO "Harinarayanan Mohan: Loading Hello%d module - Hello World %d \n",helloNum,helloNum);
	return 0;
}
static void __exit byeMessage(void)
{
	printk(KERN_INFO "Harinarayanan Mohan: Exiting Hello 2 module - Goodbye World 2\n");
}

module_init(helloMessage);
module_exit(byeMessage);


MODULE_LICENSE("GPL");