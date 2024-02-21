#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct student { //структура Студент
	string name = "Иван"; //имя
	string last_name = "Иванов"; //фамилия
	string patronymic = "Иванович"; //отчество
	string data = "01.01.2000"; //дата рождения в формате ДД.ММ.ГГГГ
	string address = "Комсомольский проспект, 29"; //домашний адрес
	int rating = 50; //рейтинг от 0 до 100

	void enter_inform(string n, string l, string p, string d, string a, int r) { //ввод информации о студенте
		name = n; //имя
		last_name = l; //фамилия
		patronymic = p; //отчество
		data = d; //дата рождения в формате ДД.ММ.ГГГГ
		address = a; //домашний адрес
		rating = r; //рейтинг от 0 до 100
	}
	
};

void print(student N) { //вывожу параметры студента
	cout << "Вывод студента: ";
	cout << N.last_name << ' ' << N.name << ' ' << N.patronymic << ' ' << N.data << ' ' << N.address << ' ' << N.rating << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	system("cls");

	const int max_size = 50;
	student mas_students[max_size]; //массив всех студентов
	int population; //количество студентов

	string name_st, last_n_st, patr_st, data_st, addr_st;
	int rat = 0;

	do {
		cout << "Введите количество студентов (от 1 до " << max_size << "): ";
		cin >> population; //количество студентов
	} while (population<1 || population>max_size);

	for (int i = 0; i < population; i++) { //ввожу данные всех студентов
		cout << "Введите Фамилию студента: ";
		cin >> last_n_st; //фамилия
		//cout << "Введите Имя студента: ";
		//cin >> name_st; //имя
		//cout << "Введите Отчество студента: ";
		//cin >> patr_st; //отчество
		cout << "Введите дату рождения студента (в формате ДД.ММ.ГГГГ): ";
		cin >> data_st; //дата рождения в формате ДД.ММ.ГГГГ
		//cout << "Введите домашний адрес студента: ";
		//cin.ignore();
		//getline(cin, addr_st); //домашний адрес

		//do {
		//	cout << "Введите рейтинг студента: ";
		//	cin >> rat; //рейтинг от 0 до 100
		//} while (rat < 0 || rat > 100);
		cout << endl;

		mas_students[i].enter_inform(name_st, last_n_st, patr_st, data_st, addr_st, rat);
	}

	for (int i = 0; i < population; i++) {
		cout << "ВЫВОД имя студента: " << i << endl;
		print(mas_students[i]);

	}

	int mas_index_del[max_size * 2]; //массив удаленных индексов
	int k = 0; //текущий индекс последнего удаленного
	for (int i = 0; i < population - 1; i++) {
		for (int j = i + 1; j < population; j++) {
			if (mas_students[i].data == mas_students[j].data) {
				mas_index_del[k] = i; //добавляю в массив индекс первого совпадения
				mas_index_del[k + 1] = j; //добавляю в массив индекс второго совпадения
				k += 2; //увеличивую последний текущий элемент
			}
		}
	}

	for (int i = 0; i < k; i++) {
		cout << mas_index_del[i] << ' ';
	}



	return 0;
}