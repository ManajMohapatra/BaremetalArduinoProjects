DEVICE = atmega328p
FILENAME = main
SRC = src
PROGRAMMER = arduino
PORT = COM7
BAUD = 115200
COMPILE = avr-gcc -Wall -Os -mmcu=${DEVICE} -DF_CPU=16000000L
default: compile upload clean

compile:
	${COMPILE} -c ${SRC}/${FILENAME}.c -o ${FILENAME}.o
	${COMPILE} -o ${FILENAME}.elf ${FILENAME}.o
	avr-objcopy -O ihex ${FILENAME}.elf ${FILENAME}.hex
	avr-size --format=avr --mcu=${DEVICE} ${FILENAME}.elf

upload:
	avrdude -v -p ${DEVICE} -c ${PROGRAMMER} -P ${PORT} -b ${BAUD} -U flash:w:${FILENAME}.hex:i

clean:
	rm ${FILENAME}.o
	rm ${FILENAME}.elf
	rm ${FILENAME}.hex
