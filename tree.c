/* @author: mrinal-pandey
 * Design, Develop and Implement a menu driven Program in C for the following operations
 * on Binary Search Tree(BST) of Integers
 * a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2
 * b. Traverse the BST in Inorder, Preorder and Postorder
 * c. Search the BST for a given element(KEY) and report the appropriate message
 * d. Delete an element(ELEM) from BST
 * e. Exit
 * */

#include<stdio.h>
#include<stdlib.h>

typedef struct tree{

	int data;
	struct tree *leftNode;
	struct tree *rightNode;

}treeNode;

treeNode* createNode()
{
	treeNode* temp=(treeNode*)malloc(sizeof(treeNode));
	temp->leftNode=NULL;
	temp->rightNode=NULL;
	return temp;
}

treeNode* createTree()
{
	int numberOfNodes,tempValue,i,insertionFlag;
	treeNode* rootNode;
	treeNode* newNode;
	treeNode* current;

	printf("\nEnter the number of nodes:");
	scanf("%d",&numberOfNodes);

	printf("\nEnter %d values\n",numberOfNodes);

	for(i=0;i<numberOfNodes;i++)
	{
		scanf("%d",&tempValue);

		newNode=createNode();
		newNode->data=tempValue;

		if(i==0)
		{
			rootNode=newNode;
		}
		else
		{
			current=rootNode;
			insertionFlag=0;

			do
			{
				while(tempValue>current->data)
				{
					if(current->rightNode==NULL)
					{
						current->rightNode=newNode;
						insertionFlag=1;
						break;
					}
					current=current->rightNode;
				}
	
				while(tempValue<current->data)
				{
					if(current->leftNode==NULL)
					{
						current->leftNode=newNode;
						insertionFlag=1;
						break;
					}
					current=current->leftNode;
				}

			}while(insertionFlag==0);
		}
	}

	return rootNode;
}

void inorder(treeNode* root)
{
	if(root!=NULL)
	{
		inorder(root->leftNode);
		printf("%d ",root->data);
		inorder(root->rightNode);
	}
}

void postorder(treeNode* root)
{
	if(root!=NULL)
	{
		postorder(root->leftNode);
		postorder(root->rightNode);
		printf("%d ",root->data);
	}
}

void preorder(treeNode* root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder(root->leftNode);
		preorder(root->rightNode);
	}
}

void searchAndDelete(treeNode* root, int deleteKey)
{
	treeNode* tempData;
	treeNode* tempDataParent;
	treeNode* findSmallest;
	treeNode* findSmallestParent;
	tempData=root;
	tempDataParent=root;
	int flag=0, returnFlag=0;

	while(tempData!=NULL)
	{
		if(deleteKey==tempData->data)
		{
			flag=1;
			break;
		}
		else if(deleteKey>tempData->data)
		{
			tempDataParent=tempData;
			tempData=tempData->rightNode;
		}
		else
		{
			tempDataParent=tempData;
			tempData=tempData->leftNode;
		}
	}

	if(flag)
	{
		if(tempData->rightNode==NULL&&tempData->leftNode==NULL)
		{
			if(tempDataParent->rightNode==tempData)
			{
				tempDataParent->rightNode=NULL;
			}
			else
			{
				tempDataParent->leftNode=NULL;
			}
		}
		else if(tempData->rightNode==NULL&&tempData->leftNode!=NULL)
		{
			if(tempDataParent->leftNode==tempData)
			{
				tempDataParent->leftNode=tempData->leftNode;
			}
			else
			{
				tempDataParent->rightNode=tempData->leftNode;
			}
		}
		else if(tempData->rightNode!=NULL&&tempData->leftNode==NULL)
		{
			if(tempDataParent->leftNode==tempData)
			{
				tempDataParent->leftNode=tempData->rightNode;
			}
			else
			{
				tempDataParent->rightNode=tempData->rightNode;
			}
		}
		else if(tempData->leftNode!=NULL&&tempData->rightNode!=NULL)
		{
			findSmallest=tempData->rightNode;
			findSmallestParent=tempData;

			while(findSmallest->leftNode!=NULL)
			{
				findSmallestParent=findSmallest;
				findSmallest=findSmallest->leftNode;
			}

			tempData->data=findSmallest->data;
			
			if(findSmallestParent!=tempData)
			{
				findSmallestParent->leftNode=findSmallest->rightNode;
			}
			else
			{
				findSmallestParent->rightNode=findSmallest->rightNode;
			}
		}
	}
	else
	{
		printf("\n\nData not found\n\n");
	}
}

int search(treeNode* root, int key)
{
	if(root!=NULL)
	{
		if(key==root->data)
		{
			return 1;
		}
		else if(key>root->data)
		{
			search(root->rightNode, key);
		}
		else
		{
			search(root->leftNode, key);
		}
	}
	else
	{
		return 0;
	}
}

int main()
{
	int choice, searchKey, deleteKey, searchResult=0;
	treeNode* rootNode;

	while(1)
	{
		printf("1.Create Tree\n2.Inorder\n3.Preorder\n4.Postorder\n5.Search\n6.Delete\nEnter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				rootNode=createTree();
				break;
			case 2:
				printf("\n\n");
				inorder(rootNode);
				printf("\n\n");
				break;
			case 3:
				printf("\n\n");
				preorder(rootNode);
				printf("\n\n");
				break;
			case 4:
				printf("\n\n");
				postorder(rootNode);
				printf("\n\n");
				break;
			case 5:
				printf("\nEnter key to search:");
				scanf("%d",&searchKey);
				searchResult=search(rootNode,searchKey);
				if(searchResult)
				{
					printf("\nElement found\n\n");
				}
				else
				{
					printf("\nElement not Found\n\n");
				}
				break;
			case 6:
				printf("\nEnter key to delete:\n");
				scanf("%d",&deleteKey);
				searchAndDelete(rootNode, deleteKey);
				break;
		}
	}
	return 0;
}
