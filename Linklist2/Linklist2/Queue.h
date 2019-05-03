#pragma once

template <typename T>
class TQueue : public TMyLinkList<T>
{
public:
	TQueue() = default;
	~TQueue() {};

	void Pop()
	{
		this->bRemoveFront();
	}

	void Push(const T& Val)
	{
		this->Add(Val);
	}

	T Front()
	{
		return this->GetHeadVal();
	}
};