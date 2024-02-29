"# CPU_EMULATOR" 


On Mac: 
    build: cmake -S . -B build -DCMAKE_BUILD_TYPE=Release

    build tests: cmake --build build --target tests
    run tests: build/tests/tests

    build and run runnn: cmake --build build --target run
    to run it again: build/CPU_EMULATOR
