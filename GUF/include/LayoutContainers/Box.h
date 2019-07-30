
#ifndef GUF_BOX_H
#define GUF_BOX_H

#include <gtk/gtk.h>
#include "Container.h"

namespace GUF{
    class Box :public Container{
    public:
        Box();
        explicit Box(GtkBox *gtkBox);
        explicit Box(GtkOrientation orientation):Box(orientation,1){}

        Box(GtkOrientation orientation,int spacing);

        ~Box() override = default;

        [[nodiscard]]
        GtkWidget *getGtkWidget() const override{
            return (GtkWidget*)_box;
        }

    protected:

    private:
        GtkBox *_box;
    };
}

#endif //GUF_BOX_H
