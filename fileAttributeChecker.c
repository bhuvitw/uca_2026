#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>


int main (int argc, char *argv[]){
	struct stat sb; 

	if(argc < 2) {
		printf("Usage %s <file path>\n", argv[0]);
		exit(-1);
	}

	if(stat(argv[1], &sb) == -1) {
		perror("stat failed"); 
		exit(EXIT_FAILURE); 
	}

	printf("%s:\n", argv[1]);
	printf("\tinode: %lu\n", sb.st_ino); 
	printf("\tperms: %o\n", sb.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO)); 
	printf("\tlinks: %ld\n" , sb.st_nlink); 
	printf("\tsize: %ld\n", sb.st_size); 
	printf("\tatime: %s", ctime(&sb.st_atim.tv_sec)); 
	printf("\tmtime: %s", ctime(&sb.st_mtim.tv_sec)); 
	printf("\tctime: %s", ctime(&sb.st_ctim.tv_sec)); 
	printf("\n"); 

	return 0; 
}
