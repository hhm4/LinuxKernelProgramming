//Hello1.c

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int  helloMessage(void)
{
        printk(KERN_ALERT "Harinarayanan Mohan: Loading Hello1 module - Hello World 1\n");
        return 0;
}

static void  byeMessage(void)
{
        printk(KERN_ALERT "Harinarayanan Mohan: Exiting Hello1 module - Goodbye World 1\n");
}

module_init(helloMessage);
module_exit(byeMessage);