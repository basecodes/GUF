
#ifndef GUF_WINDOW_H
#define GUF_WINDOW_H

#include <gtk/gtk.h>
#include <string_view>

#include "LayoutContainers/Bin.h"

namespace GUF {

    class Application;
    class Window :public Bin{
    public:

        Window():Window(GtkWindowType::GTK_WINDOW_TOPLEVEL) {}
        explicit Window(GtkWindowType windowType):Bin((GtkBin*)gtk_window_new(windowType)) {}
        explicit Window(GtkWindow *window):Bin((GtkBin*)window){}

        ~Window() override = default;

        void setTitle(const std::string_view& title);
        std::string getTitle();

        void setSize(int width,int height);
        void setPosition(GtkWindowPosition windowPosition);

        template <typename ... ArgsType>
        explicit Window(const std::string_view& firstPropertyName,ArgsType...ts);
    protected:
        template <typename ... ArgsType>
        explicit Window(GType type,const std::string_view& firstPropertyName,ArgsType...ts);
    };
}

#endif //GUF_WINDOW_H
