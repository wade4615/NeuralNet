#include "Matrix.h"

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}


template class Array<double>;

template <class T>
Array<T>::Array(IndexType numberOfElements, double low, double high):bias(NULL),m_numberOfElements(numberOfElements)
{
    elements = new T[m_numberOfElements];
    for (auto i=0; i<m_numberOfElements; i++)
    {
        elements[i] = fRand(low, high);
    }
}

template <class T>
Array<T>::Array(IndexType numberOfElements, double value):bias(NULL),m_numberOfElements(numberOfElements)
{
    elements = new T[m_numberOfElements];
    for (auto i=0; i<m_numberOfElements; i++)
    {
        elements[i] = value;
    }
}

template <class T>
Array<T>::Array(initializer_list<T> list)
{
    bias = NULL;
    m_numberOfElements = (int)list.size();
    elements = new T [m_numberOfElements];
    auto count = 0;
    for (auto element : list)
    {
        elements[count] = element;
        count++;
    }
}

template <class T>
Array<T>::~Array()
{
    delete[] elements;
}

template <class T>
T& Array<T>::operator[](const IndexType &index)
{
    return elements[index];
}

template <class T>
void Array<T>::setBias(Array<T> *other)
{
    bias = other;
}

template <class T>
Array<T> Array<T>::operator*(Matrix<T> &other)
{
    Array<T> *temp = new Array<T>(m_numberOfElements,0.0);
    for(auto j=0; j<other.getCols(); j++)
    {
        double activation = 0;
        if (bias == NULL)
            activation = 0;
        else
            activation = (*bias)[j];
        for(auto k=0; k<m_numberOfElements; k++)
        {
            activation += elements[k] * other[k][j];
        }
        (*temp)[j] = activation;
    }
    return *temp;
}

template <class T>
void Array<T>::print(char * text) const
{
    cout << text << endl;
    string delimiter = "";
    if (m_numberOfElements>0)
    {
        for (auto j = 0; j < m_numberOfElements; j++)
        {
            cout << delimiter << elements[j];
            delimiter = ",";
        }
    }
    else
    {
        cout << "size=0" << endl;
    }
    cout << endl;
}

template <class T>
unsigned Array<T>::getSize() const
{
    return m_numberOfElements;
}


template class Matrix<double>;

template <class T>
Matrix<T>::Matrix(unsigned rowSize, unsigned colSize, double low, double high)
{
    bias=NULL;
    m_rowSize = rowSize;
    m_colSize = colSize;
    elements = new T *[rowSize];
    for (auto i = 0; i < rowSize; i++)
    {
        elements[i] = new T[colSize];
        for (auto j = 0; j < colSize; j++)
        {
            elements[i][j] = fRand(low, high);
        }
    }
}

template <class T>
Matrix<T>::Matrix(unsigned rowSize, unsigned colSize, double value)
{
    bias=NULL;
    m_rowSize = rowSize;
    m_colSize = colSize;
    elements = new T *[rowSize];
    for (auto i = 0; i < rowSize; i++)
    {
        elements[i] = new T[colSize];
        for (auto j = 0; j < colSize; j++)
        {
            elements[i][j] = value;
        }
    }
}

template <class T>
Matrix<T>::Matrix(initializer_list<initializer_list<T>> list)
{
    bias=NULL;
    this->m_rowSize = (int)list.size();
    this->m_colSize = (int)(list.begin())->size();
    elements = new T *[m_rowSize];
    for (auto i = 0; i < m_rowSize; i++)
    {
        elements[i] = new T[m_colSize];
        for (auto j = 0; j < m_colSize; j++)
        {
            elements[i][j] = ((list.begin()+i)->begin())[j];
        }
    }
}

template <class T>
Matrix<T>::~Matrix()
{
    for (auto i = 0; i < m_rowSize; i++)
    {
        delete[] elements[i];
    }
    delete[] elements;
}

template <class T>
T *& Matrix<T>::operator[](const IndexType &index)
{
    return elements[index];
}

template <class T>
Matrix<T> Matrix<T>::operator*(Matrix<T> &other)
{
    Matrix<T> *temp = new Matrix<T>(m_rowSize,other.getCols(), 0.0);
    for (auto i = 0; i < m_rowSize; i++)
    {
        for (auto j = 0; j < other.getCols(); j++)
        {
            double acumulate = 0;
            if (bias == NULL)
                acumulate = 0;
            else
                acumulate = (*bias)[j];
            for (auto k = 0; k < m_colSize; k++)
            {
                acumulate += elements[i][k] * other[k][j];
            }
            (*temp)[i][j] = acumulate;
        }
    }
    return *temp;
}

template <class T>
Array<T> Matrix<T>::operator*(Array<T> &other)
{
    Array<T> *temp = new Array<T>(other.getSize(),0.0);
    for(auto i=0; i<other.getSize(); i++)
    {
        double acumulate = 0;
        if (bias == NULL)
            acumulate = 0;
        else
            acumulate = (*bias)[i];
        for(auto j=0; j<m_rowSize; j++)
        {
            acumulate += elements[i][j] * other[j];
        }
        (*temp)[i] += acumulate;
    }
    return *temp;
}

template <class T>
void Matrix<T>::print(char * text) const
{
    cout << text << endl;
    string delimiter = "";
    for (auto i = 0; i < m_rowSize; i++)
    {
        delimiter = "";
        for (auto j = 0; j < m_colSize; j++)
        {
            cout << delimiter << elements[i][j];
            delimiter = ",";
        }
        cout << std::endl;
    }
}

template <class T>
IndexType Matrix<T>::getRows() const
{
    return m_rowSize;
}

template <class T>
IndexType Matrix<T>::getCols() const
{
    return m_colSize;
}
