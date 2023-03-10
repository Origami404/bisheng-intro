- 在很多书里都会出现, 是早期编译器领域常用的 IR 形式
- 大概长这样:
	- ```cpp
	  for (int i = 0; i < 10; ++i) {
	      b[i] = i*i; 
	  }
	  ```
	- ```
	       t1 := 0                ; initialize i
	  L1:  if t1 >= 10 goto L2    ; conditional jump
	       t2 := t1 * t1          ; square of i
	       t3 := t1 * 4           ; word-align address
	       t4 := b + t3           ; address to store i*i
	       *t4 := t2              ; store through pointer
	       t1 := t1 + 1           ; increase i
	       goto L1                ; repeat loop
	  L2:
	  
	  ```
- 它有几个要素:
	- 指令有不同的种类
		- 运算上有加减乘除
		- 分支上有各种比较 + 跳转
		- 用于栈上内存分配, 内存读写, 指针操作的指令
		- 用于函数调用和返回的指令
		- 源语言中具有多种类型的话, 还会设计一些类型转换用的指令
	- 指令的操作对象是变量, 而不是指令
		- 变量, 或者更精确地说, 一个存储位置
		- 变量的值是可以变的; 换言之, **变量不是值**, 要想确定某位置中变量的值, 需要做进一步分析
		- 对指令的参数而言, 它需要的是参数的值; 对指令的结果而言, 它需要的是结果的那个位置
		- 字面量可以充当值, 但是不可以充当位置; 变量可以充当值也可以充当位置
- 它的内存形式有两种主流定义
	- 同型 IR
		- 用枚举实现指令的多态
		- ```cpp
		  class Value {};
		  class Variable : {};
		  class Literal {};
		  class Operation {};
		  ```
	- 异型 IR (怎么听起来怪怪的)
		- 用继承实现指令的多态
