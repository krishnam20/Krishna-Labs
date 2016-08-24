#include <cassert>
#include <iomanip>
#include <stdio.h>
#include <assert.h>
#include <exception>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

template <class type>
class Array{
private:
 int len;
 type * buf;

public:
 Array(int newLen)
    :len(newLen), buf(new type[newLen]){}

 Array(const Array & l)
    :len(l.len), buf(new type[l.len])
    {
        for (int i = 0; i < l.len; i++) {
            //same as *buf = *l.buf; ++buf; ++l.buf;
            // same as *buf[i] = *l.buf[i]
            //or just use buf[i] = l.buf[i]
            *buf[i] = l.*buf[i]; // note this is incorrect for pointers
        }
    }
 int length(){
     return len;
 }
 type & operator [] (int i){
     assert(0 <= i && i < len);     //I'm assuming this will immediately exit out
                                    //if exception is raised.
                                    //otherwise should I just assign to variable and call if
     return buf[i];
 }
 void print(ostream & out){
     for (int i = 0; i < len; i++) {
         out << setw(8) << setprecision(2) << fixed << right << buf[i];
     }
         // #include <iomanip>
 }
 friend ostream & operator << (ostream & out, Array & a){
     a.print(out);
     return out;
 }
 friend ostream & operator << (ostream & out, Array * ap){
     ap->print(out);
     return out;
 }

 ~Array(){
    for (int i = 0; i < len; i++){
        delete buf[i];
    }
    delete []buf;
 }

};
