wade1357991@gmail.com
403210028吳士瑋

csie1中編譯成功並成功執行且main_program結果正確

HuffmanTree operator<< 有定義，可直接輸出

在 class Node、InternalNode 、TerminalNode 中
我將部分函數                 
int getNodeType()     
char getValue()
Node* getLChild()
Node* getRChild()

給成

int getNodeType()const
char getValue()const
Node* getLChild()const
Node* getRChild()const

有關in use at exit: 72704 bytes in 1 blocks的問題
有關still reachable:72704 bytes in 1 blocks的問題

http://senlinzhan.github.io/2017/12/31/valgrind/
引述文中:
　　使用 Valgrind 分析 C++ 程序时，有一些问题需要留意。例如，这个程序并没有发生内存泄漏，但是从HEAP SUMMARY可以看到，程序分配了 2 次内存，但却只释放了 1 次内存，为什么会这样呢？
　　实际上这是由于 C++ 在分配内存时，为了提高效率，使用了它自己的内存池。当程序终止时，内存池的内存才会被操作系统回收，所以 Valgrind 会将这部分内存报告为 reachable 的，需要注意，reachable 的内存不代表内存泄漏，例如，从上面的输出中可以看到，有 72704 个字节是 reachable 的，但没有报告内存泄漏。
