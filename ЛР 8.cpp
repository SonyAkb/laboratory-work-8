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
		cout << endl;

		mas_students[i].enter_inform(name_st, last_n_st, patr_st, data_st, addr_st, rat);
	}

	for (int i = 0; i < population; i++) {
		cout << "����� ��� ��������: " << i << endl;
		print(mas_students[i]);

	}

	int mas_index_del[max_size * 2]; //������ ��������� ��������
	int k = 0; //������� ������ ���������� ����������
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



	return 0;
}