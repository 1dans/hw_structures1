#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef struct {
	string surname;
	char gender;
	double averageMark;
} Student;

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
//		cout << "������� �������� �����" << endl;
//		return;
//	}
//
//	for (int i = 0; i < monitors.size(); ++i)
//	{
//		file << monitors[i].name << ' ' << monitors[i].guarantee << ' ' << monitors[i].price << endl;
//	}
//	file.close();
//	cout << "����� � ���� ���������" << endl;
//
//}
//
void readFile(string fileName) { //��
	int lineLen, spaceLen=10;
	if (fileName == "car.txt") lineLen = 8; 
	else lineLen = 3;
	ifstream file(fileName);
	if (!file) {
		cout << "������� �������� �����" << endl;
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
	cout << "\n������ � ������ ���������\n";
}

void fillArrayStudents(); //3
void findHigherAverageMark(vector<Student> students); //3

//void writeToFile(string fileName, vector<Car> cars); //2
//void fillArrayCars(); //2
//
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
//	if (ans == 1) readFile("monitors.txt");
//}

int main()
{
	system("chcp 1251>null");
    //fillArrayMonitors(); //1
	//fillArrayCars(); //2
	fillArrayStudents(); //3
	return 0;
}

//void writeToFile(string fileName, vector<Car> cars) //2
//{
//	ofstream file(fileName, ios::app);
//	if (!file) {
//		cout << "������� �������� �����" << endl;
//		return;
//	}
//
//	for (int i = 0; i < cars.size(); ++i)
//	{
//		file << cars[i].firm << ' ' << cars[i].model << ' ' << cars[i].year << ' ' << cars[i].price << ' ' << cars[i].bargain << ' ' << cars[i].desc.color << ' ' << cars[i].desc.engine << ' ' << cars[i].desc.ownersAmount << endl;
//	}
//	file.close();
//	cout << "����� � ���� ���������" << endl;
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
//	cout << "�� ������ ����� � ��� '�����', ���� ������ ��������." << endl;
//	while (true)
//	{
//		cout << "������ ����� ����: ";
//		getline(cin, firm);
//		if (firm == "") break;
//		cout << "������ ������: ";
//		getline(cin, model);
//		cout << "������ ����: ";
//		getline(cin, desc.color);
//		cout << "������ ������ ����: ";
//		getline(cin, desc.engine);
//		cout << "������ ������� ��������: ";
//		cin >> desc.ownersAmount;
//		cout << "������ �� �������: ";
//		cin >> year;
//		cout << "������ ����: ";
//		cin >> price;
//		cout << "�� � ��������� �����? 1 - ���, 0 - �\n";
//		cin >> bargain;
//		Car car = { desc, firm, model, year, price, bargain };
//		cars.push_back(car);
//		cin.ignore();
//	}
//	writeToFile("car.txt", cars);
//	readFile("car.txt");
//}

void fillArrayStudents() { //3
	string surname;
	char gender = ' ';
	double averageMark;
	vector<Student> students;
	cout << "������� ���� '�������' �������, ���� ������ �������� ��������." << endl;
	while (true) {
		cout << "������� ��������: ";
		getline(cin, surname);
		if (surname == "") break;
		cout << "����� (M/W, �/�): ";
		cin>>gender;
		cout << "������� ���: ";
		cin >> averageMark;
		Student student = { surname, gender, averageMark };
		students.push_back(student);
		cin.ignore();
	}
	findHigherAverageMark(students);
}

void findHigherAverageMark(vector<Student> students)
{
	int countW = 0, countM = 0;
	double averageW = 0, averageM = 0, marksW = 0, marksM = 0;
	for (auto i : students)
	{
		if (i.gender == 'w' || i.gender == 'W' || i.gender=='�' || i.gender=='�')
		{
			countW++;
			marksW += i.averageMark;
		}
		else
		{
			countM++;
			marksM += i.averageMark;
		}
	}
	averageW = marksW / countW;
	averageM = marksM / countM;
	cout << "������� ������� ��� � " << ((averageM > averageW) ? "�������" : "����") << endl;
	cout << "������� ��� ����: " << averageW << ". ������� ��� �������: " << averageM << endl;
}
