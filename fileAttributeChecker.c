#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

char* getFileType(mode_t mode){
	if (S_ISREG(mode)) return "Regular File";
	else if(S_ISDIR(mode)) return "Directory"; 
	else return "to be considered";
}

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

	printf("=== File Attributes for: %s ===\n", argv[1]); 
	printf("%-22s %s\n", "File Type:", getFileType(sb.st_mode));
	printf("%-22s %04o\n","Permision:",sb.st_mode & 0777); 
	printf("%-22s %ld\n", "File size:", sb.st_size); 	
	printf("%-22s %ld\n", "Hard Link Count:" , sb.st_nlink); 
	printf("%-22s %d\n","Owner (UID):", sb.st_uid);
	printf("%-22s %d\n","Group (GID):", sb.st_gid);
	printf("%-22s %s","Last Access Time:", ctime(&sb.st_atim.tv_sec)); 
	printf("%-22s %s","Last Modification:", ctime(&sb.st_mtim.tv_sec)); 
	printf("%-22s %s","Status Change Time:", ctime(&sb.st_ctim.tv_sec)); 

	return 0; 
}
