#include <iostream>
using namespace std;

void bubble_sort(int arr[], int size_of_array)
{
    int i, j;
    int temp;

    for(i = 0; i < size_of_array; i++){
        for(j = 0; j < size_of_array - i -1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


int main()
{
    int i=0;

    int arr[] = {4, 1, 3, 2, 4, 0};

    bubble_sort(arr, 6);

    for(i = 0; i < 6; i++){
        cout << arr[i] << ' ';
    }

    return 0;
}

