#include <iostream>
#include <string>
#include "../include/matrix.h"

int main()
{
    Matrix mx(2);
    double x = 0.5;
        mx.set(1,1,++x); mx.set(1,2,++x); mx.set(2,1,++x); mx.set(2,2,++x);

    std::cout<<"\nCreating matrix mx, and dumping its data to .txt file\n";
    std::string filename="Mtrx.txt";
    std::ofstream file_output;
    file_output.open(filename);
    file_output << mx;

    // operator <<
    //druga.store(filename,path);
    std::cout<<"\nInitiating matrix 'my' with retrieved data from file\n";
    Matrix my("Mtrx.txt");
    my.print();

    
    Matrix m1(3,4);
    Matrix m2(3,4);
    Matrix m3(3,4);
    Matrix m4(4,3);
        m1.set (1,1,34.5); m1.set (1,2,34.5); m1.set (2,3,34.5);
        m2.set(1,2,20.5); m2.set(2,2,0.33); m2.set(1,1,4.5); m2.set(3,3,1.5);
        m4.set(1,2,20.5); m4.set(2,2,0.33); m4.set(1,1,4.5); m4.set(3,3,1.5);
    
    std::cout<<"Matrix m2, Matrix m1\n";
    m2.print();
    m1.print();
    std::cout<<"\n\nMatrix m2 plus m1 is equal:\n";
    Matrix * pnt_add = m1 + m2;
    pnt_add->print();

    std::cout<<"Matrix m2, Matrix m1\n";
    m2.print();
    m1.print();
    std::cout<<"\n\nMatrix m2 minus m1 is equal:\n";
    Matrix * pnt_subs = m2 - m1;
    pnt_subs->print();

    std::cout<<"Matrix m2, Matrix m1\n";
    m2.print();
    m1.print();
    std::cout<<"\n\nMatrix m2 times m4 is equal:\n";
    Matrix * pnt_mult = m2 * m4;
    pnt_mult->print();

    std::cout<<"\n\nm1 print()";
    m1.print();
    ++m1;
    std::cout<<"\n\nm1 print(), after ++m1";
    m1.print();
    --m1;
    std::cout<<"\n\nm1 print(), after --m1";
    m1.print();

    Matrix small_matrix(2);
    std::cout<<"\nWritting data to 2x2 Matrix using '<<'\n";
    std::cin>>small_matrix;
    std::cout<<"\nsmall_matrix.ptrint()\n";
    small_matrix.print();

    std::cout<<"\nPrinting small_matrix element with '[]'\n";
    std::cout<<small_matrix[1][1]<<std::endl;

    std::cout<<"\nComparing two equal matrixes, using '==' and '!='\n";
    Matrix mm1(1), mm2(1);
    std::cout<<"\nmm1 equals mm2: "<< (mm1 == mm2) <<"\n";
    std::cout<<"\nmm1 not equals mm2: "<< (mm1 != mm2) <<"\n";

    

    system("PAUSE");
    
    return 0;
}
