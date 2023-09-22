## About
The provided code is a kernel module that demonstrates how to read the contents of a file from the kernel space.
- It initializes by opening a specified file
- Allocating memory for a buffer
- Reading the file contents into the buffer using kernel_read()
- Printing the contents to the kernel log

It serves as an example of how to access and manipulate files within the kernel environment.
```
guy@guy-VirtualBox:~/projects/reveal_fs$ sudo dmesg
[ 6012.141197] Module unloaded
[ 6024.229786] File contents: Guy The King!

guy@guy-VirtualBox:~/projects/reveal_fs$ cat text 
cat: text: Permission denied
guy@guy-VirtualBox:~/projects/reveal_fs$ ll text 
-rw------- 1 600 guy 14 May 18 19:44 text
```
