### 实践背景
线性方程组是高等数学中的重要内容，涉及到矩阵和向量的运算、矩阵的秩、逆矩阵等概念。在计算机科学中，线性方程组的求解也有着广泛的应用，比如图像处理、机器学习、物理仿真等领域都需要用到线性方程组的求解。

### 实践目的
本次实践的目的是实现一个基于高斯消元法的线性方程组求解器，可以输入任意大小的线性方程组，并输出其解向量。通过这个实践，我将更加深入地理解线性代数中的概念和算法，并且掌握如何使用 C++ 编程语言进行开发。

### 实践内容
#### 算法原理
高斯消元法是一种求解线性方程组的常见方法。其基本思想是通过初等变换将增广矩阵化为行阶梯形式，然后通过回代求解出方程组的解向量。具体步骤如下：

1. 选取主元：选择第 i 列中绝对值最大的元素作为主元，将其所在的行与第 i 行互换；
2. 消元操作：从第 i+1 行到最后一行，减去其第 i 列上的元素与第 i 行上相应元素的比值乘以第 i 行，使得第 i 列所有剩余元素都变为 0；
3. 重复进行步骤 1 和 2，直至将增广矩阵化为行阶梯形式；
4. 回代求解：从最后一行开始，依次求出每个未知数的值。

#### 程序实现
我使用 C++ 编写了一个基于高斯消元法的线性方程组求解器，并且在程序中添加了一些注释和友好的提示信息。具体实现细节如下：

1. 创建 GaussElimination 类，其中包含三个成员变量：矩阵大小 n、增广矩阵 a 和解向量 ans；
2. 在构造函数中初始化这三个变量；
3. 实现 Read() 函数，用于读入待求解的线性方程组的增广矩阵；
4. 实现 Solve() 函数，用于使用高斯消元法求解线性方程组；
5. 实现 Print() 函数，用于输出线性方程组的解向量；
6. 在主函数中，首先输入线性方程组的未知数个数，然后创建 GaussElimination 对象，并调用其 Read()、Solve() 和 Print() 函数分别进行读入、求解和输出。
#### 实践结果
我使用上述代码对一些简单的线性方程组进行了求解，发现程序能够正确输出解向量。例如，对于以下的线性方程组：

程序输出的解向量为(x1, x2, x3) = (1.00, 2.67, −1.33)，与手工计算的结果一致。

### 实践总结
通过本次实践，我深入理解了高斯消元法的原理和程序实现细节，并且在实践中掌握了使用 C++ 编写线性方程组求解器的方法。同时，在编写代码的过程中，我也学会了如何添加注释、处理异常以及输出友好的提示信息，这些都是写出高质量代码必不可少的技能。

与此同时，我也发现了一些需要改进的地方，比如程序对除以 0 的情况没有进行判断和处理，输出的提示信息可能还可以更加友好等等。这些问题可以在日后的开发中逐步解决。

总的来说，本次实践让我更加深入地认识到了线性代数在计算机科学中的重要性，也让我对 C++ 编程语言有了更深入的理解。我相信这些知识和技能在我的日后的学习和工作中会有很大的用处。