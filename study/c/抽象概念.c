/*流:就是个中间数据的概念,表示是持续不断的一种过程,流并不是一个具体的载体或者硬件，所以不存在你发送到流这样的说法,你可以理解为，系统通过接口调用后，把你给的数据封装好，形成了数据流其中的一块，然后再被写进文件等等,类似高速路，有入口和出口,车流就是数据流,数据进入的时候就是上高速路,每个数据就是一个车
分类：
GitHub Copilot: 在C语言中，流（stream）可以分为标准流和用户自定义流。标准流是指由标准库提供的三个流：标准输入流（stdin）、标准输出流（stdout）和标准错误流（stderr）。这些流通常与控制台相关联，可以用于从控制台读取输入或将输出打印到控制台上。用户自定义流是指由程序员自己创建的流，可以与文件、网络套接字等数据源相关联，用于读取或写入数据。在C语言中，流是通过标准库中的FILE结构体来表示的。常见的流操作包括打开、关闭、读取、写入、定位等。*/

/*重定向：GitHub Copilot: 重定向（redirection）是指将程序的输入或输出从标准输入/输出设备（如控制台）转向到其他设备或文件中。在Linux和Unix系统中，可以使用重定向符号`<`和`>`来实现重定向。例如，`command < input.txt`表示将`command`程序的输入从文件`input.txt`中读取，而`command > output.txt`表示将`command`程序的输出写入到文件`output.txt`中。在Windows系统中，可以使用`<`和`>`符号来实现重定向，例如`command < input.txt`和`command > output.txt`。重定向可以使程序的输入输出更加灵活，可以将程序的输出保存到文件中，也可以从文件中读取输入数据，而不必手动输入或输出。
GitHub Copilot: 当你在使用计算器时，你可以通过键盘输入数字和运算符，然后计算器会将这些输入转换为计算结果并在屏幕上显示出来。这就是一个简单的输入输出过程。现在，假设你想将计算结果保存到文件中，或者从文件中读取输入数据进行计算，这时你就可以使用重定向来实现。类比到程序中，重定向就是将程序的输入或输出从标准输入/输出设备（如控制台）转向到其他设备或文件中，使得程序的输入输出更加灵活。
重定向输入：C:\Users\LU>D:\Programs\VScode\c_project\tool\test < C:\Users\LU\Desktop\input.txt
终端：man's souls will be shaken with the violences of war.
we shall prevail.
重定向输出：C:\Users\LU>D:\Programs\VScode\c_project\study\HelloWorld > C:\Users\LU\Desktop\output.txt
output.txt:Hello World
           你好世界
组合重定向：C:\Users\LU>D:\Programs\VScode\c_project\study\HelloWorld < C:\Users\LU\Desktop\input.txt > C:\Users\LU\Desktop\output.txt
output.txt:Hello World
           你好世界
*/

/*空字符和空指针
从概念上看，两者完全不同。空字符（或'\0'）是用于标记C字符串末尾的字符，其对应字符编码是0。由于其他字符的编码不可能是 0，所以不可能是字符串的一部分。
空指针（或NULL）有一个值，该值不会与任何数据的有效地址对应。通常，函数使用它返回一个有效地址表示某些特殊情况发生，例如遇到文件结尾或未能按预期执行。
空字符是整数类型，而空指针是指针类型。两者有时容易混淆的原因是：它们都可以用数值0来表示。但是，从概念上看，两者是不同类型的0。
另外，空字符是一个字符，占1字节；而空指针是一个地址，通常占4字节。
*/

/*作用域：
  块作用域，函数体是一个块，函数中的任意复合语句也是一个块，例如：for,while,if,do while
  函数作用域：指在函数内部定义的变量的作用域。这些变量（通常称为局部变量）只能在定义它们的函数内部访问，并且它们的生命周期只是函数的执行时间。
  函数原型作用域：形参定义处到原型声明结束/
  文件作用域：
  #include <stdio.h> //C预处理实际上是一个文本替换过程，它将#include指令替换为stdio.h文件的内容。因此，stdio.h文件中的所有声明都可以在程序中使用。这些声明的作用域称为文件作用域，因为它们在整个文件中都是可见的。所以，编译器源代码文件和所有的头文件都看成是一个包含信息的单独文件，这个文件被称为翻译单元
  int units=0; //该变量(全局变量)具有文件作用域，因为它在函数外定义，可见范围是所有翻译单元，若加上static，则可见范围是该文件，即只能在该文件中使用。其他变量在使用它之前必须用extern声明它
  void critic(void);
  int main(void){...extern int units;...} //extern声明，表示units是在别处定义的，这里只是引用，若省略extern，则编译器会认为units是在main()中定义的，而不是在别处定义的，会隐藏外部变量units
  int arr; //对main()不可见，但对critic()可见，作用域是从声明处到文件结尾；只能用常量初始化，如果未能初始化会被自动初始化为0
  void critic(void){...}

  存储类别和函数
  double gamma(double); //一般都是extern外部函数，但是可以省略，因为函数的作用域是整个文件，所以不需要extern
  static double beta(int,int);
  extern double delta(double,int);
  以上函数中beta()不能被调用，因为以static存储类别说明符创建的函数属于特定模块私有，这样避免了名称重复问题

  return 0和exit(0)的区别：
  return 0只是把控制权移交给上一层递归直至最初的一级，而exit(0)是直接退出整个程序，不会执行后面的语句
  */