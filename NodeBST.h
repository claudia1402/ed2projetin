/*
Integrantes:
Claudia Fiorentino Andrade - 42005302
João Victor Ferreira Pimenta - 42005876
Joyce Cui - 42017157
Ryan Marco Andrade dos Santos - 42080223
Victor Prado Chaves - 32070772
*/

// NodeBST.h
#ifndef __NODE_BST_H__
#define __NODE_BST_H__

#include <string>
#include "Funcionario.h"
class NodeBST
{
public:
	NodeBST(float salario, Funcionario func , NodeBST* parent = nullptr, NodeBST* left = nullptr, NodeBST* right = nullptr);
	~NodeBST();

	void CopyDataFrom(const NodeBST* node);

	int GetSalario() const;
	void SetSalario(float salario);

	Funcionario GetFunc() const;

	NodeBST* GetParent() const;
	void SetParent(NodeBST* parent);

	NodeBST* GetLeft() const;
	void SetLeft(NodeBST* left);

	NodeBST* GetRight() const;
	void SetRight(NodeBST* right);

	bool IsRoot() const;
	bool IsLeaf() const;

	int GetDegree() const;
	int GetDepth() const;
	int GetHeight() const;

private:
	float m_Salario;
	Funcionario m_Func;
	NodeBST* m_Parent;
	NodeBST* m_Left;
	NodeBST* m_Right;

	int GetDepthInternal(const NodeBST* node) const;
	int GetHeightInternal(const NodeBST* node) const;
};

#endif
