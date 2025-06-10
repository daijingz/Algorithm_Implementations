# Author: Jingze Dai
# Email Address: daij24@mcmaster.ca or david1147062956@163.com
# Github: https://github.com/daijingz
# Linkedin: https://www.linkedin.com/in/jingze-dai/
# Description: Basic Sort
# This file includes programs with 4 different kinds of sorting algorithm
# All of those target inputs are lists consist of unrepeated integers and floats
# Sort output is ascending-integer list
import random


class InappropriateInput(Exception):
    """! Exception when inputs are inappropriate"""
    pass


class OtherErrors(Exception):
    """! Exception for all other problems"""
    pass


def checkAvailable(inputList):
    """! Function Check whether it is correct and appropriate"""
    try:
        i = 0
        while i < len(inputList):
            if not isinstance(inputList[i], (float, int)):
                return False
            i += 1

        for j in inputList:
            if inputList.count(j) > 1:
                return False
            elif j == 0:
                return False

        return True
    except:
        raise OtherErrors("Other errors founded.")


def sciCmp(num1, num2):
    """! Compare 2 numbers scientifically"""
    try:
        if sciEql(num1, num2, 1e-6):
            return 0
        elif num1 < num2:
            return num2
        else:
            return num1
    except:
        raise Exception()


def sciEql(num1, num2, error=1e-6):
    """! Check whether 2 numbers are equal sequentially"""
    try:
        if abs(num1 - num2) <= error:
            return True
        else:
            return False
    except:
        raise Exception()


def SelectionSort(inputList):
    """! Sort select the minimum and make it into the new array again and again"""
    try:
        if not checkAvailable(inputList):
            raise InappropriateInput()

        output = []
        loopList = inputList
        while len(loopList) > 0:
            output += [min(loopList)]
            loopList.remove(min(loopList))
        return output
    except:
        raise OtherErrors("Other errors founded.")


def InsertionSort(inputList):
    """! Sort select elements from left to right and insert them sequentially"""
    try:
        if not checkAvailable(inputList):
            raise InappropriateInput()

        output = []
        for i in inputList:
            output = Insertion(output, i)
        return output
    except:
        raise OtherErrors("Other errors founded.")


def Insertion(inputList, elem):
    """! Find the right place for an element in a sorted list"""
    try:
        if not checkAvailable(inputList):
            raise InappropriateInput()

        if len(inputList) == 0:
            return [elem]
        elif elem > max(inputList):
            return inputList + [elem]
        elif elem < min(inputList):
            return [elem] + inputList
        else:
            output = inputList
            i = 0
            while i < len(inputList):
                if elem < output[i]:
                    output = output[:i] + [elem] + output[i:]
                    return output
                else:
                    i += 1
    except:
        raise OtherErrors("Other errors founded.")


def MergeSort(inputList):
    """! Divide list into sub-lists and sort them, then combine their results together"""
    try:
        if not checkAvailable(inputList):
            raise InappropriateInput()

        if len(inputList) > 1:
            subLeft = inputList[:len(inputList) // 2]
            subRight = inputList[len(inputList) // 2:]

            MergeSort(subLeft)
            MergeSort(subRight)

            i = 0
            j = 0
            k = 0

            while i < len(subLeft) and j < len(subRight):
                if subLeft[i] < subRight[j]:
                    inputList[k] = subLeft[i]
                    i += 1
                elif subLeft[i] > subRight[j]:
                    inputList[k] = subRight[j]
                    j += 1
                k += 1

            while i < len(subLeft):
                inputList[k] = subLeft[i]
                i += 1
                k += 1

            while j < len(subRight):
                inputList[k] = subRight[j]
                j += 1
                k += 1

            output = inputList
            return output
        else:
            return inputList
    except:
        raise OtherErrors("Other errors founded.")


def ShellSort(inputPart):
    """! Variation of Insertion Sort"""
    try:
        if not checkAvailable(inputPart):
            raise InappropriateInput()

        inputList = inputPart
        medium = len(inputList) // 2
        while medium > 0:
            for i in range(medium, len(inputList)):
                temp = inputList[i]
                j = i
                while j >= medium and inputList[j - medium] > temp:
                    inputList[j] = inputList[j - medium]
                    j -= medium
                inputList[j] = temp
            medium //= 2
        return inputList
    except:
        raise OtherErrors("Other errors founded.")


def QuickSort(inputList):
    """! Find a comparable index (not max or min) and then compare others"""
    try:
        if not checkAvailable(inputList):
            raise InappropriateInput()

        leftPart = []
        rightPart = []
        randomNum = inputList[random.randint(0, len(inputList) - 1)]

        while randomNum == max(inputList) or randomNum == min(inputList):
            randomNum = inputList[random.randint(0, len(inputList) - 1)]

        for i in inputList:
            if i < randomNum:
                leftPart += [i]
            elif i > randomNum:
                rightPart += [i]

        leftPart.sort()
        rightPart.sort()
        return leftPart + [randomNum] + rightPart
    except:
        raise OtherErrors("Other errors founded.")

arr = [4, 9, 1, 5, 2]
print(InsertionSort(arr))
print(MergeSort(arr))
print(ShellSort(arr))
print(QuickSort(arr))