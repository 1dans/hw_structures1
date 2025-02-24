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
//		cout << "Помилка відкриття файлу" << endl;
//		return;
//	}
//
//	for (int i = 0; i < monitors.size(); ++i)
//	{
//		file << monitors[i].name << ' ' << monitors[i].guarantee << ' ' << monitors[i].price << endl;
//	}
//	file.close();
//	cout << "Роботу завершено" << endl;
//
//}

void readFile(string fileName) {
	ifstream file(fileName);
	if (!file) {
		cout << "Помилка відкриття файлу" << endl;
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
	cout << "Роботу завершено" << endl;
}

//void fillArrayMonitors() //1
//{
//	string name;
//	int guarantee;
//	float price;
//	vector<Monitor> monitors;
//	cout << "Не вводіть нічого в полі 'найменування', якщо хочете зупинити." << endl;
//	while (true)
//	{
//		cout << "Введіть найменування монітора: ";
//		getline(cin, name);
//		if (name == "") break;
//		cout << "Введіть кількість місяців до кінця гарантії: ";
//		cin >> guarantee;
//		cout << "Введіть ціну монітора: ";
//		cin >> price;
//		Monitor monitor = { name, guarantee, price };
//		monitors.push_back(monitor);
//		cin.ignore();
//
//	}
//	int ans = 0;
//	cout << "Хочете відсортувати список за спаданням ціни? 1 - так, 0 - ні\n";
//	cin >> ans;
//	if (ans == 1) {
//		sort(monitors.begin(), monitors.end(), [](Monitor a, Monitor b) { return a.price < b.price; });
//		reverse(monitors.begin(), monitors.end());
//		cout << "Сортування завершено" << endl;
//
//	}
//	for (int i = 0; i < monitors.size(); i++)
//	{
//		cout << "Монітор: " << monitors[i].name << endl;
//		cout << "Гарантія: " << monitors[i].guarantee << " місяців" << endl;
//		cout << "Ціна: " << monitors[i].price << " грн" << endl;
//	}
//	cout << "Чи хотіли б ви зберегти дані в файл? 1 - так, 0 - ні\n";
//	cin >> ans;
//	if(ans==1) writeToFile("monitors.txt", monitors);
//	cout << "Чи хотіли б ви побачити дані, збережені в файлі? 1 - так, 0 - ні\n";
//	cin >> ans;
//	if (ans == 1) {
//		cout << setw(10) << left << "Монітори" << setw(15) << left << "Гарантія(міс)" << setw(10) << left << "Ціни"<<endl;
//		readFile("monitors.txt");
//	}
//}

int main()
{
	system("chcp 1251>null");
    //fillArrayMonitors(); //1
}
