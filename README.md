# 42 get_next_line (125/125)

This project consist of writing a function get_next_line which get the next linein a file.

There are some features this function must implement:

	we are forbiden use libft.
	we need to implement a buffer. We can't come back in the file descriptor. We can't move in the
		file descriptor. We can only use read, free, malloc. No call to lseek.
	we can't use global variable.
	we can't use FILE structure. We need to create one.
		we can read multiple file descriptors at the same time (which implies a
	buffer).
	we can't have memory leaks: every malloc must be freed.
	the buffer size (use by read) can be changed.
	
	
