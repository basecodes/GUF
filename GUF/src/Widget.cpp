
#include <Windows/Window.h>
#include "Widget.h"

namespace GUF{

    std::string Widget::getUUID() const {
        return _uuid;
    }

    Widget::Widget():_uuid(g_uuid_string_random()) {
    }

    void Widget::show() {
        gtk_widget_show_all(getGtkWidget());
    }

    void Widget::destroy() {
        gtk_widget_destroy(getGtkWidget());
    }

    bool Widget::inDestruction() {
        return gtk_widget_in_destruction(getGtkWidget());
    }

    void Widget::showNow() {
        gtk_widget_show_now(getGtkWidget());
    }

    void Widget::destroyed(GtkWidget **widget_pointer) {
        gtk_widget_destroyed(getGtkWidget(),widget_pointer);
    }

    void Widget::hide() {
        gtk_widget_hide(getGtkWidget());
    }

    void Widget::setParentWindow(Window *window) {
        gtk_widget_set_parent_window(getGtkWidget(),(GdkWindow*)window->getGtkWidget());
    }

    void Widget::setParent(Widget *widget) {
        gtk_widget_set_parent(getGtkWidget(),widget->getGtkWidget());
    }
}