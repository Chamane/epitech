/*
** Borg.cpp for cpp_d07m in /home/gogo/rendu/tek2/cpp_d07m/ex01/Borg.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 10 11:20:51 2017 Gauthier CLER
** Last update Tue Jan 10 11:20:53 2017 Gauthier CLER
*/

#include <iostream>
#include "Borg.hh"

Borg::Ship::Ship() {
  this->_side = 300;
  this->_maxWarp = 9;
  this->_core = NULL;
  std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
  std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
  std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship() {

}

void Borg::Ship::setupCore(WarpSystem::Core *core) {
  this->_core = core;
}

void Borg::Ship::checkCore() {
  std::cout << ((this->_core->checkReactor()->isStable()) ? "Everything is in order." : "Critical failure imminent.") << std::endl;
}
