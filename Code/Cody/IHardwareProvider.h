#pragma once
#include "Vector3.h"

class IHardwareProvider {
  public:
    virtual ~IHardwareProvider() {}
    virtual void initialize() {}

    virtual void move(NavigationData navigationData) {}
};
