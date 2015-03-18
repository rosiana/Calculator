#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	size_t pos = 0;
	string s1[11];
	cout << "Masukkan ekspresi matematika: ";
	cin >> s;
	int i = 0;
	cout << s<<endl;
	while(pos < s.length()){
		if(s.find(" ")!= string::npos){
			pos = s.find(" ");
			s1[i] = s.substr(0,pos);
			s.erase(0,pos+1);
			cout << s1[i] << endl;
			i++;
		}
		else if(s.find("+")!= string::npos){
			pos = s.find("+");
			s1[i] = s.substr(0,pos);
			s.erase(0,pos+1);
			cout << s1[i] << endl;
			i++;
		}
		else if(s.find("-")!= string::npos){
			pos = s.find("-");
			s1[i] = s.substr(0,pos);
			s.erase(0,pos+1);
			cout << s1[i] << endl;
			i++;
		}
		else if(s.find("*") != string::npos){
			pos = s.find("*");
			s1[i] = s.substr(0,pos);
			s.erase(0,pos+1);
			cout << s1[i] << endl;
			i++;
		}
		else if(s.find("/") != string::npos){
			pos = s.find("/");
			s1[i] = s.substr(0,pos);
			s.erase(0,pos+1);
			cout << s1[i] << endl;
			i++;
		}
		cout << "Pengulangan ke " << i << endl;
	}
	cout << s.substr(0,string::npos);
	return 0;
}
