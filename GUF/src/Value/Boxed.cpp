
#include "Value/Boxed.h"

namespace GUF{

    gpointer Boxed::gBoxedCopyFunc(gpointer data){
        auto tuple = (Tuple*)data;
        return tuple->_boxed->_copyCallback();
    }

    void Boxed::gBoxedFreeFunc(gpointer data){
        auto tuple = (Tuple*)data;
        tuple->_boxed->_freeCallback();
    }

    Boxed* Boxed::copy(){
        auto pointer = g_boxed_copy(_tuple._type,&_tuple);
        return new Boxed(_tuple._type,pointer);
    }

    void Boxed::free() {
        g_boxed_free(_tuple._type,_tuple._boxed);
    }

    Boxed::~Boxed() {
        free();
    }

    Boxed::Boxed(GType type, gpointer value){
        _tuple._type = type;
        _tuple._value = value;
        _tuple._boxed = this;
    }

    GType Boxed::boxedTypeRegister(const std::string_view& name) {
        return g_boxed_type_register_static(name.data(), gBoxedCopyFunc,gBoxedFreeFunc);
    }

    GType Boxed::pointerTypeRegister(const std::string_view& name) {
        return g_pointer_type_register_static(name.data());
    }
}