#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <stdexcept>
using namespace std;

namespace Matrix
{
    // V -> vertex  W -> weight
    template<class V, class W, W MAX_W = INT_MAX, bool Direction = false>
    class Graph
    {
    public:
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

        void AddEdge(const V& src, const V& dst, const W& w)
        {
            size_t srci = GetVertexIndex(src);
            size_t dsti = GetVertexIndex(dst);

            _matrix[srci][dsti] = w;

            // 无向图
            if (Direction == false)
            {
                _matrix[dsti][srci] = w;
            }
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