#include "options.hpp"
#include "person.hpp"

#include <fstream>
#include <iostream>

int main(int argc, char** argv)
{
  const size_t argumentCount = argc;
  muraviev::ProgramOptions options;
  if (!muraviev::parseProgramOptions(argumentCount, argv, options))
  {
    return 1;
  }

  muraviev::PersonList persons;
  muraviev::initList(persons);
  size_t accepted = 0;
  size_t ignored = 0;

  if (options.hasInput)
  {
    std::ifstream input(options.inputName);
    if (!input)
    {
      muraviev::clearList(persons);
      return 2;
    }
    muraviev::readPersons(input, persons, accepted, ignored);
    input.close();
  }
  else
  {
    muraviev::readPersons(std::cin, persons, accepted, ignored);
  }

  if (options.hasOutput)
  {
    std::ofstream output(options.outputName);
    if (!output)
    {
      muraviev::clearList(persons);
      return 2;
    }
    muraviev::printPersons(output, persons);
  }
  else
  {
    muraviev::printPersons(std::cout, persons);
  }

  std::cerr << accepted << ' ' << ignored << '\n';
  muraviev::clearList(persons);
  return 0;
}
