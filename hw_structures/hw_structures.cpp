#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

//typedef struct { //1
//	string name;
//	int guarantee;
//	float price;
//} Monitor;
//
//void writeToFile(string fileName, vector<Monitor> monitors) { //1
//	ofstream file(fileName, ios::app);
//	if (!file) {
//		cout << "������� �������� �����" << endl;
//		return;
//	}
//
//	for (int i = 0; i < monitors.size(); ++i)
//	{
//		file << monitors[i].name << ' ' << monitors[i].guarantee << ' ' << monitors[i].price << endl;
//	}
//	file.close();
//	cout << "������ ���������" << endl;
//
//}

void readFile(string fileName) {
	ifstream file(fileName);
	if (!file) {
		cout << "������� �������� �����" << endl;
		return;
	}
	string word;
	int i = 0;
	while (file >> word)
	{
		if (i == 3) { cout << endl; i = 0; }
		cout << setw(13) << left << word;
		i++;
	}
	file.close();
	cout << "������ ���������" << endl;
}

//void fillArrayMonitors() //1
//{
//	string name;
//	int guarantee;
//	float price;
//	vector<Monitor> monitors;
//	cout << "�� ������ ����� � ��� '������������', ���� ������ ��������." << endl;
//	while (true)
//	{
//		cout << "������ ������������ �������: ";
//		getline(cin, name);
//		if (name == "") break;
//		cout << "������ ������� ������ �� ���� ������: ";
//		cin >> guarantee;
//		cout << "������ ���� �������: ";
//		cin >> price;
//		Monitor monitor = { name, guarantee, price };
//		monitors.push_back(monitor);
//		cin.ignore();
//
//	}
//	int ans = 0;
//	cout << "������ ����������� ������ �� ��������� ����? 1 - ���, 0 - �\n";
//	cin >> ans;
//	if (ans == 1) {
//		sort(monitors.begin(), monitors.end(), [](Monitor a, Monitor b) { return a.price < b.price; });
//		reverse(monitors.begin(), monitors.end());
//		cout << "���������� ���������" << endl;
//
//	}
//	for (int i = 0; i < monitors.size(); i++)
//	{
//		cout << "������: " << monitors[i].name << endl;
//		cout << "�������: " << monitors[i].guarantee << " ������" << endl;
//		cout << "ֳ��: " << monitors[i].price << " ���" << endl;
//	}
//	cout << "�� ����� � �� �������� ��� � ����? 1 - ���, 0 - �\n";
//	cin >> ans;
//	if(ans==1) writeToFile("monitors.txt", monitors);
//	cout << "�� ����� � �� �������� ���, �������� � ����? 1 - ���, 0 - �\n";
//	cin >> ans;
//	if (ans == 1) {
//		cout << setw(10) << left << "�������" << setw(15) << left << "�������(��)" << setw(10) << left << "ֳ��"<<endl;
//		readFile("monitors.txt");
//	}
//}

int main()
{
	system("chcp 1251>null");
    //fillArrayMonitors(); //1
}
