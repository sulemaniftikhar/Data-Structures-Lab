// a)
// 	// previously it was uninitialized pointer
// 	int *number;
// int num = 5;
// number = &num;
// cout << number << endl;

// b)
// // it is needed to be type casted
// 	double *realptr;
// long *integerPtr;
// integerPtr = (long *)realptr;

// c)
// // made y also a pointer
// 	int *x, *y;
// x = y;

// d)
// char s[] = "this is a character array";
// // array name is a constant pointer so we cannot modify it
// for (char *ptr = s; *ptr != '\0'; ++ptr)
//     cout << *ptr << "'";

// e)
// short *numptr, result;
// void *genericPtr = numptr;
// // genericPtr needed to be type casted and than dereferenced
// result = *(short *)genericPtr + 7;

// f)

// 	double xN = 19.34;
// // give address by using & operator
// double *xPtr = &xN;
// cout << xPtr << endl;
