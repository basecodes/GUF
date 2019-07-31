
#ifndef GUF_TESTBOXED_H
#define GUF_TESTBOXED_H

#include "GUF/include/Value/Boxed.h"
#include <gtk/gtk.h>

static void TestBoxed(){
    int num = 3;
    auto newType = GUF::Boxed::boxedTypeRegister("NEWTYPE");
    GUF::Boxed boxed(newType,&num);
    boxed.addCallback([]()-> gpointer {
        g_print("new int");
        return new int{50};
    },[](){
        g_print("copy");
    });

    auto copy = boxed.copy();
    auto v = (int*)copy->getValue();
    G_STATIC_ASSERT(*v == 50);
    delete copy;
}

#endif //GUF_TESTBOXED_H
