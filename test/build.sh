CC=clang++

INPUT=$(find ./src -type f -name "*.cpp")

LINKDIRS="-L/home/abdalhalem/DEV/CPP/OpenGlGameEngine/engine/bin"

# INCLUDEDIRES="-Iexternal/glfw/include -Iinclude"
# INCLUDEDIRES="-I/home/abdalhalem/DEV/CPP/OpenGlGameEngine/engine/external/glfw/include"
# INCLUDEDIRES="-IOpenGlGameEngine/engine/include"
INCLUDEDIRES="-I/home/abdalhalem/DEV/CPP/OpenGlGameEngine/engine/include"

LINKLIBRARTIES="-lengine"

FLAGS="-fPIC -Wl,-R/home/abdalhalem/DEV/CPP/OpenGlGameEngine/engine/bin"

OUTPUT="-o bin/test"

$CC $INPUT $LINKDIRS $INCLUDEDIRES $LINKLIBRARTIES $FLAGS $OUTPUT