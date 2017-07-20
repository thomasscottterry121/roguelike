import curses
import graphics

class Player:
	def __init__(self, x, y):
		self.x = x
		self.y = y
	def move(self, mx, my):
		self.x = self.x + mx
		self.y = self.y + my
		if(self.x > 79): self.x = 79
		if(self.x < 0): self.x = 0
		if(self.y > 20): self.y = 20
		if(self.y < 2): self.y = 2

def main():
	p = Player(1,1)
	g = graphics.Graphics()
	g.clear()
	g.refresh()
	while(1):
		c = g.getch()
		g.clear()
		if Update(c, p, g):
			break
		Draw(g, p)

	return 0

def Update(c, p, g):
	if(c == '8'):
		p.move(0,-1)
		return 0
	elif(c == '2'):
		p.move(0,1)
		return 0
	elif(c == '4'):
		p.move(-1,0)
		return 0
	elif(c == '6'):
		p.move(1,0)
		return 0
	elif(c == '7'):
		p.move(-1,-1)
		return 0
	elif(c == '9'):
		p.move(1,-1)
		return 0
	elif(c == '1'):
		p.move(-1,1)
		return 0
	elif(c == '3'):
		p.move(1,1)
		return 0
	elif(c == '5'):
		p.move(0,0)
		return 0
	elif(c == 'q'):
		return 1
	else:
		g.Message("Unhandled key: " + c)

def Draw(g,p):
	g.Print(p.x,p.y,"@")
	return 0


if __name__=="__main__":
	main()
