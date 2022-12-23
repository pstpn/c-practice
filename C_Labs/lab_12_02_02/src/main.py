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

# int del_dublicates(int *src_arr, int *src_count, int *dst_arr)

_del_dublicates = lib.del_dublicates
_del_dublicates.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_int))
_del_dublicates.restype = ctypes.c_int

def del_dublicates_max_alloc(src_lst):
    src_count = len(src_lst)
    
    src = (ctypes.c_int * src_count)(*src_lst)
    
    dst_arr = (ctypes.c_int * src_count)()
    
    return (_del_dublicates(src, ctypes.c_int(src_count), dst_arr), list(dst_arr))


def del_dublicates_accurate_alloc(src_lst):
    src_count = len(src_lst)
    
    src = (ctypes.c_int * src_count)(*src_lst)
    
    dst_count = _del_dublicates(src, ctypes.c_int(src_count), None)
    
    dst_arr = (ctypes.c_int * dst_count)()
    
    return (_del_dublicates(src, ctypes.c_int(src_count), dst_arr), list(dst_arr))


class window(QtWidgets.QMainWindow):
    def __init__(self):
        super(window, self).__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        self.ui.Get_fib_arr_btn.clicked.connect(self.Get_fib_arr)
        self.ui.Filter_arr_max_alloc_btn.clicked.connect(self.Filter_arr_max_alloc)
        self.ui.Filter_arr_accurate_alloc_btn.clicked.connect(self.Filter_arr_accurate_alloc)
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
        
        if (len(in_arr) == 0):
            self.ErrorDialog("Не удалось получить корректный массив! Попробуйте снова!")
            return
        
        filter_arr = del_dublicates_max_alloc(in_arr)
        
        self.ui.Output_filter_arr_entry.setPlainText("Count: " + str(filter_arr[0]) + "\nArray: " + str(filter_arr[1]))

    def Filter_arr_accurate_alloc(self):
        try:
            in_arr = list(map(int, (self.ui.Input_arr_entry.toPlainText()).split()))
        except ValueError:
            self.ErrorDialog("Не удалось получить корректный массив! Попробуйте снова!")
            return
        
        if (len(in_arr) == 0):
            self.ErrorDialog("Не удалось получить корректный массив! Попробуйте снова!")
            return
        
        filter_arr = del_dublicates_accurate_alloc(in_arr)
        
        self.ui.Output_filter_arr_entry.setPlainText("Count: " + str(filter_arr[0]) + "\nArray: " + str(filter_arr[1]))
        
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