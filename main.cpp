#include"Singly_LInk_List.h"

int main()
{
	int n, m;

	std::cin >> n;

	int a[100001];

	for (int i = 0; i < n; i++)
		std::cin >> a[i];

	Link_List<int> my_list(a, n);

	LinkNode<int>* p = my_list.list->next;

	/*for (int i = 0; i < my_list.getLength(); i++)
	{
		std::cout << p->data << " ";
		p = p->next;
	}

	system("Pause");*/



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


		p = my_list.list->next;
		for (int k = 0; k < my_list.getLength(); k++)
		{
			std::cout << p->data << " ";
			p = p->next;
		}

		std::cout << std::endl << my_list.getLength();

		system("Pause");
	}

	p = my_list.list->next;
	for (int i = 0; i < my_list.getLength(); i++)
	{
		std::cout << p->data << " ";
		p = p->next;
	}

	system("Pause");


}