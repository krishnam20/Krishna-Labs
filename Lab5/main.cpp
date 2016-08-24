#include "Matrix.h"
using namespace std;


class IndexOutOfRangException: public exception{
  virtual const char * description () const throw (){
    return "The index is out of range";
  }
};
                                            //is it appropriate to define
                                            //exception in main or seperate file.

template
 <typename T>
void fillMatrix(Matrix <T> & m){
     int i, j;
     for (i = 0; i < m.numRows(); i++) {
         m[i][0] = T();
     }
     for (j = 0; j < m.numCols(); j++) {
         m[0][j] = T();
     }
     for (i = 1; i < m.numRows(); i++) {
         for (j = 1; j < m.numCols(); j++)
         {
             m[i][j] = T(i * j);
         }
     }
}
void test_int_matrix(){

 Matrix <int> m(10,5);
 fillMatrix(m);
 cout << m;
 // PUT YOUR TRY/CATCH HERE AND TEST EXCEPTIONS
    try{
          cout << "testing succesful index for int matrix" << endl;
          cout << endl << "m[4][4]        " << m[4][4] << endl;

          cout << "testing invalid index for int matrix" << endl;
          cout << <<endl << "m[15][15]    " << m[15][15] << endl;
     }
        catch(IndexOutOfRangException & exceptionClass){
          cout << "m[15][15] results in the following error " << exceptionClass.description() << endl;
          //cout or cerr here. Also where do you throw. Do you usually throw for if statements in the index method itself.
          //Does assert already handle that for you.
     }

}
void test_double_matrix(){

 Matrix <double> M(8,10);
 fillMatrix(M);
 cout << M;
 // PUT YOUR TRY/CATCH HERE AND TEST EXCEPTIONS
 try{
       cout << "testing succesful index for int matrix" << endl;
       cout << endl << "m[4][4]        " << m[4][4] << endl;

       cout << "testing invalid index for int matrix" << endl;
       cout << endl << "m[15][15]    " << m[15][15] << endl;
  }

    catch(IndexOutOfRangException & exceptionClass){
       cerr << "m[15][15] results in the following error " << exceptionClass.description() << endl;
  }

}
int main(){
 test_int_matrix();
 test_double_matrix();
 return 0;

};
