set -e

echo "Setting up BrickSpace..."

if [ ! -d "raylib" ]; then
    echo "Downloading raylib..."
    git clone https://github.com/raysan5/raylib.git
fi

cd raylib/src

echo "Building raylib locally..."
make PLATFORM=PLATFORM_DESKTOP

cd ../..

echo "Compiling BrickSpace..."

g++ src/main.cpp -Iraylib/src -Lraylib/src -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -o brickspace

echo "Build complete!"
echo "Run with: ./brickspace"
