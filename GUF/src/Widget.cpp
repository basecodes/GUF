
#include <Windows/Window.h>
#include <memory>
#include "Widget.h"

namespace GUF{

    void widgetDestroy(GtkWidget *gtkWidget, gpointer userData) {
        auto widget = (Widget*)g_object_get_data((GObject*)userData,"widget");
        delete(widget);
    }

    std::string Widget::getUUID() const {
        return _uuid;
    }

    template <typename ... ArgsType>
    Widget::Widget(GType type,const std::string_view &firstPropertyName,ArgsType...ts)
        :Widget(gtk_widget_new(type,firstPropertyName,ts...)) {
    }

    Widget::Widget(GtkWidget *widget) {
        _widget = widget;
        _uuid = g_uuid_string_random();
        g_object_set_data((GObject*)_widget,"widget",this);
        g_signal_connect (getGtkWidget(), "destroy", G_CALLBACK(widgetDestroy), _widget);
    }

    Widget::~Widget() {
        g_object_set_data((GObject*)_widget, "widget", nullptr);
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