#include <iostream>
#include <vector>



struct TreeNode
{	
	int val;
	TreeNode* right;
	TreeNode* left;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};


void invert(TreeNode* node)
{


	if(!node)
	{
		return;
	}

	
	invert(node->left);

	invert(node->right);


	TreeNode* temp = node->right;
	node->right = node->left;
	node->left = temp;



}

TreeNode* invertTree(TreeNode* root) 
{
	if(!root)
	{
		return root;
	}
	invert(root);

	std::cout << root->left->val << std::endl;
	std::cout << root->right->val << std::endl;

	return root;

}

TreeNode* completeBinary(int arr[], TreeNode* node, size_t pos, size_t arr_size)
{
	if(pos < arr_size)
	{
		node = new TreeNode(arr[pos]);
		node->left = completeBinary(arr, node->left, 2*pos + 1, arr_size);
		node->right = completeBinary(arr, node->right, 2*pos + 2, arr_size);
	}
	return node;
}


int main()
{
	int data[] = {4,2,7,1,3,6,9};
	int size = sizeof(data)/sizeof(data[0]); 
	TreeNode* root = completeBinary(data, root, 0, size);

	invertTree(root);



	return 0;
}