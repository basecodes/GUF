
#ifndef GUF_WIDGET_H
#define GUF_WIDGET_H

#include <string>
#include "Common.h"
#include "Object.h"
#include <gtk/gtk.h>

namespace GUF {

    class Window;
    class Widget:public Object {
    public:

        explicit Widget(GtkWidget *widget);
        template <typename ... ArgsType>
        explicit Widget(const std::string_view& firstPropertyName,ArgsType...ts);
        ~Widget() override;

        virtual void show();
        virtual void destroy();
        virtual bool inDestruction();
        virtual void showNow();
        virtual void hide();
        virtual void destroyed(GtkWidget **widget_pointer);
        virtual void setParentWindow(Window *window);
        virtual void setParent(Widget *widget);

        [[nodiscard]]
        virtual std::string getUUID() const;

    protected:
        template <typename ... ArgsType>
        Widget(GType type,const std::string_view& firstPropertyName,ArgsType... ts);

    private:
        std::string _uuid;
    };
}

#endif //GUF_WIDGET_H
