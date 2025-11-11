//Created by Dane Iwema

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd[2];
    char *c = calloc(1024, sizeof(char));
    ssize_t total = 0;
    ssize_t n;

    /* check if there are the proper amount of arguments*/
    if ( argc != 3) {
        printf("need two file names\n");
        return 1;
    }

    /* open the first file for read only and check if it worked*/
    fd[0] = open(argv[1],  O_RDONLY);
    if ( fd[1] == -1) {
        printf ("Can't read %s.\n", argv[1]);
        return 2;
    }

    /*
        open the second file for writing or create it if it does not exist
        with the permissions to read and write for only the owner
        and then check if it opened properly
    */
    fd[1] = open(argv[2],  O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if ( fd[2] == -1) {
        printf ("Can't write %s.\n", argv[2]);
        return 3;
    }

    /*
        here is the loop to read in the bytes and save them to n
        then n is checked to not be zero and then we can add n to
        the total number of bytes read in and then write them to the 
        other file while making sure it only writes n number of bytes
        once it reads in 0 bytes then the loop finishes as the EOF 
        character was found
    */
    while ( (n = read(fd[0], c, 1024)) > 0 ) {
        total += n;
        if (write(fd[1], c, n) != n) {
            break;
        }
    }

    printf("%s copied to %s successfully.\n", argv[1], argv[2]);
    printf("Total number of bytes: %zd\n", total);

    /* clean up */
    close(fd[0]);
    close(fd[1]);
    free(c);

    return 0;
}