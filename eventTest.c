#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int __init loadMessage(void){
    printk(KERN_LOG "Module has been loaded\n");
    return 0;
}

static void __exit exitMessage(void){
    printk(KERN_LOG "Module has been closed\n");
}

module_init(loadMessage);
module_exit(exitMessage);