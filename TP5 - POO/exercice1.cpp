#include "Rectangle.hpp"
#include "point.hpp"
#include <vector>
#include <time.h>

template <class T> 
T maximum (T const & a, T const & b){
	return a > b ? a : b;
}

template <class T>
T somme(vector<T> v){
	T sum;
	if(v.size() != 0){
		for(int i=0; i < v.size(); i++){
			sum = sum + v[i];
		}
	}
	return sum;
}

int main(){
	srand(time(NULL));
	Rectangle r1(13,13);
	Rectangle r2(6,4);
	cout << maximum(r1,r2) << endl;
	
	vector<int> vi;
	vector<Point> vp;
	for (int i=0;i<5;i++){
		int val = rand()%50;
		int x = rand()% 50;
		int y = rand()% 50;
		Point p(x,y);
		vi.push_back(val);
		vp.push_back(p);
		
	}
	int n = somme(vi);
	Point s = somme(vp);
	cout << n << endl;
	cout << s << endl;
	return 0;
}
