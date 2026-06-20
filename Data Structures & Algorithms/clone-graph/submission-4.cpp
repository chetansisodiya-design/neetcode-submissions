/*
// Definition for a Node.
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
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> oldToNew;
        
        return dfs(node, oldToNew);
    }

    Node* dfs(Node* node, map<Node*, Node*>& oldToNew) {
        if(node == nullptr) {
            return nullptr;
        }

        // check if node already exist so dont create
        if(oldToNew.count(node)) {
            return oldToNew[node];
        }

        Node* copy = new Node(node->val);
        oldToNew[node] = copy;
        
        // Traver original node Neighbours./ create same for clone too
        for(Node* nei: node->neighbors) {
            // we should not push nei.. we need to create a new one
            // against nei.. So use dfs function 
            copy->neighbors.push_back(dfs(nei, oldToNew));
        }
        // return copy so that it can be used in one
        //above call for linking
        return copy;
    }
};
