#include"Singly_LInk_List.h"


//当链表需要频繁插入和删除时，可以增加一个变量记录长度，极大减少时间
int main()
{
	int n, m;

	std::cin >> n;

	int data;

	//输入再初始化过慢
	Link_List<int> my_list;

	LinkNode<int>* p = my_list.list;

	/*for (int i = 0; i < my_list.getLength(); i++)
	{
		std::cout << p->data << " ";
		p = p->next;
	}

	system("Pause");*/
	my_list.length = n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> data;

		LinkNode<int>* new_node = new LinkNode<int>(data);

		p->next = new_node;

		p = new_node;
	}


	std::cin >> m;

	int flag, k, d;

	for (int i = 0; i < m; i++)
	{
		std::cin >> flag;

		if (flag == 0)
		{
			std::cin >> k >> d;
			my_list.Insert(d, k);
		}
		else
		{
			std::cin >> k;
			my_list.Delete_Node(k);
		}


	/*	p = my_list.list->next;
		for (int k = 0; k < my_list.getLength(); k++)
		{
			std::cout << p->data << " ";
			p = p->next;
		}

		std::cout << std::endl << my_list.getLength();

		system("Pause");*/
	}

	p = my_list.list->next;
	for (int i = 0; i < my_list.getLength(); i++)
	{
		std::cout << p->data << " ";
		p = p->next;
	}

	/*system("Pause");*/


}