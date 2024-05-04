#include"String.h"
leo::string::string(const char* str )
{
	assert(str);
	_capacity =_size = strlen(str);
	_str = new char[_capacity + 1];
	strcpy(_str, str);
	

}
leo::string::string(const string& s):_str(nullptr)
{
	_size = _capacity = s.size();
	string stemp = s._str;
	std::swap(stemp._str, _str);
}
void leo::string::reverse(size_t n)
{
	if (n < _size)
		return;
	_capacity = n;
	char* newstr = new char[n + 1];
	strcpy(newstr, _str);
	delete[] _str;
	_str = newstr;
}
void leo::string::rsize(size_t n, char c)
{
	if (n < _size)
	{
		_size = n;
		_str[n] = '\0';
	}
	else
	{
		if(_capacity<n)
			reverse(n);
		while (_size != n)
			_str[_size++] = c;
		_str[_size] = '\0';
	}
}
leo::string& leo::string::operator=(string s)
{

	string temp = s;
	_size = _capacity = s._size;
	std::swap(temp._str, _str);
	return *this;
	/*_capacity = s._capacity;
	_size = s._size;
	delete[] _str;
	_str = new char[_capacity + 1];
	strcpy(_str, s._str);
	return *this;*/
}
void leo::string::push_back(const char c)
{
	if (_size == _capacity)
		reverse(_capacity == 0 ? 2 : 2 * _capacity);
		
	_str[_size++] = c;
	_str[_size] = '\0';
}
void leo::string::append(const char* str)
{
	if (_capacity < _size + strlen(str))
		reverse(_size + strlen(str));
	strcpy(_str + _size, str);
	_size += strlen(str);
}
void leo::string::insert(size_t pos, char c)
{
	assert(pos <= _size);
	if (_size == _capacity)
		reverse(_capacity==0?2:_capacity * 2);
	for (size_t i = _size+1; i > pos; i--)
	{
		_str[i] = _str[i - 1];
	}
	_str[pos] = c;
	++_size;
	//_str[++_size] = '\0';
}
leo::string& leo::string::insert(size_t pos, const char* str)
{
	assert(pos <= _size);
	size_t len = strlen(str);
	if (_size + len > _capacity)
	{
		reverse(_size + len);
	}
	for (size_t i = _size; i >pos; i--)
	{
		_str[i + len] = _str[i];
	}
	for (size_t i = 0; i < len; i++)
	{
		_str[pos++] = str[i];
	}
	_size += len;
	return *this;
}
leo::string& leo::string::erase(size_t pos, size_t len)
{
	assert(pos<_size);
	if (_size - pos >= len)
	{
		for (size_t i = pos + len; i <= _size; i++)
		{
			_str[i - len] = _str[i];
		}
		_size -= len;
	}
	else
	{
		_size = pos ;
		_str[_size] = '\0';
	}
	return *this;
}
size_t leo::string::find(char c)
{
	size_t pos = 0;
	while (pos < _size)
	{
		if (_str[pos] == c)
		{
			return pos;
		}
		pos++;
	}
	return -1;
}
size_t leo::string::find(const char* str)
{
	char* p = strstr(_str, str);
	if (p)
		return p - _str;
	else
		return -1;
}
char& leo::string::operator[](size_t i)
{
	assert(i < _size);
	return _str[i];
}
const char& leo::string::operator[](size_t i)const
{
	assert(i < _size);
	return _str[i];
}
leo::string& leo::string::operator+=(const char c)
{
	push_back(c);
	return *this;
}
leo::string& leo::string::operator+=(const char* str)
{
	append(str);
	return *this;
}
size_t leo::string::size()const
{
	return _size;
}
size_t leo::string::capacity()const
{
	return _capacity;
}
const char* leo::string::c_str()const
{
	return _str;
}
leo::string::iterator leo::string::begin()
{
	return _str;
}
leo::string::iterator leo::string::end()
{
	return _str + _size;
}
leo::string::~string()
{
	if (_str == nullptr)
		return;
	delete[] _str;
	_size = _capacity = 0;
}


std::ostream& leo::operator<<(std::ostream& out, const string& s)
{
	for (int i = 0; i < s.size(); i++)
	{
		out << (s[i]);
	}
	return out;
}
std::istream& leo::operator>>(std::istream& in, leo::string& s)
{
	s = "";
	char c;
	c = cin.get();
	if(c!='\n')
		s.push_back(c);
	while((c = cin.get())!='\n')
	{
		if (c == ' ')
			break;
		s.push_back(c);
	}
	return in;
}
size_t leo::string::npos = -1;