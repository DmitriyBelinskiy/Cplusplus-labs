#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
using namespace std;

struct mydata {
	string name;
	int number;
	mydata() {}
	mydata(string name, int number) : name(name), number(number) {}
};

bool operator<(mydata lft, mydata rht) {
	return lft.name < rht.name;
}

class num_map {
	vector<mydata> collection;
	set<mydata> collectiontwo;
public:
	num_map() {}
	num_map(string name, int number) {
		mydata temp;
		temp.name = name;
		temp.number = number;
		collection.push_back(temp);
		collectiontwo.insert(temp);
	}
	void set(string name, int number) {
		mydata temp;
		temp.name = name;
		temp.number = number;
		collection.push_back(temp);
		collectiontwo.insert(temp);
	}
	void set_2(mydata new_data) {
		collection.push_back(new_data);
		collectiontwo.insert(new_data);
	}

	int size() {
		return collection.size();
	}
	void print() {
		for (auto n : collection)
			cout << n.name << '-' << n.number << endl;
	}
	void printtwo() {
		for (auto n : collectiontwo)
			cout << n.name << '-' << n.number << endl;
	}
	int find(const mydata &tofind) {
		auto test = collectiontwo.find(tofind);
		int result = test->number;
		return result;
		
	}

};


int main()
{
	num_map dec;
	dec = num_map("one", 1);
	dec.set("two", 2);
	dec.set("three", 3);
	dec.set("four", 4);

	dec.print();
	cout << "-------" << endl;
	dec.printtwo();
	cout << "-------" << endl;

	mydata five ("five", 5);
	mydata six("six", 6);
	
	dec.set_2(five);
	dec.set_2(six);

	dec.print();
	cout << "-------" << endl;
	dec.printtwo();
	cout << "-------" << endl;

	cout << dec.find(five) << endl;

    return 0;
}

