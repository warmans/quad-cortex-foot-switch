# quad-cortex-foot-switch v2

MIDI footswitch for switching between QC scenes.

![complete pedal](https://i.imgur.com/XSDIxON.jpeg)

More pictures: https://imgur.com/a/Fm4U8BB

## Parts List

1. Arduino Nano
2. 8x PCB mount momentary switches (https://www.aliexpress.com/item/32924115689.html)
3. 1x MIDI female connector (https://www.aliexpress.com/item/4000583940302.html)
4. USB-C socket for power (https://www.aliexpress.com/item/1005004564914143.html)
5. 8x resistors (5-10k ohms)
6. 1x 220ohm resistor for MIDI socket.
7. 8x 8mm LEDs
8. B3B-XH-A, B2B-XH-A headers (ideally right angle due to the awkward arduno USB position)
9. 2mm aluminium sheet for top/bottom 
10. M3 threaded inserts and bolts.

## PCB

See the [gerber files](qc-footswitch-v2-scm v55_2022-10-26-gerber.zip)

Can be manufactured by e.g. JLCPCB for ~£10.

## Arduino Code

The [arduino sketch](qcfs_v2_arduino/qcfs_v2_arduino.ino) is included. It's extremely simple but observe the difference between a generic nano and the official "Every" nano.

## Drill/bending templates 

See: 

1. [qc-fs-front.svg](qc-fs-front.svg) - Template for drilling/bending the top of the enclosure. There are too many screw holes. My advice would be 
   to only to the highest and lowest holes rather than all 5.
2. [qc-fs-back.svg](qc-fs-back.svg) - Template for the back of the pedal. This doesn't have holes defined for the MIDI/USB connectors. Just put them wherever you want.

## 3d printable enclosure Sides

The .stl for the sides is included. Just mirror it for the opposite side.

File: enclosure-left-twopart.stl

## Connector Placement Issue 

The board layout has a mistake where the power/midi headers interfere with the arduino USB connector if the arduino is connected directly to the board. 

To work around this I used sockets for the arduino pins which raise the arduino USB socket up to clear the headers. However right angle headers would probably work 
too.

## MIDI DIN output wiring

```
1 -
2 GND
3 -
4 DATA
5 5v (requires 220ohm resistor)
```

![din wiring](din.webp)