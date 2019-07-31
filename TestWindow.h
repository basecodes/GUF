
#ifndef GUF_TESTWINDOW_H
#define GUF_TESTWINDOW_H

#include "Application.h"

static void TestWindow(GUF::Application *application){
    auto window = new GUF::Window(GtkWindowType::GTK_WINDOW_TOPLEVEL);
    window->setSize(1024,800);
    window->setPosition(GtkWindowPosition::GTK_WIN_POS_CENTER);

    auto btn = new GUF::Button("this Button");
    btn->addClickEventListener([=](){
        g_print("%s", btn->getUUID().data());
        g_print("\n");
    });
    auto box = new GUF::Box(GtkOrientation::GTK_ORIENTATION_HORIZONTAL,10);

    auto btn2 = new GUF::Button("this Button2");
    btn2->addClickEventListener([=](){
        g_print("%s", btn2->getUUID().data());
        g_print("\n");
    });

    box->Add(btn);
    box->Add(btn2);

//    GValue v = {};
//    g_value_init (&v, G_TYPE_INT);
//    g_value_set_int(&v,500);
//    g_object_set_property(box->getGtkObject(),"spacing",&v);
    window->Add(box);
    application->AddWindow(window);
    window->show();
}

#endif //GUF_TESTWINDOW_H
