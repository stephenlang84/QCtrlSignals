set CMAKE_PREFIX_PATH=C:\\Qt\\6.3.0\\msvc2019_64
mkdir build
cd build
cmake -DCMAKE_PREFIX_PATH=%CMAKE_PREFIX_PATH% ..
cmake --build . --config Release

