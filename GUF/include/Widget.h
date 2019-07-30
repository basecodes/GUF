
#ifndef GUF_WIDGET_H
#define GUF_WIDGET_H

#include <string>
#include "Common.h"
#include "Object.h"
#include <gtk/gtk.h>

namespace GUF {

    class Window;
    abstract class Widget:Object {
    public:

        template <typename ... ArgsType>
        Widget(GType type,const std::string_view& firstPropertyName,ArgsType... ts);
        explicit Widget(GtkWidget *widget);
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

        [[nodiscard]]
        virtual GtkWidget *getGtkWidget() const{
            return _widget;
        }

    protected:
        template<typename T>
        T getGtkWidget() {
            return (T)(_widget);
        }

    private:
        std::string _uuid;
        GtkWidget *_widget;
    };
}

#endif //GUF_WIDGET_H
