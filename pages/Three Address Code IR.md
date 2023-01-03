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
		- 比如运算上有加减乘除
		- 比如分支上有各种跳转