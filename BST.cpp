/*
Integrantes:
Claudia Fiorentino Andrade - 42005302
João Victor Ferreira Pimenta - 42005876
Joyce Cui - 42017157
Ryan Marco Andrade dos Santos - 42080223
Victor Prado Chaves - 32070772
*/

// BST.cpp
#include "NodeBST.h"
#include "NodeBST.cpp"
#include "BST.h"
#include "Utils.h"
#include <sstream>

BST::BST()
	: m_Root(nullptr)
{
}

BST::~BST()
{
	Clear();
}

NodeBST* BST::GetRoot() const
{
	return m_Root;
}

bool BST::IsEmpty() const
{
	return m_Root == nullptr;
}

void BST::Clear()
{
	Destroy(m_Root);
	m_Root = nullptr;
}

void BST::Destroy(NodeBST* node)
{
	if (node != nullptr)
	{
		Destroy(node->GetLeft());
		Destroy(node->GetRight());

		delete node;
		node = nullptr;
	}
}

int BST::GetDegree() const
{
	return GetDegreeInternal(m_Root);
}

int BST::GetDegreeInternal(const NodeBST* node) const
{
	if (node != nullptr)
	{
		int left = GetDegreeInternal(node->GetLeft());
		int right = GetDegreeInternal(node->GetRight());
		return Utils::Max(node->GetDegree(), Utils::Max(left, right));
	}

	return 0;
}

int BST::GetHeight() const
{
	if (m_Root == nullptr)
		return -1;

	return m_Root->GetHeight();
}

/*
std::string BST::TraverseInOrder() const
{
	return TraverseInOrderInternal(m_Root);
}

std::string BST::TraverseInOrderInternal(const NodeBST* node) const
{
	if (node != nullptr)
	{
		std::ostringstream oss;
		oss << TraverseInOrderInternal(node->GetLeft());
		oss << node->GetSalario() << '(' << "Nome: " << node->GetFunc().GetNome() << "Cargo: " << node->GetFunc().GetCargo() << "Salario: " << node->GetFunc().GetSalario() << ") ";
		oss << TraverseInOrderInternal(node->GetRight());
		return oss.str();
	}

	//return "null ";
	return "";
}

std::string BST::TraversePreOrder() const
{
	return TraversePreOrderInternal(m_Root);
}

std::string BST::TraversePreOrderInternal(const NodeBST* node) const
{
	if (node != nullptr)
	{
		std::ostringstream oss;
		oss << node->GetSalario() << '(' << "Nome: " << node->GetFunc().GetNome() << "Cargo: " << node->GetFunc().GetCargo() << "Salario: " << node->GetFunc().GetSalario() << ") ";
		oss << TraversePreOrderInternal(node->GetLeft());
		oss << TraversePreOrderInternal(node->GetRight());
		return oss.str();
	}

	//return "null ";
	return "";
}

std::string BST::TraversePostOrder() const
{
	return TraversePostOrderInternal(m_Root);
}

std::string BST::TraversePostOrderInternal(const NodeBST* node) const
{
	if (node != nullptr)
	{
		std::ostringstream oss;
		oss << TraversePostOrderInternal(node->GetLeft());
		oss << TraversePostOrderInternal(node->GetRight());
		oss << node->GetSalario() << '(' << "Nome: " << node->GetFunc().GetNome() << "Cargo: " << node->GetFunc().GetCargo() << "Salario: " << node->GetFunc().GetSalario() << ") ";
		return oss.str();
	}

	//return "null ";
	return "";
}
*/
NodeBST* BST::FindMin() const
{
	return FindMinInternal(m_Root);
}

NodeBST* BST::FindMinInternal(NodeBST* node) const
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetLeft() == nullptr)
		return node;
	else
		return FindMinInternal(node->GetLeft());
}

NodeBST* BST::FindMax() const
{
	return FindMaxInternal(m_Root);
}

NodeBST* BST::FindMaxInternal(NodeBST* node) const
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetRight() == nullptr)
		return node;
	else
		return FindMaxInternal(node->GetRight());
}

NodeBST* BST::Predecessor(float salario) const
{
	NodeBST* node = SearchInternal(m_Root, salario);
	return node == nullptr ? nullptr : PredecessorInternal(node);
}

NodeBST* BST::PredecessorInternal(NodeBST* node) const
{
	if (node->GetLeft() != nullptr)
	{
		return FindMaxInternal(node->GetLeft());
	}
	else
	{
		NodeBST* current = node;
		NodeBST* currentParent = node->GetParent();
		while (currentParent != nullptr && current == currentParent->GetLeft())
		{
			current = currentParent;
			currentParent = current->GetParent();
		}

		return currentParent;
	}
}

NodeBST* BST::Successor(float salario) const
{
	NodeBST* node = SearchInternal(m_Root, salario);
	return node == nullptr ? nullptr : SuccessorInternal(node);
}

NodeBST* BST::SuccessorInternal(NodeBST* node) const
{
	if (node->GetRight() != nullptr)
	{
		return FindMinInternal(node->GetRight());
	}
	else
	{
		NodeBST* current = node;
		NodeBST* currentParent = node->GetParent();
		while (currentParent != nullptr && current == currentParent->GetRight())
		{
			current = currentParent;
			currentParent = current->GetParent();
		}

		return currentParent;
	}
}

NodeBST* BST::SearchIterative(float salario) const
{
	NodeBST* current = m_Root;
	while (current != nullptr && current->GetSalario() != salario)
	{
		if (current->GetSalario() > salario)
			current = current->GetLeft();
		else
			current = current->GetRight();
	}

	return current;
}

NodeBST* BST::Search(float salario) const
{
	return SearchInternal(m_Root, salario);
}

NodeBST* BST::SearchInternal(NodeBST* node, float &salario) const
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetSalario() == salario)
		return node;
	else if (node->GetSalario() > salario)
		return SearchInternal(node->GetLeft(), salario);
	else
		return SearchInternal(node->GetRight(), salario);
}

//Pesquisa por nome na BST
NodeBST* BST::SearchNome(std::string nome) const
{
	return SearchInternalNome(m_Root, nome);
}

NodeBST* BST::SearchInternalNome(NodeBST* node, std::string &nome) const
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetFunc().GetNome() == nome)
		return node;
	else if (node->GetFunc().GetNome() > nome)
		return SearchInternalNome(node->GetLeft(), nome);
	else
		return SearchInternalNome(node->GetRight(), nome);
}

NodeBST* BST::InsertIterative(float salario, Funcionario funcNovo)
{
	NodeBST* newNode = new NodeBST(salario, funcNovo);
	if (IsEmpty())
	{
		m_Root = newNode;
	}
	else
	{
		NodeBST* current = m_Root;
		NodeBST* currentParent = nullptr;
		while (current != nullptr)
		{
			currentParent = current;

			// Error! Cannot insert duplicate.
			if (current->GetSalario() == salario)
			{
				delete newNode;
				return nullptr;
			}

			if (current->GetSalario() > salario)
				current = current->GetLeft();
			else
				current = current->GetRight();
		}

		if (currentParent != nullptr)
		{
			if (currentParent->GetSalario() > salario)
				currentParent->SetLeft(newNode);
			else
				currentParent->SetRight(newNode);
		}
	}

	return newNode;
}

NodeBST* BST::Insert(float salario, Funcionario funcNovo)
{
	if (IsEmpty())
	{
		m_Root = new NodeBST(salario, funcNovo);
		return m_Root;
	}

	return InsertInternal(m_Root, nullptr, salario, funcNovo);
}

NodeBST* BST::InsertInternal(NodeBST* node, NodeBST* parent, float salario, Funcionario funcNovo)
{
	if (node == nullptr)
		node = new NodeBST(salario, funcNovo, parent);
	else if (node->GetSalario() == salario)
		return nullptr; // Error! Cannot insert duplicate.
	else if (node->GetSalario() > salario)
		node->SetLeft(InsertInternal(node->GetLeft(), node, salario, funcNovo));
	else if (node->GetSalario() < salario)
		node->SetRight(InsertInternal(node->GetRight(), node, salario, funcNovo));

	return node;
}

bool BST::RemoveIterative(float salario)
{
	NodeBST* current = m_Root;
	while (current != nullptr && current->GetSalario() != salario)
	{
		if (current->GetSalario() > salario)
			current = current->GetLeft();
		else
			current = current->GetRight();
	}

	if (current == nullptr)
		return false;

	RemoveNode(current);
	return true;
}

void BST::Remove(float salario)
{
	RemoveInternal(m_Root, salario);
}

NodeBST* BST::RemoveInternal(NodeBST* node, float salario)
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetSalario() == salario)
		node = RemoveNode(node);
	else if (node->GetSalario() > salario)
		node->SetLeft(RemoveInternal(node->GetLeft(), salario));
	else
		node->SetRight(RemoveInternal(node->GetRight(), salario));
	
	return node;
}

NodeBST* BST::RemoveNode(NodeBST* node)
{
	NodeBST* parent = node->GetParent();

	// Case 1: The node to be removed is a leaf.
	if (node->IsLeaf())
	{
		UpdateParentChild(parent, node, nullptr);

		delete node;
		node = nullptr;
	}
	// Case 2: The node to be removed has no left child/subtree.
	else if (node->GetLeft() == nullptr)
	{
		NodeBST* newChild = node->GetRight();
		UpdateParentChild(parent, node, newChild);

		delete node;
		node = newChild;
	}
	// Case 3: The node to be removed has no right child/subtree.
	else if (node->GetRight() == nullptr)
	{
		NodeBST* newChild = node->GetLeft();
		UpdateParentChild(parent, node, newChild);

		delete node;
		node = newChild;
	}
	// Case 4: The node to be removed has both left and right children/subtrees.
	else
	{
		// To remove the node, we are reducing the problem to Case 3.
		// In this case, predecessor is located in the node's left child/subtree and
		// is the node that has no right child/subtree.
		NodeBST* predecessor = Predecessor(node->GetSalario());

		// Instead of only updating pointers, we are copying the data from the
		// predecessor to the node pointer and then we remove the predecessor node.
		node->CopyDataFrom(predecessor);
		node->SetLeft(RemoveInternal(node->GetLeft(), predecessor->GetSalario()));
	}

	return node;
}

void BST::UpdateParentChild(NodeBST* parent, const NodeBST* child, NodeBST* newChild)
{
	if (parent != nullptr)
	{
		if (parent->GetLeft() == child)
			parent->SetLeft(newChild);
		else
			parent->SetRight(newChild);
	}
	else
	{
		m_Root = newChild;
	}

	if (newChild != nullptr)
		newChild->SetParent(parent);
}
/*
std::string BST::TraverseInOrder() const
{
	return TraverseInOrderInternal(m_Root);
}

std::string BST::TraverseInOrderInternal(const NodeBST* node) const
{
	if (node != nullptr)
	{
		std::ostringstream oss;
		oss << TraverseInOrderInternal(node->GetLeft());
		oss << node->GetSalario() << '(' << "Nome: " << node->GetFunc().GetNome() << "Cargo: " << node->GetFunc().GetCargo() << "Salario: " << node->GetFunc().GetSalario() << ") ";
		oss << TraverseInOrderInternal(node->GetRight());
		return oss.str();
	}

	//return "null ";
	return "";
}
*/

//calcula media de salario ganho por hora semanal
float BST::CalcMedia(std::string nome) 
{
	NodeBST*	funcionario;

	funcionario = SearchNome (nome);
	return CalcMediaInternal (funcionario);
}

float BST::CalcMediaInternal (NodeBST* funcionario)
{
	return funcionario -> GetSalario() / funcionario -> GetFunc().GetJornada();
}

//calcula numero de funcionarios que possuem mesma jornada por meio de um contador para casos iguais
int BST::QntdJornada(int jornada)
{
	NodeBST*	inicio = FindMin();
	int			cont = 0;

	return QntdJornadaInternal (inicio, cont, jornada);
}

int BST::QntdJornadaInternal(NodeBST* node, int cont, int jornada)
{
	while (node != nullptr)
	{
		if (node->GetFunc().GetJornada() == jornada)
			cont++;
		
		node = Successor(node->GetSalario());
	}
	return cont;
}

//calcula numero de funcionarios que trabalham na mesma unidade por meio de um contador para casos iguais
int BST::QntdUnidd(std::string unidd)
{
	NodeBST*	inicio = FindMin();
	int			cont = 0;

	return QntdUniddInternal (inicio, cont, unidd);
}

int BST::QntdUniddInternal(NodeBST* node, int cont, std::string unidd)
{
	while (node != nullptr)
	{
		if (node->GetFunc().GetUnidd() == unidd)
			cont++;
		
		node = Successor (node->GetSalario());
	}
	return cont;
}
