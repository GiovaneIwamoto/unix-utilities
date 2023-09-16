# UNIX UTILITIES

### **INTRODUCTION**

A few different UNIX utilities, simple versions of commonly used commands like cat, grep, zip, unzip.

### **OBJECTIVES**

- Become familiar with a UNIX terminal/shell/command line.

- Learn how to use an appropriate code editor such as emacs.

- Learn a little about how UNIX utilities are implemented.

While the project focuses on writing simple C programs, you can see from above that even that requires a lot of other prior knowledge, including a basic idea of what a command interpreter (shell) is and how to use the command line in some UNIX-based systems programs (e.g., Linux or macOS), how to use an editor such as emacs, and of course a basic understanding of C programming.

### **OVERVIEW**

- Several individual .c files for each of the utilities below: wcat.c, wgrep.c, wzip.c, and wunzip.c.

- Each should compile successfully when compiled with the -Wall and -Werror flags.

### **INSTALLATION GUIDE**

- Clone this repository

- Ensure that you are working from the main branch, it is the most stable at any given time for this project.

- Open a terminal and navigate to the directory where the Makefile is located.

- Run the command `make all` to compile all programs. This will create four executable files: wcat, wgrep, wzip, and wunzip.

- To run the wcat program, run the command `./wcat [filename]`, where filename is the name of the file you want to read.

- To run the wgrep program, run the command `./wgrep [search_term] [filename]`, where search_term is the term you want to search for and filename is the name of the file you want to search.

- To run the wzip program, run the command `./wzip [filename]`, where filename is the name of the file you want to compress.

- To run the wunzip program, run the command `./wunzip [filename]`, where filename is the name of the file you want to decompress.

- To remove all executable files, run the command `make clean`.

### **AUTHOR**

- Giovane Hashinokuti Iwamoto - Computer Science student at UFMS - Brazil - MS

I am always open to receiving constructive criticism and suggestions for improvement in my developed code. I believe that feedback is an essential part of the learning and growth process, and I am eager to learn from others and make my code the best it can be. Whether it's a minor tweak or a major overhaul, I am willing to consider all suggestions and implement the changes that will benefit my code and its users.
