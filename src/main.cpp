#include <drogon/drogon.h>

int main(int argc, char* argv[])
{
  drogon::app().loadConfigFile("drogon_config.json").run();

  return 0;
}
