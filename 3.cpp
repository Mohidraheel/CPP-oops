

#include <iostream>
using namespace std;

template <class T>
class matrix
{
protected:
    int rows;
    int cols;
   

public:
 T **arr;
    matrix(int r, int c)
    {
        rows = r;
        cols = c;
        arr = new T *[rows];
        for (int i = 0; i < rows; i++)
        {
            arr[i] = new T[cols];
        }
    }
    ~matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }
    void input()
    {
        cout << "Enter the elements of the matrix:" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> arr[i][j];
            }
        }
    }
    virtual void display()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << arr[i][j] << " "<<" \t";
            }
            cout << endl;
        }
    }

    matrix<T>* operator+(const matrix<T> &other) const
    {
        if (rows == other.rows && cols == other.cols)
        {

            matrix<T>* temp=new matrix<T>(rows, cols);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    temp->arr[i][j] = arr[i][j] + other.arr[i][j];
                }
            }
            return temp;
        }
        else
        {
            cout << "Addition not possible" << endl;
            matrix<T>* temp=new matrix<T>(rows, cols);
            {
                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < cols; j++)
                    {
                        temp->arr[i][j] = 0;
                    }
                }
            }
            return temp;
        }
    }
    matrix<T>* operator-(const matrix<T> &other) const
    {
        if (rows == other.rows && cols == other.cols)
        {
            matrix<T>* temp=new matrix<T>(rows, cols);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    temp->arr[i][j] = arr[i][j] - other.arr[i][j];
                }
            }
            return temp;
        }
        else
        {
            cout << "Subtraction not possible" << endl;
            matrix<T>* temp=new matrix<T>(rows, cols);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    temp->arr[i][j] = 0;
                }
            }
            return temp;
        }
    }
    matrix<T>* operator*(const matrix<T> &other) const
    {
        if (cols != other.rows)
        {
            cout << "Multiplication not possible" << endl;
            matrix<T>* temp=new matrix<T>(rows, other.cols);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < other.cols; j++)
                {
                    temp->arr[i][j] = 0;
                }
            }
            return temp;
        }
        else
        {
            matrix<T>* temp=new matrix<T>(rows, cols);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < other.cols; j++)
                {
                    for (int k = 0; k < cols; k++)
                    {
                        temp->arr[i][j] += arr[i][k] * other.arr[k][j];
                    }
                }
            }
            return temp;
        }
    }
};

template <class T>
class IntMatrix : public matrix<T>
{
public:
    IntMatrix(int r, int c) : matrix<T>(r, c)
    {
    }
    void display() 
    {
        matrix<T>::display();
    }
     IntMatrix<T> operator+(const IntMatrix<T> &other) const
    {
        const matrix<T>* temp = static_cast<const matrix<T>*>(this) -> operator+(other);
        IntMatrix<T> result(this->rows, this->cols);
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                result.arr[i][j] = temp->arr[i][j];
            }
        }
        delete temp;
        return result;
    }
     IntMatrix<T> operator*(const IntMatrix<T> &other) const
    {
        matrix<T>* temp = static_cast<const matrix<T> *>(this)->operator*(other);
        IntMatrix<T> result(this->rows, this->cols);
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                result.arr[i][j] = temp->arr[i][j];
            }
        }
        return result;
    }
    IntMatrix<T> operator-(const IntMatrix<T> &other) const
    {
        const matrix<T>* temp = static_cast<const matrix<T>*>(this) -> operator-(other);
        IntMatrix<T> result(this->rows, this->cols);
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                result.arr[i][j] = temp->arr[i][j];
            }
        }
        delete temp;
        return result;
    }
};

template <class T>
class doubleMatrix : public matrix<T>
{
    public:
    doubleMatrix(int r, int c) : matrix<T>(r, c)
    {}
    void display()
    {
        matrix<T>::display();
    }
    doubleMatrix<T> operator+(const doubleMatrix<T> &other) const
    {
        const matrix<T>* temp = static_cast<const matrix<T>*>(this) -> operator+(other);
        doubleMatrix<T> result(this->rows, this->cols);
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                result.arr[i][j] = temp->arr[i][j];
            }
        }
        delete temp;
        return result;
    }
    doubleMatrix<T> operator*(const doubleMatrix<T> &other) const
    {
        matrix<T>* temp = static_cast<const matrix<T> *>(this)->operator*(other);
        doubleMatrix<T> result(this->rows, this->cols);
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                result.arr[i][j] = temp->arr[i][j];
            }
        }
        return result;
    }
    doubleMatrix<T> operator-(const doubleMatrix<T> &other) const
    {
        const matrix<T>* temp = static_cast<const matrix<T>*>(this) -> operator-(other);
        doubleMatrix<T> result(this->rows, this->cols);
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                result.arr[i][j] = temp->arr[i][j];
            }
        }
        delete temp;
        return result;
    }
};

int main()
{
    IntMatrix<int> m1(2, 2);
    m1.input();
    m1.display();
    IntMatrix<int> m2(2, 2);
    m2.input();
    m2.display();
    IntMatrix<int> m3(2,2);
    
    m3 = m1 + m2;
    cout<<"_______________________________________________________________"<<endl;
    cout<<"Addition"<<endl;
    m3.display();
    
    m3=m1*m2;
    cout<<"_______________________________________________________________"<<endl;
    cout<<"Multiplication"<<endl;
    m3.display();
     

    m3=m1-m2;
    cout<<"_______________________________________________________________"<<endl;
    cout<<"Subtraction"<<endl;
    m3.display();


    cout<<"double"<<endl;
    doubleMatrix<double> m4(3, 3);
    m4.input();
    m4.display();

    doubleMatrix<double> m5(3, 3);
    m5.input();
    m5.display();
    doubleMatrix<double> m6(3,3);
    
    m6 = m4 + m5;
    cout<<"_______________________________________________________________"<<endl;
    cout<<"Addition"<<endl;
    m6.display();
    
    m6=m4*m5;
    cout<<"_______________________________________________________________"<<endl;
    cout<<"Multiplication"<<endl;
    m6.display();

    m6=m4-m5;
    cout<<"_______________________________________________________________"<<endl;
    cout<<"Subtraction"<<endl;
    m6.display();




    
    return 0;
}