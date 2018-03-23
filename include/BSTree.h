namespace BSTree
{
	struct Node //Структура узла
	{
		int data;
		Node *pRight;
		Node *pLeft;
	};

	class Tree //Класс дерева
	{
	private:
		Node * proot = nullptr;
	public:
		void addnode(int data, Node *&pNTree) //Функция добавления узла в дерево
		{
			if (pNTree == nullptr) //Если узлов дерева нет
			{
				pNTree = new Node; //Создаём новый узел
				pNTree->data = data; //Записываем туда значения
				pNTree->pLeft = nullptr; //Делаем пустые указатели от этого узла налево и направо
				pNTree->pRight = nullptr;
			} 
			
			if (data < pNTree->data) //Если добавленный элемент меньше текущего узла
			{
				if (pNTree->pLeft != nullptr) // Если узел НЕ содержит пустого указателя налево
				{
					addnode(data, pNTree->pLeft); //Добавляем данные и указатель на левый узел
				}
				else
				{
					pNTree->pLeft = new Node; //Иначе делаем новый узел
					pNTree->pLeft->pLeft = nullptr; //Левую ветвь левого элемента
					pNTree->pLeft->pRight = nullptr; //Правую ветвь левого элемента
					pNTree->pLeft->data = data; //Записываем данные в левый узел
				}
			}

			
			if (data > pNTree->data) //Если больше текущего узла
			{ //Всё то же самое, на левую ветвь
				if (pNTree->pRight != nullptr) 
				{
					addnode(data, pNTree->pRight);
				}
				else
				{
					pNTree->pRight = new Node;
					pNTree->pRight->pRight = nullptr;
					pNTree->pRight->pLeft = nullptr;
					pNTree->pRight->data = data;
				}
			}
		}

		void addel(int data) //Функция добавления элемента в узел
		{
			addnode(data, proot);
		}
	};
}

