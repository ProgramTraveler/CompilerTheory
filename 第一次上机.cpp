#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

string token;
double num = 1;

bool isnum(string s) {
	stringstream sin(s);
	double t;
	char p;
	if (!(sin >> t)) {
		return false;
	}
	if (sin >> p) {
		return false;
	}
	num = t;
	return true;
}

int scanner(int i, vector<string>& s) {
	int res = 0;

	if (s[i] == "begin") {
		res = 1;

	}
	else if (s[i] == "if") {
		res = 2;
	}
	else if (s[i] == "then") {
		res = 3;
	}
	else if (s[i] == "while") {
		res = 4;
	}
	else if (s[i] == "do") {
		res = 5;
	}
	else if (s[i] == "end") {
		res = 6;
	}
	else if (s[i] == "+") {
		res = 13;
	}
	else if (s[i] == "-") {
		res = 14;
	}
	else if (s[i] == "*") {
		res = 15;
	}
	else if (s[i] == "/") {
		res = 16;
	}
	else if (s[i] == ":") {
		res = 17;
	}
	else if (s[i] == ":=") {
		res = 18;
	}
	else if (s[i] == "<") {
		res = 20;
	}
	else if (s[i] == "<>") {
		res = 21;
	}
	else if (s[i] == "<=") {
		res = 22;
	}
	else if (s[i] == ">") {
		res = 23;
	}
	else if (s[i] == ">=") {
		res = 24;
	}
	else if (s[i] == "=") {
		res = 25;
	}
	else if (s[i] == ";") {
		res = 26;
	}
	else if (s[i] == "(") {
		res = 27;
	}
	else if (s[i] == ")") {
		res = 28;
	}
	else if (s[i] == "#") {
		res = 0;
	}
	else if (isnum(s[i])) {
		res = 11; 
	}
	else {
		res = 10;
		token = s[i];
	}
	//cout << res << endl;
	return res;
}

int main() {


	int i = 0;

	vector<string> str;
	string ch;
	while (cin >> ch) {
		str.push_back(ch);
		if (ch == "#")
			break;
	}
	int syn;
	int index = 0;
	do {
		syn = scanner(index, str);
		//cout << "syn:" << syn << endl;
		switch (syn) {
			case 1 :
				cout << "(" << "1, " << "begin" << ")" << " "<<endl;
				break;
			case 2 :
				cout << "(" << "2, " << "if" << ")" << " " << endl;
				break;
			case 3 :
				cout << "(" << "3, " << "then" << ")" << " " << endl;
				break;
			case 4 :
				cout << "(" << "4, " << "while" << ")" << " " << endl;
				break;
			case 5 :
				cout << "(" << "5, " << "do" << ")" << " " << endl;
				break;
			case 6 :
				cout << "(" << "6, " << "end" << ")" << " " << endl;
				break;
			case 10 :
				cout << "(" << "10, " << token << ")" << " " << endl;
				break;
			case 11 :
				cout << "(" << "11, " << num << ")" << " " << endl;
				break;
			case 13 :
				cout << "(" << "13, " << "+" << ")" << " " << endl;
				break;
			case 14 :
				cout << "(" << "14, " << "-"<< ")" << " " << endl;
				break;
			case 15 :
				cout << "(" << "15, " << "*" << ")" << " " << endl;
				break;
			case 16 :
				cout << "(" << "16, " << "/" << ")" << " " << endl;
				break;
			case 17 :
				cout << "(" << "17, " << ":" << ")" << " " << endl;
				break;
			case 18 :
				cout << "(" << "18, " << ":="<< ")" << " " << endl;
				break;
			case 20 :
				cout << "(" << "20, " << "<" << ")" << " " << endl;
				break;
			case 21 :
				cout << "(" << "21, " << "<>" << ")" << " " << endl;
				break;
			case 22 :
				cout << "(" << "22, " << "<=" << ")" << " " << endl;
				break;
			case 23 :
				cout << "(" << "23, " << ">" << ")" << " " << endl;
				break;
			case 24 :
				cout << "(" << "24, " << ">=" << ")" << " " << endl;
				break;
			case 25 :
				cout << "(" << "25, " << "=" << ")" << " " << endl;
				break;
			case 26 :
				cout << "(" << "26, " << ";" << ")" << " " << endl;
				break;
			case 27 :
				cout << "(" << "27, " << "(" << ")" << " " << endl;
				break;
			case 28 :
				cout << "(" << "28, " << ")" << ")" << " " << endl;
				break;
			case 0 :
				cout << "(" << "0, " << "#" << ")" << " " << endl;
				break;
			case -1 :
				cout << "error" << endl;
				break;
		default:
			break;
		}
		index++;
	} while (syn != 0);

	for (int i = 0; i < str.size(); i ++)
		cout<<str[i];
	return 0;
}