#include <linux/module.h>
#include <linux/init.h>
#include <linux/gpio/consumer.h>

static int num = 5;

static struct gpio_desc *led, *button;

#define IO_LED    21
#define IO_BUTTON 20

#define IO_OFFSET 512

module_param(num, int, S_IRUGO);

static int __init lkmName_init(void){
    pr_info("Loaded module\n");

    int status;

    led = gpio_to_desc(IO_LED + IO_OFFSET);
    if(!led){
        printk("gpioctrl - Error getting pin 21\n");
        return -ENODEV;
    }

    button = gpio_to_desc(IO_BUTTON + IO_OFFSET);
    if(!button){
        printk("gpioctrl - Error getting pin 20\n");
        return -ENODEV;
    }

    status = gpiod_direction_output(led, 0);
    if(status){
        printk("gpioctrl - Error setting pin 20 as output\n");
        return status;
    }

    status = gpiod_direction_input(button);
    if(status){
        printk("gpioctrl - Error setting pin 21 as input\n");
        return status;
    }

    gpiod_set_value(led, 1);
    printk("gpioctrl - Button is %spressed\n", gpiod_get_value(button) ? "" : "not ");

    return 0;
}

static void __exit lkmName_cleanup(void){
    gpiod_set_value(led, 0);
    pr_info("Unloaded module\n");
}

module_init(lkmName_init);
module_exit(lkmName_cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ME");
MODULE_DESCRIPTION("A simple lkm to use as a template");