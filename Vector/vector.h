#pragma once

#include<iostream>
#include<algorithm>
#include<initializer_list>
#include<stdexcept>

namespace popo {

	template <typename T>
	class vector {
	public:
		//类型别名
		using value_type = T;
		using iterator = T*;
		using const_iterator = const T*;



		//构造函数&析构函数
		vector() {}
		//构造一个包含n个元素vector，初始化为value
		vector(size_t n, const T& value = T())
		{
			_start = new T[n];
			_finish = _start + n;
			_end_of_storage = _finish;
			std::fill(_start, _finish, value);
		}
		//初始化列表
		vector(std::initializer_list<T> init)
		{
			_start = new T[init.size()];
			_finish = _start + init.size();
			_end_of_storage = _finish;
			std::copy(init.begin(), init.end(), _start);//拷贝初始化列表数据
		}
		//拷贝构造函数
		vector(const vector& other)
		{
			_start = new T[other.capcity()];
			_finish = _start + other.size();
			_end_of_storage = _start + other.capacity();
			std::copy(other._start, other._finish, _start);//拷贝数据
		}
		//移动构造函数
		vector(vector&& other) noexcept
			:_start(other._start),
			_finish(other._finish),
			_end_of_storage(other._end_of_storage) {
			other._start = other._finish = other._end_of_storage = nullptr;
		}
		//析构函数
		~vector()
		{
			delete[] _start;
		}
	    


		//赋值运算符
		//拷贝赋值
		vector& operator=(const vector& other)
		{
			if (this != &other)
			{
				delete[]_start;
				_start = new T[other.capacity];
				_finish = _start + other.size();
				_end_of_storage = _start + other.capacity;
				std::copy(other._start, other._finish, _start);
			}
			return *this;
		}
		//移动赋值
		vector& operator=(vector&& other) noexcept 
		{
			if (this != &other) 
			{ 
				delete[] _start;
				_start = other._start;
				_finish = other._finish;
				_end_of_storage = other._end_of_storage;
				other._start = other._finish = other._end_of_storage = nullptr;
			}
			return *this;
		}



		//容量相关操作
		//判断vector是否为空
		bool empty() const noexcept
		{
			return _start == _finish;
		}
		//返回元素个数
		size_t size() const noexcept
		{
			return _finish - _start;
		}
		//返回当前容量大小
		size_t capacity() const noexcept
		{
			return _end_of_storage - _start;
		}
		//扩容
		void reserve(size_t new_cap)
		{
			if (new_cap > capacity()) {
				T* new_start = new T[new_cap];
				size_t old_size = size();
				std::copy(_start, _finish, new_start);
				delete[] _start;
				_start = new_start;
				_finish = _start + old_size;
				_end_of_storage = _start + new_cap;
			}
		}
		//收缩内存
		void shrink_to_fit() 
		{
			if (size() < capacity()) {
				T* new_start = new T[size()];       
				std::copy(_start, _finish, new_start);   
				delete[] _start;  
				_start = new_start;
				_finish = _start + size();
				_end_of_storage = _finish;
			}
		}



        //数据操作
        //清空数据
		void clear() noexcept 
		{
			_finish = _start;
		}
		//插入元素
		iterator insert(const_iterator pos, const T& value)
		{
			size_t offset = pos - _start;
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 1 : capacity() * 2);
			}
			for (iterator it = _finish; it > _start + offset; --it)
			{
				*it = *(it - 1);
			}
			_start[offset] = value;
			++_finish;
			return _start + offset;//返回新插入的元素位置
		}
        //删除指定位置的元素
		iterator erase(const_iterator pos)
		{
			size_t offset = pos - _start;
			for (iterator it = _start + offset; it < _finish - 1; ++it)
			{
				*it = *(it + 1);
			}
			return _start + offset;
		}
		//尾插元素
		void push_back(T&& value)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 1 : capacity() * 2);
			}
			*_finish++ = std::move(value);
		}
		//尾删元素
		void pop_back()
		{
			if (_finish > _start)
			{
				--_finish;
			}
		}
		//调整vector的大小
		void resize(size_t count, const T& value = T())
		{
			if (count > capacity())
			{
				reserve(count);
			}
			if (count > size()) 
			{
				std::fill(_finish, _start + count, value); // 填充新增元素
			}
			_finish = _start + count; // 调整 _finish
		}
        //交换两个vector的内容
		void swap(vector& other) noexcept
		{
			std::swap(_start, other._start);
			std::swap(_finish, other._finish);
			std::swap(_end_of_storage, other._end_of_storage);
		}



		//元素访问
		//下标访问
		T& operator[](size_t pos)
		{
			return _start[pos];
		}
		//at-pos访问
		T& at(size_t pos) 
		{
			if (pos >= size()) {
				throw std::out_of_range("vector::at");
			}
			return _start[pos];
		}



		//迭代器
		iterator begin() { return _start; }
		iterator end() { return _finish; }        //普通接口

		const_iterator begin() const { return _start; }
		const_iterator end() const { return _finish; }  //const接口
private:
	iterator _start=nullptr;
	iterator _finish=nullptr;
	iterator _end_of_storage = nullptr;
};
}