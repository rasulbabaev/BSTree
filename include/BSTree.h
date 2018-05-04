using namespace std;
namespace BSTree
{
	bool a = false;
	struct Node 
	{
		int data;
		Node *Right;
		Node *Left;
	};

	class Tree 
	{
		Node * root = nullptr;
		void add_node(int data, Node *&NTree) 
		{
			if (NTree == nullptr) 
			{
				NTree = new Node{ data, nullptr, nullptr };
			}

			if (data < NTree->data) 
			{
				if (NTree->Left != nullptr) 
				{
					add_node(data, NTree->Left);
				}
				else
				{
					NTree->Left = new Node{ data, nullptr, nullptr };
				}
			}


			if (data > NTree->data) 
			{ 
				if (NTree->Right != nullptr)
				{
					add_node(data, NTree->Right);
				}
				else
				{
					NTree->Right = new Node{ data, nullptr, nullptr };
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
			cout << endl;

			for (int i = count; i < space; i++)
			{
				std::cout << "	";
			}
			cout << "--" << root->data << endl;
			print_tree(root->Left, space);
		}
		void straight(Node * root)
		{
			if (root == nullptr)
			{
				cout << "Дерево пусто" << endl;
				return;
			}
			cout << root->data << " ";
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
				cout << "Дерево пусто" << endl;
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
				cout << "Дерево пусто" << endl;
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

			cout << root->data << " ";
		}
		void insert(Node *&NTree, int data)
		{
			if (data < NTree->data)
			{
				if (NTree->Left != nullptr)
				{
					insert(NTree->Left, data);
				}
				else
				{
					NTree->Left = new Node{ data, nullptr, nullptr };
				}
			}

			if (data > NTree->data)
			{
				if (NTree->Right != nullptr)
				{
					insert(NTree->Right, data);
				}
				else
				{
					NTree->Right = new Node{ data, nullptr, nullptr };
				}
			}
			else
			{
				cout << "Узел уже существует в дереве" << endl;
				return;
			}
		}
		void write_to_file(Node * root, int space, ofstream &fout)
		{
			if (root == nullptr)
			{
				return;
			}
			int count = 1;
			space = space + count;
			write_to_file(root->Right, space, fout);
			fout << "\n";

			for (int i = count; i < space; i++)
			{
				fout << "	";
			}
			fout << "--" << root->data;
			fout << "\n";
			write_to_file(root->Left, space, fout);
		}
		void read_from_file(Node *root, ifstream &fin, string filename)
		{
			string spaces;
			getline(fin, spaces);
			int count = 0;
			for (int i = 0; i < spaces.length(); i++)
			{
				if (spaces[i] == ' ')
				{
					count++;
				}
			}

			fin.close();

			fin.open(filename);

			for (int i = 0; i <= count; i++)
			{
				fin >> spaces;
				add_element(atoi(spaces.data()));
			}
			fin.close();
		}
		void check_node(Node *root, int data)
		{
			if (root->data == data)
			{
				cout << "Узел найден";
				a = true;
				return;
			}

			if (root->Left != nullptr)
			{
				check_node(root->Left, data);
			}	
			if (root->Right != nullptr)
			{
				check_node(root->Right, data);
			}		
		}
		void del_node(Node *&NTree, int data) //В разработке!
		{
			if (NTree->data == data)
			{
				Node *key = nullptr;
				if (NTree->Right == nullptr)
				{
					key = NTree->Left;
				}
				else
				{

				}
			}
		} 
	public:
		void get_straight()
		{
			straight(root);
		}
		void get_symmetric()
		{
			symmetric(root);
		}
		void get_inverce()
		{
			inverse(root);
		}
		void add_element(int data) 
		{
			add_node(data, root);
		}
		void get_print_tree()
		{
			if (root == nullptr)
			{
				cout << "Дерево пусто!" << endl;
			}
			print_tree(root, 0);
		}
		void get_insert(int data)
		{
			if (root == nullptr)
			{
				cout << "Дерево пусто!" << endl;
			}
			insert(root, data);
		}
		void get_write_to_file()
		{
			if (root == nullptr)
			{
				cout << "Дерево пусто" << endl;
			}
			string filename;
			cout << "Введите путь к файлу" << endl;
			cin >> filename;
			ofstream fout;
			char choose;
			cout << "Перезаписываем? (y/N)" << endl;
			cin >> choose;
			if (choose == 'y')
			{
				fout.open(filename, ios::out | ios::trunc);
				if (!fout.is_open())
				{
					cout << "Не удается открыть файл" << endl;
				}
			}

			if (choose == 'N')
			{
				fout.open(filename, ios::out | ios::app);
				if (!fout.is_open())
				{
					cout << "Не удается открыть файл" << endl;
				}
			}

			else
			{
				cout << "Неверный ввод" << endl;
				return;
			}
			write_to_file(root, 0, fout);
			fout.close();
			
		}
		void get_check_node(int data)
		{
			if (root == nullptr)
			{
				cout << "Дерево пусто" << endl;
				return;
			}
			check_node(root, data);
			if (!a)
			{
				cout << "Узел не найден" << endl;
			}
		}
		void get_del_node(int data) //В разработке!
		{
			del_node(root, data);
		}
		void get_read_from_file()
		{
			if (root == nullptr)
			{
				cout << "Дерево пусто" << endl;
			}

			string filename;
			cout << "Введите путь к файлу" << endl;
			cin >> filename;
			ifstream fin;
			fin.open(filename);
			if (!fin.is_open())
			{
				cout << "Не удаётся открыть файл" << endl;
				return;
			}
			read_from_file(root, fin, filename);
		}
	};

}
