#include"Binary_Search_Tree.hpp"


//int main()
//{
//	BSTree<string, int> bt;
//	string arr[] = { "apple","car","air","apple","pear","sun","apple" ,"pear"};
//	for (auto e : arr)
//	{
//		BSTNode<string,int>* p = bt.Find(e);
//		if (p)
//		{
//			p->_value++;
//		}
//		else
//		{
//			bt.Insert(e, 1);
//		}
//	}
//	bt.InOrder();
//	return 0;
//}



int main()
{
	BSTree<int> bt;
	int arr[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	for (auto e : arr)
	{
		bt.Insert(e);
	}
	bt.InOrder();
	for (auto e : arr)
	{
		bt.Erase(e);
		bt.InOrder();
	}
	return 0;
}