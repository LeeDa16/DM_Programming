import tkinter as tk
import os

def examine(s):
	isInBracket = 0
	flag = 0
	if s[0] == ')' or s[0] == '!' or s[0] == '&' or s[0] == '|' or s[0] == '^' or s[0] == '~':
		return 0
	for i in range(0, len(s)):
		if s[i] == '(':
			isInBracket += 1
		elif s[i] == ')':
			if s[i - 1] == '(':
				return 0
			isInBracket -= 1
		elif s[i] == '!' or s[i] == '&' or s[i] == '|' or s[i] == '^' or s[i] == '~':
			if flag != 1:
				flag = 1
			elif s[i] != '!' or s[i - 1] == '(':
				return 0
		else:
			if flag != -1:
				flag = -1
			else:
				return 0
	if isInBracket != 0 or flag == 1:
		return 0
	return 1

def btnClicked():
	expr = str(entryExpr.get()).replace(" ", "")
	if examine(expr) == 0:
		labelPN.config(text = "Wrong format, please enter again")
	else:
		f = open("PolishNotation_InPut.txt", "w")
		f.write(expr)
		f.close()
		
		os.system("PolishNotation.exe")
		
		f = open("PolishNotation_OutPut.txt", "r")
		content = f.readline()
		labelPN.config(text = 'PolishNotation: ' + content)

top = tk.Tk()

top.title("Polish Notation")

labelPN = tk.Label(top, text = "Please enter an expression", height = 5, width = 30, fg = "blue")
labelPN.pack()

entryExpr = tk.Entry(top, text = "0")
entryExpr.pack()

btnPN = tk.Button(top, text = "Transfer", command = btnClicked)
btnPN.pack()

#print(expr)

top.mainloop()