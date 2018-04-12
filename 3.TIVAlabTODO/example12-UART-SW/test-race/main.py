#------------------------------------------------------------------------------
#   Import
#------------------------------------------------------------------------------
import serial
from time import sleep


#------------------------------------------------------------------------------
#	Function starts UART
#------------------------------------------------------------------------------
def start_COM(device='/dev/ttyACM0', baudrate=115200):
	ser = serial.Serial(device, baudrate)
	print("Start COM port {}".format(ser.name))
	return ser


#------------------------------------------------------------------------------
#	Function stops UART
#------------------------------------------------------------------------------
def stop_COM(ser):
	ser.close()
	print("Close COM port {}".format(ser.name))


#------------------------------------------------------------------------------
#	Main execution
#------------------------------------------------------------------------------
# Parameter
NUM_LOOP = 100000
cmds = [b'LED GREEN ON', b'LED GREEN OFF']

# Run
ser = start_COM()
num_cmd = len(cmds)

i = 0
while(i < NUM_LOOP):
	idx = i % num_cmd
	cmd = cmds[idx]
	ser.write(b"%s\n" % cmd)
	# sleep(1e-4)
	i += 1

stop_COM(ser)