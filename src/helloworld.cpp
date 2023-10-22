#include "helloworld.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/input.hpp>

using namespace godot;

void HelloWorld::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("get_speed"), &HelloWorld::get_speed);
    ClassDB::bind_method(D_METHOD("set_speed", "speed"), &HelloWorld::set_speed);
    ClassDB::add_property("HelloWorld", PropertyInfo(Variant::FLOAT, "_speed"), "set_speed", "get_speed");
    
    ClassDB::bind_method(D_METHOD("hello_world", "words"), &HelloWorld::hello_world);

    ADD_SIGNAL(MethodInfo("hello_world_signal", PropertyInfo(Variant::STRING, "data")));
}

HelloWorld::HelloWorld()
{
    if (Engine::get_singleton()->is_editor_hint())
    {
        set_process_mode(Node::ProcessMode::PROCESS_MODE_DISABLED);
    }

    UtilityFunctions::print("Hello World!");
}

HelloWorld::~HelloWorld()
{

}

void HelloWorld::hello_world(String words)
{
    UtilityFunctions::print("Hello world!" + words);
    emit_signal("hello_world_signal", "HELLO THIS IS A SIGNAL");
}

void HelloWorld::_process(double delta)
{
    Input& input = *Input::get_singleton();

    _velocity = Vector2(0.f,0.f);
    if (input.is_action_pressed("w"))
    {
        _velocity.y -= 1.0f;
    }
    if (input.is_action_pressed("a"))
    {
        _velocity.x -= 1.0f;
    }
    if (input.is_action_pressed("s"))
    {
        _velocity.y += 1.0f;
    }
    if (input.is_action_pressed("d"))
    {
        _velocity.x += 1.0f;
    }

    set_position(get_position() + _velocity * _speed * delta);
}

double HelloWorld::get_speed() const
{
    return _speed;
}

void HelloWorld::set_speed(double speed)
{
    _speed = speed;
}