#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	auto lambda1 = [] () { cout << "Hello world" << endl; };
	/* Due to no outer variable is captured, use "[]"
	 * Due to no parameter, can write as follow format as well:
	 * auto lambda1 = [] { ... };
	 * auto lambda1 = [] (void) { ... };
	 * Due to no return value (or the return type is void), can write as following format as well:
	 * auto lambda1 = [] () -> void { ... };
	 * Cannot discard "()" if "->" is written
	*/
	lambda1();

	int x = 1, y = 2;
	auto lambda2 = [=] () { cout << x + y << endl; };
	/* [=] means lambda function can capture some variables (i.e., x and y) that have been defined from the outside of the function scope by value 
	 * The change of captured variable will not affect its source varibale
	 * Can write as following format as well:
	 * auto lambda2 = [x, y] () { ... };
	*/
	lambda2();

	string s = "Hello world2";
	auto lambda3 = [&] () { s += "!"; };
	/* [&] means lambda function can capture some variables (i.e., s) that have been defined from the outside of the function scope by reference 
	 * The change of captured variable will also affect its source varibale
	 * Due to only one variable (i.e., s) captured, it is recommended to use individual capture, as following format:
	 * auto lambda3 = [&s] () { ... };
	*/
	lambda3();
	cout << s.c_str() << endl;
	
	vector<int> vec;
	for (int i=1; i<=10; ++i)
		vec.push_back(i);
	
	int modulo = 2;
	sort(vec.begin(), vec.end(), [&modulo] (int a, int b) { if (a % modulo > b % modulo) return true; else return a < b; });
	/* Use Lambda function to skip compare function declaration and definition in global */
	for (int& n : vec)
		cout << n << " ";

	cout << endl << "press Enter to continue" << endl;
	getc(stdin);
	return 0;
}