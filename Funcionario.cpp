/*
Integrantes:
Claudia Fiorentino Andrade - 42005302
João Victor Ferreira Pimenta - 42005876
Joyce Cui - 42017157
Ryan Marco Andrade dos Santos - 42080223
Victor Prado Chaves - 32070772
*/

#include "Funcionario.h"
#include <sstream>

Funcionario::Funcionario() {
  f_nome      = "";
  f_unidade   = "";
  f_jornada   = 0;
}

Funcionario::Funcionario(std::string nome, std::string unidade, int jornada) {
  f_nome      = nome;
  f_unidade   = unidade;
  f_jornada   = jornada;
}

// Nome do Funcionário
std::string Funcionario::GetNome(){
  return f_nome;
}

void Funcionario::SetNome(std::string nome){
  f_nome = nome;
}

//  Unidade onde o funcionario trabalha
std::string Funcionario::GetUnidd(){
  return f_unidade;
}
void Funcionario::SetUnidd(std::string unidade){
  f_unidade = unidade;
}

// Jornada do funcionario
int Funcionario::GetJornada(){
  return f_jornada;
}
void Funcionario::SetJornada(int jornada){
  f_jornada = jornada;
}