#include "Array.h"
using namespace std;


template <class Element>

class Matrix
{
private:
 int rows, cols;
 Array<Array<Element> *> m;         //this means m is an Array of Array Pointers containing whatever type is
                                    //passed in as Element
                                    // define m as an Array of Array pointers using the
                                    // template you defined above
public:
 Matrix(int newRows, int newCols)
    : rows(newRows), cols(newCols), m(rows){
        for (int i = 0; i < rows; i++){
            m[i] = new Array <Element>(cols);
        }
}
 int numRows(){
     return rows;
 }
 int numCols(){
     return cols;
 }
 Array <Element> & operator [] (int row){
                                            //do we do exception here like if row > this->rows
                                            //or can we just say row > rows, raise IndexOutOfRangException
                                            //raise Error or is that all done in the try in the main.
     return * m[row];
 }
 void print(ostream & out){
 // You can write this one too, but use the Array::operator<<
 //let array print handle printing out each array while you for loop through it

    int i = 0;
    while (i< rows){                        //if rows = 5. There are indexes 0-4 holding arrays.
        cout << m[i] << endl;               //cout array indexes from 0-4
        ++i;
                                            //out << m;
    }

 friend ostream & operator << (ostream & out, Matrix & m){
     m.print(out);
     return out;
    }

~Matrix(){
    for (int i = 0; i < rows; i++){                 //for loop through matrix
        delete m[i];                                //each array in the matrix gets deleted. m[i] gives you the array at the index i
    }
    delete []m;                                     //delete the array container itself. Is this alone sufficient.
    delete *m;                                      //delete the memory m points 2. Not sure if same as previous step.
 }

};
