#include "fonction.hpp"

int majorSel(vector<int> v){
	for (int i=0; i < v.size(); i++){
		int c = 0;
		for (int j=i; j < v.size(); j++){
			if(v[j] == v[i]){
				c++;
			}
			if(c > v.size() / 2){
				
				return v[j];
			}
		}
	}
	return -1;
}

int majorSort(vector<int> v){
	sort(v.begin(),v.end());
	int val = v[0];
	int c = 0;
	for (int i=0; i < v.size(); i++){
		if (c > v.size() / 2){
			return val;
		}else if (val != v[i+1] && c < v.size() / 2){
			c = 0;
			val = v[i+1];
			
		}
		c++;
	}
	return -1;
	
}

int majorMap(vector<int> v){
	map <int,int> m;
	for (int i=0; i < v.size();i++){
		++m[v[i]];
	}
	map<int,int>::iterator b = m.begin();
	
	for (map<int,int>::iterator it=m.begin();it!=m.end();++it){
		if(b->second < it->second){
			b = it;
		}
	}
	return b->second;
}

//Compléxité O(n*logn)
