#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <functional>
#include <stdexcept>
#include "UnionFindSet.hpp"
using namespace std;

namespace Matrix
{
    // V -> vertex  W -> weight
    template<class V, class W, W MAX_W = INT_MAX, bool Direction = false>
    class Graph
    {
        typedef Graph<V, W, MAX_W, Direction> Self;
    public:
        Graph() = default;

        Graph(const V* arr, size_t n)
        {
            _vertexs.resize(n);
            for (size_t i = 0; i < n; i++)
            {
                _vertexs[i] = arr[i];
                _indexMap[arr[i]] = i;
            }

            _matrix.resize(n);
            for (size_t i = 0; i < _matrix.size(); i++)
            {
                _matrix[i].resize(n, MAX_W);
            }
        }

        size_t GetVertexIndex(const V& v)
        {
            auto it = _indexMap.find(v);
            if (it != _indexMap.end())
            {
                return it->second;
            }
            else
            {
                throw invalid_argument("Vertex isn't exist");
                return -1;
            }
        }

        // 可以考虑函数重载(No)
        // 但是如果V本身是int类型，可能会出问题，所以抽离出来一个子函数
        void _AddEdge(size_t srci, size_t dsti, const W& w)
        {
            _matrix[srci][dsti] = w;

            // 无向图
            if (Direction == false)
            {
                _matrix[dsti][srci] = w;
            }
        }

        void AddEdge(const V& src, const V& dst, const W& w)
        {
            size_t srci = GetVertexIndex(src);
            size_t dsti = GetVertexIndex(dst);
            _AddEdge(srci, dsti, w);
        }

        void BFS(const V& src)
        {
            size_t srci = GetVertexIndex(src);

            queue<int> q;
            vector<bool> visited(_vertexs.size(), false); // 标记数组

            q.push(srci);
            visited[srci] = true;
            int levelSize = 1; // 控制每层出的数量

            while (!q.empty())
            {
                // 一层一层出
                for (size_t i = 0; i < levelSize; i++)
                {
                    int front = q.front();
                    q.pop();
                    cout << front << ":" << _vertexs[front] << " ";

                    // 把front的邻接顶点入队列
                    for (size_t j = 0; j < _vertexs.size(); j++)
                    {
                        if (_matrix[front][j] != MAX_W && visited[j] == false)
                        {
                            q.push(j);
                            visited[j] = true;
                        }
                    }
                }
                cout << endl;

                levelSize = q.size();
            }
        }

        void _DFS(size_t srci, vector<bool>& visited)
        {
            cout << srci << ":" << _vertexs[srci] << endl;
            visited[srci] = true;

            for (size_t i = 0; i < _vertexs.size(); i++)
            {
                if (_matrix[i] != MAX_W && visited[i] == false)
                {
                    _DFS(i, visited);
                }
            }
        }

        void DFS(const V& src)
        {
            size_t srci = GetVertexIndex(src);
            vector<bool> visited(_vertexs.size(), false);
            _DFS(srci, visited);

            // 处理存在不连通的情况
            for (size_t i = 0; i < _vertexs.size(); i++)
            {
                if (!visited[i])
                {
                    _DFS(i, visited);
                }
            }
        }

        struct Edge
        {
            Edge(size_t srci, size_t dsti, W w)
                : _srci(srci)
                , _dsti(dsti)
                , _w(w)
            {}

            bool operator>(const Edge& e) const
            {
                return _w > e._w;
            }

            size_t _srci;
            size_t _dsti;
            W _w;
        };

        W Kruskal(Self& minTree)
        {
            size_t n = _vertexs.size();

            // 初始化minTree
            minTree._vertexs = _vertexs;
            minTree._indexMap = _indexMap;
            minTree._matrix.resize(n);
            for (size_t i = 0; i < n; i++)
            {
                minTree._matrix[i].resize(n, MAX_W);
            }

            priority_queue<Edge, vector<Edge>, greater<Edge>> minQueue;

            // 建堆排序
            for (size_t i = 0; i < n; i++)
            {
                for (size_t j = 0; j < n; j++)
                {
                    if (i < j && _matrix[i][j] != MAX_W)
                    {
                        minQueue.push(Edge(i, j, _matrix[i][j]));
                    }
                }
            }

            // 选出n-1条边
            size_t size = 0;
            W totalW = W();
            UnionFindSet ufs(n);
            while (!minQueue.empty())
            {
                Edge min = minQueue.top();
                minQueue.pop();

                // 判环 -> 并查集
                if (!ufs.InSameSet(min._srci, min._dsti))
                {
                    cout << _vertexs[min._srci] << "->" << _vertexs[min._dsti] << ":" << min._w << endl;
                    
                    minTree._AddEdge(min._srci, min._dsti, min._w);
                    ufs.Union(min._srci, min._dsti); // 入集
                    
                    size++;
                    totalW += min._w;
                }
                else
                {
                    cout << "Forming Ring: ";
                    cout << _vertexs[min._srci] << "->" << _vertexs[min._dsti] << ":" << min._w << endl;
                }
            }

            if (size == n - 1)
            {
                return totalW;
            }
            else
            {
                return W();
            }
        } // end of Kruskal

        W Prim(Self& minTree, const W& src)
        {
            size_t srci = GetVertexIndex(src);
            size_t n = _vertexs.size();

            // 初始化minTree
            minTree._vertexs = _vertexs;
            minTree._indexMap = _indexMap;
            minTree._matrix.resize(n);
            for (size_t i = 0; i < n; i++)
            {
                minTree._matrix[i].resize(n, MAX_W);
            }

            // true & false表示该元素是否在该集合内
            vector<bool> X(n, false);
            vector<bool> Y(n, true);
            X[srci] = true;
            Y[srci] = false;

            // 从X->Y集合中连接的边里面选出最小的边
            priority_queue<Edge, vector<Edge>, greater<Edge>> minQueue;

            // 先把srci连接的边添加到队列中
            for (size_t i = 0; i < n; i++)
            {
                if (_matrix[srci][i] != MAX_W)
                {
                    minQueue.push(Edge(srci, i, _matrix[srci][i]));
                }
            }

            size_t size = 0;
            W totalW = W();
            while (!minQueue.empty())
            {
                Edge min = minQueue.top();
                minQueue.pop();

                // 最小边的目标也在X集合，则构成环
                if (X[min._dsti])
                {
                    cout << "Forming Ring:";
                    cout << _vertexs[min._srci] << "->" << _vertexs[min._dsti] << ":" << min._w << endl;
                }
                else
                {
                    cout << _vertexs[min._srci] << "->" << _vertexs[min._dsti] << ":" << min._w << endl;

                    minTree._AddEdge(min._srci, min._dsti, min._w);
                    X[min._dsti] = true;
                    Y[min._dsti] = false;

                    size++;
                    totalW += min._w;

                    // 可能最小生成树已经生成，但是多了很多成环边，无须继续遍历
                    if (size == n - 1)
                    {
                        break;
                    }

                    // 将目标顶点连接的边加入到队列中
                    for (size_t i = 0; i < n; i++)
                    {
                        if (_matrix[min._dsti][i] != MAX_W && Y[i])
                        {
                            minQueue.push(Edge(min._dsti, i, _matrix[min._dsti][i]));
                        }
                    }
                }
            }

            // 实际不一定存在最小生成树
            if (size == n - 1)
            {
                return totalW;
            }
            else
            {
                return W();
            }
        } // end of Prim

        void Print()
        {
            // 顶点
            for (size_t i = 0; i < _vertexs.size(); i++)
            {
                cout << "[" << i << "]" << "->" << _vertexs[i] << endl;
            }
            cout << endl;

            // 矩阵
            // 横下标
            cout << "  ";
            for (size_t i = 0; i < _matrix.size(); i++)
            {
                //cout << i << " ";
                printf("%4d", i);
            }
            cout << endl;

            for (size_t i = 0; i < _matrix.size(); i++)
            {
                cout << i << " "; // 竖下标
                for (size_t j = 0; j < _matrix[i].size(); j++)
                {
                    if (_matrix[i][j] == MAX_W)
                    {
                        //cout << "* ";
                        printf("%4c", '*');
                    }
                    else
                    {
                        //cout << _matrix[i][j] << " ";
                        printf("%4d", _matrix[i][j]);
                    }
                }
                cout << endl;
            }
        }
    private:
        vector<V> _vertexs;        // 顶点集合
        map<V, int> _indexMap;     // 顶点映射下标
        vector<vector<W>> _matrix; // 邻接矩阵
    };
}


namespace LinkTable
{
    template<class W>
    struct Edge
    {
        Edge(int dsti, const W& w)
            : _dsti(dsti)
            , _w(w)
        {}

        int _dsti; // 目标点下标
        W _w;      // 权值
        Edge* _next;
    };

    // V -> vertex  W -> weight
    template<class V, class W, bool Direction = false>
    class Graph
    {
        typedef Edge<W> Edge;
    public:
        Graph(const V* arr, size_t n)
        {
            _vertexs.resize(n);
            for (size_t i = 0; i < n; i++)
            {
                _vertexs[i] = arr[i];
                _indexMap[arr[i]] = i;
            }

            _tables.resize(n, nullptr);
        }
        
        size_t GetVertexIndex(const V& v)
        {
            auto it = _indexMap.find(v);
            if (it != _indexMap.end())
            {
                return it->second;
            }
            else
            {
                throw invalid_argument("Vertex isn't exist");
                return -1;
            }
        }

        void AddEdge(const V& src, const V& dst, const W& w)
        {
            size_t srci = GetVertexIndex(src);
            size_t dsti = GetVertexIndex(dst);

            Edge* eg = new Edge(dsti, w);
            eg->_next = _tables[srci]; // 头插
            _tables[srci] = eg;

            // 无向图
            if (Direction == false)
            {
                Edge* eg = new Edge(srci, w);
                eg->_next = _tables[dsti]; // 头插
                _tables[dsti] = eg;
            }
        }

        void Print()
        {
            // 顶点
            for (size_t i = 0; i < _vertexs.size(); i++)
            {
                cout << "[" << i << "]" << "->" << _vertexs[i] << endl;
            }
            cout << endl;

            for (size_t i = 0; i < _tables.size(); i++)
            {
                cout << _vertexs[i] << "[" << i << "]->";
                Edge* cur = _tables[i];
                while (cur)
                {
                    cout << "[" << _vertexs[cur->_dsti] << ":" << cur->_dsti << ":" << cur->_w << "]->";
                    cur = cur->_next;
                }
                cout << "nullptr" << endl;
            }
        }
    private:
        vector<V> _vertexs;        // 顶点集合
        map<V, int> _indexMap;     // 顶点映射下标
        vector<Edge*> _tables;     // 邻接表
    };
}