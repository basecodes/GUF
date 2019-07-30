
#include "AppDelegate.h"

AppDelegate::AppDelegate()
        :Application("org.gtk.example",
                GApplicationFlags::G_APPLICATION_FLAGS_NONE) {
}

void TestWindow(GUF::Application *application){
    auto window = new GUF::Window(GtkWindowType::GTK_WINDOW_TOPLEVEL);
    window->setSize(1024,800);
    window->setPosition(GtkWindowPosition::GTK_WIN_POS_CENTER);

    auto btn = new GUF::Button("this Button");
    btn->addClickEventListener([=](){
        g_print("%s", btn->getUUID().data());
        g_print("\n");
    });
    auto box = new GUF::Box(GtkOrientation::GTK_ORIENTATION_HORIZONTAL,50);

    auto btn2 = new GUF::Button("this Button2");
    btn2->addClickEventListener([=](){
        g_print("%s", btn2->getUUID().data());
        g_print("\n");
    });

    box->Add(btn);
    box->Add(btn2);

    window->Add(box);
    application->AddWindow(window);
    window->show();
}

void TestDialog(GUF::Application *application){
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

void AppDelegate::activate() {
    Application::activate();

    TestDialog(this);
}
