#include <stdio.h>

int print_array(char **ary)
{
	for(int i=0;i<4;i++) {
		puts(ary[i]);
	}

}

int main()
{
	char *ptr_ary[] = {"독수리","호랑이","사자","다람쥐"};
	
	print_array(ptr_ary);


	return 0;
}
