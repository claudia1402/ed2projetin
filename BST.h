/*
Integrantes:
Claudia Fiorentino Andrade - 42005302
João Victor Ferreira Pimenta - 42005876
Joyce Cui - 42017157
Ryan Marco Andrade dos Santos - 42080223
Victor Prado Chaves - 32070772
*/


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
	NodeBST* SearchInternalNome(NodeBST* node, std::string &nome) const;
	NodeBST* Search(float salario) const;
	NodeBST* SearchNome(std::string nome) const;
	NodeBST* InsertIterative(float salario, Funcionario funcNovo);
	NodeBST* Insert(float salario, Funcionario funcNovo);
	bool RemoveIterative(float salario);
	void Remove(float salario);

	float CalcMedia(std::string nome);
	int QntdJornada(int jornada);
	int QntdUnidd(std::string unidd);

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
	NodeBST* SearchInternalNome(NodeBST* node, std::string &nome) const;	
	NodeBST* InsertInternal(NodeBST* node, NodeBST* parent, float salario, Funcionario funcNovo);
	NodeBST* RemoveInternal(NodeBST* node, float salario);
	NodeBST* RemoveNode(NodeBST* node);
	void UpdateParentChild(NodeBST* parent, const NodeBST* child, NodeBST* newChild);

	float CalcMediaInternal(NodeBST* funcionario);
	int QntdJornadaInternal(NodeBST* node, int cont, int jornada);
	int QntdUniddInternal(NodeBST* node, int cont, std::string unidd);
};

#endif