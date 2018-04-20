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
		void add_node(int data, Node *&NTree) //Функция добавления узла в дерево (NTree == key) 
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
		void straight(Node * root)
		{
			if (root == nullptr)
			{
				std::cout << "Дерево пусто" << std::endl;
				return;
			}

			if (root == nullptr)
			{
				std::cout << "Дерево пусто" << std::endl;
				return;
			}
			std::cout << root->data << " ";
			if (root->Left != nullptr)
			{
				straight(root->Left);
			}
			if (root->Right != nullptr)
			{
				straight(root->Right);
			}
		}
		void symmetric(Node *root)
		{
			if (root == nullptr)
			{
				std::cout << "Дерево пусто" << std::endl;
				return;
			}

			if (root->Left != nullptr)
			{
				symmetric(root->Left);
			}

			std::cout << root->data << " ";

			if (root->Right != nullptr)
			{
				symmetric(root->Right);
			}
		}
		void inverse(Node *root)
		{
			if (root == nullptr)
			{
				std::cout << "Дерево пусто" << std::endl;
				return;
			}

			if (root->Left != nullptr)
			{
				inverse(root->Left);
			}

			if (root->Right != nullptr)
			{
				inverse(root->Right);
			}

			std::cout << root->data << " ";
		}
	public:
		void get_straight ()
		{
			straight(root);
		}
		void get_symmetric ()
		{
			symmetric(root);
		}
		void get_inverce ()
		{
			inverse(root);
		}
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
