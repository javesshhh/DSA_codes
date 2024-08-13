#include<bits/stdc++.h>
using namespace std;

int main(){
// in boolean language, only 0 is considered as false, rest all numbers are considered as true( can be +ve or -ve

// to store a large integer value, we can use long int or long long int
// long long int a=123456;
// or
// long long b=1234567;

//increment decrement operator
// int x=5;
// x=x+1;
// cout<<x<<endl; // output 6
// cout<<x++<<endl; // output 6
// cout<<x<<endl; // output 7
// cout<<++x<<endl; // output 8

// ascii value
// char c='a';
// cout<<c<<endl;
// cout<<(int) c<<endl;  //output 97
 //here we used typecasting to typecast char type of c to int type
 // here (int) c will give ascii value of c containing 'a' and that is 97
// char d='c';
// cout<<c-d<<endl; // output 97-99 = -2
 // here we are operating a int operation on characters so operation will take their ascii value for calculation

 // for char we use '' where you can store only single character(a,b,c.... 1,2,3.... @#$%.... ) and for string we use "" where you can store combinations of characters

 // for line break, we use endl. We can also use "\n"
// cout<<c<<d<<endl;
// cout<<c<<d<<"\n";

// cin take input and consider a input value terminated only after a space or enter
// cin input in characters works in different way
cin>>c>>d;
// when we give input as: a b  , it will take c as a and d as b
// when we give input as: ab a , here also it will take c as a and d as b , bcoz char is a single character

//  calculation order depends on precedence level of datatypes
// double
// float
// long long
// long
// int
// character

// cout<<7/2<<endl; // output 3
// cout<<7/2.0<<endl; // output 3.5
// cout<<'c'+1<<endl; // output ascii value of c then plus 1 // output 100

// int a= 7/2.0;
// cout<<a<<endl; // output 3 bcoz calculation gives 3.5 but int datatype can store only integer that is 3 rest truncated

// double z=7/2;
// cout<<z<<endl; // output 3 bcoz calculations are done taking integers as type not double as values are integers, so z stores 3
// double z=7/2.0;
// cout<<z<<endl; // output 3.5

// learn operators precedence in c++

// ranges of mostly used datatypes
// -10^9 < int < 10^9
// -10^12 < long int < 10^12
// -10^18 < long long int < 10^18

// int mx= INT_MAX; // here mx stores largest int value accepted in c++
// int mn= INT_MIN; // here mn stores SMALLEST int value accepted in c++
 // can be used in various competitive questions

// long long int cc=1e17; // e is used to write 10 to power something // it works in programming languages

// variables declared inside scope can be used inside that scope only
// variables inside a scope( that is between curly bracket) can be used only within that curly brackets
// { int a, double d, char c....} these cannot be used outside curly brackets
// global variables
// variables declared outside main can be used anywhere in the code

/* break statement
it throws the execution out of the last loop
like for1{ for2{ break; }} break will throw execution out of inner loop(for2) then next itertion of outer loop(for1) will run
it break the flow of iteration of loop */

// continue statement
// it makes the code run again at the last loop
// like for1{ for2{ continue; }} continue will again make the loop run for inner loop(for2)
// it makes continue the flow of iteration of loop

//string
//strings are always written inside ""
//through cin you can input strings but it will take input till space or enter we get
// string str1="hello";
// string str2="world";
// string str=str1 + str2; // output helloworld
 // + directly concatinate two strings
 // you can also compare two strings through == operator
// if(str1==str2)
// cout<<"equal";
 // if we want to take complete line as single input, use getline
// string ss;
// getline(cin,ss); // here we can take whole sentence as input
// example i am javesh lodha from ece branch

// int t;
// cin >>t;
// cin.ignore(); // this helps to take cursor to next line for appropriate inputs
// while(t--){
//     string s;
//     getline(cin,s); // to use getline for test cases, cin.ignore is needed for every test case input
//     cout <<s<< endl; //otherwise the input of last test case will not be considered

// why you should use string pushback instead of concatination(+)
// push_back operation has complexity of O(1)
// while complexity of + depends on str.length
// that is complexity of pushback is less then concatination

// array
// range of order of size of array locally assigned is of order around 10^5
// range of order of size of array globally assigned should be 10^7 or less than this
// sometimes 10^8 also works but size limit is compiler dependent so try to avoid more than 10^7
// to declare array globally, that is outside main function
// const int n=1e7;
// int arr[n];

// common verdicts of cc coding sites
// compilation error-due to syntax error
// memory limit exceeded-due to excess memory used than allowed
// runtime error-segmentation fault-out of bound error- eg, not allowed or illegal index accessed
// memory that is accessed doesn't exceed
// tle - time limit exceeded

// arithmetic modulo M
// print arithmetic modulo M of the final answer
// (a+b)%M = ( a%M + b%M ) %M
// (a*b)%M = ( a%M * b%M ) %M
// (a-b)%M = ( a%M - b%M + M) %M
// (a/b)%M = ( a%M * b^-1 %M ) %M
// example
// Given a number N. Print its factorial.
// Constraints
// 1<=N<=100
// print answer module M
// where M=47
// A%M
// code
// int n;
// cin>>n;
// int M=47;
// long long fact=1;
// for(int i=2;i<=n;++i){
//      fact=(fact*i)%M;       // modulo is applied on each step
// }
// cout << fact;

// Sum of N over all the test cases will be less than or equal to 10^6
// whenever this line is written then we can ignore constraint test cases t while calculating complexity
// so O(t*q*n) will be equal to O(q*n)

}
