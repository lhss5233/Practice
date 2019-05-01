#pragma once

template <typename T>
class MyLinkList
{
public:

	struct Node
	{
		Node(T a_val) : Val{ a_val } {};

		Node * pPrev =nullptr;
		Node * pNext = nullptr;

		T Val;
	};



public:
	MyLinkList() =default;
	~MyLinkList()
	{
		Clear();
	}

	void Add(const T& val)
	{
		Node * pTemp = new Node(val);
		if (m_pTail == nullptr)
		{
			m_pHead = pTemp;
			m_pTail = pTemp;
		}
		else
		{
			pTemp->pPrev = m_pTail;
			m_pTail->pNext = pTemp;
			m_pTail = pTemp;
		}
		++m_nSize;
	}

	void AddFront(const T& val)
	{
		Node * pTemp = new Node(val);
		if (m_pHead == nullptr)
		{
			m_pHead = pTemp;
			m_pTail = pTemp;
		}
		else
		{
			pTemp->pNext = m_pHead;
			m_pHead->pPrev = pTemp;
			m_pHead = pTemp;
		}
		++m_nSize;
	}



	bool Remove(const T& val)
	{
		Node* p = m_pHead;
		Node* prev = nullptr;

		while (p != nullptr)
		{
			if (p->Val == val)
			{
				if (prev != nullptr) { prev->pNext = p->pNext; p->pNext->pPrev = prev; }
				if (m_pHead == p) { m_pHead = p->pNext; }
				if (m_pTail == p) { m_pTail = prev; }

				delete p;
				--m_nSize;
				return true;
			}

			prev = p;
			p = p->pNext;
		}

		return false;
	}
	bool RemoveLast()
	{
		if (m_pHead == nullptr)
		{
			return false;
		}
		if (m_pHead == m_pTail)
		{
			delete m_pHead;
			m_pHead = nullptr;
			m_pTail = nullptr;
		}
		else 
		{
			Node * prev = m_pTail->pPrev;
			prev->pNext = nullptr;
			delete  m_pTail;
			m_pTail = prev;
			
		}
		--m_nSize;
		return true;
	}
	bool RemoveAll()
	{
		if (m_pHead == nullptr)
			return false;
		Clear();

		return true;
	}


	bool Find(const T& val)
	{
		Node* p = m_pHead;
		while (p != nullptr)
		{
			if (p->Val = val)
			{
				return true;
			}
			p = p->pNext;
		}
		return false;
	}

	bool Empty()
	{
		return m_pHead == nullptr;
	}

	void Clear()
	{
		Node* p = m_pHead;
		while (p != nullptr)
		{
			Node* tmp = p;
			p = p->pNext;
			delete tmp;
		}
		m_pHead = nullptr;
		m_pTail = nullptr;
	}

	int GetSize()
	{
		return m_nSize;
	}

	void Info()
	{
		if (m_pHead == nullptr)
		{
			std::cout << "인덱스가 존재하지 않음" << std::endl;
		}
		else
		{
			Node* p = m_pHead;

			while (p != nullptr)
			{
				std::cout << p->Val << std::endl;

				p = p->pNext;
			}
		}
	}

private:
	Node * m_pHead = nullptr;
	Node * m_pTail = nullptr;

	int m_nIndex = 0;
	int m_nSize = 0;
};


