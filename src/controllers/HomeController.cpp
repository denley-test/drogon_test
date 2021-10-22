#include "HomeController.h"
using namespace drogon;

void HomeController::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
  HttpViewData data;
  data["title"] ="管理平台";
  data["company_name"] = "深圳雅果";
  data["copyright_year"] = "2021";
  data["name"] = req->getParameter("name");
  auto resp = HttpResponse::newHttpViewResponse("HomeView.csp", data);
  callback(resp);
}
