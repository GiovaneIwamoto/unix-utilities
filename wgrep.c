/*
    WGREP IMPLEMENTATION

    COMPILE: prompt> gcc -o wgrep wgrep.c -Wall -Werror
    EXECUTE: prompt> ./wgrep <term> <file>

    ------------------------------
    UNIX MAN PAGES

    fopen()
        The function opens the file whose name is the string pointed
    to by pathname and associates a stream with it.

    perror()
        Function produces a message on standart error describing the
    last error encountered during a call to a system or library function.

    fclose()
        Flushes the stream pointed to by stream and closes the underlying file descriptor.

    getline()
        Reads an entire line from stream, storing the address of the buffer containing the
    text into *lineptr. The buffer is null-terminated and includes the newline character, if one was found.

    strstr()
        Finds the first occurrence of the substring needle in the string haystack.
    The terminating null bytes ('\0') are not compared.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // No term and file case
    if (argc <= 1)
    {
        printf("wgrep: <term> [file ...]\n");
        exit(1);
    }

    const char *term = argv[1];

    // Stdin case, term defined but without file to search
    if (argc == 2)
    {
        // Buffer declaration
        size_t bufferSize = 300;
        char *buffer = malloc(bufferSize);
        while (getline(&buffer, &bufferSize, stdin) != -1)
        {
            // Checks if the substring term is present in buffer.
            if (strstr(buffer, term) != NULL)
            {
                printf("%s", buffer);
            }
        }
        free(buffer);
    }
    else
    {
        // Term and file(s) defined case
        for (int i = 2; i < argc; i++)
        {
            const char *file = argv[i];
            FILE *fp = fopen(file, "r");

            if (fp == NULL)
            {
                perror("Error opening file");
                // stderr - error and diagnostic in a program
                fprintf(stderr, "wgrep: not possible to open: %s\n", file);

                exit(1);
            }

            // type size_t used to represent the size of an object
            size_t bufferSize = 300;
            char *buffer = malloc(bufferSize);
            while (getline(&buffer, &bufferSize, fp) != -1)
            {
                // Checks if the substring term is present in buffer.
                if (strstr(buffer, term) != NULL)
                {
                    printf("%s", buffer);
                }
            }
            fclose(fp);
            free(buffer);
            printf(" \n");
        }
    }

    exit(0);
}
