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

bool check_mas(int* ptr, int index, int len) { //проверяю наличие элемента в массиве
	bool flag = false;
	for (int i = 0; i < len && !flag; i++) {
		if (index == ptr[i]) { //если элемент найден
			flag = true;
		}
	}
	return flag;
}

void create_student(string& name_st, string& last_n_st, string& patr_st, string& data_st, string& addr_st, int& rat) { 
	//ввод параметров студента

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
	//cout << endl;
	
}

//bool last_name_search(struct student* N, int quantity, string last_name) { //проверяю наличие фамилии
//	bool flag = false;
//	for (int i = 0; i < quantity && !flag; i++) {
//		if (last_name == N[i].last_name) {
//			flag = true;
//		}
//	}
//	return flag;
//}

int last_name_search(struct student* N, int quantity, string last_name) { //проверяю наличие фамилии
	int index = -1;
	for (int i = 0; i < quantity && index == -1; i++) {
		if (last_name == N[i].last_name) {
			index = i;
		}
	}
	return index;
}

void writing_to_a_file(ofstream& file, struct student* N, int index) { //запись в файл определенного студента
	file << N[index].last_name << ' ' << N[index].name << N[index].patronymic << N[index].data << N[index].address << N[index].rating << endl;
}

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
		create_student(name_st, last_n_st, patr_st, data_st, addr_st, rat);
		mas_students[i].enter_inform(name_st, last_n_st, patr_st, data_st, addr_st, rat);
	}

	for (int i = 0; i < population; i++) { //////////////////---------------------------
		cout << "ВЫВОД имя студента: " << i << endl;
		print(mas_students[i]);

	}

	int mas_index_del[max_size * 2]; //массив удаленных индексов
	int k = 0; //текущий индекс последнего удаленного
	bool check; //промежуточная переменная
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

	string surname; //необходимая фамилия
	int index_new_surname; //индекс необходимой фамилии
	cout << "Введите фамилию: "; ////////////можно добавить перечинь фамилий
	cin >> surname; //ввожу новую фамилию
	index_new_surname = last_name_search(mas_students, population, surname); //индекс нужной фамилии
	while (index_new_surname == -1) {
		cout << "Такой фамилии нет. Введите существующую фамилию: ";
		cin >> surname;
		index_new_surname = last_name_search(mas_students, population, surname); //индекс нужной фамилии
	}

	create_student(name_st, last_n_st, patr_st, data_st, addr_st, rat); //запрашиваю данные о студенте
	mas_students[population].enter_inform(name_st, last_n_st, patr_st, data_st, addr_st, rat); //добавляю студента
	//++population; //увеличиваю количество студентов

	

	for (int i = 0; i < population; i++) { //////////////////---------------------------
		cout << "ВЫВОД имя студента: " << i << endl;
		print(mas_students[i]);

	}

	ofstream output("F3.txt"); // Включение файла для записи

	for (int i = 0; i < index_new_surname + 1; i++) {
		if (!check_mas(mas_index_del, i, population)) {
			//output << mas_students[i].last_name << ' ' << mas_students[i].name << mas_students[i].patronymic << mas_students[i].data << mas_students[i].address << mas_students[i].rating;
			writing_to_a_file(output, mas_students, i);
		}
	}
	writing_to_a_file(output, mas_students, population);
	for (int i = index_new_surname; i < population; i++) {
		if (!check_mas(mas_index_del, i, population)) {
			//output << mas_students[i].last_name << ' ' << mas_students[i].name << mas_students[i].patronymic << mas_students[i].data << mas_students[i].address << mas_students[i].rating;
			writing_to_a_file(output, mas_students, i);
		}
	}
	cout << "Запись в файл завершена!" << endl;

	return 0;
}