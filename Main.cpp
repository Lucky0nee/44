#include <iostream>
#include <vector>
using namespace std;

class Dot {
public:
	Dot() {
		this->x = 0;
		this->y = 0;
	}

	void AddDot(float x, float y) {
		system("cls");
		this->x = x; saved_x.push_back(this->x);
		this->y = y; saved_y.push_back(this->y);
		Counter++;
	}
	void CopyLastDot() {
		system("cls");
		if (!Counter) {
			cout << "No dots yet\n";
			return;
		}
		this->x = -saved_x[Counter - 1]; saved_x.push_back(this->x);
		this->y = -saved_y[Counter - 1]; saved_y.push_back(this->y);
		Counter++;
	}

	void CoutAllDotsCord() {
		system("cls");
		if (!Counter) {
			cout << "No dots yet\n";
			return;
		}

		for (int i = 0; i < Counter; i++) {
			cout << i + 1<< ".\n";
			cout << "x = " << saved_x[i] << " ";
			cout << "y = " << saved_y[i] << " \n\n";
		}
	}
	static void Count() {
		system("cls");
		cout << "Amount of dots:" << Counter << "\n";
	}

	void ChangeXCord(int index, float x) {
		system("cls");
		if (index >= Counter || index <= 0) {
			cout << "No dots with index " << index + 1 << "\n";
			return;
		}
		saved_x[index] = x;
		cout << "Successful\n";
	}
	void ChangeYCord(int index, int y) {
		system("cls");
		if (index >= Counter || index <= 0) {
			cout << "No dots with index " << index + 1 << "\n";
			return;
		}
		saved_y[index] = y;
		cout << "Successful\n";
	}

private:
	vector <float> saved_x;
	vector <float> saved_y;
	static int Counter;
	float x;
	float y;
};
int Dot::Counter = 0;

int main() {
	Dot Dots; string line;
	float cord, x, y;
	int index;
	while (true) {
		cout << "1. Make a dot" << "\n";
		cout << "2. Make a dot based on the last point, but with opposite coordinates" << "\n";
		cout << "3. Change a dot" << "\n";
		cout << "4. Show all dots" << "\n";
		cout << "5. Show Amount of dots" << "\n";
		cout << "6. Leave" << "\n";
		cout << "->"; cin >> line;
		if (line == "1") {
			cout << "Enter x cord:"; cin >> x;
			cout << "Enter y cord:"; cin >> y;
			Dots.AddDot(x, y);
		}
		else if (line == "2") {
			Dots.CopyLastDot();
		}
		else if (line == "3") {
			cout << "Number of dot:"; cin >> index;
			cout << "X or Y ?:"; cin >> line;
			if (line == "X") {
				cout << "New X cord:"; cin >> cord;
				Dots.ChangeXCord(index - 1, cord);
			}
			else if (line == "Y") {
				cout << "New Y cord:"; cin >> cord;
				Dots.ChangeYCord(index - 1, cord);
			}
			else
				cout << "Error, try again\n";
		}
		else if (line == "4") {
			Dots.CoutAllDotsCord();
		}
		else if (line == "5") {
			Dots.Count();
		}
		else if (line == "6") {
			system("cls");
			cout << "Bye";
			break;
		}
	}

	return 0;
}
/*
Опишіть і реалізуйте клас «Точка». У класі треба зберігати координати x, y.
Клас має мати

конструктор для створення точки із заданими координатами і
створення точки на основі існуючої, але з протилежними координатами.
Створіть функції класу для
введення даних, 
виведення даних,
редагування окремих змінних,
виводу повідомлень про те, скільки точок наразі створено.
*/
