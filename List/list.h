#pragma once
#include<assert.h>

namespace popo
{
	template<class T>
	struct list_node
	{
		list_node<T>* _next;
		list_node<T>* _prev;
		T _data;

		list_node(const T& x = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _data(x)
		{}
	};

	template<class T, class Ref, class Ptr>
	struct list_iterator
	{
		typedef list_node<T> Node;
		typedef list_iterator<T, Ref, Ptr> Self;

		Node* _node;

		list_iterator(Node* node)
			:_node(node)
		{}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self operator++(int)
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Self operator--(int)
		{
			Self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const Self& it)
		{
			return _node != it._node;
		}

		bool operator==(const Self& it)
		{
			return _node == it._node;
		}
	};

	/*template<class T>
	struct list_iterator
	{
		typedef list_node<T> Node;

		Node* _node;

		list_iterator(Node* node)
			:_node(node)
		{}

		T& operator*()
		{
			return _node->_data;
		}

		T* operator->()
		{
			return &_node->_data;
		}

		list_iterator<T>& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		bool operator!=(const list_iterator<T>& it)
		{
			return _node != it._node;
		}

		bool operator==(const list_iterator<T>& it)
		{
			return _node == it._node;
		}
	};

	template<class T>
	struct list_const_iterator
	{
		typedef list_node<T> Node;

		Node* _node;

		list_const_iterator(Node* node)
			:_node(node)
		{}

		const T& operator*()
		{
			return _node->_data;
		}

		const T* operator->()
		{
			return &_node->_data;
		}

		list_const_iterator<T>& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		bool operator!=(const list_const_iterator<T>& it)
		{
			return _node != it._node;
		}

		bool operator==(const list_const_iterator<T>& it)
		{
			return _node == it._node;
		}
	};*/

	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		//typedef Node* iterator;
	/*	typedef list_iterator<T> iterator;
		typedef list_const_iterator<T> const_iterator;*/

		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;

		iterator begin()
		{
			//return iterator(_head->_next);
			iterator it(_head->_next);
			return it;
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}

		void empty_init()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;

			_size = 0;
		}

		list()
		{
			empty_init();
		}

		/*list(initializer_list<T> lt)
		{
			empty_init();

			for (auto& e : lt)
			{
				push_back(e);
			}
		}*/

		// lt2(lt1)
		list(const list<T>& lt)
		{
			empty_init();
			for (auto& e : lt)
			{
				push_back(e);
			}
		}

		// lt1 = lt3
		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		size_t size() const
		{
			return _size;
		}

		void push_back(const T& x)
		{
			/*Node* newnode = new Node(x);

			Node* tail = _head->_prev;
			newnode->_prev = tail;
			tail->_next = newnode;
			newnode->_next = _head;
			_head->_prev = newnode;*/

			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_front()
		{
			erase(begin());
		}

		void pop_back()
		{
			erase(--end());
		}

		void insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;

			Node* newnode = new Node(x);

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;

			++_size;
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());

			Node* cur = pos._node;
			Node* nextNode = cur->_next;
			Node* prevNode = cur->_prev;

			prevNode->_next = nextNode;
			nextNode->_prev = prevNode;

			delete cur;

			--_size;

			return iterator(nextNode);
		}

	private:
		Node* _head;
		size_t _size;
	};
}