//Gets the height of the tree
int splayTree::height(struct Node* root)
{
	if (root == NULL)
		return 0;
	else
	{
		//Get height of each subtree
		int lheight = height(root->left);
		int rheight = height(root->right);
		if (lheight > rheight)
		{
			return(lheight + 1);
		}
		else
		{
			return(rheight + 1);
		}
	}
}

//Print function to print the splay tree in BFS method.
void splayTree::print()
{
	if (root == nullptr)
	{
		//Nothing to print if tree is empty
		return;
	}

	//Caluculate the height of the tree, and then print nodes on each level.
	int h = height(root);
	for (int i = 1; i <= h; i++)
	{
		printHelper.clear();
		printLevel(root, i);

		//Print the vector of all nodes on current level out
		for (unsigned int j = 0; j < printHelper.size() - 1; j++)
		{
			cout << printHelper[j] << " ";
		}
		cout << printHelper[printHelper.size() - 1] << endl;
	}
}

//Helper Function that puts all nodes on the current level into printHelper vector
void splayTree::printLevel(splayTree::Node* node, int level)
{
	if (node == NULL) return;
	if (level == 1)
	{
		printHelper.push_back(node->value);
	}
	else if (level > 1)
	{
		printLevel(node->left, level - 1);
		printLevel(node->right, level - 1);
	}
}