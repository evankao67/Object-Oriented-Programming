#include <iostream>
#include <map>
using namespace std;
int main (){
	multimap<char,int> mmap;
	multimap<char,int>::iterator it;
	mmap.insert({'a',97});
	mmap.insert(pair<char,int>('b',98));
	mmap.insert(pair<char,int>('c',99));
	mmap.insert(pair<char,int>('d',100));
	mmap.insert(pair<char,int>('a',199));
	mmap.insert(pair<char,int>('b',98));
	mmap.insert(pair<char,int>('c',99));
	mmap.insert(pair<char,int>('d',100));
	for (it=mmap.begin(); it!=mmap.end(); ++it){
		cout << it->first << " => " << it->second << endl;
	}
	cout << endl;
	mmap.erase('c');
	for (it=mmap.begin(); it!=mmap.end(); ++it){
		cout << it->first << " => " << it->second << endl;
	}	
}