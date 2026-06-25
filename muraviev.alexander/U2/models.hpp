#ifndef MODELS_HPP
#define MODELS_HPP

#include <cstddef>
#include <string>

namespace muraviev
{
  struct Person
  {
    size_t id;
    std::string info;
    bool hasInfo;
  };

  struct PersonNode
  {
    Person person;
    PersonNode* next;
  };

  struct PersonList
  {
    PersonNode* head;
    PersonNode* tail;
  };
}

#endif
