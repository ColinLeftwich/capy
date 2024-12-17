main := "src/main.c"

run *ARGS: build
    ./capy {{ ARGS }}

build:
    gcc {{ main }} -o capy 