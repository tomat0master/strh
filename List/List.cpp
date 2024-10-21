#include "List.h"
#include <iostream>

int main()
{

   List<int>list1({1,2,3,4,5});  //初始化列表构造函数
   List<int>list2(list1);    //拷贝构造函数
   list1.printList();        //pinrtlist()包含retrieve(),begin()和end()的测试
   list2.printList();
   std::cout << list1.size() <<std::endl;       //size()
   std::cout << list1.empty() <<std::endl;
   list1.clear();
   std::cout << list1.empty() <<std::endl;              //测试clear()和empty()
   list2.printList();             //深度复制
   List<int>list3 = list2;     //赋值运算符
   list3.printList();
   list3.pop_back();
   list3.pop_front();        //测试删除第一个和最后一个节点
   list3.printList();
   list3.push_back(5);
   list3.push_front(1);         //插入第一个与最后一个节点
   list3.printList();
   List<int>list4({1,1+1,1+2,1+3,1+4});   //测试右值引用的构造
   List<int>list44 = std::move(list4);    //移动调用函数
   list4.printList(); 

   List<int>list5({1,2,3,4,5});
   List<int>::const_iterator pos = list5.begin();
   std::cout << *pos << std::endl;       //一系列运算符测试
   std::cout << *(++pos) << std::endl;
   std::cout << *(pos++) << std::endl;
   std::cout << *(pos) << std::endl;
   std::cout << *(--pos) << std::endl;
   std::cout << *(pos--) << std::endl;
   std::cout << *(pos) << std::endl;
   List<int>::const_iterator ppos(pos);    //带参构造
   std::cout << (ppos==pos) << std::endl;
   std::cout << (ppos!=pos) << std::endl;

   List<int>list6({1,2,3,4,5});
   List<int>::iterator position = list6.begin();
   *(position) = 6;                                //动态迭代器的写操作
   std::cout << *(position) << std::endl;

  
   List<int>list7({1,2,3,4,5,6,7,8,9});
   List<int>::iterator p = list7.begin();
   ++p;
   list7.insert(p,7);                          //insert()
   list7.printList();
   list7.insert(p,7+1);
   list7.printList();                          //insert()右值引用
   p = list7.erase(p);                         //erase()
   list7.printList();
   List<int>::iterator pp = list7.end();
   list7.erase(p,pp);                          //测试范围删除
   list7.printList();



   List<int>list({1,2,3,4,5});
   List<int>::iterator q = list.end();
   ++q;
   std::cout << *q << std::endl;
   




    return 0;
}
