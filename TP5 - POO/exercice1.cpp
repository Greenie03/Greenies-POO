#include "Rectangle.hpp"
#include "point.hpp"
#include <vector>

template <class T> 
T maximum (T const & a, T const & b){
	return a > b ? a : b;
}

template <class T>
T somme(vector<T> v){
	T sum;
	if(v.size() != 0){
		for(int i=0; i < v.size(); i++){
			sum += v[i];
		}
	}
	return sum;
}

int main(){
	Rectangle r1(13,13);
	Rectangle r2(6,4);
	cout << maximum(r1,r2) << endl;
	
	vector<int> vi;
	vector<Point> vp;
	for (int i=0;i<5;i++){
		int val = rand()%50;
		cout << val << endl;
		vi.push_back(val);
		
	}
	cout << somme(vi) <<endl;
	return 0;
}
