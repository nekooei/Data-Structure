/*
 *  a sample for understanding spars_matrix
 *  in this sample we create a spars_matrix and after sort that we'll sum 2 spars_matrix
 *  our main goal is to show you a abstract view of spars_matrix
 *  author : Navid kalaei <navidkalaei@gmail.com>
 *  modified by : Milad nekooei <mi.nekooei@gmail.com>
 */

#include <iostream>

#define nDashes 15          // This Macro define for number of dashes in single line
#define columns 3          // all of spars_matrix have 3 columns

using namespace std;

// Here we are designing a sturcture for Spars_matrix
struct Spars {
    int header[3];          // This array is for Spars_matrix's header
    int ** matrix = NULL;   // This pointer-to-pointer is for content of spars_matrix and initialized with NULL
};

void print_seperator()
{
    int i = 0;
    cout << endl << endl;
    for(i = 0; i < nDashes; i++){
        cout << '-';
    }
    cout << endl << endl;
}

void print_matrix(struct Spars spars_matrix){

    cout << "printing spars matrix!" << endl << endl;

    int nRows = spars_matrix.header[2];

    int i=0, j=0;

    for(i = 0; i < nRows; i++){
        for(j = 0; j < 3; j++){
            cout << spars_matrix.matrix[i][j] << '\t';
        }
        cout << endl;
    }

    cout << endl << endl;
    cout << "matrix printed!";
    print_seperator();
}

struct Spars init_spars()
{
    cout << "initing spars matrix!" << endl << endl;
    struct Spars spars_matrix;
    int i=0, j=0;

    cout << "enter number of original rows: ";
    cin >> spars_matrix.header[0];

    cout << "enter number of original cols: ";
    cin >> spars_matrix.header[1];

    cout << "How many numbers are there? ";
    int nRows = 0;
    cin >> nRows;
    spars_matrix.header[2] = nRows;
    cout << endl;


    spars_matrix.matrix = new int * [nRows];

    for(i = 0; i < nRows; i++){
        spars_matrix.matrix[i] = new int[columns];
    }

    // here we get other values from user
    // i is a counter that count rows of spars_matrix
    for (int i = 0 ; i < nRows ; i++){
        cout << "please enter i : ";
        cin >> spars_matrix.matrix[i][0];
        cout << "please enter j : ";
        cin >> spars_matrix.matrix[i][1];
        cout << "please enter value : ";
        cin >> spars_matrix.matrix[i][2];
        cout << endl;
    }

    print_seperator();

    return spars_matrix;
}

void bubble_sort_matrix_helper(struct Spars & spars_matrix, string sort_by){

    /*
     * gets a spars matrix, sort its matrix by X scale (spars_matrix[0])
     * nothing returns, it's call by refrence.
     */

    int index = 0;
    if (sort_by == "row"){
        index = 0;
        cout << "Matrix is going to be sorted by row." << endl;
    }
    else if(sort_by == "col"){
        index = 1;
        cout << "Matrix is going to be sorted by column." << endl;
    }
    else{
        cout << "Sort Option Error: 2D matrises can only be sorted by row or column" << endl;
        index = 0;
        cout << "Matrises are going to be sorted by row";
    }

    int nRows = spars_matrix.header[2];

    int i, j;
    int  * temp; // = new int[nCols]; //to store rows

    for(i = 0; i < nRows; i++){
        for(j = 0; j < nRows - i -1; j++){
            if(spars_matrix.matrix[j][index] > spars_matrix.matrix[j+1][index]){
                temp = spars_matrix.matrix[j];
                spars_matrix.matrix[j] = spars_matrix.matrix[j+1];
                spars_matrix.matrix[j+1] = temp;
            }
        }
    }

    cout << "Sorting finised" << endl;
    cout << endl;
}


void bubble_sort_matrix(struct Spars & spars_matrix)
{
    cout << "Sorting Matrix!" << endl << endl;
    bubble_sort_matrix_helper(spars_matrix, "col");
    bubble_sort_matrix_helper(spars_matrix, "row");
    cout << "Matrix sorted by column and row." << endl;
    print_seperator();
}

bool are_same_points(int * cordinate1, int * cordinate2){
    if((cordinate1[0] == cordinate2[0]) and
       (cordinate1[1] == cordinate2[1])){
       return true;
       }
    return false;
}
/*
int get_sharing_len(struct Spars matrix1, struct Spars matrix2)
{
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
*/

int main(){

    struct Spars spars_matrix1, spars_matrix2;

    spars_matrix1 = init_spars();
    print_matrix(spars_matrix1);

    spars_matrix2 = init_spars();
    print_matrix(spars_matrix2);

    bubble_sort_matrix(spars_matrix1);
    print_matrix(spars_matrix1);
    bubble_sort_matrix(spars_matrix2);
    print_matrix(spars_matrix2);
    print_seperator();


    return 0;
}
