#include "list_3.h"
using namespace std;

bool is_Empty(LinkedList& list) {
	return list.first == nullptr;
}

void find(LinkedList& list, type data) {
	Node* cur = list.first;
	int count = 0;
	if (is_Empty(list)) {
		cout << "Список пуст, искать нечего" << endl;
	}
	else {
		while (cur != nullptr && cur->data != data) {
			cur = cur->next;
			count++;
		}
		if (cur != nullptr) cout << "Искомый элемент найден под индексом: " << count << endl;
		else cout << "Элемент не найден" << endl;
	}
}

void push(LinkedList& list) {
	int command;
	Node* cur = list.first, * prev = list.first;
	type data, push_data;
	cout << "Введите элемент, который хотите добавить" << endl;
	cin >> push_data;
	if (is_Empty(list)) {
		list.first = new Node;
		list.first->data = push_data;
		list.first->next = nullptr;
		list.count++;
	}
	else {
		cout << "Введите элемент, относительно которого хотите выполнить добавление" << endl;
		cin >> data;
		cout << "Введите способ добавления:\n0. Вставить перед элементом\n1. Вставить после элемента" << endl;
		command = failure();
		if (command == 0) {
			if (list.first->data == data) {
				list.first = new Node;
				list.first->next = cur;
				list.first->data = push_data;
				list.count++;
			}
			else {
				if (cur != nullptr) cur = cur->next;
				while (cur != nullptr && cur->data != data) {
					cur = cur->next; prev = prev->next;
				}
				if (cur != nullptr) {
					prev->next = new Node;
					prev->next->next = cur;
					prev->next->data = push_data;
					list.count++;
				}
				else {
					cout << "Элемент не найден" << endl;
				}
			}
		}
		else if (command == 1) {
			while (cur != nullptr && cur->data != data) {
				cur = cur->next;
			}
			if (cur != nullptr) {
				prev = cur->next;
				cur->next = new Node;
				cur->next->next = prev;
				cur->next->data = push_data;
				list.count++;
			}
			else {
				cout << "Элемент не найден" << endl;
			}
		}

	}
}

type remove(LinkedList& list) {
	type del_data = '\0', data;
	if (is_Empty(list)) {
		cout << "Список пуст, удалять нечего" << endl;
	}
	else {
		Node* cur = list.first, * prev = list.first;
		cout << "Введите информационную часть удаляемого элемента" << endl;
		cin >> data;
		if (list.first->data == data) {
			list.first = list.first->next;
			delete cur;
			list.count--;
		}
		else {
			if (cur != nullptr) cur = cur->next;
			while (cur != nullptr && cur->data != data) {
				cur = cur->next; prev = prev->next;
			}
			if (cur != nullptr) {
				prev->next = cur->next;
				del_data = cur->data;
				delete cur;
				list.count--;
			}
			else {
				cout << "Не найдено такого элемента, повторите ввод" << endl;
			}
		}
	}

	return del_data;
}

void push_front(LinkedList& list, Node* cur) {
	list.first = cur;
	list.first->next = nullptr;
	list.count++;
}

void move_to_del_list(LinkedList& list, LinkedList& del_list) {
	type data;
	Node* cur = list.first, * prev = list.first, * del_cur = del_list.first;
	if (is_Empty(list)) {
		cout << "Список пуст, удалять нечего" << endl;
	}
	else {
		cout << "Введите информационную часть удаляемого элемента" << endl;
		cin >> data;
		if (list.first->data == data) {
			list.first = list.first->next;
			if (is_Empty(del_list)) {
				push_front(del_list, cur);
			}
			else {
				while (del_cur != nullptr && del_cur->next != nullptr) {
					del_cur = del_cur->next;
				}
				del_cur->next = cur;
				del_cur->next->next = nullptr;
				del_list.count++;
			}
			list.count--;
		}
		else {
			if (cur != nullptr) cur = cur->next;
			while (cur != nullptr && cur->data != data) {
				cur = cur->next; prev = prev->next;
			}
			if (cur != nullptr) {
				prev->next = cur->next;
				if (is_Empty(del_list)) {
					push_front(del_list, cur);
				}
				else {
					while (del_cur != nullptr && del_cur->next != nullptr) {
						del_cur = del_cur->next;
					}
					del_cur->next = cur;
					del_cur->next->next = nullptr;
					del_list.count++;
				}
				list.count--;
			}
			else {
				cout << "Не найдено такого элемента, повторите ввод" << endl;
			}
		}
	}

}

void destroy(LinkedList& list) {
	Node* cur = list.first;
	while (cur != nullptr) {
		list.first = list.first->next;
		delete cur;
		cur = list.first;
		list.count--;
	}
}

void output_list(LinkedList& list) {
	if (is_Empty(list)) {
		cout << "Список пуст" << endl;
	}
	else {
		Node* cur = list.first;
		while (cur != nullptr) {
			cout << cur->data << "  ";
			cur = cur->next;
		}
		cout << endl;
	}
}