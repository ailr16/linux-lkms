#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

static int num = 5;
module_param(num, int, 0444);

static int major;

ssize_t my_read(struct file *f, char __user *u, size_t l, loff_t *o)
{
    printk("chardev - Read is called\n");
    return 0;
}

static struct file_operations fops = {
    .read = my_read
};

static int __init lkmName_init(void){
    major = register_chrdev(0, "chardev", &fops);
    if(major < 0){
        printk("chardev - Error registering chrdev\n");
        return major;
    }
    printk("chardev - Major device number: %d\n", major);

    return 0;
}

static void __exit lkmName_cleanup(void){
    unregister_chrdev(major, "chardev");
    printk("chardev - Unloaded module\n");
}

module_init(lkmName_init);
module_exit(lkmName_cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ME");
MODULE_DESCRIPTION("A sample driver for registering a char device");