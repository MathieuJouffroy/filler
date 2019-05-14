#!/usr/bin/python

import sys
import os
from tkinter import ttk
import tkinter

def close(event):
	sys.exit()

def get_my_player(me, str, self):
	me['text'] = str

def get_opponent(opponent, str, self):
	opponent['text'] = str

def get_map(map, str, self):
	map['text'] = str

def start_game(p1, p2, mp, self, warn):
	if not p1 or not p2 or not mp:
		warn['text'] = 'Empty field'
	else:
		cmd = "./filler_vm -f maps/"+mp+" -p1 ./"+p1+" -p2 players/"+p2+" | python visu.py"
		os.system(cmd)
		with open('filler.trace', 'r') as file:
			line = file.read().split('\n')[1]
		line = line.replace("players/", "")
		line = line.replace(".filler", "")
		warn['text'] = line

class Menu:
	def __init__(self):
		self.finished = False
		self.init_root()
		me = tkinter.Label(self.root, foreground='cyan', background='#0E0019')
		me.grid(padx=50, row=10, column=0)
		opponent = tkinter.Label(self.root, foreground='#E94992', background='#0E0019')
		opponent.grid(padx=50, row=10, column=2)
		map = tkinter.Label(self.root, foreground='#7FF204', background='#0E0019')
		map.grid(padx=50, row=10, column=1)
		self.listp1(me)
		self.listp2(opponent)
		self.listmap(map)
		label1 = tkinter.Label(self.root, text='My Player', foreground='cyan', background='#0E0019')
		label1.grid(padx=50, row=0, column=0)
		label2 = tkinter.Label(self.root, text='Select opponent', foreground='#E94992', background='#0E0019')
		label2.grid(padx=50, row=0, column=2)
		label3 = tkinter.Label(self.root, text='Select Map', foreground='#7FF204', background='#0E0019')
		label3.grid(padx=50, row=0, column=1)
		warn = tkinter.Label(self.root, foreground='red', background='#0E0019')
		warn.grid(padx=50, row=100, column=1)
		go = tkinter.Button(self.root, text='Play', foreground='#7FF204', background='#0E0019', command=lambda: start_game(me['text'], opponent['text'], map['text'], self, warn))
		go.grid(padx=50, row=50, column=1)


	def init_root(self):
		self.root = tkinter.Tk()
		self.root.resizable(width=False, height=False)
		self.root.bind('<Escape>', close)

	def start(self):
		self.running = True
		self.root.title("Play Filler Game")
		self.root.geometry("610x300")
		self.root.configure(background= '#0E0019')
		self.root.mainloop()

	def stop(self):
		self.running = False

	def listp1(self, me):
		lst = self.my_player()
		for x, item in enumerate(lst, start=1):
			button = tkinter.Button(self.root, text=item, foreground='#5D26F2', background='black', command=lambda arg=item: get_my_player(me, arg, self))
			button.grid(padx=50, row=x, column=0, sticky="NSEW")

	def listp2(self, opponent):
		lst = self.opponents()
		for x, item in enumerate(lst, start=1):
			button = tkinter.Button(self.root, text=item, foreground='#5D26F2', background='black', command=lambda arg=item: get_opponent(opponent, arg, self))
			button.grid(padx=50, row=x, column=2, sticky="NSEW")

	def listmap(self, map):
		lst = self.map_number()
		for x, item in enumerate(lst, start=1):
			button = tkinter.Button(self.root, text=item, foreground='#5D26F2', background='black', command=lambda arg=item: get_map(map, arg, self))
			button.grid(padx=50, row=x, column=1, sticky="NSEW")

	def opponents(self):
		opponents = []
		for file in os.listdir("./players"):
				if file.endswith(".filler"):
					opponents.append(file)
		return opponents

	def my_player(self):
		me = []
		for file in os.listdir("./"):
				if file.endswith(".filler"):
					me.append(file)
		return me

	def map_number(self):
		l = []
		for file in os.listdir("./maps"):
					l.append(file)
		return l

Menu().start()