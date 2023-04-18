//////////////////////////////////////////////////
// 'God Mode' - Create the famous god mode      //
// directory in Windows from the command line.  //
// © 2023 Ian Pride - New Pride Software        //
// / Services                                   //
//////////////////////////////////////////////////
#include <Windows.h>
#include <iostream>
#include <filesystem>
#include <sstream>
#include <map>
#include "Globals.h"
#include "Regex_.h"
void next_arg_test(int index, int argc, const char *argv[], int iferror)
{
  try
  {
    if ((index + 1) > (argc - 1))
    {
      std::string rtmsg = "No argument provided for [";
      rtmsg.append(argv[index]);
      rtmsg.append("].\n");
      throw std::runtime_error(rtmsg);
    }
  }
  catch (std::runtime_error& rerr)
  {
    std::cerr << rerr.what();
    WaitCheck();
    std::exit(iferror);
  }
}

int main(int argc, const char* argv[])
{
  HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
  SetConsoleMode(hInput, ENABLE_VIRTUAL_TERMINAL_INPUT);
  HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleMode(hOutput, ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleTitle(L"Windows God Mode");
  struct Regex regex
  {
    std::regex("^/([\\?]|[hH]|[hH][eE][lL][pP])$"),
    std::regex("^/([pP]|[pP][aA][tT][hH])$"),
    std::regex("^/([nN]|[nN][aA][mM][eE])$")
  };
  std::string godModeParentPath(".");
  std::string godModeName = "GodMode";
  const std::string godModeNameExtension = ".{ED7BA470-8E54-465E-825C-99712043E01C}";
  if (argc > 1)
  {
    for (int index = 1; index < argc; index++)
    {
      if (std::regex_match(argv[index], regex.HELP))
      {
        const std::string HELPMESSAGE =
          "\n"
          "God Mode - Create the famous god mode directory in Windows from the\n"
          "           command line.\n"
          "\n"
          "godmode   [/? | /h | /help] | [[/p | /path] <String>]\n"
          "          [[/n | /name] <String>]\n"
          "\n"
          "  /?, /h, /help This help screen.\n"
          "  /p, /path     The parent path where the directory will be located.\n"
          "                Defaults to '.' (current directory).\n"
          "  /n, /name     The name of directory. Defaults to 'GodMode', but it\n"
          "                can be any valid name including en empty string ('').\n"
          "\n";
        std::cout << HELPMESSAGE;
        WaitCheck();
        return EXIT_SUCCESS;
      }
      if (std::regex_match(argv[index], regex.PATH))
      {
        next_arg_test(index, argc, argv, 1);
        godModeParentPath = argv[index + 1];
        continue;
      }
      if (std::regex_match(argv[index], regex.NAME))
      {
        next_arg_test(index, argc, argv, 2);
        godModeName = argv[index + 1];
        continue;
      }
    }
  }
  std::string godModeFullPathString = [&godModeParentPath, godModeName, godModeNameExtension]()
  {
    std::stringstream ss;
    godModeParentPath = std::regex_replace(godModeParentPath, std::regex(R"(\\+|/)"), R"(\\)");
    godModeParentPath = std::regex_replace(godModeParentPath, std::regex(R"(\\+$|/$)"), R"()");
    ss << godModeParentPath << "\\\\" << godModeName << godModeNameExtension;
    return ss.str();
  }();
  if (godModeFullPathString.length() > MAX_PATH)
  {
    std::cerr << "The file path is too long [> " << MAX_PATH << "].\n";
    WaitCheck();
    return 3;
  }
  try
  {
    const bool CDRESULT = CreateDirectoryA(godModeFullPathString.c_str(), NULL);
    if (!CDRESULT)
    {
      DWORD CDERROR = ::GetLastError();
      throw std::runtime_error(std::system_category().message(CDERROR));
    }
  }
  catch (std::runtime_error& rerr)
  {
    const std::string errorMessage = rerr.what();
    std::map <std::string, int> em =
    {
      {"Access is denied.", 4},
      {"Cannot create a file when that file already exists.", 5},
      {"The system cannot find the path specified.", 6}
    };
    std::cerr << errorMessage << '\n';
    WaitCheck();
    return em[errorMessage];
  }
  std::cout << '\'' << godModeFullPathString << '\'' << " created successfully.\n";
  WaitCheck();
  return EXIT_SUCCESS;
}