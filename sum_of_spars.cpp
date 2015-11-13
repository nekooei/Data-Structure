#include <iostream>

using namespace std;

struct Spars {
    int header[3];
    int ** matrix = NULL;
};

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

    cout << "enter number of original rows: " << endl;
    cin >> spars_matrix.header[0];
    cout << endl;

    cout << "enter number of original cols: " << endl;
    cin >> spars_matrix.header[1];
    cout << endl;

    cout << "How many numbers are there? " << endl;

    int nRows = 0;
    cin >> nRows;
    spars_matrix.header[2] = nRows;
    cout << endl;

    int nCols = 3;

    spars_matrix.matrix = new int * [nRows];

    for(i = 0; i < nRows; i++){
        spars_matrix.matrix[i] = new int[nCols];
    }
    //could be a sprated function{
    cout << "Enter matrix: " << endl;
    for(i = 0; i < nRows; i++){
        for(j = 0; j < nCols; j++){
            cin >> spars_matrix.matrix[i][j];
        }
    }
    //}
    cout << endl << endl;
    cout << "matrix inited!";
    print_seperator();

    print_matrix(spars_matrix);

    return spars_matrix;
}

void bubble_sort_matrix(struct Spars spars_matrix){
    /*
     * gets a spars matrix, sort its matrix by X scale (spars_matrix[0])
     * nothing returns, it's call by refrence.
     */

    cout << "sorting spars matrises by X (i) scale!" << endl << endl;

    int nRows = spars_matrix.header[2];
    int nCols = 3;  //for being spars;

    int i, j;
    int  * temp; // = new int[nCols]; //to store rows

    for(i = 0; i < nRows; i++){
        for(j = 0; j < nRows - i -1; j++){
            if(spars_matrix.matrix[j][0] > spars_matrix.matrix[j+1][0]){
                temp = spars_matrix.matrix[j];
                spars_matrix.matrix[j] = spars_matrix.matrix[j+1];
                spars_matrix.matrix[j+1] = temp;
            }
        }
    }

    cout << endl << endl;
    cout << "matrix sorted by X scale!";
    print_seperator();
}

int main()
{
    int i, j;

    struct Spars spars_matrix1, spars_matrix2;

    spars_matrix1 = init_spars();
    //spars_matrix2 = init_spars();

    bubble_sort_matrix(spars_matrix1);
    print_matrix(spars_matrix1);


    return 0;
}
