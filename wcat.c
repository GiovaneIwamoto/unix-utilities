/*
    WCAT IMPLEMENTATION

    COMPILE: prompt> gcc -o wcat wcat.c -Wall -Werror
    EXECUTE: prompt> ./wcat <file>

    ------------------------------
    UNIX MAN PAGES

    fopen()
        The function opens the file whose name is the string pointed
    to by pathname and associates a stream with it.

    perror()
        Function produces a message on standart error describing the
    last error encountered during a call to a system or library function.

    fgets()
        Reads in at most one less than size characters from stream and stores
    them into the buffer pointed by s. Reading stops after an EOF or a newline.
    If a newline is read, it is stored into the buffer.

    fclose()
        Flushes the stream pointed to by stream and closes the underlying file descriptor.

*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Buffer declaration
    size_t bufferSize = 300;
    char *buffer = malloc(bufferSize);

    FILE *fp;

    // If argc >= 2, means that there is/are file(s) to read
    if (argc >= 2)
    {

        // Looping through all files
        for (int i = 1; i < argc; i++)
        {
            // Current file points to file pointer
            fp = fopen(argv[i], "r");

            // If file cannot be opened throw error
            if (fp == NULL)
            {
                perror("Error opening file");
                // stderr - error and diagnostic in a program
                fprintf(stderr, "wcat: not possible to open: %s\n", argv[i]);
                // Fail
                exit(1);
            }

            // Reads a single line from the opened file, store at buffer and continue reading until the end
            while (fgets(buffer, bufferSize, fp))
            {
                printf("%s", buffer);
            }

            printf("\n");
            fclose(fp);
        }
    }
    else
    {
        // Reads from standart input (stdin)
        while (fgets(buffer, bufferSize, stdin))
        {
            printf("%s", buffer);
        }
    }

    free(buffer);
    exit(0);
}
