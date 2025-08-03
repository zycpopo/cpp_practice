#pragma once
template<class K,class V>

struct AVLTreeNode
{
	pair<K, V> _kv;
	AVLTreeNode<K, V>* _left;
	AVLTreenode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	int _bf;

	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_bf(0)
	{}
};

template <class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new node(kv);
			return true;
		}

		node* parent = nullptr;
		node* cur = _root;
		while (cur)
		{
			if (cur->kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else {
				return false;
			}
		}
		cur = new node(kv);
		if (parent->kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else {
			parent->_left = cur;
		}
		cur->_parent = parent;

		//更新平衡因子
		while (parent)
		{
			if (cur == parent->_left)
			{
				parent->_bf--;
			}
			else {
				parent->_bf++;
			}

			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//旋转
				if (parent->_bf == 2 || parent->_bf == -2)
				{
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					RotateLR(parent);
				}

				break;
			}
			else {
				assert(false);
			}
		}

		return true;
	}
	void RotateR(node* parent)
	{
		node* subL = parent->_left;
		node* subLR = subL->_right;

		parent->_left = subLR;
		subL->_right = parent;

		if (subLR)
		{
			subLR->_parent = parent;
		}
			node* parentParent = parent->_parent;
			parent->parent = subL;

		if (parent == _root)
		{
			_root = subL;
			subL->parent = nullptr;
		}
		else {
			if (parentParent->_bf == parent)
			{
				parentPaerent->_left = subL;
			}
			else {
				parentParent->_right = subL;
			}
			subL->_bf_parent = parenParent;
		}
		
		subL->_bf = parent->_bf = 0;
	}
	void RotateL(node* parent)
	{
		node* subR = parent->_right;
		node* subRL = subR->_left;
		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}
		node* parentParent = parent->_parent;
		subR->_left = parent;
		parent->_parent = subR;
		if (parentParent == nullptr)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (parent == parentParent->_left)
			{
				parentParent->_left = subR;
			}
			else
			{
				parentParent->_right = subR;
			}
			subR->_parent = parentParent;
		}
		parent->_bf = subR->_bf = 0;
	}
	void RotateLR(node* parent)
	{
		RotateL(parent->_left);
		RotateR(parent);
	}
private:
	node* _root = nullptr;
};