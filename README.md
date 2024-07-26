# UNIX UTILITIES

### **INTRODUCTION**

A few different UNIX utilities, simple versions of commonly used commands like cat, grep, zip, unzip. While the project focuses on writing simple C programs, it also necessitates a foundational knowledge of several other concepts. These include understanding what a command interpreter (shell) is and how to use the command line in UNIX-based systems (e.g., Linux or macOS), proficiency in using an editor like Emacs, and a basic grasp of C programming.

[![Icons](https://skillicons.dev/icons?i=linux,ubuntu,debian,c&theme=dark)](https://skillicons.dev)

### **OVERVIEW**

- Several individual .c files for each of the utilities below: wcat.c, wgrep.c, wzip.c, and wunzip.c.

> [!IMPORTANT]
> The programs are designed to compile with strict flags (-Wall and -Werror), ensuring code quality and robustness. By adhering to these stringent compilation standards, the project aims to provide a practical understanding of UNIX utility implementation, fostering proficiency in both C programming and UNIX system operations.

### **INSTALLATION GUIDE**

- Open a terminal and navigate to the directory where the Makefile is located.

- Run the command `$ make all` to compile all programs. This will create four executable files: wcat, wgrep, wzip, and wunzip.

- To run the wcat program, run the command `$ ./wcat [filename]`, where filename is the name of the file you want to read.

- To run the wgrep program, run the command `$ ./wgrep [search_term] [filename]`, where search_term is the term you want to search for and filename is the name of the file you want to search.

- To run the wzip program, run the command `$ ./wzip [filename]`, where filename is the name of the file you want to compress.

- To run the wunzip program, run the command `$ ./wunzip [filename]`, where filename is the name of the file you want to decompress.

> [!TIP]
> To remove all executable files and clean up the directory, run the command make clean. This will delete all the compiled binaries, ensuring that the directory is returned to its original state, free of any generated executable files.

### **OBJECTIVES**

- Become familiar with a UNIX terminal/shell/command line.

- Learn how to use an appropriate code editor such as emacs.

- Learn a little about how UNIX utilities are implemented.

### **AUTHOR**

- Giovane Hashinokuti Iwamoto - Computer Science student at UFMS - Brazil - MS

I am always open to receiving constructive criticism and suggestions for improvement in my developed code. I believe that feedback is an essential part of the learning and growth process, and I am eager to learn from others and make my code the best it can be. Whether it's a minor tweak or a major overhaul, I am willing to consider all suggestions and implement the changes that will benefit my code and its users.
