#pragma once
#include<iostream>



//ֻ������������
template<class T>
struct LinkNode
{
	T data;
	struct LinkNode* next;

	LinkNode() = default;

	LinkNode(T e) :data(e), next(nullptr)
	{

	}

};


//ֻ�������������������ǿ�������͸�ֵ
template<class T>
class Link_List
{
public:
	LinkNode<T>* list;

	Link_List()
	{
		InitList();
	}

	Link_List(T a[], int n)
	{
		InitList_from_array(a, n);
	}

	~Link_List()
	{
		clear_list();

		delete list;
	}

	//�п�
	bool IsEmpty()const
	{
		if (list->next == nullptr)
		{
			return true;
		}
		else return false;
	}

	//�󳤶�
	int getLength()const
	{
		int length = 0;

		LinkNode<T>* p = list->next;

		//������β��
		while (p != nullptr)
		{
			length++;
			p = p->next;
		}
		
		return length;
	}

	//ͷ�巨
	void Head_Insert(T e)
	{

		LinkNode<T>* new_node = new LinkNode<T>(e);//��ʱnew_node->next�Ѿ�Ϊnullptr

		new_node->next = list->next;

		list->next = new_node;

	}

	//β�巨
	void Tail_Insert(T e)
	{
		LinkNode<T>* new_node = new LinkNode<T>(e);

		//����Ϊ��ʱ,������ͷ�巨
		if (IsEmpty())
		{
			new_node->next = list->next;

			list->next = new_node;
		}
		else
		{
			LinkNode<T>* p = list->next;

			//������β��
			while (p->next != nullptr)
			{
				p = p->next;
			}

			p->next = new_node;
		}

	}

	//����ֵ�ж��Ƿ�ɹ����� 
	bool Insert(T e,int pos)
	{
		if (pos<0 || pos>getLength())
		{
			return false;
		}

		LinkNode<T>* p = list;

		for (int i = 0; i < pos; i++)
		{
			p = p->next;
		}

		LinkNode<T>* new_node = new LinkNode<T>(e);

		new_node->next = p->next;

		p->next = new_node;

		return true;
		

	}

	


	bool Delete_Node(int pos = 1)//Ĭ�Ͻڵ��һ��ʼ
	{
		if (pos<1 || pos>getLength())
		{
			return false;
		}

		LinkNode<T>* p = list, *pre=nullptr;

		for (int i = 0; i < pos; i++)
		{
			pre = p;
			p = p->next;
		}

		pre->next = p->next;

		p->next = nullptr;

		delete p;

		return true;

	}

private:
	//��ʼ���������ڱ��ڵ�
	void InitList()
	{
		this->list = new LinkNode<T>();

		list->next = nullptr;
	}

	//�������ʼ������
	void InitList_from_array(T a[], int n)
	{
		InitList();

		LinkNode<T>* tail = list;

		for (int i = 0; i < n; i++)
		{
			LinkNode<T>* p = new LinkNode<T>(a[i]);

			tail->next = p;
			
			tail = p;

		}

	}

	void clear_list()
	{
		LinkNode<T>* p = list->next;

		while (p)
		{
			LinkNode<T>* q = p;
			p = p->next;
			delete q;
		}

	}


};