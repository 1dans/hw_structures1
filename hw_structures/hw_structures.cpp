#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

//typedef struct { //2
//	string engine, color;
//	int ownersAmount;
//} Desc;
//
//typedef struct { //2
//	Desc desc;
//	string firm, model;
//	int year;
//	float price;
//	bool bargain;
//} Car;
//
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
//	cout << "Запис у файл завершено" << endl;
//
//}
//
void readFile(string fileName) { //всі
	int lineLen, spaceLen=10;
	if (fileName == "car.txt") lineLen = 8; 
	else lineLen = 3;
	ifstream file(fileName);
	if (!file) {
		cout << "Помилка відкриття файлу" << endl;
		return;
	}
	string word;
	int i = 0;
	while (file >> word)
	{
		if (i == lineLen) { cout << endl; i = 0; }
		cout << setw(spaceLen) << left << word;
		i++;
	}
	file.close();
	cout << "\nРоботу з файлом завершено\n";
}

//void writeToFile(string fileName, vector<Car> cars); //2
//void fillArrayCars(); //2
//
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
//	if (ans == 1) readFile("monitors.txt");
//}

int main()
{
	system("chcp 1251>null");
    //fillArrayMonitors(); //1
	//fillArrayCars(); //2
	return 0;
}

//void writeToFile(string fileName, vector<Car> cars) //2
//{
//	ofstream file(fileName, ios::app);
//	if (!file) {
//		cout << "Помилка відкриття файлу" << endl;
//		return;
//	}
//
//	for (int i = 0; i < cars.size(); ++i)
//	{
//		file << cars[i].firm << ' ' << cars[i].model << ' ' << cars[i].year << ' ' << cars[i].price << ' ' << cars[i].bargain << ' ' << cars[i].desc.color << ' ' << cars[i].desc.engine << ' ' << cars[i].desc.ownersAmount << endl;
//	}
//	file.close();
//	cout << "Запис у файл завершено" << endl;
//
//}
//
//void fillArrayCars() //2
//{
//	Desc desc;
//	string firm, model;
//	int year;
//	float price;
//	bool bargain;
//	vector<Car> cars;
//	cout << "Не вводіть нічого в полі 'фірма', якщо хочете зупинити." << endl;
//	while (true)
//	{
//		cout << "Введіть фірму авто: ";
//		getline(cin, firm);
//		if (firm == "") break;
//		cout << "Введіть модель: ";
//		getline(cin, model);
//		cout << "Введіть колір: ";
//		getline(cin, desc.color);
//		cout << "Введіть двигун авто: ";
//		getline(cin, desc.engine);
//		cout << "Введіть кількість власників: ";
//		cin >> desc.ownersAmount;
//		cout << "Введіть рік випуску: ";
//		cin >> year;
//		cout << "Введіть ціну: ";
//		cin >> price;
//		cout << "Чи є можливість торгу? 1 - так, 0 - ні\n";
//		cin >> bargain;
//		Car car = { desc, firm, model, year, price, bargain };
//		cars.push_back(car);
//		cin.ignore();
//	}
//	writeToFile("car.txt", cars);
//	readFile("car.txt");
//}
