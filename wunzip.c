/*
    WUNZIP IMPLEMENTATION

    COMPILE: prompt> gcc -o wunzip wunzip.c -Wall -Werror
    EXECUTE: prompt> ./wunzip fileX.txt

    ------------------------------
    UNIX MAN PAGES

    perror()
        Function produces a message on standart error describing the
    last error encountered during a call to a system or library function.

    fclose()
        Flushes the stream pointed to by stream and closes the underlying file descriptor.

    fread()
        Reads nmemb items of data, each size bytes long, from the stream pointed to by stream,
    storing them at the location given by ptr.

*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // No files specified case
    if (argc <= 1)
    {
        fprintf(stderr, "wunzip: file1 [file2 ...]\n");
        exit(1);
    }

    int count; // How many characters repeated
    int character;

    // For loop to go through all files entered on command line
    for (int i = 1; i < argc; i++)
    {

        // Open a binary file for reading. The file must exist.
        FILE *file = fopen(argv[i], "rb");

        // No file specified case
        if (file == NULL)
        {
            perror("Error opening file");
            fprintf(stderr, "wunzip: not possible to open: %s\n", argv[i]);
            exit(1);
        }

        // sizeof(int) represents a 4 bytes int
        // sizeof(char) represents a 1 byte char
        while (fread(&count, sizeof(int), 1, file) == 1)
        {
            fread(&character, sizeof(char), 1, file);
            // Print character 'count' times
            for (int j = 0; j < count; j++)
            {
                printf("%c", character);
            }
        }

        fclose(file);
    }
    exit(0);
}