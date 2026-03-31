#pragma once
#include "NavigationData.h"
#include "ToolheadData.h"

class IHardwareProvider {
  public:
    virtual ~IHardwareProvider() {}
    virtual void initialize() {}

    virtual void move(NavigationData navigationData) {}
    virtual void moveToolhead(ToolheadData toolheadData) {}
};
