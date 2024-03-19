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
	string a[] = { "张三", "李四", "王五", "赵六" };
	LinkTable::Graph<string, int, true> g1(a, 4);
	g1.AddEdge("张三", "李四", 100);
	g1.AddEdge("张三", "王五", 200);
	g1.AddEdge("王五", "赵六", 30);
	g1.Print();
}

void TestBDFS()
{
	string a[] = { "张三", "李四", "王五", "赵六", "周七" };
	Matrix::Graph<string, int> g1(a, sizeof(a) / sizeof(string));
	g1.AddEdge("张三", "李四", 100);
	g1.AddEdge("张三", "王五", 200);
	g1.AddEdge("王五", "赵六", 30);
	g1.AddEdge("王五", "周七", 30);
	g1.Print();
	cout << endl;

	g1.BFS("张三");
	//g1.DFS("张三");
}

void TestGraphMinTree()
{
	const char str[] = "abcdefghi";
	Matrix::Graph<char, int> g(str, strlen(str));
	g.AddEdge('a', 'b', 4);
	g.AddEdge('a', 'h', 8);
	//g.AddEdge('a', 'h', 9);
	g.AddEdge('b', 'c', 8);
	g.AddEdge('b', 'h', 11);
	g.AddEdge('c', 'i', 2);
	g.AddEdge('c', 'f', 4);
	g.AddEdge('c', 'd', 7);
	g.AddEdge('d', 'f', 14);
	g.AddEdge('d', 'e', 9);
	g.AddEdge('e', 'f', 10);
	g.AddEdge('f', 'g', 2);
	g.AddEdge('g', 'h', 1);
	g.AddEdge('g', 'i', 6);
	g.AddEdge('h', 'i', 7);

	//Matrix::Graph<char, int> kminTree;
	//cout << "Kruskal:" << g.Kruskal(kminTree) << endl;
	//kminTree.Print();
	//cout << endl << endl;

	Matrix::Graph<char, int> pminTree;
	cout << "Prim:" << g.Prim(pminTree, 'a') << endl;
	pminTree.Print();
	cout << endl;

	//for (size_t i = 0; i < strlen(str); ++i)
	//{
	//	cout << "Prim:" << g.Prim(pminTree, str[i]) << endl;
	//}
}

void TestGraphDijkstra()
{
	const char* str = "syztx";
	Matrix::Graph<char, int, INT_MAX, true> g(str, strlen(str));
	g.AddEdge('s', 't', 10);
	g.AddEdge('s', 'y', 5);
	g.AddEdge('y', 't', 3);
	g.AddEdge('y', 'x', 9);
	g.AddEdge('y', 'z', 2);
	g.AddEdge('z', 's', 7);
	g.AddEdge('z', 'x', 6);
	g.AddEdge('t', 'y', 2);
	g.AddEdge('t', 'x', 1);
	g.AddEdge('x', 'z', 4);

	vector<int> dist;
	vector<int> parentPath;
	g.Dijkstra('s', dist, parentPath);
	g.PrintShortPath('s', dist, parentPath);

	// 图中带有负权路径时，贪心策略则失效了。
	// 测试结果可以看到s->t->y之间的最短路径没更新出来
	//const char* str = "sytx";
	//Matrix::Graph<char, int, INT_MAX, true> g(str, strlen(str));
	//g.AddEdge('s', 't', 10);
	//g.AddEdge('s', 'y', 5);
	//g.AddEdge('t', 'y', -7);
	//g.AddEdge('y', 'x', 3);
	//vector<int> dist;
	//vector<int> parentPath;
	//g.Dijkstra('s', dist, parentPath);
	//g.PrintShortPath('s', dist, parentPath);
}

void TestGraphBellmanFord()
{
		const char* str = "syztx";
		Matrix::Graph<char, int, INT_MAX, true> g(str, strlen(str));
		g.AddEdge('s', 't', 6);
		g.AddEdge('s', 'y', 7);
		g.AddEdge('y', 'z', 9);
		g.AddEdge('y', 'x', -3);
		g.AddEdge('z', 's', 2);
		g.AddEdge('z', 'x', 7);
		g.AddEdge('t', 'x', 5);
		g.AddEdge('t', 'y', 8);
		g.AddEdge('t', 'z', -4);
		g.AddEdge('x', 't', -2);
		vector<int> dist;
		vector<int> parentPath;
		g.BellmanFord('s', dist, parentPath);
		g.PrintShortPath('s', dist, parentPath);

	//const char* str = "syztx";
	//Matrix::Graph<char, int, INT_MAX, true> g(str, strlen(str));
	//g.AddEdge('s', 't', 6);
	//g.AddEdge('s', 'y', 7);
	//g.AddEdge('y', 'z', 9);
	//g.AddEdge('y', 'x', -3);
	////g.AddEdge('y', 's', 1); // 新增
	//g.AddEdge('z', 's', 2);
	//g.AddEdge('z', 'x', 7);
	//g.AddEdge('t', 'x', 5);
	////g.AddEdge('t', 'y', -8); //更改
	//g.AddEdge('t', 'y', 8);

	//g.AddEdge('t', 'z', -4);
	//g.AddEdge('x', 't', -2);
	//vector<int> dist;
	//vector<int> parentPath;
	//if (g.BellmanFord('s', dist, parentPath))
	//	g.PrintShortPath('s', dist, parentPath);
	//else
	//	cout << "带负权回路" << endl;
}

void TestFloydWarShall()
{
	const char* str = "12345";
	Matrix::Graph<char, int, INT_MAX, true> g(str, strlen(str));
	g.AddEdge('1', '2', 3);
	g.AddEdge('1', '3', 8);
	g.AddEdge('1', '5', -4);
	g.AddEdge('2', '4', 1);
	g.AddEdge('2', '5', 7);
	g.AddEdge('3', '2', 4);
	g.AddEdge('4', '1', 2);
	g.AddEdge('4', '3', -5);
	g.AddEdge('5', '4', 6);
	vector<vector<int>> vvDist;
	vector<vector<int>> vvParentPath;
	g.FloydWarshall(vvDist, vvParentPath);

	// 打印任意两点之间的最短路径
	for (size_t i = 0; i < strlen(str); ++i)
	{
		g.PrintShortPath(str[i], vvDist[i], vvParentPath[i]);
		cout << endl;
	}
}

int main()
{
	//Test_LinkTable_Graph();
	//TestBDFS();
	//TestGraphMinTree();
	//TestGraphDijkstra();
	//TestGraphBellmanFord();
	//TestFloydWarShall();

	return 0;
}