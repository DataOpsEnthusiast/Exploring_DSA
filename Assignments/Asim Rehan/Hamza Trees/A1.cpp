#include <iostream>
using namespace std;
class TreeNode{
	int data;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int d=0,TreeNode*l=0,TreeNode*r=0)
	{
	data=d;
	left=l;
	right=r;
	}
	
};
class Treelinklist{
	private:
		TreeNode*root;
	
		public:
			Treelinklist()
			{
				root=0;
			}
			
			InsertNode(int element)
			{
			TreeNode *newNode=new TreeNode(element);
			if(root==0){
				cout<<"First Node Created"<<endl;
				root=newNode;
			}
			else
			{
				TreeNode *parent;
				TreeNode *current=root;
				while(current!=0)
				{
				parent=current;
				if(element<current->data)
				{
					current=current->left;
					
				}	
				else
				{
					current=current->right;
				}
				}
			}
			
			}
				
			FindNode(int exixting){
			
			}
				
			DeleteNode(int existing){
			
			}
				
			InsertNode(int element){
			
			}
				
		void	Inorder()
		{
			
			}
				void	Preorder()
				{
			
			}
				void	Postorder()
				{
			
			}
			
};



int main(){
	
	
	
	return 0;
}
