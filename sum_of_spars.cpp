/*
 *  a sample for understanding spars_matrix
 *  in this sample we create a spars_matrix and after sort that we'll sum 2 spars_matrix
 *  our main goal is to show you a abstract view of spars_matrix
 *  author : Navid kalaei <navidkalaei@gmail.com>
 *  modified by : Milad nekooei <mi.nekooei@gmail.com>
 */

#include <iostream>
#define nDashes 15          // This Macro define for number of dashes in single line
///milad columns ma'ni sotoon ha mide dar soorati k inja karbordesh te'dade setoon hast.  pishnahade man ine bezari nCols.  agar editaye badish ham anjam bedi mamnoon misham
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
    cout << "nRows : " << nRows << endl;
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

void bubble_sort_matrix_helper(struct Spars spars_matrix, string sort_by){

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


void bubble_sort_matrix(struct Spars spars_matrix)
{
    cout << "Sorting Matrix!" << endl << endl;
    bubble_sort_matrix_helper(spars_matrix, "col");
    bubble_sort_matrix_helper(spars_matrix, "row");
    cout << "Matrix sorted by column and row." << endl;
    print_seperator();
}

int cmp_coordinates(int * coordinate1, int * coordinate2)
{
    //if coordinate1 < coordinate2 : return -1
    //else if coordinate2 < coordinate1 : return 1
    //else : return 0
    if(coordinate1[0] < coordinate2[0]){
        return -1;
    }
    else if(coordinate2[0] < coordinate1[0]){
        return 1;
    }
    else{
        if(coordinate1[1] < coordinate2[1]){
            return -1;
        }
        else if(coordinate2[1] < coordinate1[1]){
            return 1;
        }
        else{
            return 0;
        }
    }
}

int get_shared_len(struct Spars spars_matrix1, struct Spars spars_matrix2)
{
    int shared_len = 0;
    int i = 0, j = 0;
    int cmp = 0;

    while((i < spars_matrix1.header[2]) and (j < spars_matrix2.header[2])){
        cmp = cmp_coordinates(spars_matrix1.matrix[i], spars_matrix2.matrix[j]);
        if(cmp == -1){
            i++;
        }
        else if(cmp == 1){
            j++;
        }
        else{
            i++;
            j++;
            shared_len++;
        }
    }

    return shared_len;
}

void copy_coordinate(int * src, int * dest)
{
    dest[0] =  src[0];
    dest[1] =  src[1];
    dest[2] =  src[2];
}

struct Spars add_spars(struct Spars spars_matrix1, struct Spars spars_matrix2)
{
    bubble_sort_matrix(spars_matrix1);
    print_matrix(spars_matrix1);
    bubble_sort_matrix(spars_matrix2);
    print_matrix(spars_matrix2);

    struct Spars SOSpars;   //sum of spars.

    if((spars_matrix1.header[0] != spars_matrix2.header[0]) or (spars_matrix1.header[1] != spars_matrix2.header[1])){
        cout << "Input Error: The matrises are not in the same size.";
        exit(0);
    }

    SOSpars.header[0] = spars_matrix1.header[0];
    SOSpars.header[1] = spars_matrix1.header[1];
    int shared_len = get_shared_len(spars_matrix1, spars_matrix2);
    //cout << "Shared len is: " << shared_len << endl;
    int nRows = spars_matrix1.header[2] + spars_matrix2.header[2] - shared_len;
    SOSpars.header[2] = nRows;
    SOSpars.matrix = new int * [nRows];
    //cout << "nRows is: " << nRows << endl;
    int i = 0, j = 0, k = 0;
    int cmp = 0;

    /*
    inja ya bayad yek satre inf be akhare marisi k zoodtar tamoom mishe ezafe beshe dar python in kar ba l.append('inf') anjam mishe
    amma dar c++ agar bekhaym hamcin kari konim az paye code be ham mirize
    in ghat'e code ro negah dashtim ta motevajehe eshtebah beshin
    va bebinin k vaghti mikhayn ba yek zaban code bezanin bayad dar hamoon zaban fekr konin!

    for(k = 0; k != nRows; k++){
        SOSpars.matrix[k] = new int * [3];
        cmp = cmp_coordinates(spars_matrix1.matrix[i], spars_matrix2.matrix[j]);
        if(cmp == -1){
            copy_coordinate(spars_matrix1.matrix[i],SOSpars.matrix[k]);
            i++;
        }
        else if(cmp == 1){
            copy_coordinate(spars_matrix2.matrix[j],SOSpars.matrix[k]);
            j++;
        }
        else{
            copy_coordinate(spars_matrix1.matrix[i],SOSpars.matrix[k]);
            SOSpars.matrix[k][2] += spars_matrix2.matrix[j][2];
            i++;
            j++;
        }
    }
    */

    while((i < spars_matrix1.header[2]) and (j < spars_matrix2.header[2])){
        //cout << "we are in while" << endl;
        SOSpars.matrix[k] = new int [columns];
        cmp = cmp_coordinates(spars_matrix1.matrix[i], spars_matrix2.matrix[j]);
        cout << i << ' ' << j << ' ' << k << endl;
        if(cmp == -1){
            copy_coordinate(spars_matrix1.matrix[i],SOSpars.matrix[k]);
            i++;
        }
        else if(cmp == 1){
            copy_coordinate(spars_matrix2.matrix[j],SOSpars.matrix[k]);
            j++;
        }
        else{
            copy_coordinate(spars_matrix1.matrix[i],SOSpars.matrix[k]);
            SOSpars.matrix[k][2] += spars_matrix2.matrix[j][2];
            i++;
            j++;
        }
        k++;
    }

    while(i < spars_matrix1.header[2]){
        SOSpars.matrix[k] = new int [columns];
        copy_coordinate(spars_matrix1.matrix[i],SOSpars.matrix[k]);
        i++;
        k++;
    }

    while(j < spars_matrix2.header[2]){
        SOSpars.matrix[k] = new int [columns];
        copy_coordinate(spars_matrix2.matrix[j],SOSpars.matrix[k]);
        j++;
        k++;
    }

    //cout << SOSpars.matrix[k-1][0] << ' ' << SOSpars.matrix[k-1][1] << ' ' << SOSpars.matrix[k-1][2] << endl;

    //print_matrix(SOSpars);
    return SOSpars;
}

int main(){

    struct Spars spars_matrix1, spars_matrix2;

    spars_matrix1 = init_spars();
    print_matrix(spars_matrix1);

    spars_matrix2 = init_spars();
    print_matrix(spars_matrix2);

    struct Spars SOSpars = add_spars(spars_matrix1, spars_matrix2);
    print_matrix(SOSpars);

    return 0;
}
