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