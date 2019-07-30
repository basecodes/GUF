
#ifndef GUF_BUTTON_H
#define GUF_BUTTON_H

#include <gtk/gtk.h>
#include "LayoutContainers/Bin.h"
#include "Common.h"

namespace GUF {
    class Button : public Bin {
    public:
        Button():Button(""){}
        explicit Button(const std::string_view &label);
        ~Button() override = default;

        void addClickEventListener(const ClickCallback& clickCallback);

        template <typename ... ArgsType>
        explicit Button(const std::string_view& firstPropertyName,ArgsType...ts);
    protected:
        template <typename ... ArgsType>
        explicit Button(GType type,const std::string_view& firstPropertyName,ArgsType...ts);

    private:
        static void click(GtkWidget *widget,gpointer data);
        ClickCallback _clickCallback;
    };
}

#endif //GUF_BUTTON_H
