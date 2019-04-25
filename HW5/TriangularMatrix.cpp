#include<iostream>
#include<string.h>
#include <iomanip>
#include"TriangularMatrix.h"
#define upper 1
using namespace std;

Matrix::Matrix(int n):N(n),UD(-1)
{
	matrix = new double*[n];
	for(int i=0;i<n;i++)
	{
		matrix[i] = new double[n];
		memset(matrix[i],0,sizeof(double)*n);
	}
	return;
}

Matrix::Matrix(const Matrix &original)
{
	N = original.N;
	UD = original.UD;
	matrix = new double*[N];
	if(UD == upper)
	{
		for(int i=0;i<N;i++)matrix[i] = new double[N-i];
		for(int i=0;i<N;i++)for(int j=0;j<N-i;j++)matrix[i][j] = original.matrix[i][j];
	}
	else
	{		
		for(int i=0;i<N;i++)matrix[i] = new double[i+1];
		for(int i=0;i<N;i++)for(int j=0;j<i+1;j++)matrix[i][j] = original.matrix[i][j];
	}
	return;
}
Matrix::~Matrix(void)
{
	for(int i=0;i<N;i++)delete matrix[i];
	delete[] matrix;
	return;
}
void Matrix::readMatrix(void)
{
	for(int i=0;i<N;i++)delete[] matrix[i];
	delete[] matrix;
	cout<<"<prompt> specify number of rows:\n<user input>\n";
	cin>>N;
	cout<<"\n<prompt> is upper or lower triangular: (upper: 1, lower:0)\n<user input>\n";
	cin>>UD;
	cout<<"\n<prompt> input elements of the matrix:\n<user input>\n";
	matrix = new double*[N];
	if(UD == upper)
	{
		for(int i=0;i<N;i++)matrix[i] = new double[N-i];
		for(int i=0;i<N;i++)for(int j=0;j<N-i;j++)cin>>matrix[i][j];
	}
	else
	{		
		for(int i=0;i<N;i++)matrix[i] = new double[i+1];
		for(int i=0;i<N;i++)for(int j=0;j<i+1;j++)cin>>matrix[i][j];
	}
	return;
}
int Matrix::size(void)const
{
	return N;
}
//****************operator****************//

Matrix Matrix::operator+(const Matrix& right)
{
	Matrix temp = *this;
	if(right.N != N)
	{
		cout<<"Matrix dimensions must agree\n";
		return temp;
	}
	else if(UD != right.UD)
	{
		cout<<"upper Matrix cannot operate with lower Matrix\n";
		return temp;
	}
	if(UD == upper)	for(int i=0;i<N;i++)for(int j=0;j<N-i;j++)temp.matrix[i][j]+=right.matrix[i][j];
	else for(int i=0;i<N;i++)for(int j=0;j<i+1;j++)temp.matrix[i][j]+=right.matrix[i][j];
	return temp;
}
Matrix Matrix::operator-(const Matrix &right)
{

	Matrix temp = *this;
	if(right.N != N)
	{
		cout<<"Matrix dimensions must agree\n";
		return temp;
	}
	else if(UD != right.UD)
	{
		cout<<"upper Matrix cannot operate with lower Matrix\n";
		return temp;
	}
	if(UD == upper)for(int i=0;i<N;i++)for(int j=0;j<N-i;j++)temp.matrix[i][j]-=right.matrix[i][j];
	else for(int i=0;i<N;i++)for(int j=0;j<i+1;j++)temp.matrix[i][j]-=right.matrix[i][j];
	return temp;
}

Matrix Matrix::operator*(const Matrix &right)
{
	Matrix temp = *this;
	if(right.N != N)
	{
		cout<<"Matrix dimensions must agree\n";
		return temp;
	}
	else if(UD != right.UD)
	{
		cout<<"upper Matrix cannot operate with lower Matrix\n";
		return temp;
	}
	cerr<<right.matrix[1][1]<<endl;
	double lef,rig;
	if(UD == upper)
		for(int i=0;i<N;i++)
			for(int j=i;j<N;j++)
			{
				temp.matrix[i][j-i] = 0;
				for(int k=0;k<N;k++)
				{
					lef = (k >= i)?matrix[i][k-i]:0; 
					rig = (k <= j)?right.matrix[k][j-k]:0;
					temp.matrix[i][j-i] += (lef*rig);
				}				
			}
	else 
		for(int i=0;i<N;i++)
			for(int j=0;j<i+1;j++)
			{
				temp.matrix[i][j] = 0;
				for(int k=0;k<N;k++)
				{
					lef = (k <= i)?matrix[i][k]:0; 
					rig = (k >= j)?right.matrix[k][j]:0;
					temp.matrix[i][j] += lef*rig;
				}					
			}
	return temp;
}
Matrix Matrix ::operator*(const double a)
{
	Matrix temp = *this;
	if(UD == upper)
		for(int i=0;i<N;i++)for(int j=0;j<N-i;j++)temp.matrix[i][j]*=a;
	else 
		for(int i=0;i<N;i++)for(int j=0;j<i+1;j++)temp.matrix[i][j]*=a;
	return temp;
}
const Matrix& Matrix::operator-=(const Matrix &right)
{
	if(right.N != N)
	{
		cout<<"Matrix dimensions must agree\n";
		return *this;
	}
	else if(UD != right.UD)
	{
		cout<<"upper Matrix cannot operate with lower Matrix\n";
		return *this;
	}
	*this = *this - right;
	return *this;
}
const Matrix &Matrix::operator+=(const Matrix& right)
{
	if(right.N != N)
	{
		cout<<"Matrix dimensions must agree\n";
		return *this;
	}
	else if(UD != right.UD)
	{
		cout<<"upper Matrix cannot operate with lower Matrix\n";
		return *this;
	}
	*this = *this + right;
	return *this;
}
const Matrix& Matrix::operator*=(const Matrix &right)
{
	if(right.N != N)
	{
		cout<<"Matrix dimensions must agree\n";
		return *this;
	}
	else if(UD != right.UD)
	{
		cout<<"upper Matrix cannot operate with lower Matrix\n";
		return *this;
	}
	*this = *this * right;
	return *this;
}
const Matrix& Matrix::operator=(const Matrix &right)
{
	if(&right == this)return *this;
	for(int i=0;i<N;i++)delete[] matrix[i];
	delete[] matrix;
	N = right.N;
	UD = right.UD;
	matrix = new double*[N];
	if(UD == upper)
	{
		for(int i=0;i<N;i++)matrix[i] = new double[N-i];
		for(int i=0;i<N;i++)for(int j=0;j<N-i;j++)matrix[i][j] = right.matrix[i][j];
	}
	else
	{		
		for(int i=0;i<N;i++)matrix[i] = new double[i+1];
		for(int i=0;i<N;i++)for(int j=0;j<i+1;j++)matrix[i][j] = right.matrix[i][j];
		
	}
	return *this;
}
double Matrix::operator()(int i,int j)const
{
	if(UD == upper)
	{
		if(i<=j)return matrix[i-1][j-i];
		else return 0;
	}
	if(i>=j)return matrix[i-1][j-1];
	return 0;
}

/**********friend************/
Matrix operator*(double a,Matrix& right)
{
	Matrix temp = right;
	temp = temp*a;
	return temp;
}
ostream &operator<<(ostream &stream,const Matrix& right)
{
	stream<<endl;
	if(right.UD == upper)
		for(int i=0;i<right.N;i++)
		{
			for(int j=0;j<i;j++)stream<<left<<setw(8)<<"0";
			for(int j=0;j<right.N-i;j++)stream<<left<<setw(8)<<right.matrix[i][j];			
			stream<<endl;
		}
	else
		for(int i=0;i<right.N;i++)
		{
			for(int j=0;j<i+1;j++)stream<<left<<setw(8)<<right.matrix[i][j];
			for(int j=0;j<right.N-i-1;j++)stream<<left<<setw(8)<<"0";
			stream<<endl;
		}
	return stream;
}




