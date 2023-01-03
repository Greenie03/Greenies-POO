#include "fonction.hpp"

int main(){
	    
    	vector<int> v;
    	vector<int> v2;
    	v.push_back(1);
    	v.push_back(8);
    	v.push_back(1);
    	v.push_back(1);
    	v.push_back(6);
    	v.push_back(5);
    	v.push_back(1);  
    	
    	v2.push_back(1);
    	v2.push_back(2);
    	v2.push_back(1);
    	v2.push_back(2);
    	v2.push_back(3);
    	v2.push_back(4);
    	v2.push_back(5);
	cout << majorSel(v) << endl;
	cout << majorSort(v) << endl;
	cout << majorMap(v) <<endl;
	cout << endl;
	cout << majorSel(v2) << endl;
	cout << majorSort(v2) << endl;
	cout << majorMap(v2) <<endl;
	
	return 0;
}
