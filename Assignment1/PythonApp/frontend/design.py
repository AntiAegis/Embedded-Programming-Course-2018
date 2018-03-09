# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'frontend/design.ui'
#
# Created by: PyQt5 UI code generator 5.10
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(426, 110)
        self.centralWidget = QtWidgets.QWidget(MainWindow)
        self.centralWidget.setObjectName("centralWidget")
        self.widgetBTN = QtWidgets.QWidget(self.centralWidget)
        self.widgetBTN.setGeometry(QtCore.QRect(10, 10, 401, 91))
        self.widgetBTN.setObjectName("widgetBTN")
        self.btnRON = QtWidgets.QPushButton(self.widgetBTN)
        self.btnRON.setGeometry(QtCore.QRect(20, 10, 99, 27))
        self.btnRON.setObjectName("btnRON")
        self.btnROFF = QtWidgets.QPushButton(self.widgetBTN)
        self.btnROFF.setGeometry(QtCore.QRect(20, 50, 99, 27))
        self.btnROFF.setObjectName("btnROFF")
        self.btnGON = QtWidgets.QPushButton(self.widgetBTN)
        self.btnGON.setGeometry(QtCore.QRect(150, 10, 99, 27))
        self.btnGON.setObjectName("btnGON")
        self.btnBON = QtWidgets.QPushButton(self.widgetBTN)
        self.btnBON.setGeometry(QtCore.QRect(290, 10, 99, 27))
        self.btnBON.setObjectName("btnBON")
        self.btnGOFF = QtWidgets.QPushButton(self.widgetBTN)
        self.btnGOFF.setGeometry(QtCore.QRect(150, 50, 99, 27))
        self.btnGOFF.setObjectName("btnGOFF")
        self.btnBOFF = QtWidgets.QPushButton(self.widgetBTN)
        self.btnBOFF.setGeometry(QtCore.QRect(290, 50, 99, 27))
        self.btnBOFF.setObjectName("btnBOFF")
        MainWindow.setCentralWidget(self.centralWidget)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "UART"))
        self.btnRON.setText(_translate("MainWindow", "RON"))
        self.btnROFF.setText(_translate("MainWindow", "ROFF"))
        self.btnGON.setText(_translate("MainWindow", "GON"))
        self.btnBON.setText(_translate("MainWindow", "BON"))
        self.btnGOFF.setText(_translate("MainWindow", "GOFF"))
        self.btnBOFF.setText(_translate("MainWindow", "BOFF"))

