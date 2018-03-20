namespace BSTree
{
	struct Node //Ñòðóêòóðà óçëà0
	{
		int data;
		Node *pRight;
		Node *pLeft;
	};

	class Tree //Êëàññ äåðåâà
	{
	private:
		Node * proot = nullptr;
	public:
		void addnode(int data, Node *pNTree) //Ôóíêöèÿ äîáàâëåíèÿ óçëà â äåðåâî
		{
			if (pNTree == nullptr) //Åñëè óçëîâ äåðåâà íåò
			{
				pNTree = new Node; //Ñîçäà¸ì íîâûé óçåë
				pNTree->data = data; //Çàïèñûâàåì òóäà çíà÷åíèÿ
				pNTree->pLeft = nullptr; //Äåëàåì ïóñòûå óêàçàòåëè îò ýòîãî óçëà íàëåâî è íàïðàâî
				pNTree->pRight = nullptr;
			} 
			
			if (data < pNTree->data) //Åñëè äîáàâëåííûé ýëåìåíò ìåíüøå òåêóùåãî óçëà
			{
				if (pNTree->pLeft != nullptr) // Åñëè óçåë ÍÅ ñîäåðæèò ïóñòîãî óêàçàòåëÿ íàëåâî
				{
					addnode(data, pNTree->pLeft); //Äîáàâëÿåì äàííûå è óêàçàòåëü íà ëåâûé óçåë
				}
				else
				{
					pNTree->pLeft = new Node; //Èíà÷å äåëàåì íîâûé óçåë
					pNTree->pLeft->pLeft = nullptr; //Ëåâóþ âåòâü ëåâîãî ýëåìåíòà
					pNTree->pLeft->pRight = nullptr; //Ïðàâóþ âåòâü ëåâîãî ýëåìåíòà
					pNTree->pLeft->data = data; //Çàïèñûâàåì äàííûå â ëåâûé óçåë
				}
			}

			
			if (data > pNTree->data) //Åñëè áîëüøå òåêóùåãî óçëà
			{ //Âñ¸ òî æå ñàìîå, íà ëåâóþ âåòâü
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

		void addel(int data) //Ôóíêöèÿ äîáàâëåíèÿ ýëåìåíòà â óçåë
		{
			addnode(data, proot);
		}
	};
}
