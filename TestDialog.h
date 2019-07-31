
#ifndef GUF_TESTDIALOG_H
#define GUF_TESTDIALOG_H

#include "AppDelegate.h"

static void TestDialog(GUF::Application *application){
    auto dialog = new GUF::Dialog();
    dialog->setTitle("Test Dialog!");
    dialog->setSize(500,500);
    auto btn = new GUF::Button("this Button");
    btn->addClickEventListener([=](){
        g_print("%s", btn->getUUID().data());
        g_print("\n");
    });

    auto btn2 = new GUF::Button("this Button2");
    btn2->addClickEventListener([=](){
        g_print("%s", btn->getUUID().data());
        g_print("\n");
    });

    dialog->getBox()->Add(btn);
    dialog->getBox()->Add(btn2);
    dialog->show();
    btn->hide();
    dialog->showNow();
    application->AddWindow(dialog);
}

#endif //GUF_TESTDIALOG_H
