MCU=atmega328p
CC=avr-gcc
CFLAGS=-std=c99 -Wall -g -Os -mmcu=${MCU}
OBJCOPY=avr-objcopy
TARGET=main
INCLUDE=include
# SRC=main.c
SRC:=$(wildcard src/*.c)
DEV=/dev/tty.usbserial-11140

all:
	${CC} ${CFLAGS} -I ${INCLUDE} -o ${TARGET}.bin ${SRC} -lm
	${OBJCOPY} -j .text -j .data -O ihex ${TARGET}.bin ${TARGET}.hex

flash: all
	avrdude -v -p ${MCU} -carduino -P${DEV} -b57600 -D -U flash:w:${TARGET}.hex:i

clean:
	rm ${TARGET}.bin ${TARGET}.hex