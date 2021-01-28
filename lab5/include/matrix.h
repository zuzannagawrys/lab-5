#include <iostream>
#include <fstream>

class Matrix{
public:
    //pola klasy
    double **macierz;
    int szerokosc, wysokosc;


    //Konstruktory
    Matrix(int x, int y);
    Matrix(int side);
    Matrix(std::string path);
    
    //Destruktor
    ~Matrix();


    //Przeciążenie operatorów
    Matrix* operator+(Matrix);
    Matrix* operator-(Matrix);
    Matrix* operator*(Matrix);
    friend std::ostream & operator<<(std::ostream &, const Matrix &);
    friend std::istream & operator>>(std::istream &, Matrix);
    double* operator[](int);
    bool operator==(Matrix);
    bool operator!=(Matrix);
    void operator++();
    void operator--();



    //Metody
    void print();
    void set(int x, int y, double value);
    double get(int x, int y);
    void add(Matrix m);
    void substract(Matrix m);
    Matrix* multiply(Matrix m);
    int cols();
    int rows();
    void store(std::string filename, std::string path);

};