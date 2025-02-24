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
	cout << "Не вводіть нічого в полі 'найменування', якщо хочете зупити." << endl;
	while (true)
	{
		cin.ignore();
		cout << "Введіть найменування монітора: ";
		getline(cin, name);
		if (name == "" || name=="1") break;
		cout << "Введіть кількість місяців до кінця гарантії: ";
		cin >> guarantee;
		cout << "Введіть ціну монітора: ";
		cin >> price;
		Monitor monitor = { name, guarantee, price };
		monitors.push_back(monitor);
		cin.ignore();

	}

	sort(monitors.begin(), monitors.end(), [](Monitor a, Monitor b) { return a.price < b.price; });
	reverse(monitors.begin(), monitors.end());
	for (int i = 0; i < monitors.size(); i++)
	{
		cout << "Монітор: " << monitors[i].name << endl;
		cout << "Гарантія: " << monitors[i].guarantee << " місяців" << endl;
		cout << "Ціна: " << monitors[i].price << " грн" << endl;
	}
	ofstream file("monitors.txt", ios::app);
	if (!file) {
		cout << "Помилка відкриття файлу" << endl;
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
			cout << "Помилка відкриття файлу" << endl;
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


