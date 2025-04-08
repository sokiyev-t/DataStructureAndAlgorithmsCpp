#include <iostream>

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// int factorial(int n)
// {
//     if (n == 0)
//     {
//         return 1;
//     }
//     return n * factorial(n - 1);
// }

// int main()
// {
//     int n = 5;
//     std::cout << "Factorial of " << n << " is " << factorial(n) << std::endl;
//     return 0;
// }