#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct student { //��������� �������
	string name = "����"; //���
	string last_name = "������"; //�������
	string patronymic = "��������"; //��������
	string data = "01.01.2000"; //���� �������� � ������� ��.��.����
	string address = "������������� ��������, 29"; //�������� �����
	int rating = 50; //������� �� 0 �� 100

	void enter_inform(string n, string l, string p, string d, string a, int r) { //���� ���������� � ��������
		name = n; //���
		last_name = l; //�������
		patronymic = p; //��������
		data = d; //���� �������� � ������� ��.��.����
		address = a; //�������� �����
		rating = r; //������� �� 0 �� 100
	}
	
};

bool check_mas(int* ptr, int index, int len) { //�������� ������� �������� � �������
	bool flag = false;
	for (int i = 0; i < len && !flag; i++) {
		if (index == ptr[i]) { //���� ������� ������
			flag = true;
		}
	}
	return flag;
}

void create_student(string& name_st, string& last_n_st, string& patr_st, string& data_st, string& addr_st, int& rat) { 
	//���� ���������� ��������

	cout << "������� ������� ��������: ";
	cin >> last_n_st; //�������
	//cout << "������� ��� ��������: ";
	//cin >> name_st; //���
	//cout << "������� �������� ��������: ";
	//cin >> patr_st; //��������
	cout << "������� ���� �������� �������� (� ������� ��.��.����): ";
	cin >> data_st; //���� �������� � ������� ��.��.����
	//cout << "������� �������� ����� ��������: ";
	//cin.ignore();
	//getline(cin, addr_st); //�������� �����

	//do {
	//	cout << "������� ������� ��������: ";
	//	cin >> rat; //������� �� 0 �� 100
	//} while (rat < 0 || rat > 100);
	//cout << endl;
	
}

//bool last_name_search(struct student* N, int quantity, string last_name) { //�������� ������� �������
//	bool flag = false;
//	for (int i = 0; i < quantity && !flag; i++) {
//		if (last_name == N[i].last_name) {
//			flag = true;
//		}
//	}
//	return flag;
//}

int last_name_search(struct student* N, int quantity, string last_name) { //�������� ������� �������
	int index = -1;
	for (int i = 0; i < quantity && index == -1; i++) {
		if (last_name == N[i].last_name) {
			index = i;
		}
	}
	return index;
}

void writing_to_a_file(ofstream& file, struct student* N, int index) { //������ � ���� ������������� ��������
	file << N[index].last_name << ' ' << N[index].name << N[index].patronymic << N[index].data << N[index].address << N[index].rating << endl;
}

void print(student N) { //������ ��������� ��������
	cout << "����� ��������: ";
	cout << N.last_name << ' ' << N.name << ' ' << N.patronymic << ' ' << N.data << ' ' << N.address << ' ' << N.rating << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	system("cls");

	const int max_size = 50;
	student mas_students[max_size]; //������ ���� ���������
	int population; //���������� ���������

	string name_st, last_n_st, patr_st, data_st, addr_st;
	int rat = 0;

	do {
		cout << "������� ���������� ��������� (�� 1 �� " << max_size << "): ";
		cin >> population; //���������� ���������
	} while (population<1 || population>max_size);

	for (int i = 0; i < population; i++) { //����� ������ ���� ���������
		create_student(name_st, last_n_st, patr_st, data_st, addr_st, rat);
		mas_students[i].enter_inform(name_st, last_n_st, patr_st, data_st, addr_st, rat);
	}

	for (int i = 0; i < population; i++) { //////////////////---------------------------
		cout << "����� ��� ��������: " << i << endl;
		print(mas_students[i]);

	}

	int mas_index_del[max_size * 2]; //������ ��������� ��������
	int k = 0; //������� ������ ���������� ����������
	bool check; //������������� ����������
	for (int i = 0; i < population - 1; i++) {
		for (int j = i + 1; j < population; j++) {
			if (mas_students[i].data == mas_students[j].data) {
				mas_index_del[k] = i; //�������� � ������ ������ ������� ����������
				mas_index_del[k + 1] = j; //�������� � ������ ������ ������� ����������
				k += 2; //���������� ��������� ������� �������
			}
		}
	}

	for (int i = 0; i < k; i++) {
		cout << mas_index_del[i] << ' ';
	}

	string surname; //����������� �������
	int index_new_surname; //������ ����������� �������
	cout << "������� �������: "; ////////////����� �������� �������� �������
	cin >> surname; //����� ����� �������
	index_new_surname = last_name_search(mas_students, population, surname); //������ ������ �������
	while (index_new_surname == -1) {
		cout << "����� ������� ���. ������� ������������ �������: ";
		cin >> surname;
		index_new_surname = last_name_search(mas_students, population, surname); //������ ������ �������
	}

	create_student(name_st, last_n_st, patr_st, data_st, addr_st, rat); //���������� ������ � ��������
	mas_students[population].enter_inform(name_st, last_n_st, patr_st, data_st, addr_st, rat); //�������� ��������
	//++population; //���������� ���������� ���������

	

	for (int i = 0; i < population; i++) { //////////////////---------------------------
		cout << "����� ��� ��������: " << i << endl;
		print(mas_students[i]);

	}

	ofstream output("F3.txt"); // ��������� ����� ��� ������

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
	cout << "������ � ���� ���������!" << endl;

	return 0;
}