import curses

class Graphics:
	def __init__(self):
		self.stdscr = curses.initscr()
		curses.noecho()
		curses.cbreak()
		curses.curs_set(0)
	def getch(self):
		c = self.stdscr.getch()
		if c < 256:
			return chr(c)
		else:
			return c

	def Print(self,x,y,string):
		self.stdscr.addstr(y,x,string)
	def Message(self, message):
		self.stdscr.addstr(0,0,message)

	def refresh(self):
		self.stdscr.refresh()

	def clear(self):
		self.stdscr.clear()

	def __del__(self):
		curses.curs_set(1)
		curses.echo()
		curses.nocbreak()
		curses.endwin()
