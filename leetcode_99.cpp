/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* tmp = nullptr;
        while(true){
            tmp = find_mis_node(root);
            if(tmp) break;
            if(root->left) recoverTree(root->left);
            if(root->right) recoverTree(root->right);
            break;
        }
        cout << tmp->val << endl;
        if(tmp){
            TreeNode* TT = root;
            TT = find_left(tmp->left,tmp->val);
            if(TT){
                cout << "before TT: " << TT->val << endl;
                cout << "before tmp: " << tmp->val << endl;
                swap(&tmp,&TT);
                cout << "after TT: " << TT->val << endl;
                cout << "after tmp: " << tmp->val << endl;
                cout << "root: " << root->val << endl;
                cout << "root left: " << root->left->val << endl;
                return;
            }
            TT = find_right(tmp->right,tmp->val);
            if(TT){
                swap(&tmp,&TT);
                cout << TT->val << endl;
                return;
            }
        }
    }

    TreeNode* find_mis_node(TreeNode* root){
        if(root->left){
            if(find_left(root->left,root->val)) return root;
        }
        if(root->right){
            if(find_right(root->right,root->val)) return root;
        }
        return nullptr;
    }


    TreeNode* find_left(TreeNode* left, int val){
        if(!left) return nullptr;
        if(left->val>val){
            return left;
        }
        if(left->left) find_left(left->left, val);
        if(left->right) find_right(left->right, val);

        return nullptr;
    }

    TreeNode* find_right(TreeNode* right, int val){
        if(!right) return nullptr;
        if(right->val<val){
            return right;
        }
        if(right->left) find_left(right->left, val);
        if(right->right) find_right(right->right, val);

        return nullptr;
    }
    void swap(TreeNode **a , TreeNode **b){
        TreeNode* temp = *a;
        *a = *b;
        *b = temp;
    }

};
