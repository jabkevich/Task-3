#include <iostream>
#include<string>
#include<fstream>
#include<string.h>
#include<map>
using namespace std;


class Example {
protected: 
	struct Roots {
		string error="";
		float x[10];
		float answer;
		string Answer;
	};


public:
	virtual string decision(string a) = 0;
	
};


class check_Example {
public: 

};
class  Quadratic_example : public Example {
private: 
	int pos;
	string num;
	float a;
	float b;
	float c;
	float D;
	string answer;
public:
	int Pos(string example) {
		for (int i = 0; i < example.size(); i++) {
			if (example[i] == '+') {
				return i;
			}
			if (example[i] == '-') {
				return i; 
			}
		}
	}
	string decision(string example) override {
		
		num = example.substr(0, example.find('x'));
		a = stoi(num);
		pos=Pos(example);
		example.erase(0, pos);
	
		num = example.substr(0, example.find('x'));
		b = stoi(num);
		example.erase(0, 1);
		pos = Pos(example);
		example.erase(0, pos);
		
		num = example.substr(0, example.find('='));

		c = stoi(num);
		D = b * b - 4 *a*c;
		
		if (D >= 0) {
			D = sqrt(D);
			answer += "x1= ";
			answer += to_string(+(-b + D) / (2 * a));
			answer += "x2= ";
			answer += to_string((-b - D) / (2 * a));
			return answer;
		}
		else if (D < 0) {
			return "нет корней";
		}
		
	}
	
};


class Add :public Example {
private:
	string Snum;
	int num=0;
	string answer="";
public:

	string decision(string example) override {
		for (int i = 0; i < example.size(); i++) {
			if (example[i] == '+') {
				num += stoi(Snum);
				Snum = "";
				i++; 
			}
				Snum += example[i];
		}
		num += stoi(Snum);
		answer = to_string(num);
		return answer;
		}
		
};
		

	


class  Subtraction : public Example {
private:
	string Snum;
	int num=0;
	string answer="";
public:

	
	string decision(string example) override {
			for (int i = 0; i < example.size(); i++) {
				if (example[i] == '-') {
					num += stoi(Snum);
					Snum = "";
					i++;
				}
				Snum += example[i];
			}
			num -= stoi(Snum);
			answer = to_string(num);
			return answer;
		}
	

};

class Multiplication :public Example {
private:
	string Snum;
	int num=0;
	string answer;
public:


	string decision(string example) override {
		for (int i = 0; i < example.size(); i++) {
			if (example[i] == '*') {
				num += stoi(Snum);
				Snum = "";
				i++;
			}
			Snum += example[i];
		}
		num *= stoi(Snum);
		answer = to_string (num);
		return answer;
	}

};

class Division : public Example {
private:
	string Snum;
	float num=0;
	string answer;
public:


	string decision(string example) override {
		for (int i = 0; i < example.size(); i++) {
			if (example[i] == '/') {
				num += stoi(Snum);
				Snum = "";
				i++;
			}
			Snum += example[i];
		}
		num /= stoi(Snum);
		answer = to_string(num);
		return answer;
	}

};

class Decision_Example {
public:
	string decision(Example *example, string a) {
		return example->decision(a);
	}
};


void Prim() {
	ifstream infile("input.TXT");
	string buffer;
	//Decision_Example decision_Example[5]; (попытка избежать кэсы(не вышло))
	Decision_Example decision_Example; //а еще мне не пон€тно, почему € не могу создать экземпл€р класса внутре кэса
	Quadratic_example Quadr;
	Add add;
	Subtraction sub;
	Multiplication mul;
	Division division;


    getline(infile, buffer);
	char a = buffer[0];
	buffer.erase(0, 3);
	switch (a) //€ очень очень думал как избежать кэсы, но у мен€ не вышло
	{
	case '1': 
		cout<< decision_Example.decision(&Quadr, buffer)<<endl;
		break;
	case'2':
		cout<< decision_Example.decision(&add, buffer)<<endl;
		break;
	case'3':
		cout<< decision_Example.decision(&sub, buffer)<<endl;
		break;
	case'4':
		cout<<decision_Example.decision(&mul, buffer)<<endl;
		break;
	case'5':
		cout<< decision_Example.decision(&division, buffer)<<endl;
		break;
	}


}


int main() {
	setlocale(LC_ALL, "rus");
	Prim();
	system("pause");
	return 0;
}

