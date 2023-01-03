#include "Rectangle.hpp"
#include "point.hpp"
#include <vector>
#include <time.h>
#include <map>
#include <string>

template <class T> 
T maximum (T const & a, T const & b){
	return a > b ? a : b;
}

template <class T>
T somme(vector<T> v){
	T sum = T();
	if(v.size() != 0){
		for(int i=0; i < v.size(); i++){
			sum = sum + v[i];
		}
	}
	return sum;
}

template <typename T>
vector<T> tri_panier(vector<T> v){
	map<T,int> m;
	for(int i=0; i < v.size(); i++){
		int cnt = 0;
		if(m.find(v[i]) == m.end()){
			for(int j=i; j<v.size(); j++){
				if(v[i]==v[j]){
					cnt++;
				}
			}
			m[v[i]]=cnt;
		}
	}
	vector<T> v2;
	typename map<T,int>::iterator it;
	for(it = m.begin(); it != m.end(); it++){
		for(int i=0; i < it->second; i++){
			v2.push_back(it->first);
		}
	}
	return v2;
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
	
	vector<string> tab;
        tab.push_back("ce");
        tab.push_back("pas");
        tab.push_back("trié");
        tab.push_back("pas");
        tab.push_back("pas");
        tab.push_back("tableau");
        tab.push_back("n'est");
        tab.push_back("ce");
        vector<string> tab_trié = tri_panier(tab);
    
        for(int i = 0; i <tab.size(); i++){
    	    cout << tab[i] << endl;
        }
        cout << endl;
        for(int i = 0; i <tab.size(); i++){
    	    cout << tab_trié[i] << endl;
        }
	return 0;
}
