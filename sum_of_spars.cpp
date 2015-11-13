/*
 *  a sample for understanding spars_matrix
 *  in this sample we create a spars_matrix and after sort that we'll sum 2 spars_matrix
 *  our main goal is to show you a abstract view of spars_matrix
 *  author : Navid kalaei <navidkalaei@gmail.com>
 *  modified by : Milad nekooei <mi.nekooei@gmail.com>
 *  Date : 11 / 9 / 2015
 */

#include <iostream>

#define nDashes 15          // This Macro define for number of dashes in single line
#define columns 3           // all of spars_matrix have 3 columns

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

void print_matrix(struct Spars * spars_matrix){
    cout << "printing spars matrix!" << endl << endl;

    int nRows = spars_matrix->header[2];

    int i=0, j=0;

    for(i = 0; i < nRows; i++){
        for(j = 0; j < 3; j++){
            cout << spars_matrix->matrix[i][j] << '\t';
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


    spars_matrix.matrix = new int * [nRows];

    for(i = 0; i < nRows; i++){
        spars_matrix.matrix[i] = new int[columns];
    }

    // here we get other values from user
    // i is a counter that count rows of spars_matrix
    for (int i = 0 ; i < nRows ; i++){
        cout<<"please enter i : ";
        cin>>spars_matrix.matrix[i][0];
        cout<<"please enter j : ";
        cin>>spars_matrix.matrix[i][1];
        cout<<"please enter value : ";
        cin>>spars_matrix.matrix[i][2];
    }
    return spars_matrix;
}

void bubble_sort_matrix(struct Spars & spars_matrix){

    /*
     * gets a spars matrix, sort its matrix by X scale (spars_matrix[0])
     * nothing returns, it's call by refrence.
     */

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
}

int find_sharing (struct Spars matrix1 , struct Spars matrix2){
    int shared= 0;
    for (int i = 0 ; i < matrix1.header[2]; i++){
        for(int j = 0 ; j < matrix1.header[2] ; j++){
            if(matrix1.matrix[i][0] == matrix2.matrix[j][0]
            && matrix1.matrix[i][1] == matrix2.matrix[j][1]){
                shared +=1;
            }
        }
    }
    return shared;
}

bool CanISet(int i , int j,int len,struct Spars res){
    for(int k = 0 ; k < len ; k++){
        if(res.matrix[k][0] == i && res.matrix[k][1] == j){
            return false;
            }
    }
    return true;
}

void add_Spars (struct Spars operand1 , struct Spars operand2 , struct Spars & result){
//    struct Spars * result ;
    int shared ;
    if((operand1.header[0] == operand2.header[0])
        &&(operand1.header[1] == operand2.header[1])){
        //start initilizing and memory allocationg for result matrix
  //      result = new struct Spars();
        result.header[0] = operand1.header[0];
        result.header[1] = operand1.header[1];
        shared = find_sharing(operand1,operand2);
        cout<<"\n shared : "<<shared;
        int newCountValue = (operand1.header[2] + operand2.header[2]) - shared;
        cout<<"\n new count: "<<newCountValue;
        result.header[2] = newCountValue;

        result.matrix = new int * [newCountValue];
        for(int i = 0 ; i < newCountValue ; i++){
            result.matrix[i] = new int[columns];
        }
        // end of initilizing and memory allocationg

    }
}

int main(){
    int i, j;

    struct Spars spars_matrix1, spars_matrix2;

    spars_matrix1 = init_spars();
    spars_matrix2 = init_spars();

    bubble_sort_matrix(spars_matrix1);
    bubble_sort_matrix(spars_matrix2);
    struct Spars res;
    add_Spars(spars_matrix1,spars_matrix2,res);
    print_seperator();
    print_matrix(spars_matrix1);
    print_matrix(spars_matrix2);
    print_seperator();
    print_matrix(res);

    return 0;
}
