#include <iostream>
#include <string>
#include "BSTree.h"

using namespace std;
using namespace BSTree;

void MenuOut()
{
	cout << "Выберите одну из операций:" << endl;
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

int main(int argc, char * argv[])
{
	setlocale(LC_ALL, "Russian");
	Tree *tree = new Tree;
	for (int i = 0; i < argc; i++)
	{
		int x;
		x = atoi(argv[i]);
		tree->addel(x);
	}
	label:
	MenuOut();

	unsigned int ch;
	cin >> ch;
	switch (ch)
	{
	case 1:
	{
		break;
	}
	case 2:
	{
		break;
	}
	case 3:
	{
		break;
	}
	case 4:
	{
		break;
	}
	case 5:
	{
		break;
	}
	case 6:
	{
		break;
	}
	case 7:
	{
		break;
	}
	case 8:
	{
		string exit;
	label_exit:
		cout << "Вы хотите выйти?" << endl;
		cin >> exit;
		if ((exit == "y") || (exit == "Y") || (exit == "yes") || (exit == "Yes"))
		{
			return 0;
		}

		if ((exit == "n") || (exit == "N") || (exit == "no") || (exit == "No"))
		{
			cout << endl;
			goto label;
		}

		else
		{
			cout << "Неверный ввод" << endl << endl;
			goto label_exit;
		}
		break;
	}
	default:
	{
		cout << "Неверный ввод" << endl << endl;
		goto label;
	}

	}
}