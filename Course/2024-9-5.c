#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>


#include<stdlib.h>

//int main()
//{
//
//
//	int n = 0;
//	scanf("%d", &n);
//	int* arr = (int*)malloc(sizeof(int) * n);
//	for (int i = 0; i < n; ++i)
//		scanf("%d", &arr[i]);
//	int left = 0;
//	int right = n - 1;
//	while (left <= right)
//	{
//		while (left <= right && arr[left] % 2 != 0)
//			++left;
//		while (left <= right && arr[right] % 2 == 0)
//			--right;
//		arr[right] = arr[left] ^ arr[right];
//		arr[left] = arr[left] ^ arr[right];
//		arr[right] = arr[left] ^ arr[right];
//
//	}
//	for (int i = 0; i < n; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//char* reverse(char* str)
//{
//	int left = 0;
//	int right = strlen(str)-1;
//	while (left < right)
//	{
//		char c = str[left];
//		str[left++] = str[right];
//		str[right--] = c;
//		
//	}
//	return str;
//}
//
//char* link(char* str1, char* str2)
//{
//	int i = 0;
//	while (str1[i] != '\0')
//		++i;
//	int j = 0;
//	while ((str1[i++] = str2[j++])!='\0')
//		;
//	return str1;
//}
//
//
//int main()
//{
//	char string1[256];
//	char string2[256];
//	gets(string1);
//	gets(string2);
//	printf("s1_reverse:%s\n", reverse(string1));
//	printf("s2_reverse:%s\n", reverse(string2));
//	printf("s1_reverse+s2_reverse:%s\n", link(string1, string2));
//	
//	
//	return 0;
//}


int main()
{
	int a = 0;
	int* p = &a;
	float b = 0;
	float* q = &b;
	
	int c = 3;
	scanf("%d %f", p, q);
	printf("a:%d b:%f\n", *p, *q);
	printf("p:%p a:%p q:%p b:%p\n", p, &a, q, &b);
	p = &c;
	printf("c:%d\n", *p);
	printf("p:%p c:%p", p, &c);
	return 0;
}