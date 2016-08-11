#include<stdio.h>
#include<dirent.h> // opendir,closedir,readdir,DIR, struct dirent
#include<sys/stat.h> //struct stat

void main()
{
	DIR *dir; // DIR represents directory streams
	struct dirent *sdir; // required to read directory
	/* Dirent contains structure dirent which inlcudes ino_t - file serial number
	and name of entry */
	struct stat buf;
	//this structure returns information about a file
	int size;
	int type;
	
	dir = opendir("./"); // opening the current directory
	
	if(dir == NULL)
		printf("\nCannot open directory.\n");		

	else{

		printf("\nThe directory is opened!!!!!\n");
		
		// Now read the directory stream which contains directory entries

                while(sdir = readdir(dir))
                {       
                        printf("\n%s",sdir->d_name);
			stat(sdir->d_name,&buf);
			size = buf.st_size;
			printf("\t%d",size);
			if(S_ISDIR(buf.st_mode))
				printf("\t Directory");
			else
				printf("\tFile");
                }

		printf("\n");
                // close the directory stream pointer   

                closedir(dir);

	}		

}
