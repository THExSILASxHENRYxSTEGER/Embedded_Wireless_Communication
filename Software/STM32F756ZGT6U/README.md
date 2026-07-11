## Bare Metal STM32F7 Ethernet Input Bluetooth Output

# To Compile the and Link the image to flash:

docker run --rm -it \
    -v $(pwd):/app \
    stm32-builder \
    make

# To Flash the application onto the stm32f756:

1. To connect stm32 f7 with openOCD and GDB open in one terminal:

    openocd -f interface/stlink-v2-1.cfg -f target/stm32f7x.cfg -c "init" -c "reset halt"

2. Flash the .elf file:

    From the folder of this README.md file execute:

    arm-none-eabi-gdb build/final.elf

3. Connect to the uC:

    press enter and then execute command

    "target remote :3333"

    after pressing enter should give result: (gdb) ... possible gdb command line

    If you input "target remote :3333" again u get:

    A program is being debugged already.  Kill it? (y or n) n 

    --> then answer n

4. Load the flash on the uC:

    "load"

5. Set break points:

    "break main.cpp:21"

6. restart program with break points:

    "monitor reset halt"

7. execute program until first break point:

    "continue"

