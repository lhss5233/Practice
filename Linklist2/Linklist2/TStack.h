#pragma once


template <typename T>
class TStack : public  TMyLinkList<T>
{
public:
	TStack() = default;
	~TStack(){};



	void Pop()
	{
		this->bRemoveLast();
	}

	void Push(const T& Val)
	{
		this->Add(Val);
	}
	
	T Top()
	{
		 return this->GetTailVal();
	}

};