"# CPU_EMULATOR" 


On Mac: 
    build: cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
    
    For run anything first of all do: cd build
    build tests: cmake --build . --target tests
    run tests: ./tests/tests

    build and run runnn: cmake --build . --target run
    to run it again: ./CPU_EMULATOR
