// BST.h
#ifndef __BST_H__
#define __BST_H__

#include "NodeBST.h"

class BST
{
public:
	BST();
	~BST();

	NodeBST* GetRoot() const;

	bool IsEmpty() const;
	void Clear();

	int GetDegree() const;
	int GetHeight() const;
/*
	std::string TraverseInOrder() const;
	std::string TraversePreOrder() const;
	std::string TraversePostOrder() const;
*/
	NodeBST* FindMin() const;
	NodeBST* FindMax() const;

	NodeBST* Predecessor(float salario) const;
	NodeBST* Successor(float salario) const;

	NodeBST* SearchIterative(float salario) const;
	NodeBST* Search(float salario) const;
	NodeBST* InsertIterative(float salario, Funcionario funcNovo);
	NodeBST* Insert(float salario, Funcionario funcNovo);
	bool RemoveIterative(float salario);
	void Remove(float salario);

private:
	NodeBST* m_Root;

	void Destroy(NodeBST *node);
	
	int GetDegreeInternal(const NodeBST* node) const;
/*
	std::string TraverseInOrderInternal(const NodeBST* node) const;
	std::string TraversePreOrderInternal(const NodeBST* node) const;
	std::string TraversePostOrderInternal(const NodeBST* node) const;
*/
	NodeBST* FindMinInternal(NodeBST* node) const;
	NodeBST* FindMaxInternal(NodeBST* node) const;

	NodeBST* PredecessorInternal(NodeBST* node) const;
	NodeBST* SuccessorInternal(NodeBST* node) const;

	NodeBST* SearchInternal(NodeBST* node, float &salario) const;
	NodeBST* InsertInternal(NodeBST* node, NodeBST* parent, float salario, Funcionario funcNovo);
	NodeBST* RemoveInternal(NodeBST* node, float salario);
	NodeBST* RemoveNode(NodeBST* node);
	void UpdateParentChild(NodeBST* parent, const NodeBST* child, NodeBST* newChild);
};

#endif