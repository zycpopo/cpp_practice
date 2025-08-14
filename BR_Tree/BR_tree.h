// 禁用VS的安全函数警告，避免编译报错
#define _CRT_SECURE_NO_WARNINGS
// 引入pair类的头文件（用于存储键值对）
#include <utility>

// 定义红黑树节点的颜色枚举：红色、黑色
enum colour
{
    red,
    black
};

// 红黑树节点结构体模板：需同时接收键类型K和值类型V
template<class K, class V>
struct BRTreeNode
{
    std::pair<K, V> _kv;          // 存储键值对（节点核心数据）
    BRTreeNode* _left;            // 左子节点指针
    BRTreeNode* _right;           // 右子节点指针
    BRTreeNode* _parent;          // 父节点指针（迭代调整平衡需用到）
    colour _c;                    // 节点颜色（红/黑）

    // 节点构造函数：初始化数据和指针，默认颜色设为红色
    // 原因：新节点设为红色，仅可能违反“无连续红节点”规则，修复成本低于设为黑色（可能破坏黑平衡）
    BRTreeNode(const std::pair<K, V>& kv)
        : _kv(kv)                 // 初始化键值对
        , _left(nullptr)          // 左子初始为空
        , _right(nullptr)         // 右子初始为空
        , _parent(nullptr)        // 父节点初始为空
        , _c(red)                 // 新节点默认红色
    {}
};

// 红黑树类模板：封装节点操作逻辑
template<class K, class V>
class BRTree
{
    // 类型别名：简化节点指针的写法（后续用node代替BRTreeNode<K, V>）
    typedef BRTreeNode<K, V> node;
public:
    // 插入键值对：返回是否插入成功（重复键返回false）
    bool Insert(const std::pair<K, V>& kv)
    {
        // 场景1：树为空（根节点未初始化）
        if (_root == nullptr)
        {
            _root = new node(kv);   // 创建新节点作为根
            _root->_c = black;      // 红黑树规则2：根节点必须为黑色
            return true;            // 插入成功
        }

        // 场景2：树非空，先按二叉搜索树（BST）规则找插入位置
        node* parent = nullptr;     // 记录当前节点的父节点（用于后续链接新节点）
        node* cur = _root;          // 从根节点开始遍历
        while (cur)                 // 遍历到空节点时停止（找到插入位置）
        {
            if (cur->_kv.first < kv.first)  // 插入键 > 当前节点键：去右子树找
            {
                parent = cur;
                cur = cur->_right;
            }
            else if (cur->_kv.first > kv.first)  // 插入键 < 当前节点键：去左子树找
            {
                parent = cur;
                cur = cur->_left;
            }
            else  // 插入键 == 当前节点键：红黑树不允许重复键，插入失败
            {
                return false;
            }
        }

        // 步骤3：创建新节点并链接到父节点
        cur = new node(kv);         // 构造新节点（默认红色）
        if (parent->_kv.first < kv.first)  // 插入键 > 父节点键：新节点作为父的右子
        {
            parent->_right = cur;
        }
        else  // 插入键 < 父节点键：新节点作为父的左子
        {
            parent->_left = cur;
        }
        cur->_parent = parent;      // 设置新节点的父指针（后续调整平衡需回溯）

        // 核心步骤：平衡调整（从新节点的父节点开始回溯，修复颜色规则）
        // 只有父节点为红色时才需调整（父为黑色不会违反“连续红节点”规则）
        while (parent && parent->_c == red)
        {
            // 祖父节点：父节点的父节点（平衡调整需参考祖父和叔叔节点）
            node* grandfather = parent->_parent;
            if (grandfather == nullptr)  // 祖父为空（父节点是根），无需调整
                break;

            // 分支1：父节点是祖父节点的左子节点（左支场景）
            if (parent == grandfather->_left)
            {
                // 叔叔节点：祖父的右子节点（平衡调整的关键参考）
                node* uncle = grandfather->_right;

                // 子场景1.1：叔叔存在且为红色（可通过“着色”修复规则）
                if (uncle && uncle->_c == red)
                {
                    // 修复逻辑：父和叔改为黑色（消除连续红），祖父改为红色（维持黑平衡）
                    parent->_c = black;
                    uncle->_c = black;
                    grandfather->_c = red;

                    // 向上回溯：祖父改为红色后，可能与它的父节点形成连续红，需继续检查
                    cur = grandfather;
                    parent = cur->_parent;
                }
                // 子场景1.2：叔叔不存在或为黑色（需通过“旋转+着色”修复）
                else
                {
                    // 子场景1.2.1：新节点是父节点的左子（左-左型失衡）
                    if (cur == parent->_left)
                    {
                        RotateR(grandfather);  // 对祖父右旋：调整结构，降低左支高度
                        // 着色：父节点升为新的“祖父层”，设为黑色；原祖父降为右子，设为红色
                        parent->_c = black;
                        grandfather->_c = red;
                    }
                    // 子场景1.2.2：新节点是父节点的右子（左-右型失衡）
                    else
                    {
                        RotateL(parent);       // 先对父左旋：将左-右型转为左-左型
                        RotateR(grandfather);  // 再对祖父右旋：调整整体结构
                        // 着色：新节点升为“中间层”，设为黑色；原祖父降为右子，设为红色
                        cur->_c = black;
                        grandfather->_c = red;
                    }
                    break;  // 旋转+着色后，当前分支平衡已修复，无需继续回溯
                }
            }
            // 分支2：父节点是祖父节点的右子节点（右支场景，与左支对称）
            else
            {
                // 叔叔节点：祖父的左子节点
                node* uncle = grandfather->_left;

                // 子场景2.1：叔叔存在且为红色（着色修复）
                if (uncle && uncle->_c == red)
                {
                    // 同左支1.1：父和叔变黑，祖父变红，向上回溯
                    parent->_c = black;
                    uncle->_c = black;
                    grandfather->_c = red;

                    cur = grandfather;
                    parent = cur->_parent;
                }
                // 子场景2.2：叔叔不存在或为黑色（旋转+着色修复）
                else
                {
                    // 子场景2.2.1：新节点是父节点的右子（右-右型失衡）
                    if (cur == parent->_right)
                    {
                        RotateL(grandfather);  // 对祖父左旋：调整结构，降低右支高度
                        // 着色：父节点升为“祖父层”，设为黑色；原祖父降为左子，设为红色
                        parent->_c = black;
                        grandfather->_c = red;
                    }
                    // 子场景2.2.2：新节点是父节点的左子（右-左型失衡）
                    else
                    {
                        RotateR(parent);       // 先对父右旋：将右-左型转为右-右型
                        RotateL(grandfather);  // 再对祖父左旋：调整整体结构
                        // 着色：新节点升为“中间层”，设为黑色；原祖父降为左子，设为红色
                        cur->_c = black;
                        grandfather->_c = red;
                    }
                    break;  // 平衡修复，停止回溯
                }
            }
        }

        // 最终保障：无论调整过程如何，根节点必须为黑色（防止回溯时根被改为红色）
        _root->_c = black;
        return true;  // 插入成功
    }

private:
    // 左旋转函数：将节点parent的右子树“提升”为新的父节点，修复右支失衡
    // 适用场景：右-右型、右-左型失衡
    void RotateL(node* parent)
    {
        node* subR = parent->_right;    // subR：parent的右子节点（即将提升的节点）
        node* subRL = subR->_left;      // subRL：subR的左子节点（旋转后要挂到parent的右子）

        // 步骤1：将subRL挂到parent的右子
        parent->_right = subRL;
        if (subRL != nullptr)           // 若subRL非空，更新其父子关系
            subRL->_parent = parent;

        // 步骤2：将parent挂到subR的左子
        subR->_left = parent;
        node* pParent = parent->_parent; // pParent：parent的原父节点（旋转后subR要挂到这里）
        parent->_parent = subR;         // 更新parent的父指针为subR

        // 步骤3：将subR挂到原parent的父节点上
        if (pParent == nullptr)         // 原parent是根节点：subR成为新根
        {
            _root = subR;
        }
        else                            // 原parent不是根：根据原位置挂subR
        {
            if (pParent->_left == parent)  // 原parent是左子：subR挂到pParent的左子
                pParent->_left = subR;
            else                            // 原parent是右子：subR挂到pParent的右子
                pParent->_right = subR;
        }
        subR->_parent = pParent;        // 更新subR的父指针为pParent
    }

    // 右旋转函数：将节点parent的左子树“提升”为新的父节点，修复左支失衡
    // 适用场景：左-左型、左-右型失衡
    void RotateR(node* parent)
    {
        node* subL = parent->_left;     // subL：parent的左子节点（即将提升的节点）
        node* subLR = subL->_right;     // subLR：subL的右子节点（旋转后要挂到parent的左子）

        // 步骤1：将subLR挂到parent的左子
        parent->_left = subLR;
        if (subLR != nullptr)           // 若subLR非空，更新其父子关系
            subLR->_parent = parent;

        // 步骤2：将parent挂到subL的右子
        subL->_right = parent;
        node* pParent = parent->_parent; // pParent：parent的原父节点（旋转后subL要挂到这里）
        parent->_parent = subL;         // 更新parent的父指针为subL

        // 步骤3：将subL挂到原parent的父节点上
        if (pParent == nullptr)         // 原parent是根节点：subL成为新根
        {
            _root = subL;
        }
        else                            // 原parent不是根：根据原位置挂subL
        {
            if (pParent->_left == parent)  // 原parent是左子：subL挂到pParent的左子
                pParent->_left = subL;
            else                            // 原parent是右子：subL挂到pParent的右子
                pParent->_right = subL;
        }
        subL->_parent = pParent;        // 更新subL的父指针为pParent
    }

    node* _root = nullptr;  // 红黑树的根节点，初始为空
};