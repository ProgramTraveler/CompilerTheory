#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

string token;
double num = 1;
int len = 0;

bool isnum(char s) {
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

int scanner(int i, string s) {
	int res = 0;
	int index = i;
	len = 0;
	token = "";
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
		cout << "space" << endl;
		len ++;
		return -12;
	}
	/*if (s[i] == 'b') {
		if (s[i + 1] == 'e' && s[i + 2] == 'g' && s[i + 3] == 'i' && s[i + 4] == 'n' && (s[i + 5] - 'a' < 0 && s[i + 5] - 'a'  >25 )) {
			res = 1;
			//token = "begin";
		}
		else {
			res = 10;
			token += s[i];
		}

	}
	else if (s[i] == 'i') {
		if (s[i + 1] == 'f' &&(s[i + 2] - 'a' < 0 && s[i + 2] - 'a' > 25)) {
			
			res = 2;
			//token = "if";
		}
		else {
			res = 10;
			token += s[i];
		}
	}
	else if (s[i] == 't') {
		if (s[i + 1] == 'h' && s[i + 2] == 'e' && s[i + 3] == 'n' && (s[i + 4] - 'a' < 0 && s[i + 4] - 'a' > 25)) {
			res = 3;
			//token = "then";
		}
		else {
			res = 10;
			token = s[i];
		}
	}
	else if (s[i] == 'w') {
		if (s[i + 1] == 'h' && s[i + 2] == 'i' && s[i + 3] == 'l' && s[i + 4] == 'e' && (s[i + 5] - 'a' < 0 && s[i + 5] - 'a' > 25)) {
			res = 4;
			//token = "while";
		}
		else {
			res = 10;
			token = s[i];
		}
	}
	else if (s[i] == 'd') {
		if (s[i + 1] == 'o' && (s[i + 2] - 'a' < 0 && s[i + 2] - 'a' > 25)) {
			res = 5;
			//token = "do";
		}
		else {
			res = 10;
			token = s[i];
		}
	}
	else if (s[i] == 'e') {
		if (s[i + 1] == 'n' && s[i + 2] == 'd' && (s[i + 3] - 'a' < 0 && s[i + 3] - 'a' > 25)) {
			res = 6;
			//token = "end";
		}
		else {
			res = 10;
			token = s[i];
		}
	}
	else if (s[i] == '+') {
		res = 13;
	}
	else if (s[i] == '-') {
		res = 14;
	}
	else if (s[i] == '*') {
		res = 15;
	}
	else if (s[i] == '/') {
		res = 16;
	}
	else if (s[i] == ':') {
		if (s[i + 1] == '=')
			res = 18;
		else
			res = 17;

	}
	
	else if (s[i] == '<') {
		if (s[i + 1] == '>')
			res = 21;
		else if (s[i + 1] == '=')
			res = 22;
		else
			res = 20;
	}
	else if (s[i] == '>') {
		if (s[i + 1] == '=')
			res = 24;
		else 
			res = 23;
	}
	else if (s[i] == '=') {
		res = 25;
	}
	else if (s[i] == ';') {
		res = 26;
	}
	else if (s[i] == '(') {
		res = 27;
	}
	else if (s[i] == ')') {
		res = 28;
	}
	else if (s[i] == '#') {
		res = 0;
	}
	else if (isnum(s[i])) {
		res = 11; 
	}
	else {
		res = 10;
		token = s[i];
	}*/
	//cout << res << endl;
	return res;
}

int main() {


	int i = 0;

	cout << "请输入：" << endl;
	/*vector<char> str;
	char ch;
	cout << "请输入：" << endl;
	while (cin >> ch) {
		str.push_back(ch);
		if (ch == '#')
			break;
	}*/
	string str;

	getline(cin, str);

	cout << str << endl;

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
		/*if (syn == 1 || syn == 4) {
			index += 5;
		}
		else if (syn == 2 || syn == 5 || syn == 21 || syn == 24 || syn == 18 || syn == 22 || syn == 24) {
			index += 2;
		}
		else if (syn == 3) {
			index += 4;
		}
		else if (syn == 6) {
			index += 3;
		}
		else {
			index++;
		}*/
		index += len;
		cout << "index:" << index << endl;
	} while (syn != 0);
	cout << endl;
	cout << "最初的输入:" << endl;
	for (int i = 0; i < str.size(); i ++)
		//cout<<str[i];
	cout << endl;
	return 0;
}