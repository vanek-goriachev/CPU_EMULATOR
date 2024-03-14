"# CPU_EMULATOR" 


On Mac: 
    TESTING:
        cd tests
        make test

    RUNNING:
        cd cpu_emulator
        make run PROGRAM_FILE=<filepath>
        
        example: make run PROGRAM_FILE=examples/fibonacci
