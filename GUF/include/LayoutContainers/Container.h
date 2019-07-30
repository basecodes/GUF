
#ifndef GUF_CONTAINER_H
#define GUF_CONTAINER_H

#include <map>
#include <string>
#include <gtk/gtk.h>
#include "Widget.h"

namespace GUF{

    class Container: public Widget {
    public:
        template <typename ... ArgsType>
        explicit Container(const std::string_view& firstPropertyName,ArgsType...ts);

        explicit Container(GtkContainer *container);
        ~Container() override;

        virtual void Add(Widget *widget) ;
        virtual void Remove(Widget *widget) ;

    protected:
        template <typename ... ArgsType>
        Container(GType type,const std::string_view& firstPropertyName,ArgsType...ts);
    };
}

#endif //GUF_CONTAINER_H
