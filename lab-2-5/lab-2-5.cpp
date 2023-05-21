#include "list_3.h"
#include "list_3.cpp"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	menu();
	return 0;
}

int failure() {
	int a;
	while (!(cin >> a) || (cin.peek() != '\n'))
	{
		// достигнут ли конец и введено ли больше одного "слова"
		cin.clear();
		while (cin.get() != '\n');
		cout << "\nОшибка ввода. Попробуйте снова.\n" << endl;
	}
	return a;
}


void menu() {
	int command, choice;
	type search_data;
	LinkedList l, del_l;
	while (true) {
		cout << "\nВыберите команду из списка:\n";
		cout << "1. Вывод текущего состояния списка на экран\n";
		cout << "2. Проверка пустоты списка\n";
		cout << "3. Вывод текущего состояния вспомогательного списка на экран\n";
		cout << "4. Добавить элемент в список\n";
		cout << "5. Удалить элемент из списка\n";
		cout << "6. Поиск элемента с заданной информационной частью\n";
		cout << "7. Очистить список\n";
		cout << "0. Завершить работу программы\n";
		cout << "Номер команды: ";
		command = failure();
		switch (command) {
		case 0:
			destroy(l);
			return;
			break;
		case 1:
			output_list(l);
			break;
		case 2:
			if (is_Empty(l)) cout << "Список пуст" << endl;
			else cout << "Список не пуст" << endl;
			break;
		case 3:
			output_list(del_l);
			break;
		case 4:
			push(l);
			break;
		case 5:
			if (is_Empty(l)) {
				cout << "Список пуст, удалять нечего" << endl;
			}
			else {
				cout << "Как выполнить удаление элемента?\n0. Удалить с освобождением памяти\n1. Добавить элемент в конец вспомогательного списка" << endl;
				choice = failure();
				if (choice == 0) {
					remove(l);
				}
				else if (choice == 1) {
					move_to_del_list(l, del_l);
				}
				else {
					cout << "Такой команды нет в меню" << endl;
				}
			}
			break;
		case 6:
			cout << "Введите информационную часть искомого элемента: " << endl;
			cin >> search_data;
			find(l, search_data);
			break;
		case 7:
			if (!is_Empty(l)) {
				destroy(l);
			}
			else {
				cout << "Список пуст, удалять нечего";
			}
			break;
		default:
			cout << "\nТакой команды нет, введите другое число" << endl;
			break;
		}
	}
}
