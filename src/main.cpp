#include <drogon/drogon.h>

int main(int argc, const char* argv[])
{
  drogon::app().loadConfigFile("argusai_backend_config.json").run();

  return 0;
}
