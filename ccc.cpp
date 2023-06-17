
#include <stdio.h>
# include <iostream>
using namespace std;

int main() {
long a, b;
int i = 0, r = 0, sum[20];
cout << "Enter the first binary number: ";

cin >> a;

cout << "Enter the second binary number: ";

cin >> b;

while (a != 0 || b != 0)
{
sum[i++] = (a % 10 + b % 10 + r) % 2;
r = (a % 10 + b % 10 + r) / 2;
a = a / 10;
b = b / 10;
}
if (r != 0)
sum[i++] = r;
--i;
cout << "The sum of the two binary numbers is: ";
while (i >= 0)
cout << sum[i--];
cout << ". ";

return 0;
}

// I need to use similar methods to allow for binary subtraction and multiplication. I tried the following code, but it did not work as planned. Adding an if statement (like in if c=1) causes the loop to continue several times, never giving the correct answer. Using the subtract formula individually, gives me the same result as addition. Could someone please help me fix this? Thanks

// #include <stdio.h>
// # include <iostream>
// using namespace std;

// int main() {
// long a, b;

// int c = 0;

// cout << "Enter the first binary number: ";

// cin >> a;

// cout << "Enter the second binary number: ";

// cin >> b;

// cout << "Which operation do you want to complete: Add=1, Subtract=2, Multiply=3: ";

// cin >> c;

// if (c = 1){
//     int i = 0, r = 0, sum[20];
// while (a != 0 || b != 0)
// {

// sum[i++] = (a % 10 + b % 10 + r) % 2;
// r = (a % 10 + b % 10 + r) / 2;
// a = a / 10;
// b = b / 10;
// }
// if (r != 0)
// sum[i++] = r;
// --i;
// cout << "The sum of the two binary numbers is: ";
// while (i >= 0)
// cout << sum[i--];
// cout << ". ";
// }

// if (c = 2) {
// while (a != 0 || b != 0)
// {
// int i = 0, r = 0, sub[20];
// sub[i++] = (a % 10 - b % 10 + r) % 2;
// r = (a % 10 - b % 10 + r) / 2;
// a = a / 10;
// b = b / 10;
// if (r != 0)
// sub[i++] = r;
// --i;
// cout << "The difference of the two binary numbers is: ";
// while (i >= 0)
// cout << sub[i--];
// cout << ". ";
// }
// if (c = 3) {
// while (a != 0 || b != 0)
// {
// int i = 0, r = 0, prod[20];
// prod[i++] = (a % 10 * b % 10 + r) % 2;
// r = (a % 10 * b % 10 + r) / 2;
// a = a / 10;
// b = b / 10;
// if (r != 0)
// prod[i++] = r;
// --i;
// cout << "The product of the two binary numbers is: ";
// while (i >= 0)
// cout << prod[i--];
// cout << ". ";
// }
// }
// }