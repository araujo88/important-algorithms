#include <iostream>

#define SIZE(x) (sizeof(x)/sizeof(x[0]))
#define MAX(a,b) (a > b) ? a : b;
#define MIN(a,b) (a < b) ? a : b;

int max_subarray_sum(int *array, unsigned int size) {
	int max_ending_here = array[0]; // the maximum sum of a subarray ending at the current position
	int max_so_far = array[0]; // the overall maximum of a subarray found so far

	for (int i = 1; i < size; i++) {
		max_ending_here = MAX(array[i],array[i]+max_ending_here);
		if (max_ending_here > max_so_far)
			max_so_far = max_ending_here;
	}
	return max_so_far;
}

int main(void) {
	int array[] = {-2, -3, 4, -1, -2, 1, 5, -3};

	std::cout << max_subarray_sum(array, SIZE(array)) << std::endl; 

	return 0;
}
