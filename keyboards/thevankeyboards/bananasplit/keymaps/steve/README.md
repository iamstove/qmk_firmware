## How to make and flash

(These instructions are for Linux-based operating systems
with `dfu-programmer` available.)

`cd` into the `qmk main directory'

    make bananasplit:steve

which should result in a file called `bananasplit_rask.hex` appearing
in your QMK directory.

Now plug in your BananaSplit60 keyboard via USB. Verify
with `lsusb` that it appears. At least my PCB did not have
anything preflashed so you should see `atmega32u4` or similar
in the `lsusb` output.

Now you can flash the firmware by

    $ sudo dfu-programmer atmega32u4 erase
    $ cd to the qmk_firmware folder
    $ sudo dfu-programmer atmega32u4 flash bananasplit_steve.hex

_If_ you happen to have some other `atmega32u4` based device
I suggest you plug it out before flashing your BS60 just to
prevent accidentally flashing your old device.
