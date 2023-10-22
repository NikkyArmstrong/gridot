#pragma once

#include <godot_cpp/classes/node2d.hpp>

namespace godot 
{
    class HelloWorld : public Node2D
    {
        GDCLASS(HelloWorld, Node2D)

        private:
            double _speed;
            Vector2 _velocity;

        protected:
            static void _bind_methods();

        public:
            HelloWorld();
            ~HelloWorld();
            void hello_world(String words);
            void _process(double delta);

            double get_speed() const;
            void set_speed(double speed);
    };
}