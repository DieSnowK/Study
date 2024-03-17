#include <string>
#include "Graph.hpp"

void Test_Matrix_Graph()
{
	Matrix::Graph<char, int, INT_MAX, true> g("0123", 4);
	g.AddEdge('0', '1', 1);
	g.AddEdge('0', '3', 4);
	g.AddEdge('1', '3', 2);
	g.AddEdge('1', '2', 9);
	g.AddEdge('2', '3', 8);
	g.AddEdge('2', '1', 5);
	g.AddEdge('2', '0', 3);
	g.AddEdge('3', '2', 6);

	g.Print();
}

void Test_LinkTable_Graph()
{
	string a[] = { "����", "����", "����", "����" };
	LinkTable::Graph<string, int, true> g1(a, 4);
	g1.AddEdge("����", "����", 100);
	g1.AddEdge("����", "����", 200);
	g1.AddEdge("����", "����", 30);
	g1.Print();
}

void TestBDFS()
{
	string a[] = { "����", "����", "����", "����", "����" };
	Matrix::Graph<string, int> g1(a, sizeof(a) / sizeof(string));
	g1.AddEdge("����", "����", 100);
	g1.AddEdge("����", "����", 200);
	g1.AddEdge("����", "����", 30);
	g1.AddEdge("����", "����", 30);
	g1.Print();

	g1.BFS("����");
	//g1.DFS("����");
}


int main()
{
	//Test_LinkTable_Graph();
	TestBDFS();

	return 0;
}