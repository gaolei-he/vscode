#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
static int hello_init(void)
{
 	printk(KERN_ALERT"hello world enter\n");
 	return 0;
}
static void hello_exit(void)
{
        printk(KERN_ALERT"hello world exit!\n");
        
}
module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
