/*
** droid.cpp for cpp_d07m in /home/gogo/rendu/tek2/cpp_d08/ex00/droid.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Jan 11 10:48:13 2017 Gauthier CLER
** Last update Wed Jan 11 10:48:14 2017 Gauthier CLER
*/


#include <iostream>
#include "droid.hh"

Droid::Droid(std::string ID): _id(ID), _energy(50), _attack(25), _toughness(15){
  this->_status = new std::string("Standing by");
    std::cout << "Droid '" << this->_id << "' Activated" << std::endl;
}

Droid::Droid(Droid const &otherDroid) : _id(otherDroid._id), _energy(otherDroid._energy), _attack(otherDroid._attack), _toughness(otherDroid._toughness){
  this->_status = new std::string(otherDroid._status->c_str());
  std::cout << "Droid '" << this->_id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid() {
  delete this->_status;
  std::cout << "Droid '" << this->_id << "' Destroyed" << std::endl;
}

std::string Droid::getId() const {
  return this->_id;
}

size_t Droid::getEnergy() const {
  return this->_energy;
}

size_t Droid::getAttack() const {
  return this->_attack;
}

size_t Droid::getToughness() const {
  return this->_toughness;
}

std::string *Droid::getStatus() const {
  return this->_status;
}

void Droid::setId(std::string const & id) {
  this->_id = id;
}

void Droid::setEnergy(size_t const & energy) {
  if (energy > 100)
    this->_energy = 100;
  else
    this->_energy = energy;
}

void Droid::setStatus(std::string *status)  {
  delete this->_status;
  this->_status = status;
}

bool Droid::operator==(Droid const &otherDroid) const{
  if (this->_energy == otherDroid._energy
      && this->_id == otherDroid._id
      && *this->_status == *otherDroid._status
      && this->_attack == otherDroid._attack
      && this->_toughness == otherDroid._toughness)
    return true;
  return false;
}

Droid &Droid::operator<<(size_t &stock) {
  size_t	toGive = 100 - this->_energy;

  if (this->_energy < 100){
    if (toGive > stock)
      toGive = stock;
    this->_energy += toGive;
    stock -= toGive;
  }
  return *this;
}

bool Droid::operator!=(Droid const &otherDroid) const{
  return !this->operator==(otherDroid);
}

Droid & Droid::operator=(const Droid &otherDroid) {
  delete this->_status;
  this->_status = new std::string(otherDroid._status->c_str());
  this->_id = otherDroid._id;
  this->_energy = otherDroid._energy;
  return *this;
}

std::ostream &operator<<(std::ostream &stream, Droid const & droid) {
  stream << "Droid '" << droid.getId() << "', " << *(droid.getStatus()) << ", "  << droid.getEnergy();
  return stream;
}



