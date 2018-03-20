namespace BSTree
{
	struct Node //��������� ����
	{
		int data;
		Node *pRight;
		Node *pLeft;
	};

	class Tree //����� ������
	{
	private:
		Node * proot = nullptr;
	public:
		void addnode(int data, Node *pNTree) //������� ���������� ���� � ������
		{
			if (pNTree == nullptr) //���� ����� ������ ���
			{
				pNTree = new Node; //������ ����� ����
				pNTree->data = data; //���������� ���� ��������
				pNTree->pLeft = nullptr; //������ ������ ��������� �� ����� ���� ������ � �������
				pNTree->pRight = nullptr;
			} 
			
			if (data < pNTree->data) //���� ����������� ������� ������ �������� ����
			{
				if (pNTree->pLeft != nullptr) // ���� ���� �� �������� ������� ��������� ������
				{
					addnode(data, pNTree->pLeft); //��������� ������ � ��������� �� ����� ����
				}
				else
				{
					pNTree->pLeft = new Node; //����� ������ ����� ����
					pNTree->pLeft->pLeft = nullptr; //����� ����� ������ ��������
					pNTree->pLeft->pRight = nullptr; //������ ����� ������ ��������
					pNTree->pLeft->data = data; //���������� ������ � ����� ����
				}
			}

			
			if (data > pNTree->data) //���� ������ �������� ����
			{ //�� �� �� �����, �� ����� �����
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

		void addel(int data) //������� ���������� �������� � ����
		{
			addnode(data, proot);
		}
	};
}
