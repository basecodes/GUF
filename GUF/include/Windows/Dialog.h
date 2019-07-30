
#ifndef GUF_DIALOG_H
#define GUF_DIALOG_H

#include "Window.h"

namespace GUF{

    class Box;
    class Dialog:public Window{
    public:
        explicit Dialog();
        ~Dialog() override ;

        [[nodiscard]]
        GtkWidget *getGtkWidget() const override{
            return (GtkWidget*)_dialog;
        }

        Box *getBox();
    private:
        GtkDialog *_dialog;
        Box *_box;
    };
}

#endif //GUF_DIALOG_H
