## 链表

### 链表定义

```C++
struct Node {
int data;
Node* next; // 指针
};
```

### 遍历链表

循环：

```C++
Node* current = head;
while (current != nullptr) {
std::cout << current->data << " ";
current = current->next; //当 current 指向 nullptr 时，即遍历到链表末尾，循环结束。
}
```

### 需要手动释放分配的内存

在使用链表时，我们需要手动释放分配的内存，否则会导致内存泄漏。可以使用 delete 关键字来释放节点所占用的内存：

```C++
Node* current = head;
while (current != nullptr) {
Node* temp = current;
current = current->next;
delete temp;
}
```

### 什么情况下适合用链表

* 需要频繁插入和删除元素的场景。因为在链表中，每个元素都包含一个指向下一个元素的指针，插入或删除元素只需要修改相应指针即可，不需要像数组那样移动大量元素来保持顺序，避免了大量的时间开销。
* 链表还适合用于动态扩展的情况，因为链表的大小可以动态增长或缩小，不会浪费空间。
* 链表还适用于对元素访问顺序无特定要求的情况下，因为链表中的元素并不是存储在一段连续的内存空间中。

常见的用例：

1. 需要实现一个任务队列，队列中的任务可能动态增加或删除。
2. 需要实现一个浏览历史记录，每当用户访问一个页面时，就将该页面加入链表中，从而实现浏览历史记录。
3. 需要实现一个图，图中的节点和边都可以动态增加或删除。

### 缺点

1. 链表的缺点是访问某个元素的时间复杂度为 O(n)，比数组的 O(1) 要慢。在需要频繁访问元素的场景下，应该使用数组。
2. 链表还会消耗额外的空间来存储指针，因此在空间敏感的场景下，也应该慎重使用链表。

## 1. 链表反转

假设我们有一个链表 head，要求反转这个链表，即将原来的 head 变成新的尾节点。

通常可以使用三个指针变量 prev、cur 和 next 来实现链表反转。
具体做法是，先将 prev 初始化为 NULL，cur 初始化为 head，然后依次遍历链表，对于每个节点：

* 将 next 指针指向当前节点的下一个节点，避免链表的断裂；
* 将当前节点的 next 指针指向 prev，实现节点的反转；
* 将 prev 指针指向当前节点，为下一轮循环做好准备；
* 将 cur 指针指向 next，继续遍历。
遍历完毕后，prev 指向新的头节点，即反转前原来的尾节点。

代码如下：

```c++
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* cur = head;
    while(cur != NULL){
        Node* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
```

## 2. 链表排序

链表排序也是一道经典面试题。一个朴素的做法是将链表转换为数组，使用标准库函数排序后再转换回来。如果不使用额外的空间，则可以使用归并排序。

具体做法是将链表分成两部分，对每部分分别排序，然后将两个有序链表合并成一个有序链表。在合并过程中，可以创建一个虚拟头节点作为新链表的头节点，然后依次比较两个链表的头节点，将较小的节点接到新链表的末尾，直到其中一个链表为空，再将剩余的节点直接接到新链表的末尾即可。

代码如下：

```c++
Node *merge(Node *l1, Node *l2) {
    Node *dummy = new Node(0);

    Node *cur = dummy;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }

    if (l1 != NULL)
        cur->next = l1;
    if (l2 != NULL)
        cur->next = l2;
    return dummy->next;
}

Node *sortList(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node *slow = head;
    Node *fast = head->next;
    // 使用快慢指针将链表一分为二
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *mid = slow->next;
    slow->next = NULL;
    Node *l1 = sortList(head);
    Node *l2 = sortList(mid);
    return merge(l1, l2);
}

```

## 3. 链表是否有环

判断链表是否有环也是一道经典面试题。方法是使用两个指针变量 slow 和 fast，起始时它们都指向链表的头节点。然后依次遍历链表：

- slow 指针每次移动一个节点，即 slow = slow->next；
- fast 指针每次移动两个节点，即 fast = fast->next->next；
- 如果 fast 找到 NULL，说明链表不包含环；
- 如果 slow 和 fast 在某个节点相遇，说明链表包含环。

具体实现如下：

```c++
bool hasCycle(Node *head) {
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

```

以上是链表使用的三个例子，链表的应用非常广泛，可以支持丰富的算法和数据结构操作，如栈、队列、哈希表、LRU缓存等。

## 树

节点：根节点、父节点、子节点、兄弟节点
空树：一棵树可以没有任何节点
一棵树可以只有1个节点，也就是只有根节点
子树：左子树、右子树
节点的度（degree）：子树的个数
树的度：所有节点度中的最大值
叶子节点（leaf）：度为 0 的节点
非叶子节点：度不为 0 的节点
层数（level）：根节点在第1层，根节点的子节点在第2层，以此类推（有些教程也从第0层开始计算）
节点的深度（depth）：从根节点到当前节点的唯一路径上的节点总数
节点的高度（height）：从当前节点到最远叶子节点的路径上的节点总数
树的深度：所有节点深度中的最大值
树的高度：所有节点高度中的最大值
树的深度等于树的高度

### 二叉树的遍历

前序遍历（Preorder Traversal）：根节点、左子树、右子树 — （根节点访问在前）
中序遍历（Inorder Traversal） ：左子树——根节点——右子树
后序遍历（Postorder Traversal）
层序遍历（Level Order Traversal）：从上到下、从左到右依次访问每一个节点

中序遍历：
1. 递归
递归公式 Preorder(node) = Preorder(node->left)->print node->preorder(node->right)
中止条件：node是否为空，为空则返回
2. 迭代
把递归的过程模拟出来