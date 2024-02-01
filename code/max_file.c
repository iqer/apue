#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define MAX_FILES 100000
#define FILENAME_PREFIX "testfile"

int main()
{
    int files[MAX_FILES];

    for (int i = 0; i < MAX_FILES; ++i)
    {
        char filename[20];
        snprintf(filename, sizeof(filename), "%s%d.txt", FILENAME_PREFIX, i);

        files[i] = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
        if (files[i] == -1)
        {
            perror("open error");
            exit(EXIT_FAILURE);
        }

        // Optionally write some data to the file
        const char *data = "Hello, File!\n";
        if (write(files[i], data, strlen(data)) == -1)
        {
            perror("write error");
            exit(EXIT_FAILURE);
        }
    }

    printf("Successfully opened %d files.\n", MAX_FILES);

    // Optionally, close the files
    for (int i = 0; i < MAX_FILES; ++i)
    {
        if (close(files[i]) == -1)
        {
            perror("close error");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
