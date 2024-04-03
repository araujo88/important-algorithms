#include <iostream>

#define LENGTH(array) (sizeof(array) / sizeof(*(array)))

bool binary_search(int *array, unsigned int size, int target)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (array[mid] == target)
            return true;
        if (array[mid] > target)
            high = mid - 1;
        if (array[mid] < target)
            low = mid + 1;
    }
    return false;
}

int main(void)
{
    int array[] = {2, 3, 4, 8, 10, 15, 18};

    std::cout << binary_search(array, LENGTH(array), 8) << std::endl;
    std::cout << binary_search(array, LENGTH(array), 42) << std::endl;

    return 0;
}