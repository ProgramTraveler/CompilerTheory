#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

string token;
string num ;
int len = 0;

bool isnum(char s) {
	if (isdigit(s) != 0) {
		return true;
	}
	else return false;
}

int scanner(int i, string s) {
	int res = 0;
	int index = i;
	len = 0;
	token = "";
	num = "";
	if (s[index] - 'a' >= 0 && s[index] - 'a' <= 25) {
		while (index < s.size() && s[index] - 'a' >= 0 && s[index] - 'a' <= 25) {
			if (s[index] == ' ') break;
			token += s[index];
			index++;
			len++;
		}
		if (token == "begin") return 1;
		else if (token == "if") return 2;
		else if (token == "then") return 3;
		else if (token == "while") return 4;
		else if (token == "do") return 5;
		else if (token == "end") return 6;
		else return 10;
	}
	if (s[index] == ' ') { 
		//cout << "space" << endl;
		len ++;
		return -12;
	}
	else if (s[index] == '+') {
		res = 13;
		len ++;
	}
	else if (s[index] == '-') {
		res = 14;
		len ++;
	}
	else if (s[index] == '*') {
		res = 15;
		len ++;
	}
	else if (s[index] == '/') {
		res = 16;
		len ++;
	}
	else if (s[index] == ':') {
		if (s[index + 1] == '=') {
			res = 18;
			len += 2;
		}
		else {
			res = 17;
			len ++;
		}


	}
	else if (s[index] == '<') {
		if (s[index + 1] == '>') {
			res = 21;
			len += 2;
		}
		else if (s[index + 1] == '=') {
			res = 22;
			len += 2;
		}
		else {
			res = 20;
			len++;
		}
	}
	else if (s[index] == '>') {
		if (s[index + 1] == '=') {
			res = 24;
			len += 2;
		}
		else {
			res = 23;
			len ++;
		}
	}
	else if (s[index] == '=') {
		res = 25;
		len ++;
	}
	else if (s[index] == ';') {
		res = 26;
		len ++;
	}
	else if (s[index] == '(') {
		res = 27;
		len ++;
	}
	else if (s[index] == ')') {
		res = 28;
		len ++;
	}
	else if (s[index] == '#') {
		res = 0;
	}
	else if (isnum(s[index])) {
		while (isnum(s[index])) {
			len ++;
			num += s[index];
			index++;

		}
		res = 11;
	}
	return res;
}

int main() {


	int i = 0;

	cout << "请输入：" << endl;
	string str;

	getline(cin, str);

	//cout << str << endl;

	int syn;
	int index = 0;
	cout << endl;
	cout << "词法分析结果："<<endl;
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
		index += len;
	} while (syn != 0);
	return 0;
}