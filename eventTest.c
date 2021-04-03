#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

static int __init eventTest_init(void){
    printk(KERN_EMERG "Module has been loaded.\n");
    return 0;
}

static void __exit eventTest_exit(void){
    printk(KERN_EMERG "Module has been closed.\n");
}

module_init(eventTest_init);
module_exit(eventTest_exit);