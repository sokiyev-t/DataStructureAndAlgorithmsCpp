#include <iostream>
#include <vector>
using namespace std;

int area_size(int w, int h)
{
    if (h > w)
    {
        int temp = w;
        w = h;
        h = temp;
    }

    while (w % h != 0)
    {
        int temp = w % h;
        w = h;
        h = temp;
    }
    return h;
}

int array_sum(vector<int> a)
{
    int sum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];
    }
    return sum;
}

int array_sum_rec(vector<int> a, int n)
{
    if (n == 0)
    {
        return 0;
    }
    return a[n - 1] + array_sum_rec(a, n - 1);
}

vector<int> quick_sort(vector<int> a)
{
    if (a.size() <= 1)
    {
        return a;
    }

    int pivot = a[a.size() / 2];
    vector<int> left;
    vector<int> right;
    vector<int> equal;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < pivot)
        {
            left.push_back(a[i]);
        }
        else if (a[i] == pivot)
        {
            equal.push_back(a[i]);
        }
        else
        {
            right.push_back(a[i]);
        }
    }

    vector<int> result;
    vector<int> left_sorted = quick_sort(left);
    vector<int> right_sorted = quick_sort(right);

    result.insert(result.end(), left_sorted.begin(), left_sorted.end());
    result.insert(result.end(), equal.begin(), equal.end());
    result.insert(result.end(), right_sorted.begin(), right_sorted.end());

    return result;
}

int main()
{
    //====Алгоритм разделяй и властвуй====
    // int result = area_size(640, 1680);
    // cout << "Result: " << result << std::endl;

    //====Алгоритм нахождения суммы элементов массива рекурсивно====
    // vector<int> a = {1, 2, 3, 4, 5};
    // int result = array_sum_rec(a, a.size());
    // cout << "Result: " << result << endl;
    //====Алгоритм быстрой сортировки====
    vector<int> a = {15, 23, 3, 23, 5, 4, 23};
    vector<int> result = quick_sort(a);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}