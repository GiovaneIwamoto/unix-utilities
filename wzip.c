/*
    WZIP IMPLEMENTATION

    COMPILE: prompt> gcc -o wzip wzip.c -Wall -Werror
    EXECUTE: prompt> ./wzip fileX.txt > fileY

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

    fread()
        Reads nmemb items of data, each size bytes long, from the stream pointed to by stream,
    storing them at the location given by ptr.

    fwrite()
        Writes nmemb items of data, each size bytes long, to the stream pointed to by stream,
    obtaining them from the location given by ptr.

*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // No files specified case
    if (argc <= 1)
    {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    char current_char;     // Current character
    char last_char = 0;    // Character for comparison
    int current_count = 0; // Character counter

    for (int i = 1; i < argc; i++)
    {
        FILE *file = fopen(argv[i], "rb");

        if (file == NULL)
        {
            /*  Ensure that the last set of characters from the last file is processed correctly and written
                to the final output in case the next file reading fails
            */
            if (last_char != 0)
            {
                // sizeof(int) is the expression that represents the size in bytes of a 4-byte integer
                fwrite(&current_count, sizeof(int), 1, stdout);
                fwrite(&last_char, sizeof(char), 1, stdout);
            }
            perror("\nError opening file");
            // stderr - error and diagnostic in a program
            fprintf(stderr, "wzip: not possible to open: %s\n", argv[i]);

            exit(1);
        }

        // Read the file while there is success
        while ((fread(&current_char, sizeof(char), 1, file)) == 1)
        {
            // Start of reading
            if (last_char == 0)
            {
                last_char = current_char;
                current_count = 1;
            }
            // Counting
            else if (current_char == last_char)
            {
                current_count++;
            }
            // current_char != last_char, so writes current_count followed by last_char
            else
            {
                // sizeof(int) is the expression that represents the size in bytes of a 4-byte integer
                fwrite(&current_count, sizeof(int), 1, stdout);
                fwrite(&last_char, sizeof(char), 1, stdout);

                last_char = current_char;

                // Reset count
                current_count = 1;
            }
        }
        fclose(file);
    }
    // Ensure that the last set of characters from the last file is processed correctly and written to the final output
    if (last_char != 0)
    {
        fwrite(&current_count, sizeof(int), 1, stdout);
        fwrite(&last_char, sizeof(char), 1, stdout);
    }
    exit(0);
}