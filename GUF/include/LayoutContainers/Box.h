
#ifndef GUF_BOX_H
#define GUF_BOX_H

#include <gtk/gtk.h>
#include "Container.h"

namespace GUF{
    class Box :public Container{
    public:
        Box():Box(GtkOrientation::GTK_ORIENTATION_VERTICAL,1){}
        explicit Box(GtkBox *box):Container((GtkContainer*)box){}
        explicit Box(GtkOrientation orientation):Box(orientation,1){}

        Box(GtkOrientation orientation,int spacing)
        :Box((GtkBox*)gtk_box_new(orientation,spacing)) {}
        ~Box() override = default;

        template <typename ... ArgsType>
        explicit Box(const std::string_view& firstPropertyName,ArgsType...ts);
    protected:
        template <typename ... ArgsType>
        explicit Box(GType type,const std::string_view& firstPropertyName,ArgsType...ts);
    };
}

#endif //GUF_BOX_H
