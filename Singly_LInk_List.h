#pragma once
#include<iostream>



//只保留基础操作
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


//只保留基础操作，不考虑拷贝构造和赋值
template<class T>
class Link_List
{
public:
	LinkNode<T>* list;
	int length;

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

	//判空
	bool IsEmpty()const
	{
		return list->next == nullptr;
	}

	//求长度
	int getLength()const
	{
		return length;
	}

	//头插法
	void Head_Insert(T e)
	{

		LinkNode<T>* new_node = new LinkNode<T>(e);//此时new_node->next已经为nullptr

		length++;

		new_node->next = list->next;

		list->next = new_node;

	}

	//尾插法
	void Tail_Insert(T e)
	{
		LinkNode<T>* new_node = new LinkNode<T>(e);

		//链表为空时,类似于头插法
		if (IsEmpty())
		{
			new_node->next = list->next;

			list->next = new_node;
		}
		else
		{
			LinkNode<T>* p = list->next;

			//遍历到尾部
			while (p->next != nullptr)
			{
				p = p->next;
			}

			p->next = new_node;
		}

		length++;
	}

	//返回值判断是否成功插入 
	bool Insert(T e,int pos)
	{
		if (pos<0 || pos>length)
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

		length++;

		return true;
		

	}

	


	bool Delete_Node(int pos = 1)//默认节点从一开始
	{
		if (pos<1 || pos>length)
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

		length--;

		return true;

	}

private:
	//初始化链表构造哨兵节点
	void InitList()
	{
		this->list = new LinkNode<T>();

		list->next = nullptr;
		
		length = 0;
	}

	//以数组初始化链表
	void InitList_from_array(T a[], int n)
	{
		InitList();

		LinkNode<T>* tail = list;

		for (int i = 0; i < n; i++)
		{
			LinkNode<T>* p = new LinkNode<T>(a[i]);

			length++;

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

		length = 0;

	}


};