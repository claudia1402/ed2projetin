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

	std::string TraverseInOrder() const;
	std::string TraversePreOrder() const;
	std::string TraversePostOrder() const;

	NodeBST* FindMin() const;
	NodeBST* FindMax() const;

	NodeBST* Predecessor(int id) const;
	NodeBST* Successor(int id) const;

	NodeBST* SearchIterative(int id) const;
	NodeBST* Search(int id) const;
	NodeBST* InsertIterative(int id, const std::string& data);
	NodeBST* Insert(int id, const std::string& data);
	bool RemoveIterative(int id);
	void Remove(int id);

private:
	NodeBST* m_Root;

	void Destroy(NodeBST *node);
	
	int GetDegreeInternal(const NodeBST* node) const;

	std::string TraverseInOrderInternal(const NodeBST* node) const;
	std::string TraversePreOrderInternal(const NodeBST* node) const;
	std::string TraversePostOrderInternal(const NodeBST* node) const;

	NodeBST* FindMinInternal(NodeBST* node) const;
	NodeBST* FindMaxInternal(NodeBST* node) const;

	NodeBST* PredecessorInternal(NodeBST* node) const;
	NodeBST* SuccessorInternal(NodeBST* node) const;

	NodeBST* SearchInternal(NodeBST* node, int &id) const;
	NodeBST* InsertInternal(NodeBST* node, NodeBST* parent, int id, const std::string& data);
	NodeBST* RemoveInternal(NodeBST* node, int id);
	NodeBST* RemoveNode(NodeBST* node);
	void UpdateParentChild(NodeBST* parent, const NodeBST* child, NodeBST* newChild);
};

#endif