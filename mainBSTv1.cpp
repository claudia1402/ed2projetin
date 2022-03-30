// mainBST.cpp
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "BST.h"
#include "Arquivo.h"
#include "vector"


// Prototipacao
void PrintNode(NodeBST* node);
void Insert(BST* bst);
void CreateBST(BST* bst);
void Remove(BST* bst);
void Search(BST* bst);
void Predecessor(BST* bst);
void Successor(BST* bst);
void FindMin(BST* bst);
void FindMax(BST* bst);


void PrintNode(NodeBST* node)
{
	if (node == nullptr) return;
	std::cout << "Salario:" << node->GetSalario()
		<< "(" << "Nome:" << node->GetFunc().GetNome() << "Unidade:" << node->GetFunc().GetUnidd() << "Jornada:" << node->GetFunc().GetJornada() << ")"
		<< " Pai:" << (node->GetParent() != nullptr ? node->GetParent()->GetSalario() : -1)
		<< "Filho esquerdo:" << (node->GetLeft() != nullptr ? node->GetLeft()->GetSalario() : -1)
		<< " Filho direito:" << (node->GetRight() != nullptr ? node->GetRight()->GetSalario() : -1)
		<< " Grau: " << node->GetDegree()
		<< " Profundidade: " << node->GetDepth()
		<< " Altura: " << node->GetHeight()	<< '\n';
}

void Insert(BST* bst)
{
	float salario;
	std::string nome;
	std::string unidade;
	std::string jornada;
	std::cout << "Inserir nome: ";
	std::cin >> nome;
	std::cout << "Inserir salario: ";
	std::cin >> salario;
	std::cout << "Inserir unidade: ";
	std::cin >> unidade;
	std::cout << "Inserir jornada: ";
	std::cin >> jornada;
	Funcionario func;
	func.SetNome(nome);
	func.SetUnidd(unidade);
	func.SetJornada(jornada);
	NodeBST* node = bst->Insert(salario, func);
	if (node)
	{
		std::cout << "Node inserted:\n";
		PrintNode(node);
	}
	else
		std::cout << "*** ERROR! Couldn't insert node!\n";
}

void CreateBST(BST* bst)
{
	std::fstream fin;
	std::vector<std::string> row;
	std::string line, word, temp;

	fin.open("askojdas.csv", std::fstream::in);

	while (fin >> temp) 
	{
		row.clear();
		getline(fin, line);
		std::istringstream s(line);
		while (getline(s, word, ','))
		{
			row.push_back(word);
		}
	}
}

void CreateBST2(BST* bst)
{
	std::string		dadosFunc[4];
	std::string		line;
	std::ifstream	arq;
	Funcionario		funcLinha;

	arq.open("remuneracao.csv", std::fstream::in);

	while(!arq.eof())  //laco de funcionarios
	{
		std::getline(arq, line); // recebe cada linha a partir do

		std::istringstream ss(line);
		std::string del;

		int i = -1;
		while(getline(ss, del, ','))
			dadosFunc[i++] = del;

		funcLinha.SetNome(dadosFunc[0]);
		funcLinha.SetUnidd(dadosFunc[2]);
		funcLinha.SetJornada(dadosFunc[3]);
		
		NodeBST* node = bst->Insert(std::stof(dadosFunc[1]), funcLinha);
	}
}

void Remove(BST* bst)
{
	int num;
	std::cout << "Remove number: ";
	std::cin >> num;
	bst->Remove(num);
}

void Search(BST* bst)
{
	int num;
	std::cout << "Search number: ";
	std::cin >> num;
	NodeBST* node = bst->Search(num);
	if (node)
	{
		std::cout << "Node found:\n";
		PrintNode(node);
	}
	else
		std::cout << "*** ERROR! Couldn't find node!\n";
}

void Predecessor(BST* bst)
{
	int num;
	std::cout << "Find predecessor of: ";
	std::cin >> num;
	NodeBST* node = bst->Predecessor(num);
	if (node)
	{
		std::cout << "Predecessor of " << num << ":\n";
		PrintNode(node);
	}
	else
		std::cout << "*** ERROR! There is no predecessor of " << num << "!\n";
}

void Successor(BST* bst)
{
	int num;
	std::cout << "Find successor of: ";
	std::cin >> num;
	NodeBST* node = bst->Successor(num);
	if (node)
	{
		std::cout << "Successor of " << num << ":\n";
		PrintNode(node);
	}
	else
		std::cout << "*** ERROR! There is no successor of " << num << "!\n";
}

void FindMin(BST* bst)
{
	NodeBST* node = bst->FindMin();
	if (node)
	{
		std::cout << "Minimum:\n";
		PrintNode(node);
	}
	else
		std::cout << "*** ERROR! Couldn't find minimum (tree is probably empty...)\n";
}

void FindMax(BST* bst)
{
	NodeBST* node = bst->FindMax();
	if (node)
	{
		std::cout << "Maximum:\n";
		PrintNode(node);
	}
	else
		std::cout << "*** ERROR! Couldn't find maximum (tree is probably empty...)\n";
}
/*
void TraverseInOrder(BST* bst)
{
	std::cout << bst->TraverseInOrder() << '\n';
}

void TraversePreOrder(BST* bst)
{
	std::cout << bst->TraversePreOrder() << '\n';
}

void TraversePostOrder(BST* bst)
{
	std::cout << bst->TraversePostOrder() << '\n';
}

void TraverseBST(NodeBST* node)
{
	if (node != nullptr)
	{
		TraverseBST(node->GetLeft());
		PrintNode(node);
		TraverseBST(node->GetRight());
	}
}
*/

int main()
{
	 
	BST* bst = new BST();
  
	int option = 0;
	do
	{
		std::cout << "*** BST Tree ***\n"
			<< "[1] Buscar o nome das pessoas com o maior salario\n"
			<< "[2] Buscar o nome das pessoas com o menor salario\n"
			<< "[3] Média gasta em cada cargo por hora (salario/hora)\n"
			<< "[4] Quantas pessoas tem a mesma hora de jornada\n"
			<< "[5] Quantas pessoas trabalham na mesma unidade\n"
			<< "[6] Finalizar programa\nOption: ";
		std::cin >> option;
		std::cout << '\n';

		switch (option)
		{
		// case 1: função(atributo); break;
		// case 2: função(atributo); break;
		// case 3: função(atributo); break;
		// case 4: função(atributo); break;
		// case 5: função(atributo); break;
		}

		std::cout << '\n';
	} while (option != 6);

	delete bst;
	return 0;
}