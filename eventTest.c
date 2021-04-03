#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "KEYSMASH"

static int dev_open(struct inode*, struct file*);
static int dev_release(struct inode*, struct file*);
static ssize_t dev_read(struct file*, char*, size_t, loff_t*);
static ssize_t dev_write(struct file*, const char*, size_t, loff_t*);

static struct file_operation fops = {
    .open = dev_open,
    .read = dev_read,
    .write = dev_write,
    .release = dev_release,
};

static int major;

static int __init eventTest_init(void){
    major = register_chrdev(0, DEVICE_NAME, &fops);

    if(major < 0){
        printk(KERN_ALERT "Event test module load failed");
        return major;
    }else{
        printk(KERN_INFO "Module has been loaded and updated.\n");
    }    
    return 0;
}

static void __exit eventTest_exit(void){
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "Module has been closed down.\n");
}

module_init(eventTest_init);
module_exit(eventTest_exit);