
//  * Definition for a binary tree node.
 
 #include <queue>
 using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
TreeNode *root;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        //判断空
        if(root ==NULL)
            return{};
        //返回答案
        vector<vector<int>> ans;
        vector<int> res;

        //两个队列
        queue<TreeNode*> q1,q2;
        q1.push(root);
        while(!q1.empty()||!q2.empty())
        {
            //q1不为空 子节点进入q2
            if(!q1.empty())
            {
                while(!q1.empty())
                {
                    auto c = q1.front();
                    q1.pop();
                    res.push_back(c->val);
                    if(c->left!=NULL)
                        q2.push(c->left);
                    if(c->right!=NULL)
                        q2.push(c->right);
                }

                ans.push_back(res);
                res.clear();
            }

            //q2不为空 子节点进入q1
            if(!q2.empty())
            {
                while(!q2.empty())
                {
                    auto c = q2.front();
                    q2.pop();
                    res.push_back(c->val);
                    if(c->left!=NULL)
                        q1.push(c->left);
                    if(c->right!=NULL)
                        q1.push(c->right);
                }

                ans.push_back(res);
                res.clear();
            }

        }

        return ans;
    }
};
