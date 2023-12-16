#include<iostream>
#include <random>
#include <fstream>
#include<vector>
#include "../../../OOP/OOP_LAB_4_(�lass of boolean matrix)/BoolMatrix/BoolMatrix.h"
#include "../../../OOP/OOP_LAB_5_(�lass list)/OOP_LAB_5_(�lass list)/List.h"
#include "../../../OOP/OOP_LAB_2/OOP_LAB_2/Array.h"

void RandMatr(BoolMatrix& matrix)
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> dist(0, 1);
	for (int i = 0; i < matrix.Rows(); i++) 
		for (int j = 0; j < matrix.Cols(); j++) 
			matrix[i][j] = dist(rng);
}
BoolMatrix Form(std::string name)
{
	std::ifstream inputFile(name);
	std::string st;
	if (inputFile.is_open())
	{
		char num;
		while (inputFile >> num)
			if (num != ',' && num != ' ')
				st.push_back(num);
	}
	else std::cout << "File opening error!\n";
	/*for (int i = 0; i < st.size(); i++)
		std::cout << st[i];*/
	return BoolMatrix(st);
}

void FormVector(std::vector<int>& vec, const int  n)
{
	int ed;
	std::cin >> ed;
	if (ed > n || ed == 0)
	{
		std::cout << "The entered value is incorrect: exceeding the number of verinches.\n Try again:";
		FormVector(vec, n);
		return;
	}
	if (ed < 0)
		return;
	vec.push_back(ed);
	FormVector(vec, n);
}
bool �heck(const Array<int>& arr)
{
	for (int i = arr.Size()-1; i >= 0; --i)
	{
		if (!arr[i])
			return false;
	}
	return true;
}

Array<int> TSortMatr(BoolMatrix matrix)
{
	int n = matrix.Rows();
	Array<int> answer(n, 0);
	BoolVector exp(n, 0);
	int k = 0;
	while (!exp.Full())
	{
		BoolVector mask(n, 0);
		for (int i = 0; i < n; i++)
		{
			mask |= matrix[i];
			if (exp[i])
				mask[i] = exp[i];
		}
		if (mask.Full())
		{
			return answer;
		}
		mask = ~mask;
		
		for (int i = 0; i < n; i++)
			if (mask[i])
				exp[i] = mask[i];
		BoolVector mask2(n, 1);

		for (int i = 0; i < n; i++)
			if ((mask[i] & mask2[i]) == 1)
			{
				answer[k++] = i + 1;
				mask2 >>= 1;
			}
		for (int j = 0; j < n; j++)
			for (int i = 0; i < k; i++)
				matrix[answer[i] - 1][j] = 0;
	}

	return answer;
}
int main()
{
	
	std::cout << "Enter the number of vertices of the graph: ";
	int n;
	std::cin >> n;
	BoolMatrix Test(n, n, 0);
	std::cout << "Enter the edges of the graph: ";
	std::vector<int> edges;
	FormVector(edges, n);
	
	for (int k = 0; k < edges.size() - 2; k+=2)
	{
		Test[edges[k]-1][edges[k + 1]-1]=~Test[edges[k]][edges[k + 1]];
	}
	Test.Print();


	/*BoolMatrix Test(Form("../../../../matrix.txt"));
	Test.Print();
	std::cout << "\n";*/
	Array<int> answer(TSortMatr(Test));
	if (!�heck(answer))
		std::cout << "!!!CYCLE!!!" << std::endl;
	else 
	{
		std::cout << "Sorted vertices: ";
		for (int i = 0; i < Test.Rows(); i++)
			std::cout << answer[i] << " ";
	}
}