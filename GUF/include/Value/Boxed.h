
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

        Boxed* copy();
        void free();

        void addCallback(const CopyCallback& copyCallback,const FreeCallback& freeCallback){
            _copyCallback = copyCallback;
            _freeCallback = freeCallback;
        }

        gpointer getValue() const{
            return _tuple._value;
        }

        GType getType() const{
            return _tuple._type;
        }

        static GType boxedTypeRegister(const std::string_view& name);
        static GType pointerTypeRegister(const std::string_view& name);

    private:
        struct Tuple{
            gpointer _value;
            GType _type;
            Boxed *_boxed;
        };
        static gpointer gBoxedCopyFunc(gpointer boxed);
        static void gBoxedFreeFunc(gpointer boxed) ;

        Tuple _tuple;
        CopyCallback _copyCallback;
        FreeCallback _freeCallback;
    };
}

#endif //GUF_BOXED_H
