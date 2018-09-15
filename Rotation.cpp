#include <fstream>
#include <iostream>
#include <stdio.h>


using namespace std;

/*
Function: 
        Name: Print Matrix
        Purpose: Prints out matrix in matrix notation
        Arguments:  int matrix[][]  - 2D matrix
                    int m           - # of rows in the matrix 
                    int n           - # of columns in the matrix
*/
void printMatrix(int matrix[][4], int m, int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
}

/*
Function: 
        Name: Peel Matrix 
        Purpose: Peels outer layer of 2D matrix and puts it into a 1D array
        Arguments:  int matrix[][]  - 2D matrix
                    int matrow      - # of rows in the matrix 
                    int matcol      - # of columns in the matrix
                    int peel        - peel count
*/
void PeelMatrix(int mat[][4], int matrow, int matcol, int peel)
{
    int flag = 0;
    int i, j;
    i = j = peel - 1;

                cout<<"\nIndex: "<<peel<<"| i = "<<i<<"| j = "<<j<<"|";
                cout<<"\nMatrix Row: "<<matrow<<"| Matrix Comumn: "<<matcol;
                int indexi = i;
                int indexj = j;
                int vali = i;
                int valj = j;
                int m = matrow; //Boundary placeholders. Updated after each peeling
                int n = matcol; 
                int peelarray[50];
                int k=0;
                
                    cout<<"TEST: "<<valj<<" "<<n-1<<"\n";
                    if(valj == n-1)
                    {
                        peelarray[k] = mat[vali][valj];
                        cout<<"Peel #"<<peel<<": "<<mat[vali][valj];
                        return;
                    }

                    cout<<"\nBegin Peeling: \n";
                    cout<<"\t1: Going Top-Left -> Top-Right\n";
                    while( valj < n-1 )                              //Index Corner
                    {
                        cout<<"Yes";
                        peelarray[k] = mat[vali][valj];
                        valj++;
                        k++;
                    }
                
                    cout<<"\t2: Going Top-Right -> Bottom-Right\n";
                    while( vali < m-1 )
                    {
                        peelarray[k] = mat[vali][valj];
                        vali++;
                        k++;
                    }
            
                    cout<<"\t3: Going Bottom-Right -> Bottom-Left\n";
                    while(valj>indexj)
                    {
                        peelarray[k] = mat[vali][valj];
                        valj--;
                        k++;
                    }


                    cout<<"\t4: Going Bottom-Left -> Top-Left\n";
                    while(vali>indexi) //Not equal to  0 as we dont want he first element again
                    {
                        peelarray[k] = mat[vali][valj];
                        vali--;
                        k++;
                    }


                //Display The Peel
                cout<<"Peel #"<<peel<<": ";
                for(int x=0;x<k;x++)
                {
                    cout<<peelarray[x]<<",";
                }
                cout<<" !\n";
                flag=1;
                //break; 
                if(matrow!=peel)
                {
                    cout<<"\n\tPeeler";
                    PeelMatrix(mat,matrow-1,matcol-1,peel+1);
                }
}

int ReadMatrix()
{
    int m,n;
    int mat[4][4];
    ifstream fopen("Input.txt");
    fopen >> m >> n;

    if ((m != 4) || (n != 3))
    {
            
        return 1;
    }

    for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++)
    fopen >> mat[i][j];
    printMatrix(mat,m,n);
}
/*
MAIN Function: 
        Purpose: Initializes two matrices and calls the recursive function PeelMatrix     
*/
int main()
{

    int mat[3][3] = { { 11,12,13 },
                      { 21,22,23 },
                      { 31,32,33 } };

    int mat2[4][4] = { { 11,12,13,14 },
                       { 21,22,23,24 },
                       { 31,32,33,34 },
                       { 41,42,43,44 } };

    int matrow = 3;
    int matcol = 3;

    cout<<"\n MATRIX 3x3 \n";    
    cout<<"\n MATRIX 4x4 \n";    
    printMatrix(mat2,4,4);

    PeelMatrix(mat2, 4, 4,1);

    

    return 0;
}

