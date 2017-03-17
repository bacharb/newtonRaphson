#include <iostream>
#include <sstream>      // std::istringstream
#include <fstream>

#include <vector>
#include <list>
#include<set>
#include<map>

using namespace std;

string ident(string arg){ // string passed by value (copied into arg)
	return arg; // return string (move the value of arg out of ident() to a caller)
}

struct Record {
	string label;
	int value;
};

bool operator<(const Record& a, const Record& b){
	return a.label<b.label;
}


template<typename T>
struct Named_val {
	string name;
	T value;
};

template <typename T>
ostream& operator<<(ostream& os, const Named_val<T>& nv) {
	return os << '{' << nv.name << ':' << nv.value << '}';
}

int main (){

	Named_val<Named_val<Named_val<float>>> interest {"koko",{"toto", {"roro", .0324}}};

	cout << interest << endl;

return 0;


	string s1 {"Adams"}; // initialize string (construct in s1).
	vector<string> v = {"Robert", "Khalid", "Fatna", "Hamza", "Pau"};
	s1 = ident(s1); // copy s1 into ident()

	// move the result of ident(s1) into s1;
	// s1’s value is "Adams".

	string s2 {"Pratchett"}; // initialize string (construct in s2)

	//s1 = s2; // copy the value of s2 into s1
// both s1 and s2 have the value "Pratchett".


	string s3{s1};
	vector<string> vs3{s1,s2};
//	for (auto name : vs3) cout << name << endl;

	int a {1};
	vector<int> va{1,2,3};

//	for (auto e : va) cout << e << endl;

  struct Work {
		string author;
		string name;
		int year;
	};

	Work s9;
	Work s4{"Chab Khald","Alaaita 4", 2020};


	Work none {}; // default initializatio
  Work w;
  vector<Work> currently_playing { s9, s4,none, none, none, none,w}; // copy initialization

	struct  X {
		float x;
		X(float x): x{x} {};
    float getValue() const {return x;};
	};

	struct Y : X {
		X m {0.0}; // provide default initializer for member m

		Y(float a) :X{a}, m{a} { }; // initialize base and member (§17.4)
		Y() : X{0.0} { }; // initialize base and member
	};

	X x2(0.0);
	auto alist = {1,2,3,4,5,6};
  vector<int> vlist = {1,2,3,4};

  vector<Y> vy;
  for (float r : {0.75,0.77,0.78}) 
  	vy.push_back(r);

 	X array[] {1,2,3}; // initialize array elements`
	X* p {nullptr};
	p = new X{4};

	vector<vector<string>> vv{{}, {}};

	vector<vector<double>> vs = {
		{10,11,12,13,14}, // OK: vector of five elements
		{10}, // OK: vector of one element
		//	10, // error : vector<double>(int) is explicit
		vector<double>{10,(float)11,12,13}, // OK: vector of five elements
		vector<double>{10}, // OK: vector of one element with value 10.0
		vector<double>(10), // OK: vector of 10 elements with value 0.0
	};

	list  <int> lst1 {1,2,3};
	vector<int> vect {1,2,3};

	string s;	

	set<Record> mr {{"duck",10}, {"pork",12}};
	set <int> toto{1,2,3};
//  for (auto x : mr) cout <<x.label << endl; 

	map <int, string> x { 
		{ 42, "foo" }, 
		{ 3,  "bar" } 
	};	
	int * pp = new int(1);  // allocation and construction
	x[42]="XXXX";


	struct PersonInfo {
		string name;
		vector<int> phones;
	};

	string line;
	int word;

	vector<PersonInfo> people; // will hold all the records from the input


  cerr 	<< "Hello Error1" << endl;
  clog	<< "Hello Log1" 	<< endl;
	ofstream f ("file.out");
	
	ofstream& g = f;
	g  << "Hello there " << endl;

	auto F = [](ofstream f) {};



return 0;
	while (getline(cin, line)) {
		PersonInfo info; // create an object to hold this record’s data

		istringstream record(line); // bind record to the line we just read
		
		record >> info.name; // read the name
		
		while (record >> word) info.phones.push_back(word); // and store them

		people.push_back(info); // append this record to people
	}

  auto valid = [](auto ) {return true;};
  auto format= [](auto x) {return x;};

	for (const auto &entry : people) { // for each entry in people
		ostringstream formatted, badNums; // objects created on each loop
		for (const auto &nums : entry.phones) { // for each number
			if (!valid(nums)) {
				badNums << " " << nums; // string in badNums
			} else
				// ‘‘writes’’ to formatted’s string
				formatted << " " << format(nums);
		}
		if (badNums.str().empty()) // there were no bad numbers
			cout<< entry.name << " " // print the name
				<< formatted.str() << endl; // and reformatted numbers
		else // otherwise, print the name and bad numbers
			cerr << "input error: " << entry.name
				<< " invalid number(s) " << badNums.str() << endl;
	}
  
}
