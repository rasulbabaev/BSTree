namespace BSTree
{
	struct Node //Структура узла
	{
		int data;
		Node *Right;
		Node *Left;
	};

	class Tree //Класс дерева
	{
		Node * root = nullptr;
		void print_tree(Node *root, int space)
		{
			if (root == nullptr)
			{
				return;
			}

			int count = 1;
			space = space + count;
			print_tree(root->Right, space);
			std::cout << std::endl;

			for (int i = count; i < space; i++)
			{
				std::cout << "	";
			}
			std::cout << "--" << root->data << std::endl;

			print_tree(root->Left, space);
		}
		void add_node(int data, Node *&NTree) //Функция добавления узла в дерево
		{
			if (NTree == nullptr) //Если узлов дерева нет
			{
				NTree = new Node; //Создаём новый узел
				NTree->data = data; //Записываем туда значения
				NTree->Left = nullptr; //Делаем пустые указатели от этого узла налево и направо
				NTree->Right = nullptr;
			}

			if (data < NTree->data) //Если добавленный эл-т меньше
			{
				if (NTree->Left != nullptr) // Если узел НЕ содержит пустого указателя налево
				{
					add_node(data, NTree->Left); //Добавляем данные и указатель на левый узел
				}
				else
				{
					NTree->Left = new Node; //Иначе делаем новый узел
					NTree->Left->Left = nullptr; //Левую ветвь левого элемента
					NTree->Left->Right = nullptr; //Правую ветвь левого элемента
					NTree->Left->data = data; //Записываем данные в левый узел
				}
			}


			if (data > NTree->data) //Если больше текущего узла
			{ //Всё то же самое, на левую ветвь
				if (NTree->Right != nullptr)
				{
					add_node(data, NTree->Right);
				}
				else
				{
					NTree->Right = new Node;
					NTree->Right->Right = nullptr;
					NTree->Right->Left = nullptr;
					NTree->Right->data = data;
				}
			}
		}
	public:


		void add_element(int data) //Функция добавления элемента в узел
		{
			add_node(data, root);
		}

		void print_tree()
		{
			print_tree(root, 0);
		}
	};
}

