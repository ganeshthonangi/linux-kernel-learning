
markdown
# Linux Kernel Learning Journey on BeagleBone Black (BBB)

This document tracks my learning journey from setting up the BeagleBone Black (BBB), connecting it to the internet, writing Makefiles, and finally creating and loading my first Linux kernel module.

---

## 1. BeagleBone Black (BBB) Setup

- Connected BBB to power using the USB cable.
- Connected BBB to the internet via Ethernet or WiFi.
- Accessed BBB terminal via SSH from my PC:
  
  ```bash
  ssh root@<bbb-ip-address>
Verified BBB is online and connected.

2. Preparing the Development Environment
Installed necessary tools on BBB:

bash
opkg update
opkg install gcc make bc
Checked Linux kernel version:

bash
uname -r
Prepared cross-compilation toolchain on my PC (if compiling modules on PC):

Downloaded ARM cross-compiler: arm-linux-gnueabihf-gcc

Set environment variables for cross-compiling

3. Writing a Simple Makefile for Kernel Module
Created a directory for my module, e.g., hello_module

Inside it, created a Makefile:

makefile
obj-m := hello.o

KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
Explanation:

obj-m specifies the module file to build (hello.o from hello.c)

KDIR points to kernel build directory

all target builds the module using kernel build system

clean target cleans up build files

4. Writing My First Kernel Module (hello.c)
c
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A Simple Hello World Kernel Module");
MODULE_VERSION("0.1");

static int __init hello_init(void) {
    printk(KERN_INFO "Hello, BBB Kernel Module Loaded!\n");
    return 0;
}

static void __exit hello_exit(void) {
    printk(KERN_INFO "Goodbye, BBB Kernel Module Unloaded!\n");
}

module_init(hello_init);
module_exit(hello_exit);
This module prints messages to the kernel log when loaded and unloaded.

5. Compiling the Module
Run this inside your module directory:

bash
make
This generates the hello.ko kernel object file.

6. Loading and Testing the Module on BBB
Insert the module:

bash

sudo insmod hello.ko
Check kernel messages to verify:

bash
dmesg | tail -n 10

Remove the module:

bash
sudo rmmod hello
Check dmesg again to confirm unload message.

7. Troubleshooting Common Issues
If insmod gives File exists error, it means module already loaded. Use:

bash
sudo rmmod hello
before inserting again.

Make sure kernel headers are installed and match kernel version.

Use printk with correct log level (KERN_INFO, KERN_ERR, etc.)

8. Next Steps
Explore writing modules with parameters.

Learn debugging with printk and dmesg.

Cross-compile modules from PC to BBB.

Understand kernel subsystems and driver models.

References
Linux Kernel Module Programming Guide

BeagleBone Black Getting Started Guide

Kernel Modules Documentation

This document will be updated as I progress with my Linux kernel learning journey on BBB.

✅ Step-by-step: Copy BBB Files to Windows Using scp in Git Bash
Open Git Bash on your Windows machine

Run this command to copy the entire driver_test folder:

bash
Copy
Edit
scp -r debian@192.168.7.2:/home/debian/driver_test/* /c/Users/ganes/linux-kernel-learning/
-r = recursive

debian@192.168.7.2 = your BBB login and IP

/home/debian/driver_test/* = the folder on your BBB

/c/Users/ganes/linux-kernel-learning/ = your GitHub project directory on Windows

If asked for a password, just press enter. Usually, there's no password set for user debian.
