1. Page tables/ virutal memor
2. `fork()` return value
3. Multiple `fork()` calls
4. Parent/child memory after `fork()`
5. File descriptor + file offset after `fork()`
6. Zombie processes

**Page-table entries = Number of virtual pages = Virtual address space / page size**

`fork()` creates a new process
what does it return? 
In the parent:
> fork() -> child's PID
In the child: 
> fork() -> 0
If fork fails: 
> fork() -> -1

n sequential unconditional forks -> 2^n processes

memory after `fork()`
After fork(), parent and child have separate process address spaces.

File Descriptor + `fork()`

They share the open file table entry, including the current file offset

Zombie Process -> has already terminated + it's process-table still exists