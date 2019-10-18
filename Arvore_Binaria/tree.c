#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

PtTree Subtree(PtTree Root, PtTree R, int* info){
	if(!R){
		R = (PtTree)malloc(sizeof(struct tree));
		if(!R){
			printf("\n\tEmpty space on memory.");
			exit(0);
		}
		R->right = NULL;
		R->left = NULL;
		R->info = info;
		if(!Root) return R;
		if(*(info) < *(Root->info)) Root->left = R;
		else Root->right = R;
		return R;
	}
	if(*(info) < *(R->info)) Subtree(R, R->left, info);
	else Subtree(R, R->right, info);
}

int Search_Tree(PtTree Root, int* key){
	if(!Root) return 0;
	if(*key != *(Root->info)){
		if(*key < *(Root->info)) Search_Tree(Root->left, key);
		else Search_Tree(Root->right, key);
	}else return 1;
}

PtTree Remove_Tree(PtTree Root, int* key){
	PtTree HP1, HP2;
	if(!Root) return Root;
	if(*(Root->info) == *key){
		if((Root->left) == (Root->right)){
			free(Root);
			return NULL;
		}else if((Root->left) == NULL){
			HP1 = Root->right;
			free(Root);
			return HP1;
		}else if((Root->right) == NULL){
			HP1 = Root->left;
			free(Root);
			return HP1;
		}else{
			HP2 = Root->right;
			HP1 = Root->right;
			while(HP2->left) HP2 = HP2->left;
			HP2->left = Root->left;
			free(Root);
			return HP1;
		}
	}
	if(*key < *(Root->info)) Root->left = Remove_Tree(Root->left, key);
	else Root->right = Remove_Tree(Root->right, key);
	return Root;
}

void Order(PtTree Root){
	if(!Root) return;
	Order(Root->left);
	if(Root->info) printf("\t%d", *(Root->info));
	Order(Root->right);
}

void PreOrder(PtTree Root){
	if(!Root) return;
	if(Root->info) printf("\t%d", *(Root->info));
	PreOrder(Root->left);
	PreOrder(Root->right);
}

void PosOrder(PtTree Root){
	if(!Root) return;
	PosOrder(Root->left);
	PosOrder(Root->right);
	if(Root->info) printf("\t%d", *(Root->info));
}

void Destroy_Tree(PtTree Root, PtTree R, PtTree Help_R){
	if(Root){
		if((R->left) || (R->right)){
			if(R->left){
				Help_R = R;
				Destroy_Tree(Root, R->left, Help_R);
			}
			if(R->right){
				Help_R = R;
				Destroy_Tree(Root, R->right, Help_R);
			}
		}else{
			if(Root != R){
				if(Help_R->left == R) Help_R->left = NULL;
				else Help_R->right = NULL;
				free(R);
				Destroy_Tree(Root,Root,Root);
			}else free(Root);
		}
	} 
}