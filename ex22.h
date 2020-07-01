#ifndef _ex22_h
#define _ex22_h

//makes the size of ex22.c avalable to other .c files
extern int THE_SIZE;

// gets and sets an dinternal static variable in ex22.c
int get_age();
int set_age(int age);

//updates a static variable thats inside update_ratio
double update_ratio(double_ratio);

void print_size();

#endif
