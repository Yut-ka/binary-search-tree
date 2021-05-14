#pragma once
#include "../menu.h"
#include <string>
#include <iostream>
#include <time.h>
#include <string>

struct Tree_Item {
public:
	int inf;
	int count;
	Tree_Item* left;
	Tree_Item* right;
};

int stop = false;
Tree_Item* pRoot;
Tree_Item* pFind = new Tree_Item();


void Search(int x) {
	stop = false;
	pFind = pRoot;
	while (pFind != NULL && !stop) {
		if (x < pFind->inf) pFind = pFind->left;
		else if (x > pFind->inf) pFind = pFind->right;
		else stop = true;
	}
}

void Add_recursion(int inf, Tree_Item*& pCurrent = pRoot) {
	if (pCurrent == NULL) {
		pCurrent = new Tree_Item();
		pCurrent->inf = inf;
		pCurrent->left = NULL;
		pCurrent->right = NULL;
		pCurrent->count = 1;
	}
	else {
		if (inf < pCurrent->inf) Add_recursion(inf, pCurrent->left);
		else if (inf > pCurrent->inf) Add_recursion(inf, pCurrent->right);
		else pCurrent->count++;
	}
}

int Add(int inf) {
	if (pRoot == NULL) {
		pRoot = new Tree_Item();
		pRoot->inf = inf;
		pRoot->left = NULL;
		pRoot->right = NULL;
		pRoot->count = 1;
	}
	else {
		Tree_Item* pCurrent;
		Tree_Item* pPred;
		pCurrent = pRoot;
		while (pCurrent != NULL) {
			pPred = pCurrent;
			if (inf < pCurrent->inf) pCurrent = pCurrent->left;
			else if (inf > pCurrent->inf) pCurrent = pCurrent->right;
			else {
				pCurrent->count++;
				return 1;
			}
		}
		pCurrent = new Tree_Item();
		pCurrent->inf = inf;
		pCurrent->left = NULL;
		pCurrent->right = NULL;
		pCurrent->count = 1;

		if (inf < pPred->inf) {
			pPred->left = pCurrent;
		}
		else if (inf > pPred->inf) {
			pPred->right = pCurrent;
		}
		return 0;
	}
}

void Create_Tree(int N, Tree_Item*& pCurrent = pRoot) {
	if(pCurrent == NULL && N > 0){
		for (int i = 0; i < N; ++i) {
			int x = rand() % 100;
			Add(x);
			Search(x);
			pFind->count = 1 + rand() % 5;
		}
	}
}

void Changer(Tree_Item*& p, Tree_Item*& pTemp) {
	if (p->right != NULL) Changer(p->right, pTemp);
	else {
		pTemp->inf = p->inf;
		pTemp = p;
		p = p->left;
	}
}

std::string str_delete;

void Delete(int inf, Tree_Item*& pCurrent = pRoot, Tree_Item*& pParent = pRoot) {
	str_delete = "The vertex not found!";
	if (pCurrent != NULL) {
		if (inf < pCurrent->inf) Delete(inf, pCurrent->left, pCurrent);
		else if (inf > pCurrent->inf) Delete(inf, pCurrent->right, pCurrent);
		else {
			Tree_Item* pTemp = pCurrent;
			if (pTemp->left == NULL) {
				if (pParent != NULL && pParent->left == pTemp) pParent->left = pTemp->right;
				if (pParent != NULL && pParent->right == pTemp) pParent->right = pTemp->right;
				if (pTemp == pRoot) pParent = pTemp->right;
			}
			else if (pTemp->right == NULL) {
				if (pParent != NULL && pParent->left == pTemp) pParent->left = pTemp->left;
				if (pParent != NULL && pParent->right == pTemp) pParent->right = pTemp->left;
				if (pTemp == pRoot) pParent = pTemp->left;
			}
			else {
				Changer(pTemp->left, pTemp);
			}
			delete(pTemp);
			str_delete = "The vertex was deleted successfully!";
		}
	}
}

void Preorder_inline(std::string& str, Tree_Item* pCurrent) {
	if (pCurrent != NULL) {
		Preorder_inline(str, pCurrent->left);
		std::string line = std::to_string(pCurrent->inf) + "[" + std::to_string(pCurrent->count) + "]  ";
		str = str + line + "  ";
		Preorder_inline(str, pCurrent->right);
	}
}

void Preorder_traversal(std::string& str, Tree_Item* pCurrent, int t = 0) {
	if (pCurrent != NULL) {
		std::string line = "";
		for (int i = 0; i < t; i++) line += "\t";
		line = line + std::to_string(pCurrent->inf);
		str = str + line + "\n";
		Preorder_traversal(str, pCurrent->left, t + 1);
		Preorder_traversal(str, pCurrent->right, t + 1);
	}
}

void Inorder_traversal(std::string& str, Tree_Item* pCurrent, int t = 0) {
	if (pCurrent != NULL) {
		Inorder_traversal(str, pCurrent->left, t + 1);
		std::string line = "";
		for (int i = 0; i < t; i++) line += "\t";
		line = line + std::to_string(pCurrent->inf);
		str = str + line + "\n";
		Inorder_traversal(str, pCurrent->right, t + 1);
	}
}

void Reverse_Inorder(std::string& str, Tree_Item* pCurrent, int t = 0) {
	if (pCurrent != NULL) {
		Reverse_Inorder(str, pCurrent->right, t + 1);
		std::string line = "";
		for (int i = 0; i < t; i++) line += "\t";
		line = line + std::to_string(pCurrent->inf);
		str = str + line + "\n";
		Reverse_Inorder(str, pCurrent->left, t + 1);
	}
}