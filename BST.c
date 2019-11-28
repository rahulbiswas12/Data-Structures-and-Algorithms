#include<stdio.h>
#include<stdlib.h>
 struct BST{
	int info;
	struct BST *left;
	struct BST *right;
};
struct stk
{
        struct BST* info2;
        struct stk *next2;
};

void push(struct stk **,struct BST *);
struct BST * pop(struct stk **);


void insert(struct BST **,int);
void rpreorder(struct BST *);
void rinorder(struct BST *);
void rpostorder(struct BST *);
void nrpreorder(struct BST *);
void nrinorder(struct BST *);
//void nrpostorder(struct BST *);
void maxmin(struct BST *);
int find_h(struct BST *);
void delete(struct BST *,int);

int main()
{
	struct BST *root=NULL;
	int ch,item,h;
	while(1)
	{
		printf("1. Insert\n2. Recursive Preorder\n3. Recursive Inorder\n4. Recursive Postorder\n5. NR Preorder\n6. NR Inorder\n8. MAX and MIN\n9. Find height\n10. Delete\n0. Exit\n\nChoice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter the item to be inserted:");
				scanf("%d",&item);
				insert(&root,item);
				break;
			case 2: rpreorder(root);
				break;
			case 3: rinorder(root);
				break;
			case 4: rpostorder(root);
				break;
			case 5:	nrpreorder(root);
				break;
			case 6: nrinorder(root);
				break;
			case 8: maxmin(root);
				break;
			case 9: h=find_h(root);
				printf("\nHeight=%d\n",h);
				break;
			case 10: printf("\nEnter item to be deleted : ");
				 scanf("%d",&item);				 
				 delete(root,item);
				 break;
			case 0: exit(0);
			default: printf("\nWrong choice!\n");
		}
	}
	return(0);
}
void insert(struct BST **proot,int item)
{
	struct BST *par=NULL;
	struct BST *loc=*proot;
	struct BST *newnode;
	while(loc!=NULL)
	{
		if(item==loc->info)
		{
			printf("\nDuplicate value!\n");
			return;
		}
		par=loc;
		if(item<loc->info)
			loc=loc->left;
		else
			loc=loc->right;
	}
	newnode=(struct BST *)malloc(sizeof(struct BST));
	newnode->info=item;
	newnode->left=NULL;
	newnode->right=NULL;
	if(par==NULL)
		*proot=newnode;
	else if(item<par->info)
		par->left=newnode;
	else
		par->right=newnode;
}
void rpreorder(struct BST *root)
{
	if(root!=NULL)
	{
		printf("\nItem=%d\n",root->info);
		rpreorder(root->left);
		rpreorder(root->right);
	}
}
void rinorder(struct BST *root)
{
        if(root!=NULL)
        {
                rinorder(root->left);
		printf("\nItem=%d\n",root->info);
                rinorder(root->right);
        }
}
void rpostorder(struct BST *root)
{
        if(root!=NULL)
        {
                rpostorder(root->left);
                rpostorder(root->right);
		printf("\nItem=%d\n",root->info);
        }
}
void push(struct stk **ptop,struct BST *item)
{
        struct stk *newnode;
        newnode=(struct stk *)malloc(sizeof(struct stk));
        newnode->info2=item;
        newnode->next2=*ptop;
        *ptop=newnode;
}
struct BST * pop(struct stk **ptop)
{
        struct stk *temp;
        struct BST *item;

        
        item=(*ptop)->info2;
        temp=*ptop;
        *ptop=temp->next2;
        temp->next2=NULL;
        free(temp);
        return(item);
}
void nrpreorder(struct BST *root)
{
	struct stk *s=NULL;
	while(1)
	{
		while(root!=NULL)
		{
			printf("\nItem=%d\n",root->info);
			push(&s,root);
			root=root->left;
		}
		if(s==NULL)
			return;
		root=pop(&s);
		root=root->right;
	}
}
void nrinorder(struct BST *root)
{
        struct stk *s=NULL;
        while(1)
        {
                while(root!=NULL)
                {
                        push(&s,root);
                        root=root->left;
                }
                if(s==NULL)
                        return;
		printf("Item=%d\n",root->info);
                root=pop(&s);
                root=root->right;
	}
}
void maxmin(struct BST *root)
{
	struct BST *loc;
	loc=root;
	while(loc->left!=NULL)
		loc=loc->left;
	printf("\nMin=%d\n",loc->info);
	loc=root;
	while(loc->right!=NULL)
		loc=loc->right;
	printf("\nMax=%d\n",loc->info);
}
int find_h(struct BST *root)
{
	int l,r;
	if(root!=NULL)
	{
		l=1+find_h(root->left);
		r=1+find_h(root->right);
		if(l>r)
			return(l);
		else 
			return(r);
	}
	return(-1);
}
void delete(struct BST *root,int item)
{
	struct BST *loc=root, *par=NULL, *child,*suc,*parsuc;
	while(loc!=NULL && loc->info != item)
	{
		par=loc;
		if(item<loc->info)
			loc=loc->left;
		else
			loc=loc->right;
	}
	if(loc==NULL)
	{
		printf("\nNode containing item does not exist!\n");
		return;
	}
	if(loc->left==NULL && loc->right==NULL)
		child=NULL;
	else if(loc->left==NULL)
		child=loc->right;
	else if(loc->right==NULL)
		child=loc->left;
	else
	{
		suc=loc->right;
		parsuc=loc;
		while(suc->left!=NULL)
		{
			parsuc=suc;
			suc=suc->left;
		}
		if(parsuc!=loc)
		{
			parsuc->left=suc->right;
			suc->right=loc->right;
		}
		suc->left=loc->left;
		child=suc;
	}
	if(par!=NULL)
	{
		if(loc==par->left)
			par->left=child;
		else
			par->right=child;
	}
	else
		root=child;
	loc->left=NULL;
	loc->right=NULL;
	free(loc);
}
	
	
