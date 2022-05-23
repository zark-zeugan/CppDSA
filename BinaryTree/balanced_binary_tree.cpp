#include <iostream>

struct TreeNode
{
	int val; 
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int height(TreeNode* root,bool& ans)
{
    if(root == NULL)
    {
        return 0;
    }
    if(!root->left && !root->right)
    {
        return 1;
    }

    int left = height(root->left,ans);
    int right = height(root->right,ans);

    if(std::abs(left - right) > 1)
    {
       ans = false;         
    }

    return std::max(left ,right) + 1;
}


bool isBalanced(TreeNode* root)
{
    /*
        if null return 0 
        height = max(leftsub, rightsub) + 1
    */
    if(!root)
    {
        return true;
    }
    bool ans = true;
    height(root, ans);
    return ans;


}



TreeNode* completeBinary(int arr[], TreeNode* node, size_t pos, size_t arr_size)
{
	if(pos < arr_size)
	{
		node = new TreeNode(arr[pos]);
		node->left = completeBinary(arr, node->left, 2*pos+1, arr_size);
		node->right = completeBinary(arr, node->right, 2*pos+2, arr_size);
	}

	return node;
}

int main()
{
	int data[] = {1,0,2,0,3};
	int size = sizeof(data)/sizeof(data[0]);
	TreeNode* root = completeBinary(data, root, 0, size);
	std::cout << root->left->val << std::endl;

	std::cout << isBalanced(root) << std::endl; 

	return 0;

}