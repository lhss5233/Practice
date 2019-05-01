#pragma once



template <typename T>
class TMyLinkList
{
public:

	struct FNode
	{
		FNode(T a_val) : Val{ a_val } {};

		FNode * pPrev =nullptr;
		FNode * pNext = nullptr;

		T Val;
	};



public:
	TMyLinkList() =default;
	~TMyLinkList()
	{
		Clear();
	}

	void Add(const T& val)
	{
		FNode * pTemp = new FNode(val);
		if (PTail == nullptr)
		{
			PHead = pTemp;
			PTail = pTemp;
		}
		else
		{
			pTemp->pPrev = PTail;
			PTail->pNext = pTemp;
			PTail = pTemp;
		}
		++ListSize;
	}

	void AddFront(const T& val)
	{
		FNode * pTemp = new FNode(val);
		if (PHead == nullptr)
		{
			PHead = pTemp;
			PTail = pTemp;
		}
		else
		{
			pTemp->pNext = PHead;
			PHead->pPrev = pTemp;
			PHead = pTemp;
		}
		++ListSize;
	}



	bool bRemove(const T& val)
	{
		FNode* p = PHead;
		FNode* prev = nullptr;

		while (p != nullptr)
		{
			if (p->Val == val)
			{
				if (prev != nullptr) { prev->pNext = p->pNext; p->pNext->pPrev = prev; }
				if (PHead == p) { PHead = p->pNext; }
				if (PTail == p) { PTail = prev; }

				delete p;
				--ListSize;
				return true;
			}

			prev = p;
			p = p->pNext;
		}

		return false;
	}
	bool bRemoveLast()
	{
		if (PHead == nullptr)
		{
			return false;
		}
		if (PHead == PTail)
		{
			delete PHead;
			PHead = nullptr;
			PTail = nullptr;
		}
		else 
		{
			FNode * prev = PTail->pPrev;
			prev->pNext = nullptr;
			delete  PTail;
			PTail = prev;
			
		}
		--ListSize;

		return true;
	}
	bool bRemoveAll()
	{
		if (PHead == nullptr)
			return false;
		Clear();

		return true;
	}


	bool bFind(const T& val)
	{
		FNode* p = PHead;
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

	bool bEmpty()
	{
		return PHead == nullptr;
	}

	void Clear()
	{
		FNode* p = PHead;
		while (p != nullptr)
		{
			FNode* tmp = p;
			p = p->pNext;
			delete tmp;
		}
		PHead = nullptr;
		PTail = nullptr;
	}

	int32 GetSize() const
	{
		return ListSize;
	}

	void Info() const
	{
		if (PHead == nullptr)
		{
			std::cout << "인덱스가 존재하지 않음" << std::endl;
		}
		else
		{
			FNode* p = PHead;

			while (p != nullptr)
			{
				std::cout << p->Val << std::endl;

				p = p->pNext;
			}
		}
	}

	T GetHeadVal ()
	{
		if (PHead != nullptr)
		{
			return PHead->Val;
		}
	}
	
	T GetTailVal()
	{
		if (PTail != nullptr)
		{
			return PTail->Val;
		}
	}


protected:

	FNode * PHead = nullptr;
	FNode * PTail = nullptr;

	int32 ListIndex = 0;
	int32 ListSize = 0;
};


