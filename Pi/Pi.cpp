#include<iostream>
#include<fstream>
#include<cmath>
#include<numbers>
#include<vector>
#include<chrono>
#include<algorithm>
using namespace std;

const int number = 11;

double level(double pi)
{
	return -log(abs(pi - 3.1415926535));
}
ofstream ou("result.txt");
struct Node
{
	double pi;
	double lev;
	size_t time;
	bool operator>(const Node& n)const
	{
		return time > n.time;
	}
};
void Write_Data(vector<Node>& v)
{
	ou.precision(11);
	ou.setf(std::ios::fixed, std::ios::floatfield);
	ou.fill('0');
	sort(v.begin(), v.end(), greater<Node>());
	for (auto& e : v)
	{
		ou << e.pi << "     " << e.lev << "     " << e.time << "     ";
	}
	ou << endl<<endl;
}
void Plan1()
{
	vector<Node> v;
	ou << "蒙特卡洛法  ";
	int trialsPerIteration = 1500;
	int totalIterations = 2500;
	ofstream out("result1.txt");
	int nums = number;
	int ci = 5;
	//int ci = 1000000;
	while (nums--)
	{
		auto begin = chrono::steady_clock::now();
		double a = 0;
		srand(time(0));
		for (int i = 0; i <ci; i++)
		{
			double x1 = static_cast<double>(rand()) / RAND_MAX * 2 - 1;
			double y1 = static_cast<double>(rand()) / RAND_MAX * 2 - 1;
			double d1 = pow(x1, 2) + pow(y1, 2);
			if (d1 <= 1.0)
				a++;
		}
		double pi = (a / (ci)) * 4;
		cout.precision(11);
		cout.setf(std::ios::fixed, std::ios::floatfield);
		cout.fill('0');
		auto end = chrono::steady_clock::now();
		size_t ti = chrono::duration_cast<chrono::nanoseconds>(end - begin).count();
		cout << pi << "  " << (int)(ci) <<"    "<<ti << "    " << level(pi) << endl;
		Node n1 = { pi,level(pi) ,ti };
		v.push_back(n1);
		trialsPerIteration += 1000;
		totalIterations += 1;
		ci += 5;
	}
	Write_Data(v);
}

//double S(size_t n)
//{
//
//	double s= sqrt(3) * 1.5;
//	double pi = 3.14159265358979323846;
//	for (size_t i = 2; i <= n; i++)
//	{
//		s = s / cos(pi / (3 * pow(2, i - 1)));
//	}
//	return s;
//}
//#define long double double
long double r = 4;
double C(size_t n)
{
	long double y = r;
	size_t nums = 6;
	long double sum = 0;
	while (n--)
	{
		sum = nums * y;
		nums *= 2;
		long double bd =  y/2;
		long double ab2 = pow(r,2) - pow(bd, 2);
		long double ab = sqrt(ab2);
		long double bc = r - ab;
		long double y2 = pow(bd, 2) + pow(bc, 2);
		y = sqrt(y2);
	}
	return sum;
}
void Plan2()
{
	vector<Node> v;
	ou << "割圆法  ";
	ofstream out("result2.txt");
	size_t nums = 5;
	for (int i = 0; i < number; i++)
	{
		auto begin = chrono::high_resolution_clock::now();
		double pi = C(nums)/(2*r);
		cout.precision(10);
		cout.setf(std::ios::fixed, std::ios::floatfield);
		cout.fill('0');
		out.precision(10);
		out.setf(std::ios::fixed, std::ios::floatfield);
		out.fill('0');
		auto end = chrono::high_resolution_clock::now();
		size_t ti = chrono::duration_cast<chrono::nanoseconds>(end - begin).count();
		cout << pi << "   " << nums << "    " << ti<< "    " << level(pi)  <<endl;
		Node n1 = { pi,level(pi) ,ti };
		v.push_back(n1);
		nums += 5;
	}
	Write_Data(v);
}
void Plan3()
{
	vector<Node> v;
	ou << "无穷级数法  ";
	ofstream out("result3.txt");
	size_t n = 1;
	double sum = 0;
	double nums = 5;
	//double nums = 1000000;
	double f = 1;
	for (int i = 0; i < number; i++)
	{
		int t = nums;
		//int begin = clock();
		auto begin = chrono::high_resolution_clock::now();
		while (nums--)
		{
			sum += (1.0 / n) * f;
			f *= -1;
			n += 2;
		}
		double pi=sum * 4;
		cout.precision(11);
		cout.precision(11);
		cout.setf(std::ios::fixed, std::ios::floatfield);
		cout.fill('0');
		out.precision(11);
		out.setf(std::ios::fixed, std::ios::floatfield);
		out.fill('0');
		//int end = clock();
		auto end = chrono::high_resolution_clock::now();
		size_t ti=chrono::duration_cast<chrono::nanoseconds>(end - begin).count();
		cout << pi << "   " << t <<"    "<<ti  << "    " << level(pi) << endl;
		//Node n1 = { pi,level(pi) ,end - begin };
		//v.push_back(n1);
		nums = t+ 5;
	}
	Write_Data(v);
}
double arc_tan(double x,size_t n)
{
	double f = 1;
	int nums = 1;
	double sum = 0;
	while (n--)
	{
		sum += pow(x, nums)*f/nums;
		f *= -1;
		nums += 2;
	}
	return sum;
}
void Plan4()
{
	vector<Node> v;
	ou << "梅钦法  ";
	ofstream out("result4.txt");
	size_t nums = 5;
	for (int i = 0; i < number; i++)
	{
		auto begin = chrono::high_resolution_clock::now();
		double pi = 16 * arc_tan(0.2, nums) - 4 * arc_tan(1.0 / 239, nums);
		cout.precision(10);
		cout.setf(std::ios::fixed, std::ios::floatfield);
		cout.fill('0');
		out.precision(10);
		out.setf(std::ios::fixed, std::ios::floatfield);
		out.fill('0');
		auto end = chrono::high_resolution_clock::now();
		size_t ti = chrono::duration_cast<chrono::nanoseconds>(end - begin).count();
		cout << pi << "   " << nums << "    " << ti  << "    " << level(pi) << endl;
		Node n1 = { pi,level(pi) ,ti };
		v.push_back(n1);
		nums += 5;
	}
	Write_Data(v);
}

int main()
{
	Plan1();
	cout << endl;
	Plan2();
	cout << endl;

	Plan3();
	cout << endl;

	Plan4();
	return 0;

}