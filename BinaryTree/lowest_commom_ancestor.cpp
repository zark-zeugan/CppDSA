#include <iostream>


struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {} 
};



TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	//std::cout << root->val << std::endl;
	if(root->val == p->val || root->val == q->val)
	{
		return root;
	}
	if(root->left == nullptr && root->right == nullptr)
	{
		return nullptr;
	}

	TreeNode* left = nullptr;
	TreeNode* right = nullptr;

	if(root->left)
	{
		left = lowestCommonAncestor(root->left, p, q);
	}
	if(root->right)
	{
		right = lowestCommonAncestor(root->right, p, q);
	}

	if(right == nullptr && left != nullptr)
	{
		return left;
	}
	else if(right != nullptr && left == nullptr)
	{
		return right;
	}

	else if(right != nullptr && left != nullptr)
	{
		return root;
	}
	return nullptr;
	
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
	int data[] = {6,2,8,0,4,7,9,0,0,3,5};
	TreeNode* p = new TreeNode(0);
	TreeNode*q = new TreeNode(9);
	int size = sizeof(data)/sizeof(data[0]); 
	TreeNode* root = completeBinary(data, root, 0, size);

	std::cout << lowestCommonAncestor(root,p,q)->val << std::endl;

	return 0;
}


