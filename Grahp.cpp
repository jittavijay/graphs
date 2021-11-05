//============================================================================
// Name        : ffffffffff.cpp
// Author      : Vijay
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;
class Graph {
private:
	vector<unordered_set<int> > m_graph;
public:

	Graph(int count) {
		m_graph.resize(count);
	}
	int addPair(int x, int y) {
		m_graph[y].insert(x);
		return 0;
	}

	int getSchedule(vector<int> &order) {
		vector<int> deg(m_graph.size(), 0);
		// compute degree
		// this could be calculated while adding the node to grahp
		for (auto neighbors : m_graph)
			for (int neigh : neighbors)
				deg[neigh]++;
		/// BFS - queue
		queue<int> q;

		for (unsigned int i = 0; i < m_graph.size(); i++)
			if (!deg[i])
				q.push(i);
		// reduce degree 
		for (unsigned int i = 0; i < m_graph.size(); i++) {
			if (q.empty()) {
				order.resize(0);
				return 0;
			}
			auto val = q.front();
			q.pop();
			order.push_back(val);
			for (int neigh : m_graph[val]) {
				if (!--deg[neigh])   // reduce the degree
					q.push(neigh);
			}
		}
		return 0;
	}

};

int main() {

	vector<int> order;
	Graph g(3);
	g.addPair(0, 1);
	g.addPair(0, 2);
	g.addPair(1, 2);
	g.getSchedule(order);

	for (auto item : order) {
		cout << item << " ";
	}
	cout << endl;
	return 0;
}
