#include<stdio.h>
#include<setjmp.h>
#include<signal.h>
#include<iostream>
using namespace std;
#include<string>

void Reverse(string str, int start,int end){
	
	while (start<end){
		str.at(start) ^= str.at(end);
		str.at(end) ^= str.at(start);
		str.at(start) ^= str.at(end);
		start++;
		end--;
	}
}



string LeftRotateString(string str, int n) {
	if (NULL == str.c_str() || str.size() <= 0 || n < 0)
		return NULL;
	n %= str.size();
	Reverse(str, 0, n - 1);
	Reverse(str, n, str.size() - 1);
	Reverse(str, 0, str.size() - 1);
}


//string replaceSpace(string iniString, int length) {
//	// write code here
//	int count = 0;
//	int new_len = 0;
//	int Old = length - 1;
//	int New = 0;
//	//遍历字符串，计算空格数
//	for (int i = 0; i < length; i++){
//		if (iniString[i] == ' ')
//			count++;
//	}
//
//	new_len = length + 2 * count;
//	New = new_len - 1;
//	while (New>Old){
//		if (iniString.at(Old) == ' '){
//			iniString.at(New--) = 'd';
//			iniString.at(New--) = '2';
//			iniString.at(New--) = '%';
//			Old--;
//		}
//		iniString.resize(new_len, ' ');
//		iniString.at(New--) = iniString.at(Old--);
//	}
//	return iniString;
//}


int main(){
	string s = { "Mr John Smith" };
	string s2;
	int len = 13;
	s2=replaceSpace(s, len);
	return 0;
}
//
//void Test1()
//{
//	try
//	{
//		char* p = new char[0x7fffffff];  //抛出异常
//	}
//	catch (exception e)
//	{
//		cout << e.what() << endl;   //捕获异常，然后程序结束
//	}
//
//}
//int main()
//{
//	Test1();
//	system("pause");
//	return 0;
//}

//jmp_buf buf;
//
//void funtest1(){
//	longjmp(buf, 1);
//}
//
//void funtest2(){
//	longjmp(buf, 2);
//}
//
//void funtest3(){
//	longjmp(buf, 3);
//}
//
//int main(){
//	int state = setjmp(buf);
//	if (0 == state){
//		funtest1();
//		funtest2();
//		funtest3();
//	}
//	else{
//		switch (state)
//		{
//		case 1:
//			cout << "funtest1 error" << endl;
//			break;
//		case 2:
//			cout << "funtest2 error" << endl;
//			break;
//		case 3:
//			cout << "funtest3 error" << endl;
//			break;
//		default:
//			break;
//		}
//	}
//	cout << "main end" << endl;
//	return 0;
//}

//void handler(int s){
//	//没有到达
//	if (s == SIGINT)
//		printf("now got a SIGINT signal\n");
//	longjmp(buf, 1);
//}
//
//int main(){
//	signal(SIGINT, handler);
//	if (setjmp(buf)){
//		printf("back in main\n");
//		return 0;
//	}
//	else{
//		printf("first time through\n");
//	}
//loop:
//	//在这里循环，等待ctrl-C
//	goto loop;
//}
