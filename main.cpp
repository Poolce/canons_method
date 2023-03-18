#include <vector>
#include <iostream>
#include "main.h"

using std::cout;

Matrix seqKannonMethod(Matrix& a, Matrix& b){
    int size = a.size;

    Matrix c(size);
    a.leftInitialise();
    b.upInitialise();

    for(int k = 0; k < size;k++){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                c.data.at(i).at(j) += a.data.at(i).at(j)*b.data.at(i).at(j);
            }
        }
        a.moveRight();
        b.moveUp();
    }
    return c;
}



int main(){
    Matrix a(5), b(5);

    a.randomize();
    // a.out();
    // a.transponse();
    // a.out();
    b.randomize();
    a.out();
    b.out();
    std::cout<<"____________________________________________\n";
    Matrix d = a*b;
    d.out();
    std::cout<<"____________________________________________\n";
    Matrix c = seqKannonMethod(a,b);
    c.out();
}
