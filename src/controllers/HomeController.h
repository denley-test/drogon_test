#ifndef __ARGUSAI_BACKEND_CONTROLLER_HOME_CONTROLLER_H__
#define __ARGUSAI_BACKEND_CONTROLLER_HOME_CONTROLLER_H__

#include <drogon/HttpSimpleController.h>

class HomeController:public drogon::HttpSimpleController<HomeController>
{
  public:
    virtual void asyncHandleHttpRequest(const drogon::HttpRequestPtr& req, std::function<void (const drogon::HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    PATH_ADD("/", drogon::Get);
    PATH_ADD("/index", drogon::Get);
    PATH_ADD("/home", drogon::Get);
    PATH_LIST_END
};

#endif
