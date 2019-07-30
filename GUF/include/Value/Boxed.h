
#ifndef GUF_BOXED_H
#define GUF_BOXED_H

#include <gtk/gtk.h>
#include <string_view>
#include <utility>
#include "Common.h"

namespace GUF{
    class Boxed{
    public:

        Boxed(GType type,gpointer value);
        ~Boxed();

        gpointer copy();
        void free();

        void addCallback(CopyCallback copyCallback,FreeCallback freeCallback){
            _copyCallback = std::move(copyCallback);
            _freeCallback = std::move(freeCallback);
        }

        static GType boxedTypeRegister(const std::string_view& name);
        static GType pointerTypeRegister(const std::string_view& name);

    private:
        static gpointer gBoxedCopyFunc(gpointer boxed);
        static void gBoxedFreeFunc(gpointer boxed) ;

        gpointer _boxed;
        GType _type;
        CopyCallback _copyCallback;
        FreeCallback _freeCallback;
    };
}

#endif //GUF_BOXED_H
