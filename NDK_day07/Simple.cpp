#include<stdio.h>  // 第一步：导入头文件

/*// 程序主入口
void main(){

	// 二级指针：就是对一级指针取地址
	
	int num = 12;
	// int*: 是指针，用于接收num地址返回值  &：获取地址
	int* p = &num;

	// int**：表示对p取地址 
	int** s_p = &p;
	// 意思就是：s_p存的是p的地址 p存的是num的地址
	printf("p 的值是：%p , s_p 的值是：%p" , p , s_p);  // s_p的地址是：0x0042FBC4 上边debug中存储的值是0042fbd0
	// 0042fbd0刚好就是p的地址，上边存储的值是+12

	// 如果想知道s_p的地址，可以写成下边代码
	// int*** s_s_p = &s_p; 多级指针

	// 通过二级指针怎么获取到最终的值？ s_p (*代表取值)
	printf("获取最终的值是：%d" , **s_p); // 获取最终的值是：12

	// 暂停
	getchar();
}*/

/*// 数组与数组指针
void main(){

	// 定义一个数组
	int arr[] = {1,2,3,4};

	// 遍历数组，这种写法用到Linux上，可能会有问题
	for (int i = 0; i < 4; i++){
		printf("%d\n" , arr[i]);
	}

	// for循环在c与c++中的正确写法，以后在c和c++中写for循环用下边这种方式就可以
	int i = 0;
	for (; i < 4;i++){
		printf("%d\n", arr[i]);
	}

	// 看一种现象： arr的值 = arr取地址的值 = arr[0]的地址的值，arr[0]的值就是首地址
	printf("arr = %p\n" , arr); // 打印数组： arr = 003DFE84
	printf("arr& = %p\n", &arr);// 打印数组地址： arr& = 003DFE84
	printf("arr[0]& = %p\n", &arr[0]); // 打印数组第0个位置的地址： arr[0] & = 003DFE84


	// 如何获取数组的指针[数组获取地址]
	// int[]* arr_p = &arr; 这种写法不行，因为c中没有这种写法

	// 数组指针一般都是：用int*去接，然后直接等于arr就可以
	// arr可以看做是上边的arr[0]
	// 数组指针指向的是数组的首地址
	int* arr_p = arr;  

	// 有了数组指针就可以做一系列的操作

	// 比如：获取指针第一个值

	
	// 数组第1位值
	printf("%d\n" , *arr_p); // *arr_p: 就是对arr取值，也就是对 arr[0]取值，也就是1

	// 比如：对指针++
	
	// 数组指针挪动1位 
	arr_p++;                // 对指针++，表示指针从1移动到2的位置，然后再通过 *arr_p对指针取值，就是2
	printf("%d\n", *arr_p); 

	// 数组指针从2的位置：再移动2位，就到4的位置了
	arr_p += 2;
	printf("%d\n", *arr_p); // 4

	// 数组指针从4的位置：再移动1位，由于已经超出了自定义 arr的范围，这个时候指针就移动到了系统内存中了，
	// 这个时候打印的值就是系统的内存的值，我们看不懂，但是这里不会角标越界
	arr_p += 1;
	printf("%d", *arr_p);

	// 上边输出语句打印结果如下：
	//  1
	//	2
	//	4
	// 	- 858993460  这个是系统内存的值，我们看不懂
	getchar();
}*/

// 对数组：采用指针，遍历数组以及循环赋值

/*
// 采用指针遍历数组 - 开发中一般不会使用这种方式
void main(){

	// 定义数组
	int arr[] = {1,2,3,4};
	// 采用指针对数组进行赋值
	int* arr_p = arr;

	// 循环遍历数组
	int i = 0;
	for (; i < 4;i++){
		printf("位置%d的值是：%d\n" , i , *(arr_p+i));
	}

	// 位置0的值是：1
	// 位置1的值是：2
	// 位置2的值是：3
	// 位置3的值是：4

	getchar();

}*/

/*
// 循环赋值 - 开发中一般不会使用这种方式
void main(){

	// 指定数组，并且长度是4
	int arr[4];
	// 采用指针对数组进行赋值
	int* arr_p = arr;

	int i = 0;
	for (; i < 4; i++){
		// 循环赋值
		*(arr_p + i) = i;
	}

	i = 0;
	for (; i < 4;i++){
		printf("位置%d的值是：%d\n", i, arr[i]);
	}

	// 位置0的值是：0
	// 位置1的值是：1
	// 位置2的值是：2
	// 位置3的值是：3
	getchar();

}*/

/*
// 数组指针操作的几种方式
void main(){
	int arr[] = {1,2,3,4};

	int* arr_p = arr;

	int i = 0;
	for (; i < 4;i++){
		// printf("位置%d的值是：%d\n" , i , *(arr+i));  // 由int* arr_p = arr;可知：arr=arr_p，所以直接打印 *(arr+i)表示值
		printf("位置%d的值是：%d\n", i, arr_p[i]); // == *(arr+i)
	}
	getchar();
}*/

/*
// 指针为什么要有类型？ 指针其实就是一块地址，而且它的值都差不多，
// 原因有2个：
// 1. 取值的时候，我要知道怎么取：4字节、8字节、16字节，就是debug方式，调试 - 窗口 - 内存 - 内存1，这样去查看；
// 2. 指针的偏移：指针移动时，如果是int类型指针，按照4字节移动；如果是double类型指针，按照8字节移动
void main(){
	int num = 12;

	int* num_p = &num;

	// double* num_p_d = num;

	printf("%p" , num_p);
	getchar();
	}*/


/*
// 函数指针，相当于 回调

// 两个数相加
void add(int num1 , int num2){
	printf("num1 + num2 = %d\n" , (num1+num2));  // num1 + num2 = 3
}

// 两个数相减
void mins(int num1, int num2){
	printf("num1 - num2 = %d", (num1 - num2));  // num1 - num2 = -1
}

// 参数1：方法指针（类似于java中的接口），两个数
void operate(void(method)(int,int) , int num1 , int num2){
	// method是自己定义的方法，就是上边的method
	method(num1, num2);
}


void main(){

	// 在这个Simple.cpp中可以直接用下边方式调用；
	add(1,2);  

	// 但是想要在另一个文件调用add方法，就不能这么调用了，其实另外一个文件也是可以调用这个方法的，需要把 函数指针传给另一个方法就可以

	// 方法指针的定义格式如下： 
	// 方法的返回值* (方法的名称)(方法的参数)
	// void* (add_p)(int, int);

	operate(add , 1 , 2);
	operate(mins, 1, 2);

	getchar();
	}*/

/*
// 监听数据压缩回调
void call_back(int current , int total){
	printf("压缩的进度是：%d/%d" , current , total);  // 12/24
}


// 压缩的方法，这里就相当于是另一个文件，我们需要在另一个文件中回调
// 参数1：压缩的文件名；参数2：回调方法，就是上边的call_back
void compress(char* file_name  ,void(callback)(int , int)){
	callback(12 , 24);
}

void main(){

	// 第一种写法：一般用这种方式
	// compress("1.png" , call_back);

	// 第二种写法：一般不会这样写

	// 声明一个函数指针
	void(*call)(int , int);
	// 给函数指针赋值
	call = call_back;

	// 通过函数指针间接的调用call_back，
	call(1 , 2);  // 压缩进度是：1/2
	getchar();
	}*/

// 方法指针使用场景（视频压缩回调）
void print(char* message){
	printf("打印内容：%s" , message);

}

// 把函数指针作为参数传递
void method(void(*prinf_m)(char*)){
	prinf_m("指针函数回调");  // 打印内容：指针函数回调
}

void main(){

	// print, &print：这两个打印结果一样，打印的都是 print方法的地址，所以下边直接用 print来接收方法指针
	// printf("%p , %p", print, &print);  // 00C411FE , 00C411FE

	// 用一个指针接收 printf方法
	// 下边就是一个方法指针：方法返回值(*方法名称)(参数)：方法名称随便定义，多个参数的话用 , 逗号隔开
	void(*prinf_m)(char*) = print;
	// void(*prinf_m)(char*) = &print;  这样也可以

	// 直接传递print就可以，因为传递的参数就需要指针
	method(print);
	getchar();
}