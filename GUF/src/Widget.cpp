
#include <Windows/Window.h>
#include <memory>
#include "Widget.h"

namespace GUF{

    void widgetDestroy(GtkWidget *gtkWidget, gpointer userData) {
        auto widget = (Widget*)g_object_get_data((GObject*)gtkWidget,"widget");
        delete(widget);
    }

    std::string Widget::getUUID() const {
        return _uuid;
    }

    template <typename ... ArgsType>
    Widget::Widget(GType type,const std::string_view &firstPropertyName,ArgsType...ts)
        :Object(gtk_widget_new(type,firstPropertyName,ts...)) {
    }

    template<typename... ArgsType>
    Widget::Widget(const std::string_view &firstPropertyName, ArgsType... ts)
            :Widget(GTK_TYPE_WIDGET,firstPropertyName,ts...){
    }

    Widget::Widget(GtkWidget *widget):Object((GObject*)widget) {
        _uuid = g_uuid_string_random();
        g_object_set_data(getGtkObject(),"widget",this);
        g_signal_connect (getGtkObject(), "destroy", G_CALLBACK(widgetDestroy), nullptr);
    }

    Widget::~Widget() {
        g_object_set_data((GObject*)getGtkObject<GtkWidget*>(), "widget", nullptr);
    }

    void Widget::show() {
        gtk_widget_show_all(getGtkObject<GtkWidget*>());
    }

    void Widget::destroy() {
        gtk_widget_destroy(getGtkObject<GtkWidget*>());
    }

    bool Widget::inDestruction() {
        return gtk_widget_in_destruction(getGtkObject<GtkWidget*>());
    }

    void Widget::showNow() {
        gtk_widget_show_now(getGtkObject<GtkWidget*>());
    }

    void Widget::destroyed(GtkWidget **widget_pointer) {
        gtk_widget_destroyed(getGtkObject<GtkWidget*>(),widget_pointer);
    }

    void Widget::hide() {
        gtk_widget_hide(getGtkObject<GtkWidget*>());
    }

    void Widget::setParentWindow(Window *window) {
        gtk_widget_set_parent_window(getGtkObject<GtkWidget*>(),(GdkWindow*)window->getGtkObject<GtkWindow*>());
    }

    void Widget::setParent(Widget *widget) {
        gtk_widget_set_parent(getGtkObject<GtkWidget*>(),widget->getGtkObject<GtkWidget*>());
    }
}