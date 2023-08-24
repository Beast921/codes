#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* clone(Node* node, map<int, Node*>& nodes) {
    if(nodes.count(node->val))
        return nodes[node->val];
    Node* clnode = new Node(node->val);
    nodes.insert({node->val, clnode});
    for(Node* n: node->neighbors) {
        clnode->neighbors.push_back(clone(n, nodes));
    }
    return clnode;
}

Node* cloneGraph(Node* node) {
    if(!node) return node;
    map<int, Node*> nodes;
    return clone(node, nodes);
}

Node *buildGraph() {
    /*
        Note : All the edges are Undirected
        Given Graph:
        1--2
        | |
        4--3
    */
    Node *node1 = new Node();
    node1->val = 1;
    Node *node2 = new Node();
    node2->val = 2;
    Node *node3 = new Node();
    node3->val = 3;
    Node *node4 = new Node();
    node4->val = 4;
    vector<Node *> v;
    v.push_back(node2);
    v.push_back(node4);
    node1->neighbors = v;
    v.clear();
    v.push_back(node1);
    v.push_back(node3);
    node2->neighbors = v;
    v.clear();
    v.push_back(node2);
    v.push_back(node4);
    node3->neighbors = v;
    v.clear();
    v.push_back(node3);
    v.push_back(node1);
    node4->neighbors = v;
    return node1;
}
 
void bfs(Node *src) {
    map<Node*, bool> visit;
    queue<Node*> q;
    q.push(src);
    visit[src] = true;
    while (!q.empty())
    {
        Node *u = q.front();
        cout << "Value of Node " << u->val << "\n";
        cout << "Address of Node " <<u << "\n";
        q.pop();
        vector<Node *> v = u->neighbors;
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            if (!visit[v[i]])
            {
                visit[v[i]] = true;
                q.push(v[i]);
            }
        }
    }
    cout << endl;
}

int main() {
    Node *node = buildGraph();
    cout<<"Original graph\n";
    bfs(node);
    Node *clnode = cloneGraph(node);
    cout<<"After cloning:\n";
    bfs(clnode);
    return 0;}