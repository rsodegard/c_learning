#include <stdio.h>

int main(int argc, char *argv[])
{
	int distance = 100;
	float power = 2.345f;
	double super_power = 56789.4532;
	char initial = 'A';
	char first_name[] = "Zed";
	char last_name[] = "Shaw";

	//error, at index3 that puts Z on the null byte of this array
	//warning, at index 4, that overwrites the middle initial when printing last and first name.
	//first_name[3] = 'Z';

	printf("You are %d miles away.\n", distance);
	printf("You have %f levels of power.\n", power);
	printf("You have %f awesome super powers.\n", super_power);
	printf("I have an initial %c.\n", initial);
	//mess with pointer below by adding +100 to first_name, to have it point 100 over in memory
	printf("I have a first name %s.\n", first_name);
	printf("I have a last name %s.\n", last_name);
	printf("My whole name is %s %c. %s.\n", 
			first_name, initial, last_name);

	int bugs = 100;
	double bug_rate = 1.2;

	printf("you have %d bigs at the imaginery rate of %f.\n",
			bugs, bug_rate);

	//L is for long integer
	long universe_of_defects = 1L * 1024L * 1024L * 1024L;
	printf("The entire universe has %ld bugs.\n", universe_of_defects);

	double expected_bugs = bugs * bug_rate;
	printf("You are expected to have %f bugs.\n", expected_bugs);

	double part_of_universe = expected_bugs / universe_of_defects;
    printf("That is only a %e portion of the universe.\n",
            part_of_universe);

    // this makes no sense, just a emo of something weird
    char nul_byte = '\0';
    int care_percentage = bugs * nul_byte;
    printf("Which means you should care %d%%.\n", care_percentage);

    return 0;

    //float is f, integer is d, c is character, s is full string, e is exponent float
    // float is smaller than a double, ld is for long decimer. %% is for percentage
}