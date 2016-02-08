//Hello3.c
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>
#include <linux/stat.h>


static char *name = "Harinarayanan Mohan";
static char *street="Hoyt Street";
static char *city="Kearny";
static long zip=07032;

module_param(name,charp, 0000);
module_param(street,charp, 0000);
module_param(city,charp, 0000);
module_param(zip, long, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
//S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
static int __init displayDetails(void)
{
	printk(KERN_INFO "Loading Hello 3: Hello World 3\n ");
	printk(KERN_INFO "==============================\n ");
	printk(KERN_INFO "Name : %s \n",name);
	printk(KERN_INFO "Street : %s \n",street);
	printk(KERN_INFO "City : %s \n",city);
	printk(KERN_INFO "Zip : %ld \n",zip);
	return 0;
}

static void __exit byeMessage(void)
{
	printk(KERN_INFO "Exiting Hello 3 : Good Bye 3");
}
module_init(displayDetails);
module_exit(byeMessage);

MODULE_LICENSE("GPL");