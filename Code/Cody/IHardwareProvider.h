#pragma once
#include "NavigationData.h"

class IHardwareProvider {
  public:
    virtual ~IHardwareProvider() {}
    virtual void initialize() {}

    virtual void move(NavigationData navigationData) {}
    virtual void homeXAxisAsync() {}
    virtual void moveXAxisAsync(double position) {}
    virtual void homeYAxisAsync() {}
    virtual void moveYAxisAsync(double position) {}
};
