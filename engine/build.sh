CC=clang++

INPUT=$(find ./src -type f -name "*.cpp")

LINKDIRS="-Lexternal/glfw/lib"

INCLUDEDIRES="-Iexternal/glfw/include -Iinclude"
LINKLIBRARTIES="-lglfw3"

FLAGS="-shared -fPIC"

OUTPUT="-o bin/libengine.so"

$CC $INPUT $LINKDIRS $INCLUDEDIRES $LINKLIBRARTIES $FLAGS $OUTPUT