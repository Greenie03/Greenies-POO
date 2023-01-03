# include <iostream>
# include <stdlib.h>  // drand48

# include <assert.h>

# undef NDEBUG

# include "matrix.hpp"

using namespace std ; 


Matrix :: Matrix() {
	this->line_nbr = 0;
	this->column_nbr = 0;
	this->element = NULL;
}					


Matrix :: Matrix ( unsigned int const _line_nbr , unsigned int const _column_nbr ) { 
	this->line_nbr = _line_nbr;
	this->column_nbr = _column_nbr;
	this->element = new float[_column_nbr * _line_nbr];
	for(int i = 0; i < this->column_nbr * this->line_nbr;i++){
		this->element[i] = 0.;
	}
} 


Matrix :: Matrix ( Matrix const & m ) {
	this->line_nbr = m.line_nbr;
	this->column_nbr = m.column_nbr;
	this->element = new float[m.column_nbr * m.line_nbr];
	for(int i = 0; i < m.column_nbr * m.line_nbr;i++){
		this->element[i] = m.element[i];
	}
} 

Matrix :: ~ Matrix () {
  delete [] element; // works with NULL
}


void Matrix :: init_alea () {
	for ( unsigned int i = 0 ; i < line_nbr * column_nbr ; i++ ) {	
		element[ i ] = drand48 () ; 
	}	
}


void Matrix :: init ( float const * coefficients ) {
	for (int i=0; i < this->column_nbr * this->line_nbr;i++){
		this->element[i] = coefficients[i];
	}
	
}


void Matrix :: set_identity () {
	assert(this->column_nbr == this->line_nbr);
	for (int i=0; i < this->line_nbr;i++){
		for(int j=0; j < this->column_nbr;j++){
			if(i == j){
				(*this)(i,j) = 1;
			}else{
				(*this)(i,j) = 0;
			}
		}
	}	
}


std :: ostream & operator << ( std :: ostream & ost , 
			       Matrix const & m ) { 
			       for (int i=0; i < m.line_nbr;i++){
			       		for(int j=0; j <m.column_nbr;j++){
			       			ost << m.element[j+(i*m.line_nbr)] << "\t";
			       		}
			       		ost << "\n";
			       }
			       return ost;
}


Matrix & Matrix :: operator = ( Matrix const & m ) { 
	assert(this->column_nbr == m.column_nbr && this->line_nbr == m.line_nbr);
	this->column_nbr = m.column_nbr;
	this->line_nbr = m.column_nbr;
	for (int i=0; i <  column_nbr * line_nbr;i++){
		this->element[i] = m.element[i];
	}
	return *this;
}


Matrix Matrix :: operator + ( Matrix const & m ) const {
	assert(this->column_nbr == m.column_nbr && this->line_nbr == m.line_nbr);
	Matrix copy(*this);
	for (int i=0; i <  column_nbr * line_nbr;i++){
		copy.element[i] += m.element[i];
	}
	return copy;

}


Matrix Matrix :: operator - ( Matrix const & m ) const { 
	assert(this->column_nbr == m.column_nbr && this->line_nbr == m.line_nbr);
	Matrix copy(*this);
	for (int i=0; i <  column_nbr * line_nbr;i++){
		copy.element[i] -= m.element[i];
	}
	return copy;
}


Matrix Matrix :: operator * ( Matrix const & m ) const { 
	assert(m.line_nbr == this->column_nbr);
	Matrix copy(m.line_nbr,this->column_nbr);
	for (int i=0; i <  m.line_nbr;i++){
		for(int j = 0; j < this->column_nbr;j++){
			copy(i,j) = m.extract_ligne(i,0,m.line_nbr-1) | this->extract_col(0,this->column_nbr-1,j);
		}
	}
	return copy;
}


Vector Matrix :: operator * ( Vector const & v ) const {
	assert(this->column_nbr == v.get_size());
	Vector sum(this->line_nbr);
	for(int j = 0; j < this->line_nbr;j++){
		sum[j] = this->extract_ligne(j,0,this->column_nbr-1) | v;
	}
	return sum;
}


Matrix Matrix :: operator * ( const float a ) const {
	Matrix copy(*this);
	for(int i=0; i < column_nbr * line_nbr;i++){
		copy.element[i] *= a;
	}
	return copy;
}


Matrix operator * ( float const a ,
		    Matrix const & m ) {
  return m * a ; 
}


Matrix & Matrix :: operator += ( Matrix const & m ) { 
	assert(this->column_nbr == m.line_nbr);
	for(int i=0; i < column_nbr * line_nbr;i++){
		this->element[i] += m.element[i];
	}
	return *this;
}


Matrix & Matrix :: operator *= ( Matrix const & m ) { 
	Matrix copy = (*this) * m;
	*this = copy;
	return *this;
}


bool Matrix :: operator == ( Matrix const & m ) const {
	assert(this->column_nbr == m.column_nbr && this->line_nbr == m.line_nbr);
	for (int i=0; i < this->column_nbr * this->line_nbr; i++){
		if(this->element[i] != m.element[i]){
			return false;
		}
	}
	return true;
}


Vector Matrix :: extract_ligne ( unsigned int const l ,
				 unsigned int const c1 ,
				 unsigned int const c2 ) const {
				 assert(c1<=c2);
				 Vector v(c2-c1+1);
				 for (int i = c1; i <= c2; i++){
				 	v[i - c1] = (*this)(l,i);
				 }
				 return v;
}


Vector Matrix :: extract_col ( unsigned int const l1 ,
			       unsigned int const l2 ,
			       unsigned int const c ) const { 
			       	 assert(l1<=l2);
				 Vector v(l2-l1+1);
				 for (int i = l1; i <= l2; i++){
				 	v[i - l1] = (*this)(i,c);
				 }
				 return v;
} 


Matrix Matrix :: extract_triangular_lower_diag_one () const {
	assert(this->column_nbr == this->line_nbr);
	Matrix m(this->line_nbr,this->column_nbr);
	for (int i=0;i < this->line_nbr;i++){
		for(int j=0; j <= i; j++){
			if(j < i){
				m(i,j) = (*this)(i,j);
			}else if(j == i){
				m(i,j) = 1;
			}else{
				m(i,j) = 0;
			}

		} 
	}
	return m;
}


Matrix Matrix :: extract_triangular_upper_diag () const {
	assert(this->column_nbr == this->line_nbr);
	Matrix m(this->line_nbr,this->column_nbr);
	for (int i=0;i < this->line_nbr;i++){
		for(int j=0; j < this->column_nbr; j++){
			if(j >= i){
				m(i,j) = (*this)(i,j);
			}else{
				m(i,j) = 0;
			}
		} 
	}
	return m;
}


Matrix Matrix :: extract_diagonal () const { 
  return * ( Matrix * ) NULL ;
}

