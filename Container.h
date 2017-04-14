#pragma once
#include<stddef.h>
#include<string>
template <class T> class Container
{
	struct Element
	{
		Element* next;
		Element* previous;
		T content;
	} *head, *tail,*iter_pointer;
public:
	class MyExeption:public std::exception
	{
	public:
		std::string message;
		MyExeption(const std::string& msg) noexcept
		{
			message = msg;
		}
	};
	Container() {};
	Container(const Container & other) :
		head(NULL),
		tail(NULL)
	{
		for (auto e = other.head; NULL != e; e = e->next) {
			AddFirst(e->content);
		}
	}
	void AddFirst(const T& elem)
	{
		if (head == NULL)
		{
			Element *NewHead = new Element();
			NewHead->content = elem;
			NewHead->next = head;
			NewHead->previous = NULL;
			head = NewHead;
			tail = NewHead;
		}
		else
		{
			Element *NewHead = new Element();
			NewHead->content = elem;
			NewHead->next = head;
			NewHead->previous = NULL;
			head = NewHead;
		}
	}
	void AddLast(const T& elem)
	{
		if (head != NULL)
		{
			Element *NewTail = new Element();
			tail->next = NewTail;
			NewTail->content = elem;
			NewTail->next = NULL;
			NewTail->previous = tail;
			tail = NewTail;
		}
		else this->AddFirst(elem);
	}
	void DeleteFirst()
	{
		if (head == NULL) return;
		Element *DelPointer = head;
		head = head->next;
		if (head != NULL) head->previous = NULL;
		delete DelPointer;
	}
	void DeleteLast()
	{
		if (head == NULL) return;
		if (head->next == NULL)
		{
			delete head;
			head = NULL;
		}
		else
		{
			Element* DelPointer = tail;
			tail = tail->previous;
			tail->next = NULL;
			delete DelPointer;
		}
	}
	const T& GetFirst()
	{
		return head->content;
	}
	const T& GetLast()
	{
		return tail->content;
	}
	void SetToFirst()
	{
		try
		{
			this->ExeptionCheck();
		}
		catch (MyExeption& ex)
		{
			std::cout << ex.message << "\n";
			system("pause");
			exit(0);
		}
		iter_pointer = head;
	}
	const T* GetAndMove()
	{
		if (iter_pointer->next != NULL)
		{
			iter_pointer = iter_pointer->next;
			return &iter_pointer->content;
		}
		else return NULL;
	}
	void ExeptionCheck()
	{
		if (this->IsEmpty())
		{
			throw MyExeption("EmptinessExeption");
		}
	}
	void ExeptionCheck(Element* el)
	{
		if (el == NULL)
		{
			throw MyExeption("OutOfRangeExeption");
		}
	}
	bool IsEmpty()
	{
		if (this->head == NULL) return true;
		else return false;
	}
	int GetNumberOfElements()
	{
		if (!IsEmpty())
		{
			Element* Counter = head;
			int i = 1;
			while (Counter->next)
			{
				i++;
				Counter = Counter->next;
			}
			return i;
		}
		else return 0;
	}
	~Container()
	{
		while (!IsEmpty())
		{
			this->DeleteFirst();
		}
	}
};