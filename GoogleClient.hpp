#pragma once
#include "httpclient.h"
#include <iostream>

class GoogleClient final : private HttpClient
{
public:
    GoogleClient()
        : HttpClient(QHostAddress("8.8.8.8"))
    {}
    void helloGoogle() { get(""); }

private:
    virtual void processResponce(QByteArray) override
    {
        std::cout << "google responce!!" << std::endl;
    }
};
