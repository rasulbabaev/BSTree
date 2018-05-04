#include <iostream>
#include <string>
#include <fstream>
#include "BSTree.h"

using namespace std;
using namespace BSTree;

void MenuOut()
{
	cout << "\n\nВыберите одну из операций:" << endl;
	cout << "1. Вывести дерево на экран" << endl;
	cout << "2. Вывести список узлов дерева:" << endl;
	cout << "   a. Прямой обход" << endl;
	cout << "   b. Поперечный обход" << endl;
	cout << "   c. Обратный обход" << endl;
	cout << "3. Добавить узел в дерево" << endl;
	cout << "4. Удалить узел из дерева" << endl;
	cout << "5. Сохранить дерево в файл" << endl;
	cout << "6. Загрузить дерево из файла" << endl;
	cout << "7. Проверить наличие узла" << endl;
	cout << "8. Завершение работы" << endl << endl;

}
void Menu_for_case2()
{
	cout << "a - Прямой обход" << endl;
	cout << "b - Поперечный обход" << endl;
	cout << "c - Обратный обход" << endl;
}

int main(int argc, char * argv[])
{
	setlocale(LC_ALL, "Russian");
	Tree *tree = new Tree;
	cout << "Введите кол-во элементов" << endl;
	int *n = new int;
	cin >> *n;
	int *mas = new int[*n];
	for (int i = 0; i < *n; i++)
	{
		cout << "Введите " << i + 1 << " элемент" << endl;
		cin >> *(mas + i);
	}
	for (int i = 0; i < *n; i++)
	{
		tree->add_element(*(mas + i));
	}
	delete[] mas;
	delete n;
	while (true)
	{
		MenuOut();
		unsigned int ch;
		cin >> ch;
		switch (ch)
		{
		case 1:
		{
			tree->get_print_tree();
			break;
		}
		case 2:
		{
			char *ch = new char;
			Menu_for_case2();
			cin >> *ch;
			if (*ch == 'a')
			{
				tree->get_straight();
				break;
			}

			if (*ch == 'b')
			{
				tree->get_symmetric();
				break;
			}

			if (*ch == 'c')
			{
				tree->get_inverce();
				delete ch;
				break;
			}
			
			else
			{
				cout << "Неправильный ввод" << endl;
			}
			break;
		}
		case 3:
		{
			cout << "\nВведите значение для нового узла" << endl;
			int *ins = new int;
			cin >> *ins;
			tree->get_insert(*ins);
			delete ins;
			break;
		}
		case 4:
		{
			int *del = new int;
			int *ins = new int;
			cout << "Введите узел, который должен быть удалён" << endl;
			cin >> *del;
			cout << "Введите значение для нового узла" << endl;
			cin >> *ins;
			break;
		}
		case 5:
		{
			tree->get_write_to_file();
			break;
		}
		case 6:
		{
			tree->get_read_from_file();
			break;
		}
		case 7:
		{
			int data;
			cout << "Введите узел для проверки" << endl;
			cin >> data;
			tree->get_check_node(data);
			a = false;
			break;
		}
		case 8:
		{
			string *exit = new string;
			cout << "Вы хотите выйти?" << endl;
			cin >> *exit;
			if ((*exit == "y") || (*exit == "Y") || (*exit == "yes") || (*exit == "Yes") || (*exit == "YES"))
			{
				return 0;
			}

			if ((*exit == "n") || (*exit == "N") || (*exit == "no") || (*exit == "No") || (*exit == "NO"))
			{
				cout << endl;
				break;
			}

			else
			{
				cout << "Неверный ввод" << endl << endl;
			}
			delete exit;
			break;
		}
		default:
		{
			cout << "Неверный ввод" << endl << endl;
			return 0;
		}
		delete tree;
		}
	}
	
}
