
#include "Value/Boxed.h"

namespace GUF{

    gpointer Boxed::gBoxedCopyFunc(gpointer boxed){
        auto box = (Boxed*)boxed;
        return box->_copyCallback();
    }

    void Boxed::gBoxedFreeFunc(gpointer boxed){
        auto box = (Boxed*)boxed;
        box->_freeCallback();
    }

    gpointer Boxed::copy(){
        return g_boxed_copy(_type,_boxed);
    }

    void Boxed::free() {
        g_boxed_free(_type,_boxed);
    }

    Boxed::~Boxed() {
        free();
    }

    Boxed::Boxed(GType type, gpointer value):
        _type(type),_boxed(value){

    }

    GType Boxed::boxedTypeRegister(const std::string_view& name) {
        return g_boxed_type_register_static(name.data(), gBoxedCopyFunc,gBoxedFreeFunc);
    }

    GType Boxed::pointerTypeRegister(const std::string_view& name) {
        return g_pointer_type_register_static(name.data());
    }
}