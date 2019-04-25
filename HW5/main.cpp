#include<iostream>
#include"TriangularMatrix.h"
using namespace std;
int main(void)
{
	//freopen("test.txt","r",stdin);
	//"***lower trangular***\n"//	
	Matrix m0;
	Matrix m1;
	cout<<"***constructor***\n";
	cout<<"m0 = \n"<<m0<<endl;
	cout<<"m1 = \n"<<m1<<endl;
	m0.readMatrix();	
	m1.readMatrix();	
	cout<<"***lower trangular***\n";	
	cout<<"\n***copy constructor m2 = m1 ***\n";
	Matrix m2 = m1;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	cout<<"\n*** m2 = m0 + m1 ***\n";
	m2 = m0 + m1;
	cout<<"m0 = \n"<<m0<<endl;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	cout<<"\n*** m2 = m0 - m1 ***\n";
	m2 = m0 - m1;
	cout<<"m0 = \n"<<m0<<endl;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	cout<<"\n*** m2 = m0 * m1 ***\n";
	m2 = m0 * m1;
	cout<<"m0 = \n"<<m0<<endl;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	cout<<"\n*** m2 = m1 * 3 ***\n";
	m2 = m1 * 3;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	cout<<"\n*** m2 -= m1 ***\n";
	m2 -= m1;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	cout<<"\n*** m2 += m1 ***\n";
	m2 += m1;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	cout<<"\n*** m2 *= m1 ***\n";
	m2 *= m1;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	cout<<"\n*** assignment m2 = m1 ***\n";
	m2 = m1;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	cout<<"\n***  m2(i, j) ***\n";
	cout<<"m2(2, 1) = "<<m2(2, 1)<<endl;
	cout<<"m2(3, 3) = "<<m2(3, 3)<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	cout<<"\n*** m2 = 3 * m1  ***\n";
	m2 = 3 * m1;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	//***upper trangular***//
	m0.readMatrix();
	m1.readMatrix();
	cout<<"***upper trangular***\n";
	cout<<"m0 = \n"<<m0<<endl;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"\n***copy constructor m3 = m1 ***\n";
	Matrix m3 = m1;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"m3 = \n"<<m3<<endl;
	cout<<"\n*** m2 = m0 + m1 ***\n";
	m2 = m0 + m1;
	cout<<"m0 = \n"<<m0<<endl;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	cout<<"\n*** m2 = m0 - m1 ***\n";
	m2 = m0 - m1;
	cout<<"m0 = \n"<<m0<<endl;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	cout<<"\n*** m2 = m0 * m1 ***\n";
	m2 = m0 * m1;
	cout<<"m0 = \n"<<m0<<endl;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	cout<<"\n*** m2 = m1 * 3 ***\n";
	m2 = m1 * 3;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	cout<<"\n*** m2 -= m1 ***\n";
	m2 -= m1;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	cout<<"\n*** m2 += m1 ***\n";
	m2 += m1;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	cout<<"\n*** m2 *= m1 ***\n";
	m2 *= m1;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	cout<<"\n*** assignment m2 = m1 ***\n";
	m2 = m1;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	cout<<"\n***  m2(i, j) ***\n";
	cout<<"m2(1, 2) = "<<m2(1, 2)<<endl;
	cout<<"m2(3, 3) = "<<m2(3, 3)<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	cout<<"\n*** m2 = 3 * m1  ***\n";
	m2 = 3 * m1;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	
	//upper lower error//
	m0.readMatrix();
	cout<<"\nupper lower error\n";
	cout<<"m0 = \n"<<m0<<endl;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"\n*** m2 = m0 + m1 ***\n";
	m2 = m0 + m1;
	cout<<"m0 = \n"<<m0<<endl;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	cout<<"\n*** m2 = m0 - m1 ***\n";
	m2 = m0 - m1;
	cout<<"m0 = \n"<<m0<<endl;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	cout<<"\n*** m2 = m0 * m1 ***\n";
	m2 = m0 * m1;
	cout<<"m0 = \n"<<m0<<endl;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	cout<<"\n*** m2 -= m1 ***\n";
	m2 -= m1;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	cout<<"\n*** m2 += m1 ***\n";
	m2 += m1;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	cout<<"\n*** m2 *= m1 ***\n";
	m2 *= m1;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	
	//matrix dimension error//
	m0.readMatrix();
	cout<<"\nmatrix dimension error\n";
	cout<<"m0 = \n"<<m0<<endl;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"\n*** m2 = m0 + m1 ***\n";
	m2 = m0 + m1;
	cout<<"m0 = \n"<<m0<<endl;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	cout<<"\n*** m2 = m0 - m1 ***\n";
	m2 = m0 - m1;
	cout<<"m0 = \n"<<m0<<endl;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	cout<<"\n*** m2 = m0 * m1 ***\n";
	m2 = m0 * m1;
	cout<<"m0 = \n"<<m0<<endl;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	cout<<"\n*** m2 -= m1 ***\n";
	m2 -= m1;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	cout<<"\n*** m2 += m1 ***\n";
	m2 += m1;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	cout<<"\n*** m2 *= m1 ***\n";
	m2 *= m1;
	cout<<"m1 = \n"<<m1<<endl;
	cout<<"m2 = \n"<<m2<<endl;
	
	Matrix M1, M2, M3;
	cout << "* Assign values for matrix M1 *" << endl;
	M1.readMatrix();
	// ---This should be implemented in Matrix::readMatrix()---
	// <prompt> specify number of rows:
	// <user input> 3
	// <prompt> is upper or lower triangular: (upper: 1, lower:0)
	// <user input> 0
	// <prompt> input elements of the matrix:
	// <prompt> for example, if you want to create a lower-triangular matrix with following elements:
	// <prompt> 4    0    0
    // <prompt> 3    2.5  0
	// <prompt> 1    2    2
	// <prompt> please type: 4 3 2.5 1 2 2
	
	cout << "* Assign values for matrix M2 *" << endl;
	M2.readMatrix();
	
	
	cout << "M1 is: " << M1 << endl << endl;
	cout << "M2 is: " << M2 << endl << endl;
	
	// Note that the size(row count) of M1, M2 may vary,
	// also M1, M2 can be upper or lower triangular matrices.
	// Therefore, please make sure that you check their types first before doing the calculation.

	cout << "M3 = M1 + M2" <<endl;
	M3 = M1 + M2;
	cout << "Now M3 is: " << M3 << endl << endl;
	
	cout << "M3 = M2 * 5" <<endl;
	M3 = M2 * 5;
	cout << "Now M3 is: " << M3 << endl << endl;

	cout << "M3 -= M1" << endl;
	M3 -= M1;
	cout << "Now M3 is: " << M3 << endl << endl;
	
	cout << "M3 = M2 * 2 * M1" << endl;
	M3 = M2 * 2 * M1;
	cout << "Now M3 is: " << M3 << endl << endl;
	
	cout << "double d = M1(1,2)" << endl;
	double d = M1(1,2);
	cout << "Now d is: " << d << endl << endl;
	
	cout << "M2(1,1) equals to: " << M2(1,1) << endl << endl;
	
	
	return 0;
}