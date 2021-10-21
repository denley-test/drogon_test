#include "HomeController.h"
using namespace drogon;

void HomeController::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
  HttpViewData data;
  data["name"] = req->getParameter("name");
  auto resp = HttpResponse::newHttpViewResponse("HomeView.csp", data);
  callback(resp);
}
