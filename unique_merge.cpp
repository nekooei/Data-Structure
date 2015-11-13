#include <iostream>
#include "bubble_sort.h"
#include <tuple>
using namespace std;


void print_seperator()
{
    int i = 0;
    int nDashes = 15;

    cout << endl << endl;
    for(i = 0; i < nDashes; i++){
        cout << '-';
    }
    cout << endl << endl;
}

void print_list(int * arr, int arr_len)
{
    int i = 0;

    for(i = 0; i < arr_len; i++){
        cout << arr[i] << ' ';
    }

    print_seperator();
}

int * get_copy(int * arr, int arr_len)
{
    int * copied_arr = new int[arr_len];

    int i = 0;

    for(i = 0; i < arr_len; i++){
        copied_arr[i] = arr[i];
    }

    return copied_arr;
}

int get_sharing_len(int * arr1, int arr1_len, int * arr2, int arr2_len)
{
    int * arr1_copy = get_copy(arr1, arr1_len);
    int * arr2_copy = get_copy(arr2, arr2_len);

    bubble_sort(arr1_copy, arr1_len);
    bubble_sort(arr2_copy, arr2_len);

    int sharing_len = 0;
    int i = 0, j = 0;

    while((i < arr1_len) or (j < arr2_len)){
        if(arr1_copy[i] < arr2_copy[j]){
            i++;
        }
        else if(arr2_copy[j] < arr1_copy[i]){
            j++;
        }
        else {
            i++;
            j++;
            sharing_len++;
        }
    }

    return sharing_len;
}

tuple <int *, int> unique_merge(int * arr1, int arr1_len, int * arr2, int arr2_len)
{
    int sharing_len = get_sharing_len(arr1, arr1_len, arr2, arr2_len);
    int merged_arr_len = arr1_len+arr2_len-sharing_len;
    int * merged_arr = new int [merged_arr_len];

    int * arr1_copy = get_copy(arr1, arr1_len);
    int * arr2_copy = get_copy(arr2, arr2_len);

    bubble_sort(arr1_copy, arr1_len);
    bubble_sort(arr2_copy, arr2_len);

    int i = 0, j = 0, k = 0;
    while((i < arr1_len) or (j < arr2_len)){
        if(arr1_copy[i] < arr2_copy[j]){
            merged_arr[k] = arr1_copy[i];
            i++;
        }
        else if(arr2_copy[j] < arr1_copy[i]){
            merged_arr[k] = arr2_copy[j];
            j++;
        }
        else {
            merged_arr[k] = arr1_copy[i];
            i++;
            j++;
            sharing_len++;
        }
        k++;
    }

    return make_tuple(merged_arr, merged_arr_len);
}


int main()
{
    int nLists = 1;
    int i=0;


    int arr1[] = {20, 16, 13, 5, 12, 3, 2, 11, 6, 17};
    int arr1_len = 10;
    int arr2[] = {9, 1, 8, 16, 19, 20, 13, 14, 18, 4};
    int arr2_len = 10;


    cout << "#" << nLists++ << " list is: " << endl;
    print_list(arr1, arr1_len);

    cout << "#" << nLists++ << " list is: " << endl;
    print_list(arr2, arr2_len);


    auto merged_tuple = unique_merge(arr1, arr1_len, arr2, arr2_len);
    int * merged_arr = get<0>(merged_tuple);
    int merged_arr_len = get<1>(merged_tuple);

    print_list(merged_arr, merged_arr_len);

    return 0;
}
