/* Noah Verdeyen
 * CIS 343
 * C project
 * */
#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"
#include <sys/stat.h>

/* worked with RJ Hamilton on this file */

int read_file( char* filename, char **buffer ){
	
	FILE *filePTR;
	
	// gives system stats, for how large data types are
	struct stat st;
	stat(filename, &st);
	int size = st.st_size;
	
	// opens file to be read
	filePTR = fopen(filename, "r");

	// if file does not exist, exit
	if(filePTR == NULL){
		fprintf(stderr, "failed to open the file.\n");
		exit(1);
	}
	
	// else, begin reading and allocating memory
	else{
		*buffer = malloc(sizeof(char) *(size));
		fread(*buffer, sizeof(char), size, filePTR);
		fclose(filePTR);
	}

	return size;
}

int write_file( char* filename, char *buffer, int size ){
	
	// creates new file to be written on
	FILE *filePTR = fopen(filename, "w");
	
	// if file does not exist, exit
	if(filePTR == NULL){
		fprintf(stderr, "failed to open the file.\n");
		exit(1);
	}
	
	// else, begin writing
	else{
		fwrite(buffer, sizeof(char), size, filePTR);
	}
	return 0;
}
