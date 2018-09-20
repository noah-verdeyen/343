/* Noah Verdeyen
 * CIS 343
 * C Project
 * */

#ifndef H_FILEUTIL
#define H_FILEUTIL

/* Opens and reads a file, allowing us to put the chars into memory to be reversed */
int read_file( char* filename, char **buffer );

/* Creates a new file which writes new chars into it, that are in reverse order */
int write_file( char* filename, char *buffer, int size);

#endif
