
#include "Object.h"

namespace GUF{

    Object::Object(GObject *object) {
        _object = object;
    }

    template<typename... ArgsType>
    Object::Object(GType type, const std::string_view &firstPropertyName, ArgsType... ts)
        :Object((GObject*)g_object_new(type, firstPropertyName, ts...)){
    }

    void Object::setProperty(const std::string_view &propertyName, const GValue *value) {
        g_object_set_property(_object, propertyName.data(), value);
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

    void Object::notify(const std::string_view& propertyName) {
        g_object_notify(_object,propertyName.data());
    }

    void Object::constructed() {
    }
}