#include<iostream>
#include "Array.h"
#include"assert.h"

double calculateAvg(Array arr)
{
	double avg = 0;
	if (arr.Size() == 0) return 0;

	for (int i = 0; i < arr.Size(); i++)
		avg += arr[i];
	avg /= arr.Size();
	return avg;
}
int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	Array arr_1(10,0);
	Array arr_2(10,0);
	cout << "Creating an array of random numbers: ";
	arr_1.RandArray(0, 100);
	arr_1.Print();
	cout << "Creating an array of random numbers in increasing order: ";
	arr_1.RandArrayIns(-50, 100);
	arr_1.Print();
	cout << "Creating an array of random numbers in descending order: ";
	arr_1.RandArrayDes(-50, 100);
	arr_1.Print();
	cout << endl;

	arr_2.RandArray(0, 100);
	cout << "Sharing the contents of masives:\narr_1: " << arr_1 << "arr_2: " << arr_2;
	arr_1.Swap(arr_2);
	cout << "Result:\narr_1: " << arr_1 << "arr_2: " << arr_2;
	cout << endl;

	int el = 50;
	cout << "Searching for the index of an element in an array:\nThe desired element: "<<el<<"\n";
	int index= arr_1.ISearch(el);
	if (index == -1) cout << "There are no occurrences\n";
	else cout<<"It's index: " << index;
	cout << endl;

	cout << "Sort the array arr_1: ";
	arr_1.Sort();
	cout << arr_1;
	cout << endl;

	el = 228; index = 5;
	cout << "Insert an element by index:\nelement - "<<el<<", index - "<<index<< endl;
	if (!arr_1.Insert(el, index)) cout<<"There is no such index\n";
	else cout << arr_1;
	cout << endl;
	el = 333; index = 20;
	cout << "Insert an element by index:\nelement - " << el << ", index - " << index << endl;
	if (!arr_1.Insert(el, index)) cout << "There is no such index\n";
	else cout << arr_1;
	cout << endl;

	index = 3;
	cout << "Delete an element on the index: " << index<<endl;
	if (!arr_1.DelbyIndex(index)) cout << "There is no such index\n";
	else cout << arr_1;
	cout << endl;

	el = 228;
	cout << "Delete an element by value: " << el << endl;
	if (!arr_1.DelElement(el)) cout << "There is no such element\n";
	else cout << arr_1;
	cout << endl;

	Array arr_3(8);
	arr_3[0] = 1; arr_3[1] = 2; arr_3[2] = 3; arr_3[3] = 2; arr_3[4] = 3; arr_3[5] = 1; arr_3[6] = 1; arr_3[7] = 3;
	cout << arr_3;
	el = 3;
	cout << "Deleting all elements with the value: "<<el<<endl;
	arr_3.DelElementAll(el);
	cout << arr_3;
	cout << endl;
	Array arr_4(20, 0);
	arr_4.RandArray(-50, 100);
	cout << arr_4 << "Search for the maximum/minimum element: "<<endl;
	int i_max = arr_4.IMax();
	if (i_max==-1) cout << "The array is empty" << endl;
	else cout << "Maximum element: " << arr_4[i_max] << endl;
	int i_min = arr_4.IMin();
	if (i_min==-1) cout << "The array is empty" << endl;
	else cout << "Minimum element: " << arr_4[i_min] << endl;
	cout << endl;

	cout << "Operators == and !=: \n";
	Array arr_5(10), arr_6(10), arr_7(10);
	arr_5.RandArray(-50, 100);
	arr_6 = arr_5;
	cout << "Array 1: " << arr_5 << "Array 2: " << arr_6 << "Array 3: " << arr_7 << "Array 4: " << arr_4;
	if (arr_5 == arr_6) cout << "Arry 1 == Array 2\n";
	else  cout << "Arry 1 != Array 2\n";
	if (arr_5 != arr_6) cout << "Arry 1 != Array 2\n";
	else  cout << "Arry 1 == Array 2\n";
	if (arr_5 == arr_7) cout << "Arry 1 == Array 3\n";
	else  cout << "Arry 1 != Array 2\n";
	if (arr_5 == arr_4) cout << "Arry 1 == Array 4\n";
	else  cout << "Arry 1 != Array 4\n";
	cout << endl;
	
	cout << "Operators + � +=: \n";
	cout<< arr_7<<" + 5 + 10: " << arr_7 + 5 + 10 << endl;
	arr_7 += 38;
	cout<<arr_7<<"+= 38: " << arr_7;
	return 0;

}