#include "options.hpp"

#include <string>

namespace muraviev
{
  bool parseProgramOptions(const int argc, char** argv,
      ProgramOptions& options)
  {
    options.hasInput = false;
    options.hasOutput = false;
    if (argc < 1 || argc > 3)
    {
      return false;
    }
    for (size_t index = 1; index < static_cast< size_t >(argc); ++index)
    {
      const std::string argument = argv[index];
      if (argument.compare(0, 3, "in:") == 0)
      {
        options.hasInput = true;
        options.inputName = argument.substr(3);
      }
      else if (argument.compare(0, 4, "out:") == 0)
      {
        options.hasOutput = true;
        options.outputName = argument.substr(4);
      }
      else
      {
        return false;
      }
    }
    return true;
  }
}
