
#include "Object.h"

namespace GUF{

    template<typename... ArgsType>
    Object::Object(GType type, const std::string_view &firstPropertyName, ArgsType... ts) {
        _object = (GObject*)g_object_new(type, firstPropertyName, ts...);
    }

    void Object::setProperty(const std::string_view &propertyId, const GValue *value) {
        g_object_set_property(_object, propertyId.data(), value);
    }

    GValue Object::getProperty(const std::string_view &propertyId) {
        GValue value = {};
        g_object_get_property(_object, propertyId.data(), &value);
        return value;
    }

    void Object::dispose() {
        g_object_run_dispose(_object);
    }

    void Object::finalize() {
        GObjectFinalizeFunc (_object);
    }

    void Object::dispatchPropertiesChanged() {
    }

    void Object::notify() {
        //g_object_notify()
    }
}