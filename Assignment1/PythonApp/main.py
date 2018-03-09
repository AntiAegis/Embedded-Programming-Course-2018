#------------------------------------------------------------------------------
#   Import
#------------------------------------------------------------------------------
from PyQt5.QtWidgets import QMainWindow, QApplication
from sys import argv
import serial
from frontend import design


#------------------------------------------------------------------------------
#   Class
#------------------------------------------------------------------------------
class UsrApplication(QMainWindow, design.Ui_MainWindow):
	def __init__(self, parent=None):
		super(UsrApplication, self).__init__(parent)
		self.setupUi(self)
		self.start_COM()

		self.btnRON.clicked.connect(self.btnRON_handler)
		self.btnROFF.clicked.connect(self.btnROFF_handler)
		self.btnGON.clicked.connect(self.btnGON_handler)
		self.btnGOFF.clicked.connect(self.btnGOFF_handler)
		self.btnBON.clicked.connect(self.btnBONhandler)
		self.btnBOFF.clicked.connect(self.btnBOFFhandler)

	def start_COM(self, device='/dev/ttyACM0', baudrate=115200):
		self.ser = serial.Serial(device, baudrate)
		print("Start COM port {}".format(self.ser.name))

	def close_COM(self):
		self.ser.close()
		print("Close COM port {}".format(self.ser.name))

	def btnRON_handler(self):
		self.ser.write(b'RON\n')

	def btnROFF_handler(self):
		self.ser.write(b'ROFF\n')

	def btnGON_handler(self):
		self.ser.write(b'GON\n')

	def btnGOFF_handler(self):
		self.ser.write(b'GOFF\n')

	def btnBONhandler(self):
		self.ser.write(b'BON\n')

	def btnBOFFhandler(self):
		self.ser.write(b'BOFF\n')
		

#------------------------------------------------------------------------------
#   Main
#------------------------------------------------------------------------------
app = QApplication(argv)
form = UsrApplication()
form.show()
app.exec_()
form.close_COM()

