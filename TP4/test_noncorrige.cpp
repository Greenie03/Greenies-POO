# include "matrix.hpp"

using namespace std ; 

static void test_noncorrige ( Matrix m ) {
  
  Matrix m_orig ( m ) ;
  cout << m ;
  
  Matrix l = m . extract_triangular_lower_diag_one () ; 
  Matrix u = m . extract_triangular_upper_diag () ; 
  
  cout << "Matrix L :" << endl ; 
  cout << l ; 

  cout << "Matrix U :" << endl ; 
  cout << u ; 

  cout << "Produit" << endl;
  cout << l*u << endl;
}


// To simplify writing to the maximum
# define TEST_MACRO( n , ... )				\
  {							\
    Matrix m ( n , n ) ;				\
    float coefficients [ n * n ] = { __VA_ARGS__ } ;	\
    m . init ( coefficients ) ;				\
    test_noncorrige ( m ) ;					\
  }


int main ( void ) {
  TEST_MACRO ( 1 , 2 ) ;
  TEST_MACRO ( 2 , 2 , 1 , 2 , 3 ) ;
  TEST_MACRO ( 3 , 2 , 1 , 2 , 3 , 4 , 4 , 3 , 3 , 0 ) ;
  TEST_MACRO ( 4 , 2 , 1 , 2 , 3 , 4 , 4 , 3 , 3 , 0 , 5 , 1 , 2 , 1 , 0 , 5 , 8 ) ;
  TEST_MACRO ( 5 , 2 , 1 , 2 , 3 , 4 , 4 , 3 , 3 , 0 , 5 , 1 , 2 , 1 , 0 , 5 , 8 , 5 , 1 , 6 , 1 , 8 , 10 , 1 , 2 , 0 ) ;
  TEST_MACRO ( 6 , 2 , 1 , 2 , 3 , 4 , 4 , 3 , 3 , 0 , 5 , 1 , 2 , 1 , 0 , 5 , 8 , 5 , 1 , 6 , 1 , 8 , 10 , 1 , 2 , 0 , 16 , 12 , 5 , 13 , 16 , 2 , 8 , 10 , 7 , 3 , 25 ) ;
  return 0 ; 
}
