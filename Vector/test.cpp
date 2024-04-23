#include"Vector.hpp"


int main()
{
	vector<int> v1;
	v1.Push_Back(1);
	v1.Push_Back(2);
	v1.Push_Back(3);
	v1.Push_Back(4);
	for (int i = 0; i < v1.size(); i++)
	{
		std::cout << v1[i] << " ";
	}
	return 0;
}