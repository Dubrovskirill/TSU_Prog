#include<iostream>
#include "BoolVector.h"
#include"assert.h"
int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	BoolVector bvec_1;
	cout << "bvec_1: "; bvec_1.Print();
	BoolVector bvec_2(19, 1);
	cout << "bvec_2: "; bvec_2.Print();
	cout << endl;

	BoolVector bvec_3 = "10111";
	cout << "bvec_3: "; bvec_3.Print();
	cout << endl;

	bvec_1.Swap(bvec_2);
	cout << "bvec_1: "; bvec_1.Print();
	cout << "bvec_2: "; bvec_2.Print();
	cout << endl;

	BoolVector bvec_4(bvec_3);
	cout << "bvec_4: "; bvec_4.Print();
	bvec_4.Inverse();
	cout << "bvec_4: "<<bvec_4; 
	cout << endl;

	cout << "bvec_1: ";
	for(int i=0;i<24;i++)
		cout << bvec_1[i];
	cout <<endl<< bvec_1;
	bvec_1.Inverse();
	cout << bvec_1;
	cout << endl;

	bvec_1 = "101110011101001111";
	cout << bvec_1<<"&\n";
	bvec_2 = "1100101001";
	cout << bvec_2<<"=\n";
	bvec_3 = bvec_1 & bvec_2;
	cout << bvec_3<<endl;
	bvec_1 &= bvec_2;
	cout << bvec_1;
	cout << endl;

	bvec_1 = "101110011101001111";
	cout << bvec_1 << "|\n";
	cout << bvec_2 << "=\n";
	bvec_3 = bvec_1 | bvec_2;
	cout << bvec_3 << endl;
	bvec_1 |= bvec_2;
	cout << bvec_1;
	cout << endl;
	return 0;
}
//1011101011111