#include "options.hpp"

int main(int argc, char** argv)
{
  const size_t argumentCount = argc;
  muraviev::ProgramOptions options;
  if (!muraviev::parseProgramOptions(argumentCount, argv, options))
  {
    return 1;
  }
  return 0;
}
