在C++中，我们可以使用指针来创建链表。每个节点都是一个包含数据和指向下一个节点的指针的结构体。下面是一个基本的链表的定义：

```C++

struct Node {

int data;

Node* next;

};

```

上面定义了一个包含 data 和 next 指针的 Node 结构体。其中，data 存储节点数据，next 指向下一个节点。

可以使用循环来遍历链表：

```C++

Node* current = head;

while (current != nullptr) {

std::cout << current->data << " ";

current = current->next; //当 current 指向 nullptr 时，即遍历到链表末尾，循环结束。

}

```

在使用链表时，我们需要手动释放分配的内存，否则会导致内存泄漏。可以使用 delete 关键字来释放节点所占用的内存：

```C++

Node* current = head;

while (current != nullptr) {

Node* temp = current;

current = current->next;

delete temp;

}

```

什么情况下适合用链表：

链表适合用于需要频繁插入和删除元素的场景。因为在链表中，每个元素都包含一个指向下一个元素的指针，插入或删除元素只需要修改相应指针即可，不需要像数组那样移动大量元素来保持顺序，避免了大量的时间开销。

链表还适合用于动态扩展的情况，因为链表的大小可以动态增长或缩小，不会浪费空间。

另外，链表还适用于对元素访问顺序无特定要求的情况下，因为链表中的元素并不是存储在一段连续的内存空间中。

下面列举一些常见的用例：

1. 需要实现一个任务队列，队列中的任务可能动态增加或删除。
2. 需要实现一个浏览历史记录，每当用户访问一个页面时，就将该页面加入链表中，从而实现浏览历史记录。
3. 需要实现一个图，图中的节点和边都可以动态增加或删除。

需要注意的是，链表的缺点是访问某个元素的时间复杂度为 O(n)，比数组的 O(1) 要慢。因此，在需要频繁访问元素的场景下，应该使用数组。另外，链表还会消耗额外的空间来存储指针，因此在空间敏感的场景下，也应该慎重使用链表。


链表是一种常见的数据结构，它由一系列节点组成，每个节点包含一个数据元素和一个指向下一个节点的指针。

链表常用于实现队列、栈、哈希表等数据结构。以下是一个简单的链表示例：

class Node{

public:

    int val;

    Node* next;

    Node(int x) : val(x), next(NULL) {}

};

Node* head = new Node(1);

head->next = new Node(2);

head->next->next = new Node(3);

// 遍历链表

Node* cur = head;

while(cur != NULL){

    cout << cur->val << " ";

cur = cur->next;

}

上面的代码用一个指针变量 cur 遍历链表中的每个节点，并输出该节点的值。

需要注意的是，遍历链表时必须从链表的头节点开始遍历，并在每个节点上调用 next 指针来获取下一个节点。

// 释放内存空间

需要注意的是，在使用完链表后必须释放掉链表中的所有内存空间，否则会导致内存泄漏：

上面的代码用一个指针变量 cur 遍历链表中的每个节点，并依次释放每个节点的内存空间。

Node* cur = head;

while(cur != NULL){

    Node* tmp = cur;

cur = cur->next;

    delete tmp;

}

## 1. 链表反转

链表反转是一道非常经典的面试题，假设我们有一个链表 head，要求反转这个链表，即将原来的 head 变成新的尾节点。

通常可以使用三个指针变量 prev、cur 和 next 来实现链表反转。具体做法是，先将 prev 初始化为 NULL，cur 初始化为 head，然后依次遍历链表，对于每个节点：

- 将 next 指针指向当前节点的下一个节点，避免链表的断裂；
- 将当前节点的 next 指针指向 prev，实现节点的反转；
- 将 prev 指针指向当前节点，为下一轮循环做好准备；
- 将 cur 指针指向 next，继续遍历。

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

Node* merge(Node* l1, Node* l2){

    Node* dummy = new Node(0);

    Node* cur = dummy;

    while(l1 != NULL && l2 != NULL){

        if(l1->val < l2->val){

            cur->next = l1;

l1 = l1->next;

        }

        else{

            cur->next = l2;

l2 = l2->next;

        }

cur = cur->next;

    }

    if(l1 != NULL) cur->next = l1;

    if(l2 != NULL) cur->next = l2;

    return dummy->next;

}


Node* sortList(Node* head) {

    if(head == NULL || head->next == NULL){

        return head;

    }

    Node* slow = head;

    Node* fast = head->next;

    // 使用快慢指针将链表一分为二

    while(fast != NULL && fast->next != NULL){

slow = slow->next;

fast = fast->next->next;

    }

    Node* mid = slow->next;

    slow->next = NULL;

    Node* l1 = sortList(head);

    Node* l2 = sortList(mid);

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

bool hasCycle(Node* head) {

    Node* slow = head;

    Node* fast = head;

    while(fast != NULL && fast->next != NULL){

slow = slow->next;

fast = fast->next->next;

        if(slow == fast){

            return true;

        }

    }

    return false;

}

```

以上是链表使用的三个例子，链表的应用非常广泛，可以支持丰富的算法和数据结构操作，如栈、队列、哈希表、LRU缓存等。
