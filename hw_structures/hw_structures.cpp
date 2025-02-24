#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

typedef struct {
	string name;
	int guarantee;
	float price;
} Monitor;

void fillArrayMonitors()
{
	string name;
	int guarantee;
	float price;
	vector<Monitor> monitors;
	cout << "�� ������ ����� � ��� '������������', ���� ������ ������." << endl;
	while (true)
	{
		cin.ignore();
		cout << "������ ������������ �������: ";
		getline(cin, name);
		if (name == "" || name=="1") break;
		cout << "������ ������� ������ �� ���� ������: ";
		cin >> guarantee;
		cout << "������ ���� �������: ";
		cin >> price;
		Monitor monitor = { name, guarantee, price };
		monitors.push_back(monitor);
		cin.ignore();

	}

	sort(monitors.begin(), monitors.end(), [](Monitor a, Monitor b) { return a.price < b.price; });
	reverse(monitors.begin(), monitors.end());
	for (int i = 0; i < monitors.size(); i++)
	{
		cout << "������: " << monitors[i].name << endl;
		cout << "�������: " << monitors[i].guarantee << " ������" << endl;
		cout << "ֳ��: " << monitors[i].price << " ���" << endl;
	}
	ofstream file("monitors.txt", ios::app);
	if (!file) {
		cout << "������� �������� �����" << endl;
		return;
	}

	int i = 0;
	while (file<<monitors)
	{
		file << monitors[i].name << ' ' << monitors[i].guarantee << ' ' << monitors[i].price << endl;
		i++;
	}
	file.close();
	if (name == "1") {
		ifstream file("monitors.txt");
		if (!file) {
			cout << "������� �������� �����" << endl;
			return;
		}
		string line;
		while (file >> line)
		{
			cout << line << endl;
		}
		file.close();
	}
}

int main()
{
	system("chcp 1251>null");

    fillArrayMonitors();
}


