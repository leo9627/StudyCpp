#include"AVLTree.h"

int main()
{

	int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int, int> t;
	for (auto& e : arr)
	{
		t.Insert(make_pair(e, e));
	}
	/*for (int i = 0; i < 100; i++)
	{
		int a = rand();
		t.Insert(make_pair(a, a));
	}*/
	t.InOrder();
	cout << t.IsBalance();
	return 0;
}