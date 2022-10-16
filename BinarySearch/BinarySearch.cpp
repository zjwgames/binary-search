// BinarySearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
#include <ctime>

// Linear search in O(N) time
int linear_search(int data[], int x, const int size) {
    int index = -1;

    for (int i = 0; i < size; i++) {
        if (x == data[i]) {
            index = i;
            break;
        }
    }

    return index;
}

// Assume elements of array are comparable and you are provided a sort function.
// Binary search in O(log N) time
int binary_search(int data[], int x, const int size, int start, int end) {
    int index = -1;
    const int midpoint = (int)round( (end - start) / 2) + start;

    if (x == data[midpoint]) {
        return midpoint;
    }
    else if (x < data[midpoint] && end != midpoint) {
        end = midpoint;
        binary_search(data, x, midpoint, start, end);
    }
    else if (x > data[midpoint] && start != midpoint) {
        start = midpoint;
        binary_search(data, x, end - start, start, end);
    }
    else {
        return index;
    }
}

int main()
{
    std::cout << "BinarySearch\n";

    const int N = 20;

    int data[N]{
        1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20
    };

    int x = 20;

    // Linear search

    int indexFoundLinear = linear_search(data, x, N);

    std::cout << "indexFoundLinear: " << indexFoundLinear << std::endl;

    // Binary search

    int indexFoundBinary = binary_search(data, x, N, 0, N);

    std::cout << "indexFoundBinary: " << indexFoundBinary << std::endl;

    return 0;
}
