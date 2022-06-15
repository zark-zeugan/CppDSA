#include <iostream>
#include <vector>
#include <queue>
#include <map>

struct TreeNode
{	
	int val;
	int hd;
	TreeNode* right;
	TreeNode* left;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};

void print_map(std::map<int, int> const &m)
{
    for (auto const &pair: m) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}


void print_arr(std::vector<int> arr)
{
	for(int i=0; i < arr.size(); i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "" << std::endl; 
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

std::map<int,int> Top_View(TreeNode* root)
{

	std::queue<TreeNode*> q;
	root->hd = 0;
	q.push(root);
	std::map<int, int> map;

	while(!q.empty())
	{
		
		TreeNode* current = q.front();
		q.pop();		
		// Search if the node (key) already exists in the map.
		auto search = map.find(current->hd);
		// If it does not exist then add the value.
		if(search == map.end())
		{
			map[current->hd] = current->val;
		} 

		// Check the left and right nodes and update the height value. 
		if(current->left != nullptr)
		{
			current->left->hd = current->hd-1;
			q.push(current->left);
		}
		if(current->right != nullptr)
		{
			current->right->hd = current->hd+1;			
			q.push(current->right);
		}

	}
	return map;
}

std::map<int,int> Bottom_View(TreeNode* root)
{

	std::queue<TreeNode*> q;
	root->hd = 0;
	q.push(root);
	std::map<int, int> map;

	while(!q.empty())
	{
		
		TreeNode* current = q.front();
		q.pop();		
	
		map[current->hd] = current->val; 

		// Check the left and right nodes and update the height value. 
		if(current->left != nullptr)
		{
			current->left->hd = current->hd-1;
			q.push(current->left);
		}
		if(current->right != nullptr)
		{
			current->right->hd = current->hd+1;			
			q.push(current->right);
		}

	}
	return map;
}


std::vector<int> Level_order(TreeNode* root)
{
	std::queue<TreeNode*> q;
	q.push(root);
	std::vector<int> result;

	while(!q.empty())
	{
		TreeNode* current = q.front();
		q.pop();
		if(current)
		{
			result.push_back(current->val);
		}			

		if(current->left != nullptr)
		{
			q.push(current->left);
		}
		if(current->right != nullptr)
		{
			q.push(current->right);
		}
	} 
	return result;
} 


int main()
{
	int data[] = {10,20,30,40,60,90,100};
	int size = sizeof(data)/sizeof(data[0]); 
	TreeNode* root = completeBinary(data, root, 0, size);

	//std::vector<int> result = Level_order(root);
	std::map<int, int> result = Bottomx`_View(root);
	print_map(result);

	// print_arr(result);
	return 0;
}












