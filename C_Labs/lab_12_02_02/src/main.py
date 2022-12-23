from PyQt5 import QtWidgets
from PyQt5.QtCore import Qt
import sys
import ctypes

sys.path.insert(0, './interface/')

from MyWindow import Ui_MainWindow


lib = ctypes.CDLL("./libs/lib_arr.so")

# void create_fib_arr(int *fib_arr, int count)

_create_fib_arr = lib.create_fib_arr
_create_fib_arr.argtypes = (ctypes.POINTER(ctypes.c_uint64), ctypes.c_uint64)
_create_fib_arr.restype = None


def create_fib_arr(count):
    fib_arr = (ctypes.c_uint64 * count)()
    
    _create_fib_arr(fib_arr, count)
    
    return list(fib_arr)


def del_dublicates():
    


class window(QtWidgets.QMainWindow):
    def __init__(self):
        super(window, self).__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        self.ui.Get_fib_arr_btn.clicked.connect(self.Get_fib_arr)
        self.ui.Filter_arr_btn.clicked.connect(self.Filter_arr)
        self.ui.Clear_action.setShortcut("Ctrl+W")
        self.ui.Clear_action.triggered.connect(self.ClearAll)
        self.ui.Quit.setShortcut("Ctrl+D")
        self.ui.Quit.triggered.connect(QtWidgets.qApp.quit)
        
    def Get_fib_arr(self):
        try:
            count = int(self.ui.Input_count_fib_entry.toPlainText())
        except ValueError:
            self.ErrorDialog("Не удалось получить корректное количество! Попробуйте снова!")
            return
        
        if count < 1 or count > 90:
            self.ErrorDialog("Не удалось получить корректное количество! Попробуйте снова!")
            return
        
        fib_arr = create_fib_arr(count)
        
        self.ui.Output_fib_arr_entry.setPlainText(str(fib_arr))
        
    def Filter_arr_max_alloc(self):
        try:
            in_arr = list(map(int, (self.ui.Input_arr_entry.toPlainText()).split()))
        except ValueError:
            self.ErrorDialog("Не удалось получить корректный массив! Попробуйте снова!")
            return

        
                    
        
    def ErrorDialog(self, info):
        msg = QtWidgets.QMessageBox()
        msg.setIcon(QtWidgets.QMessageBox.Information)
        
        msg.setText("Ошибка")
        msg.setInformativeText(info)
        msg.setWindowTitle("Error")
        msg.setStandardButtons(QtWidgets.QMessageBox.Ok)
        
        msg.exec_()
            
    def ClearAll(self):
        self.ui.Input_arr_entry.clear()
        self.ui.Input_count_fib_entry.clear()
        self.ui.Output_fib_arr_entry.clear()
        self.ui.Output_filter_arr_entry.clear()


app = QtWidgets.QApplication([])
application = window()
application.show()
 
sys.exit(app.exec())