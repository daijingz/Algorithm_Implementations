# Author: Jingze Dai
# Email Address: daij24@mcmaster.ca or david1147062956@163.com
# Github: https://github.com/daijingz
# Linkedin: https://www.linkedin.com/in/jingze-dai/
# Description: 2-dimensional array implementation 2


class Table:
    def __init__(self, row: int, col: int):
        if row <= 0 or col <= 0:
            raise ValueError("Error: x and y should between 1 and 20")
        elif row >= 20 or col >= 20:
            raise ValueError("Error: x and y should between 1 and 20")
        self.__row = row
        self.__col = col
        self.__body = dict()

    def get_row(self):
        try:
            return self.__row
        except:
            raise Exception()

    def get_col(self):
        try:
            return self.__col
        except:
            raise Exception()

    def get_body(self):
        try:
            return self.__body
        except:
            raise Exception()

    def set_row(self, row: int):
        if row <= 0 or row >= 20:
            raise ValueError("Error: x and y should between 1 and 20")
        self.__row = row

    def set_col(self, col: int):
        if col <= 0 or col >= 20:
            raise ValueError("Error: x and y should between 1 and 20")
        self.__col = col

    def set_point(self, row: int, col: int, value: int):
        pass

    def empty(self):
        pass

    def __str__(self):
        pass

    def appendRow(self):
        pass

    def deleteRow(self):
        pass

    def insertRow(self):
        pass

    def appendCol(self):
        pass

    def deleteCol(self):
        pass

    def insertCol(self):
        pass

    def filter(self):
        pass

    def rotate(self):
        pass