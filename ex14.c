#include <stdio.h>
#include <ctype.h>

//lecture here really good
//we have to add print letters below, to give c a warning that its coming. old cpu small, no memory to load files. 

//forward declarations
int can_print_it(char ch);
void print_letters(char arg[]);

void print_arguments(int argc, char *argv[])
{
	int i = 0;

	for (i = 0; i < argc; i++){
		print_letters(argv[i]);
	}
}

//what does backslash n do, do d and s on a letter change what i get

void print_letters(char arg[])
{
	int i = 0;
	for (i = 0; arg[i] != '\0'; i++){
		char ch = arg[i];

		if (can_print_it(ch)) {
			printf("'%c' == %d ", ch, ch);
		}
	}

	printf("\n");
}

int can_print_it(char ch)
{
	//return the isalpha number if true, if false, return blank
	return isalpha(ch) || isblank(ch);
}

int main(int argc, char *argv[])
{
	print_arguments(argc, argv);
	return 0;
}
