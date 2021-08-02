#include <stdio.h>
#include <stdlib.h>

//https://stackoverflow.com/questions/42046611/reading-and-writing-to-a-file-at-the-same-time-in-c

int main() {
	char str[] = "This is gitbook.net";
	/**
	* https://www.tutorialspoint.com/cprogramming/c_file_io.htm
	* w+: Opens a text file for both reading and writing. 
	* It first truncates the file to zero length if it exists, 
	* otherwise creates a file if it does not exist.
	**/
	FILE* fp = fopen("file.txt", "w+");
	fwrite(str, 1, sizeof(str), fp);
	fflush(fp);

	fseek(fp, 0, SEEK_END);
	long size = ftell(fp);
	printf("Wrote %d bytes\n", size);
	//https://stackoverflow.com/questions/32366665/resetting-pointer-to-the-start-of-file/32366729
	fseek(fp, 0, SEEK_SET);

	char* fcontent = (char*)malloc(size);
	// if we open the file with "w", then we cannot read from fp!!
	fread(fcontent, 1, size, fp);
	fclose(fp);

	printf("We just wrote: %s\n", fcontent);

    return 0;
}

/*
Wrote 20 bytes
We just wrote: This is gitbook.net
*/
