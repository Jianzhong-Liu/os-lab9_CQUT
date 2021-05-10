#include<fcntl.h>
#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>
#include <errno.h>

int main(){

	int fd1,fd2;
	int e,f;
	int a,b;  // get the value of mask

    a = umask(2);
	fd1 = open("t1.txt",O_CREAT,a);
	if(0 > fd1) // create fault
	{
		printf("errno:%s\n",strerror(errno));
		exit(0);
	}
	else
	{
		e=link("t1.txt","ha1");

		if(e < 0){
			printf("errno:%s\n",strerror(errno));
			exit(0);
		}

		f =  symlink("t1.txt","so1");

		if(f < 0){
			printf("errno:%s\n",strerror(errno));
			exit(0);
		}

	}

	 b = umask(0);  // change the mask value to 2


	fd2 = open("t2.txt",O_CREAT,b); // create a new file with current mask

	if(0 > fd2) // create fault
		{
			printf("errno:%s\n",strerror(errno));
			exit(0);
		}
		else
		{
			e=link("t2.txt","ha2");

			if(e < 0){
				printf("errno:%s\n",strerror(errno));
				exit(0);
			}

			f =  symlink("t2.txt","so2");

			if(f < 0){
				printf("errno:%s\n",strerror(errno));
				exit(0);
			}
			system("ls -li t1.txt t2.txt ha1 ha2 so1 so2");

            return 0;
		}









}
