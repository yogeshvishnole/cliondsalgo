#include<iostream>
#include<vector>
#include<utility>

using namespace std;
typedef pair<pair<int, int>, bool> pa;

class Node {
public:
    int q;
    int nodeGold;
    int nodeGoldCost;
    vector<Node *> children;

    Node(int q, int nodeGold, int nodeGoldCost) :q{q}, nodeGold{nodeGold}, nodeGoldCost{nodeGoldCost} {}
};

void insertNode(Node *root, int parent, int q, int goldPresent, int goldCost) {
    if (root->q == parent) {
        Node *newNode = new Node(q, goldPresent, goldCost);
        root->children.push_back(newNode);
        return;
    } else {
        for (int i = 0; i < root->children.size(); i++) {
            insertNode(root->children[i], parent, q, goldPresent, goldCost);
        }
    }
}

pa minimumGoldCost(Node *root, int wi, int vertex) {
    int goldBought = 0;
    int cost = 0;
    while (wi != goldBought && root->nodeGold > 0) {
        goldBought++;
        cost += root->nodeGoldCost;
        root->nodeGold--;
    }
    int nextWi = wi - goldBought;
    vector<pa> childAns;
    for (int i = 0; i < root->children.size(); i++) {
        childAns.push_back(minimumGoldCost(root->children[i], nextWi, vertex));
    }
    if (childAns.empty()) {
        if (root->q == vertex) {
            return make_pair(make_pair(goldBought, cost), true);
        } else {
            return make_pair(make_pair(goldBought, cost), false);
        }
    } else {
        for (int i = 0; i < childAns.size(); i++) {
            if (childAns[i].second == true) {
                return make_pair(make_pair(goldBought + childAns[i].first.first, cost + childAns[i].first.second),
                                 true);
            }
        }
        return make_pair(make_pair(INT32_MAX,INT32_MAX),false);
    }
}

int main() {

    int qn;
    int gn;
    int cn;
    cin >> qn >> gn >> cn;
    int tempQn = qn;

    Node *root = new Node(0, gn, cn);

    while (qn--) {

        int queryType;
        cin >> queryType;

        if (queryType == 1) {
            int parent;
            int goldPresent;
            int goldCost;
            cin >> parent >> goldPresent >> goldCost;
            int nodeQ = tempQn - qn;
            insertNode(root, parent, nodeQ, goldPresent, goldCost);
            9;
        }

        if (queryType == 2) {
            int vertex;
            int wi;
            cin >> vertex >> wi;
            pa ans = minimumGoldCost(root, wi, vertex);
            cout << ans.first.first << " " << ans.first.second << endl;
        }

    }

}

