#include <linux/module.h>

static int __init lkmName_init(void){
    pr_info("Hello world\n");

    return 0;
}

static void __exit lkmName_cleanup(void){
    pr_info("Good bye world\n");
}

module_init(lkmName_init);
module_exit(lkmName_cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ME");
MODULE_DESCRIPTION("A simple lkm to use as a template");