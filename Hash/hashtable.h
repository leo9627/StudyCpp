#pragma once
#include<vector>
#include<string>

namespace leo_close
{

	enum STATUS
	{
		EMPTY,
		EXITS,
		DELETE,
	};

	template<class T>
	struct HashNode
	{
		T _data;
		STATUS _status;
		HashNode(const T& data=T())
			:_data(data)
			,_status(EMPTY)
		{}
	};
	template<class K,class T,class KOFT>
	class Hash
	{
		typedef HashNode<T> HashNode;
	public:
		bool Insert(const T& data)
		{
			KOFT koft;
			//负载因子设为0.7
			if (_tables.size()==0||_nums * 10 / _tables.size() >= 7)
			{
				size_t newsize = _tables.size() == 0 ? 10 : 2 * _tables.size();

				Hash<K, T, KOFT> newhash;
				newhash._tables.resize(newsize);
				for (auto& e : _tables)
				{
					if(e._status==EXITS)
						newhash.Insert(koft(e._data));
				}
				_tables.swap(newhash._tables);
			}
			size_t index = koft(data) % _tables.size();
			if (_tables[index]._status ==EXITS)
			{
				if (_tables[index]._data == koft(data))
				{
					return false;
				}
				else
				{
					while (_tables[index]._status == EXITS)
					{
						if(koft(_tables[index]._data)==koft(data))
							return false;
						++index;
						if (index == _tables.size())
							index = 0;
					}
					_tables[index] = HashNode(data);
					_tables[index]._status = EXITS;
				}
			}
			else
			{

				_tables[index] = HashNode(data);
				_tables[index]._status = EXITS;
			}
			++_nums;
		}
		HashNode* Find(const K& key)
		{
			KOFT koft;
			size_t index = key % _tables.size();
			while (_tables[index]._status != EMPTY)
			{
				if (_tables[index]._status == EXITS && koft(_tables[index]._data) == key)
				{
					return &_tables[index];
				}
				else
					++index;
			}
			return nullptr;
		}
		bool erase(const K& key)
		{
			HashNode* ret = Find(key);
			if (ret)
			{
				ret->_status = DELETE;
				--_nums;
				return true;
			}
			else
			{
				return false;
			}
		}

	private:
		std::vector<HashNode> _tables;
		size_t _nums=0;
	};
}

namespace leo
{
	template<class T>
	struct HashNode
	{
		T _data;
		HashNode<T>* _next;
		HashNode(const T& data)
			:_data(data)
			,_next(nullptr)
		{}
	};
	template<class K>
	struct MyHash
	{
		size_t operator()(const K& key)
		{
			return key;
		}
	};
	template<>
	struct MyHash<std::string>
	{
		size_t operator()(const std::string& key)
		{
			size_t ret=0;
			for (size_t i = 0; i < (key.size()>10?10:key.size()); i++)
			{
				ret *= 31;
				ret += key[i];
			}
			return ret;
		}
	};

	template<class K,class T,class KOFT,class _Hash>
	class Hash_iterator
	{
		typedef HashNode<T> Node;
		typedef Hash_iterator<K, T,KOFT, _Hash> Self;
	public:
		Hash_iterator(Node* p,const std::vector<Node*>& tables)
			:_ptr(p)
			,_tables(tables)
		{}
		Self& operator++()
		{
			if (_ptr->_next)
			{
				_ptr = _ptr->_next;
				return *this;
			}
			else
			{
				KOFT koft;
				_Hash  hash;
				size_t i = hash(koft(_ptr->_data)) % _tables.size();
				++i;//!!!!
				for (; i < _tables.size(); i++)
				{
					if (_tables[i])
					{
						_ptr = _tables[i];
						return *this;
					}
				}
				_ptr = nullptr;
				return *this;
			}
		}
		T& operator*()
		{
			return _ptr->_data;
		}
		T* operator->()
		{
			return &_ptr->_data;
		}
		bool operator!=(const Self& it)
		{
			return _ptr != it._ptr;
		}
	private:
		Node* _ptr;
		const std::vector<Node*>& _tables;
	};
	template<class K,class T,class KOFT,class _Hash=MyHash<K>>
	class Hash
	{
		typedef HashNode<T> Node;
	public:
		typedef Hash_iterator<K, T, KOFT, _Hash> iterator;
		std::pair<iterator, bool> Insert(const T& data)
		{
			KOFT koft;
			_Hash hash;
			//负载因子->扩容
			if (_nums == _tables.size())  //负载因子为1
			{
				std::vector<Node*> newtables;
				size_t newsize = _tables.size() == 0 ? 10 : 2 * _tables.size();
				newtables.resize(newsize);
				for (size_t i = 0; i < _tables.size(); i++)
				{
					Node* cur = _tables[i];

					while (cur)
					{
						Node* next = cur->_next;
						size_t index = hash(koft(cur->_data)) % newtables.size();
						cur->_next = newtables[index];
						newtables[index] = cur;
						cur = next;
					}
				}

				_tables.swap(newtables);
			}

			size_t index = hash(koft(data)) % _tables.size();
			//头插
			Node* cur = _tables[index];
			while (cur)
			{
				if (koft(cur->_data) == koft(data))
					return std::make_pair(iterator(cur,_tables),false);
				else
					cur=cur->_next;
			}
			Node* newnode=new Node(data);
			newnode->_next=_tables[index];
			_tables[index] = newnode;
			++_nums;
			return std::make_pair(iterator(newnode,_tables), true);
		}
		iterator begin()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				if (_tables[i])
				{
					return iterator(_tables[i], _tables);
				}
			}
			return end();
		}
		iterator end()
		{
			return iterator(nullptr, _tables);
		}
		iterator Find(const K& key)
		{
			KOFT koft;
			_Hash hash;
			size_t index = hash(key) % _tables.size();
			Node* cur = _tables[index];
			while (cur)
			{
				if (koft(cur->_data) == key)
					return iterator(cur,_tables);
				cur = cur->_next;
			}

			return iterator(nullptr,_tables);
		}
		bool Erase(const K& key)
		{
			KOFT koft;
			_Hash  hash;
			size_t index = hash(key) % _tables.size();
			Node* cur = _tables[index];
			Node* prev = nullptr;
			while (cur)
			{
				if (koft(cur->_data) == key)
				{
					if (prev)
					{
						prev->_next = cur->_next;
						delete cur;
					}
					else
					{
						_tables[index] = cur->_next;
						delete cur;
					}
					return true;
				}
				else
				{
					cur = cur->_next;
				}
			}
			--_nums;
			return false;

		}
		void clear()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				Node* next = nullptr;
				while (cur)
				{
					next = cur->_next;
					delete cur;
					cur = next;
				}
				_tables[i] = nullptr;
			}
		}
		~Hash()
		{
			clear();
		}
	private:
		std::vector<Node*> _tables;
		size_t _nums=0;
	};
}