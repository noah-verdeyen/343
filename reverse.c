/* Noah Verdeyen
 * CIS 343
 * Project in C
 * */

#include <stdio.h>
#include <stdlib.h>

/* worked with RJ Hamilton and Matt Kennedy */

int main(int argc, char** argv){
	
	
	char* buffer;
	
	// fail if not enough or too few arguments
	if(argc != 3){
		fprintf(stderr, "improper input");
		exit(1);
	}
	
	// if proper amount of arguments, begin reverse
	else{	
		// reads
		int size = read_file(*(argv[1]), &buffer);
		
		// allocates memory
		char* reverseBuffer = (char*)malloc(size * sizeof(char));

		for(int i = 0; i < size; i++){
			reverseBuffer[size - 1 - i] = buffer[i];
		}
		// writes new file
		write_file(*(argv[2]), reverseBuffer, size);

		free(reverseBuffer);
	}
	
	free(buffer);

	return 0;
}
