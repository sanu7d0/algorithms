#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

class Node {
public:
    string name;
    vector<Node*> childs;

    Node(string name)
        : name(name)
    {
    }

    ~Node()
    {
        for (auto child : childs)
            if (child)
                delete child;
    }

    void AddChild(queue<string>& q)
    {
        if (q.empty())
            return;

        string node = q.front();
        q.pop();

        bool exist = false;
        for (auto c : childs) {
            if (c->name == node) {
                c->AddChild(q);
                exist = true;
                break;
            }
        }

        if (!exist) {
            Node* newChild = new Node(node);
            childs.push_back(newChild);
            newChild->AddChild(q);
        }
    }

    void SortAndPrint(stringstream& ss, int depth)
    {
        // name == "" -> root dir
        if (name != "") {
            ss << string(depth, ' ') << name << "\n";
        }

        if (childs.size() == 0)
            return;

        sort(childs.begin(), childs.end(), [&](Node* a, Node* b) -> bool {
            return a->name < b->name;
        });
        for (auto child : childs) {
            child->SortAndPrint(ss, depth + 1);
        }
    }
};

int main()
{
    fastio;

    int N;
    Node* root = new Node("");

    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; ++i) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        string temp;
        queue<string> q;
        while (getline(ss, temp, '\\'))
            q.push(temp);

        root->AddChild(q);
    }

    stringstream output;
    root->SortAndPrint(output, -1);
    cout << output.str();

    delete root;
}
