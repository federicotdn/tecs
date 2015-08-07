## GLOBAL SETTINGS ##
compiler = 'g++'
program_name = 'ecs'
global_flags = '-std=c++11 -Wall -pedantic -isystem /usr/include/bullet -O4'

## ENVIRONMENT ##
env = Environment(CXX = compiler)
env.Append(CCFLAGS = global_flags)
env.Decider('MD5-timestamp')

## SOURCE FILES ##
src_physics = Split('physics/physicssystem.cpp')
src_render = Split('render/rendersystem.cpp')
src_tdogl = Split('tdogl/Bitmap.cpp tdogl/Texture.cpp tdogl/Camera.cpp tdogl/Program.cpp tdogl/Shader.cpp')
src_input = Split('input/inputsystem.cpp')
src_main = Split('assetloader.cpp engine.cpp game.cpp main.cpp')

## OBJECT FILES ##
obj_physics = Split('physics/physicssystem.o')
obj_render = Split('render/rendersystem.o')
obj_tdogl = Split('tdogl/Bitmap.o tdogl/Texture.o tdogl/Camera.o tdogl/Program.o tdogl/Shader.o')
obj_input = Split('input/inputsystem.o')
obj_main = Split('assetloader.o engine.o game.o main.o')

obj_all = obj_physics + obj_render + obj_tdogl + obj_main + obj_input

## LIBRARIES ##
lib_opengl = Split('GLEW GLU glfw GL')
lib_bullet = Split('BulletSoftBody BulletDynamics BulletCollision LinearMath')

lib_all = lib_opengl + lib_bullet

## BUILD AND LINK ##
env.Object(src_physics)
env.Object(src_render)
env.Object(src_tdogl)
env.Object(src_input)
env.Object(src_main)

env.Program(program_name, obj_all, LIBS = lib_all)


