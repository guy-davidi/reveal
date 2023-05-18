#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/mutex.h>
#include <linux/slab.h>
#include <linux/uaccess.h>

MODULE_LICENSE("GPL");

#define FILE_PATH "/home/guy/projects/reveal_fs/text"

static int __init my_module_init(void) {
    struct file *file;
    char *data;
    loff_t offset = 0;
    ssize_t length;

    file = filp_open(FILE_PATH, O_RDONLY, 0);

    if (IS_ERR(file)) {
        pr_err("Failed to open file\n");
        return PTR_ERR(file);
    }

    length = i_size_read(file_inode(file));

    data = kmalloc(length, GFP_KERNEL);

    if (!data) {
        pr_err("Failed to allocate memory\n");
        filp_close(file, NULL);
        return -ENOMEM;
    }

    kernel_read(file, data, length, &offset);

    pr_info("File contents: %s\n", data);

    kfree(data);
    filp_close(file, NULL);

    return 0;
}

static void __exit my_module_exit(void) {
    pr_info("Module unloaded\n");
}

module_init(my_module_init);
module_exit(my_module_exit);
