
#ifndef GUF_APPDELEGATE_H
#define GUF_APPDELEGATE_H

#include "GUF.h"

class AppDelegate: public GUF::Application {
public:
    AppDelegate();
    void activate() override;
};


#endif //GUF_APPDELEGATE_H
