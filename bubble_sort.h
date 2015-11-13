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
