# include <stdlib.h>
# include <assert.h>
# include "vector.hpp"

using namespace std ; 

Vector :: Vector ( ) {
	this->size = 0;
	this->element = NULL;
	
}

Vector :: Vector ( unsigned int const _size ) {
	this->size = _size;
	this->element = new float[_size];
	for(int i = 0; i < this->size; i++){
		this->element[i] = 0.;
	}
	
}

Vector :: Vector ( const Vector & v ) {
	this->size = v.size;
	this->element = new float[v.size];
	for (int i = 0; i < v.size; i++){
		this->element[i] = v.element[i];
	}
}


Vector :: ~Vector () {
	delete[] this->element;	
}


void Vector :: init_alea () { 
  for ( unsigned int i = 0 ; i < size ; i++ ) {	
    element[ i ] = drand48 () ; 
  }					
}


float & Vector :: operator [] ( unsigned int const i ) {
  return this->element[i];
}


float const & Vector :: operator [] ( unsigned int const i ) const { 
  return this->element[i];
}


std :: ostream & operator << ( std :: ostream& ost ,
			       Vector const & v ) {
			       ost << "(";
			       for (int i = 0; i < v.size - 1; i++){
			       		ost << v.element[i] << ", ";
			       }
			       ost << v.element[v.size-1] << ")" << endl;
  return ost ; 
}


Vector & Vector :: operator = ( Vector const & v ) { 
  this->size = v.size;
  for (int i=0; i < v.size; i++){
  	this->element[i] = v.size;
  }
  this->element = v.element;
  return *this;
}


Vector Vector :: operator + ( Vector const & v ) const {
	assert(this->size == v.size);
	for (int i = 0; i < v.size;i++){
		v.element[i] += this->element[i];
	}
 	return v ;
}


Vector Vector :: operator - ( Vector const & v ) const { 
	assert(this->size == v.size);
	for (int i = 0; i < v.size;i++){
		v.element[i] -= this->element[i];
	}
 	return v ;
}


Vector Vector :: operator * ( float const a ) const { 
	for (int i = 0; i < this->size;i++){
		this->element[i] = this->element[i] * a;
	}
	return *this;
}


float Vector :: operator | ( Vector const & v ) const {
	assert(this->size == v.size);
	float sum = 0;
	for(int i = 0; i < v.size;i++){
		sum += this->element[i] * v.element[i];
	}
	return sum;
}


bool Vector :: operator == ( Vector const & v ) const {
	if (this->size == v.size){
		for (int i = 0; 0<this->size;i++){
			if(this->element[i] != v.element[i]){
				return false;
			}
		return true;
		}
	}
  return false ;
}


Vector operator * ( float const a ,
		    Vector const & v ) { 
  	return v*a;
}



