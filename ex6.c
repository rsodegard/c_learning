// If Statement
if (TEST) {
	CODE:
} else if (TEST){
	CODE:
} else {
	CODE:
}

//Switch statement
switch (OPERAND) {
	case CONSTANT:
	CODE:
	break;
default:
	CODE;
}

//While Loop
while(TEST){
	CODE;
}

//While continue loop
while(TEST){
	if(OTHER_TEST){
		continue;
	}
	CODE;
}

//While break loop
while(TEST){
	if(OTHER_TEST){
		break;
	}
	CODE:
}

//do while loop
do {
	CODE:
} while(TEST);

//for loop
for(INIT; TEST; POST){
	CODE;
}

//enum - creates a set of integer constants
enum { CONST1, CONST2, CONST3 } NAME;

//goto error detection and exiting
if(ERROR_TEST){
	goto fail;
}

fail:
	CODE;

// function

TYPE NAME(ARG1, ARG2, ..) {
	CODE;
	return VALUE;
}

//practical function example

int name(arg1, arg2) {
	CODE;
	return 0;
}

//typedef

typedef DEFINITION IDENTIFIER:

//typdef practical example
typedef unsigned char byte;

//struct

struct NAME {
	ELEMENTS;
} [VARIABLE NAME];

typedef struct [STRUCT_NAME] {
	ELEMENTS;
} IDENTIFIER;

//union
union NAME {
	ELEMENTS;
} [VARIABLE_NAME];


