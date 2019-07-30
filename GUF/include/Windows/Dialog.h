
#ifndef GUF_DIALOG_H
#define GUF_DIALOG_H

#include "Window.h"

namespace GUF{

    class Box;
    class Dialog:public Window{
    public:
        explicit Dialog();
        ~Dialog() override ;

        Box *getBox();

        template <typename ... ArgsType>
        explicit Dialog(const std::string_view& firstPropertyName,ArgsType...ts);
    protected:
        template <typename ... ArgsType>
        explicit Dialog(GType type,const std::string_view& firstPropertyName,ArgsType...ts);

    private:
        Box *_box;
    };
}

#endif //GUF_DIALOG_H