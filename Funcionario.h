/*
Integrantes:
Claudia Fiorentino Andrade - 42005302
João Victor Ferreira Pimenta - 42005876
Joyce Cui - 42017157
Ryan Marco Andrade dos Santos - 42080223
Victor Prado Chaves - 32070772
*/

// Funcionario.h
#ifndef __Funcionario_H__
#define __Funcionario_H__

#include "NodeBST.h"

class Funcionario {
private:
  std::string f_nome;       // Nome completo do funcionário
  std::string f_unidade;    // Unidade onde trabalha
  int f_jornada;    // Jornada
 
public:
  Funcionario();
  Funcionario(std::string nome, std::string unidade, int jornada);
  std::string GetNome();
  void SetNome(std::string nome);
  std::string GetUnidd();
  void SetUnidd(std::string unidade);
  int GetJornada();
  void SetJornada(int jornada);
};

#endif