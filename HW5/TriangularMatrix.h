#include<iostream>
using namespace std;
class Matrix
{
	friend Matrix operator*(double,Matrix&);
	friend ostream &operator<<(ostream&,const Matrix&);
	int N,UD;
	double **matrix;
public:
	Matrix(int n=2);
	Matrix(const Matrix&);
	~Matrix(void);
	void readMatrix(void);
	int size(void)const;
	double operator()(int,int)const;
	Matrix operator+(const Matrix&);
	Matrix operator-(const Matrix&);
	Matrix operator*(const Matrix&);
	Matrix operator*(const double);
	const Matrix &operator=(const Matrix&);
	const Matrix &operator-=(const Matrix&);
	const Matrix &operator+=(const Matrix&);
	const Matrix &operator*=(const Matrix&);
};

