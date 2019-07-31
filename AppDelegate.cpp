
#include "AppDelegate.h"
#include "TestBoxed.h"

AppDelegate::AppDelegate()
        :Application("org.gtk.example",
                GApplicationFlags::G_APPLICATION_FLAGS_NONE) {
}

void AppDelegate::activate() {
    Application::activate();

    TestBoxed();
}
