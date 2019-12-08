# DataStructure-C
Codes for "Fundamentals of Data Structures in C"


####Weixiao的第一份代码仓库

以《数据结构 C语言版》，机械工业出版社 为基础，包含部分数据结构的C++实现代码。


##§1 基本概念
ADT：抽象数据类型


##§2 数组与结构
1. ADT数组
2. 结构、共用体
3. 多项式
4. ADT稀疏矩阵
   + 存储方式：三元组
   + 转置：[稀疏矩阵的快速转置](https://github.com/hahachicken/DataStructure-C/tree/master/%C2%A72%20%E6%95%B0%E7%BB%84%E4%B8%8E%E7%BB%93%E6%9E%84/%E7%A8%80%E7%96%8F%E7%9F%A9%E9%98%B5%E5%BF%AB%E9%80%9F%E8%BD%AC%E7%BD%AE)
   + 矩阵乘法
5. 多维数组的存储
   + int Array[n][n][n]...
   + 临接表
6. 字符串
   + 存储
   index = [0] [1] [2] ... [-1]
   array = 'a' 'b' 'c' ... '\0'
   + 字符串模式
      + 朴素的字符串模式匹配
      + ==KMP算法==
         O(n+m)，n目标字符串长度，m匹配模式长度


##§3 栈与队列
   1. ADT栈
      + 函数调用在内存中使用栈的方式调用 => 递归函数皆可栈实现
      + 排列组合
   2. 队列
      + 经典队列
      + 双端队列
   3. 迷宫问题
   4. [表达式求值](https://github.com/hahachicken/DataStructure-C/tree/master/%C2%A73%20%E6%A0%88%E4%B8%8E%E9%98%9F%E5%88%97/%E4%B8%AD%E7%BC%80%E8%A1%A8%E8%BE%BE%E5%BC%8F%E6%B1%82%E5%80%BC)
      + 后缀表达式求值
      + 中缀表达式转后缀表达式
      

##§4 链表
   1. new & delete & Ptr
   2. 单链表
   3. **栈**&**队列**的链表形式
   4. 多项式的循环链表
   5. 寻找等价类
   6. ==**稀疏矩阵**的十字链表形式==

##§5 树
   1. ADT
      + 存储：列表、链式
      + 度
   2. [二叉树](https://github.com/hahachicken/DataStructure-C/tree/master/%C2%A75%20%E6%A0%91/%E4%BA%8C%E5%8F%89%E6%A0%91)：Binary Tree
      + [先序表达式建立二叉树](https://github.com/hahachicken/DataStructure-C/tree/master/%C2%A75%20%E6%A0%91/%E5%89%8D%E5%BA%8F%E8%A1%A8%E8%BE%BE%E5%BC%8F%E7%94%9F%E6%88%90%E4%BA%8C%E5%8F%89%E6%A0%91)
   3. 二叉树的遍历：
      + 前、中、后序:
      [中序线索二叉树](https://github.com/hahachicken/DataStructure-C/tree/master/%C2%A75%20%E6%A0%91/%E4%B8%AD%E5%BA%8F%E7%BA%BF%E7%B4%A2%E4%BA%8C%E5%8F%89%E6%A0%91)
      + ==层序遍历==
      队列实现
   4. 可满足性问题（NP完全问题之一）
   5. [最大堆](https://github.com/hahachicken/DataStructure-C/tree/master/%C2%A77%20%E6%8E%92%E5%BA%8F/%E6%9C%80%E5%A4%A7%E5%A0%86)
      + 线性存储
   6. **二叉查找（实现内容关联§10）**
      + 静态搜索 ***等概率***
         顺序查找、折半查找、斐波那契查找、插值查找
      + 静态查找 ***非等概率***
         + [二叉查找树](https://github.com/hahachicken/DataStructure-C/tree/master/%C2%A75%20%E6%A0%91/%E4%BA%8C%E5%8F%89%E6%9F%A5%E6%89%BE%E6%A0%91)
            1. 保证左子树节点 <= 节点 <= 右子树节点节点
            2. 生成最简单，性能最差，可能退化成链表
         + ==最优查找树:又称哈夫曼树==
            1. 带权路径长度达到最小
               查找概率越大的节点离根越近
               构建时间达到O(n^3)
            2. 等概率情况下：即完全二叉树
               不等概率：利用最小堆生成
         + ==次优查找树==
            1. 针对的是静态非等概率下的搜索需求
            同时满足： 优于朴素的二叉搜索树的搜索性能，小于AVL树的构造开支，且引起的性能损失可接受
            2. 构造方法：先排序，再选取左右概率差最小的节点进行分裂

      + 动态搜索树
         + [平衡二叉搜索树 - AVL树](https://github.com/hahachicken/DataStructure-C/tree/master/%C2%A75%20%E6%A0%91/AVL%E6%A0%91)
         + 2-3树
            弱化AVL的平衡条件得到
         + 2-3-4树 红黑树
            弱化2-3树的分裂条件，数据移动更少
            红黑树与2-3-4树等价，优化了存储
         + B树
         + B+树
         + 检索树
         + 。。。

   7. 森林
      + ==并查集==

##§6 图
   1. ADT图
      + 存储：==邻接矩阵==、==邻接表==、==邻接多重表==
   2. 操作
      + 搜索
         + 深度优先搜索 DFS
         + 广度优先搜索 BFS
      + 连通
         + 连通分支：BFS遍历
   3. 最小生成树
      + Kruskal：找最小不产生回路的边
      + Prim：找能到达的点中 路径权值最校的点
   4. 最短路径
      + ==蒂彻斯特算法==
         O(n^2)
      + ==动态规划算法==
         O(n^3),时间常数优于n*(蒂彻斯特)
   5. 活动网络
      + 拓扑序列
      + AOV：可行工程 = 优先关系是传递且反自反的
      + AOE
         + 最 早/晚 开始时间
         + 关键路径

##§7 排序
   1. ==插入排序== 
      最坏情况 ～ 平均情况 ～ O(n^2)
   2. ==快速排序==
      最坏情况 ～ O(n^2)
      平均 ～ O(n * log2(n))
   3. 归并排序
   4. [堆排序](https://github.com/hahachicken/DataStructure-C/tree/master/%C2%A77%20%E6%8E%92%E5%BA%8F/%E6%9C%80%E5%A4%A7%E5%A0%86)
      O(n * log2(n))

##§8 散列

##§9 堆

##§10 搜索
本质上是基于排序的搜索，散列的hash()是基于计算的搜索
   1. 最优二叉查找树
   2. 次优秀二叉查找书（非等概率）
   3. [AVL树](https://github.com/hahachicken/DataStructure-C/tree/master/%C2%A75%20%E6%A0%91/AVL%E6%A0%91)
   4. 2-3树
   5. 2-3-4树
   6. 红黑树：2-3-4树的等价形式，空间复杂度更优 
   7. B/B+ 树
   8. 检索树


