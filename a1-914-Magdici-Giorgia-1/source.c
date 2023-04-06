#include <stdio.h>



//a.Read sequences of positive integer numbers(reading of each sequence ends by 0, reading of all the sequences 
//	ends by - 1) and determine the maximum element of each sequenceand the maxim element of the global sequence.
//b.Given a vector of numbers, find the longest contiguous subsequence such that all elements are in a given interval.


typedef struct {
	int arr[101], len;
}Vector;



void print_menu()
// print the menu 
{

	printf("\n1.Read sequences of positive integer numbers (reading of each sequence ends by 0, reading of all the sequences ends by - 1) and determine the maximum element of each sequence and the maxim element of the global sequence.\n");
	printf("2.Given a vector of numbers, find the longest contiguous subsequence such that all elements are in a given interval.\n");
	printf("3.Print the exponent of a prime number p from the decomposition in prime factors of a given number n(n is a non - null natural number).\n");
	printf("4. Exit\n");

}


Vector read_until_zero()
/// Read sequence of positive integer numbers ending with 0 and returns a Vector
{
	Vector v;
	int x;

	v.len = 0;
	printf("Input sequence(ending with 0) ");
	scanf("%d", &x);
	if (x != -1) {
		while (x != 0)
		{
			v.arr[v.len++] = x;
			scanf("%d", &x);
		}
	}
	else {
		v.arr[0] = x;
		v.len = 1;
	}
	return v;
}



int maximum_from_vector(Vector v) {
	/// returns the maximum value from the vector v 

	int max = v.arr[0];
	for (int i = 1; i < v.len; i++) {
		if (v.arr[i] > max) {
			max = v.arr[i];
		}
	}
	return max;
}

Vector read_vectors_and_get_maxs() {
	//returns a vector containing the maximum element of each sequence
	Vector maxs, cr_seq;
	maxs.len = 0;
	cr_seq = read_until_zero();
	while (cr_seq.arr[0] != -1) {
		maxs.arr[maxs.len++] = maximum_from_vector(cr_seq);
		cr_seq = read_until_zero();
	}
	//maxs.len -= 1;
	return maxs;
}

Vector read_vector()
{
	//reads a vector 
	Vector v;
	printf("The lenght of the vector:");
	scanf("%d", &v.len);
	for (int i = 0; i < v.len; i++)
	{
		scanf("%d", &v.arr[i]);
	}
	return v;


}



void longest_subsequence_in_interval(Vector v, int* start, int* end, int int1, int int2)
{
	//Given a vector of numbers v, the function returns by parameters "start" and "end" 
	//the start poition and the end position of the longest contiguous subsequence such that 
	//all elements are in a given interval [int1,int2].

	*start = -1, * end = -1;
	int cr_start = -1, cr_end = -1;
	for (int i = 0; i < v.len; i++) {
		if (v.arr[i] >= int1 && v.arr[i] <= int2) {
			if (cr_start == -1) {
				cr_start = i;
			}
			cr_end = i;
		}
		else {
			if (cr_end - cr_start > *end - *start)
			{
				*end = cr_end;
				*start = cr_start;
			}
			cr_end = i + 1;
			cr_start = i + 1;
		}
	}
	if (cr_end - cr_start > *end - *start)
	{
		*end = cr_end;
		*start = cr_start;
	}

}


void print_seq_from_vector(Vector v, int start, int end) {
	//prints from vector v the sequence between positions start and end.
	if (start == -1) {
		printf("\nthe sequence is empty\n");
	}
	else {
		for (int i = start; i <= end; i++) {
			printf("%d ", v.arr[i]);
		}
		printf("\n");
	}
}

void read_interval(int* left, int* right) {
	//reads the endpoints of an interval
	printf("which is the interval?\nleft extrema:");
	scanf("%d", left);
	printf("\nright extrema:");
	scanf("%d", right);
}


int exponent_of_a_prime_factor(int x) {
	//returns the exponent of the lowest prime number d from the decomposition in prime factors of x
	int d, p;
	for (d = 2; d <= x; d++) {
		p = 0;
		while (x % d == 0) {
			x = x / d;
			p = p + 1;
		}
		if (p != 0)
			return p;
	}
}


int main()
{
	int x;
	int option, should_run = 1;

	while (should_run == 1)
	{
		print_menu();
		scanf("%d", &option);
		Vector v;
		int max;
		switch (option)
		{
		case 1:
			Vector maximums;
			maximums = read_vectors_and_get_maxs();
			printf("the maximums for each subsequence are:");
			print_seq_from_vector(maximums, 0, maximums.len - 1);
			max = maximum_from_vector(maximums);
			printf("the final one:%d", max);
			break;
		case 2:
			v = read_vector();
			int start, end;
			int int_left, int_right;
			read_interval(&int_left, &int_right);
			longest_subsequence_in_interval(v, &start, &end, int_left, int_right);
			print_seq_from_vector(v, start, end);
			break;

		case 3:
			int x, p;
			printf("x:");
			scanf("%d", &x);
			while (x <= 0)
				printf("please, enter a non-null natural number");
			p = exponent_of_a_prime_factor(x);
			printf("\n%d", p);
		case 4:
			should_run = 0;
			break;
		default:
			printf("Wrong option!\n");
			break;
		}
	}
}
