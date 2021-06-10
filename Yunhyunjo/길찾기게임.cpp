#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int grid[10000][10000];

struct Btree{
    int data;
    Btree *left = NULL, *right = NULL;
};

Btree *makeTree(vector<vector<int>> &nodeinfo, int start, int end){
    if(start > end) return NULL;
    int max = nodeinfo[start][1];
    int idx = start;
    for(int i = start + 1; i <= end; i++){
        if(max < nodeinfo[i][1]){
            idx = i;
            max = nodeinfo[i][1];
        }
    }
    Btree *tree = new Btree();
    tree->data = nodeinfo[idx][2];
    tree->left = makeTree(nodeinfo, start, idx-1);
    tree->right = makeTree(nodeinfo, idx+1, end);
    return tree;
}

void pre(Btree *tree, vector <int> &v){
    if(tree == NULL) {
        return;
    }
    v.push_back(tree->data);
    pre(tree->left,v);
    pre(tree->right,v);
}

void pos(Btree *tree, vector <int> &v){
    if(tree == NULL) {
        return;
    }
    pos(tree->left, v);
    pos(tree->right, v);
    v.push_back(tree->data);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    int num = 1;
    int mx = 0, my = 0;
    for(int i = 0; i < nodeinfo.size(); i++){
        nodeinfo[i].push_back(num++);
    }
    sort(nodeinfo.begin(), nodeinfo.end());
    Btree *tree = makeTree(nodeinfo, 0, nodeinfo.size()-1);
    vector <int> pr, po;
    pre(tree, pr);
    pos(tree, po);
    answer.push_back(pr);
    answer.push_back(po);
    return answer;
}