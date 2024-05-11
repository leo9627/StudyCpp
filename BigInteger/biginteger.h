#pragma once
#include<string>
#include<vector>

using std::string;
using std::vector;

bool cmp(const string& a, const string& b);
void Erase(string& s);
string Add(const string& a, const string& b);
string Sub(const string& x, const string& y);
string Mul(const string& x, const string& y);
string Div(const string& x, const string& y);
string Mod(const string& a, const string& b);