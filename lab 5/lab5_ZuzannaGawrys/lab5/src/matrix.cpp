#include <iostream>
#include <string>
#include "..\include\matrix.h"

using namespace std;

Matrix::Matrix(int y, int x)
{
    try
    {
        if ( x < 1 )
            throw 1;
        if ( y < 2)
            throw 2;
    
    macierz = new double * [y];
    szerokosc=x;
    wysokosc=y;
    for (int i=0; i<y; i++)
        macierz[i] = new double [x];

    for (int i=0; i<y; i++)
        for(int j=0; j<x; j++)
            macierz[i][j]=0;
    }
    catch(int e)
    {   cout<<"Error: "<<e<<endl;
        if (e==1)
            cout << "Wysokosc musi byc wieksza od zera\n";
        if (e==2)
            cout << "Szerokosc musi byc wieksza od zera\n";
        exit (1);
    }

}

Matrix::Matrix(int x)
{
    try
    {
        if ( x <1 )
            throw "Poddany bok musi byc wiekszy od zera\n";
    
    macierz = new double * [x];
    szerokosc = wysokosc = x;
    for (int i=0; i<x; i++)
        macierz[i] = new double [x];

    for (int i=0; i<x; i++)
        for(int j=0; j<x; j++)
            macierz[i][j]=0;
    
    }
    catch(const char *err)
    {
        cout<<"Error: "<<endl;
        cout<<err;
        exit (1);
    }
    
}

Matrix::Matrix(string path)
{
    try
    {
        std::ifstream file;
        file.open (path);

        if(!file.is_open())
            throw "File error";

        string x,y;
        getline (file,x);    getline (file,y);

        szerokosc = std::stoi(x);   wysokosc = std::stoi(y);
        if (szerokosc <1 || wysokosc<1)
                throw 1;

        //Inicializacja tabeli dynamicznej
        macierz = new double * [wysokosc];
        for (int i=0; i < wysokosc ; i++)
            macierz[i] = new double [szerokosc];


        //Przypisywanie wartosci z pliku
        for (int i=0; i<wysokosc ; i++)
           for (int j=0; j<szerokosc && getline(file, x); j++)
            {
                //cout <<x<<" "<<stod(x)<<"\t"<<macierz[i][j]<<"\n";
                macierz[i][j] = std::stod(x);
            }

        file.close();
        
    }
    catch (const char * err)
    {
        cout<<"Error: "<< err << endl;
        cout<<"Nie udalo sie otworzyc plik\n";
        exit (1);
    }
    catch (int err)
    {
        cout<<"Error: "<< endl;
        cout<<"Niepoprawne rozmiary macierzy\n";
        exit (1);
    }

}
Matrix::~Matrix()
{
    for (int i=0; i<wysokosc; i++)
        delete macierz[i];
    delete macierz;
}

Matrix* Matrix::operator+(Matrix m)
{
    Matrix * pnt = new Matrix(wysokosc, szerokosc);

    for (int i=0; i<wysokosc; i++)
        {
            for(int j=0; j<szerokosc; j++)
                pnt->macierz[i][j] = macierz[i][j] + m.macierz[i][j];
        }
    return pnt;
}

Matrix* Matrix::operator-(Matrix m)
{
    Matrix * pnt = new Matrix(wysokosc, szerokosc);

    for (int i=0; i<wysokosc; i++)
        {
            for(int j=0; j<szerokosc; j++)
                pnt->macierz[i][j] = macierz[i][j] - m.macierz[i][j];
        }
    return pnt;
}

Matrix* Matrix::operator*(Matrix m)
{
     Matrix * pnt = new Matrix(wysokosc, m.szerokosc);
        double s=0.0;
        for (int i=0; i<wysokosc; i++)
        {
            for(int j=0; j<m.szerokosc; j++)
            {   s=0.0;
                for(int k=0; k<szerokosc; k++)
                {
                    s += macierz[i][k]*m.macierz[k][j];
                }
                pnt->macierz[i][j]=s;
            }

        }
        return pnt;
}

std::ostream & operator<<(ostream &output, const Matrix &m)
{
    output << m.szerokosc <<std::endl<< m.wysokosc;
    for (int i=0; i < m.wysokosc; i++)
    {
        for (int j=0; j < m.szerokosc; j++)
            output<<std::endl<<m.macierz[i][j];
    }

    return output<<std::endl;
}

std::istream & operator>>(istream &input, Matrix m)
{
    for (int i=0; i < m.wysokosc; i++)
    {
        for (int j=0; j < m.szerokosc; j++)
            input>>m.macierz[i][j];
    }

    return input;
}

double Matrix::operator[](int i)
{
    return *macierz[i];
}
bool Matrix::operator==(Matrix m)
{
    if (!(szerokosc == m.szerokosc && wysokosc == m.wysokosc ))
        return 0;
    else
    {
        for(int i=0; i < wysokosc ; i++)
        {
            for (int j=0; j < szerokosc ; j++)
                if (macierz[i][j] != m.macierz[i][j])
                    return 0;
        }
    }
    return 1;
}

bool Matrix::operator!=(Matrix m)
{
    if (!(szerokosc == m.szerokosc && wysokosc == m.wysokosc ))
        return 1;
    else
    {
        for(int i=0; i < wysokosc ; i++)
        {
            for (int j=0; j < szerokosc ; j++)
                if (macierz[i][j] != m.macierz[i][j])
                    return 1;
        }
    }
    return 0;
}

void Matrix::operator++()
{
    for(int i=0; i < wysokosc ; i++)
        {
            for (int j=0; j < szerokosc ; j++)
                (macierz[i][j])++;
        }
}
void Matrix::operator--()
{
    for(int i=0; i < wysokosc ; i++)
        {
            for (int j=0; j < szerokosc ; j++)
                (macierz[i][j])--;
        }
}


void Matrix::print()
{
    cout<<"Printing matrix ("<<szerokosc<<","<<wysokosc<<"):"<<endl;
    for (int i=0; i<wysokosc; i++)
    {
        for(int j=0; j<szerokosc; j++)
            cout<<macierz[i][j]<<"\t";
        cout<<endl;
    }
}

void Matrix::set(int x, int y, double value)
{
    try
    {
        if (x > szerokosc+1 || x < 1)
            throw 1;
        if (y > wysokosc+1 || y < 1)
            throw 2;
        macierz[x-1][y-1] = value;
    }
    catch(int err)
    {
        cout<<"Error: "<<err<<endl;
        if (err==1)
            cout << "Niepoprawna wartosc x\n";
        if (err==2)
            cout << "Niepoprawna wartosc y\n";
        exit (1);
    }
    
    
}

double Matrix::get(int x, int y)
{
    try
    {
        if (x > szerokosc+1 || x < 1)
            throw 1;
        if (y > wysokosc+1 || y < 1)
            throw 2;
        return macierz[x-1][y-1];
    }
    catch(int err)
    {
        cout<<"Error: "<<err<<endl;
        if (err==1)
            cout << "Niepoprawna wartosc x\n";
        if (err==2)
            cout << "Niepoprawna wartosc y\n";
        return 0;
    }
    
}

void Matrix::add(Matrix m)
{
    try
    {
        if (m.wysokosc != wysokosc || m.szerokosc != szerokosc)
            throw 1;
        
         for (int i=0; i<wysokosc; i++)
        {
            for(int j=0; j<szerokosc; j++)
                macierz[i][j] += m.macierz[i][j];
        }
    }
    catch(int err)
    {
        cout<<"Error"<<"\nNiepoprawny rozmiar podanej macierzy\n"<<
        "Musza byc tego samego rozmiaru\n";
        exit (1);
    }

}

void Matrix::substract(Matrix m)
{
    try
    {
        if (m.wysokosc != wysokosc || m.szerokosc != szerokosc)
            throw 1;
        for (int i=0; i<m.wysokosc; i++)
        {
            for(int j=0; j<m.szerokosc; j++)
                macierz[i][j] -= m.macierz[i][j];
        }
    }
    catch(int err)
    {
        cout<<"Error"<<"\nNiepoprawny rozmiar podanej macierzy\n"<<
        "Musza byc tego samego rozmiaru\n";
        exit (1);
    }

}

Matrix* Matrix::multiply(Matrix m)
{
    try
    {
        if (m.wysokosc != szerokosc)
            throw 1;
        Matrix * pnt = new Matrix(wysokosc, m.szerokosc);
        double s=0.0;
        for (int i=0; i<wysokosc; i++)
        {
            for(int j=0; j<m.szerokosc; j++)
            {   s=0.0;
                for(int k=0; k<szerokosc; k++)
                {
                    s += macierz[i][k]*m.macierz[k][j];
                }
                pnt->macierz[i][j]=s;
            }

        }
        return pnt;
    }
    catch(int err)
    {
        cout<<"Error"<<"\nWiersze drugiej macierzy"<<
        " musza byc rowne kolumnom pierwszej macierzy\n";
        exit (1);
    }

}

int Matrix::cols()
{
    return szerokosc;
}

int Matrix::rows()
{
    return wysokosc;
}

void Matrix::store(std::string filename, std::string path)
{
    try
    {

        std::ofstream file;
        file.open (path , ios::in);

        if (!file.is_open())
            throw "File error";

        std::string data = to_string(szerokosc)+"\n"+to_string(wysokosc)+"\n";
        for (int i=0; i<wysokosc; i++)
        {
            for(int j=0; j<szerokosc; j++)
                data += to_string(macierz[i][j]) + "\n";
        }
        file << data;

        file.close();
    }
    catch (const char * err)
    {
        cout<<"Error: "<< err << endl;
        cout<<"Nie udalo sie otworzyc plik\n";
        exit (1);
    }
}
