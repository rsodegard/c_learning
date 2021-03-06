#include <stdio.h>

int main(int argc, char *argv[])
{
	int ages[] = {23, 43, 12, 89, 2};
	char *names[] = {
		"Alan", "Frank",
		"Mary", "John", "Lisa"
	};

	int count = sizeof(ages) / sizeof(int);
	int i = 0;

	for (i = 0; i < count; i++){
		printf("%s has %d years alive.\n", names[i], ages[i]);
	}

	printf("---\n");
	//creating a pointer
	int *cur_age = ages;
	char **cur_name = names;

	//SECOND WAY

	for (i = 0; i < count; i++){
		printf("%s is %d yearls old.\n",
			*(cur_name + i), *(cur_age + i));
	}
	printf("---\n");

	//THIRD WAY GOOD WAY
	for (i = 0; i < count; i++){
		printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
	}

	printf("---\n");

	//fourth way

	for (cur_name = names, cur_age = ages;
			(cur_age - ages) < count; cur_name++, cur_age++){
		printf("%s lived %d years so far.\n", *cur_name, *cur_age );
	}

	return 0;

	//Note
	//int, char, person, void
	//you can treat computer as gigantic array of bytes.
	//a regular variable declaration is the actual piece of ram
	// a pointer dec is the array index, number, address of where it is in ram
	










}