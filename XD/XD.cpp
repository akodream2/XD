#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>
using namespace std;

template <class T>
void PrintVector(vector<T> a) {
	for (auto el : a) {
		cout << el << " ";
	}
	cout << "\n";
}


class Machine {
	string name;
	int year;
	int price;
public:
	Machine() {}
	Machine(string name, int year, int price) {
		this->name = name;
		this->year = year;
		this->price = price;
	}
	void SetCar(string name, int year, int price) {
		this->name = name;
		this->year = year;
		this->price = price;
	}
	string GetName() const {
		return name;
	}
	int GetYear() const {
		return year;
	}
	int GetPrice() const {
		return price;
	}
	friend ostream& operator<<(ostream& os, const Machine& dt);
	friend bool operator <(const Machine fisrt, const Machine second);
	friend bool operator >(const Machine fisrt, const Machine second);
};
ostream& operator<<(ostream& os, const Machine& dt)
{
	os << "\nName:" << dt.name << "\nYear:" << dt.year << "\nPrice:" << dt.price << "\n";
	return os;
}
bool operator <(const Machine first, const Machine second) {
	return first.price < second.price;
}
bool operator >(const Machine first, const Machine second) {
	return first.price > second.price;
}



int menu() {
	int a;
	cout << "------------------------------\n";
	cout << "1-Add new car\n";
	cout << "2-Delete car(name)\n";
	cout << "3-Print data of all car\n";
	cout << "4-Sort car\n";

	cout << "5-Search for car\n";
	cout << "0-End sesion\n";
	cout << "Enter:";
	cin >> a;
	cout << "------------------------------\n";
	return a;
}

int main() {

	//������� �������� ��� ������ ����������. ��������� �������� ���������� ��� ��������, �� ���������� (�����, �� �������, ��'�� �������, ����). 
	// ��������� ��������� ��� ��������� �����, ��������� �����, ����������� �����, ���������� ����� �� ������ �����������, ������ ����� �� ������ �����������. 
	// ��� ��������� �������������� ����������, ��������, ������-������� �� ���������.
	//2
	vector<Machine> AutoCenter;
	int a = -1;
	while (a != 0) {
		a = menu();
		if (a == 1) {
			string name;
			int year;
			int price;
			cout << "Name:";
			cin >> name;
			cout << "Year:";
			cin >> year;
			cout << "Price:";
			cin >> price;
			Machine tmp(name, year, price);
			AutoCenter.push_back(tmp);
		}
		if (a == 2) {
			string name;
			cout << "Назва: ";
			cin >> name;
			AutoCenter.erase(
				remove_if(AutoCenter.begin(), AutoCenter.end(), [name](const Machine& tmp) {
					return tmp.GetName() == name;
					}),
				AutoCenter.end());

		}
		if (a == 3) {
			PrintVector(AutoCenter);
		}
		if (a == 4) {
			sort(AutoCenter.begin(), AutoCenter.end());
		}

		if (a == 5) {
			string name;
			cout << "Name:";
			cin >> name;
			auto it = find_if(AutoCenter.begin(), AutoCenter.end(), [name](Machine tmp) {
				return tmp.GetName() == name;
				});
			if (it != AutoCenter.end())
				cout << *it << "\n";
			else
				cout << "Car NOT FOUND!\n";


		}
		if (a == 0) cout << "Have a nice day";
	}










	cout << "\n";

	//XDXDXDXDXDXD






	//1
	//vector<int> a{72,10,56,172,-192, 19, -69, 1};


	//deleting
	/*int b = 72;
	remove(a.begin(), a.end(), b)*/



	//Increase or reduce the value in the container by the given constan
	/*vector<int> NewA;
	int const count = 5;
	copy(a.begin(), a.end(), back_inserter(NewA));

	for (int i = 0; i < count; i++)
	{
		NewA.push_back(rand());

	}
	PrintVector(NewA);*/

	/*vector<int> NewA;
	int const count = 5;
	for (auto numb : a) {
		if (NewA.size() == count) break;
		NewA.push_back(numb);
	}
	PrintVector(NewA);*/



	//sort
	/*sort(a.begin(), a.end());
	sort(a.begin(), a.end(), greater<int>());
	PrintVector(a);*/











	//find max or min
	// 
	//auto ans = find_if(a.begin(), a.end(), [a](int needs) {
	//	
	//	for (auto el : a) {
	//		if (needs < el)//change < to > for searching min number
	//			return false;
	//	}
	//	return true;
	//	});
	//cout << *ans;



	//another way
	/*int ans = *a.begin();
	for (auto el : a) {
		if (el > ans) ans = el;
	}
	cout << ans;

	cout << "\n";


	for (auto el : a) {
		if (el < ans) ans = el;
	}
	cout << ans;*/

}