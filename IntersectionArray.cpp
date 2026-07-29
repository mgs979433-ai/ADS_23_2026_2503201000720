#include <iostream>
using namespace std;

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {2, 4, 5, 6, 8};

    int n1 = 5, n2 = 5;
    int i = 0, j = 0;

    cout << "Intersection: ";

    while (i < n1 && j < n2)
    {
        if (arr1[i] == arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return 0;
}